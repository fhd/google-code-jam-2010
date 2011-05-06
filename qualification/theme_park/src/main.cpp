#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

#include <boost/algorithm/string.hpp>
#include <boost/filesystem.hpp>
#include <boost/lexical_cast.hpp>

#include "theme_park.hpp"

namespace fs = boost::filesystem;

void process(const std::string& input_file, const std::string& output_file)
{
   std::ifstream input(input_file.c_str());
   std::ofstream output(output_file.c_str());
   std::string line;
   bool first_line = true;
   int i = 1, rounds, capacity;

   std::getline(input, line); // Ignore the first line.
   while (std::getline(input, line)) {
      if (line.empty())
         continue;

      // Every problem consists of two lines
      if (first_line) {
          std::vector<std::string> elements;
          boost::split(elements, line, boost::is_any_of(" "));
          rounds = boost::lexical_cast<int>(elements[0]);
          capacity = boost::lexical_cast<int>(elements[1]);
          first_line = false;
      } else {
          std::queue<int> groups;
          typedef boost::split_iterator<std::string::iterator> string_split_iterator;
          for (string_split_iterator it =
                   boost::make_split_iterator(line, boost::first_finder(" ", boost::is_equal()));
               it != string_split_iterator(); it++)
              groups.push(boost::lexical_cast<int>(*it));
          output << "Case #" << i++ << ": "
                 << profit_from(rounds, capacity, groups)
                 << std::endl;
          first_line = true;
      }
   }
}

int main(int argc, char *argv[])
{
   try {
      if (argc != 3) {
         std::cerr << "Usage: " << fs::basename(argv[0]) << " INPUT OUTPUT"
                   << std::endl;
         return 1;
      }
      process(argv[1], argv[2]);
   } catch (std::exception& e) {
      std::cerr << "Caught an exception: " << e.what() << std::endl;
      return 1;
   }

   return 0;
}
