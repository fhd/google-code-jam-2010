#include <queue>
#include <boost/foreach.hpp>

inline int profit_from(int rounds, int capacity, std::queue<int>& groups)
{
    if (rounds == 0 || capacity == 0 || groups.empty())
        return 0;

    int profit = 0;

    for (int i = 0; i < rounds; i++) {
        int remaining_capacity = capacity;

        for (int j = 0; j < groups.size(); j++) {
            int next_group = groups.front();
            if (remaining_capacity < next_group)
                break;

            remaining_capacity -= next_group;
            groups.pop();
            groups.push(next_group);
        }

        profit += capacity - remaining_capacity;
    }

    return profit;
}
