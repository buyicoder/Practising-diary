# C++ Primer Plus  复习题



## 第三章

- 1.为什么C++有多种整型？

  答：为了满足不同的精度和范围需求

- 2.声明与下述描述相符的变量

  - a.short整数
  - b.unsigned int 整数，值为42110
  - c.值为3000000000的整数

  答：

  ```C++
  //a.
  short value_a=80;
  //b.
  unsigned int value_b=42110
  //c.
  long long value_c=3000000000;
  ```

- 3.C++提供了什么措施来防止超出整型的范围？

  答：没有。。。

- 4.33L与33之间有什么区别？

  答：类型不同，前者是long int 型，后者默认是int型

- 5.下面两条C++语句是否等价？

  ```C++
  char grade = 65;
  char grade = 'A';
  ```

  答：等价

- 6.如何使用C++来找出编码88的字符？至少指出两种方法

  答：

  ```C++
  //第一种方法
  char ch=88;
  cout<<ch;
  //第二种方法
  printf("%c",88);
  ```

- 7.将long值赋给float变量会导致舍入误差，将long值赋给double变量呢？将long long 值赋给double变量呢？

  答：long最大十位数，double至少提供13个有效数字，long long 最大19位数，long不需要舍入，long long需要。

- 8.



## 编程练习

### 第四章

#### 1.

```C++
#include<iostream>
#include<string>
using namespace std;

struct people {
	string firstName;
	string lastName;
	char grade;
	int age;
};

int main() {
	const int maxStrNameSize = 50;
	struct people you;
	cout << "What is your first name? ";
	getline(cin, you.firstName);
	cout << "What is your last name? ";
	getline(cin, you.lastName);
	cout << "What letter grade do you deserve? ";
	cin >> you.grade;
	you.grade += 1;
	cout << "What is your age? ";
	cin >> you.age;
	cout << "Name: " << you.lastName << ", " << you.firstName << endl;
	cout << "Grade: " << you.grade<< endl;
	cout << "Age: " << you.age;
}
```

#### 2.同上



#### 3.

```C++
#include<iostream>
#include<string>
#include<cstring>
using namespace std;

int main() {
	char lastName[20];
	char firstName[20];
	char allName[40];
	cout << "Enter your first name: ";
	cin >> firstName;
	cout << "Enter your last name: ";
	cin>>lastName;
	strcpy(allName, lastName);
	strcat(allName, " ");
	strcat(allName, firstName);
	cout << "Here's the information in a single string: " << allName;
}
```

编译没通过，VS 2022不让用strcpy,不安全

#### 4.

```C++
#include<iostream>
#include<string>
using namespace std;

int main() {
	string lastName;
	string firstName;
	string allName;
	cout << "Enter your first name: ";
	cin >> firstName;
	cout << "Enter your last name: ";
	cin>>lastName;
	allName = lastName+" "+ firstName;
	cout << "Here's the information in a single string: " << allName;
}
```

#### 5.

```C++
#include<iostream>
#include<string>
#include<cstring>
using namespace std;

struct CandyBar {
	string brand;
	double weight;
	int calorie;
};

int main() {
	CandyBar snack{ "Mocha Munch", 2.3,350 };
	cout << "brand: " << snack.brand << endl;
	cout << "weight: " << snack.weight << endl;
	cout << "calorie: " << snack.calorie << endl;
}
```

#### 6.

```C++
#include<iostream>
#include<string>
using namespace std;

struct CandyBar {
	string brand;
	double weight;
	int calorie;
};

int main() {
	CandyBar snack[3]{ { "Mocha Munch", 2.3,350 },{ "Mocha Munch", 2.3,350 } };
	for (int i = 0;i < 3;i++) {
		cout << "snack" << i << ": " << endl;
		cout << "brand: " << snack[i].brand << endl;
		cout << "weight: " << snack[i].weight << endl;
		cout << "calorie: " << snack[i].calorie << endl<<endl;
	}
}
```

#### 7.

```C++
#include<iostream>
#include<string>
using namespace std;

struct pissa {
	string company;
	double diameter;
	double weight;
 };

int main() {
	pissa myPissa;
	cout << "Please enter the company: ";
	getline(cin, myPissa.company);
	cout << "Please enter the diameter: ";
	cin >> myPissa.diameter;
	cout << "Please enter the weight: ";
	cin >> myPissa.weight;
	cout << "myPissa's company: " << myPissa.company << endl;
	cout << "myPissa's diameter: " << myPissa.diameter << endl;
	cout << "myPissa's weight: " << myPissa.weight << endl;
}
```

#### 8.

```C++
#include<iostream>
#include<string>
using namespace std;

struct pissa {
	string company;
	double diameter;
	double weight;
 };

int main() {
	pissa* myPissa=new pissa;
	cout << "Please enter the diameter: ";
	cin >> myPissa->diameter;
	cout << "Please enter the company: ";
	getline(cin, myPissa->company);
	cout << "Please enter the weight: ";
	cin >> myPissa->weight;
	cout << "myPissa's company: " << myPissa->company << endl;
	cout << "myPissa's diameter: " << myPissa->diameter << endl;
	cout << "myPissa's weight: " << myPissa->weight << endl;
    delete pissa;
}
```

#### 9.

```C++
#include<iostream>
#include<string>
using namespace std;

struct CandyBar {
	string brand;
	double weight;
	int calorie;
};

int main() {
	CandyBar* snack = new CandyBar[3]{ {"Mocha Munch",2.3,350},{},{}};
	for (int i = 0;i < 3;i++) {
		cout << "snack" << i << ": " << endl;
		cout << "brand: " << snack[i].brand << endl;
		cout << "weight: " << snack[i].weight << endl;
		cout << "calorie: " << snack[i].calorie << endl << endl;
	}
	delete[] snack;
}
```

#### 10.

```C++
#include<iostream>
#include<string>
#include<array>
using namespace std;


int main() {
	array<int,3> points;
	cout << "Please enter three your points in 40 meters: ";
	cin >> points[0] >> points[1] >> points[2];
	cout << "3 times" << endl;
	cout << "average value: " << (points[0] + points[1] + points[2])*1.0 / 3 << endl;
}
```

### 第五章

#### 1.

```C++
#include<iostream>
#include<string>
#include<array>
using namespace std;


int main() {
	int left, right;
	cout << "Please enter two nembers.The first number should smaller than the second nember: " << endl;
	cin >> left >> right;
	int sum = 0;
	for (int i = left;i <= right;i++) {
		sum += i;
	}
	cout << "The sum of integers between " << "\"" << left << "\"" << " and " << "\"" << right << "\"" << " is ";
	cout << sum << endl;
}
```

#### 2.

```C++
#include<iostream>
#include<string>
#include<array>
using namespace std;
const int ArSize = 101;
int main() {
	array<long double, ArSize> factorials;
	factorials[1] = factorials[0] = 1;
	for (int i = 2;i < ArSize;i++) {
		factorials[i] = i * factorials[i - 1];
	}
	for (int i = 0;i < ArSize;i++) {
		cout << i << "! = " << factorials[i] << endl;
	}
}
```

#### 3.

```C++
#include<iostream>
#include<string>
#include<array>
using namespace std;
const int ArSize = 101;
int main() {
	int num;
	int sum = 0;
	cin >> num;
	while (num != 0) {
		sum += num;
		cout << "The sum has been " << sum << endl;
		cout << "please enter a number: ";
		cin >> num;
	}
}
```

#### 4.

```C++
#include<iostream>
#include<string>
#include<array>
using namespace std;
const int ArSize = 101;
int main() {
	double Cmoney = 100;
	double Dmoney = 100;
	int year = 0;
	while (Cmoney <= Dmoney) {
		year++;
		Cmoney = Cmoney * 1.05;
		Dmoney = Dmoney + 10;
	}
	cout <<"after" << year << "years"<< endl;
	cout << "Cleo: " << Cmoney << endl;
	cout << "Daphne: " << Dmoney << endl;
}
```

#### 5.

