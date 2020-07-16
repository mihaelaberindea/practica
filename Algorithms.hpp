#ifndef ALGORITHMS.HPP
#define ALGORITHMS.HPP
#include <cstddef>
template <typename TInputIt,typename TOutputIt, typename T,typename TPredicate, typename TComparator,typename TLhsInputIt,typename TRhsInputIt, typename TUnaryFunc, typename TBinaryFunc>
class Algorithms
{
  public:
  TOutputIt copy(TInputIt first, TInputIt last,TOutputIt output)
  {
      for(TInputIt it=first; it !=last; ++it)
      {
          *ouput++=*it;
      }
      return ouput;
  }
  TOutputIt copyIf(TInputIt first, TInputIt last,TPredicate pred)
  {
      for(TInputIt it=first; it !=last; ++it)
      {
          if(pred(*it)==true)
          {  *ouput++=*it;}
      }
      return ouput;
  }

  TInputIt find(TInputIt first, TInputIt last, T value)
  {
    while (first!=last)
     {
      if (*first==value) 
      return first;
       ++first;
    }
    return last;
  }

  TInputIt findIf(TInputIt first, TInputIt last, TPredicate pred)
  {
    while (first!=last) {
    if (pred(*first)) 
    return first;
    ++first;
    }
    return last;
  }


  size_t count(TInputIt first, TInputIt last, T value)
  {   size_t c=0;
      while (first!=last)
      {
          if(*first==value)
          return ++c;
          ++first;
      }
      return c;
  }
  size_t countIf(TInputIt first, TInputIt last, TPredicate pred)
  {   size_t cf=0;
      while(first!=last)
     {
         if(pred(*first))
         ++cf;
        ++first;
     } 
     return last;

  }

  void fill(TInputIt first, TInputIt last, T value)
  {
    while (first != last)
     {  *first = value;
        ++first;
     }
  }
  void sort(TInputIt first, TInputIt last, TComparator comp)
  {
      while(first!=last)
      {
          comp(first, last);
          ++first;
      }
      return comp;
  }

  bool equal(TLhsInputIt lhsFirst,TLhsInputIt lhsLast,TRhsInputIt rhsFirst)
  {
    for(TLhsInputIt il=lhsFirst; il!=rhsFirst; ++il)
    {
        for(TRhsInputIt ir=rhsFirst; ir!=lhsFirst; ++ir)
        {
            if(!(*il==*ir))
            {return false;}
        }
    }
      return true;
  }
  bool anyOf(TInputIt first, TInputIt last, TPredicate pred)
  {
      return findIf(first, last, pred)!=last;
  }
  bool allOf(TInputIt first, TInputIt last, TPredicate pred)
  {
      return find(first, last, pred)!=last;
  }
  bool noneOf(TInputIt first, TInputIt last, TPredicate pred)
  {
      return findIf(first, last, pred) == last;
  }

  TOutputIt transform(TInputIt first, TInputIt last,TOutputIt output, TUnaryFunc func)
  {
      while( first !=last)
      {
          output++=func(*first++);
      }
      return output ;
  }
  T reduce(TInputIt first, TInputIt last, T initValue, TBinaryFunc func)
  {

  }

};
#endif