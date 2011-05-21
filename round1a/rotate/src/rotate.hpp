#include <boost/multi_array.hpp>

enum Player {
    RED,
    BLUE,
    BOTH,
    NEITHER
};

inline Player determine_winner(const boost::multi_array<Player, 2>& board,
                               int k)
{
    return NEITHER;
}
