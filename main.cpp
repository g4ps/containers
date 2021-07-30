#include "list.hpp"
#include "vector.hpp"
#include "map.hpp"
#include "stack.hpp"
#include "queue.hpp"
#include <list>
#include <iostream>
#include <iomanip>
#include <string>
#include <unistd.h>
#include <vector>
#include <map>
#include <queue>
#include <stack>

#include "checker.hpp"

template <class K, class T>
void print_comp(std::map<K, T> &s1, ft::map<K, T> &l1) {

  typename std::map<K, T>::const_iterator si = s1.begin();
  typename ft::map<K, T>::const_iterator i = l1.begin();
  while (i != l1.end() && si != s1.end()) {
    if ((*i).first != (*si).first || (*i).second != (*si).second) {
      std::cout<<"(!!!!ERROR!!!!)\n";
      return ;
    }
    i++;
    si++;
  }
  if (i != l1.end() || si != s1.end()) {
    std::cout<<"(!!!!ERROR!!!!)\n";
    return ;
  }
  if (s1.size() != l1.size()) {
    std::cout<<"(!!!!SIZE ERROR!!!!)\n";
    return ;
  }
  std::cout<<"(OK)\n";
}

template <class K, class T>
void print_ft_map(const ft::map<K, T> &l1)
{
  typename ft::map<K, T>::const_iterator i;
  for (i = l1.begin(); i != l1.end(); i++) {
    std::cout<<"("<<(*i).first<<", "<<(*i).second<<") ";    
  }
  std::cout<<std::endl;
}



template <class K, class T>
void print_std_map(const std::map<K, T> &l1)
{
  typename std::map<K, T>::const_iterator i;
  for (i = l1.begin(); i != l1.end(); i++) {
    std::cout<<"("<<(*i).first<<", "<<(*i).second<<") ";    
  }
  std::cout<<std::endl;
}

template <class K, class T>
void rev_print_ft_map(const ft::map<K, T> &l1)
{
  typename ft::map<K, T>::const_reverse_iterator i;
  for (i = l1.rbegin(); i != l1.rend(); i++) {
    std::cout<<"("<<(*i).first<<", "<<(*i).second<<") ";    
  }
  std::cout<<std::endl;
}

template <class K, class T>
void rev_print_std_map(const std::map<K, T> &l1)
{
  typename std::map<K, T>::const_reverse_iterator i;
  for (i = l1.rbegin(); i != l1.rend(); i++) {
    std::cout<<"("<<(*i).first<<", "<<(*i).second<<") ";    
  }
  std::cout<<std::endl;
}

template <class K, class T>
void print_in_comp(std::map<K, T> &s1, ft::map<K, T> &l1)
{
  std::cout<<std::setw(10)<<"Standart: ";
  print_std_map<K, T>(s1);
  std::cout<<std::setw(10)<<"Mine: ";
  print_ft_map<K, T>(l1);
  print_comp(s1, l1);
  std::cout<<std::endl;
}

template <class K, class T>
void rev_print_in_comp(std::map<K, T> &s1, ft::map<K, T> &l1)
{
  std::cout<<std::setw(10)<<"Standart: ";
  rev_print_std_map<K, T>(s1);
  std::cout<<std::setw(10)<<"Mine: ";
  rev_print_ft_map<K, T>(l1);
  print_comp(s1, l1);
  std::cout<<std::endl;
}

void map_constructor_check()
{
  std::cout<<"Constructor check:\n";
  ft::map<int, int> m1;
  std::map<int, int> s1;
  print_in_comp(s1, m1);
  for (int i = 0; i < 10; i++) {
    int temp1 = rand() % 20;
    int temp2 = rand() % 20;
    m1.insert(ft::pair<int, int>(temp1, temp2));
    s1.insert(std::pair<int, int>(temp1, temp2));
  }
  print_in_comp(s1, m1);
  ft::map<int, int> m2(m1.begin(), m1.end());
  std::map<int, int> s2(s1.begin(), s1.end());
  print_in_comp(s2, m2);
  ft::map<int, int> m3(m2);
  std::map<int, int> s3(s2);
  print_in_comp(s3, m3);
  ft::map<int, int> m4;
  ft::map<int, int> m5;
  ft::map<int, int> m6;
  std::map<int, int> s4;
  std::map<int, int> s5;
  std::map<int, int> s6;
  m4 = m1;
  m5 = m2;
  m6 = m3;
  s4 = s1;
  s5 = s2;
  s6 = s3;
  print_in_comp(s4, m4);
  print_in_comp(s5, m5);
  print_in_comp(s5, m6);
}

