// FunctorsBetter.h
#ifndef FUNCTORS_BETTER_H
#define FUNCTORS_BETTER_H

#include <algorithm>
#include <limits>

// Функтор для поиска минимального значения
template <typename T>
struct MinValueBetter {
    typename T::value_type operator()(const T& data) const {
        auto minElement = std::min_element(data.begin(), data.end());
        return *minElement;
    }
};

// Функтор для поиска максимального значения
template <typename T>
struct MaxValueBetter {
    typename T::value_type operator()(const T& data) const {
        return *std::max_element(data.begin(), data.end());
    }
};

// Функтор для сортировки по убыванию
template <typename T>
struct SortDescendingBetter {
    void operator()(T& data) const {
        std::sort(data.begin(), data.end(), std::greater<typename T::value_type>());
    }
};

// Функтор для сортировки по возрастанию
template <typename T>
struct SortAscendingBetter {
    void operator()(T& data) const {
        std::sort(data.begin(), data.end());
    }
};

// Функтор для увеличения значений на заданную константу
template <typename T, typename U>
struct IncreaseByBetter {
    U increment;
    IncreaseByBetter(U inc) : increment(inc) {}
    void operator()(T& data) const {
        std::for_each(data.begin(), data.end(), [this](typename T::value_type& val) { val += increment; });
    }
};

// Функтор для уменьшения значений на заданную константу
template <typename T, typename U>
struct DecreaseByBetter {
    U decrement;
    DecreaseByBetter(U dec) : decrement(dec) {}
    void operator()(T& data) const {
        std::for_each(data.begin(), data.end(), [this](typename T::value_type& val) { val -= decrement; });
    }
};

// Функтор для удаления элементов, равных заданному значению
template <typename T>
struct RemoveValueBetter {
    typename T::value_type value;
    RemoveValueBetter(typename T::value_type val) : value(val) {}
    void operator()(T& data) const {
        data.erase(std::remove(data.begin(), data.end(), value), data.end());
    }
};

#endif // FUNCTORS_BETTER_H
