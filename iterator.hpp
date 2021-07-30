#ifndef FT_ITERATOR_HPP
#define FT_ITERATOR_HPP

namespace ft {
  template <typename I>
  class _reverse_iterator
  {
    I _it;

  public:
    _reverse_iterator()
    {
    }

    _reverse_iterator(const I &i)
    {
      _it = i;
    }

    _reverse_iterator(const _reverse_iterator &i)
    {
      _it = i._it;
    }

    _reverse_iterator& operator=(const _reverse_iterator &l)
    {
      _it = l._it;
      return *this;
    }
    
    _reverse_iterator& operator=(const I &l)
    {
      _it = l;
      return *this;
    }

    ~_reverse_iterator()
    {
    }

    bool operator==(const _reverse_iterator &i)
    {
      return _it == i._it;
    }

    bool operator!=(const _reverse_iterator &i)
    {
      return _it != i._it;
    }
    
    typename I::value_type operator*()
    {
      return (*_it);
    }

    const _reverse_iterator& operator++()
    {
      _it--;
      return *this;
    }

    const _reverse_iterator& operator++(int)
    {
      _it--;
      return *this;
    }

    const _reverse_iterator& operator--()
    {
      _it++;
      return *this;
    }

    const _reverse_iterator& operator--(int)
    {
      _it++;
      return *this;
    }
    
  };
}

#endif
