# C++ Primer Plus

### 第十二章

### 1.

```c++
#include <iostream>
#include <typeinfo>
using namespace std;
class Cow {
	char name[20];
	char* hobby;
	double weight;
public:
	Cow();
	Cow(const char* nm, const char* ho, double wt);
	Cow(const Cow& c);
	~Cow();
	Cow& operator=(const Cow & c);
	void ShowCow() const; //display all cow data
};
int main()
{
	Cow a;
	a.ShowCow();
	Cow b("nana", "happy", 1002);
	b.ShowCow();
	a = b;
	a.ShowCow();
	return 0;
}
Cow::Cow() {
	strcpy(name,"moumou");
	hobby = new char[10];
	strcpy(hobby, "singing");
	weight = 1000;
}
Cow::Cow(const char* nm, const char* ho, double wt) {
	strcpy(name, nm);
	hobby = new char[strlen(ho) + 1];
	strcpy(hobby, ho);
	weight = wt;
}
Cow::Cow(const Cow& c) {
	strcpy(name, c.name);
	hobby = new char[strlen(c.hobby)];
	strcpy(hobby, c.hobby);
	weight = c.weight;
}
Cow::~Cow() {
	delete[] hobby;
}
Cow& Cow::operator=(const Cow& c) {
	strcpy(name, c.name);
	strcpy(hobby, c.hobby);
	weight = c.weight;
}
void Cow::ShowCow() const {
	cout << "name: " << name << endl;
	cout << "hobby: " << hobby << endl;
	cout << "weight: " << weight << endl;
}

```

### 2.

```c++
// string2.h -- fixed and augmented string class definition

#ifndef STRING1_H_
#define STRING1_H_
#include <iostream>
#include <cstring>
using std::ostream;
using std::istream;

class String
{
private:
	char* str;             // pointer to string
	int len;                // length of string
	static int num_strings; // number of objects
	static const int CINLIM = 80;  // cin input limit
public:
	// constructors and other methods
	String(const char* s); // constructor
	String();               // default constructor
	String(const String&); // copy constructor
	~String();              // destructor
	int length() const { return len; }
	// overloaded operator methods    
	String& operator=(const String&);
	String& operator=(const char*);
	char& operator[](int i);
	const char& operator[](int i) const;
	// overloaded operator friends
	friend bool operator<(const String& st, const String& st2);
	friend bool operator>(const String& st1, const String& st2);
	friend bool operator==(const String& st, const String& st2);
	friend ostream& operator<<(ostream& os, const String& st);
	friend istream& operator>>(istream& is, String& st);
	// static function
	friend String operator+( String str1,  String str2) {
		String result;
		result.len = str1.len + str2.len;
		result.str = new char[result.len + 1];
		strcpy(result.str,str1.str);
		strcat(result.str,str2.str);
		return result;
	}
	friend String operator+(String str2, const char* str1) {
		String result;
		result.len = strlen(str1) + str2.len;
		result.str = new char[result.len + 1];
		strcpy(result.str, str2.str);
		strcat(result.str, str1);
		return result;
	}
	friend String operator+(const char* str1, String str2) {
		String result;
		result.len = strlen(str1) + str2.len;
		result.str = new char[result.len + 1];
		strcpy(result.str,str1);
		strcat(result.str,str2.str);
		return result;
	}
	String stringlow() {
		for (int i = 0;i < len;i++) {
			str[i] = tolower(str[i]);
		}
		return *this;
	}
	String stringup() {
		for (int i = 0;i < len;i++) {
			str[i] = toupper(str[i]);
		}
		return *this;
	}
	int has(char ch) {
		int count = 0;
		for (int i = 0;i < len;i++) {
			if (str[i] == ch)count++;
		}
		return count;
	}
	static int HowMany();
};
#endif
```