```C++
#include<iostream>
#include<string>
#include<array>
using namespace std;
const int ArSize = 101;
int main() {
	string months[12] = {
		"January",
		"February",
		"March",
		"April",
		"May",
		"June",
		"July",
		"August",
		"September",
		"October",
		"November",
		"December"
	};
	int salesQuantity[12];
	cout << "Please enter the sales quantities every months this year."<<endl;
	int sum = 0;
	for (int i = 0;i < 12;i++) {
		cout << months[i] << ": ";
		cin >> salesQuantity[i];
		sum += salesQuantity[i];
	}
	for (int i = 0;i < 12;i++) {
		cout << months[i] << ": ";
		cout<< salesQuantity[i]<<endl;
	}
	cout << "All:" << sum << endl;
}
```

#### 6.

```C++
#include<iostream>
#include<string>
#include<array>
using namespace std;
const int ArSize = 101;
int main() {
	string months[12] = {
		"January",
		"February",
		"March",
		"April",
		"May",
		"June",
		"July",
		"August",
		"September",
		"October",
		"November",
		"December"
	};
	int salesQuantity[3][12];
	int all = 0;
	for (int j = 0;j < 3;j++) {
		cout << "Please enter the sales quantities every months this year." << endl;
		int sum = 0;
		for (int i = 0;i < 12;i++) {
			cout << months[i] << ": ";
			cin >> salesQuantity[j][i];
			sum += salesQuantity[j][i];
			all += salesQuantity[j][i];
		}
		for (int i = 0;i < 12;i++) {
			cout << months[i] << ": ";
			cout << salesQuantity[j][i] << endl;
		}
		cout << "all of this year:" << sum << endl;
	}
	cout << "All:" << all << endl;
}
```

#### 7.

```C++
#include<iostream>
#include<string>
#include<array>
using namespace std;
struct car {
	string make;
	int year;
};
int main() {
	int num;
	cout << "How many cars do you wish to catalog? ";
	cin >> num;
	getchar();
	car* cars = new car[num];
	for (int i = 0;i < num;i++) {
		cout << "Car #" << i + 1 << endl;
		cout << "Please enter the make: ";
		getline(cin,cars[i].make);
		cout << "Please enter year made: ";
		cin >> cars[i].year;
		getchar();
	}
	cout << "Here is your collection: " << endl;
	for (int i = 0;i < num;i++) {
		cout << cars[i].year << " " << cars[i].make << endl;
	}
}
```

#### 8.

```C++
#include<iostream>
#include<string>
#include<array>
using namespace std;
int main() {
	cout << "Enter words (to stop, type the word done: " << endl;
	string str;
	cin >> str;
	int count = 0;
	while (str != "done") {
		count++;
		cin >> str;
	}
	cout << "You entered a total of " << count << " words." << endl;
}
```

#### 9.同上

#### 10.

```C++
#include<iostream>
#include<string>
#include<array>
using namespace std;
int main() {
	cout << "Enter number of rows: ";
	int num;
	cin >> num;
	for (int i = 0;i < num;i++) {
		for (int j = 0;j < num - 1 - i;j++)cout << ".";
		for (int j = 0;j <= i;j++)cout << "*";
		cout << endl;
	}
}
```

### 第六章

#### 1.

```C++
#include<iostream>
#include<string>
#include<array>
using namespace std;
int main() {
	char ch;
	cin >> ch;
	while (ch != '@') {
		if (isalpha(ch)) {
			if (ch >= 'a' && ch <= 'z') {
				ch=ch+'A'-'a';
			}
			else {
				ch=ch+'a'-'A';
			}
		}
		if(ch>'9'||ch<'0')cout << ch;
		cin >> ch;
	}
}
```

#### 2.

```C++
#include<iostream>
#include<string>
#include<array>
using namespace std;
int main() {
	double D[10];
	int count = 0;
	while (count < 10&& cin >> D[count]) {
		count++;
	}

	double sum = 0;
	for (int i = 0;i < count;i++) {
		sum += D[i];
	}
	sum /= count;
	int num=0;
	for (int i = 0;i < count;i++) {
		if (D[i] > sum)num++;
	}
	cout << "average: " << sum << endl;
	cout << num << endl;
}
```

#### 3.

```C++
#include<iostream>
#include<string>
#include<array>
using namespace std;
int main() {
	cout << "Please enter one of the following choices" << endl;
	cout << "c) carnivore        p) pianist" << endl;
	cout << "t) tree             g) game" << endl;
	char ch;
	cout << "Please enter a c, p, t, or g: ";
	cin >> ch;
	while (!(ch == 'c' || ch == 'p' || ch == 't' || ch == 'g')) {
		cout << "Please enter a c, p, t, or g: ";
		cin >> ch;
	}
	cout << "A maple is a ";
	switch (ch) {
	case 'c':cout << "carnivore.";break;
	case 'p':cout << "pianist.";break;
	case 't':cout << "tree.";break;
	case 'g':cout << "game";break;
	}
}
```

#### 4.

```C++
#include<iostream>
#include<string>
#include<array>
using namespace std;
const int strsize = 40;
struct bop {
	char fullname[strsize];
	char title[strsize];
	char bopname[strsize];
	int preference;
};
int main() {
	bop example[5]{
		{"Wimp Macho","C++","whatever",0},
		{"Raki Rhodes","Junior Programmer","whatever",1},
		{"Celia Laiter","whatever","MIPS",2},
		{"Hoppy Hipman","Analyst Trainee","hello",1},
		{"Pat Hand","whatever","LOOPY ONE",2}
	};

	cout << "Benevolent Order of Programmers Report" << endl;
	cout << "a. display by name      b.display by title" << endl;
	cout << "c. display by bopname   d. display by preference" << endl;
	cout << "q. quit" << endl;
	cout << "Enter your choice: ";
	char ch;
	cin >> ch;
	while (ch != 'q') {
		switch (ch) {
		case 'a':
			for (int i = 0;i < 5;i++) {
				cout << example[i].fullname << endl;
			}
			break;
		case 'b':
			for (int i = 0;i < 5;i++) {
				cout << example[i].title << endl;
			}
			break;
		case 'c':
			for (int i = 0;i < 5;i++) {
				cout << example[i].bopname << endl;
			}
			break;
		case 'd':
			for (int i = 0;i < 5;i++) {
				switch (example[i].preference) {
				case 0:
					cout << example[i].fullname << endl;
					break;
				case 1:
					cout << example[i].title << endl;
					break;
				case 2:
					cout << example[i].bopname << endl;
					break;
				}
			}
			break;
		}
		cout << "Next choice: ";
		cin >> ch;
	}
	cout << "Bye!" << endl;
}
```

#### 5.

```C++
#include<iostream>
#include<string>
#include<array>
using namespace std;
int main() {
	cout << "Please enter your revenue: ";
	double revenue;
	double tax;
	while (cin>>revenue) {
		if (revenue < 0)break;
		if (revenue <= 5000) {
			tax = 0;
			cout <<"tax: "<<tax<< endl;
		}
		else if(revenue<=15000){
			tax = (revenue - 5000) * 0.1;
			cout << "tax: " << tax << endl;
		}
		else if (revenue <= 35000) {
			tax = 10000 * 0.1 + (revenue - 15000) * 0.15;
			cout << "tax: " << tax << endl;
		}
		else {
			tax = 10000 * 0.1 + 20000 * 0.15 + (revenue - 35000) * 0.2;
			cout << "tax: " << tax << endl;
		}
		cout << "Please enter your revenue: ";
	}
	cout << "END" << endl;
}
```

#### 6.

```c++
#include<iostream>
#include<string>
#include<array>
using namespace std;
struct partron {
	string name;
	double money;
};

int main() {
	cout << "Please enter a number: ";
	int num;
	cin >> num;
	getchar();
	partron* partrons = new partron[num];
	for (int i = 0;i < num;i++) {
		cout << "Please enter the name: ";
		getline(cin, partrons[i].name);
		cout << "Please enter the value of money: ";
		cin >> partrons[i].money;
		getchar();
	}
	int count = 0;
	cout << "Grand Patrons: " << endl;
	for (int i = 0;i < num;i++) {
		if (partrons[i].money > 10000) {
			cout << partrons[i].name << ": " << partrons[i].money << endl;
			count++;
		}
	}
	if (count == 0)cout << "none" << endl;
	cout << "Patrons: " << endl;
	for (int i = 0;i < num;i++) {
		if (partrons[i].money <= 10000) {
			cout << partrons[i].name << ": " << partrons[i].money << endl;
		}
	}
	if (num - count == 0)cout << "none" << endl;
}
```

