#include <iostream>
#include <climits> // Для використання INT_MIN

int main() {
    int A[100][10], n, m, i, j;

    std::cout << "Vvedit n" << std::endl;
    std::cin >> n;
    std::cout << "Vvedit m" << std::endl;
    std::cin >> m;

    // Введення матриці
    for (i = 0; i < n; i++)
        for (j = 0; j < m; j++) {
            std::cout << "A[" << i << "][" << j << "] ";
            std::cin >> A[i][j];
        }

    // Виведення матриці
    std::cout << "Matrix:" << std::endl;
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            std::cout << A[i][j] << " ";
        }
        std::cout << std::endl;
    }

    int max_of_min = INT_MIN; // Ініціалізуємо максимум як найменше можливе значення INT_MIN

    // Знаходження та виведення мінімального елементу кожного рядка та знаходження максимального серед них
    for (i = 0; i < n; i++) {
        int min_row = A[i][0];  // Припускаємо, що перший елемент - мінімальний для поточного рядка
        for (j = 1; j < m; j++) {
            if (A[i][j] < min_row) {
                min_row = A[i][j];
            }
        }
        std::cout << "min in row " << i << ": " << min_row << std::endl;

        // Оновлення максимуму серед мінімальних елементів
        if (min_row > max_of_min) {
            max_of_min = min_row;
        }
    }

    // Виведення максимального серед мінімальних елементів
    std::cout << "max of min: " << max_of_min << std::endl;

    return 0;
}


