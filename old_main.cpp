//including all the standart stuff for testing
#include <map>
#include <time.h>
#include <stdlib.h>
#include <string>
#include <unistd.h>
#include <list>
#include <vector>
#include <iostream>
#include <memory>
#include <stack>
#include <queue>

//Adding all my stuff
#include "list.hpp"
#include "vector.hpp"
#include "map.hpp"
#include "stack.hpp"
#include "queue.hpp"

class sacr
{
private:
  int i;
public:
  sacr()
  {
    std::cout<<"Empty onstructor is called\n";
  }
  sacr(int n)
  {
    std::cout<<"Constructor is called\n";
    i = n;
  }
  sacr(const sacr &n)
  {
    std::cout<<"Copy Constructor is called\n";
    i = n.i;
  }
  virtual ~sacr()
  {
    std::cout<<"Destructor is called\n";
  }

  const sacr & operator=(const sacr &val)
  {
    i = val.i;
    std::cout<<"equality operator is called\n";
    return *this;
  }

};

void print_ft_list(const char *str, ft::list<int> &l) {
  std::cout<<str<<std::endl;
  ft::list<int>::iterator i;
  for (i = l.begin(); i != l.end(); i++) {
    std::cout<<*i<<" ";
  }
  std::cout<<std::endl;
}

void print_std_list(const char *str, std::list<int> &l) {
  std::cout<<str<<std::endl;
  std::list<int>::iterator i;
  for (i = l.begin(); i != l.end(); i++) {
    std::cout<<*i<<" ";
  }
  std::cout<<std::endl;
}

void print_ft_vector(const char *str, ft::vector<int> &v) {
  std::cout<<str<<std::endl;
  ft::vector<int>::iterator i;
  for (i = v.begin(); i != v.end(); i++) {
    std::cout<<*i<<" ";
  }
  std::cout<<std::endl;
}

void print_std_vector(const char *str, std::vector<int> &v) {
  std::cout<<str<<std::endl;
  std::vector<int>::iterator i;
  for (i = v.begin(); i != v.end(); i++) {
    std::cout<<*i<<" ";
  }
  std::cout<<std::endl;
}

void print_ft_map(const char *str, ft::map<int, int> &b) {
  std::cout<<str<<std::endl;
  ft::map<int, int>::iterator i;
  for (i = b.begin(); i != b.end(); i++) {
    std::cout<<"("<<(*i).first<<", "<<(*i).second<<") ";
  }
  std::cout<<std::endl;
}