```c++
// string1.cpp -- String class methods
#include <cstring>                 // string.h for some
#include "String2.h"               // includes <iostream>
using std::cin;
using std::cout;

// initializing static class member

int String::num_strings = 0;

// static method
int String::HowMany()
{
    return num_strings;
}

// class methods
String::String(const char* s)     // construct String from C string
{
    len = std::strlen(s);          // set size
    str = new char[len + 1];       // allot storage
    std::strcpy(str, s);           // initialize pointer
    num_strings++;                 // set object count
}

String::String()                   // default constructor
{
    len = 4;
    str = new char[1];
    str[0] = '\0';                 // default string
    num_strings++;
}

String::String(const String& st)
{
    num_strings++;             // handle static member update
    len = st.len;              // same length
    str = new char[len + 1];  // allot space
    std::strcpy(str, st.str);  // copy string to new location
}

String::~String()                     // necessary destructor
{
    --num_strings;                    // required
    delete[] str;                    // required
}

// overloaded operator methods    

    // assign a String to a String
String& String::operator=(const String& st)
{
    if (this == &st)
        return *this;
    delete[] str;
    len = st.len;
    str = new char[len + 1];
    std::strcpy(str, st.str);
    return *this;
}

// assign a C string to a String
String& String::operator=(const char* s)
{
    delete[] str;
    len = std::strlen(s);
    str = new char[len + 1];
    std::strcpy(str, s);
    return *this;
}

// read-write char access for non-const String
char& String::operator[](int i)
{
    return str[i];
}

// read-only char access for const String
const char& String::operator[](int i) const
{
    return str[i];
}

// overloaded operator friends

bool operator<(const String& st1, const String& st2)
{
    return (std::strcmp(st1.str, st2.str) < 0);
}

bool operator>(const String& st1, const String& st2)
{
    return st2 < st1;
}

bool operator==(const String& st1, const String& st2)
{
    return (std::strcmp(st1.str, st2.str) == 0);
}

// simple String output
ostream& operator<<(ostream& os, const String& st)
{
    os << st.str;
    return os;
}

// quick and dirty String input
istream& operator>>(istream& is, String& st)
{
    char temp[String::CINLIM];
    is.get(temp, String::CINLIM);
    if (is)
        st = temp;
    while (is && is.get() != '\n')
        continue;
    return is;
}

```

#### 3.

```c++
// stock20.cpp -- augmented version
#include <iostream>
#include <cstring>
#include "stock20.h"
using namespace std;
// constructors
Stock::Stock()        // default constructor
{
    shares = 0;
    share_val = 0.0;
    total_val = 0.0;
}

Stock::Stock(const char * co, long n, double pr)
{
	company= new char[strlen(co)+1];
    strcpy(company,co);
    if (n < 0)
    {
        std::cout << "Number of shares can't be negative; "
                   << company << " shares set to 0.\n";
        shares = 0;
    }
    else
        shares = n;
    share_val = pr;
    set_tot();
}

// class destructor
Stock::~Stock()        // quiet class destructor
{
	delete [] company;
}

// other methods
void Stock::buy(long num, double price)
{
     if (num < 0)
    {
        std::cout << "Number of shares purchased can't be negative. "
             << "Transaction is aborted.\n";
    }
    else
    {
        shares += num;
        share_val = price;
        set_tot();
    }
}

void Stock::sell(long num, double price)
{
    using std::cout;
    if (num < 0)
    {
        cout << "Number of shares sold can't be negative. "
             << "Transaction is aborted.\n";
    }
    else if (num > shares)
    {
        cout << "You can't sell more than you have! "
             << "Transaction is aborted.\n";
    }
    else
    {
        shares -= num;
        share_val = price;
        set_tot();
    }
}

void Stock::update(double price)
{
    share_val = price;
    set_tot();
}

ostream &operator<<(ostream & os,const Stock & st){
	using std::cout;
    using std::ios_base;
    // set format to #.###
    ios_base::fmtflags orig = 
        cout.setf(ios_base::fixed, ios_base::floatfield); 
    std::streamsize prec = cout.precision(3);

    cout << "Company: " << st.company
        << "  Shares: " << st.shares << '\n';
    cout << "  Share Price: $" << st.share_val;
    // set format to #.##
    cout.precision(2);
    cout << "  Total Worth: $" << st.total_val << '\n';

    // restore original format
    cout.setf(orig, ios_base::floatfield);
    cout.precision(prec);
    return os;
}

const Stock & Stock::topval(const Stock & s) const
{
    if (s.total_val > total_val)
        return s;
    else
        return *this; 
}

```

```c++
// stock20.h -- augmented version
#ifndef STOCK20_H_
#define STOCK20_H_
#include <string>
#include <iostream>
using namespace std;
class Stock
{
private:
    char * company;
    int shares;
    double share_val;
    double total_val;
    void set_tot() { total_val = shares * share_val; }
public:
    Stock();        // default constructor
    Stock(const char * co, long n = 0, double pr = 0.0);
    ~Stock();       // do-nothing destructor
    void buy(long num, double price);
    void sell(long num, double price);
    void update(double price);
    const Stock & topval(const Stock & s) const;
    friend ostream &operator<<(ostream & os,const Stock & st);
};

#endif

```