#### 7.

```c++
#include<iostream>
#include<string>
#include<array>
using namespace std;

int main() {
	cout << "Enter words (q to quit):" << endl;
	string str;
	cin >> str;
	int vowels=0;
	int consonants=0;
	int others=0;
	while (str!="q") {
		if (isalpha(str[0])) {
			switch (str[0]) {
			case'a':
			case'e':
			case'i':
			case'o':
			case'u':vowels++;break;
			default:consonants++;
			}
		}
		else {
			others++;
		}
		cin >> str;
	}
	cout << vowels << " words beginning with vowels" << endl;
	cout << consonants << " words beginning with consonants" << endl;
	cout << others << " others"<<endl;
}
```

#### 8.

```c++
#include<iostream>
#include<string>
#include<fstream>
using namespace std;

int main() {
	string filename = "test.txt";
	ifstream inFile;
	inFile.open(filename);
	if (!inFile.is_open()) {
		cout << "Could not open the file " << filename << endl;
		cout << "Program terminating." << endl;
		exit(EXIT_FAILURE);
	}
	char ch;
	int count = 0;
	while (inFile >> ch) {
		count++;
	}
	cout << "There are " << count << " characters in " << filename << endl;
}
```

#### 9.略

### 第七章

#### 1.

```c++
#include<iostream>
#include<string>
#include<fstream>
using namespace std;
double	harmonic_mean(double, double);
int main() {
	int a, b;
	cout << "Please enter two numbers: ";
	cin >> a >> b;
	while (a != 0 && b != 0) {
		cout <<"harmonic mean: " << harmonic_mean(a, b)<<endl;
		cout << "Please enter two numbers: ";
		cin >> a >> b;
	}
	cout << "END" << endl;
}
double harmonic_mean(double a, double b) {
	return 2 * a * b / (a + b);
}
```

#### 2.

```c++
#include<iostream>
#include<string>
#include<fstream>
using namespace std;
int input(double*,int);
void display(double*,int);
double mean(double*,int);
int main() {
	double a[10];
	int size=input(a, 10);
	display(a, size);
}
int input(double* a,int n) {
	int count = 0;
	while (count<10 && cin >> a[count]) {
		count++;
	}
	return count;
}
void display(double* a,int n) {
	for (int i = 0;i < n;i++) {
		cout << a[i] << " ";
	}
	cout << endl;
	cout << "mean: " << mean(a, n);
};
double mean(double* a, int n) {
	double sum = 0;
	for (int i = 0;i < n;i++) {
		sum += a[i];
	}
	return sum / n;
};
```

#### 3.

```c++
#include<iostream>
#include<string>
#include<fstream>
using namespace std;
struct box {
	char maker[40];
	float height;
	float width;
	float length;
	float volume;
};
void display(struct box );
void set_volume(struct box*);
int main() {
	struct box example {
		"example",1.2,2.5,2.7,1.0
	};
	display(example);
	set_volume(&example);
	display(example);
}
void display(struct box example) {
	cout <<"maker: " << example.maker << endl;
	cout <<"height: " << example.height << endl;
	cout << "width: " << example.width << endl;
	cout << "length: " << example.length << endl;
	cout << "volume: " << example.volume << endl;
}
void set_volume(struct box* a) {
	a->volume = a->height * a->width * a->length;
}
```

#### 4.

```c++
#include<iostream>
#include<string>
#include<fstream>
using namespace std;
long double probability(unsigned numbers, unsigned picks);
int main() {
	cout << 1/probability(47,5)/27;
}
long double probability(unsigned numbers, unsigned picks) {
	long double result = 1.0;
	long double n;
	unsigned p;

	for (n = numbers, p = picks; p > 0;n--, p--) {
		result = result * n / p;
	}
	return result;
}
```

#### 5.

```c++
#include<iostream>
#include<string>
#include<fstream>
using namespace std;
long double f(int n);
int main() {
	int n;
	cout << "Please enter a number: ";
	while (cin >> n) {
		cout << n << "!= " << f(n)<<endl;
		cout << "Pleaes enter a number: ";
	}
}
long double f(int n) {
	if (n == 0)return 1;
	return n*f(n - 1);
}

```

#### 6.

```c++
#include<iostream>
#include<string>
#include<fstream>
using namespace std;
int Fill_array(double*, int);
void Show_array(double*, int);
void Reverse_array(double*, int);

int main() {
	double Arr[10];
	int num;
	num = Fill_array(Arr, 10);
	Show_array(Arr, num);
	Reverse_array(Arr, num);
	Show_array(Arr, num);
}
int Fill_array(double* Arr, int n) {
	int count = 0;
	while (count<n && cin >> Arr[count]) {
		count++;
	}
	return count;
}
void Show_array(double* Arr, int n) {
	for (int i = 0;i < n;i++) {
		cout << Arr[i] << " ";
	}
	cout << endl;
}
void Reverse_array(double* Arr, int n) {
	for (int i = 1;i < n / 2;i++) {
		double temp = Arr[i];
		Arr[i] = Arr[n - 1 - i];
		Arr[n - 1 - i] = temp;
	}
}

```

#### 7.

```c++
#include<iostream>
#include<string>
#include<fstream>
using namespace std;
double* Fill_array(double*, int);
void Show_array(double*, double *p);
void Reverse_array(double*, double *p);

int main() {
	double Arr[10];
	double *p=Fill_array(Arr, 10);
	Show_array(Arr, p);
	Reverse_array(Arr, p);
	Show_array(Arr, p);
}
double *Fill_array(double* Arr, int n) {
	int count = 0;
	while (count<n && cin >> Arr[count]) {
		count++;
	}
	return Arr+count;
}
void Show_array(double* Arr, double *p) {
	int n = p - Arr;
	for (int i = 0;i < n;i++) {
		cout << Arr[i] << " ";
	}
	cout << endl;
}
void Reverse_array(double* Arr, double *p) {
	int n = p - Arr;
	for (int i = 1;i < n / 2;i++) {
		double temp = Arr[i];
		Arr[i] = Arr[n - 1 - i];
		Arr[n - 1 - i] = temp;
	}
}
```

#### 8.

##### a.

```c++
#include<iostream>
#include<string>
#include<fstream>
using namespace std;
const int Seasons = 4;
const int maxSnameSize = 10;
const char Snames[Seasons][maxSnameSize]{
	"Spring",
	"Summer",
	"Fall",
	"Winter"
};
void fill(double*);
void show(double*);

int main() {
	double expenses[Seasons];
	fill(expenses);
	show(expenses);
}
void fill(double* pa) {
	for (int i = 0;i < Seasons;i++) {
		cout << "Enter " << Snames[i] << " expenses: ";
		cin >> pa[i];
	}
}
void show(double* da) {
	double total = 0.0;
	cout << "EXPENSES\n";
	for (int i = 0;i < Seasons;i++) {
		cout << Snames[i] << ": $" << da[i] << endl;
		total += da[i];
	}
	cout << "Total Expenses: $" << total << endl;
}

```

##### b.

```c++
#include<iostream>
#include<string>
#include<fstream>
using namespace std;
const int Seasons = 4;
const int maxSnameSize = 10;
const char Snames[Seasons][maxSnameSize]{
	"Spring",
	"Summer",
	"Fall",
	"Winter"
};
struct expense {
	double expenses[4];
};
void fill(struct expense*);
void show(struct expense*);

int main() {
	struct expense expenses;
	fill(&expenses);
	show(&expenses);

}
void fill(struct expense *expenses) {
	for (int i = 0;i < Seasons;i++) {
		cout << "Enter " << Snames[i] << " expenses: ";
		cin >> expenses->expenses[i];
	}
}
void show(struct expense *expenses) {
	double total = 0.0;
	cout << "EXPENSES\n";
	for (int i = 0;i < Seasons;i++) {
		cout << Snames[i] << ": $" << expenses->expenses[i] << endl;
		total += expenses->expenses[i];
	}
	cout << "Total Expenses: $" << total << endl;
}

```

