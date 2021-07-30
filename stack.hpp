#ifndef FT_STACK_HPP
#define FT_STACK_HPP

#include "list.hpp"
namespace ft {
  template <class T, class Container = ft::list<T> >
  class stack
  {
  public:
    typedef T value_type;
    typedef Container container_type;
    typedef size_t size_type;

    container_type _c;

    explicit stack(const Container& c = Container())
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

    value_type& top()
    {
      return _c.back();
    }

    const value_type& top() const
    {
      return _c.back();
    }

    void push(const value_type &val)
    {
      _c.push_back(val);
    }

    void pop()
    {
      _c.pop_back();
    }
  
  };
}

#endif
