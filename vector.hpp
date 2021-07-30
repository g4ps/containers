#ifndef FT_VECTOR
#define FT_VECTOR

#include <memory>
#include "iterator.hpp"

namespace ft {

  template <typename T>
  class const_vector_iterator;
  
  //Normal iterator;
  //All the fields are located in protected, because we need access to them
  //  form derived reverse iterator
  template <typename T>
  class vector_iterator {
    friend class const_vector_iterator<T>;
  protected:
    T *ptr;
    T *_start;
    T *_end;
    int dir;
  public:
    typedef T value_type;
    vector_iterator()
    {
      ptr = NULL;
      _start = NULL;
      _end = NULL;
      dir = 1;
    }
    vector_iterator(const vector_iterator &v)
    {
      ptr = v.ptr;;
      _start = v._start;
      _end = v._end;
      dir = 1;
    }
    vector_iterator(const const_vector_iterator<T> &v)
    {
      ptr = v.ptr;;
      _start = v._start;
      _end = v._end;
      dir = 1;
    }
    vector_iterator(T *p, T *s, T *e)
    {
      ptr = p;
      _start = s;
      _end = e;
      dir = 1;
    }
    ~vector_iterator(){}

    const vector_iterator& operator=(const vector_iterator &v)
    {
      ptr = v.ptr;
      _start = v._start;
      _end = v._end;
      return *this;
    }

    const vector_iterator& operator=(const const_vector_iterator<T> &v)
    {
      ptr = v.ptr;
      _start = v._start;
      _end = v._end;
      return *this;
    }

    bool operator==(const vector_iterator &v)
    {
      if (ptr == v.ptr && _start == v._start && _end == v._end)
	return true;
      return false;       
    }

    bool operator!=(const vector_iterator &v)
    {
      return !(*this == v);      
    }

    T& operator*()
    {
      return *ptr;
    }

    const T* operator*() const
    {
      return *ptr;
    }

    //required for internal operations
    T* get_ptr() const
    {
      return ptr;
    }

    const vector_iterator& operator++()
    {
      if (ptr == _end + 1 && dir == 1)
	ptr = _start;
      else if (ptr == _start - 1 && dir == -1)
	ptr = _end;
      else
	ptr += dir;
      return *this;
    }

    const vector_iterator& operator++(int)
    {
      if (ptr == _end + 1 && dir == 1)
	ptr = _start;
      else if (ptr == _start - 1 && dir == -1)
	ptr = _end;
      else
	ptr += dir;
      return *this;
    }

    const vector_iterator& operator--()
    {
      if (ptr == _start - 1 && dir == 1)
	ptr = _end;
      else if (ptr == _end + 1 && dir == -1)
	ptr = _start;
      else
	ptr -= dir;
      return *this;
    }

    const vector_iterator& operator--(int)
    {
      if (ptr == _start - 1 && dir == 1)
	ptr = _start;
      else if (ptr == _end + 1 && dir == -1)
	ptr = _end;
      else
	ptr -= dir;
      return *this;
    }

    //Required, because for vector we have random-access iterators
    //(i.e. i + 5 is a valid operation)
    vector_iterator operator+(size_t n) {
      for (size_t i = 0; i < n; i++) {
	(*this)++;
      }
      return *this;
    }
    vector_iterator operator-(size_t n) {
      for (size_t i = 0; i < n; i++) {
	(*this)--;
      }
      return *this;
    }

    vector_iterator operator+=(size_t n) {
      for (size_t i = 0; i < n; i++) {
	(*this)++;
      }
      return *this;
    }
    vector_iterator operator-=(size_t n) {
      for (size_t i = 0; i < n; i++) {
	(*this)--;
      }
      return *this;
    }
    
  };


  template <typename T>
  class const_vector_iterator {
    friend class vector_iterator<T>;
  protected:
    T *ptr;
    T *_start;
    T *_end;
    int dir;
  public:
    typedef T value_type;
    const_vector_iterator()
    {
      ptr = NULL;
      _start = NULL;
      _end = NULL;
      dir = 1;
    }
    const_vector_iterator(const const_vector_iterator &v)
    {
      ptr = v.ptr;;
      _start = v._start;
      _end = v._end;
      dir = 1;
    }
    const_vector_iterator(const vector_iterator<T> &v)
    {
      ptr = v.ptr;;
      _start = v._start;
      _end = v._end;
      dir = 1;
    }
    
    const_vector_iterator(T *p, T *s, T *e)
    {
      ptr = p;
      _start = s;
      _end = e;
      dir = 1;
    }
    
    ~const_vector_iterator(){}