#### 9.

```c++
#include<iostream>
#include<string>
#include<fstream>
using namespace std;
const int SLEN = 30;
struct student {
	char fullname[SLEN];
	char hobby[SLEN];
	int ooplevel;
};
int getinfo(student pa[], int n);
void display1(student st);
void display2(const student* ps);
void display3(const student pa[], int n);
int main() {
	cout << "Enter class size: ";
	int class_size;
	cin >> class_size;
	while (cin.get() != '\n')continue;
	student* ptr_stu = new student[class_size];
	int entered = getinfo(ptr_stu, class_size);
	for (int i = 0;i < entered;i++) {
		display1(ptr_stu[i]);
		display2(&ptr_stu[i]);
	}
	display3(ptr_stu, entered);
	delete[]  ptr_stu;
	cout << "Done\n";
	return 0;
}
int getinfo(student pa[], int n) {
	int count = 0;
	cout << "Please enter the fullname: ";
	cin >> pa[count].fullname;
	if (pa[count].fullname == NULL) return count;
	cout << "Please enter the hobby: ";
	cin >> pa[count].hobby;
	cout << "Please enter the ooplevel: ";
	cin >> pa[count].ooplevel;
	count++;
	while (count<n&&pa[count].fullname!=NULL) {
		cout << "Please enter the fullname: ";
		cin >> pa[count].fullname;
		if (pa[count].fullname == NULL) return count;
		cout << "Please enter the hobby: ";
		cin >> pa[count].hobby;
		cout << "Please enter the ooplevel: ";
		cin >> pa[count].ooplevel;
		count++;
	}
}
void display1(student st) {
	cout<<"display1: ";
	cout <<"fullname: " << st.fullname << "   hobby: " << st.hobby << "   ooplevel: " << st.ooplevel << endl;
}
void display2(const student* ps) {
	cout << "display2: ";
	cout << "fullname: " << ps->fullname << "   hobby: " << ps->hobby << "   ooplevel: " << ps->ooplevel << endl;
}
void display3(const student pa[], int n) {
	cout <<"display3: " << endl;
	for (int i = 0;i < n;i++) {
		cout << "fullname: " << pa[i].fullname << "   hobby: " << pa[i].hobby << "   ooplevel: " << pa[i].ooplevel << endl;
	}
}
```

#### 10.

```c++
#include<iostream>
#include<string>
#include<fstream>
using namespace std;
double add(double, double);
double calculate(double, double, double (*pf)(double, double));
int main() {
	double a, b;
	cout << "Please enter two numbers: ";
	while (cin >> a >> b) {
		cout << "calculate result: " << calculate(a, b, add)<<endl;
		cout << "Please enter two numbers: ";
	}
}
double add(double a, double b) {
	return a + b;
}
double calculate(double a, double b, double (*pf)(double, double)) {
	return pf(a, b);
}
```

### 第八章

#### 1.

```c++
#include<iostream>
#include<string>
#include<fstream>
using namespace std;
int cc = 0;
void print(const string&);
void print(const string&, int);
int main() {
	string str = "test";
	print(str, 0);
	print(str, 1);
	print(str);
	print(str, 1);
	print(str);
}
void print(const string& str) {
	cout << str << endl;
	cc++;
}
void print(const string& str, int num) {
	cc++;
	if (num != 0) {
		for (int i = 0;i < cc;i++) {
			cout << str <<" ";
		}
		cout << endl;
	}
}
```

#### 2.

```c++
#include<iostream>
#include<string>
#include<fstream>
using namespace std;
struct CandyBar {
	string bland;
	double weight;
	int calorie;
};
void setCandyBar(CandyBar&,const char*, double, int);
void display(const CandyBar&);
int main() {
	CandyBar example;
	setCandyBar(example, "Millennium Munch", 2.85, 350);
	display(example);
}
void setCandyBar(CandyBar& example, const char* bland, double weight, int calorie) {
	example.bland = bland;
	example.weight = weight;
	example.calorie = calorie;
	cout << "set success" << endl;
}
void display(const CandyBar& example) {
	cout<<"bland: " << example.bland << endl;
	cout<<"weight: " << example.weight << endl;
	cout<<"calorie: " << example.calorie << endl;
}

```

#### 3.

```c++
#include<iostream>
#include<string>
#include<fstream>
using namespace std;
void toUpper(string&);
int main() {
	string str;
	cout << "Enter a string (q to quit): ";
	getline(cin, str);
	while (str != "q") {
		toUpper(str);
		cout << str << endl;
		cout << "Next string (q to quit): ";
		getline(cin, str);
	}
	cout << "Bye.";
}
void toUpper(string& str) {
	for (int i = 0;i < str.size();i++) {
		str[i] = toupper(str[i]);
	}
}

```

#### 4.

```c++
#include<iostream>
#include<string>
#include<cstring>
using namespace std;
struct stringy {
	char* str;
	int ct;
};
void set(stringy&,const string &);
void show(const stringy&);
void show(const stringy&, const int);
void show(const string&);
void show(const string&, const int);
int main() {
	stringy beany;
	char testing[] = "Reality isn't what it used to be.";

	set(beany, testing);
	show(beany);
	show(beany, 2);
	testing[0] = 'D';
	testing[1] = 'u';
	show(testing);
	show(testing,3);
	show("Done!");
	return 0;
}
void set(stringy& stry, const string& str) {
	stry.str = new char[str.size() + 1];
	stry.str[str.size()] = '\0';
	for (int i = 0;i < str.size();i++) {
		stry.str[i] = str[i];
	}
	stry.ct = str.size();
}
void show(const stringy& stry, const int times) {
	for(int i=0;i<times;i++)cout << stry.str << endl;
}
void show(const stringy& stry) {
	cout << stry.str << endl;
}
void show(const string& str) {
	cout << str << endl;
}
void show(const string& str, const int times) {
	for (int i = 0;i < times;i++) {
		cout << str << endl;
	}
}
```

#### 5.

```c++
#include<iostream>
#include<string>
#include<cstring>
using namespace std;
template <typename T>
T max5(T test[]) {
	T max = test[0];
	for (int i = 0;i < 5;i++) {
		if (max < test[i])max = test[i];
	}
	return max;
};
int main() {
	double test1[] = { 1.1,2.2,5.5,7.9,7.3 };
	int test2[] = { 5,1,9,8,6 };
	cout<<max5<double>(test1)<<endl;
	cout<<max5<int>(test2)<<endl;
}

```

#### 6.

```c++
#include<iostream>
#include<string>
#include<cstring>
using namespace std;
template <typename T>
T maxn(T test[],int size) {
	T max = test[0];
	for (int i = 0;i < size;i++) {
		if (max < test[i])max = test[i];
	}
	return max;
};
int main() {
	double test1[] = { 1.1,2.2,5.5,7.9,7.3 };
	int test2[] = { 5,1,9,8,6,80 };
	char* str[5];
	for (int i = 0;i < 5;i++) {
		str[i] = new char[50]{"string"};
	}
	cout<<maxn<double>(test1,4)<<endl;
	cout<<maxn<int>(test2,6)<<endl;
	cout << maxn<char*>(str, 5) << endl;
}
```

#### 7.

```

```

### 第九章

#### 1.

```C++
#include "glof.h"
#include <iostream>
using std::cout;
using std::cin;
void setgolf(golf& g, const char* name, int hc) {
	for (int i = 0;i < Len;i++) {
		g.fullname[i] = name[i];
	}
	g.handicap = hc;
}
int setgolf(golf& g) {
	g.fullname[Len - 1] = '\0';
	cout << "Please enter a name: ";
	cin >> g.fullname;
	if (g.fullname[Len - 1] != '\0') {
		cout << "The Length of name is longer than the maxsize " << std::endl;
		return 0;
	}
	else if (g.fullname[0] == '\0') {
		cout << "the name is NULL" << std::endl;
		return 0;
	}
	cout << "Please enter a number: ";
	cin >> g.handicap;
	return 1;
}
void handicap(golf& g, int hc) {
	g.handicap = hc;
}
void showgolf(const golf& g) {
	cout << "fullname: " << g.fullname << std::endl;
	cout << " handicap: " << g.handicap << std::endl;
}
```

