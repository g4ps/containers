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

#include "checker.hpp"


bool is_not_prime(int arg)
{
  if (arg < 2)
    return true;
  for (int i = 2; i * i < arg; i++) {
    if (arg % i == 0)
      return true;
  }
  return false;
}



std::string
random_string()
{
  std::string ret;
  std::string alpha = "qwertyuiopasdfghjklzxcvbnm1234567890";
  int r = rand() % 10 + 5;
  for (int i = 0; i < r; i++) {
    ret += alpha[rand() % alpha.size()];
  }
  return ret;
}

double
random_double()
{
  double ret = rand() % 1000;
  ret /= rand() % 500;
  return ret;
}

template <class T>
void print_comp(std::list<T> &s1, ft::list<T> &l1) {

  typename std::list<T>::const_iterator si = s1.begin();
  typename ft::list<T>::const_iterator i = l1.begin();
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
void print_ft_list(const ft::list<T> &l1)
{
  typename ft::list<T>::const_iterator i;
  for (i = l1.begin(); i != l1.end(); i++) {
    std::cout<<*i<<" ";    
  }
  std::cout<<std::endl;
}

template <class T>
void print_std_list(const std::list<T> &l1)
{
  typename std::list<T>::const_iterator i;
  for (i = l1.begin(); i != l1.end(); i++) {
    std::cout<<*i<<" ";    
  }
  std::cout<<std::endl;
}

template <class T>
void rev_print_ft_list(const ft::list<T> &l1)
{
  typename ft::list<T>::const_reverse_iterator i;
  for (i = l1.rbegin(); i != l1.rend(); i++) {
    std::cout<<*i<<" ";    
  }
  std::cout<<std::endl;
}

template <class T>
void rev_print_std_list(const std::list<T> &l1)
{
  typename std::list<T>::const_reverse_iterator i;
  for (i = l1.rbegin(); i != l1.rend(); i++) {
    std::cout<<*i<<" ";    
  }
  std::cout<<std::endl;
}

template <class T>
void print_in_comp(std::list<T> &s1, ft::list<T> &l1)
{
  std::cout<<std::setw(10)<<"Standart: ";
  print_std_list<T>(s1);
  std::cout<<std::setw(10)<<"Mine: ";
  print_ft_list<T>(l1);
  print_comp(s1, l1);
  std::cout<<std::endl;
}

template <class T>
void rev_print_in_comp(std::list<T> &s1, ft::list<T> &l1)
{
  std::cout<<std::setw(10)<<"Standart: ";
  rev_print_std_list<T>(s1);
  std::cout<<std::setw(10)<<"Mine: ";
  rev_print_ft_list<T>(l1);
  std::cout<<std::endl;
}

template <class T>
void print_comp_size(std::list<T> &s1, ft::list<T> &l1)
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
void print_comp_front(std::list<T> &s1, ft::list<T> &l1)
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
void print_comp_back(std::list<T> &s1, ft::list<T> &l1)
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


void constructor_list_check()
{
  std::cout<<"Constructor check\n";
  int arr[] = {2, 3, 2, 9, 10, 15, 17, 2, 3};
  double arr2[10] = {1.12, 2, 123.13, 131, 123.132, 132};
  ft::list<int> l1;
  ft::list<int> l2(10);
  ft::list<int> l3(10, 20);
  ft::list<int> l4(arr, arr + 9);
  ft::list<int> l5(l4);
  ft::list<double> l6(arr2, arr2 + 6);
  std::list<int> s1;
  std::list<int> s2(10);
  std::list<int> s3(10, 20);
  std::list<int> s4(arr, arr + 9);
  std::list<int> s5(s4);
  std::list<double> s6(arr2, arr2 + 6);
  print_in_comp(s1, l1);
  print_in_comp(s2, l2);
  print_in_comp(s3, l3);
  print_in_comp(s4, l4);
  print_in_comp(s5, l5);
  print_in_comp(s6, l6);
  ft::list<int> l7;
  std::list<int> s7;
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


void iterator_list_check()
{
  std::cout<<"Iterator check\n";
  int arr[] = {2, 3, 2, 9, 10, 15, 17, 2, 3};
  double arr2[10] = {1.12, 2, 123.13, 131, 123.132, 132};
  ft::list<int> l1;
  ft::list<int> l2(10);
  ft::list<int> l3(10, 20);
  ft::list<int> l4(arr, arr + 9);
  ft::list<int> l5(l4);
  ft::list<double> l6(arr2, arr2 + 6);
  std::list<int> s1;
  std::list<int> s2(10);
  std::list<int> s3(10, 20);
  std::list<int> s4(arr, arr + 9);
  std::list<int> s5(s4);
  std::list<double> s6(arr2, arr2 + 6);
  std::cout<<"Printing in reverse\n";
  rev_print_in_comp(s1, l1);
  rev_print_in_comp(s2, l2);
  rev_print_in_comp(s3, l3);
  rev_print_in_comp(s4, l4);
  rev_print_in_comp(s5, l5);
  rev_print_in_comp(s6, l6);
}

void   capacity_list_check()
{
  int arr[] = {2, 3, 2, 9, 10, 15, 17, 2, 3};
  double arr2[10] = {1.12, 2, 123.13, 131, 123.132, 132};
  ft::list<int> l1;
  ft::list<int> l2(10);
  ft::list<int> l3(10, 20);
  ft::list<int> l4(arr, arr + 9);
  ft::list<int> l5(l4);
  ft::list<double> l6(arr2, arr2 + 6);
  ft::list<int> l7;
  std::list<int> s1;
  std::list<int> s2(10);
  std::list<int> s3(10, 20);
  std::list<int> s4(arr, arr + 9);
  std::list<int> s5(s4);
  std::list<double> s6(arr2, arr2 + 6);
  std::list<int> s7;
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

void front_and_back_list()
{
  std::cout<<"Front and back\n";
  ft::list<int> l1;
  std::list<int> s1;
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
    l1.push_front(temp);
    s1.push_front(temp);
    if (!s1.empty())
      print_comp_front(s1, l1);
  }
  print_comp_back(s1, l1);
  print_comp(s1, l1);
}

void assign_check_list()
{
  int arr[] = {2, 3, 2, 9, 10, 15, 17, 2, 3};
  double arr2[10] = {1.12, 2, 123.13, 131, 123.132, 132};
  ft::list<int> l1;
  ft::list<int> l2(10);
  ft::list<int> l3(10, 20);
  ft::list<int> l4(arr, arr + 9);
  ft::list<int> l5(l4);
  ft::list<double> l6(arr2, arr2 + 6);
  ft::list<int> l7;
  std::list<int> s1;
  std::list<int> s2(10);
  std::list<int> s3(10, 20);
  std::list<int> s4(arr, arr + 9);
  std::list<int> s5(s4);
  std::list<double> s6(arr2, arr2 + 6);
  std::list<int> s7;
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

void insert_list_check()
{
  int comp;
  //Insert at begin
  std::cout<<"Insert in begin";
  comp = rand() % 10 + 3;
  for (int j = 0; j < comp; j++) {
    ft::list<int> l1;
    std::list<int> s1;
    int r = rand() % 10 + 3;
    for (int k = 0; k < r; k++) {
      int temp = rand() % 20 + 3;
      l1.insert(l1.begin(), temp);
      s1.insert(s1.begin(), temp);
      print_in_comp(s1, l1);
    }
  }
  comp = rand() % 10 + 3;
  for (int j = 0; j < comp; j++) {
    ft::list<double> l1;
    std::list<double> s1;
    int r = rand() % 10 + 3;
    for (int k = 0; k < r; k++) {
      double temp = random_double();
      l1.insert(l1.begin(), temp);
      s1.insert(s1.begin(), temp);
      print_in_comp(s1, l1);
    }
  }
  comp = rand() % 10 + 3;
  for (int j = 0; j < comp; j++) {
    ft::list<std::string> l1;
    std::list<std::string> s1;
    int r = rand() % 10 + 3;
    for (int k = 0; k < r; k++) {
      std::string temp = random_string();
      l1.insert(l1.begin(), temp);
      s1.insert(s1.begin(), temp);
      print_in_comp(s1, l1);
    }
  }
  //Insert at random position
  comp = rand() % 10 + 3;
  for (int j = 0; j < comp; j++) {
    ft::list<int> l1;
    std::list<int> s1;
    int r = rand() % 10 + 3;
    for (int k = 0; k < r; k++) {
      int temp = rand() % 20 + 3;
      ft::list<int>::const_iterator i = l1.begin();
      std::list<int>::const_iterator si = s1.begin();
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
  comp = rand() % 10 + 3;
  for (int j = 0; j < comp; j++) {
    ft::list<double> l1;
    std::list<double> s1;
    int r = rand() % 10 + 3;
    for (int k = 0; k < r; k++) {
      double temp = random_double();
      ft::list<double>::const_iterator i = l1.begin();
      std::list<double>::const_iterator si = s1.begin();
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
  comp = rand() % 10 + 3;
  for (int j = 0; j < comp; j++) {
    ft::list<std::string> l1;
    std::list<std::string> s1;
    int r = rand() % 10 + 3;
    for (int k = 0; k < r; k++) {
      std::string temp = random_string();
      ft::list<std::string>::const_iterator i = l1.begin();
      std::list<std::string>::const_iterator si = s1.begin();
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
  //insert of several elements at random position
  comp = rand() % 10 + 3;
  for (int j = 0; j < comp; j++) {
    ft::list<int> l1;
    std::list<int> s1;
    int r = rand() % 10 + 3;
    for (int k = 0; k < r; k++) {
      int temp = rand() % 20 + 3;
      ft::list<int>::const_iterator i = l1.begin();
      std::list<int>::const_iterator si = s1.begin();
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
    ft::list<double> l1;
    std::list<double> s1;
    int r = rand() % 10 + 3;
    for (int k = 0; k < r; k++) {
      double temp = random_double();
      ft::list<double>::const_iterator i = l1.begin();
      std::list<double>::const_iterator si = s1.begin();
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
    ft::list<std::string> l1;
    std::list<std::string> s1;
    int r = rand() % 10 + 3;
    for (int k = 0; k < r; k++) {
      std::string temp = random_string();
      ft::list<std::string>::const_iterator i = l1.begin();
      std::list<std::string>::const_iterator si = s1.begin();
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
  //inserting at random position with iterators
  comp = rand() % 10 + 3;
  for (int j = 0; j < comp; j++) {
    ft::list<int> l1;
    ft::list<int> l2;   
    std::list<int> s1;
    std::list<int> s2;
    int kpos = rand() % 10 + 3;
    for (int k = 0; k < kpos; k++) {
      int trand = rand() % 10 + 3;
      for (int l = 0; l < trand; l++) {
	int temp = rand () % 20 + 3;
	l2.push_front(temp);
	s2.push_front(temp);
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
      ft::list<int>::const_iterator i1 = l2.begin();
      std::list<int>::const_iterator si1 = s2.begin();
      ft::list<int>::const_iterator i2 = l2.begin();
      std::list<int>::const_iterator si2 = s2.begin();
      ft::list<int>::const_iterator i = l1.begin();
      std::list<int>::const_iterator si = s1.begin();
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
  comp = rand() % 10 + 3;
  for (int j = 0; j < comp; j++) {
    ft::list<double> l1;
    ft::list<double> l2;   
    std::list<double> s1;
    std::list<double> s2;
    int kpos = rand() % 10 + 3;
    for (int k = 0; k < kpos; k++) {
      int trand = rand() % 10 + 3;
      for (int l = 0; l < trand; l++) {
	double temp = random_double();
	l2.push_front(temp);
	s2.push_front(temp);
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
      ft::list<double>::const_iterator i1 = l2.begin();
      std::list<double>::const_iterator si1 = s2.begin();
      ft::list<double>::const_iterator i2 = l2.begin();
      std::list<double>::const_iterator si2 = s2.begin();
      ft::list<double>::const_iterator i = l1.begin();
      std::list<double>::const_iterator si = s1.begin();
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
    comp = rand() % 10 + 3;
  for (int j = 0; j < comp; j++) {
    ft::list<std::string> l1;
    ft::list<std::string> l2;   
    std::list<std::string> s1;
    std::list<std::string> s2;
    int kpos = rand() % 10 + 3;
    for (int k = 0; k < kpos; k++) {
      int trand = rand() % 10 + 3;
      for (int l = 0; l < trand; l++) {
	std::string temp = random_string();
	l2.push_front(temp);
	s2.push_front(temp);
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
      ft::list<std::string>::const_iterator i1 = l2.begin();
      std::list<std::string>::const_iterator si1 = s2.begin();
      ft::list<std::string>::const_iterator i2 = l2.begin();
      std::list<std::string>::const_iterator si2 = s2.begin();
      ft::list<std::string>::const_iterator i = l1.begin();
      std::list<std::string>::const_iterator si = s1.begin();
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

void erase_list_check()
{
  std::cout<<"Erase check\n";
  ft::list<int> l1;
  std::list<int> s1;
  int sz = rand() % 10 + 3;
  for (int i = 0; i < sz; i++) {
    int temp = rand() % 15 + 3;
    l1.push_back(temp);
    s1.push_back(temp);
  }
  print_in_comp(s1, l1);
  sz = rand() % 20;
  for (int i = 0; i < sz; i++) {
    ft::list<int>::iterator it = l1.begin();
    std::list<int>::iterator sit = s1.begin();
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
    ft::list<int>::iterator it1 = l1.begin();
    ft::list<int>::iterator it2 = l1.begin();
    std::list<int>::iterator sit1 = s1.begin();
    std::list<int>::iterator sit2 = s1.begin();
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

void resize_list_check()
{
  std::cout<<"Resize check\n";
  for (int iter = 0; iter < 10; iter++) {
    ft::list<int> l1;
    std::list<int> s1;
    int sz;
    sz = rand() % 20;
    for (int i = 0; i < sz; i++) {
      int temp = rand() % 20 + 3;
      l1.push_back(temp);
      s1.push_back(temp);
    }
    int temp = rand() % 30;
    l1.resize(temp);
    s1.resize(temp);
    print_in_comp(s1, l1);
  }
  for (int iter = 0; iter < 10; iter++) {
    ft::list<int> l1;
    std::list<int> s1;
    int sz;
    sz = rand() % 20;
    for (int i = 0; i < sz; i++) {
      int temp = rand() % 20 + 3;
      l1.push_back(temp);
      s1.push_back(temp);
    }
    int temp = rand() % 30;
    int val = rand() % 30;
    l1.resize(temp, val);
    s1.resize(temp, val);
    print_in_comp(s1, l1);
  }
}

void splice_list_check()
{
  std::cout<<"Splice check\n";
  int comp;
  comp = rand() % 10 + 3;
  for (int j = 0; j < comp; j++) {
    ft::list<int> l1;
    ft::list<int> l2;   
    std::list<int> s1;
    std::list<int> s2;
    int kpos = rand() % 5 + 2;
    for (int k = 0; k < kpos; k++) {
      int trand = rand() % 10 + 3;
      for (int l = 0; l < trand; l++) {
	int temp = rand () % 5 + 2;
	l2.push_front(temp);
	s2.push_front(temp);
      }
      // print_in_comp(s2, l2);
      // int lpos = rand() % s2.size();
      // int fpos;
      // if (lpos != 0)
      // 	fpos = rand() % lpos;
      // else
      // 	fpos = 0;
      // int ipos;
      // if (s1.empty())
      // 	ipos = 0;
      // else
      // 	ipos = rand() % s1.size();
      // ft::list<int>::const_iterator i1 = l2.begin();
      // std::list<int>::const_iterator si1 = s2.begin();
      // ft::list<int>::const_iterator i2 = l2.begin();
      // std::list<int>::const_iterator si2 = s2.begin();
      ft::list<int>::const_iterator i = l1.begin();
      std::list<int>::const_iterator si = s1.begin();
      // for (int o = 0; o < ipos; o++) {
      // 	i++;
      // 	si++;
      // }
      // for (int o = 0; o < fpos; o++) {
      // 	i1++;
      // 	si1++;
      // }
      // for (int o = 0; o < lpos; o++) {
      // 	i2++;
      // 	si2++;
      // }
      l1.splice(i, l2);
      s1.splice(si, s2);
      print_in_comp(s1, l1);
      print_comp_size(s2, l2);
    }
  }
  //random position
  comp = rand() % 10 + 3;
  for (int j = 0; j < comp; j++) {
    ft::list<int> l1;
    ft::list<int> l2;   
    std::list<int> s1;
    std::list<int> s2;
    int kpos = rand() % 5 + 2;
    for (int k = 0; k < kpos; k++) {
      int trand = rand() % 10 + 3;
      for (int l = 0; l < trand; l++) {
	int temp = rand () % 5 + 2;
	l2.push_front(temp);
	s2.push_front(temp);
      }
      // print_in_comp(s2, l2);
      // int lpos = rand() % s2.size();
      // int fpos;
      // if (lpos != 0)
      // 	fpos = rand() % lpos;
      // else
      // 	fpos = 0;
      int ipos;
      if (s1.empty())
	ipos = 0;
      else
	ipos = rand() % s1.size();
      // ft::list<int>::const_iterator i1 = l2.begin();
      // std::list<int>::const_iterator si1 = s2.begin();
      // ft::list<int>::const_iterator i2 = l2.begin();
      // std::list<int>::const_iterator si2 = s2.begin();
      ft::list<int>::const_iterator i = l1.begin();
      std::list<int>::const_iterator si = s1.begin();
      for (int o = 0; o < ipos; o++) {
	i++;
	si++;
      }
      //std::cout<<"Inserting at position " << *si << " list ";
      //print_ft_list(l2);
      l1.splice(i, l2);
      s1.splice(si, s2);
      print_in_comp(s1, l1);
      print_comp_size(s2, l2);
    }
  }
  comp = rand() % 10 + 3;
  for (int j = 0; j < comp; j++) {
    ft::list<int> l1;
    ft::list<int> l2;   
    std::list<int> s1;
    std::list<int> s2;
    int kpos = rand() % 5 + 2;
    for (int k = 0; k < kpos; k++) {
      int trand = rand() % 10 + 3;
      for (int l = 0; l < trand; l++) {
	int temp = rand () % 5 + 2;
	l2.push_front(temp);
	s2.push_front(temp);
      }
      // print_in_comp(s2, l2);
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
      ft::list<int>::const_iterator i1 = l2.begin();
      std::list<int>::const_iterator si1 = s2.begin();
      ft::list<int>::const_iterator i2 = l2.begin();
      std::list<int>::const_iterator si2 = s2.begin();
      ft::list<int>::const_iterator i = l1.begin();
      std::list<int>::const_iterator si = s1.begin();
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
      l1.splice(i, l2, i1, i2);
      s1.splice(si, s2, si1, si2);
      print_in_comp(s1, l1);
      print_comp_size(s2, l2);
    }
  }
  std::cout<<"If they are in the same list\n";
  ft::list<int> l1;
  std::list<int> s1;
  for (int i = 0; i < 10; i++) {
    l1.push_back(i);
    s1.push_back(i);
  }
  ft::list<int>::iterator it1 = l1.begin();
  std::list<int>::iterator sit1 = s1.begin();
  ft::list<int>::iterator it2 = l1.begin();
  std::list<int>::iterator sit2 = s1.begin();
  for (int i = 0; i < 0; i++) {
    it1++;
    sit1++;
  }
  for (int i = 0; i < 4; i++) {
    it2++;
    sit2++;
  }
  it2 = l1.end();
  sit2 = s1.end();
  //l1.splice(it1, l1, it2);
  s1.splice(sit1, s1, sit2);
  print_in_comp(s1, l1);
}

void remove_list_check()
{
  std::cout<<"Remove check\n";
  ft::list <int> l1;
  std::list <int> s1;
  for (int j = 0; j < 10; j++) {
    int r = rand() % 10 + 3;
    for (int i = 0; i < r; i++) {
      int temp = rand() % 5;
      l1.push_back(temp);
      s1.push_back(temp);
    }
    int temp = rand() % 5;
    std::cout<<"Removing element " << temp << std::endl;
    l1.remove(temp);
    s1.remove(temp);
    print_in_comp(s1, l1);
    l1.clear();
    s1.clear();
  }
  for (int i = 0; i < 10; i++) {
    l1.push_back(2);
    s1.push_back(2);
  }
  l1.remove(2);
  s1.remove(2);
  print_in_comp(s1, l1);
  l1.clear();
  s1.clear();
  for (int i = 0; i < 10; i++) {
    int temp = rand() % 20;
    l1.push_back(temp);
    s1.push_back(temp);
  }
  print_in_comp(s1, l1);
  l1.remove_if(is_not_prime);
  s1.remove_if(is_not_prime);
  std::cout<<"Removing all non-primes from lists:\n";
  print_in_comp(s1, l1);
}

void sort_list_check()
{
  std::cout<<"Sort check:\n";
  ft::list<int> l1;
  std::list<int> s1;
  for (int i = 0; i < 10; i++) {
    int sz = rand() % 20;
    for (int j = 0; j < sz; j++) {
      int temp = rand() % 20;
      l1.push_back(temp);
      s1.push_back(temp);
    }
    print_ft_list(l1);
    l1.sort();
    s1.sort();
    print_in_comp(s1, l1);
    l1.clear();
    s1.clear();
  }
}

void list_check()
{
  std::cout<<"--------------------LIST--------------------\n";
  constructor_list_check();
  iterator_list_check();
  capacity_list_check();
  front_and_back_list();
  assign_check_list();
  insert_list_check();
  erase_list_check();
  resize_list_check();
  splice_list_check();
  remove_list_check();
  sort_list_check();
  std::cout<<"--------------------------------------------\n";
}