void list_push_check() {
  ft::list<int> l1;
  l1.push_back(10);
  l1.pop_front();
  l1.push_front(10);

  int j = 1;
  for (ft::list<int>::iterator i = l1.begin(); i != l1.end(); i++) {
    std::cout<<j++<<": "<<*i<<std::endl;
  }

  ft::list<std::string>l2;
  l2.push_front("String 1");
  l2.push_front("String 2");
  l2.push_front("String 3");
  l2.push_back("String 4");
  l2.pop_back();
  l2.pop_front();

  j = 1;
  std::cout<<"Size: " << l2.size() << std::endl;
  std::cout<<"Normal order:\n";
  for (ft::list<std::string>::iterator i1 = l2.begin(); i1 != l2.end(); i1++) {
    std::cout<<j++<<": "<<*i1<<std::endl;
  }
  j = 1;
  std::cout<<"Reverse order:\n";
  ft::list<std::string>::reverse_iterator i1;
  for (i1 = l2.rbegin(); i1 != l2.rend(); i1++) {
    std::cout<<j++<<": "<<*i1<<std::endl;
  }

  std::cout<<"Stress_test\n";
  std::list<int> stl;
  ft::list<int> myl;
  std::cout<<"Filling up containers from random directions with 10000 elements\n";
  for (int i = 0; i < 10000; i++) {
    int o = rand() % 1000000;
    if (rand() % 2 == 0) {
      stl.push_front(o);
      myl.push_front(o);
    }
    else {
      stl.push_back(o);
      myl.push_back(o);      
    }
  }
  std::cout<<"Removing randomly  stuff from front and back\n";
  for (int i = 0; i < 500; i++) {
    if (rand() % 2 == 0) {
      stl.pop_front();
      myl.pop_front();
    }
    else {
      stl.pop_back();
      myl.pop_back();      
    }
  }
  std::cout<<"Comparing them all\n";
  if (stl.size() != myl.size()) {
    std::cout<<"SIZE FAIL\n";
    std::cout<<"my size: "<<myl.size()<<" stl size "<<stl.size()<<std::endl;
    exit(0);
  }
  int y = 0;
  std::list<int>::iterator iter1 = stl.begin();
  ft::list<int>::iterator iter2 = myl.begin();
  for (; iter1 != stl.end() && iter2 != myl.end(); iter1++, iter2++) {
    if (*iter1 != *iter2) {
      std::cout<<"FAIL COMP in position "<<y<<"\n";
      exit(0);
    }
    y++;
  }
  if (iter1 == stl.end() && iter2 == myl.end())
    std::cout<<"Good\n";
  else {
    std::cout<<"FAIL: WRONG END POSITION\n";
    exit(0);
  }
  std::cout<<"Comparing in reverse order\n";
  std::list<int>::reverse_iterator iter3 = stl.rbegin();
  ft::list<int>::reverse_iterator iter4 = myl.rbegin();
  for (; iter3 != stl.rend() && iter4 != myl.rend(); iter3++, iter4++) {
    if (*iter3 != *iter4) {
      std::cout<<"FAIL COMP in position "<<y<<"\n";
      exit(0);
    }
    y++;
  }
  if (iter3 == stl.rend() && iter4 == myl.rend())
    std::cout<<"Good\n";
  else {
    std::cout<<"FAIL: WRONG END POSITION\n";
    exit(0);
  }
}


void list_constructor_check() {
  int arr1[] = {1, 2, 3, 4, 5};
  const int arr2[] = {5, 4, 3, 2, 1};
  ft::list<int> l1(arr1, arr1 + 5);
  ft::list<int> l2(arr2, arr2 + 5);
  ft::list<int>::iterator beg = l2.begin();
  ft::list<int>::iterator end = l2.end();
  ft::list<int> l3(beg, end);
  ft::list<int> l4((unsigned long int)15, 40);
  ft::list<int> l5(l4);
  
  for (ft::list<int>::iterator i = l1.begin(); i != l1.end(); i++) {
    std::cout<<*i<<" ";
  }
  std::cout<<std::endl;
  for (ft::list<int>::iterator i = l2.begin(); i != l2.end(); i++) {
    std::cout<<*i<<" ";
  }
  std::cout<<std::endl;
  for (ft::list<int>::iterator i = l3.begin(); i != l3.end(); i++) {
    std::cout<<*i<<" ";
  }
  std::cout<<std::endl;
  for (ft::list<int>::iterator i = l4.begin(); i != l4.end(); i++) {
    std::cout<<*i<<" ";
  }
  std::cout<<std::endl;
  for (ft::list<int>::iterator i = l5.begin(); i != l5.end(); i++) {
    std::cout<<*i<<" ";
  }
  std::cout<<std::endl;
}

void list_insert_check() {
  ft::list<int> l1;
  l1.push_back(1);
  l1.push_back(2);
  l1.push_back(3);
  l1.push_back(4);
  l1.push_back(5);
  l1.push_back(6);
  l1.push_back(7);
  l1.push_back(8);
  ft::list<int> l2;
  //  l2.push_back(8);
  ft::list<int>::reverse_iterator i1 = l1.rbegin();
  i1++;
  i1++;
  ft::list<int>::reverse_iterator i2 = l1.rend();
  i2--;
  i2--;
  ft::list<int>::iterator i;
  l2.insert(l2.begin(), i1, i2);
  i = l2.begin();
  i++;
  i++;
  l2.insert(i, l1.begin(), l1.end());

  for (i = l2.begin(); i != l2.end(); i++) {
    std::cout<<*i<<" ";
  }  
  std::cout<<"\nsize: "<<l2.size()<<std::endl;
}

