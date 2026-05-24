#include "../includes/array_sequence.h"


Array_sequence::Array_sequence(int cap) :
    _capacity(cap > 0 ? cap : min_cap),
    _size(0),
    _array(new int[cap]) {}

Array_sequence::~Array_sequence()
{
    delete[] _array;
}


void Array_sequence::resize()
{
    if (_size < _capacity) return;

    _capacity *= 2;

    int* new_array = new int[_capacity];

    for (int i = 0; i < _size; i++) new_array[i] = _array[i];

    delete[] _array;
    _array = new_array;
}

bool Array_sequence::push_back(int value)
{
    return insert(_size+1, value);
}

bool Array_sequence::push_front(int value)
{
    return insert(1, value);
}

bool Array_sequence::insert(int pos, int value) {
    if (pos < 1 || pos > _size + 1) return false;

    --pos;

    for (int i = _size++; i > pos; i--) {
        _array[i] = _array[i-1];
    }
    _array[pos] = value;

    resize();

    return true;
}

bool Array_sequence::remove(int pos)
{
    if (_size == 0 || pos > _size) return false;

    --pos;

    for (int i = pos; i < _size; i++) {
        _array[i] = _array[i+1];
    }
    
    _size--;

    return true;
}

std::optional<int> Array_sequence::find(int value) const
{
    for (int i = 0; i < _size; i++) {
        if (_array[i] == value) return i+1;
    }

    return std::nullopt;
}

int Array_sequence::size()
{
    return _size;
}

void Array_sequence::print() const
{
    std::cout << "Array Sequence:" << std::endl;
    std::cout << *this << std::endl;
}

std::ostream& operator<<(std::ostream& os, const Array_sequence& array_seq)
{
    os << "[";
    for (int i = 0; i < array_seq._size; i++) {
        os << array_seq._array[i] << (i+1 < array_seq._size ? ", ":"");
    }
    os << "]";

    return os;
}
