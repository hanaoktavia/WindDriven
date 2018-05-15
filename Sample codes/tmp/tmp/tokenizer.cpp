// Tokenizer, this program uses C++11

#include "tokenizer.hpp"
#include <iostream>
#include <algorithm>

using namespace std;

// callback function
int isForwardSlash(int c)
{
   return (c == '/');
}

int isComma(int c)
{
   return (c == ',');
}

// default delimiter can be found in Tokenizer.hpp
vector<string> split(const string& str, int delimiter(int))
{
  vector<string> result;
  // iterators to str
  auto e = end(str);
  auto i = begin(str);
  
  while (i != e)
  {
    // find first char != delimiter
    i = find_if_not(i, e, delimiter);
    if (i != e)
    {
      // find first char == delimiter
      auto j = find_if(i, e, delimiter);
      // substring between i (begin) and j (end) added to result 
      result.push_back(string(i, j));
      i = j; 
    }
  }
 
  return result;
}

