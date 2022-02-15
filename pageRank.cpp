#include <iostream>
#include <fstream>
#include <sstream>

#include <string>
#include <complex>
#include <vector>
#include <math.h>

#include <ctime>
#include <chrono>
using namespace std;

// void pageRank(int iteration, int size, float* x, float matrix_proba[][1005], float dumping_factor);
int main(int argc, char const *argv[]) {
  // clock
  int size = 1005;
  float dumping_diff = 0.05;
  float tol = 1;
  // set Matrix to zero
  int matrix[size][size];
  for (int i = 0; i < size; i++) {
    for (int j = 0; j < size; j++) {
      matrix[i][j] = 0;
    }
  }

  // init Matrix
  string line;
  fstream file("/home/hugo/Project/pageRank/email-Eu-core.txt", ios_base::in);
  if (file) {
    while (getline(file, line)) {
      matrix[stoi(line.substr(0, line.find(" ")))][stoi(line.erase(0, line.find(" ")+1))] = 1;
    }
  }

  // count link
  int count_link[size];
  for (int i = 0; i < size; i++) {
    count_link[i] = 0;
    for (int j = 0; j < size; j++) {
      if (matrix[i][j] == 1) {
        count_link[i] ++;
      }
    }
  }

  // matrix transition
  float matrix_proba[size][size];
  for (int i = 0; i < size; i++) {
    for (int j = 0; j < size; j++) {
      if (matrix[i][j] == 1) {
        matrix_proba[i][j] = 1.0/count_link[i];
      } else {
        matrix_proba[i][j] = 0.0;
      }
      // printf("%f\n",matrix_proba[i][j]);
      // printf("%d\n",matrix[i][j]);
    }
  }

  // init Vector
  float b[size];
  for (int i = 0; i < size; i++) {
    b[i] = (1.0 / size);
    // printf("%f\n", b[i]);
  }

  for (int tol_it = 1; tol_it < 6; tol_it ++) {
    tol = 1 / pow(10, tol_it);

    // Write
    ofstream output_file;
    output_file.open("clock_"+ to_string(tol) +".txt");
    string separator = " ";

    // loop dumping factor
    float x[size];
    float x_last[size];
    double err;

    for (double dumping_factor = 0; dumping_factor <= 1.00 + dumping_diff; dumping_factor += dumping_diff) {
      // loop it
      err = 0.0; // need to be > 0
      for (int i = 0; i < size; i++) {
        x[i] = b[i];
      }

      auto start = chrono::steady_clock::now();
      for (int k = 0; k < 100; k++) {
        // x = A * b
        for (int m = 0; m < size; m++) {
          // err += fabs(x_new[m] - x[m]);
          x_last[m] = x[m];
        }

        for (int n = 0; n != size; n++) {
          x[n] = 0;
          for (int d = 0; d != size; d++) {
            x[n] += (matrix_proba[n][d]*x_last[d]);
          }
          // printf("%f\n", x[n]);
        }

        for (int l = 0; l != size; l++) {
          x[l] = (dumping_factor * x[l]) + ((1 - dumping_factor) / size);
          // printf("%f\n", x[l]);
        }

        err = 0.0;
        for (int e = 0; e != size; e++) {
          err += fabs(x_last[e] - x[e]);
        }

        if (err < tol) {
          // printf("%f vs %f\n", err, tol);
          break;
        }
      }

      auto end = chrono::steady_clock::now();
      output_file << chrono::duration_cast<std::chrono::milliseconds>(end - start).count() << separator << dumping_factor << "\n";
    }
    output_file.close();
  }
  return 0;
}