void map_iterator_check()
{
  std::cout<<"Iterator check:\n";
  ft::map<int, int> m1;
  std::map<int, int> s1;
  for (int j = 0; j < 5; j++) {
    int sz = rand() % 10 + 3;
    for (int i = 0; i < sz; i++) {
      int temp1 = rand() % 20;
      int temp2 = rand() % 20;
      m1.insert(ft::pair<int, int>(temp1, temp2));
      s1.insert(std::pair<int, int>(temp1, temp2));
    }
    rev_print_in_comp(s1, m1);
    s1.clear();
    m1.clear();
  }
}

void map_modifiers_check()
{
  std::cout<<"Modifiers check\n";
  ft::map<int, int> m1;
  std::map<int, int> s1;
  for (int i = 0; i < 10; i++) {
    m1.insert(ft::pair<int, int>(i, i));
    s1.insert(std::pair<int, int>(i, i));
  }
  print_in_comp(s1, m1);
  ft::map<int, int> m3;
  std::map<int, int> s3;  
  for (int i = 0; i < 10; i++) {
    int temp1 = rand() % 15;
    int temp2 = rand() % 15;
    m3.insert(ft::pair<int, int>(temp1, temp2));
    s3.insert(std::pair<int, int>(temp1, temp2));
  }
  print_in_comp(s3, m3);
  ft::map<int, int>::iterator i1, i2;
  std::map<int, int>::iterator si1, si2;
  i1 = m3.begin();
  si1 = s3.begin();
  i1++;
  si1++;
  i2 = i1;
  si2 = si1;
  i2++;
  i2++;
  si2++;
  si2++;
  if (m3.size() > 5) {
    std::cout<<"Removing from "<<(*i1).first<<" to "<<(*i2).first<<std::endl;
    m3.erase(i1, i2);
    s3.erase(si1, si2);
    print_in_comp(s3, m3);
  }
  std::cout<<"Swapping m1 and m3\n";
  m1.swap(m3);
  s1.swap(s3);
  print_in_comp(s1, m1);
  print_in_comp(s3, m3);
  std::cout<<"Clearing m3\n";
  m3.clear();
  s3.clear();
  print_in_comp(s3, m3);
}

void map_all_the_bullshit_check()
{
  ft::map<int, int> m1;
  std::map<int, int> s1;
  for (int i = 0; i < 15; i++) {
    int temp1 = rand() % 15;
    int temp2 = rand() % 15;
    m1.insert(ft::make_pair(temp1, temp2));
    s1.insert(std::make_pair(temp1, temp2));
  }
  print_in_comp(s1, m1);
  int pos = rand() % 15;
  std::cout<<"Accessing element "<<pos<<std::endl;
  m1[pos] = 100;
  s1[pos] = 100;
  print_in_comp(s1, m1);
}

void map_check()
{
  map_constructor_check();
  map_iterator_check();
  map_modifiers_check();
  map_all_the_bullshit_check();
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

void all_check()
{
  list_check();
  vector_check();
  map_check();
  derived_types_check();
}

int main(int argc, char **argv)
{
  srand(time(NULL));
  if (argc == 1) {
    all_check();
    return 0;
  }
  std::string arg = argv[1];
  if (arg == "-s") {
    all_check();
    sleep(10);
  }
  else if (arg == "list") {
    list_check();      
  }
  else if (arg == "vector") {
    vector_check();
  }
  else if (arg == "map") {
    map_check();
  }
  else if (arg == "stack" || arg == "queue") {
    derived_types_check();
  }
  else {
    std::cout<<"No known parameter: " << arg << std::endl;
    std::cout<<"Defaulting to checking all\n";
    all_check();
  }
}