void list_erase_check() {
  ft::list<int>l1;
  l1.push_back(1);
  l1.push_back(2);
  l1.push_back(3);
  l1.push_back(4);
  l1.push_back(5);
  l1.push_back(6);
  l1.push_back(7);
  l1.push_back(8);
  l1.push_back(9);
  ft::list<int>::iterator i1 = l1.begin();
  ft::list<int>::iterator i2 = l1.end();
  std::cout<<"----------------------------------------------------------------------\n";
  std::cout<<"Erase check:\nInit list: ";
  for (; i1 != i2; i1++) {
    std::cout<<*i1<<" ";    
  }
  std::cout<<std::endl;
  i1 = l1.begin();
  int res = rand() % l1.size();
  for (int i = 0; i < 5; i++) {
    i1++;    
  }
  std::cout<<"Removing element "<<*i1<<"\n";
  l1.erase(i1);
  i1 = l1.begin();
  for (; i1 != i2; i1++) {
    std::cout<<*i1<<" ";    
  }  
  std::cout<<std::endl;
  res = 1 + rand() % (l1.size() - 2);
  res = 8;
  int res2 =  1 + rand() % (res - 2);
  res2 = 1;
  i1 = l1.begin();
  i2 = l1.begin();
  for (int i = 0; i < res; i++) {
    i2++;
  }
  for (int i = 0; i < res2; i++) {
    i1++;
  }
  l1.erase(i1, i2);
  for (i1 = l1.begin(); i1 != l1.end(); i1++)  {
    std::cout<<*i1<<" ";
  }
  std::cout<<"\n";
}

void list_splice_check()
{
  std::cout<<"splice check:\n";
  ft::list<int> l1;
  std::list<int> sl1;
  std::list<int> sl2;
  for (int i = 0; i < 5; i++) {
    l1.push_front(i);
    sl1.push_front(i);
  }
  ft::list<int>::iterator i1;
  ft::list<int>::iterator i2;
  ft::list<int>::iterator i3;
  ft::list<int>::iterator it;
  std::list<int>::iterator sit;
  i1 = l1.begin();
  i2 = l1.end();
  i2--;
  i2--;
  ft::list<int> l2;
  print_ft_list("first list", l1);
  for (int i = 0; i < 10; i++) {
    l2.push_back(i);
    sl2.push_back(i);
  }
  i3 = l2.begin();
  i3++;
  i3++;
  std::cout<<"Inserting element "<<*i1<<std::endl;
  l2.splice(i3, l1, i1);
  std::cout<<"Final list: \n";
  for (i3 = l2.begin(); i3 != l2.end(); i3++) {
    std::cout<<*i3<<" ";
  }
  std::cout<<std::endl;  
  print_ft_list("Previous list:", l1);
  i3 = l2.begin();
  i3++;
  i3++;
  std::cout<<"Inserting full list at "<<*i3<<":\n";
  l2.splice(i3, l1);
  print_ft_list("Previous list:", l1);
  print_ft_list("Final list:", l2);
  sit = sl1.begin();
  sit++;
  std::cout<<"Trying std list:\n";
  print_std_list("fisrt: ", sl1);
  print_std_list("second: ", sl2);
  std::cout<<"Splicing at "<<*sit<<std::endl;
  sl1.splice(sl1.begin(), sl2);
  print_std_list("fisrt: ", sl1);
  print_std_list("second: ", sl2);
  l1.clear();
  l2.clear();
  for (int i = 0; i < 5; i++) {
    l1.push_back(2 * i);
    l2.push_back(2 * i + 1);    
  }
  ft::list<int>::iterator i;
  i = l1.end();
  l1.splice(i, l2);
  print_ft_list("Test", l1);
  l1.clear();
  l2.clear();
  l1.push_back(5);
  l2.splice(l2.begin(), l1, l1.begin());
  print_ft_list("Testing on empty list:", l2);
}


