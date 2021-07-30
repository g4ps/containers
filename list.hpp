#ifndef FT_LIST
#define FT_LIST

#include "lex.hpp"
#include "iterator.hpp"
#include <limits>
#include <stdint.h>
#include <memory>

namespace ft {
  
  template <typename T>
  bool
  comp_func(T &a, T &b)
  {
    return a < b;
  } 
  
  template <typename T>
  struct _node {
      _node *next;
      _node *prev;
      T* data;
  };

  template <typename T>
  class const_list_iterator;
  
  template <typename T>
  class list_iterator {
  protected:
    _node<T> *n;
    int dir;
  public:
    list_iterator(): n(NULL), dir(1) {}
    list_iterator(const list_iterator<T> &v): n(v.get_node()), dir(1) {}
    list_iterator(const const_list_iterator<T> &v): n(v.get_node()), dir(1) {}
    list_iterator(_node<T> *v): n(v), dir(1) {}
    ~list_iterator(){}

    //typedefs
    typedef T value_type;
    

    _node<T>* get_node() const
    {
      return n;
    }
    const list_iterator& operator=(const list_iterator&v)
    {
      n = v.n;
      return *this;
    }

    const list_iterator& operator=(const const_list_iterator<T>&v)
    {
      n = v.get_node();
      return *this;
    }

    bool operator==(const list_iterator &v)
    {
      return (n == v.n);
    }

    bool operator!=(const list_iterator &v)
    {
      return (n != v.n);
    }

    T& operator*()
    {      
      return (*n->data);
    }

    const T& operator*() const
    {
      return (n->data);
    }

    const list_iterator& operator++()
    {
      if (dir == 1)
	n = n->next;
      else
	n = n->prev;      
      return *this;
    }

    const list_iterator& operator++(int)
    {
      if (dir == 1)
	n = n->next;
      else
	n = n->prev;      
      return *this;
    }

    const list_iterator& operator--()
    {
      if (dir == 1)
	n = n->prev;
      else
	n = n->next;      
      return *this;
    }

    const list_iterator& operator--(int)
    {
      if (dir == 1)
	n = n->prev;
      else
	n = n->next;    
      return *this;
    }
  };


  template <typename T>
  class const_list_iterator {
  protected:
    _node<T> *n;
    int dir;    
  public:
    const_list_iterator(): n(NULL), dir(1) {}
    const_list_iterator(const list_iterator<T> &v): n(v.get_node()), dir(1) {}
    const_list_iterator(const const_list_iterator<T> &v): n(v.n), dir(1) {}
    const_list_iterator(_node<T> *v): n(v), dir(1) {}
    ~const_list_iterator(){}

    //typedefs
    typedef T value_type;
    

    _node<T>* get_node() const
    {
      return n;
    }

    
    const const_list_iterator& operator=(const const_list_iterator<T>&v)
    {
      n = v.n;
      return *this;
    }

    const const_list_iterator& operator=(const list_iterator<T>&v)
    {
      n = v.get_node();
      return *this;
    }

    bool operator==(const const_list_iterator &v)
    {
      return (n == v.n);
    }

    bool operator!=(const const_list_iterator &v)
    {
      return (n != v.n);
    }

    const T& operator*()
    {      
      return (*n->data);
    }

    const T& operator*() const
    {
      return (n->data);
    }

    const const_list_iterator& operator++()
    {
      if (dir == 1)
	n = n->next;
      else
	n = n->prev;      
      return *this;
    }

    const const_list_iterator& operator++(int)
    {
      if (dir == 1)
	n = n->next;
      else
	n = n->prev;      
      return *this;
    }

    const const_list_iterator& operator--()
    {
      if (dir == 1)
	n = n->prev;
      else
	n = n->next;      
      return *this;
    }

    const const_list_iterator& operator--(int)
    {
      if (dir == 1)
	n = n->prev;
      else
	n = n->next;    
      return *this;
    }
  }; 


  template <typename T, typename Alloc = std::allocator<T> >
  class list {
  public:
    //Typedefs for different types
    typedef T value_type;
    typedef Alloc allocator_type;
    typedef typename Alloc::reference reference;
    typedef typename Alloc::const_reference const_reference;
    typedef typename Alloc::pointer pointer;
    typedef typename Alloc::const_pointer const_pointer;
    typedef list_iterator<T> iterator;
    typedef const_list_iterator<T> const_iterator;
    typedef _reverse_iterator<list_iterator<T> > reverse_iterator;
    typedef _reverse_iterator<const_list_iterator<T> > const_reverse_iterator;
    typedef std::ptrdiff_t difference_type;
    typedef std::size_t size_type;
  private:
    _node<T> *n;
    _node<T> *_end;
    _node<T> *sent;
    size_type _size;
    Alloc _allocator;

