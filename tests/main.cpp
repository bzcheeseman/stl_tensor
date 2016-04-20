#include <iostream>
#include "../Tensor.h"

using namespace std;

int main() {
  Tensor<int> m;

  std::vector<int> zeros = {0,0,0,0};
  m[0] = zeros;

  m.insert(1,3,52);

  cout << m[1][3] << endl;

  cout << m(0,0) << endl;

  Tensor3<int> t;
  std::vector<int> ones = {1,1,1,1};
  t(0,0,0) = 3;
  t[0][1] = ones;
  t[2] = m;

  cout << t(0,0,0) << endl;
  cout << t[0][1][3] << endl;

  return 0;
}