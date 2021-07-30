#ifndef FT_MAP_HPP
#define FT_MAP_HPP

#include <memory>
#include "iterator.hpp"

namespace ft {

  //Struct for the insides
  template <typename pointer>
  struct _mnode
  {
    _mnode* parent;
    _mnode* left;
    _mnode* right;
    pointer *ptr;
    _mnode()
    {
      parent = NULL;
      left = NULL;
      right = NULL;
      ptr = NULL;
    }
    _mnode(pointer *p1)
    {
      parent = NULL;
      left = NULL;
      right = NULL;
      ptr = p1;
    }
  };

  //Struct less for the map
  //IDK if i need to implement it myself instead of borrowing it from the STD
  //but it's not hard, so fuck it
  template <class T> struct less {
    typedef T first_argument_type;
    typedef T second_argument_type;
    typedef bool result_type;
    bool operator() (const T& x, const T& y) const {return x<y;}
  };

  

  //Same with pairs, most of it was copied from
  //the reference
  template <typename C1, typename C2>  
  struct pair {
    typedef C1 first_type;
    typedef C2 second_type;
    C1 first;
    C2 second;
    //constructors
    pair(){};

    template <typename C, typename U>
    pair(const pair<C, U>& pr)
    {
      first = pr.first;
      second = pr.second;
    }
    
    pair(const first_type &a, const second_type &b) {
      first = a;
      second = b;
    }

    pair& operator= (const pair& pr)
    {
      first = pr.first;
      second = pr.second;
      return *this;
    }
  };

