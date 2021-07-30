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

#include "checker.hpp"

template <class T>
void print_comp(std::vector<T> &s1, ft::vector<T> &l1) {

  typename std::vector<T>::const_iterator si = s1.begin();
  typename ft::vector<T>::const_iterator i = l1.begin();
  while (i != l1.end() && si != s1.end()) {
    if (*i != *si) {
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

template <class T>
void print_ft_vector(const ft::vector<T> &l1)
{
  typename ft::vector<T>::const_iterator i;
  for (i = l1.begin(); i != l1.end(); i++) {
    std::cout<<*i<<" ";    
  }
  std::cout<<std::endl;
}

template <class T>
void print_std_vector(const std::vector<T> &l1)
{
  typename std::vector<T>::const_iterator i;
  for (i = l1.begin(); i != l1.end(); i++) {
    std::cout<<*i<<" ";    
  }
  std::cout<<std::endl;
}

template <class T>
void rev_print_ft_vector(const ft::vector<T> &l1)
{
  typename ft::vector<T>::const_reverse_iterator i;
  for (i = l1.rbegin(); i != l1.rend(); i++) {
    std::cout<<*i<<" ";    
  }
  std::cout<<std::endl;
}

template <class T>
void rev_print_std_vector(const std::vector<T> &l1)
{
  typename std::vector<T>::const_reverse_iterator i;
  for (i = l1.rbegin(); i != l1.rend(); i++) {
    std::cout<<*i<<" ";    
  }
  std::cout<<std::endl;
}

template <class T>
void print_in_comp(std::vector<T> &s1, ft::vector<T> &l1)
{
  std::cout<<std::setw(10)<<"Standart: ";
  print_std_vector<T>(s1);
  std::cout<<std::setw(10)<<"Mine: ";
  print_ft_vector<T>(l1);
  print_comp(s1, l1);
  std::cout<<std::endl;
}

template <class T>
void rev_print_in_comp(std::vector<T> &s1, ft::vector<T> &l1)
{
  std::cout<<std::setw(10)<<"Standart: ";
  rev_print_std_vector<T>(s1);
  std::cout<<std::setw(10)<<"Mine: ";
  rev_print_ft_vector<T>(l1);
  std::cout<<std::endl;
}

template <class T>
void print_comp_size(std::vector<T> &s1, ft::vector<T> &l1)
{
  std::cout<<std::setw(10)<<"Standart: ";
  std::cout<<s1.size()<<" ";
  if (s1.empty()) {
    std::cout<<std::setw(13)<<"Is empty\n";
  }
  else {
    std::cout<<std::setw(13)<<"Not empty\n";
  }
  std::cout<<std::setw(10)<<"Mine: ";
  std::cout<<l1.size()<<" ";
  if (l1.empty()) {
    std::cout<<std::setw(13)<<"Is empty ";
  }
  else {
    std::cout<<std::setw(13)<<"Not empty ";
  }
  if (s1.size() == l1.size() && s1.empty() == l1.empty())
    std::cout<<"(OK)";
  else
    std::cout<<"(!!!!ERROR!!!!)";
  std::cout<<std::endl;
}

template <class T>
void print_comp_front(std::vector<T> &s1, ft::vector<T> &l1)
{
  std::cout<<std::setw(10)<<"Standart: ";
  std::cout<<std::setw(3)<<s1.front()<<" ";
  std::cout<<std::setw(10)<<"Mine: ";
  std::cout<<std::setw(3)<<l1.front()<<" ";
  if (s1.front() == l1.front())
    std::cout<<"(OK)";
  else
    std::cout<<"(!!!!ERROR!!!!)";
  std::cout<<std::endl;  
}

template <class T>
void print_comp_back(std::vector<T> &s1, ft::vector<T> &l1)
{
  std::cout<<std::setw(10)<<"Standart: ";
  std::cout<<std::setw(3)<<s1.back()<<" ";
  std::cout<<std::setw(10)<<"Mine: ";
  std::cout<<std::setw(3)<<l1.back()<<" ";
  if (s1.back() == l1.back())
    std::cout<<"(OK)";
  else
    std::cout<<"(!!!!ERROR!!!!)";
  std::cout<<std::endl;  
}

void constructor_vector_check()
{
  int arr[] = {2, 3, 2, 9, 10, 15, 17, 2, 3};
  double arr2[10] = {1.12, 2, 123.13, 131, 123.132, 132};
  ft::vector<int> l1;
  ft::vector<int> l2(10);
  ft::vector<int> l3(10, 20);
  ft::vector<int> l4(arr, arr + 9);
  ft::vector<int> l5(l4);
  ft::vector<double> l6(arr2, arr2 + 6);
  std::vector<int> s1;
  std::vector<int> s2(10);
  std::vector<int> s3(10, 20);
  std::vector<int> s4(arr, arr + 9);
  std::vector<int> s5(s4);
  std::vector<double> s6(arr2, arr2 + 6);
  print_in_comp(s1, l1);
  print_in_comp(s2, l2);
  print_in_comp(s3, l3);
  print_in_comp(s4, l4);
  print_in_comp(s5, l5);
  print_in_comp(s6, l6);
  ft::vector<int> l7;
  std::vector<int> s7;
  l7 = l5;
  l5 = l4;
  l4 = l3;
  l3 = l2;
  l2 = l1;
  l1 = l7;
  s7 = s5;
  s5 = s4;
  s4 = s3;
  s3 = s2;
  s2 = s1;
  s1 = s7;
  print_in_comp(s1, l1);
  print_in_comp(s2, l2);
  print_in_comp(s3, l3);
  print_in_comp(s4, l4);
  print_in_comp(s5, l5);
}

void iterator_vector_check()
{
    std::cout<<"Iterator check\n";
  int arr[] = {2, 3, 2, 9, 10, 15, 17, 2, 3};
  double arr2[10] = {1.12, 2, 123.13, 131, 123.132, 132};
  ft::vector<int> l1;
  ft::vector<int> l2(10);
  ft::vector<int> l3(10, 20);
  ft::vector<int> l4(arr, arr + 9);
  ft::vector<int> l5(l4);
  ft::vector<double> l6(arr2, arr2 + 6);
  std::vector<int> s1;
  std::vector<int> s2(10);
  std::vector<int> s3(10, 20);
  std::vector<int> s4(arr, arr + 9);
  std::vector<int> s5(s4);
  std::vector<double> s6(arr2, arr2 + 6);
  std::cout<<"Printing in reverse\n";
  rev_print_in_comp(s1, l1);
  rev_print_in_comp(s2, l2);
  rev_print_in_comp(s3, l3);
  rev_print_in_comp(s4, l4);
  rev_print_in_comp(s5, l5);
  rev_print_in_comp(s6, l6);
}

void capacity_vector_check()
{
  int arr[] = {2, 3, 2, 9, 10, 15, 17, 2, 3};
  double arr2[10] = {1.12, 2, 123.13, 131, 123.132, 132};
  ft::vector<int> l1;
  ft::vector<int> l2(10);
  ft::vector<int> l3(10, 20);
  ft::vector<int> l4(arr, arr + 9);
  ft::vector<int> l5(l4);
  ft::vector<double> l6(arr2, arr2 + 6);
  ft::vector<int> l7;
  std::vector<int> s1;
  std::vector<int> s2(10);
  std::vector<int> s3(10, 20);
  std::vector<int> s4(arr, arr + 9);
  std::vector<int> s5(s4);
  std::vector<double> s6(arr2, arr2 + 6);
  std::vector<int> s7;
  print_in_comp(s1, l1);
  print_in_comp(s2, l2);
  print_in_comp(s3, l3);
  print_in_comp(s4, l4);
  print_in_comp(s5, l5);
  print_in_comp(s6, l6);
  print_in_comp(s7, l7);  
  print_comp_size(s1, l1);
  print_comp_size(s2, l2);
  print_comp_size(s3, l3);
  print_comp_size(s4, l4);
  print_comp_size(s5, l5);
  print_comp_size(s6, l6);
  print_comp_size(s7, l7);
  l7 = l5;
  l5 = l4;
  l4 = l3;
  l3 = l2;
  l2 = l1;
  l1 = l7;
  s7 = s5;
  s5 = s4;
  s4 = s3;
  s3 = s2;
  s2 = s1;
  s1 = s7;
  std::cout<<"After a lot of assignations\n";
  print_comp_size(s1, l1);
  print_comp_size(s2, l2);
  print_comp_size(s3, l3);
  print_comp_size(s4, l4);
  print_comp_size(s5, l5);
  print_comp_size(s6, l6);
  print_comp_size(s7, l7);
}

void front_and_back_vector()
{
  std::cout<<"Front and back\n";
  ft::vector<int> l1;
  std::vector<int> s1;
  for (int i = 0; i < 10; i++) {
    int temp = rand() % 20;
    l1.push_back(temp);
    s1.push_back(temp);
    if (!s1.empty())
      print_comp_back(s1, l1);
  }
  print_comp_front(s1, l1);
  for (int i = 0; i < 10; i++) {
    l1.pop_back();
    s1.pop_back();
    if (!s1.empty())
      print_comp_back(s1, l1);
  }
  for (int i = 0; i < 10; i++) {
    int temp = rand() % 20;
    l1.push_back(temp);
    s1.push_back(temp);
    if (!s1.empty())
      print_comp_front(s1, l1);
  }
  print_comp_back(s1, l1);
  print_comp(s1, l1);
}

void assign_check_vector()
{
  int arr[] = {2, 3, 2, 9, 10, 15, 17, 2, 3};
  double arr2[10] = {1.12, 2, 123.13, 131, 123.132, 132};
  ft::vector<int> l1;
  ft::vector<int> l2(10);
  ft::vector<int> l3(10, 20);
  ft::vector<int> l4(arr, arr + 9);
  ft::vector<int> l5(l4);
  ft::vector<double> l6(arr2, arr2 + 6);
  ft::vector<int> l7;
  std::vector<int> s1;
  std::vector<int> s2(10);
  std::vector<int> s3(10, 20);
  std::vector<int> s4(arr, arr + 9);
  std::vector<int> s5(s4);
  std::vector<double> s6(arr2, arr2 + 6);
  std::vector<int> s7;
  l7.assign(l5.begin(), l5.end());
  l5.assign(l4.begin(), l4.end());
  l4.assign(l3.begin(), l3.end());
  l3.assign(l2.begin(), l2.end());
  l2.assign(l1.begin(), l1.end());
  l1.assign(l7.begin(), l7.end());
  s7.assign(s5.begin(), s5.end());
  s5.assign(s4.begin(), s4.end());
  s4.assign(s3.begin(), s3.end());
  s3.assign(s2.begin(), s2.end());
  s2.assign(s1.begin(), s1.end());
  s1.assign(s7.begin(), s7.end());
  print_in_comp(s1, l1);
  print_in_comp(s2, l2);
  print_in_comp(s3, l3);
  print_in_comp(s4, l4);
  print_in_comp(s5, l5);
  print_in_comp(s6, l6);
  print_in_comp(s7, l7);
  int temp1;
  int temp2;
  temp1 = rand() % 15 + 3;
  temp2 = rand() % 15 + 3;
  l7.assign(temp1, temp2);
  s7.assign(temp1, temp2);
  temp1 = rand() % 15 + 3;
  temp2 = rand() % 15 + 3;
  l6.assign(temp1, temp2);
  s6.assign(temp1, temp2);
  temp1 = rand() % 15 + 3;
  temp2 = rand() % 15 + 3;
  l5.assign(temp1, temp2);
  s5.assign(temp1, temp2);
  temp1 = rand() % 15 + 3;
  temp2 = rand() % 15 + 3;
  l4.assign(temp1, temp2);
  s4.assign(temp1, temp2);
  temp1 = rand() % 15 + 3;
  temp2 = rand() % 15 + 3;
  l3.assign(temp1, temp2);
  s3.assign(temp1, temp2);
  temp1 = rand() % 15 + 3;
  temp2 = rand() % 15 + 3;
  l2.assign(temp1, temp2);
  s2.assign(temp1, temp2);
  temp1 = rand() % 15 + 3;
  temp2 = rand() % 15 + 3;
  l1.assign(temp1, temp2);
  s1.assign(temp1, temp2);
  print_in_comp(s1, l1);
  print_in_comp(s2, l2);
  print_in_comp(s3, l3);
  print_in_comp(s4, l4);
  print_in_comp(s5, l5);
  print_in_comp(s6, l6);
  print_in_comp(s7, l7);	    
}

void access_check_vector()
{
  std::cout<<"Access\n";  
  ft::vector<int> v1;
  std::vector<int> s1;
  for (int j = 0; j < 10; j++) {
    for (int i = 0; i < 10; i++) {
      int temp = rand() % 20;
      v1.push_back(temp);
      s1.push_back(temp);
    }
    print_in_comp(s1, v1);
    for (size_t i = 0; i < v1.size(); i++) {
      int temp = rand() % 20;
      v1[i] = temp;
      s1[i] = temp;
    }
    print_in_comp(s1, v1);
    s1.clear();
    v1.clear();
  }
}

void insert_vector_check()
{
  int comp;
  //Insert at begin
  std::cout<<"Insert in begin\n";
  comp = rand() % 2 + 3;
  for (int j = 0; j < comp; j++) {
    ft::vector<int> l1;
    std::vector<int> s1;
    int r = rand() % 10 + 3;
    for (int k = 0; k < r; k++) {
      int temp = rand() % 20 + 3;
      l1.insert(l1.begin(), temp);
      s1.insert(s1.begin(), temp);
      print_in_comp(s1, l1);
    }
  }
  std::cout<<"Insert at random position:\n";
  comp = rand() % 2 + 3;
  for (int j = 0; j < comp; j++) {
    ft::vector<int> l1;
    std::vector<int> s1;
    int r = rand() % 10 + 3;
    for (int k = 0; k < r; k++) {
      int temp = rand() % 20 + 3;
      ft::vector<int>::const_iterator i = l1.begin();
      std::vector<int>::const_iterator si = s1.begin();
      int tpos;
      if (!l1.empty())
	tpos = rand() % l1.size();
      else
	tpos = 0;
      for (int l = 0; l < tpos; l++) {
	i++;
	si++;
      }
      l1.insert(i, temp);
      s1.insert(si, temp);
      print_in_comp(s1, l1);
    }
  }
  std::cout<<"Inserting several elements at random position\n";
  comp = rand() % 10 + 3;
  for (int j = 0; j < comp; j++) {
    ft::vector<int> l1;
    std::vector<int> s1;
    int r = rand() % 10 + 3;
    for (int k = 0; k < r; k++) {
      int temp = rand() % 20 + 3;
      ft::vector<int>::const_iterator i = l1.begin();
      std::vector<int>::const_iterator si = s1.begin();
      int tpos;
      if (!l1.empty())
	tpos = rand() % l1.size();
      else
	tpos = 0;
      for (int l = 0; l < tpos; l++) {
	i++;
	si++;
      }
      int times = rand() % 5 + 2;
      l1.insert(i, times, temp);
      s1.insert(si, times, temp);
      print_in_comp(s1, l1);
    }
  }
    comp = rand() % 10 + 3;
  for (int j = 0; j < comp; j++) {
    ft::vector<int> l1;
    ft::vector<int> l2;   
    std::vector<int> s1;
    std::vector<int> s2;
    int kpos = rand() % 10 + 3;
    for (int k = 0; k < kpos; k++) {
      int trand = rand() % 10 + 3;
      for (int l = 0; l < trand; l++) {
	int temp = rand () % 20 + 3;
	l2.push_back(temp);
	s2.push_back(temp);
      }
      print_in_comp(s2, l2);
      int lpos = rand() % s2.size();
      int fpos;
      if (lpos != 0)
	fpos = rand() % lpos;
      else
	fpos = 0;
      int ipos;
      if (s1.empty())
	ipos = 0;
      else
	ipos = rand() % s1.size();
      ft::vector<int>::const_iterator i1 = l2.begin();
      std::vector<int>::const_iterator si1 = s2.begin();
      ft::vector<int>::const_iterator i2 = l2.begin();
      std::vector<int>::const_iterator si2 = s2.begin();
      ft::vector<int>::const_iterator i = l1.begin();
      std::vector<int>::const_iterator si = s1.begin();
      for (int o = 0; o < ipos; o++) {
	i++;
	si++;
      }
      for (int o = 0; o < fpos; o++) {
	i1++;
	si1++;
      }
      for (int o = 0; o < lpos; o++) {
	i2++;
	si2++;
      }
      l1.insert(i, i1, i2);
      s1.insert(si, si1, si2);
      print_in_comp(s1, l1);
    }
  }
}

void erase_vector_check()
{
  std::cout<<"Erase check\n";
  ft::vector<int> l1;
  std::vector<int> s1;
  int sz = rand() % 10 + 3;
  for (int i = 0; i < sz; i++) {
    int temp = rand() % 15 + 3;
    l1.push_back(temp);
    s1.push_back(temp);
  }
  print_in_comp(s1, l1);
  sz = rand() % 20;
  for (int i = 0; i < sz; i++) {
    ft::vector<int>::iterator it = l1.begin();
    std::vector<int>::iterator sit = s1.begin();
    if (s1.size() == 0)
      break;
    int tpos = rand() % s1.size();
    for (int j = 0; j < tpos; j++) {
      it++;
      sit++;
    }
    l1.erase(it);
    s1.erase(sit);
    print_in_comp(s1, l1);
  }
  print_in_comp(s1, l1);
  l1.clear();
  s1.clear();
  sz = rand() % 30 + 3;
  for (int i = 0; i < sz; i++) {
    int temp = rand() % 15 + 3;
    l1.push_back(temp);
    s1.push_back(temp);
  }
  print_in_comp(s1, l1);
  sz = rand() % 20;
  for (int i = 0; i < sz; i++) {
    ft::vector<int>::iterator it1 = l1.begin();
    ft::vector<int>::iterator it2 = l1.begin();
    std::vector<int>::iterator sit1 = s1.begin();
    std::vector<int>::iterator sit2 = s1.begin();
    if (s1.empty())
      break;
    int lpos = rand() % s1.size();
    int fpos;
    if (lpos == 0)
      fpos = 0;
    else
      fpos = rand() % lpos;
    for (int j = 0; j < fpos; j++) {
      it1++;
      sit1++;
    }
    for (int j = 0; j < lpos; j++) {
      it2++;
      sit2++;
    }
    l1.erase(it1, it2);
    s1.erase(sit1, sit2);
    print_in_comp(s1, l1);
  }
  print_in_comp(s1, l1);
}

void vector_check()
{
  constructor_vector_check();
  iterator_vector_check();
  capacity_vector_check();
  front_and_back_vector();
  assign_check_vector();
  access_check_vector();
  insert_vector_check();
  erase_vector_check();
}