    const const_vector_iterator& operator=(const vector_iterator<T> &v)
    {
      ptr = v.ptr;
      _start = v._start;
      _end = v._end;
      return *this;
    }

    const const_vector_iterator& operator=(const const_vector_iterator &v)
    {
      ptr = v.ptr;
      _start = v._start;
      _end = v._end;
      return *this;
    }

    bool operator==(const const_vector_iterator &v)
    {
      if (ptr == v.ptr && _start == v._start && _end == v._end)
	return true;
      return false;       
    }

    bool operator!=(const const_vector_iterator &v)
    {
      return !(*this == v);      
    }

    const T& operator*()
    {
      return *ptr;
    }

    //required for internal operations
    const T* get_ptr() const
    {
      return ptr;
    }

    const vector_iterator<T>& operator++()
    {
      if (ptr == _end + 1 && dir == 1)
	ptr = _start;
      else if (ptr == _start - 1 && dir == -1)
	ptr = _end;
      else
	ptr += dir;
      return *this;
    }

    const_vector_iterator<T>& operator++(int)
    {
      if (ptr == _end + 1 && dir == 1)
	ptr = _start;
      else if (ptr == _start - 1 && dir == -1)
	ptr = _end;
      else
	ptr += dir;
      return *this;
    }

    const_vector_iterator<T>& operator--()
    {
      if (ptr == _start - 1 && dir == 1)
	ptr = _end;
      else if (ptr == _end + 1 && dir == -1)
	ptr = _start;
      else
	ptr -= dir;
      return *this;
    }

    const_vector_iterator& operator--(int)
    {
      if (ptr == _start - 1 && dir == 1)
	ptr = _start;
      else if (ptr == _end + 1 && dir == -1)
	ptr = _end;
      else
	ptr -= dir;
      return *this;
    }

    //Required, because for vector we have random-access iterators
    //(i.e. i + 5 is a valid operation)
    vector_iterator<T> operator+(size_t n) {
      for (size_t i = 0; i < n; i++) {
	(*this)++;
      }
      return *this;
    }
    
    vector_iterator<T> operator-(size_t n) {
      for (size_t i = 0; i < n; i++) {
	(*this)--;
      }
      return *this;
    }
      
    vector_iterator<T> operator+=(size_t n) {
      for (size_t i = 0; i < n; i++) {
	(*this)++;
      }
      return *this;
    }
    vector_iterator<T> operator-=(size_t n) {
      for (size_t i = 0; i < n; i++) {
	(*this)--;
      }
      return *this;
    }
    
  };


  
  template <typename T, typename Alloc = std::allocator<T> >
  class vector
  {
  public:
    //Required typedef's
    typedef T value_type;
    typedef Alloc allocator_type;
    typedef typename Alloc::reference reference;
    typedef typename Alloc::const_reference const_reference;
    typedef typename Alloc::pointer pointer;
    typedef typename Alloc::const_pointer const_pointer;
    typedef vector_iterator<T> iterator;
    typedef const_vector_iterator<T> const_iterator;
    typedef _reverse_iterator<vector_iterator<T> > reverse_iterator;
    typedef _reverse_iterator<const_vector_iterator<T> > const_reverse_iterator;
    typedef std::ptrdiff_t difference_type;
    typedef std::size_t size_type;
  private:

    //Internal structure: Pointer to first element
    //and  a counple of ints for size managment
    T *_start;
    size_type _size;
    size_type _cap;
    Alloc _allocator;
    void check_and_increase_cap(size_type n = 1)
    {
      size_type temp = _cap;
      if (_size + n <= _cap) {
	_size += n;
	return;
      }
      while (temp - _cap < n) {
	if (temp == 0)
	  temp = 1;
	else
	  temp *= 2;
      }
      T *ptr = _allocator.allocate(temp);
      for (size_type i = 0; i < _size; i++) {
	_allocator.construct(ptr + i, *(_start + i));
      }
      _allocator.deallocate(_start, _size);
      _size += n;
      _cap = temp;
      _start = ptr;
    }

    
  public:
    //constructors
    explicit vector(const allocator_type& alloc = allocator_type())
    {
      _start = NULL;
      _size = 0;
      _cap = 0;
      _allocator = alloc;
    }

    explicit vector(size_type n, const value_type& val= value_type(), const allocator_type& alloc = allocator_type())
    {
      _allocator = alloc;
      _start = _allocator.allocate(n);
      _size = n;
      for (size_type i = 0; i < _size; i++) {
	_allocator.construct(_start + i, val);
      }
      _cap = _size;
    }

    template <typename II>
    vector(II first, II last, const allocator_type& alloc = allocator_type())
    {
      _start = NULL;
      _size = 0;
      _cap = 0;
      _allocator = alloc;
      while (first != last) {
	this->push_back(*first);
	first++;
      }
    }

