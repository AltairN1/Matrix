#include <iostream>      
#include <ctime>      

int** generate(const int** matrix, size_t m, size_t n);

int main() {

    size_t m, n;
    (std::cin >> m >> n).get();

    int** Arr = new int* [n];
    srand(time(0));
    for (size_t i = 0; i < n; ++i) {
        Arr[i] = new int[m];
        for (size_t j = 0; j < m; ++j)
            std::cout << (Arr[i][j] = rand() % 100) << '\t';
        std::cout << std::endl;
    }

    std::cout << std::endl;

    auto i = generate((const int**)Arr, m, n);
    std::cout << std::endl;

    for (size_t i = 0; i < n; ++i) {
        for (size_t j = 0; j < m; ++j)
            std::cout << Arr[i][j] << '\t';
        std::cout << std::endl;
        delete[] Arr[i];
    }
    delete[] Arr;

    return 0;
}

int** generate(const int** matrix, size_t m, size_t n) {
    int temp1;
    int *temp11, *temp22;
    // сортировка по столбцам
    for (size_t i = 0; i < m; i++) {
        for (size_t j = 1; j <= n; j++) {
            for (size_t k = n - 1; k >= j; k--) {
                if (matrix[k - 1][i] < matrix[k][i]) {
                    temp1 = matrix[k][i];
                    temp11 = (int*)(&matrix[k][i]);
                    temp22 = (int*)(&matrix[k - 1][i]);
                    *temp11 = *temp22;
                    *temp22 = temp1;
                }
            }
        }
    }
    // сортировка по строкам
    for (size_t i = 0; i < m; i++) {
        for (size_t j = 1; j <= n; j++) {
            for (size_t k = n - 1; k >= j; k--) {
                if (matrix[i][k - 1] < matrix[i][k]) {
                    temp1 = matrix[i][k];
                    temp11 = (int*)(&matrix[i][k]);
                    temp22 = (int*)(&matrix[i][k-1]);
                    *temp11 = *temp22;
                    *temp22 = temp1;
                }
            }
        }
    }
    return 0;
}