  //Overloaded operators for the pair compaire
  template <class T1, class T2>
  bool operator== (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
  { return lhs.first==rhs.first && lhs.second==rhs.second; }

  template <class T1, class T2>
  bool operator!= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
  { return !(lhs==rhs); }

  template <class T1, class T2>
  bool operator<  (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
  { return lhs.first<rhs.first || (!(rhs.first<lhs.first) && lhs.second<rhs.second); }

  template <class T1, class T2>
  bool operator<= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
  { return !(rhs<lhs); }

  template <class T1, class T2>
  bool operator>  (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
  { return rhs<lhs; }

  template <class T1, class T2>
  bool operator>= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
  { return !(lhs<rhs); }

  template<class T1, class T2>
  ft::pair<T1, T2>
  make_pair(T1 lhs, T2 rhs)
  {
    return ft::pair<T1, T2>(lhs, rhs);
  }

  template <class T>
  class const_map_iterator;

  //Iterators for the pair
  //it's bidirectional, so i dont need to implement plus
  template <typename P>
  class map_iterator {
    friend class const_map_iterator<P>;
  protected:
    int dir;
    _mnode<P> *ptr;
  private:

    const map_iterator& successor()
    {
      _mnode<P> *temp;
      if (ptr->right != NULL) {
	temp = ptr->right;
	while (temp->left != NULL) {
	  temp = temp->left;
	}
	ptr = temp;
	return *this;
      }
      temp = ptr->parent;
      while (temp != NULL && ptr == temp->right) {
	ptr = temp;
	temp = temp->parent;
      }
      ptr = temp;
      return *this;
    }

    const map_iterator& predecessor()
    {
      _mnode<P> *temp;
      if (ptr->left != NULL) {
	temp = ptr->left;
	while (temp->right != NULL) {
	  temp = temp->right;
	}
	ptr = temp;
	return *this;
      }
      temp = ptr->parent;
      while (temp != NULL && ptr == temp->left) {
	ptr = temp;
	temp = temp->parent;
      }
      ptr = temp;
      return *this;
    }
  public:
    typedef P value_type;
    map_iterator()
    {
      ptr = NULL;
      dir = 0;
    }
    map_iterator(const map_iterator &t)
    {
      ptr = t.ptr;
      dir = 0;
    }

    map_iterator(const const_map_iterator<P> &t)
    {
      ptr = t.ptr;
      dir = 0;
    }
    map_iterator(_mnode<P> *p)
    {
      ptr = p;
      dir = 0;
    }
    ~map_iterator()
    {
    }

    _mnode<P>*
    get_node()
    {
      return ptr;
    }
    const map_iterator& operator=(const map_iterator &t)
    {
      ptr = t.ptr;
      dir = 0;
      return *this;
    }

    const map_iterator& operator=(const const_map_iterator<P> &t)
    {
      ptr = t.ptr;
      dir = 0;
      return *this;
    }
    
    const map_iterator& operator++()
    {
      if (dir == 0)
	return successor();
      return predecessor();
    }

    const map_iterator& operator++(int)
    {
      if (dir == 0)
	return successor();
      return predecessor();
    }

    const map_iterator& operator--()
    {
      if (dir == 1)
	return successor();
      return predecessor();
    }

    const map_iterator& operator--(int)
    {
      if (dir == 1)
	return successor();
      return predecessor();
    }

    bool operator==(const map_iterator &t)
    {
      return ptr == t.ptr;
    }

    bool operator!=(const map_iterator &t)
    {
      return ptr != t.ptr;
    }

    P& operator*()
    {
      return *(ptr->ptr);
    }
    
  };

  template <typename P>
  class const_map_iterator {
    friend class map_iterator<P>;
  protected:
    int dir;
    _mnode<P> *ptr;
  private:    
    const const_map_iterator& successor()
    {
      _mnode<P> *temp;
      if (ptr->right != NULL) {
	temp = ptr->right;
	while (temp->left != NULL) {
	  temp = temp->left;
	}
	ptr = temp;
	return *this;
      }
      temp = ptr->parent;
      while (temp != NULL && ptr == temp->right) {
	ptr = temp;
	temp = temp->parent;
      }
      ptr = temp;
      return *this;
    }

    const const_map_iterator& predecessor()
    {
      _mnode<P> *temp;
      if (ptr->left != NULL) {
	temp = ptr->left;
	while (temp->right != NULL) {
	  temp = temp->right;
	}
	ptr = temp;
	return *this;
      }
      temp = ptr->parent;
      while (temp != NULL && ptr == temp->left) {
	ptr = temp;
	temp = temp->parent;
      }
      ptr = temp;
      return *this;
    }
  public:
    typedef P value_type;
    const_map_iterator()
    {
      ptr = NULL;
      dir = 0;
    }
    const_map_iterator(const map_iterator<P> &t)
    {
      ptr = t.ptr;
      dir = 0;
    }
    const_map_iterator(const const_map_iterator &t)
    {
      ptr = t.ptr;
      dir = 0;
    }
    const_map_iterator(_mnode<P> *p)
    {
      ptr = p;
      dir = 0;
    }
    ~const_map_iterator()
    {
    }

    _mnode<P>*
    get_node()
    {
      return ptr;
    }
    const const_map_iterator& operator=(const map_iterator<P> &t)
    {
      ptr = t.ptr;
      dir = 0;
      return *this;
    }

    const const_map_iterator& operator=(const const_map_iterator &t)
    {
      ptr = t.ptr;
      dir = 0;
      return *this;
    }
    
    const const_map_iterator& operator++()
    {
      if (dir == 0)
	return successor();
      return predecessor();
    }

    const const_map_iterator& operator++(int)
    {
      if (dir == 0)
	return successor();
      return predecessor();
    }

    const const_map_iterator& operator--()
    {
      if (dir == 1)
	return successor();
      return predecessor();
    }

    const const_map_iterator& operator--(int)
    {
      if (dir == 1)
	return successor();
      return predecessor();
    }

    bool operator==(const const_map_iterator &t)
    {
      return ptr == t.ptr;
    }

    bool operator!=(const const_map_iterator &t)
    {
      return ptr != t.ptr;
    }

    const P& operator*()
    {
      return *(ptr->ptr);
    }
    
  };


  template <typename Key, typename T, typename Compare = ft::less<Key>, typename Alloc = std::allocator<ft::pair<Key, T> > >
  class map
  {
  public:

    //Typedefs for stuff
    typedef Key key_type;
    typedef Compare key_compare;
    typedef Alloc allocator_type;
    typedef T mapped_type;
    typedef ft::pair<key_type, mapped_type> value_type;    
    typedef typename Alloc::reference reference;
    typedef typename Alloc::const_reference const_reference;
    typedef typename Alloc::pointer pointer;
    typedef typename Alloc::const_pointer const_pointer;
    typedef map_iterator<value_type> iterator;
    typedef const_map_iterator<value_type> const_iterator;
    typedef _reverse_iterator<map_iterator<value_type> > reverse_iterator;
    typedef _reverse_iterator<const_map_iterator<value_type> > const_reverse_iterator;
    typedef std::ptrdiff_t difference_type;
    typedef std::size_t size_type;


  private:
    //insides
    _mnode<value_type> *ptr;
    size_type _size;
    allocator_type _allocator;    
    key_compare _comp;

  private:
    //Some methods for the rest
    void transplant(_mnode<value_type> *u, _mnode<value_type> *v)
    {
      if (u->parent == NULL)
	ptr = v;
      else if (u == u->parent->left)
	u->parent->left = v;
      else
	u->parent->right = v;
      if (v != NULL)
	v->parent = u->parent;
    }

    _mnode<value_type> *
    maximum(_mnode<value_type> *u)
    {
      _mnode<value_type> *temp = u;
      _mnode<value_type> *prev = u;
      while (temp) {
	prev = temp;
	temp = temp->right;	
      }
      return prev; 
    }

    _mnode<value_type> *
    minimum(_mnode<value_type> *u)
    {
      _mnode<value_type> *temp = u;
      _mnode<value_type> *prev = u;
      while (temp) {
	prev = temp;
	temp = temp->left;	
      }
      return prev; 
    }
  public:
    explicit map(const key_compare& c = key_compare(), const allocator_type &a = allocator_type())
    {
      _comp = c;
      _allocator = a;
      ptr = NULL;
      _size = 0;
    }

    template <class II>
    map(II first, II second, const key_compare &c = key_compare(),
	const allocator_type &a = allocator_type())
    {
      _comp = c;
      _allocator = a;
      ptr = NULL;
      _size = 0;
      while (first != second) {
	insert(*first);
	first++;
      }
    }

    map(class map& x)
    {
      _comp = x._comp;
      _allocator = x._allocator;
      ptr = NULL;
      _size = 0;
      iterator i;
      for (i = x.begin(); i != x.end(); i++) {
	insert(*i);
      }
    }       

    ~map()
    {
      clear();
    }

    const map& operator=(const map& x)
    {
      clear();
      iterator i;
      for (i = x.begin(); i != x.end(); i++) {
	insert(*i);	
      }
      return *this;
    }

    //capacity

    bool empty() const
    {
      return _size == 0;
    }

    size_type size() const
    {
      return _size;
    }

    size_type max_size() const
    {
      return _allocator.max_size();
    }


    //Element access
    mapped_type& operator[](const key_type &k)
    {
      key_type ins = k;
      iterator i = find(k);
      if (i == this->end()) {
	iterator ret = insert(make_pair(ins, mapped_type())).first;
	i = ret;
      }
      return const_cast<mapped_type&>((*i).second);
    }

    
    //insert

    ft::pair<iterator, bool>
    insert(const value_type &val)
    {
      //if the container is empty, then we allcating a node and
      //putting it in the ptr
      if (ptr == NULL) {
	pointer n = _allocator.allocate(1);
	_allocator.construct(n, val);
	_mnode<value_type> *temp;
	temp = new _mnode<value_type>(n);
	ptr = temp;
	_size = 1;
	iterator i(ptr);
	return pair<iterator, bool>(i, true);
      }
      _mnode<value_type> *x = ptr;
      _mnode<value_type> *y;	
      while (x != NULL) {
	y = x;
	if (val.first == y->ptr->first) {
	  iterator i(ptr);
	  return pair<iterator, bool>(y, false);
	}
	else if (_comp(val.first, x->ptr->first))
	  x = x->left;
	else
	  x = x->right;	  
      }
      pointer n = _allocator.allocate(1);
      _allocator.construct(n, val);
      _mnode<value_type> *z = new _mnode<value_type>(n);
      z->parent = y;
      if (_comp(z->ptr->first, y->ptr->first)) {
	y->left = z;
      }
      else
	y->right = z;
      _size++;
      iterator i(z);
      return pair<iterator, bool>(i, true);
    }

    iterator
    insert(const value_type &val, iterator i)
    {
      i = this->begin();
      return insert(val).first;
    }

    template <typename II>
    void insert(II first, II last)
    {
      while (first != last) {
	insert(*first);
	first++;
      }
    }    

    //iterators
    
    iterator begin()
    {
      if (ptr == NULL)
	return iterator(ptr);
      _mnode<value_type> *temp = ptr;
      _mnode<value_type> *prev = temp;
      while(temp) {
	prev = temp;
	temp = temp->left;      
      }
      return iterator(prev);
    }

    const_iterator begin() const
    {
      if (ptr == NULL)
	return const_iterator(ptr);
      _mnode<value_type> *temp = ptr;
      _mnode<value_type> *prev = temp;
      while(temp) {
	prev = temp;
	temp = temp->left;      
      }
      return const_iterator(prev);
    }

    iterator end()
    {
      return iterator(NULL);
    }

    const_iterator end() const
    {
      return const_iterator(NULL);
    }

    reverse_iterator rbegin()
    {
      if (ptr == NULL)
	return reverse_iterator(ptr);
      _mnode<value_type> *temp = ptr;
      _mnode<value_type> *prev = temp;
      while(temp) {
	prev = temp;
	temp = temp->right;
      }
      iterator i(prev);
      return reverse_iterator(i);
    }
    
    const_reverse_iterator rbegin() const
    {
      if (ptr == NULL)
	return const_reverse_iterator(ptr);
      _mnode<value_type> *temp = ptr;
      _mnode<value_type> *prev = temp;
      while(temp) {
	prev = temp;
	temp = temp->right;
      }
      const_iterator i(prev);
      return const_reverse_iterator(i);
    }

    reverse_iterator rend()
    {
      iterator i(NULL);
      return reverse_iterator(i);
    }

    const_reverse_iterator rend() const
    {
      const_iterator i(NULL);
      return const_reverse_iterator(i);
    }


    //erase
    void
    erase(iterator i)
    {
      _mnode<value_type> *temp = i.get_node();
      _mnode<value_type> *y;
      _allocator.deallocate(temp->ptr, 1);
      if (temp->left == NULL)
	transplant(temp, temp->right);
      else if (temp->right == NULL)
	transplant(temp, temp->left);
      else {
	y = minimum(temp->right);
	if (y->parent != temp) {
	  transplant(y, y->right);
	  y->right = temp->right;
	  y->right->parent = y;	  
	}
	transplant(temp, y);
	y->left = temp->left;
	y->left->parent = y;
      }
      delete temp;
      _size--;
    }

    size_type erase(const key_type&k)
    {
      size_type ret = 0;
      iterator i = this->begin();
      iterator next;
      while (i != this->end()) {
	if ((*i).first == k) {
	  ret++;
	  next = i;
	  i++;
	  erase(i);
	  i = next;
	}
	else
	  i++;
      }
      return ret;
    }

    void erase(iterator first, iterator last)
    {
      iterator next;
      while (first != last) {
	next = first;
	next++;
	erase(first);
	first = next;
      }
    }

    void swap(map& x)
    {
      _mnode<value_type> *t;
      t = x.ptr;
      x.ptr = ptr;
      ptr = t;
      size_type tt = x._size;
      x._size = _size;
      _size = tt;
    }

    void clear()
    {
      erase(this->begin(), this->end());      
    }

    //getters

    key_compare
    key_comp() const
    {
      return _comp;
    }

    allocator_type
    get_allocator() const
    {
      return _allocator;             
    }

    class value_compare
    {
      friend class map;
    protected:
      Compare comp;
      value_compare (Compare c): comp(c) {}
    public:
      typedef bool result_type;
      typedef value_type first_argument_type;
      typedef value_type second_argument_type;
      bool operator() (const value_type &x, const value_type &y)
      {
	return (comp(x.first, y.first));
      }
    };

    value_compare
    value_comp() const
    {
      return value_compare(_comp);
    }

    iterator find(const key_type &k)
    {
      iterator i;
      for (i = this->begin(); i != this->end(); i++) {
	if ((*i).first == k)
	  return i;
      }
      return i;
    }

    const_iterator find(const key_type &k) const
    {
      iterator i;
      for (i = this->begin(); i != this->end(); i++) {
	if ((*i).first == k)
	  return i;
      }
      return i;
    }

    size_type count(const key_type &k) const
    {
      iterator i;
      for (i = this->begin(); i != this->end(); i++) {
	if ((*i).first == k)
	  return 1;
      }
      return 0;
    }

    iterator lower_bound(const key_type &k)
    {
      iterator i;
      for (i = this->begin(); i != this->end(); i++) {
	if (!_comp((*i).first, k))
	  return i;
      }
      return i;
    }

    const_iterator lower_bound(const key_type &k) const
    {
      iterator i;
      for (i = this->begin(); i != this->end(); i++) {
	if (!_comp((*i).first, k))
	  return i;
      }
      return i;
    }

    iterator upper_bound(const key_type &k)
    {
      iterator i;
      for (i = this->begin(); i != this->end(); i++) {
	if (_comp((*i).first, k))
	  return i;
      }
      return i;
    }

    const_iterator upper_bound(const key_type &k) const
    {
      iterator i;
      for (i = this->begin(); i != this->end(); i++) {
	if (_comp((*i).first, k))
	  return i;
      }
      return i;
    }

    ft::pair<iterator, iterator>
    equal_range(const key_type &k)
    {
      iterator ret = find(k);
      if (ret != this->end()) {
	iterator next = ret;
	next++;
	return pair<iterator, iterator>(ret, next);
      }
      return pair<iterator, iterator>(this->begin(), this->begin());
    }

    ft::pair<const_iterator, const_iterator>
    equal_range(const key_type &k) const
    {
      iterator ret = find(k);
      if (ret != this->end()) {
	iterator next = ret;
	next++;
	return pair<iterator, iterator>(ret, next);
      }
      return pair<iterator, iterator>(this->begin(), this->begin());
    }
    
  };





  //end of the namespace
}

#endif

