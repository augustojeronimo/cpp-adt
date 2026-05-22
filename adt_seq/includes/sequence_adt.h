#pragma once

#include <iostream>
#include <optional>

#include "node.h"


class Sequence_ADT
{
    private:
        Node* index;
        int size;

    public:
        Sequence_ADT();
        ~Sequence_ADT();

        bool insert(int pos, int elem);
        bool remove(int pos);
        std::optional<int> get(int pos);
        void print();

        friend std::ostream& operator<<(std::ostream& os, Sequence_ADT& seq);
};

