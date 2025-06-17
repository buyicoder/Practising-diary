import threading
import time
import random
from collections import deque

# 自定义公平信号量（FIFO 排队）
class FairSemaphore:
    def __init__(self, initial=1):
        self.count = initial
        self.queue = deque()
        self.lock = threading.Lock()

    def wait(self):
        my_sem = threading.Semaphore(0)
        with self.lock:
            self.queue.append(my_sem)
            if len(self.queue) == 1 and self.count > 0:
                self.count -= 1
                self.queue.popleft()  # 我自己就出队
                return
        my_sem.acquire()

    def signal(self):
        with self.lock:
            if self.queue:
                next_sem = self.queue.popleft()
                next_sem.release()
            else:
                self.count += 1

# 非公平锁（标准互斥）
unfair_mutex = threading.Lock()
fair_mutex = FairSemaphore(1)

log_unfair = []
log_fair = []

# 非公平模式：模拟提前释放 queue_mutex，读者更容易抢占
def unfair_reader(name, log):
    time.sleep(random.uniform(0.01, 0.05))  # 模拟到达时间
    unfair_mutex.acquire()
    log.append(f"{time.time():.3f} Reader-{name} acquired")
    time.sleep(0.01)
    unfair_mutex.release()
    log.append(f"{time.time():.3f} Reader-{name} released")

def unfair_writer(log):
    time.sleep(0.03)
    unfair_mutex.acquire()
    log.append(f"{time.time():.3f} Writer acquired")
    time.sleep(0.02)
    unfair_mutex.release()
    log.append(f"{time.time():.3f} Writer released")

# 公平模式：模拟延迟释放 queue_mutex，写者按顺序执行
def fair_reader(name, log):
    time.sleep(random.uniform(0.01, 0.05))
    fair_mutex.wait()
    log.append(f"{time.time():.3f} Reader-{name} acquired")
    time.sleep(0.01)
    fair_mutex.signal()
    log.append(f"{time.time():.3f} Reader-{name} released")

def fair_writer(log):
    time.sleep(0.03)
    fair_mutex.wait()
    log.append(f"{time.time():.3f} Writer acquired")
    time.sleep(0.02)
    fair_mutex.signal()
    log.append(f"{time.time():.3f} Writer released")

# --------------------------
# 模拟执行
# --------------------------
def run_simulation():
    print("=== 非公平锁模拟 ===")
    threads = [threading.Thread(target=unfair_reader, args=(i, log_unfair)) for i in range(3)]
    threads.append(threading.Thread(target=unfair_writer, args=(log_unfair,)))
    for t in threads: t.start()
    for t in threads: t.join()

    for entry in log_unfair:
        print(entry)

    print("\n=== 公平信号量模拟 ===")
    threads = [threading.Thread(target=fair_reader, args=(i, log_fair)) for i in range(3)]
    threads.append(threading.Thread(target=fair_writer, args=(log_fair,)))
    for t in threads: t.start()
    for t in threads: t.join()

    for entry in log_fair:
        print(entry)

if __name__ == "__main__":
    run_simulation()