#### 2.

```c++
#include <iostream>
#include <string>
using namespace std;
const int ArSize = 10;
void strcount(const string &str);

int main() {
	using namespace std;
	string input;
	char next;

	cout << "Enter a line:\n";
	getline(cin, input);
	while (input.size()!=0) {
		strcount(input);
		cout << "Enter next line (empty line to quit):\n";
		getline(cin, input);
	}
	cout << "Bye\n";
	return 0;
}
void strcount(const string &str)
{
	using namespace std;
	static int total = 0;
	int count = str.size();
	total += count;
	cout << "\"" << str << "\" contains ";
	cout << count << " characters\n";
	cout << total << " characters total\n";
}
```

#### 3.

```c++

```

### 第十章

#### 1.

```c++
#include <iostream>
#include <string>
using namespace std;
class account {
private:
	string name;
	string number;
	int deposit;
public:
	account() :name("xiao ming"), number("111111"), deposit(0) {};
	void show() const;
	void save(int money);
	void remove(int money);
};
int main() {
	account one;
	one.show();
	one.save(100);
	one.show();
	one.save(-50);
	one.show();
	one.remove(150);
	one.show();
	one.remove(50);
	one.show();
	return 0;
}
void account::show() const {
	cout << "name: " << name << endl;
	cout << "number: " << number << endl;
	cout << "deposit: " << deposit << endl;
}
void account::save(int money) {
	if (money ) {
		cout << "Failed!The money should not be less then zero." << endl;
		return;
	}
	deposit += money;
}
void account::remove(int money) {
	if (money < 0) {
		cout << "Failed!The money should not be less then zero." << endl;
		return;
	}
	if (deposit < money) {
		cout << "Failed! The money should not be larger then deposit." << endl;
		return;
	}
	deposit -= money;
}
```



#### 2.

```C++
#include <iostream>
#include <string>
using namespace std;
class Person {
private:
	static const  int LIMIT = 25;
	string lname;
	char fname[LIMIT];
public:
	Person() { lname = ""; fname[0] = '\0'; }
	Person(const string& in, const char* fn = "Heyyou");
	void show() const;
	void FormalShow() const;
};
int main() {
	Person one;
	Person two("Smythecragt");
	Person three("dimwiddy", "Sam");
	two.show();
	cout << endl;
	two.FormalShow();
	return 0;
}
Person::Person(const string& in, const char* fn) {
	lname = in;
	for (int i = 0;i < LIMIT;i++) {
		fname[i] = fn[i];
	}
}
void Person::show()const {
	cout << fname<<" "<< lname << endl;
};
void Person::FormalShow() const {
	cout << lname << "," << fname << endl;
};
```

#### 3.

```C++
//golf.h
#pragma once
#include<iostream>
#include<string>
using namespace std;
class golf {
	enum{Len=30};
private:
	string fullname;
	int handicap;
public:
	void setgolf(const char* name, int hc);
	int setgolf();
	void sethandicap(int hc);
	void showgolf();
};

//golf.cpp
#include <iostream>
#include "golf.h"
void golf::setgolf(const char* name, int hc) {
	for (int i = 0;i < Len;i++) {
		fullname[i] = name[i];
	}
	handicap = hc;
}
int golf::setgolf() {
	fullname[Len - 1] = '\0';
	cout << "Please enter a name: ";
	cin >> fullname;
	if (fullname[Len - 1] != '\0') {
		cout << "The Length of name is longer than the maxsize " << std::endl;
		return 0;
	}
	else if (fullname[0] == '\0') {
		cout << "the name is NULL" << std::endl;
		return 0;
	}
	cout << "Please enter a number: ";
	cin >> handicap;
	return 1;
}
void golf::sethandicap(int hc) {
	handicap = hc;
}
void golf::showgolf() {
	cout << "fullname: " << fullname << std::endl;
	cout << "handicap: " << handicap << std::endl;
}

```

#### 4.

```C++
//sales.h
#pragma once
#include<iostream>
#include<string>
using namespace std;
namespace SALES {
	const int QUARTERS = 4;
	class Sales
	{
	private:
		double sales[QUARTERS];
		double average;
		double max;
		double min;
	public:
		void setSales(const double ar[], int n);
		void setSales();
		void showSales();
	};
}

//sales.cpp
#include <iostream>
#include "sales.h"
using namespace SALES;
void Sales::setSales(const double ar[], int n) {
	double themax = ar[0];
	double themin = ar[0];
	double sum = 0;
	for (int i = 0;i < n;i++) {
		sales[i] = ar[i];
		sum += ar[i];
		if (themax < ar[i])themax = ar[i];
		if (themin > ar[i])themin = ar[i];
	}
	max = themax;
	min = themin;
	average = sum / n;
}
void Sales::setSales() {
	cout << "Please enter 4 sales: ";
	for (int i = 0;i < 4;i++) {
		cin >> sales[i];
	}
	double themax = sales[0];
	double themin = sales[0];
	double sum = 0;
	for (int i = 0;i < 4;i++) {
		sum += sales[i];
		if (themax < sales[i])themax = sales[i];
		if (themin > sales[i])themin = sales[i];
	}
	max = themax;
	min = themin;
	average = sum / 4;
}
void Sales::showSales() {
	cout << "sales: ";
	for (int i = 0;i < 4;i++) {
		cout << sales[i] << " ";
	}
	cout << endl;
	cout << "average: " << average << endl;
	cout << "max: " << max << endl;
	cout << "min: " << min << endl;
}
```

#### 5.

```c++
#include <iostream>
#include <string>
#include <stack>
using namespace std;
const int MAX = 10;
struct customer {
	char fullname[35];
	double payment;
};
class Stack {
private:
	customer items[MAX];
	int top;
public:
	Stack() :top(0) {};
	bool isempty() const { return top == 0; };
	bool isfull() const { return top == MAX; };
	bool push(const customer& item) {
		if (top < MAX) {
			items[top++] = item;
			return true;
		}
		return false;
	}

	bool pop(customer & item) {
		if (top > 0) {
			item = items[--top];
			return true;
		}
		return false;
	}
};
int main() {
	Stack st;
	customer temp;
	double totalPayment = 0.0;

	customer c1 = { "Alice Smith", 100.0 };
	customer c2 = { "Bob Johnson", 200.0 };
	customer c3 = { "Charlie Brown",300.0 };

	st.push(c1);
	st.push(c2);
	st.push(c3);

	while (!st.isempty()) {
		st.pop(temp);
		totalPayment += temp.payment;
		cout << "Customer: " << temp.fullname << ", Payment: " << temp.payment << endl;
	}

	cout << "Total Payment: " << totalPayment << endl;

	return 0;
}

```

#### 6.

```c++
#include <iostream>
#include <string>
#include <stack>
using namespace std;
class Move
{
private:
	double x;
	double y;
public:
	Move(double a = 0, double b = 0):x(a),y(b) {};
	void showmove() const {
		cout << "x: " << x << ",y: " << y << endl;
	};
	Move add(const Move& m) const {
		return Move(x + m.x, y + m.y);
	};
	void reset(double a = 0, double b = 0) {
		x = a;
		y = b;
	};
};
int main() {
	Move m1(10, 20);
	Move m2(5, 15);
	cout << "Initial positions:" << endl;
	m1.showmove();
	m2.showmove();

	Move m3 = m1.add(m2);
	cout << "After adding m1 and m2:" << endl;
	m3.showmove();
	m1.reset();
	cout << "After resetting m1:" << endl;
	m1.showmove();

	return 0;
}
```

#### 7.

```c++
#include <iostream>
#include <string>
#include <stack>
using namespace std;
const int MAX = 20;
class Plorg {
private:
	char name[MAX];
	int CI;
public:
	Plorg(string str="Plorga", int x = 50) {
		if (str.size() < MAX) {
			for (int i = 0;i < str.size();i++) {
				name[i] = str[i];
			}
			name[str.size()] = '\0';
		}
		  
		else {
			cout << "Failed.The size of name is out of range." << endl;
		}
		CI = x;
	}
	void setCI(int x) {
		CI = x;
	}
	void show() const {
		cout << "name: " << name <<endl<< "CI: " << CI << endl;
	}
};

int main() {
	Plorg item;
	item.show();
	int CI = 90;
	item.setCI(CI);
	item.show();
	Plorg example("name", 20);
	example.show();
	return 0;
}

```

