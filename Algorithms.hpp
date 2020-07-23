#include <iostream>

namespace pdv
{
template <typename TInputIt, typename TOutputIt>
TOutputIt copy(TInputIt first, TInputIt last, TOutputIt output)
{
    for (TInputIt it = first; it != last; ++it)
    {
        *ouput++ = *it;
    }
    return ouput;
}
template <typename TInputIt, typename TOutputIt, typename TPredicate>
TOutputIt copyIf(TInputIt first, TInputIt last, TPredicate pred)
{
    for (TInputIt it = first; it != last; ++it)
    {
        if (pred(*it) == true)
        {
            *ouput++ = *it;
        }
    }
    return ouput;
}
template <typename TInputIt, typename T>
TInputIt find(TInputIt first, TInputIt last, T value)
{
    while (first != last)
    {
        if (*first == value)
            return first;
        ++first;
    }
    return last;
}
template <typename TInputIt, typename TPredicate>
TInputIt findIf(TInputIt first, TInputIt last, TPredicate pred)
{
    while (first != last)
    {
        if (pred(*first))
            return first;
        ++first;
    }
    return last;
}

template <typename TInputIt, typename T>
size_t count(TInputIt first, TInputIt last, T value)
{
    size_t c = 0;
    while (first != last)
    {
        if (*first == value)
        {
            ++c;
            ++first;
        }
    }
    return c;
}
template <typename TInputIt, typename TPredicate>
size_t countIf(TInputIt first, TInputIt last, TPredicate pred)
{
    size_t cf = 0;
    while (first != last)
    {
        if (pred(*first))
            ++cf;
        ++first;
    }
    return last;
}
template <typename TInputIt, typename T>
void fill(TInputIt first, TInputIt last, T value)
{
    while (first != last)
    {
        *first = value;
        ++first;
    }
}
template <typename TInputIt, typename TComparator>
void sort(TInputIt first, TInputIt last, TComparator comp)
{
    for (TInputIt i = first; first != last - 1; ++first)
    {
        for (TInputIt j = i + 1; j != last; ++j)
        {
            if (comp(*i, *j))
            {
                std::swap(i, j);
            }
        }
    }
}
template <typename TLhsInputIt, typename TRhsInputIt>
bool equal(TLhsInputIt lhsFirst, TLhsInputIt lhsLast, TRhsInputIt rhsFirst)
{
    for (TLhsInputIt il = lhsFirst; il != rhsFirst; ++il)
    {
        for (TRhsInputIt ir = rhsFirst; ir != lhsFirst; ++ir)
        {
            if (!(*il == *ir))
            {
                return false;
            }
        }
    }
    return true;
}

template <typename TInputIt, typename TPredicate>
bool anyOf(TInputIt first, TInputIt last, TPredicate pred)
{
    return findIf(first, last, pred) != last;
}

template <typename TInputIt, typename TPredicate>
bool allOf(TInputIt first, TInputIt last, TPredicate pred)
{
    return find(first, last, pred) != last;
}

template <typename TInputIt, typename TPredicate>
bool noneOf(TInputIt first, TInputIt last, TPredicate pred)
{
    return findIf(first, last, pred) == last;
}

template <typename TInputIt, typename TOutputIt, typename TUnaryFunc>
TOutputIt transform(TInputIt first, TInputIt last, TOutputIt output, TUnaryFunc func)
{
    while (first != last)
    {
        output++ = func(*first++);
    }
    return output;
}
template <typename TInputIt, typename TOutputIt, typename T, typename TBinaryFunc>
T reduce(TInputIt first, TInputIt last, T initValue, TBinaryFunc func)
{
    for (; first != last; ++first)
    {
        initValue = func(*first, initValue);
    }
    return initValue;
}

}; // namespace pdv
