#include <algorithm>
#include <iostream>
#include <sstream>
#include <vector>
#include <boost/lexical_cast.hpp>

struct Costs {
    int d;
    int i;
    int m;
    int n;
};

void read_numeric_line(std::vector<int> &elements) {
    std::string line;
    std::getline(std::cin, line);

    std::istringstream iss(line);
    std::string element;
    while (std::getline(iss, element, ' '))
        elements.push_back(boost::lexical_cast<int>(element));
}

void read_costs(Costs& costs)
{
    std::vector<int> costs_vector;
    read_numeric_line(costs_vector);
    costs.d = costs_vector[0];
    costs.i = costs_vector[1];
    costs.m = costs_vector[2];
    costs.n = costs_vector[3];
}

void read_case(Costs& costs, std::vector<int>& array)
{
    read_costs(costs);
    read_numeric_line(array);
}

int calculate_cost(const Costs& costs, const std::vector<int>& array)
{
/*
    Look at three elements in turn, then calculate the cost of smoothing them
    out by deleting, inserting and modifying. Return the lowest cost.

    array = 1 7 5

    delete: (1)
        7 5

    insert: (2)
        1 3 5 7 5

    modify: (1)
        1 3 5
*/
}

int main()
{
    std::string line;
    std::getline(std::cin, line);
    int num_cases = boost::lexical_cast<int, std::string>(line);
    for (int i = 0; i < num_cases; i++) {
        Costs costs;
        std::vector<int> array;
        read_case(costs, array);
        std::cout << "Case #" << i + 1 << ": " <<
            calculate_cost(costs, array) << std::endl;
    }
}