```c++
// usestok2.cpp -- using the Stock class
// compile with stock20.cpp
#include <iostream>
#include "stock20.h"
const int STKS = 4; 
int main()
{
// create an array of initialized objects
    Stock stocks[STKS] = {
        Stock("NanoSmart", 12, 20.0),
        Stock("Boffo Objects", 200, 2.0),
        Stock("Monolithic Obelisks", 130, 3.25),
        Stock("Fleep Enterprises", 60, 6.5)
        };

    std::cout << "Stock holdings:\n";
    int st;
    for (st = 0; st < STKS; st++)
        cout<<stocks[st];
// set pointer to first element
    const Stock * top = &stocks[0];
    for (st = 1; st < STKS; st++)
        top = &top->topval(stocks[st]);
// now top points to the most valuable holding
    std::cout << "\nMost valuable holding:\n";
	std::cout<<*top;
    // std::cin.get();
    return 0; 
}

```

#### 4.

```c++
// usestok2.cpp -- using the Stock class
// compile with stock20.cpp
#include <iostream>
#include "stack.h"

int main()
{
	Stack s1(20);
	Item its[25];
	for(int i=0;i<25;i++){
		its[i]=i*1000;
	}
	for(int i=0;i<25;i++){
		cout<<s1.push(its[i])<<" ";
	}
	cout<<endl;
	unsigned long x;
	for(int i=0;i<25;i++){
		cout<<s1.pop(x)<<" ";
	}
	cout<<endl;
	for(int i=0;i<25;i++){
		s1.push(its[i]);
	}
	s1.show();
	Stack s2(s1);
	s2.show();
	Stack s3;
	s3=s2;
	s3.show();
    return 0; 
}
```

```c++
// stack.h -- class definition for the stack ADT
#ifndef STACK_H_
#define STACK_H_

typedef unsigned long Item;
#include <iostream>
using namespace std;

class Stack
{
private:
    enum {MAX = 10};    // constant specific to class
    Item *pitems;    // holds stack items
    int size;
	int top;            // index for top stack item
public:
    Stack(int n=MAX);
    Stack(const Stack & st);
    ~Stack();
    bool isempty() const;
    bool isfull() const;
    // push() returns false if stack already is full, true otherwise
    bool push(const Item & item);   // add item to stack
    // pop() returns false if stack already is empty, true otherwise
    bool pop(Item & item);          // pop top into item
	Stack & operator=(const Stack & st);
	void show(){
		cout<<"size: "<<size<<endl;
		cout<<"top: "<<top<<endl;
		cout<<"Items: ";
		for(int i=0;i<top;i++){
			cout<<pitems[i]<<" ";
		}
		cout<<endl;
	}
};
#endif
```

```c++
// stack.cpp -- Stack member functions
#include "stack.h"
Stack::Stack(int n){
	pitems=new Item[n];
	size=n;
	top=0;    	
}
Stack::Stack(const Stack & st){
	pitems= new Item[st.size];
	size=st.size;
	top=st.top;
	for(int i=0;i<top;i++){
		pitems[i]=st.pitems[i];
	}
}
Stack::~Stack(){
	delete [] pitems;
}
bool Stack::isempty() const
{
    return top == 0;
}

bool Stack::isfull() const
{
    return top == size;
}

bool Stack::push(const Item & item) 
{
    if (top < size)
    {
        pitems[top++] = item;
        return true;
    }
    else
        return false;
}

bool Stack::pop(Item & item)
{
    if (top > 0)
    {
        item = pitems[--top];
        return true;
    }
    else
        return false; 
}
Stack & Stack::operator=(const Stack & st){
	if(&st==this)return *this;
	pitems= new Item[st.size];
	size=st.size;
	top=st.top;
		for(int i=0;i<top;i++){
		pitems[i]=st.pitems[i];
	}
	return *this;
}
```

#### 5.

这题不用写代码

多试几次发现18最合适

#### 6.

