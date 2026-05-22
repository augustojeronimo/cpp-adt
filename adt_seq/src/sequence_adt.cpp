#include "../includes/sequence_adt.h"


Sequence_ADT::Sequence_ADT() : index(nullptr), size(0) {}

Sequence_ADT::~Sequence_ADT()
{
    Node* current = index;

    while (current != nullptr) {
        Node* next = current->next;
        delete current;
        current = next;
    }

    index = nullptr;
    size = 0;
}


bool Sequence_ADT::insert(int pos, int elem)
{
    if (pos < 1 || pos > (size + 1)) return false;

    if (pos == 1) {
        index = new Node{elem, index};
    }
    else {
        Node* current = index;
        for (int i = 1; i < pos -1; i++) current = current->next;

        current->next = new Node{elem, current->next};
    }

    size++;

    return true;
}

bool Sequence_ADT::remove(int pos)
{
    if (pos < 1 || pos > size) return false;

    Node* target;

    if (pos == 1) {
        target = index;
        index = index->next;
    }
    else {
        Node* before = index;
        for (int i = 1; i < (pos - 1); i++) before = before->next;
        
        target = before->next;
        before->next = target->next;
    }

    delete target;
    size--;

    return true;
}

std::optional<int> Sequence_ADT::get(int pos)
{
    if (pos < 1 || pos > size) return std::nullopt;

    Node* current = index;
    for (int i = 1; i < pos; i++) current = current->next;

    return current->value;
}

void Sequence_ADT::print()
{
    std::cout << "Sequence:" << std::endl;
    std::cout << *this << std::endl;
}

std::ostream& operator<<(std::ostream& os, Sequence_ADT& seq)
{
    os << "[";
    if (seq.size > 0) {
        Node* current = seq.index;

        for (int i = 1; i <= seq.size; i++) {
            os << current->value << (i < seq.size? ", ":"");
            current = current->next;
        }
    }
    os << "]";

    return os;
}
