#pragma once

#include <iostream>
#include <optional>

#include "node.h"


class Sequence
{
    private:
        Node* index;
        int size;

    public:
        Sequence();
        ~Sequence();

        bool insert(int pos, int elem);
        bool remove(int pos);
        std::optional<int> get(int pos) const;
        void print() const;

        friend std::ostream& operator<<(std::ostream& os, const Sequence& seq);
};