```c++
// bank.cpp -- using the Queue interface
// compile with queue.cpp
#include <iostream>
#include <cstdlib> // for rand() and srand()
#include <ctime>   // for time()
#include "queue.h"
const int MIN_PER_HR = 60;

bool newcustomer(double x); // is there a new customer?

int main()
{
    using std::cin;
    using std::cout;
    using std::endl;
    using std::ios_base;
// setting things up
    std::srand(std::time(0));    //  random initializing of rand()

    cout << "Case Study: Bank of Heather Automatic Teller\n";
    cout << "Enter maximum size of queue: ";
    int qs;
    cin >> qs;
    Queue line1(qs);         // line queue holds up to qs people
	Queue line2(qs);

    cout << "Enter the number of simulation hours: ";
    int hours;              //  hours of simulation
    cin >> hours;
    // simulation will run 1 cycle per minute
    long cyclelimit = MIN_PER_HR * hours; // # of cycles

    cout << "Enter the average number of customers per hour: ";
    double perhour;         //  average # of arrival per hour
    cin >> perhour;
    double min_per_cust;    //  average time between arrivals
    min_per_cust = MIN_PER_HR / perhour;

    Item temp;              //  new customer data
    long turnaways = 0;     //  turned away by full queue
    long customers = 0;     //  joined the queue
    long served = 0;        //  served during the simulation
    long sum_line = 0;      //  cumulative line length
    int wait_time1 = 0;
	int wait_time2 = 0;      //  time until autoteller is free
    long line_wait = 0;     //  cumulative time in line


// running the simulation
    for (int cycle = 0; cycle < cyclelimit; cycle++)
    {
        if (newcustomer(min_per_cust))  // have newcomer
        {
            if (line1.isfull()&&line2.isfull())
                turnaways++;
			else
            {
                customers++;
                temp.set(cycle);    // cycle = time of arrival
                if(line1.queuecount()<line2.queuecount())
				{
				 	line1.enqueue(temp); // add newcomer to line
            	}
            	else
				{
					line2.enqueue(temp);
				}
			}
        }
        if (wait_time1 <= 0 && !line1.isempty())
        {
            line1.dequeue (temp);      // attend next customer
            wait_time1 = temp.ptime(); // for wait_time minutes
            line_wait += cycle - temp.when();
            served++;
        }
        if (wait_time2 <= 0 && !line2.isempty())
        {
            line2.dequeue (temp);      // attend next customer
            wait_time2 = temp.ptime(); // for wait_time minutes
            line_wait += cycle - temp.when();
            served++;
        }
        if (wait_time1 > 0)
            wait_time1--;
        if(wait_time2 > 0)
        	wait_time2--;
        sum_line += line1.queuecount()+line2.queuecount();
    }

// reporting results
    if (customers > 0)
    {
        cout << "customers accepted: " << customers << endl;
        cout << "  customers served: " << served << endl;
        cout << "         turnaways: " << turnaways << endl;
        cout << "average queue size: ";
        cout.precision(2);
        cout.setf(ios_base::fixed, ios_base::floatfield);
        cout << (double) sum_line / cyclelimit/2 << endl;
        cout << " average wait time: "
             << (double) line_wait / served << " minutes\n";
    }
    else
        cout << "No customers!\n";
    cout << "Done!\n";
    // cin.get();
    // cin.get();
    return 0;
}

//  x = average time, in minutes, between customers
//  return value is true if customer shows up this minute
bool newcustomer(double x)
{
    return (std::rand() * x / RAND_MAX < 1); 
}
```

最大长度10，试了几次发现每小时50顾客，平均等待时长是一分钟

### 第十三章

#### 1.

```c++
//classic.h
#include <iostream>
#include <cstring> 
using namespace std;
class Cd{
private:
	char performers[50];
	char label[20];
	int selections;
	double playtime;
public:
	Cd(char * s1, char * s2,int n, double x);
	Cd(const Cd & d);
	Cd(){};
	virtual ~Cd(){};
	virtual void Report() const;
	virtual Cd & operator=(const Cd & d);
}; 
class Classic :public Cd
{
private:
	char mainwork[50];
public:
	Classic(char * s1,char *s2,char *s3,int n,double x)
	:Cd(s1,s2,n,x)
	{
		strcpy(mainwork,s3);
	}
	Classic(const Classic& d)
	:Cd(d)
	{
		strcpy(mainwork,d.mainwork);	
	}
	Classic(){};
	virtual ~Classic(){};
	void Report() const;
	Classic & operator=(const Classic & d);
};
```

