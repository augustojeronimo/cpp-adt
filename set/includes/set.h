#pragma once

#include <iostream>
#include <initializer_list>

#include "node.h"


class Set
{
    private:
        Node* index;
        int size;

    public:
        Set();
        Set(std::initializer_list<int> elements);
        Set(const Set& other);
        ~Set();

        bool add(int elem);
        bool remove(int elem);
        bool contains(int elem) const;
        void print() const;

        static Set Union(const Set& A, const Set& B);
        static Set Intersection(const Set& A, const Set& B);

        Set operator&(const Set& other);
        Set operator|(const Set& other);
        Set& operator=(const Set& other);

        friend std::ostream& operator<<(std::ostream& os, const Set& set);
};

