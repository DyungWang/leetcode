#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  int distanceBetweenBusStops(vector<int>& distance, int start, int destination) {
    if (start > destination) swap(start, destination);
    int total = 0; for (auto dis : distance) total += dis;
    int forward = 0; for (int i = start; i < destination; ++i) forward += distance[i]; 
    return min(forward, total - forward);      
  }
};

struct TestCase {
  vector<int> distance;
  int start;
  int destination;
  int result;
};

TestCase case1 = { { 1, 2, 3, 4}, 0, 1, 1 };
TestCase case2 = { { 1, 2, 3, 4}, 0, 2, 3 };
TestCase case3 = { { 1, 2, 3, 4}, 0, 3, 4 };
TestCase case4 = { { 7, 10, 1, 12, 11, 14, 5, 0 }, 7, 2, 17 };

int main(int, char**) {
  Solution solution;
  assert(solution.distanceBetweenBusStops(case1.distance, case1.start, case1.destination) == case1.result);
  assert(solution.distanceBetweenBusStops(case2.distance, case2.start, case2.destination) == case2.result);
  assert(solution.distanceBetweenBusStops(case3.distance, case3.start, case3.destination) == case3.result);
  assert(solution.distanceBetweenBusStops(case4.distance, case4.start, case4.destination) == case4.result);
  return 0;
}