```c++
//classic.cpp
#include <iostream>
using namespace std;
#include "classic.h"

Cd::Cd(char * s1, char * s2,int n, double x):selections(n),playtime(x){
	strcpy(performers,s1);
	strcpy(label,s2);
}
Cd::Cd(const Cd & d):selections(d.selections),playtime(d.playtime){
	strcpy(performers,d.performers);
	strcpy(label,d.label);
}
void Cd::Report() const{
	cout<<"performers: "<<performers<<endl;
	cout<<"label: "<<label<<endl;
	cout<<"selections: "<<selections<<endl;
	cout<<"playtime: "<<playtime<<endl;	
}
Cd & Cd::operator=(const Cd & d){
	if(&d==this)return *this;
	strcpy(performers,d.performers);
	strcpy(label,d.label);
	selections=d.selections;
	playtime=d.playtime;
	return *this;
}
void Classic::Report() const{
	Cd::Report();
	cout<<"mainwork: "<<mainwork<<endl;
}
Classic & Classic::operator=(const Classic & d){
	if(&d==this)return *this;
	strcpy(mainwork,d.mainwork);
	Cd::operator=(d);
	return *this;
}
```

```c++
//main.cpp
#include <iostream>
#include "classic.h"
using namespace std;
void Bravo(const Cd & disk);
int main()
{
	Cd c1("Beatles","Capitol",14,35.5);
	Classic c2 = Classic("Piano Sonata in B flat, Fantasia in C",
						"Alfred Brendel","Philips",2,57.17);
	Cd *pcd = &c1;
	
	cout<<"Using object direct:\n";
	c1.Report();
	c2.Report();
	
	cout<<"using type cd * pointer to objects:\n";
	pcd->Report();
	pcd= &c2;
	pcd->Report();
	
	cout<<"Calling a function with a Cd reference argument:\n";
	Bravo(c1);
	Bravo(c2);
	
	cout<<"Testing assignment: ";
	Classic copy;
	copy = c2;
	copy.Report();
	
	return 0;
}

void Bravo(const Cd & disk)
{
	disk.Report();
}
```

#### 2.

该死，找了半天bug，重新运行又对了

如果有成员是指针，默认的初始化最好分配动态内存

```c++
//main.cpp
#include <iostream>
#include "classic.h"
using namespace std;
void Bravo(const Cd & disk);
int main()
{
	Cd c1("Beatles","Capitol",14,35.5);
	Classic c2 = Classic("Piano Sonata in B flat, Fantasia in C",
						"Alfred Brendel","Philips",2,57.17);
	Cd *pcd = &c1;
	
	cout<<"Using object direct:\n";
	c1.Report();
	c2.Report();
	
	cout<<"using type cd * pointer to objects:\n";
	pcd->Report();
	pcd= &c2;
	pcd->Report();
	
	cout<<"Calling a function with a Cd reference argument:\n";
	Bravo(c1);
	Bravo(c2);
	
	cout<<"Testing assignment: ";
	Classic copy;
	copy = c2;
	copy.Report();
	
	return 0;
}

void Bravo(const Cd & disk)
{
	disk.Report();
}
```

```c++
//classic.h
#include <iostream>
#include <cstring> 
using namespace std;
class Cd{
private:
	char *performers;
	char *label;
	int selections;
	double playtime;
public:
	Cd(char * s1, char * s2,int n, double x);
	Cd(const Cd & d);
	Cd() {
        performers = new char[1]; // 分配最小内存
        performers[0] = '\0';
        label = new char[1];
        label[0] = '\0';
        selections = 0;
        playtime = 0.0;
    }
	virtual ~Cd(){delete [] performers;delete [] label;};
	virtual void Report() const;
	virtual Cd & operator=(const Cd & d);
}; 
class Classic :public Cd
{
private:
	char *mainwork;
public:
	Classic(char * s1,char *s2,char *s3,int n,double x)
	:Cd(s1,s2,n,x)
	{
		mainwork = new char[50];
		strcpy(mainwork,s3);
	}
	Classic(const Classic& d)
	:Cd(d)
	{
		mainwork= new char[50];
		strcpy(mainwork,d.mainwork);	
	}
	Classic():Cd(){
		mainwork = new char[1]; // 分配最小内存
    	mainwork[0] = '\0';
	};
	virtual ~Classic(){delete [] mainwork;};
	virtual void Report() const;
	virtual Classic & operator=(const Classic & d);
};
```