  private:
    void clear_list() {
      _node<T> *i = sent->next;
      _node<T> *temp;
      while (i != sent) {
	temp = i->next;
	_allocator.destroy(i->data);
	_allocator.deallocate(i->data, 1);
	delete i;
	i = temp;
      }
      n = sent;
      _end = sent;
      sent->prev = sent;
      sent->next = sent;
      _size = 0;
    }
    
    void initialize_with_sequence(size_type n1, const value_type& val = value_type(),  const allocator_type& alloc = allocator_type()) {
      sent = new _node<T>;
      _end = sent;
      n = sent;
      sent->prev = _end;
      sent->next = n;
      _size = 0;
      _allocator = alloc;
      for (size_type i = 0; i < n1; i++) {
	this->push_back(val);
      }
    }

    void _swap(iterator i1, iterator i2) {
      iterator temp;
      if (i1 == i2)
	return ;
      _node <T> *tp = i1.get_node()->prev;
      _node <T> *tn = i1.get_node()->next;
      i1.get_node()->prev->next = i2.get_node();
      i2.get_node()->next->prev = i1.get_node();

      if (i1.get_node()->next != i2.get_node()) {
	i1.get_node()->next->prev = i2.get_node();     
	i2.get_node()->prev->next = i1.get_node();
	i1.get_node()->prev = i2.get_node()->prev;
	i1.get_node()->next = i2.get_node()->next;
	i2.get_node()->prev = tp;
	i2.get_node()->next = tn;
      }
      else {
	tp = i2.get_node()->next;
	i2.get_node()->next = i1.get_node();
	i2.get_node()->prev = i1.get_node()->prev;
	i1.get_node()->prev = i2.get_node();
	i1.get_node()->next = tp;
      }
      //changing the element itself

      if (n == i1.get_node())
	n = i2.get_node();
      else if (n == i2.get_node())
	n = i1.get_node();
      if (_end == i1.get_node())
	_end = i2.get_node();
      else if (_end == i2.get_node())
	_end = i1.get_node();
      
    }
    
    template <class Compare>
    iterator __part(iterator i1, iterator i2, Compare comp)
    {
      iterator x = i2;
      iterator temp = i2;
      iterator i = i1;
      iterator j = i1;
      i--;
      while (j != temp) {
	iterator next  = j;
	next++;
	if (comp(*j, *x)) {
	  i++;
	  iterator in;
	  _swap(i, j);
	  in = j;
	  j = i;
	  i = in;
	}
	j = next;
      }
      i++;
      _swap(i, x);
      return x;
    }
    
    template <class Compare>
    void __sort(iterator i1, iterator i2, Compare comp)
    {
      if (i1 != i2) {
	iterator q = __part(i1, i2, comp);
	q--;
	__sort(i1, q, comp);
	q++;
	q++;
	__sort(q, i2, comp);
      }
    }

  public:
    explicit list(const allocator_type& alloc = allocator_type()): _allocator(alloc)
    {
      sent = new _node<T>;
      _end = sent;
      n = sent;
      sent->prev = _end;
      sent->next = n;
      _size = 0;
    }

    explicit list(size_type n1, const value_type& val = value_type(),
		  const allocator_type& alloc = allocator_type()): _allocator(alloc)
    {
      initialize_with_sequence(n1, val, alloc);
    }
    
    
    template <class InputIterator>
    list (InputIterator first, InputIterator last,
	  const allocator_type& alloc = allocator_type()): _allocator(alloc)
    {
      sent = new _node<T>;
      _end = sent;
      n = sent;
      sent->prev = _end;
      sent->next = n;
      _size = 0;
      for (; first != last; first++) {
	this->push_back(*first);
      }
    }

    template <>
    list<int>(int first, int last,
	  const allocator_type& alloc = allocator_type()): _allocator(alloc)
    {
      initialize_with_sequence(first, last, alloc);
    }

    template <>
    list<char>(char first, char last,
	  const allocator_type& alloc = allocator_type()): _allocator(alloc)
    {
      initialize_with_sequence(first, last, alloc);
    }

