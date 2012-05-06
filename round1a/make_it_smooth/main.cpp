#include <algorithm>
#include <cmath>
#include <iostream>
#include <sstream>
#include <vector>
#include <boost/lexical_cast.hpp>

void read_numeric_line(std::vector<int> &elements) {
    std::string line;
    std::getline(std::cin, line);

    std::istringstream iss(line);
    std::string element;
    while (std::getline(iss, element, ' '))
        elements.push_back(boost::lexical_cast<int>(element));
}

void read_case(std::vector<int>& settings, std::vector<int>& pixels)
{
    read_numeric_line(settings);
    read_numeric_line(pixels);
}

int solve(std::vector<int>::const_iterator first,
          std::vector<int>::const_iterator last, int final_value,
          int d, int i, int m)
{
    if (first == last)
        return 0;

    int best = solve(first, last - 1, final_value, d, i, m) + d;
    for (int prev_value = 0; prev_value < 255; prev_value++) {
        int prev_cost = solve(first, last - 1, prev_value, d, i, m);
        int move_cost = abs(final_value - *last);
        int num_inserts = (abs(final_value - *last) - 1) / m;
        int insert_cost = num_inserts * i;
        best = std::min(best, prev_cost + move_cost + insert_cost);
    }
    return best;
}

int calculate_cost(const std::vector<int>& settings,
                   const std::vector<int>& pixels)
{
    int d = settings[0];
    int i = settings[1];
    int m = settings[3];
    int best = -1;

    for (int final_value = 0; final_value < 255; final_value++) {
        int cost = solve(pixels.begin(), pixels.end() - 1,
                         final_value, d, i, m);
        if (best == -1)
            best = cost;
        else
            best = std::min(best, cost);
    }
    return best;
}

int main()
{
    std::string line;
    std::getline(std::cin, line);
    int num_cases = boost::lexical_cast<int, std::string>(line);
    for (int i = 0; i < num_cases; i++) {
        std::vector<int> settings;
        std::vector<int> pixels;
        read_case(settings, pixels);
        std::cout << "Case #" << i + 1 << ": " <<
            calculate_cost(settings, pixels) << std::endl;
    }
}