```c++
//classic.cpp
#include <iostream>
using namespace std;
#include "classic.h"

//class Cd{
//private:
//	char performers[50];
//	char label[20];
//	int selections;
//	double playtime;
//public:
//	Cd(char * s1, char * s2,int n, double x);
//	Cd(const Cd & d);
//	Cd();
//	virtual ~Cd();
//	virtual void Report() const;
//	virtual Cd & operator=(const Cd & d);
//}

Cd::Cd(char * s1, char * s2,int n, double x):selections(n),playtime(x){
	performers=new char[50];
	label=new char[20];
	strcpy(performers,s1);
	strcpy(label,s2);
}
Cd::Cd(const Cd & d):selections(d.selections),playtime(d.playtime){
	performers=new char[50];
	label=new char[20];
	strcpy(performers,d.performers);
	strcpy(label,d.label);
}
void Cd::Report() const{
	cout<<"performers: "<<performers<<endl;
	cout<<"label: "<<label<<endl;
	cout<<"selections: "<<selections<<endl;
	cout<<"playtime: "<<playtime<<endl;	
}
Cd & Cd::operator=(const Cd & d){
	if(&d==this)return *this;
	delete[] performers; // 释放旧内存
    delete[] label;
	performers=new char[50];
	label=new char[20];
	strcpy(performers,d.performers);
	strcpy(label,d.label);
	selections=d.selections;
	playtime=d.playtime;
	return *this;
}
void Classic::Report() const{
	Cd::Report();
	cout<<"mainwork: "<<mainwork<<endl;
}
Classic & Classic::operator=(const Classic & d){
	if(&d==this)return *this;
	strcpy(mainwork,d.mainwork);
	Cd::operator=(d);
	return *this;
}
```

### 3.

抽象类的第一次尝试

抽象类首先要把它当类

有纯虚函数的类。纯虚函数就是一定要派生类重新定义，不重新定义没法用，在函数原型后面加上=0就可以了。



```c++
// usedma.cpp -- inheritance, friends, and DMA
// compile with dma.cpp
#include <iostream>
#include "dma.h"
int main()
{
    using std::cout;
    using std::endl;

	dmaABC * pABC[3];
    baseDMA shirt("Portabelly", 8);
    lacksDMA balloon("red", "Blimpo", 4);
    hasDMA map("Mercator", "Buffalo Keys", 5);
    pABC[0]=&shirt;
    pABC[1]=&balloon;
    pABC[2]=&map;
	cout << "Displaying baseDMA object:\n";
    pABC[0]->View();
    cout << "Displaying lacksDMA object:\n";
    pABC[1]->View();
    cout << "Displaying hasDMA object:\n";
    pABC[2]->View();
    lacksDMA balloon2(balloon);
    cout << "Result of lacksDMA copy:\n";
    cout << balloon2 << endl;
    hasDMA map2;
    map2 = map;
    cout << "Result of hasDMA assignment:\n";
    cout << map2 << endl;
    // std::cin.get();
    return 0; 
}
```

```c++
// dma.h  -- inheritance and dynamic memory allocation
#ifndef DMA_H_
#define DMA_H_
#include <iostream>

class dmaABC
{
private:
    char * label;
    int rating;
    
public:
    dmaABC(const char * l = "null", int r = 0);
    dmaABC(const dmaABC & rs);
    virtual ~dmaABC();
    dmaABC & operator=(const dmaABC & rs);
    friend std::ostream & operator<<(std::ostream & os, 
                                     const dmaABC & rs);
    virtual void View()=0;
};


//  Base Class Using DMA
class baseDMA:public dmaABC
{   
public:
    baseDMA(const char * l = "null", int r = 0);
    baseDMA(const baseDMA & rs);
    virtual ~baseDMA();
    baseDMA & operator=(const baseDMA & rs);
    friend std::ostream & operator<<(std::ostream & os, 
                                     const baseDMA & rs);
    virtual void View();
};

// derived class without DMA
// no destructor needed
// uses implicit copy constructor
// uses implicit assignment operator
class lacksDMA :public dmaABC
{
private:
    enum { COL_LEN = 40};
    char color[COL_LEN];
public:
    lacksDMA(const char * c = "blank", const char * l = "null",
              int r = 0);
    lacksDMA(const char * c, const baseDMA & rs);
    friend std::ostream & operator<<(std::ostream & os, 
                                     const lacksDMA & rs);
    virtual void View();
};

// derived class with DMA
class hasDMA :public dmaABC
{
private:
    char * style;
public:
    hasDMA(const char * s = "none", const char * l = "null",
              int r = 0);
    hasDMA(const char * s, const baseDMA & rs);
    hasDMA(const hasDMA & hs);
    ~hasDMA();
    hasDMA & operator=(const hasDMA & rs);  
    friend std::ostream & operator<<(std::ostream & os, 
                                     const hasDMA & rs);
    virtual void View();
};

#endif
```