void list_sort_test()
{
  ft::list<int> l1;
  ft::list<int> l2;
  ft::list<int>::iterator it;


  std::cout<<"\nSort test:\n";
  l1.push_back(10);
  l1.merge(l2);
  print_ft_list("Doing merge on emply list:", l1);
  l1.clear();
  for (int i = 0; i < 10; i++) {
    l1.push_back(2 * i);
    l2.push_back(2 * i + 1);
  }
  l2.push_back(115);
  l2.push_back(120);
  print_ft_list("First list:", l1);
  print_ft_list("Second list:", l2);
  l1.merge(l2);
  print_ft_list("Finished list:", l1);
  print_ft_list("Second_list:", l2);
  l1.clear();
  l2.clear();
  for(int i = 0; i < 10; i++) {
    l1.push_back(rand() % 100);
  }
  print_ft_list("Unsorted: ", l1);
  l1.sort();
  print_ft_list("Sorted: ", l1);
  l1.reverse();
  print_ft_list("Reversed: ", l1);
}

void list_check()
{
  std::cout<<"--------------------LIST--------------------\n";
  list_push_check();
  list_constructor_check();
  list_insert_check();
  list_erase_check();
  list_splice_check();
  list_sort_test();
  std::cout<<"---------------------------------------------\n";
}

void vector_constructor_check()
{
  std::cout<<"Constructor check:\n";
  int arr[] = {1, 2, 3, 4, 5};
  ft::vector<int> v1;
  ft::vector<int> v2((size_t)10, 20);
  ft::vector<int> v3(arr, arr + 5);
  ft::vector<int> v4(v2);
  print_ft_vector("Empty: ", v1);
  print_ft_vector("10 of 20: ", v2);
  print_ft_vector("Constructed from iterator(should be 1 2 3 4 5): ", v3);
  print_ft_vector("Copy of the second vector: ", v4);
}

void vector_iterator_check()
{
  std::cout<<"Iterator check\n";
  int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
  ft::vector<int>v1(arr, arr + 9);
  print_ft_vector("initial vector: ", v1);
  std::cout<<"Printing with reverse iterator:\n";
  ft::vector<int>::reverse_iterator i;
  for (i = v1.rbegin(); i != v1.rend(); i++) {    
    std::cout<<*i<<" ";
  }
  
  std::cout<<std::endl;
}

void vector_capacity_check()
{
  std::cout<<"Capacity check\n";
  int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
  ft::vector<int>v1(arr, arr + 9);
  ft::vector<int>v2;
  print_ft_vector("first vector: ", v1);
  std::cout<<"It's size: "<<v1.size()<<std::endl;
  std::cout<<"It's capacity: "<<v1.capacity()<<std::endl;
  v1.reserve(30);
  std::cout<<"After reserving 30 in the cap: "<<v1.capacity()<<std::endl;
  print_ft_vector("and its insides are: ", v1);
}

