#include "../includes/autotest.h"
#include "../includes/set.h"


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
    void print(Set& set)
    {
        std::cout << "current state of the set:" << std::endl;
        std::cout << set << std::endl;
        std::cout << std::endl;
    }

    void add(Set& set, int elem)
    {
        std::cout << "[attempt to insert the value " << elem << "]" << std::endl;
        bool success = set.add(elem);

        if (success) {
            color::green();
            std::cout << "[value " << elem << " inserted]" << std::endl;
        }
        else {
            color::red();
            std::cout << "[failed to insert value " << elem << "]" << std::endl;
        }
        color::reset();
        std::cout << std::endl;

        print(set);
    }

    void remove(Set& set, int elem)
    {
        std::cout << "[attempt to remove the value " << elem << "]" << std::endl;
        bool success = set.remove(elem);

        if (success) {
            color::green();
            std::cout << "[value " << elem << " removed]" << std::endl;
        }
        else {
            color::red();
            std::cout << "[failed to remove value " << elem << "]" << std::endl;
        }
        color::reset();
        std::cout << std::endl;

        print(set);
    }

    void contains(Set& set, int elem)
    {
        std::cout << "[checking if the value " << elem << " exists in the set]" << std::endl;
        auto contains = set.contains(elem);

        if (contains) {
            color::green();
            std::cout << "[the value " << elem << " exists in the set]" << std::endl;
        }
        else {
            color::red();
            std::cout << "[the value " << elem << " does not exist in the set]" << std::endl;
        }
        color::reset();
        std::cout << std::endl;
    }
}


void start_test()
{
    // The values ​​below are exclusive to the automation algorithm
    // They only simulate the input
    const int size_add = 10;
    int values_to_add[size_add] = {
        11,
        22,
        33,
        44,
        55,
        44,
        66,
        11,
        88,
        77,
    };

    const int size_remove = 3;
    int values_to_remove[size_remove] = {
        88, 55, 99
    };

    const int size_contain = 3;
    int values_to_check[size_contain] = {
        22, 55, 44
    };


    // Start of tests

    Set set;
    
    color::blue();
    std::cout << "--------------------------------------------------------------------------------" << std::endl;
    std::cout << " This is an automated test of the implementation of the abstract data type: set " << std::endl;
    std::cout << "--------------------------------------------------------------------------------" << std::endl;
    std::cout << std::endl;

    color::yelow();
    std::cout << "-----------------------" << std::endl;
    std::cout << " Initiating insertions " << std::endl;
    std::cout << "-----------------------" << std::endl;
    std::cout << std::endl;
    color::reset();

    print(set);

    for (int i = 0; i < size_add; i++) add(set, values_to_add[i]);

    color::yelow();
    std::cout << "---------------------" << std::endl;
    std::cout << " Initiating removals " << std::endl;
    std::cout << "---------------------" << std::endl;
    std::cout << std::endl;
    color::reset();

    print(set);

    for (int i = 0; i < size_remove; i++) remove(set, values_to_remove[i]);
    
    color::yelow();
    std::cout << "---------------------" << std::endl;
    std::cout << " Initiating contains " << std::endl;
    std::cout << "---------------------" << std::endl;
    std::cout << std::endl;
    color::reset();

    print(set);

    for (int i = 0; i < size_contain; i++) contains(set, values_to_check[i]);

    color::yelow();
    std::cout << "-----------------------------------" << std::endl;
    std::cout << " Initiating union and intersection " << std::endl;
    std::cout << "-----------------------------------" << std::endl;
    std::cout << std::endl;
    color::reset();

    Set A {11, 22, 33, 44};
    Set B {33, 44, 55 ,66, 88};
    Set C {11, 55, 88, 44};

    std::cout << "Sets:" << std::endl;
    std::cout << "A = " << A << std::endl;
    std::cout << "B = " << B << std::endl;
    std::cout << "C = " << C << std::endl;
    std::cout << std::endl;

    std::cout << "Union:" << std::endl;
    std::cout << "A|B = " << (A|B) << std::endl;
    std::cout << "A|C = " << (A|C) << std::endl;
    std::cout << "B|C = " << (B|C) << std::endl;
    std::cout << std::endl;

    std::cout << "Intersection:" << std::endl;
    std::cout << "A&B = " << (A&B) << std::endl;
    std::cout << "A&C = " << (A&C) << std::endl;
    std::cout << "B&C = " << (B&C) << std::endl;
    std::cout << std::endl;

    color::blue();
    std::cout << "------------------------" << std::endl;
    std::cout << " End of test automation " << std::endl;
    std::cout << "------------------------" << std::endl;
    color::reset();
}