```c++
// dma.cpp --dma class methods

#include "dma.h"
#include <cstring>

//dmaABC methods
dmaABC::dmaABC(const char * l, int r)
{
    label = new char[std::strlen(l) + 1];
    std::strcpy(label, l);
    rating = r;
}
dmaABC::dmaABC(const dmaABC & rs)
{
    label = new char[std::strlen(rs.label) + 1];
    std::strcpy(label, rs.label);
    rating = rs.rating;
}

dmaABC::~dmaABC()
{
    delete [] label;
}

dmaABC & dmaABC::operator=(const dmaABC & rs)
{
    if (this == &rs)
        return *this;
    delete [] label;
    label = new char[std::strlen(rs.label) + 1];
    std::strcpy(label, rs.label);
    rating = rs.rating;
    return *this;
}
    
std::ostream & operator<<(std::ostream & os, const dmaABC & rs)
{
    os << "Label: " << rs.label << std::endl;
    os << "Rating: " << rs.rating << std::endl;
    return os;
}
void dmaABC::View(){
	std::cout<< "Label: " << label << std::endl;
    std::cout<< "Rating: " << rating << std::endl;
};

// baseDMA methods
baseDMA::baseDMA(const char * l, int r):dmaABC(l,r)
{};
    

baseDMA::baseDMA(const baseDMA & rs):dmaABC(rs)
{};

baseDMA::~baseDMA()
{};

baseDMA & baseDMA::operator=(const baseDMA & rs)
{
    if (this == &rs)
        return *this;
    dmaABC::operator=(rs);
    return *this;
}
    
std::ostream & operator<<(std::ostream & os, const baseDMA & rs)
{
    os<<(const dmaABC &)rs;
    return os;
}
void baseDMA::View(){
	dmaABC::View();
}

// lacksDMA methods
lacksDMA::lacksDMA(const char * c, const char * l, int r)
    : dmaABC(l, r)
{
    std::strncpy(color, c, 39);
    color[39] = '\0';
}

lacksDMA::lacksDMA(const char * c, const baseDMA & rs)
    : dmaABC(rs)
{
    std::strncpy(color, c, COL_LEN - 1);
    color[COL_LEN - 1] = '\0';
}

std::ostream & operator<<(std::ostream & os, const lacksDMA & ls)
{
    os << (const dmaABC &) ls;
    os << "Color: " << ls.color << std::endl;
    return os;
}
void lacksDMA::View(){
	dmaABC::View();
	std::cout<<"Color: "<<color<<std::endl;
}

// hasDMA methods
hasDMA::hasDMA(const char * s, const char * l, int r)
         : dmaABC(l, r)
{
    style = new char[std::strlen(s) + 1];
    std::strcpy(style, s);
}

hasDMA::hasDMA(const char * s, const baseDMA & rs)
         : dmaABC(rs)
{
    style = new char[std::strlen(s) + 1];
    std::strcpy(style, s);
}

hasDMA::hasDMA(const hasDMA & hs)
         : dmaABC(hs)  // invoke base class copy constructor
{
    style = new char[std::strlen(hs.style) + 1];
    std::strcpy(style, hs.style);
}

hasDMA::~hasDMA()
{
    delete [] style;
}

hasDMA & hasDMA::operator=(const hasDMA & hs)
{
    if (this == &hs)
        return *this;
    dmaABC::operator=(hs);  // copy base portion
    delete [] style;         // prepare for new style
    style = new char[std::strlen(hs.style) + 1];
    std::strcpy(style, hs.style);
    return *this;
}
    
std::ostream & operator<<(std::ostream & os, const hasDMA & hs)
{
    os << (const baseDMA &) hs;
    os << "Style: " << hs.style << std::endl;
    return os;
}
void hasDMA::View(){
	dmaABC::View();
	std::cout << "Style: " << style << std::endl;
}

```

