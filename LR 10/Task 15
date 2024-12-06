#include <iostream>
using namespace std;

int main() {
    const int m = 3, n = 3; // Розміри масиву
    int array[m][n] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    int mainDiagonalSum = 0; // Сума головної діагоналі
    int secondaryDiagonalSum = 0; // Сума побічної діагоналі

    for (int i = 0; i < m; ++i) {
        mainDiagonalSum += array[i][i]; // Головна діагональ
        secondaryDiagonalSum += array[i][n - 1 - i]; // Побічна діагональ
    }
  /*
  Головна діагональ: Значення елементів на позиціях (0,0), (1,1), (2,2) додаються до mainDiagonalSum.
Побічна діагональ: Значення елементів на позиціях (0,2), (1,1), (2,0) додаються до secondaryDiagonalSum.
  */

    cout << "Сума головної діагоналі: " << mainDiagonalSum << endl;
    cout << "Сума побічної діагоналі: " << secondaryDiagonalSum << endl;
  //Сума головної діагоналі: 15 (1 + 5 + 9)
//Сума побічної діагоналі: 15 (3 + 5 + 7)
    return 0;
}