    template <>
    vector<int> (int n, int val, const allocator_type& alloc = allocator_type())
    {
      _allocator = alloc;
      _start = _allocator.allocate(n);
      _size = n;
      for (int i = 0; i < n; i++) {
	_allocator.construct(_start + i, val);
      }
      _cap = _size;
    }

    template <>
    vector<long> (long n, long val, const allocator_type& alloc = allocator_type())
    {
      _allocator = alloc;
      _start = _allocator.allocate(n);
      _size = n;
      for (long i = 0; i < n; i++) {
	_allocator.construct(_start + i, val);
      }
      _cap = _size;
    }

    template <>
    vector<char> (char n, char val, const allocator_type& alloc = allocator_type())
    {
      _allocator = alloc;
      _start = _allocator.allocate(n);
      _size = n;
      for (char i = 0; i < n; i++) {
	_allocator.construct(_start + i, val);
      }
      _cap = _size;
    }

    vector(const vector &vec)
    {
      iterator i;
      _start = NULL;
      _size = 0;
      _cap = 0;
      _allocator = vec._allocator;
      for (i = vec.begin(); i != vec.end(); i++) {
	this->push_back(*i);
      }
    }

    
    virtual ~vector()
    {
      for (size_type i = 0; i < _size; i++) {
	_allocator.destroy(_start + i);
      }
      _allocator.deallocate(_start, _size);
      return ;
    }

    const vector &operator=(const vector &vec) {
      clear();
      iterator i;
      _start = NULL;
      _size = 0;
      _cap = 0;
      _allocator = vec._allocator;
      for (i = vec.begin(); i != vec.end(); i++) {
	this->push_back(*i);
      }
      return *this;
    }

    //Iterators
    iterator begin()
    {
      iterator ret(_start, _start, _start + _size);
      return ret;
    }

    const_iterator begin() const
    {
      const_iterator ret(_start, _start, _start + _size);
      return ret;
    }

    iterator end()
    {
      iterator ret(_start + _size, _start, _start + _size);
      return ret;
    }

    const_iterator end() const
    {
      const_iterator ret(_start + _size, _start, _start + _size);
      return ret;
    }

    reverse_iterator rbegin()
    {
      iterator ret(_start + _size - 1, _start, _start + _size);
      reverse_iterator i(ret);
      return i;
    }

    const_reverse_iterator rbegin() const
    {
      iterator ret(_start + _size - 1, _start, _start + _size);
      const_reverse_iterator i(ret);
      return i;
    }

    reverse_iterator rend()
    {
      iterator ret(_start - 1, _start, _start + _size);
      reverse_iterator i(ret);
      return i;
    }

    const_reverse_iterator rend() const
    {
      iterator ret(_start - 1, _start, _start + _size);
      const_reverse_iterator i(ret);
      return i;
    }

    //capacity

    size_type size() const
    {
      return _size;
    }

    size_type max_size() const
    {
      return _allocator.max_size();
    }

    void resize(size_type n, value_type val = value_type())
    {
      if (n <= _size) {
	for (size_type i = _size; i < n; i++)
	  this->push_back(val);
      }
      while (_size > n)
	this->pop_back();
    }

    size_type capacity() const
    {
      return _cap;
    }

    bool empty() const
    {
      return _size == 0;
    }

    void reserve(size_type n)
    {
      if (_cap >= n)
	return ;
      check_and_increase_cap(n - _cap);
    }

    //Access
    reference operator[] (size_type n)
    {
      return _start[n];
    }

    const_reference operator[](size_type n) const   
    {
      return _start[n];
    }

    reference at(size_type n)
    {
      if (n >= _size)
	throw std::out_of_range("ft::vector: argument is out of range");
      return _start[n];
    }

    const_reference at(size_type n) const
    {
      if (n >= _size)
	throw std::out_of_range("ft::vector: argument is out of range");
      return _start[n];
    }

    reference front()
    {
      return *_start;
    }

    const_reference front() const
    {
      return *_start;
    }

    reference back()
    {
      return _start[_size - 1];
    }

    const_reference back() const
    {
      return _start[_size - 1];
    }

    //Modifiers

    template <typename II>
    void assign(II first, II last)
    {
      this->clear();
      while (first != last) {
	this->push_back(*first);
	first++;
      }
    }

    template <>
    void assign<int>(int n, int val)
    {
      this->clear();
      for (int i = 0; i < n; i++) {
	this->push_back(val);
      }     
    }

    template <>
    void assign<char>(char n, char val)
    {
      this->clear();
      for (char i = 0; i < n; i++) {
	this->push_back(val);
      }     
    }

