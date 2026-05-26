#include "../includes/set.h"


Set::Set() : index(nullptr), size(0) {}

Set::Set(std::initializer_list<int> elements) : index(nullptr), size(0)
{
    for (int elem : elements) {
        add(elem);
    }
}

Set::Set(const Set& other) : index(nullptr), size(0)
{
    Node* current;
    for (current = other.index; current != nullptr; current = current->next) {
        this->add(current->value);
    }
}

Set::~Set()
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


Set Set::Union(const Set& A, const Set& B)
{
    Set C(A);

    Node* current;
    for (current = B.index; current != nullptr; current = current->next) {
        C.add(current->value);
    }

    return C;
}

Set Set::Intersection(const Set& A, const Set& B)
{
    Set C;

    Node* current;
    for (current = A.index; current != nullptr; current = current->next) {
        if (B.contains(current->value)) C.add(current->value);
    }

    return C;
}

bool Set::add(int elem)
{
    if (size == 0) {
        index = new Node{elem, nullptr};
        size++;
        return true;
    }

    Node* current = index;

    while (current != nullptr) {
        if (current->value == elem) return false;

        if (current->next == nullptr) break;

        current = current->next;
    }
    
    current->next = new Node{elem, nullptr};
    
    size++;
    return true;
}

bool Set::remove(int elem)
{
    if (size == 0) return false;
    
    if (index->value == elem) {
        Node* target = index;

        index = index->next;

        delete target;
        size--;

        return true;
    }

    for (Node* before = index; before->next != nullptr; before = before->next) {

        if (before->next->value == elem) {
            Node* target = before->next;

            before->next = target->next;

            delete target;
            size--;

            return true;
        }
    }

    return false;
}

bool Set::contains(int elem) const
{
    for (Node* current = index; current != nullptr; current = current->next) {
        if (current->value == elem) return true;
    }

    return false;
}

void Set::print() const
{
    std::cout << "Set:" << std::endl;
    std::cout << *this << std::endl;
}

Set Set::operator|(const Set& other)
{
    return Set::Union(*this, other);
}

Set Set::operator&(const Set& other)
{
    return Set::Intersection(*this, other);
}

Set& Set::operator=(const Set& other)
{
    if (this == &other) return *this;

    Set temp(other);

    std::swap(index, temp.index);
    std::swap(size, temp.size);

    return *this;
}

std::ostream& operator<<(std::ostream& os, const Set& seq)
{
    os << "{";
    if (seq.size > 0) {
        Node* current = seq.index;

        for (int i = 1; i <= seq.size; i++) {
            os << current->value << (i < seq.size? ", ":"");
            current = current->next;
        }
    }
    os << "}";

    return os;
}