#### 8.

```c++
//分文件有点麻烦，
#include <iostream>
#include <string>
#include <stack>
using namespace std;
const int SIZE = 10;
template <typename T>
class List {
private:
	T item[SIZE];
	int n;
public:
	List() :n(0) {};
	bool isempty() {
		return n == 0;
	}
	bool isfull() {
		return n == SIZE;
	}
	void push(T it) {
		item[n++] = it;
	}
	void visit(void (*pf)(T &)) {
		for (int i = 0;i < n;++i) {
			pf(item[i]);
		}
	}
};
template <typename T>
void printItem(T & item) {
	std::cout << item << " ";
}

int main() {
	List<int> Li;
	cout<<Li.isempty()<<endl;
	cout << Li.isfull() << endl;
	Li.visit(printItem);
	for (int i = 0;i < SIZE;i++) {
		Li.push(i);
	}
	cout << Li.isempty() << endl;
	cout<<Li.isfull()<<endl;
	Li.visit(printItem);
	return 0;
}

```

### 第十一章

#### 1.

11.5有问题？和描述对不上

实际上是修改11.15随机漫步

```c++
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include "vector.h"
using std::ofstream;
int main()
{
	using namespace std;
	using VECTOR::Vector;
	srand(time(0));
	ofstream outfile;
	outfile.open("test.txt");

	double direction;
	Vector step;
	Vector result(0.0, 0.0);
	unsigned long steps = 0;
	double target;
	double dstep;
	cout << "Enter target distance (q to quit): ";
	while (cin >> target)
	{
		cout << "Enter step length: ";
		if (!(cin >> dstep))
			break;
		outfile << "Target Distance: " << target << ", Step Size: " << dstep << endl;
		while (result.magval() < target)
		{
			direction = rand() % 360;
			step.reset(dstep, direction, Vector::POL);
			result = result + step;
			cout <<steps<<": " << result << endl;
			outfile << steps << ": " << result << endl;
			steps++;
		}
		cout << "After " << steps << " steps, the subject has the following location:\n";
		cout << result << endl;
		result.polar_mode();
		cout << " or\n" << result << endl;
		cout << "Average outward distance per step = " << target / steps << endl;
		outfile << "After " << steps << " steps, the subject has the following location:\n";
		outfile << result << endl;
		result.polar_mode();
		outfile << " or\n" << result << endl;
		outfile << "Average outward distance per step = " << target / steps << endl;
		steps = 0;
		result.reset(0.0, 0.0);
		cout << "Enter target distance (q to quit): ";
	}
	cout << "Bye!\n";
	cin.clear();
	while (cin.get() != '\n')continue;
    ofstream.close();
	return 0;
}

```

#### 2.

```c++
//vector.h
// vect.h --- Vector class with <<, mode-state
#ifndef VECTOR_H_
#define VECTOR_H_
#include <iostream>
namespace VECTOR
{
    class Vector
    {
    public:
        enum Mode { RECT, POL };
        // RECT for rectangular, POL for Polar modes
    private:
        double x;    // horizontal value
        double y;    // vertical valuedegrees
        Mode mode;    // RECT or POL
        // private methods for setting values
    public:
        Vector();
        Vector(double n1, double n2, Mode form = RECT);
        void reset(double n1, double n2, Mode form = RECT);
        ~Vector();
        double xval() const { return x; }  // report x value
        double yval() const { return y; }  // report y value
        double magval() const { return sqrt(x*x+y*y); }  // report magnitude

        double angval() const { return atan(y/x); }  // report angle
        void polar_mode();  // set mode to POL
        void rect_mode();   // set mode to RECT

        // operator overloading
        Vector operator+(const Vector& b) const;
        Vector operator-(const Vector& b) const;
        Vector operator-() const;
        Vector operator*(double n) const;

        // friends
        friend Vector operator*(double n, const Vector& a);
        friend std::ostream&
            operator<<(std::ostream& os, const Vector& v);
    };
}
// end namespace VECTOR
#endif
```

```c++
//vector.cpp
#include <iostream>
#include "vector.h"
using std::sqrt;
using std::sin;
using std::cos;
using std::atan;
using std::atan2;
using std::cout;

namespace VECTOR
{
	const double Rad_to_deg = 45.0 / atan(1.0);
	Vector::Vector()
	{
		x = y = 0.0;
		mode = RECT;
	}
	Vector::Vector(double n1, double n2, Mode form)
	{
		mode = form;
		if (form == RECT)
		{
			x = n1;
			y = n2;
		}
		else if (form == POL)
		{
		}
		else
		{
			cout << "Incorrect 3rd argument to Vector() -- ";
			cout << "vector set to 0\n";
			x = y = 0.0;
			mode = RECT;
		}
	}
	void Vector::reset(double n1, double n2, Mode form) 
	{
		mode = form;
		if (form == RECT)
		{
			x = n1;
			y = n2;
		}
		else if (form == POL)
		{
			x = n1 * cos(n2);
			y = n1 * sin(n2);
		}
		else
		{
			cout << "Incorrect 3rd argument to Vector() -- ";
			cout << "vector set to 0\n";
			x = y = 0.0;
			mode = RECT;
		}
	}
	Vector::~Vector()
	{
	}
	
	void Vector::polar_mode()
	{
		mode = POL;
	}
	void Vector::rect_mode()
	{
		mode = RECT;
	}
	Vector Vector::operator+(const Vector& b)const
	{
		return Vector(x + b.x ,y+ b.y);
	}
	Vector Vector::operator-(const Vector& b)const
	{
		return Vector(x - b.x, y - b.y);
	}
	Vector Vector::operator-() const
	{
		return Vector(-x, -y);
	}
	Vector Vector::operator*(double n) const
	{
		return Vector(n * x, n * y);
	}
	Vector operator*(double n, const Vector& a)
	{
		return a * n;
	}

	std::ostream& operator<<(std::ostream& os, const Vector& v)
	{
		if (v.mode == Vector::RECT)os << "(x.y) = (" << v.x << ", " << v.y << ")";
		else if (v.mode == Vector::POL)
		{
			os << "(m,a) = (" << v.magval() << ", " << v.angval() * Rad_to_deg << ")";
		}
		else os << "Vector object mode is invalid";
		return  os;
	}
}
```

```c++
//main.cpp
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include "vector.h"
using std::ofstream;
int main()
{
	using namespace std;
	using VECTOR::Vector;
	srand(time(0));
	ofstream outfile;
	outfile.open("test.txt");

	double direction;
	Vector step;
	Vector result(0.0, 0.0);
	unsigned long steps = 0;
	double target;
	double dstep;
	cout << "Enter target distance (q to quit): ";
	while (cin >> target)
	{
		cout << "Enter step length: ";
		if (!(cin >> dstep))
			break;
		outfile << "Target Distance: " << target << ", Step Size: " << dstep << endl;
		while (result.magval() < target)
		{
			direction = rand() % 360;
			step.reset(dstep, direction, Vector::POL);
			result = result + step;
			cout <<steps<<": " << result << endl;
			outfile << steps << ": " << result << endl;
			steps++;
		}
		cout << "After " << steps << " steps, the subject has the following location:\n";
		cout << result << endl;
		result.polar_mode();
		cout << " or\n" << result << endl;
		cout << "Average outward distance per step = " << target / steps << endl;
		outfile << "After " << steps << " steps, the subject has the following location:\n";
		outfile << result << endl;
		result.polar_mode();
		outfile << " or\n" << result << endl;
		outfile << "Average outward distance per step = " << target / steps << endl;
		steps = 0;
		result.reset(0.0, 0.0);
		cout << "Enter target distance (q to quit): ";
	}
	cout << "Bye!\n";
	cin.clear();
	while (cin.get() != '\n')continue;
	return 0;
}

```

#### 3.

