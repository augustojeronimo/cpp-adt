#include "../includes/autotest.h"
#include "../includes/array_sequence.h"


namespace color
{
    void red()   { std::cout    << "\033[91m"; }
    void green() { std::cout    << "\033[92m"; }
    void yelow() { std::cout    << "\033[93m"; }
    void blue()  { std::cout    << "\033[94m"; }
    void cyan()  { std::cout    << "\033[96m"; }
    
    void black() { std::cout    << "\033[90m"; }
    void white() { std::cout    << "\033[97m"; }

    void reset() { std::cout    << "\033[0m"; }
}

namespace
{
    void print(Array_sequence& as)
    {
        std::cout << "current state of the array sequence:" << std::endl;
        std::cout << as << std::endl;
        std::cout << std::endl;
    }

    void push_back(Array_sequence& as, int value)
    {
        std::cout << "[attempt to push back value " << value << "]" << std::endl;
        bool success = as.push_back(value);

        if (success) {
            color::green();
            std::cout << "[value " << value << " pushed back]" << std::endl;
        }
        else {
            color::red();
            std::cout << "[failed to push back value " << value << "]" << std::endl;
        }
        color::reset();
        std::cout << std::endl;

        print(as);
    }

    void push_front(Array_sequence& as, int value)
    {
        std::cout << "[attempt to push front value " << value << "]" << std::endl;
        bool success = as.push_front(value);

        if (success) {
            color::green();
            std::cout << "[value " << value << " pushed front]" << std::endl;
        }
        else {
            color::red();
            std::cout << "[failed to push front value " << value << "]" << std::endl;
        }
        color::reset();
        std::cout << std::endl;

        print(as);
    }

    void insert(Array_sequence& as, int pos, int elem)
    {
        std::cout << "[attempt to insert the value " << elem << " at position " << pos << "]" << std::endl;
        bool success = as.insert(pos, elem);

        if (success) {
            color::green();
            std::cout << "[value " << elem << " inserted at position " << pos << "]" << std::endl;
        }
        else {
            color::red();
            std::cout << "[failed to insert value " << elem << " at position " << pos << "]" << std::endl;
        }
        color::reset();
        std::cout << std::endl;

        print(as);
    }

    void remove(Array_sequence& as, int pos)
    {
        std::cout << "[attempt to remove the element at position " << pos << "]" << std::endl;
        bool success = as.remove(pos);

        if (success) {
            color::green();
            std::cout << "[element removed from position " << pos << "]" << std::endl;
        }
        else {
            color::red();
            std::cout << "[failed to remove element from position " << pos << "]" << std::endl;
        }
        color::reset();
        std::cout << std::endl;

        print(as);
    }

    void find(Array_sequence& as, int value)
    {
        std::cout << "[attempt to find value " << value << "]" << std::endl;
        auto position = as.find(value);

        if (position) {
            color::green();
            std::cout << "[value " << value << " found at position " << *position << "]" << std::endl;
        }
        else {
            color::red();
            std::cout << "[value " << value << " not found]" << std::endl;
        }
        color::reset();
        std::cout << std::endl;
    }
}


void start_test()
{
    // The values ​​below are exclusive to the automation algorithm
    // They only simulate the input
    const int size_insert = 5;
    int values_to_insert[size_insert][2] = {
        {1, 10},
        {2, 30},
        {2, 20},
        {3, 40},
        {6, 100},
    };
    
    const int size_remove = 4;
    int positions_to_remove[size_remove] = {
        4, 2,1, 3
    };

    const int size_push_back = 3;
    int values_to_push_back[size_push_back] = {
        50, 60, 70
    };

    const int size_push_front = 3;
    int values_to_push_front[size_push_front] = {
        30, 20, 10
    };

    const int size_find = 3;
    int positions_to_find[size_find] = {
        10, 100,70
    };


    // Start of tests

    Array_sequence array_seq;
    
    color::blue();
    std::cout << "-------------------------------------------------------------------------------------------" << std::endl;
    std::cout << " This is an automated test of the implementation of the abstract data type: array sequence " << std::endl;
    std::cout << "-------------------------------------------------------------------------------------------" << std::endl;
    std::cout << std::endl;

    color::yelow();
    std::cout << "-----------------------" << std::endl;
    std::cout << " Initiating insertions " << std::endl;
    std::cout << "-----------------------" << std::endl;
    std::cout << std::endl;
    color::reset();

    print(array_seq);

    for (int i = 0; i < size_insert; i++) insert(array_seq, values_to_insert[i][0], values_to_insert[i][1]);

    color::yelow();
    std::cout << "---------------------" << std::endl;
    std::cout << " Initiating removals " << std::endl;
    std::cout << "---------------------" << std::endl;
    std::cout << std::endl;
    color::reset();

    print(array_seq);

    for (int i = 0; i < size_remove; i++) remove(array_seq, positions_to_remove[i]);
    
    color::yelow();
    std::cout << "-----------------------" << std::endl;
    std::cout << " Initiating push backs " << std::endl;
    std::cout << "-----------------------" << std::endl;
    std::cout << std::endl;
    color::reset();

    print(array_seq);

    for (int i = 0; i < size_push_back; i++) push_back(array_seq, values_to_push_back[i]);

    color::yelow();
    std::cout << "------------------------" << std::endl;
    std::cout << " Initiating push fronts " << std::endl;
    std::cout << "------------------------" << std::endl;
    std::cout << std::endl;
    color::reset();

    print(array_seq);

    for (int i = 0; i < size_push_front; i++) push_front(array_seq, values_to_push_front[i]);

    color::yelow();
    std::cout << "-----------------" << std::endl;
    std::cout << " Initiating gets " << std::endl;
    std::cout << "-----------------" << std::endl;
    std::cout << std::endl;
    color::reset();

    print(array_seq);

    for (int i = 0; i < size_find; i++) find(array_seq, positions_to_find[i]);

    color::blue();
    std::cout << "------------------------" << std::endl;
    std::cout << " End of test automation " << std::endl;
    std::cout << "------------------------" << std::endl;
    color::reset();
}
