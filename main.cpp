#include <bits/stdc++.h>
using namespace std;

class maze_solver {
 private:
  unique_ptr<vector<vector<int>>> maze;
  unique_ptr<pair<int, int>> goal;
  unique_ptr<pair<int, int>> start;

  bool solvable(int row, int col) {
    if (row < 0 or col < 0 or row > maze->size() - 1 or col > maze->at(0).size() - 1 or maze->at(row).at(col)) return false;
    maze->at(row).at(col) = 2;
    if (row == goal->first and col == goal->second) return true;
    if (solvable(row, col + 1) or solvable(row + 1, col) or solvable(row, col - 1) or solvable(row - 1, col)) return true;
    maze->at(row).at(col) = 0;
    return false;
  }

 public:
  maze_solver(vector<vector<int>>& maze, pair<int, int>& goal, pair<int, int>& start) {
    this->maze = make_unique<vector<vector<int>>>(maze);
    this->goal = make_unique<pair<int, int>>(goal);
    this->start = make_unique<pair<int, int>>(start);
  }

  void get_ans() {
    bool has_ans = solvable(start->first, start->second);
    cout.setf(ios::boolalpha);
    cout << has_ans << endl;
    if (has_ans)
      for (int i = 0; i < maze->size(); i++) {
        for (int j = 0; j < maze->at(0).size(); j++)
          cout << (maze->at(i).at(j) != 2 ? to_string(maze->at(i).at(j)) : "*");
        cout << endl;
      }
  }
};

int main() {
  vector<vector<int>> maze{
      {0, 0, 0, 0, 0, 0, 0, 0, 0},  // sl1
      {0, 0, 0, 0, 0, 0, 1, 1, 1},  // gp1,2
      {0, 1, 0, 1, 0, 0, 0, 0, 0},  // sl2
      {0, 1, 0, 1, 1, 1, 0, 1, 1},  // gp2,3
      {0, 1, 0, 0, 0, 1, 0, 0, 0},  // sl3
      {0, 1, 1, 1, 0, 1, 1, 1, 0},  // gp3,4
      {0, 0, 0, 1, 0, 0, 0, 1, 0},  // sl4
      {0, 1, 1, 1, 1, 1, 0, 1, 0},  // gp4,5
      {0, 0, 0, 0, 0, 1, 0, 1, 0}   // sl5
  };
  pair<int, int> goal{8, 8};
  pair<int, int> start{0, 0};
  maze_solver solver(maze, goal, start);
  solver.get_ans();
}