```c++
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include "vector.h"
using std::ofstream;
int main()
{
	using namespace std;
	using VECTOR::Vector;
	srand(time(0));
	ofstream outfile;
	outfile.open("test.txt");

	double direction;
	Vector step;
	Vector result(0.0, 0.0);
	unsigned long steps = 0;
	double target;
	double dstep;
	int N;
	int min = INT_MAX;
	int max = 0;
	double sum = 0;
	cout << "Enter test times: ";
	cin >> N;
	cout << "Enter target distance (q to quit): ";
	cin >> target;
	cout << "Enter step length: ";
	cin >> dstep;
	for (int i = 0;i < N;i++)
	{
		
		outfile << "Target Distance: " << target << ", Step Size: " << dstep << endl;
		while (result.magval() < target)
		{
			direction = rand() % 360;
			step.reset(dstep, direction, Vector::POL);
			result = result + step;
			//cout <<steps<<": " << result << endl;
			//outfile << steps << ": " << result << endl;
			steps++;
		}
		/*cout << "After " << steps << " steps, the subject has the following location:\n";
		cout << result << endl;
		result.polar_mode();
		cout << " or\n" << result << endl;
		cout << "Average outward distance per step = " << target / steps << endl;
		outfile << "After " << steps << " steps, the subject has the following location:\n";
		outfile << result << endl;
		result.polar_mode();
		outfile << " or\n" << result << endl;
		outfile << "Average outward distance per step = " << target / steps << endl;*/
		if (max < steps)max = steps;
		if (min > steps)min = steps;
		sum += steps;
		steps = 0;
		result.reset(0.0, 0.0);
	}
	cout << "max: " << max << endl;
	cout << "min: " << min << endl;
	cout << "average: " << sum / N << endl;
	cout << "Bye!\n";
	cin.clear();
	while (cin.get() != '\n')continue;
	return 0;
}

```

#### 4.

```c++
//mytime3.h
#pragma once
#include <iostream>

class Time
{
private:
	int hours;
	int minutes;
public:
	Time();
	Time(int h, int m = 0);
	void AddMin(int m);
	void AddHr(int h);
	void Reset(int h = 0, int m = 0);
	friend Time operator+(const Time& m, const Time& t);
	friend Time operator-(const Time& m, const Time& t);
	friend Time operator*(double m, const Time& t);
	friend Time operator*(const Time& t, double m) {
		return m * t;
	}
	friend std::ostream& operator<<(std::ostream& os, const Time& t);
};
```

```c++
//mytime3.cpp
#include "mytime3.h"

Time::Time()
{
	hours = minutes = 0;
}
Time::Time(int h, int m)
{
	hours = h;
	minutes = m;
}
void Time::AddMin(int m)
{
	minutes += m;
	hours += minutes / 60;
	minutes %= 60;
}
void Time::AddHr(int h)
{
	hours += h;
}

void Time::Reset(int h, int m)
{
	hours = h;
	minutes = m;
}

Time operator+(const Time& m,const Time& t)
{
	Time sum;
	sum.minutes = m.minutes + t.minutes;
	sum.hours = m.hours + t.hours + sum.minutes / 60;
	sum.minutes %= 60;
	return sum;
}

Time operator-(const Time& m,const Time& t)
{
	Time diff;
	int tot1, tot2;
	tot1 = t.minutes + 60 * t.hours;
	tot2 = m.minutes + 60 * m.hours;
	diff.minutes = (tot2 - tot1) % 60;
	diff.hours = (tot2 - tot1) / 60;
	return diff;
}
Time operator*(double mult, const Time& t)
{
	Time result;
	long totalminutes = t.hours * mult * 60 + t.minutes * mult;
	result.hours = totalminutes / 60;
	result.minutes = totalminutes % 60;
	return result;
}

std::ostream& operator<<(std::ostream& os, const Time& t)
{
	os << t.hours << " hours, " << t.minutes << " minutes";
	return os;
}
```

```c++
//main.cpp
#include <iostream>
#include "mytime3.h"
int main()
{
	using std::cout;
	using std::endl;
	Time aida(3, 55);
	Time tosca(2, 48);
	Time temp;

	cout << "Aida and Tosca:\n";
	cout << aida << ";" << tosca << endl;
	temp = aida + tosca;
	cout << "Aida + Tosca: " << temp << endl;
	temp = aida * 1.17;
	cout << "Aida * 1.17: " << temp << endl;
	cout << "10.0 * Tosca: " << 10.0 * tosca << endl;


	return 0;
}
```

#### 5.

```c++
//main.cpp
#include <iostream>
using std::cout;
#include "stonewt.h"
void display(const Stonewt& st, int n);
int main()
{
	Stonewt incognito = 275;
	Stonewt wolfe(285.7);
	Stonewt taft(21, 8);
	cout << "incognito+wolfe: "<<incognito + wolfe << endl;
	cout << "incognito-wolfe: " << incognito - wolfe << endl;
	cout << "incognito*2.3: " << incognito * 2.3 << endl;

	cout << "The celebrity weighed ";
	incognito.set_stn();
	cout << incognito << endl;
	cout << "The detective weighted ";
	taft.set_dlbs();
	cout << taft<<endl;
	incognito = 276.8;
	taft = 325;
	cout << "After dinner, the celebrity wieghted ";
	incognito.set_stn();
	cout << taft<<endl;
	cout << "After dinner, the President weighed ";
	taft.set_ilbs();
	cout << taft<<endl;
	display(taft, 2);
	cout << "The wrestler weighted even more.\n";
	display(422, 2);
	cout << "No stone left unearned\n";
	return 0;
}

void display(const Stonewt& st, int n)
{
	for (int i = 0;i < n;i++) {
		cout << "Wow! ";
		cout << st;
	}
}
```

```c++
#pragma once
#include <iostream>
using namespace std;
class Stonewt
{
private:
	enum {Lbs_per_stn = 14};
	enum{ DLBS_STYLE,STN_STYLE,ILBS_STYLE};
	int status;
	int stone;
	double pds_left;
	double pounds;
public:
	Stonewt(double lbs);
	Stonewt(int stn, double lbs);
	Stonewt();
	~Stonewt();
	void set_dlbs();
	void set_ilbs();
	void set_stn(); 
	friend ostream & operator<<(ostream &os, const Stonewt& s );
	friend Stonewt operator+(Stonewt& m, Stonewt& t);
	friend Stonewt operator-(Stonewt& m, Stonewt& t);
	friend Stonewt operator*(Stonewt& m, double t);
	friend Stonewt operator*(double m, Stonewt& t) {
		return t * m;
	}
};
```

```c++
#include<iostream>
using std::cout;
#include "stonewt.h"

Stonewt::Stonewt(double lbs)
{
	stone = int(lbs) / Lbs_per_stn;
	pds_left = int(lbs) % Lbs_per_stn + lbs - int(lbs);
	pounds = lbs;
}

Stonewt::Stonewt(int stn, double lbs)
{
	status = DLBS_STYLE;
	stone = stn;
	pds_left = lbs;
	pounds = stn * Lbs_per_stn + lbs;
}

Stonewt::Stonewt()
{
	status=stone = pounds = pds_left = 0;
}
Stonewt::~Stonewt()
{

}
void Stonewt::set_stn()
{
	status = STN_STYLE;
}

void Stonewt::set_ilbs()
{
	status = ILBS_STYLE;
}
void Stonewt::set_dlbs()
{
	status = DLBS_STYLE;
}
ostream& operator<<(ostream& os, const Stonewt& s) {
	switch (s.status) {
	case s.STN_STYLE:os << s.stone;break;
	case s.DLBS_STYLE:os << s.pounds;break;
	case s.ILBS_STYLE:os << (int)s.pounds;break;
	}
	return os;
}
Stonewt operator+(Stonewt& m, Stonewt& t) {
	Stonewt temp;
	temp.pounds = m.pounds + t.pounds;
	temp.stone = temp.pounds / temp.Lbs_per_stn;
	temp.pds_left = temp.pounds - temp.Lbs_per_stn * temp.stone;
	return temp;
}
Stonewt operator-(Stonewt& m, Stonewt& t) {
	Stonewt temp;
	temp.pounds = m.pounds - t.pounds;
	temp.stone = temp.pounds / temp.Lbs_per_stn;
	temp.pds_left = temp.pounds - temp.Lbs_per_stn * temp.stone;
	return temp;
}
Stonewt operator*(Stonewt& m, double t) {
	Stonewt temp;
	temp.pounds = m.pounds * t;
	temp.stone = temp.pounds / temp.Lbs_per_stn;
	temp.pds_left = temp.pounds - temp.Lbs_per_stn * temp.stone;
	return temp;
}
```

