// FunctorsBetter.h
#ifndef FUNCTORS_BETTER_H
#define FUNCTORS_BETTER_H

#include <algorithm>
#include <limits>

// ������� ��� ������ ������������ ��������
template <typename T>
struct MinValueBetter {
    typename T::value_type operator()(const T& data) const {
        auto minElement = std::min_element(data.begin(), data.end());
        return *minElement;
    }
};

// ������� ��� ������ ������������� ��������
template <typename T>
struct MaxValueBetter {
    typename T::value_type operator()(const T& data) const {
        return *std::max_element(data.begin(), data.end());
    }
};

// ������� ��� ���������� �� ��������
template <typename T>
struct SortDescendingBetter {
    void operator()(T& data) const {
        std::sort(data.begin(), data.end(), std::greater<typename T::value_type>());
    }
};

// ������� ��� ���������� �� �����������
template <typename T>
struct SortAscendingBetter {
    void operator()(T& data) const {
        std::sort(data.begin(), data.end());
    }
};

// ������� ��� ���������� �������� �� �������� ���������
template <typename T, typename U>
struct IncreaseByBetter {
    U increment;
    IncreaseByBetter(U inc) : increment(inc) {}
    void operator()(T& data) const {
        std::for_each(data.begin(), data.end(), [this](typename T::value_type& val) { val += increment; });
    }
};

// ������� ��� ���������� �������� �� �������� ���������
template <typename T, typename U>
struct DecreaseByBetter {
    U decrement;
    DecreaseByBetter(U dec) : decrement(dec) {}
    void operator()(T& data) const {
        std::for_each(data.begin(), data.end(), [this](typename T::value_type& val) { val -= decrement; });
    }
};

// ������� ��� �������� ���������, ������ ��������� ��������
template <typename T>
struct RemoveValueBetter {
    typename T::value_type value;
    RemoveValueBetter(typename T::value_type val) : value(val) {}
    void operator()(T& data) const {
        data.erase(std::remove(data.begin(), data.end(), value), data.end());
    }
};

#endif // FUNCTORS_BETTER_H
