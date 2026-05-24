#pragma once

#include <iostream>
#include <optional>


class Array_sequence
{
    private:
        int  _capacity;
        int  _size;
        int* _array;

        void resize();

        static const int min_cap = 2;
    public:
        Array_sequence(int cap = min_cap);
        ~Array_sequence();

        bool push_back(int value);
        bool push_front(int value);
        bool insert(int pos, int value);
        bool remove(int pos);
        std::optional<int> find(int pos) const;
        int size();
        void print() const;

        friend std::ostream& operator<<(std::ostream& os, const Array_sequence& array_seq);
};

