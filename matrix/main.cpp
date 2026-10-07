#include <iostream>
#include <stdexcept>

void freeMatrix(int ** m, size_t rows) {
  for (size_t i = 0; i < rows; ++i) {
    delete [] m[i];
  }
  delete [] m;
}

int ** readTransposed(size_t rows, size_t cols) {
  int ** t = new int * [cols]();
  try {
    for (size_t j = 0; j < cols; ++j) {
      t[j] = new int[rows];
    }
    for (size_t i = 0; i < rows; ++i) {
      for (size_t j = 0; j < cols; ++j) {
        if (!(std::cin >> t[j][i])) {
          throw std::invalid_argument("bad input");
        }
      }
    }
  } catch (...) {
    freeMatrix(t, cols);
    throw;
  }
  return t;
}

void printMatrix(const int * const * m, size_t rows, size_t cols) {
  for (size_t i = 0; i < rows; ++i) {
    for (size_t j = 0; j < cols; ++j) {
      std::cout << m[i][j] << " ";
    }
    std::cout << "\n";
  }
}

int main() {
  size_t rows = 0, cols = 0;
  if (!(std::cin >> rows >> cols)) {
    return 1;
  }
  try {
    int ** t = readTransposed(rows, cols);
    printMatrix(t, cols, rows);
    freeMatrix(t, cols);
  } catch (const std::bad_alloc &) {
    return 2;
  } catch (const std::invalid_argument &) {
    return 1;
  }
}
