#include <iostream>
#include <string>
#include <vector>
#include <matrix>
#include <stdio.h>
#include <stdlib.h>
#include <ctime>
#include <fstream>
using namespace std;

int main(int argc, char** argv) {
  srand((unsigned) time(0));

  std::fstream file("/home/hugo/Project/pageRank/email-Eu-core.txt", std::ios_base::in);
  double a;
  while (file >> a) {
      cout << a << "\n";
  }

  getchar();
  // Initialise Vector
  std::vector<double> b_0(5);
  cout << "Initial Vector b_0: ";
  for (int i = 0; i < b_0.size(); ++i) {
    b_0.at(i) = (1 + (rand() % 6));
    cout << b_0.at(i) << "  ";
  }
  cout << "\n";

  // Launch Function
  // power_iteration(b_0);
  return 0;
}

// vector power_iteration(vector b_0) {
//   // for _ in range(num_simulations):
//   //       # calculate the matrix-by-vector product Ab
//   //       b_k1 = np.dot(A, b_k)
//   //
//   //       # calculate the norm
//   //       b_k1_norm = np.linalg.norm(b_k1)
//   //
//   //       # re normalize the vector
//   //       b_k = b_k1 / b_k1_norm
//   //
//   //   return b_k
//   return 0;
// }
