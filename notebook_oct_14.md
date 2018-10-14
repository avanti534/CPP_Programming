# reference
// swap two ints
void swap(int &a, int &b){
  int tmp = a;
  b = a;
  a = tmp;
}

int a = 5, b = 1;
swap(a, b); 

// pass an array
void func(int * a, int n){
 // ...
 a[0] = 10;
 a[1] = 5;
 // ...
}

# string

#include <string>
string s{"abcd"};
s.charAt(4) = ...


# define a structure

struct {
int x;
int y;

Point(int a, int b){
  x = a;
  y = b;
}

void print_point(){
  std::cout << x << "," << y << std::endl;
}

} Point;

struct {
  //....
} Circle;

Point p1(3, 5);
Point p2(1, 2);
p1.print_point();

Point line[10];

int p1_x,p1_y;

# array vs vector
int a[10];
a[0] = 10;
a[1] = 11;

STL Standard template library

#include <vector>
std::vector<int> v;
v.push_back(10);
v.push_back(11);

v[0] // 10
v[1] // 11

for (int x: v){
  std::cout << x << std::endl;
}

#include <set>

std::set<int> s;
s.insert(1);
s.insert(2);
s.insert(1); // do nothing;
//...
if (!s.count(5)){
  s.insert(5);
} // counting returns 0 / 1


#include <map>
// key - value
std::map<std::int, std::string> m;
m[3] = "abc";
m[4] = "efg";
m[5] = "efg"; // 
m[4] = "eee"; 
//...

std::cout << m[3] << std::endl; // abc

#include <stack>
std::stack<int> st;
st.push(1);
st.push(2);
st.push(3);
std::cout << st.top() << std::endl; // print 3
st.pop(); // removing. you can't use the pop-out element.
std::cout << st.top() << std::endl; // print 2


#include <queue>
std::queue<double> mq;
mq.push(1.0);
mq.push(2.0);
mq.push(3.0);
std::cout << mq.front() << std::endl; //print 1.0

mq.pop(); // the frist element is removed. you can't access the first element
std::cout << mq.front() << std::endl; //print 2.0

if (!mq.empty()){
  double f = mq.front();
  mq.pop();
  // do something for the f...
}

std::cout << mq.size() << std::endl;
if (mq.size() < 10){
  mq.push(100.0);
}