    template <>
    void assign<long>(long n, long val)
    {
      this->clear();
      for (long i = 0; i < n; i++) {
	this->push_back(val);
      }     
    }

    void assign(size_type n, const value_type &val)
    {
      this->clear();
      for (size_type i = 0; i < n; i++) {
	this->push_back(val);
      }
    }

    void push_back(const value_type &val)
    {
      check_and_increase_cap(1);
      _start[_size - 1] = val;
    }

    void pop_back()
    {
      if (_size == 0)
	return ;
      _size--;
      _allocator.destroy(_start + _size - 1);
    }

    iterator insert (iterator position, const value_type &val)
    {
      T *ptr = position.get_ptr();
      size_type pos = ptr - _start;
      check_and_increase_cap(1);
      for (size_type i = _size - 1; i > pos; i--) {
	_start[i] = _start[i - 1];
      }
      _start[pos] = val;
      iterator ret(_start + pos, _start, _start + _size);
      return ret;
    }

    iterator insert (iterator position, size_type n, const value_type &val)
    {
      T *ptr = position.get_ptr();
      size_type pos = ptr - _start;
      check_and_increase_cap(n);
      for (size_type i = _size - 1; i > pos; i--) {
	_start[i] = _start[i - n];
      }
      for(size_type i = 0; i < n; i++)
	_start[pos + i] = val;
      iterator ret(_start + pos, _start, _start + _size);
      return ret;
    }

    template <typename II>
    iterator insert(iterator position, II first, II last)
    {
      size_type s = 0;
      while (first != last) {
	s++;
	position = insert(position, *first);
	position++;
	first++;
      }
      return position - s;
    }

    template <>
    iterator insert(iterator position, int n, int val)
    {
      T *ptr = position.get_ptr();
      size_type pos = ptr - _start;
      check_and_increase_cap(n);
      for (size_type i = _size - 1; i > pos; i--) {
	_start[i] = _start[i - n];
      }
      for(int i = 0; i < n; i++)
	_start[pos + i] = val;
      iterator ret(_start + pos, _start, _start + _size);
      return ret;
    }

    iterator erase(iterator position) {
      iterator ret = position;
      size_type pos = position.get_ptr() - _start;
      _allocator.destroy(position.get_ptr());
      for (size_type i = pos; i != _size - 1; i++) {
	_start[i] = _start[i + 1];
      }
      _size--;
      return ret;
    }

    iterator erase(iterator first, iterator last) {
      while (first != last) {
	first = erase(first);
	last--;
      }
      return first;
    }

    void clear() {
      _allocator.deallocate(_start, _size);
      _size = 0;
      _start = NULL;
      _cap = 0;
    }

    void swap (ft::vector<T, Alloc> &v) {
      T* temp;
      temp = v._start;
      v._start = _start;
      _start = temp;
      size_type n = v._size;
      v._size = _size;
      _size = n;
      n = v._cap;
      v._cap = _cap;
      _cap = n;            
    }

    allocator_type get_allocator() const
    {
      return _allocator;
    }

    
  };
  
  template <class T, class Alloc>
  void swap (vector<T,Alloc>& x, vector<T,Alloc>& y)
  {
    x.swap(y);
  }

  template <typename T, typename Alloc>
  bool operator==(const ft::vector<T, Alloc>& lhs, const ft::vector<T, Alloc>& rhs)
  {
    if (lhs.size() != rhs.size())
      return false;
    typename ft::vector<T>::iterator i;
    typename ft::vector<T>::iterator i1;
    i1 = rhs.begin();
    for (i = lhs.begin(); i != lhs.end(); i++) {
      if (*i != *i1)
	return false;
      i1++;
    }
    return true;
  }

  template <typename T, typename Alloc>
  bool operator!=(const ft::vector<T, Alloc>& lhs, const ft::vector<T, Alloc>& rhs)
  {
    return !(lhs == rhs);
  }

  template <typename T, typename Alloc>
  bool operator<(const ft::vector<T, Alloc>& lhs, const ft::vector<T, Alloc>& rhs)
  {
    return ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
  }

  template <typename T, typename Alloc>
  bool operator>(const ft::vector<T, Alloc>& lhs, const ft::vector<T, Alloc>& rhs)
  {
    return rhs < lhs;
  }

  template <typename T, typename Alloc>
  bool operator<=(const ft::vector<T, Alloc>& lhs, const ft::vector<T, Alloc>& rhs)
  {
    return !(rhs < lhs);
  }

  template <typename T, typename Alloc>
  bool operator>=(const ft::vector<T, Alloc>& lhs, const ft::vector<T, Alloc>& rhs)
  {
    return !(lhs < rhs);
  }
  
}

#endif