void vector_modifiers_check()
{
  std::cout<<"Modifiers check\n";
  std::vector<int> comp1;
  std::vector<int> comp2;
  ft::vector<int> v1;
  ft::vector<int> v2;
  for (int  i = 0; i < 10; i++) {
    comp1.push_back(i * 2);
    comp2.push_back(i * 3);
    v1.push_back(i * 2);
    v2.push_back(i * 3);
    
  }
  print_ft_vector("Vector 1:", v1);
  print_ft_vector("Vector 2:", v2);
  ft::vector<int>::iterator i1 = v1.begin();
  ft::vector<int>::iterator i2 = v1.begin();
  ft::vector<int>::iterator i3 = v2.begin();
  std::vector<int>::iterator si1 = comp1.begin();
  std::vector<int>::iterator si2 = comp1.begin();
  std::vector<int>::iterator si3 = comp2.begin();
  i1  += 2;
  si1 += 2;
  i2 += 6;
  i3 += 6;
  si2 += 6;
  si3 += 6;
  std::cout<<"Inserting into second vector at position "<<*i3<<std::endl<<
    "Everyting from " << *i1 << " and " << *i2<<std::endl;
  std::cout<<"Return values of insert:\n";
  std::cout<<"Standart: "<<*comp2.insert(si3, 3)<<std::endl;
  std::cout<<"Mine: "<<*v2.insert(i3, 3)<<std::endl;
  si3 = comp2.insert(si3, si1, si2);
  i3 = v2.insert(i3, i1, i2);
  print_ft_vector("Vector 2:", v2);
  print_std_vector("Standart vector 2: ", comp2);
  std::cout<<"Return values:\n";
  std::cout<<"Standart: "<< *si3 << "\nMine: " << *i3 << std::endl;
  std::cout<<"Erase check:\n";
  std::cout<<"Erasing at position " << *i3 <<std::endl;
  i3 = v2.erase(i3);
  si3 = comp2.erase(si3);
  print_ft_vector("Vector 2:", v2);
  print_std_vector("Standart vector 2: ", comp2);
  std::cout<<"Return values:\n";
  std::cout<<"Standart: "<< *si3 << "\nMine: " << *i3 << std::endl;
  i2 = i3;
  si2 = si3;
  i3 += 3;
  si3 += 3;
  i3 = v2.erase(i2, i3);
  si3 = comp2.erase(si2, si3);
  print_ft_vector("Vector 2:", v2);
  print_std_vector("Standart vector 2: ", comp2);
  std::cout<<"Printing through operator []\n";
  for (size_t i = 0; i < v2.size(); i++) {
    std::cout<<v2[i]<<" ";    
  }
  std::cout<<std::endl;
}

void vector_check()
{
  std::cout<<"--------------------VECTOR--------------------\n";
  vector_constructor_check();
  vector_iterator_check();
  vector_capacity_check();
  vector_modifiers_check();
  std::cout<<"----------------------------------------------\n";
}

void map_constructor_check()
{
  ft::map<int, int> m1;
  for (int i = 0; i < 10; i++) {
    m1.insert(ft::pair<int, int>(i, i));
  }
  ft::map<int, int> m2(m1.begin(), m1.end());
  ft::map<int, int> m3(m2);
  print_ft_map("Defalut: ", m1);
  print_ft_map("Iterator: ", m2);
  print_ft_map("Copy: ", m3);
}

void map_iterator_check()
{
  std::cout<<"Map iterator check:\n";

  std::cout<<"Standart map check:\n";
  std::map<int, int> m2;
  for (int i = 0; i < 10; i++) {
    m2.insert(std::pair<int, int>(i, i * 2));
  }
  std::map<int, int>::iterator i1;
  for (i1 = m2.begin(); i1 != m2.end(); i1++) {
    std::cout<<(*i1).second<<" ";
  }
  std::cout<<std::endl;
  std::cout<<"My map:\n";
  ft::map<int, int> m1;
  for (int  i = 0; i < 10; i++) {
    m1.insert(ft::pair<int, int>(i, 2 * i));
    m1.insert(ft::pair<int, int>(100 - i, 2 * (100 - i)));
  }
  ft::map<int, int>::iterator i;
  for (i = m1.begin(); i != m1.end(); i++) {
    std::cout<<(*i).second<<" ";
  }
  std::cout<<std::endl;
  std::cout<<"And in reverse\n";
  ft::map<int, int>::reverse_iterator ir;
  for (ir = m1.rbegin(); ir != m1.rend(); ir++) {
    std::cout<<(*ir).second<<" ";    
  }
  std::cout<<std::endl;
  std::cout<<"Size: "<<m1.size()<<std::endl;
}