    template <>
    list<long>(long first, long last,
	  const allocator_type& alloc = allocator_type()): _allocator(alloc)
    {
      initialize_with_sequence(first, last, alloc);
    }


    allocator_type get_allocator() const
    {
      return _allocator;
    }

    list (const list &x) {
      sent = new _node<T>;
      _end = sent;
      n = sent;
      sent->prev = _end;
      sent->next = n;
      _size = 0;
      *this = x;
    }

    list& operator= (const list &x) {
      iterator i = x.begin();
      iterator lend = x.end();
      this->clear_list();
      while (i != lend) {
	this->push_back(*i);
	i++;
      }
      return *this;
    }

    virtual ~list() {
      this->clear_list();
      delete sent;      
    }
    

    template <typename InputIterator>
    void assign(InputIterator first, InputIterator last)
    {
      this->clear_list();
      for (; first != last; first++) {
	this->push_back(*first);
      }
    }

    template <>
    void assign<int>(int first, int last)
    {
      this->clear_list();
      for (int i = 0; i < first; i++) {
	push_back(last);
      }
    }

    template <>
    void assign<char>(char first, char last)
    {
      this->clear_list();
      for (char i = 0; i < first; i++) {
	push_back(last);
      }
    }

    template <>
    void assign<long>(long first, long last)
    {
      this->clear_list();
      for (long i = 0; i < first; i++) {
	push_back(last);
      }
    }

    void assign (size_type n, const value_type& val)
    {
      this->clear_list();
      for (size_type i = 0; i < n; i++) {
	push_back(val);
      }
    }

    
    bool empty() const
    {
      return (_size == 0);
    }

    size_type max_size() const
    {
      return _allocator.max_size();
    }

    void push_front(const_reference v)
    {
      _node<T> *temp = new _node<T>;
      pointer t_data = _allocator.allocate(1);
      _allocator.construct(t_data, v);
      temp->data = t_data;
      if (_size == 0) {
	temp->next = sent;
	temp->prev = sent;
	sent->next = temp;
	sent->prev = temp;
	n = temp;
	_end = temp;
	_size = 1;
      }
      else {
	sent->next = temp;
	temp->prev = sent;
	n->prev = temp;
	temp->next = n;
	n = temp;
	_size++;
      }
    }

    void pop_front()
    {
      if (_size == 0)
	return;
      else if (_size == 1) {
	_allocator.deallocate(n->data, 1);
	delete n;
	n = sent;
	_end = sent;
	_size = 0;
	sent->next = sent;
	sent->prev = sent;
      }
      else {
	_allocator.deallocate(n->data, 1);
	_node<T> *ptr = n;
	n = n->next;
	sent->next = n;
	delete ptr;
	_size--;
      }
    }

    void push_back(const_reference v)
    {
      _node<T> *temp = new _node<T>;
      pointer t_data = _allocator.allocate(1);
      _allocator.construct(t_data, v);
      temp->data = t_data;
      if (_size == 0) {
	temp->next = sent;
	temp->prev = sent;
	sent->next = temp;
	sent->prev = temp;
	_end = temp;
	n = temp;
	_size = 1;
      }
      else {
	sent->prev = temp;
	temp->next = sent;
	_end->next = temp;
	temp->prev = _end;
	_end = temp;
	_size++;
      }
    }

    void pop_back()
    {
      //      _node<T> *temp;
      if (_size == 0)
	return ;
      else if (_size == 1) {
	_allocator.deallocate(n->data, 1);
	delete(n);
	n = sent;
	_end = sent;
	sent->next = sent;
	sent->prev = sent;
	_size = 0;
      }
      else {
	_allocator.deallocate(_end->data, 1);
	_end = _end->prev;
	delete(_end->next);
	_end->next = sent;
	sent->prev = _end;
	_size--;
      }      
    }

    size_type size() const
    {
      return _size;
    }

    reference front()
    {
      return *n->data;
    }

    const_reference front() const
    {
      return *n->data;     
    }

    reference back()
    {
      return *_end->data;
    }

    const_reference back() const
    {
      return *_end->data;
    }


    iterator begin()
    {
      return iterator(n);
    }

    const_iterator begin() const
    {
      return const_iterator(n);
    }

    iterator end()
    {
      return iterator(sent);
    }

    const_iterator end() const
    {
      return const_iterator(sent);
    }

