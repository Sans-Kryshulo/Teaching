// Functors.h
#ifndef FUNCTORS_H
#define FUNCTORS_H

#include <algorithm>
#include <vector>
#include <limits>

// ������� ��� ������ ������������ ��������
struct MinValue {
    int operator()(const std::vector<int>& data) const {
        return *std::min_element(data.begin(), data.end());
    }
};

// ������� ��� ������ ������������� ��������
struct MaxValue {
    int operator()(const std::vector<int>& data) const {
        return *std::max_element(data.begin(), data.end());
    }
};

// ������� ��� ���������� �� ��������
struct SortDescending {
    void operator()(std::vector<int>& data) const {
        std::sort(data.begin(), data.end(), std::greater<int>());
    }
};

// ������� ��� ���������� �� �����������
struct SortAscending {
    void operator()(std::vector<int>& data) const {
        std::sort(data.begin(), data.end());
    }
};

// ������� ��� ���������� �������� �� �������� ���������
template <typename T>
struct IncreaseBy {
    T increment;
    IncreaseBy(T inc) : increment(inc) {}
    void operator()(std::vector<int>& data) const {
        std::for_each(data.begin(), data.end(), [this](int& val) { val += increment; });
    }
};

// ������� ��� ���������� �������� �� �������� ���������
template <typename T>
struct DecreaseBy {
    T decrement;
    DecreaseBy(T dec) : decrement(dec) {}
    void operator()(std::vector<int>& data) const {
        std::for_each(data.begin(), data.end(), [this](int& val) { val -= decrement; });
    }
};

// ������� ��� �������� ���������, ������ ��������� ��������
struct RemoveValue {
    int value;
    RemoveValue(int val) : value(val) {}
    void operator()(std::vector<int>& data) const {
        data.erase(std::remove(data.begin(), data.end(), value), data.end());
    }
};

#endif // FUNCTORS_H
