// Functors.h
#ifndef FUNCTORS_H
#define FUNCTORS_H

#include <algorithm>
#include <vector>
#include <limits>

// Функтор для поиска минимального значения
struct MinValue {
    int operator()(const std::vector<int>& data) const {
        return *std::min_element(data.begin(), data.end());
    }
};

// Функтор для поиска максимального значения
struct MaxValue {
    int operator()(const std::vector<int>& data) const {
        return *std::max_element(data.begin(), data.end());
    }
};

// Функтор для сортировки по убыванию
struct SortDescending {
    void operator()(std::vector<int>& data) const {
        std::sort(data.begin(), data.end(), std::greater<int>());
    }
};

// Функтор для сортировки по возрастанию
struct SortAscending {
    void operator()(std::vector<int>& data) const {
        std::sort(data.begin(), data.end());
    }
};

// Функтор для увеличения значений на заданную константу
template <typename T>
struct IncreaseBy {
    T increment;
    IncreaseBy(T inc) : increment(inc) {}
    void operator()(std::vector<int>& data) const {
        std::for_each(data.begin(), data.end(), [this](int& val) { val += increment; });
    }
};

// Функтор для уменьшения значений на заданную константу
template <typename T>
struct DecreaseBy {
    T decrement;
    DecreaseBy(T dec) : decrement(dec) {}
    void operator()(std::vector<int>& data) const {
        std::for_each(data.begin(), data.end(), [this](int& val) { val -= decrement; });
    }
};

// Функтор для удаления элементов, равных заданному значению
struct RemoveValue {
    int value;
    RemoveValue(int val) : value(val) {}
    void operator()(std::vector<int>& data) const {
        data.erase(std::remove(data.begin(), data.end(), value), data.end());
    }
};

#endif // FUNCTORS_H
