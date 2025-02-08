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

