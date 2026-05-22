#include "../includes/autotest.h"
#include "../includes/sequence_adt.h"


namespace
{
    void print(Sequence_ADT& seq)
    {
        std::cout << "current state of the sequence:" << std::endl;
        std::cout << seq << std::endl;
        std::cout << std::endl;
    }

    void insert(Sequence_ADT& seq, int pos, int elem)
    {
        std::cout << "[attempt to insert the value " << elem << " at position " << pos << "]" << std::endl;
        bool success = seq.insert(pos, elem);

        if (success) std::cout << "[value " << elem << " inserted at position " << pos << "]" << std::endl;
        else std::cout << "[failed to insert value " << elem << " at position " << pos << "]" << std::endl;
        std::cout << std::endl;

        print(seq);
    }

    void remove(Sequence_ADT& seq, int pos)
    {
        std::cout << "[attempt to remove the element at position " << pos << "]" << std::endl;
        bool success = seq.remove(pos);

        if (success) std::cout << "[element removed from position " << pos << "]" << std::endl;
        else std::cout << "[failed to remove element from position " << pos << "]" << std::endl;
        std::cout << std::endl;

        print(seq);
    }

    void get(Sequence_ADT& seq, int pos)
    {
        std::cout << "[attempt to get value at position " << pos << "]" << std::endl;
        auto value = seq.get(pos);

        if (value) std::cout << "[value at position " << pos << " is " << *value << "]" << std::endl;
        else std::cout << "[failure to get the value at position " << pos << "]" << std::endl;
        std::cout << std::endl;
    }
}

namespace color
{
    void red() { std::cout      << "\033[91m"; }
    void green() { std::cout    << "\033[92m"; }
    void yelow() { std::cout    << "\033[93m"; }
    void blue() { std::cout     << "\033[94m"; }
    void cyan() { std::cout     << "\033[96m"; }
    
    void black() { std::cout    << "\033[90m"; }
    void white() { std::cout    << "\033[97m"; }

    void reset() { std::cout    << "\033[0m"; }
}

void start_test()
{
    // The values ​​below are exclusive to the automation algorithm
    // They only simulate the input
    const int size_insert = 10;
    int insert_values[10][2] = {
        {1, 10},
        {2, 20},
        {3, 30},
        {3, 40},
        {5, 50},
        {4, 60},
        {2, 70},
        {1, 80},
        {5, 90},
        {9, 100}
    };

    const int size_remove = 4;
    int remove_positions[4] = {
        1, 4,5, 10
    };

    const int size_get = 4;
    int get_positions[size_get] = {
        2, 3,5, 11
    };


    Sequence_ADT sequence;
    
    color::blue();
    std::cout << "-------------------------------------------------------------------------------------" << std::endl;
    std::cout << " This is an automated test of the implementation of the abstract data type: sequence " << std::endl;
    std::cout << "-------------------------------------------------------------------------------------" << std::endl;
    std::cout << std::endl;

    color::cyan();
    std::cout << "-----------------------" << std::endl;
    std::cout << " Initiating insertions " << std::endl;
    std::cout << "-----------------------" << std::endl;
    std::cout << std::endl;
    color::reset();

    print(sequence);

    for (int i = 0; i < size_insert; i++) insert(sequence, insert_values[i][0], insert_values[i][1]);

    color::red();
    std::cout << "---------------------" << std::endl;
    std::cout << " Initiating removals " << std::endl;
    std::cout << "---------------------" << std::endl;
    std::cout << std::endl;
    color::reset();

    print(sequence);

    for (int i = 0; i < size_remove; i++) remove(sequence, remove_positions[i]);
    
    color::yelow();
    std::cout << "-----------------" << std::endl;
    std::cout << " Initiating gets " << std::endl;
    std::cout << "-----------------" << std::endl;
    std::cout << std::endl;
    color::reset();

    print(sequence);

    for (int i = 0; i < size_get; i++) get(sequence, get_positions[i]);

    color::blue();
    std::cout << "------------------------" << std::endl;
    std::cout << " End of test automation " << std::endl;
    std::cout << "------------------------" << std::endl;
    color::reset();
}