    reverse_iterator rbegin()
    {
      iterator i(_end);
      reverse_iterator k(i);
      return k;
    }

    const_reverse_iterator rbegin() const
    {
      const_iterator i(_end);
      const_reverse_iterator k(i);
      return k;
    }

    reverse_iterator rend()
    {
      iterator i(sent);
      return reverse_iterator(n->prev);
    }

    const_reverse_iterator rend() const
    {
      const_iterator i(sent);
      const_reverse_iterator k(i);
      return k;
    }

    iterator insert(iterator position, const value_type& val)
    {
      _node<T> *temp = new _node<T>;
      temp->data = _allocator.allocate(1);
      _allocator.construct(temp->data, val);
      temp->next = position.get_node();
      temp->prev = position.get_node()->prev;
      position.get_node()->prev->next = temp;
      position.get_node()->prev = temp;
      if (_size == 0) {
	_end = temp;
      }
      if (temp->prev == sent) {
	n = temp;
      }
      _size++;
      position--;
      return position;
    }

    void insert(iterator position, size_type num, const value_type& v) {
      for (size_type i = 0; i < num; i++) {
	position = insert(position, v);
      }     
    }

    template <class InputIterator>
    void insert(iterator position, InputIterator first, InputIterator last) {
      if (first == last)
	return ;
      last--;
      while (first != last) {
	position = insert(position, *last);
	last--;
      }
      position = insert(position, *first);
    }

    template <>
    void insert<int>(iterator position, int num, int v) {
      for (int i = 0; i < num; i++) {
	position = insert(position, v);
      }     
    }

    void clear()
    {
      this->clear_list();
    }

    iterator erase(iterator position)
    {
      _node<T> *ptr;
      ptr = position.get_node();
      position++;
      if (ptr == n)
	n = n->next;
      if (ptr == _end)
	_end = _end->prev;
      ptr->next->prev = ptr->prev;
      ptr->prev->next = ptr->next;
      _allocator.deallocate(ptr->data, 1);
      delete ptr;
      _size--;
      return position;
    }

    iterator erase(iterator first, iterator last)
    {
      while (first != last) {
	first = erase(first);
      }
      return first;
    }

    void swap(ft::list<T>& x) {
      _node<T> *temp;
      temp = x.n;
      x.n = n;
      n = temp;

      temp = x._end;
      x._end = _end;
      _end = temp;

      temp = x.sent;
      x.sent = sent;
      sent = temp;
      
      size_type s;
      s = x._size;
      x._size = _size;
      _size = s;
    }

    void resize(size_type num, value_type val = value_type()) {
      if (_size == num)
	return;
      else if (_size > num) {
	// iterator it = this->begin();
	// size_type i;
	// for (i = 0; i < num; i++) {
	//   it++;
	// }
	// this->erase(it, this->end());
	while (size() != num)
	  pop_back();
      }
      else {
	size_type i;
	for (i = _size; i < num; i++) {
	  this->push_back(val);
	}
      }
    }

    void splice (iterator position, list<T>& x, iterator i) {
      _node<T> *local;
      _node<T> *ext;
      local = position.get_node();
      ext = i.get_node();
      if (ext == x.n)
	x.n = x.n->next;
      if (ext == x._end)
	x._end = x._end->prev;
      //removing from the first list
      ext->prev->next = ext->next;
      ext->next->prev = ext->prev;
      //setting new element
      ext->prev = local->prev;
      ext->next = local;
      //inserting it into the list
      local->prev->next = ext;
      local->prev = ext;
      if (n == local)
	n = ext;
      if (local == sent)
	_end = ext;
      x._size--;
      _size++;
    }

    void splice (iterator position, list<T>& x) {
      while (x.size() != 0) {
	splice(position, x, x.begin());
      }
    }

    void splice(iterator position, list<T>& x, iterator first, iterator last) {
      iterator i;
      iterator temp;
      if (first == last)
	return;
      i = position;
      while (first != last) {
	i--;
	temp = first;
	temp++;
	splice(position, x, first);
	first = temp;
	//position = i;
      }
      //splice(position, x, last);
    }

    void remove(const value_type& val)
    {
      iterator i = this->begin();
      iterator tmp;      
      while (i != this->end()) {
	if (*i == val) {
	  tmp = i;
	  tmp++;
	  this->erase(i);
	  i = tmp;
	}
	else
	  i++;
      }
    }

