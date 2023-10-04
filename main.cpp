#include <iostream>
#include <vector>

template <typename T>
auto make_matrix(const size_t nrows, const size_t ncols) {
    std::vector<std::vector<T>> result(nrows);
    for (size_t r = 0; r != nrows; ++r) {
        result[r].resize(ncols);
    }
    return result;
}

template <typename T>
void matmul(const std::vector<std::vector<T>>& A, const std::vector<std::vector<T>>& B, std::vector<std::vector<T>>& C) {
    const auto m = A.size();
    const auto k = B.size();
    const auto n = B[0].size();
    assert(k == A[0].size());

    for (size_t k_val = 0; k_val < k; ++k_val) {
        for (size_t i = 0; i < m; ++i) {
            for (size_t j = 0; j < n; ++j) {
                if (k_val == 0) {
                    C[i][j] = A[i][k_val] * B[k_val][j];
                } else {
                    C[i][j] += A[i][k_val] * B[k_val][j];
                }
            }
        }
    }
}

int main() {
    using T = double;
    const size_t N = 8192;
    auto A = make_matrix<T>(N, N);
    auto B = make_matrix<T>(N, N);
    auto C = make_matrix<T>(N, N);
    matmul(A, B, C);

    return 0;
}
