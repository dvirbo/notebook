// Header file for class Notebook
#pragma once
#include "Direction.hpp"
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;


namespace ariel
{
  class Notebook
  {
  private:
  
    unordered_map<string, vector<char>> note;
  
  public:
    void write(int page, int row, int col, Direction dir, string const &data);
    string read(int page, int row, int col, Direction dir, int len);
    void erase(int page, int row, int col, Direction dir, int len);
    void show(int page);
    void ckeck_args(int page, int row, int col, int len, Direction dir);
    void valid_write(string const &data);
  };
}
