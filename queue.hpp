#ifndef FT_QUEUE_HPP
#define FT_QUEUE_HPP

#include "list.hpp"

namespace ft {

  template <class T, class Container = ft::list<T> >
  class queue
  {
  public:
    typedef T value_type;
    typedef Container container_type;
    typedef size_t size_type;

    container_type _c;

    explicit queue(const container_type& c = container_type())
    {
      _c = c;
    }

    bool empty() const
    {
      return _c.empty();
    }

    size_type size()
    {
      return _c.size();
    }

    value_type &front()
    {
      return _c.front();
    }

    const value_type& front() const
    {
      return _c.front();
    }

    value_type &back()
    {
      return _c.back();
    }

    const value_type& back() const
    {
      return _c.back();
    }

    void push(const value_type &val)
    {
      _c.push_back(val);
    }

    void pop()
    {
      _c.pop_front();
    }
  
  };

}

#endif