    template <typename Predicate>
    void remove_if(Predicate pred)
    {
      iterator i = this->begin();
      iterator tmp;      
      while (i != this->end()) {
	if (pred(*i)) {
	  tmp = i;
	  tmp++;
	  this->erase(i);
	  i = tmp;
	}
	else
	  i++;
      }
    }

    void unique()
    {
      iterator i1 = this->begin();
      iterator i2 = i1;
      iterator tmp;
      i2++;
      while (i2 != this->end()) {
	if (*i1 == *i2) {
	  tmp = i2;
	  tmp++;
	  this->remove(i2);
	  i2 = tmp;
	}
	else {
	  i1++;
	  i2++;
	}
      }
    }

    template <typename BP>
    void unique(BP b)
    {
      iterator i1 = this->begin();
      iterator i2 = i1;
      iterator tmp;
      i2++;
      while (i2 != this->end()) {
	if (b(*i1,*i2)) {
	  tmp = i2;
	  tmp++;
	  this->remove(i2);
	  i2 = tmp;
	}
	else {
	  i1++;
	  i2++;
	}
      }
    }

    template <typename Compare>
    void merge(ft::list<T> &x, Compare comp)
    {
      iterator i1;
      iterator i2;
      iterator t1;
      iterator t2;
      i1 = this->begin();
      i2 = x.begin();
      while (i2 != x.end() && i1 != this->end()) {
	if (!comp(*i1, *i2)) {
	  t1 = i1;
	  t2 = i2;
	  t1++;
	  t2++;
	  this->splice(i1, x, i2);
	  i1 = t1;
	  i2 = t2;
	}
	else {
	  i1++;
	}
      }
      if (i1 == this->end()) {
	this->splice(this->end(), x);
      }
    }

    void merge(ft::list<T> &x)
    {
      this->merge(x, comp_func<T>);
    }

    template <typename Compare>    
    void sort(Compare comp)
    {
      if (this->size() <= 1)
	return ;
      // iterator i1 = this->begin();
      // iterator i2 = this->end();
      // i2--;
      // __sort(i1, i2, comp);
      ft::list<T> t1;
      ft::list<T> t2;
      iterator i = this->begin();
      iterator t;
      while (i != this->end()) {
	t = i;
	t++;
	t2.splice(t2.begin(), *this, i);
	t1.merge(t2, comp);
	i = t;
      }
      this->swap(t1);
    }

    void sort()
    {
      this->sort(comp_func<T>);
    }

    void reverse()
    {
      if (_size <= 1)
	return;
      _node<T> *ptr;
      _node<T> *temp;
      ptr = sent->next;
      //switching all elements
      while (ptr != sent) {
	temp = ptr->next;
	ptr->next = ptr->prev;
	ptr->prev = temp;
	ptr = ptr->prev;
      }
      temp = sent->next;
      sent->next = sent->prev;
      sent->prev = temp;
      temp = n;
      n = _end;
      _end = temp;
    }
    
  };

  template <typename T, typename Alloc>
  bool operator==(const ft::list<T, Alloc>& lhs, const ft::list<T, Alloc>& rhs)
  {
    if (lhs.size() != rhs.size())
      return false;
    typename ft::list<T>::iterator i;
    typename ft::list<T>::iterator i1;
    i1 = rhs.begin();
    for (i = lhs.begin(); i != lhs.end(); i++) {
      if (*i != *i1)
	return false;
      i1++;
    }
    return true;
  }

  template <typename T, typename Alloc>
  bool operator!=(const ft::list<T, Alloc>& lhs, const ft::list<T, Alloc>& rhs)
  {
    return !(lhs == rhs);
  }

  template <typename T, typename Alloc>
  bool operator<(const ft::list<T, Alloc>& lhs, const ft::list<T, Alloc>& rhs)
  {
    return ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
  }

  template <typename T, typename Alloc>
  bool operator>(const ft::list<T, Alloc>& lhs, const ft::list<T, Alloc>& rhs)
  {
    return rhs < lhs;
  }

  template <typename T, typename Alloc>
  bool operator<=(const ft::list<T, Alloc>& lhs, const ft::list<T, Alloc>& rhs)
  {
    return !(rhs < lhs);
  }

  template <typename T, typename Alloc>
  bool operator>=(const ft::list<T, Alloc>& lhs, const ft::list<T, Alloc>& rhs)
  {
    return !(lhs < rhs);
  }
  //----------------------------------------

  

}

#endif

