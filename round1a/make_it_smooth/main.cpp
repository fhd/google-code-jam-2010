#include <algorithm>
#include <cmath>
#include <iostream>
#include <map>
#include <sstream>
#include <vector>
#include <boost/lexical_cast.hpp>
#include <boost/tuple/tuple.hpp>
#include <boost/tuple/tuple_comparison.hpp>

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
    typedef boost::tuple<std::vector<int>::const_iterator,
                         std::vector<int>::const_iterator, int> Lookup_key;
    typedef std::map<Lookup_key, int> Lookup_table;

    static Lookup_table lookup_table;

    Lookup_key key(first, last, final_value);

    Lookup_table::iterator lookup_it = lookup_table.find(key);
    if (lookup_it != lookup_table.end())
        return lookup_it->second;

    if (first > last)
        return 0;

    int best = solve(first, last - 1, final_value, d, i, m) + d;
    for (int prev_value = 0; prev_value < 256; prev_value++) {
        int prev_cost = solve(first, last - 1, prev_value, d, i, m);
        int move_cost = abs(final_value - *last);
        int num_inserts = (abs(final_value - prev_value) - 1) / m;
        int insert_cost = num_inserts * i;
        best = std::min(best, prev_cost + move_cost + insert_cost);
    }

    lookup_table[key] = best;

    return best;
}

int calculate_cost(const std::vector<int>& settings,
                   const std::vector<int>& pixels)
{
    int d = settings[0];
    int i = settings[1];
    int m = settings[2];
    int best = -1;

    for (int final_value = 0; final_value < 256; final_value++) {
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
