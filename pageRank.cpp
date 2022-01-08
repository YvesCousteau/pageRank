#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <complex>
using namespace std;

int * power_iteration(int matrix[][2], int num_simulations, int size);

int main() {
  srand((unsigned) time(0));

  // Initialise Matrix
  std::fstream file_size("/home/hugo/Project/pageRank/email-Eu-core.txt", std::ios_base::in);
  int size = 0;
  std::string unused;
  while ( std::getline(file_size, unused) ) {
      ++size;
  }
  int matrix[size][2];
  string var_1, var_2;
  int i = 0;
  int j = 0;
  std::fstream file_init("/home/hugo/Project/pageRank/email-Eu-core.txt", std::ios_base::in);
  while ( std::getline(file_init, unused) ) {
    istringstream tmp(unused);
    for(string unused; tmp >> unused; ) {
      matrix[i][j] = stoi(unused);
      ++j;
    }
    ++i;
    j = 0;
  }
  //

  // Launch Function
  int* b_final = power_iteration(matrix, 100, size);
  cout << b_final;
  return 0;
}

int * power_iteration(int matrix[][2], int num_simulations, int size) {
  // Initialise Vector
  int b_0[size];
  for (int i = 0; i < (sizeof(b_0)/sizeof(*b_0)); ++i) {
    b_0[i] = (1 + (rand() % size));
  }

  //
  int* b_k = b_0;
  int b_k_tmp[size];
  int b_k_tmp_norm;
  for (int z = 0; z < num_simulations; ++z) {
    for (int i = 0; i < size; ++i) {
      for (int j = 0; j < 2; ++j) {
        b_k_tmp[i] = b_k_tmp[i] + (b_k[i] * matrix[i][j]);
      }
    }
    double norm = 0.;
    for (int i = 0; i < size; ++i) {
        norm += b_k_tmp[i] * b_k_tmp[i];
    }
    b_k_tmp_norm = sqrt(norm);

    for (int i = 0; i < size; ++i) {
        b_k[i] = b_k_tmp[i] / b_k_tmp_norm;
    }
  }
  return b_k;
}