#### 6.

```c++
//main.cpp
#include <iostream>
using std::cout;
#include "stonewt.h"

void display(const Stonewt& st, int n);
int main()
{
	Stonewt s[6];
	double pounds;
	for (int i = 3;i < 6;i++) {
		cout << "Enter a pounds: ";
		cin >> pounds;
		s[i].set_pounds(pounds);
	}
	Stonewt min;
	min = s[0];
	Stonewt max;
	max = s[0];
	Stonewt standard(11,0.0);
	int count = 0;
	for (int i = 0;i < 6;i++) {
		if (min > s[i])min = s[i];
		if (max < s[i])max = s[i];
		if (s[i] > standard)count++;
	}
	cout << "min: " << min<<endl;
	cout << "max: "<< max<<endl;
	cout << "count: " << count << endl;
	return 0;
}

void display(const Stonewt& st, int n)
{
	for (int i = 0;i < n;i++) {
		cout << "Wow! ";
		cout << st;
	}
}

```

```c++
#pragma once
#include <iostream>
using namespace std;
class Stonewt
{
private:
	enum {Lbs_per_stn = 14};
	enum{ DLBS_STYLE,STN_STYLE,ILBS_STYLE};
	int status;
	int stone;
	double pds_left;
	double pounds;
public:
	Stonewt(double lbs);
	Stonewt(int stn, double lbs);
	Stonewt();
	~Stonewt();
	void set_dlbs();
	void set_ilbs();
	void set_stn(); 
	void set_pounds(double n);
	friend ostream & operator<<(ostream &os, const Stonewt& s );
	friend Stonewt operator+(Stonewt& m, Stonewt& t);
	friend Stonewt operator-(Stonewt& m, Stonewt& t);
	friend Stonewt operator*(Stonewt& m, double t);
	friend Stonewt operator*(double m, Stonewt& t);
	friend bool operator>(Stonewt& m, Stonewt& t);
	friend bool operator<(Stonewt& m, Stonewt& t);
	friend bool operator>=(Stonewt& m, Stonewt& t);
	friend bool operator<=(Stonewt& m, Stonewt& t);
	friend bool operator==(Stonewt& m, Stonewt& t);
	friend bool operator!=(Stonewt& m, Stonewt& t);
};
```

```c++
#include<iostream>
using std::cout;
#include "stonewt.h"

Stonewt::Stonewt(double lbs)
{
	stone = int(lbs) / Lbs_per_stn;
	pds_left = int(lbs) % Lbs_per_stn + lbs - int(lbs);
	pounds = lbs;
}

Stonewt::Stonewt(int stn, double lbs)
{
	status = DLBS_STYLE;
	stone = stn;
	pds_left = lbs;
	pounds = stn * Lbs_per_stn + lbs;
}

Stonewt::Stonewt()
{
	status=stone = pounds = pds_left = 0;
}
Stonewt::~Stonewt()
{

}
void Stonewt::set_stn()
{
	status = STN_STYLE;
}

void Stonewt::set_ilbs()
{
	status = ILBS_STYLE;
}
void Stonewt::set_dlbs()
{
	status = DLBS_STYLE;
}
ostream& operator<<(ostream& os, const Stonewt& s) {
	switch (s.status) {
	case s.STN_STYLE:os << s.stone;break;
	case s.DLBS_STYLE:os << s.pounds;break;
	case s.ILBS_STYLE:os << (int)s.pounds;break;
	}
	return os;
}
Stonewt operator+(Stonewt& m, Stonewt& t) {
	Stonewt temp;
	temp.pounds = m.pounds + t.pounds;
	temp.stone = temp.pounds / temp.Lbs_per_stn;
	temp.pds_left = temp.pounds - temp.Lbs_per_stn * temp.stone;
	return temp;
}
Stonewt operator-(Stonewt& m, Stonewt& t) {
	Stonewt temp;
	temp.pounds = m.pounds - t.pounds;
	temp.stone = temp.pounds / temp.Lbs_per_stn;
	temp.pds_left = temp.pounds - temp.Lbs_per_stn * temp.stone;
	return temp;
}
Stonewt operator*(Stonewt& m, double t) {
	Stonewt temp;
	temp.pounds = m.pounds * t;
	temp.stone = temp.pounds / temp.Lbs_per_stn;
	temp.pds_left = temp.pounds - temp.Lbs_per_stn * temp.stone;
	return temp;
}
Stonewt operator*(double m, Stonewt& t) {
	return t * m;
}
bool operator>(Stonewt& m, Stonewt& t) {
	return m.pounds > t.pounds;
	}
bool operator<(Stonewt& m, Stonewt& t) {
	return m.pounds < t.pounds;
	}
bool operator>=(Stonewt& m, Stonewt& t) {
	return m.pounds >= t.pounds;
	}
bool operator<=(Stonewt& m, Stonewt& t) {
	return m.pounds <= t.pounds;
	}
bool operator==(Stonewt& m, Stonewt& t) {
	return m.pounds == t.pounds;
	}
bool operator!=(Stonewt& m, Stonewt& t) {
	return m.pounds != t.pounds;
	}
void Stonewt::set_pounds(double n) {
	pounds = n;
	stone = pounds / Lbs_per_stn;
	pds_left = pounds - Lbs_per_stn * stone;
}
```

#### 7.

```c++
//main.cpp
#include <iostream>
#include <typeinfo>
using namespace std;
#include "complex0.h"
int main()
{
	complex a(3.0, 4.0);
	complex c;
	cout << "Enter a complex number (q to quit):\n";
	while (cin >> c)
	{
		cout << "c is " << c << '\n';
		cout << "complex conjugate is " << ~c << '\n';
		cout << "a is " << a << '\n';
		cout << "a + c is " << a + c << '\n';
		cout << "a - c is " << a - c << '\n';
		cout << "a * c is " << a * c << '\n';
		cout << "2 * c is " << 2 * c << '\n';
		cout << "Enter a complex number (q to quit):\n";
	}
	cout << "Done!\n";
	return 0;
}
```

```c++
//complex0.h
#pragma once
#include <iostream>
using namespace std;
class complex {
private:
	double real;
	double imag;
public:
	complex(double re=0, double im=0);
	friend complex operator+(complex& a, complex& b);
	friend complex operator-(complex& a, complex& b);
	friend complex operator*(complex& a, double b);
	friend complex operator*(double a, complex& b);
	complex operator~()const;
	friend complex operator*(complex& a, complex& b);
	friend ostream& operator<<(ostream& os, complex a);
	friend istream& operator>>(istream& os, complex& a);
};
```

```c++
//complex0.cpp
#include <iostream>
#include "complex0.h"
complex::complex(double re, double im) {
	real = re;
	imag = im;
}
complex operator+(complex& a, complex& b) {
	return complex(a.real + b.real, a.imag + b.imag);
}
complex operator-(complex& a, complex& b) {
	return complex(a.real - b.real, a.imag - b.imag);
 }
complex operator*(complex& a, double b) {
	return complex(a.real * b, a.imag * b);
 }
complex operator*(double a, complex& b) {
	return b * a;
 }
complex complex::operator~()const {
	return complex(real, -imag);
 }
complex operator*(complex& a, complex& b) {
	return complex(a.real * b.real - a.imag * b.imag, a.real * b.imag + a.imag * b.real);
}
ostream& operator<<(ostream& os, complex a) {
	os << "(" << a.real << "," << a.imag << "i)";
	return os;
 }
istream& operator>>(istream& is, complex& a) {
	cout << "real: ";
	if(!(is >> a.real))return is;
	cout << "imaginary: ";
	is >> a.imag;
	return is;
}
```