void map_modifiers_check()
{
  std::cout<<"Modifiers check\n";
  ft::map<int, int> m1;  
  for (int i = 0; i < 10; i++) {
    m1.insert(ft::pair<int, int>(i, i));
  }
  print_ft_map("making through insert with a single pair", m1);
  ft::map<int, int> m2;
  m2.insert(m1.begin(), m1.end());
  print_ft_map("making through iterator insert: ", m2);
  ft::map<int, int> m3;
  for (int i = 0; i < 10; i++) {
    m3.insert(ft::pair<int, int>(rand() % 15, rand() % 15));
  }
  print_ft_map("Random insert, should be less than 10 in size and sorted:\n", m3);
  std::cout<<"Size: "<<m3.size()<<std::endl;
  ft::map<int, int>::iterator i1, i2;
  i1 = m3.begin();
  i1++;
  i2 = i1;
  i2++;
  i2++;
  if (m3.size() > 5) {
    std::cout<<"Removing from "<<(*i1).first<<" to "<<(*i2).first<<std::endl;
    m3.erase(i1, i2);
    print_ft_map("Result: ", m3);
  }
  std::cout<<"Swapping m1 and m3\n";
  m1.swap(m3);
  print_ft_map("m1: ", m1);
  print_ft_map("m3: ", m3);
  std::cout<<"Clearing m3\n";
  m3.clear();
  print_ft_map("m3", m3);
}

void map_all_the_bullshit_check()
{
  ft::map<int, int> m1;
  for (int i = 0; i < 15; i++) {
    m1.insert(ft::make_pair(rand() % 15, rand() % 15));
  }
  print_ft_map("Map to be dissected(m1): ", m1);
  int pos = rand() % 15;
  std::cout<<"Accessing element "<<pos<<std::endl;
  m1[pos] = 100;
  print_ft_map("current state of m1: ", m1);
}

void map_check()
{
  std::cout<<"--------------------MAP--------------------\n";
  map_constructor_check();
  map_iterator_check();
  map_modifiers_check();
  map_all_the_bullshit_check();
  std::cout<<"-------------------------------------------\n";
}

void derived_types_check()
{
  std::cout<<"--------------------STACK & QUEUE--------------------\n";  
  std::cout<<"Checking out stack\n";
  ft::stack<int> s1;
  std::stack<int> s2;
  for (int i = 0; i < 15; i++) {
    s1.push(i);
    s2.push(i);
  }
  std::cout<<"Local: ";
  while (s1.size()) {
    std::cout<<s1.top()<<" ";
    s1.pop();
  }
  std::cout<<std::endl;
  std::cout<<"Standart: ";
  while(s2.size()) {
    std::cout<<s2.top()<<" ";
    s2.pop();
  }
  std::cout<<std::endl;
  std::cout<<std::endl;
  ft::queue<int> q1;
  std::queue<int> q2;
  for (int i = 0; i < 10; i++) {
    q1.push(i * 2);
    q2.push(i * 2);
  }
  std::cout<<"Checking out queue\n";
  std::cout<<"Local: ";
  while (q1.size()) {
    std::cout<<q1.front()<<" ";
    q1.pop();
  }
  std::cout<<std::endl;
  std::cout<<"Standart: ";
  while(q2.size()) {
    std::cout<<q2.front()<<" ";
    q2.pop();
  }
  std::cout<<std::endl;
  std::cout<<"--------------------------------------------------\n";
}

int main(int argc, char **argv)
{
  srand(time(NULL));
  // list_check();
  // vector_check();
  // map_check();
  // derived_types_check();
  ft::list<int>::iterator i;
  size_t t = static_cast<size_t>(i);
  argv = NULL;
  if (argc != 1) {
    sleep(10);
  }
  return 0;
}
