#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 100

void createMatrix(int a[MAX][MAX], int m, int n);
void printMatrix(int a[MAX][MAX], int m, int n);
void rowSum(int a[MAX][MAX], int m, int n);
void maxInColumns(int a[MAX][MAX], int m, int n);
void borderElements(int a[MAX][MAX], int m, int n);
void maxElements(int a[MAX][MAX], int m, int n);
void evenRows(int a[MAX][MAX], int m, int n);
void sortRows(int a[MAX][MAX], int m, int n);

void oddColumns(int a[MAX][MAX], int m, int n);
int maxBorderElement(int a[MAX][MAX], int m, int n);
int countDigitTwo(int a[MAX][MAX], int m, int n);
void minElements(int a[MAX][MAX], int m, int n);
void customRowSort(int a[MAX][MAX], int m, int n);
void customColumnSort(int a[MAX][MAX], int m, int n);
int checkZigzagDecrease(int a[MAX][MAX], int m, int n);
void listEvenRowsIndices(int a[MAX][MAX], int m, int n);
void listDecreasingRows(int a[MAX][MAX], int m, int n);
int mostFrequentValue(int a[MAX][MAX], int m, int n);
int mostFrequentDigit(int a[MAX][MAX], int m, int n);
void columnsWithMinSum(int a[MAX][MAX], int m, int n);
void swapColumns(int a[MAX][MAX], int m, int col1, int col2);
void swapRows(int a[MAX][MAX], int m, int row1, int row2);


int main() {
    int a[MAX][MAX];
    int m, n;
    int choice;

    srand(time(0));

    printf("Nhap so dong (m): ");
    scanf("%d", &m);
    printf("Nhap so cot (n): ");
    scanf("%d", &n);

    createMatrix(a, m, n);
    printMatrix(a, m, n);

    while (1) {
        printf("\nMenu:\n");
        printf("1. Xuat cac cot chi chua so le\n");
        printf("2. Tim phan tu lon nhat tren bien\n");
        printf("3. Dem cac phan tu chua chu so 2\n");
        printf("4. Xuat cac phan tu cuc tieu\n");
        printf("5. Sap xep cac dong le tang dan, chan giam dan\n");
        printf("6. Sap xep cac cot le giam dan, chan tang dan\n");
        printf("7. Kiem tra gia tri giam dan theo cot va dong (ziczac)\n");
        printf("8. Liet ke chi so cac dong chua toan gia tri chan\n");
        printf("9. Liet ke cac dong chua gia tri giam dan\n");
        printf("10. Tim gia tri xuat hien nhieu nhat\n");
        printf("11. Tim cac chu so xuat hien nhieu nhat\n");
        printf("12. Liet ke cac cot co tong nho nhat\n");
        printf("13. Hoan vi hai cot i va j\n");
        printf("14. Hoan vi hai dong k va l\n");
        printf("0. Thoat\n");
        printf("Chon: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            oddColumns(a, m, n);
            break;
        case 2:
            printf("Phan tu lon nhat tren bien: %d\n", maxBorderElement(a, m, n));
            break;
        case 3:
            printf("So phan tu chua chu so 2: %d\n", countDigitTwo(a, m, n));
            break;
        case 4:
            minElements(a, m, n);
            break;
        case 5:
            customRowSort(a, m, n);
            printMatrix(a, m, n);
            break;
        case 6:
            customColumnSort(a, m, n);
            printMatrix(a, m, n);
            break;
        case 7:
            if (checkZigzagDecrease(a, m, n)) {
                printf("Ma tran giam dan theo cot va dong (ziczac)\n");
            }
            else {
                printf("Ma tran khong giam dan theo cot va dong (ziczac)\n");
            }
            break;
        case 8:
            listEvenRowsIndices(a, m, n);
            break;
        case 9:
            listDecreasingRows(a, m, n);
            break;
        case 10:
            printf("Gia tri xuat hien nhieu nhat: %d\n", mostFrequentValue(a, m, n));
            break;
        case 11:
            printf("Chu so xuat hien nhieu nhat: %d\n", mostFrequentDigit(a, m, n));
            break;
        case 12:
            columnsWithMinSum(a, m, n);
            break;
        case 13: {
            int col1, col2;
            printf("Nhap hai cot can hoan vi (i, j): ");
            scanf("%d %d", &col1, &col2);
            swapColumns(a, m, col1, col2);
            printMatrix(a, m, n);
            break;
        }
        case 14: {
            int row1, row2;
            printf("Nhap hai dong can hoan vi (k, l): ");
            scanf("%d %d", &row1, &row2);
            swapRows(a, m, row1, row2);
            printMatrix(a, m, n);
            break;
        }

        case 0:
            return 0;
        default:
            printf("Lua chon khong hop le!\n");
            break;
        }
    }

    return 0;
}

void createMatrix(int a[MAX][MAX], int m, int n) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            a[i][j] = rand() % 100;  // Random number between 0 and 99
        }
    }
}

void printMatrix(int a[MAX][MAX], int m, int n) {
    printf("\nMa tran:\n");
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            printf("%4d", a[i][j]);
        }
        printf("\n");
    }
}

void rowSum(int a[MAX][MAX], int m, int n) {
    printf("\nTong gia tri tung dong:\n");
    for (int i = 0; i < m; i++) {
        int sum = 0;
        for (int j = 0; j < n; j++) {
            sum += a[i][j];
        }
        printf("Tong dong %d: %d\n", i, sum);
    }
}

void maxInColumns(int a[MAX][MAX], int m, int n) {
    printf("\nPhan tu lon nhat tren tung cot:\n");
    for (int j = 0; j < n; j++) {
        int max = a[0][j];
        for (int i = 1; i < m; i++) {
            if (a[i][j] > max) {
                max = a[i][j];
            }
        }
        printf("Cot %d: %d\n", j, max);
    }
}

void borderElements(int a[MAX][MAX], int m, int n) {
    printf("\nCac phan tu thuoc cac duong bien:\n");
    for (int j = 0; j < n; j++) {
        printf("%4d ", a[0][j]);
    }
    printf("\n");
    for (int i = 1; i < m - 1; i++) {
        printf("%4d ", a[i][0]);
        for (int j = 1; j < n - 1; j++) {
            printf("    ");
        }
        printf("%4d\n", a[i][n - 1]);
    }
    for (int j = 0; j < n; j++) {
        printf("%4d ", a[m - 1][j]);
    }
    printf("\n");
}

void maxElements(int a[MAX][MAX], int m, int n) {
    printf("\nCac phan tu cuc dai:\n");
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            int isMax = 1;
            if (i > 0 && a[i][j] <= a[i - 1][j]) isMax = 0;
            if (i < m - 1 && a[i][j] <= a[i + 1][j]) isMax = 0;
            if (j > 0 && a[i][j] <= a[i][j - 1]) isMax = 0;
            if (j < n - 1 && a[i][j] <= a[i][j + 1]) isMax = 0;
            if (isMax) {
                printf("%4d ", a[i][j]);
            }
            else {
                printf("    ");
            }
        }
        printf("\n");
    }
}

void evenRows(int a[MAX][MAX], int m, int n) {
    printf("\nDong chi chua so chan:\n");
    for (int i = 0; i < m; i++) {
        int isEvenRow = 1;
        for (int j = 0; j < n; j++) {
            if (a[i][j] % 2 != 0) {
                isEvenRow = 0;
                break;
            }
        }
        if (isEvenRow) {
            for (int j = 0; j < n; j++) {
                printf("%4d", a[i][j]);
            }
            printf("\n");
        }
    }
}

void sortRows(int a[MAX][MAX], int m, int n) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n - 1; j++) {
            for (int k = j + 1; k < n; k++) {
                if (a[i][j] > a[i][k]) {
                    int temp = a[i][j];
                    a[i][j] = a[i][k];
                    a[i][k] = temp;
                }
            }
        }
    }
}

void oddColumns(int a[MAX][MAX], int m, int n) {
    printf("\nCac cot chi chua so le:\n");
    for (int j = 0; j < n; j++) {
        int isOddColumn = 1;
        for (int i = 0; i < m; i++) {
            if (a[i][j] % 2 == 0) {
                isOddColumn = 0;
                break;
            }
        }
        if (isOddColumn) {
            for (int i = 0; i < m; i++) {
                printf("%4d", a[i][j]);
            }
            printf("\n");
        }
    }
}

int maxBorderElement(int a[MAX][MAX], int m, int n) {
    int max = a[0][0];
    for (int j = 0; j < n; j++) {
        if (a[0][j] > max) max = a[0][j];
        if (a[m - 1][j] > max) max = a[m - 1][j];
    }
    for (int i = 1; i < m - 1; i++) {
        if (a[i][0] > max) max = a[i][0];
        if (a[i][n - 1] > max) max = a[i][n - 1];
    }
    return max;
}

int countDigitTwo(int a[MAX][MAX], int m, int n) {
    int count = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            int num = a[i][j];
            while (num != 0) {
                if (num % 10 == 2) {
                    count++;
                    break;
                }
                num /= 10;
            }
        }
    }
    return count;
}

void minElements(int a[MAX][MAX], int m, int n) {
    printf("\nCac phan tu cuc tieu:\n");
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            int isMin = 1;
            if (i > 0 && a[i][j] >= a[i - 1][j]) isMin = 0;
            if (i < m - 1 && a[i][j] >= a[i + 1][j]) isMin = 0;
            if (j > 0 && a[i][j] >= a[i][j - 1]) isMin = 0;
            if (j < n - 1 && a[i][j] >= a[i][j + 1]) isMin = 0;
            if (isMin) {
                printf("%4d ", a[i][j]);
            }
            else {
                printf("    ");
            }
        }
        printf("\n");
    }
}

void customRowSort(int a[MAX][MAX], int m, int n) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n - 1; j++) {
            for (int k = j + 1; k < n; k++) {
                if ((i % 2 == 0 && a[i][j] > a[i][k]) || (i % 2 != 0 && a[i][j] < a[i][k])) {
                    int temp = a[i][j];
                    a[i][j] = a[i][k];
                    a[i][k] = temp;
                }
            }
        }
    }
}

void customColumnSort(int a[MAX][MAX], int m, int n) {
    for (int j = 0; j < n; j++) {
        for (int i = 0; i < m - 1; i++) {
            for (int k = i + 1; k < m; k++) {
                if ((j % 2 == 0 && a[i][j] > a[k][j]) || (j % 2 != 0 && a[i][j] < a[k][j])) {
                    int temp = a[i][j];
                    a[i][j] = a[k][j];
                    a[k][j] = temp;
                }
            }
        }
    }
}

int checkZigzagDecrease(int a[MAX][MAX], int m, int n) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n - 1; j++) {
            if (a[i][j] < a[i][j + 1]) return 0;
        }
    }
    for (int j = 0; j < n; j++) {
        for (int i = 0; i < m - 1; i++) {
            if (a[i][j] < a[i + 1][j]) return 0;
        }
    }
    return 1;
}

void listEvenRowsIndices(int a[MAX][MAX], int m, int n) {
    printf("\nChi so cac dong chua toan gia tri chan:\n");
    for (int i = 0; i < m; i++) {
        int isEvenRow = 1;
        for (int j = 0; j < n; j++) {
            if (a[i][j] % 2 != 0) {
                isEvenRow = 0;
                break;
            }
        }
        if (isEvenRow) {
            printf("%d ", i);
        }
    }
    printf("\n");
}

void listDecreasingRows(int a[MAX][MAX], int m, int n) {
    printf("\nCac dong chua gia tri giam dan:\n");
    for (int i = 0; i < m; i++) {
        int isDecreasingRow = 1;
        for (int j = 0; j < n - 1; j++) {
            if (a[i][j] < a[i][j + 1]) {
                isDecreasingRow = 0;
                break;
            }
        }
        if (isDecreasingRow) {
            for (int j = 0; j < n; j++) {
                printf("%4d", a[i][j]);
            }
            printf("\n");
        }
    }
}

int mostFrequentValue(int a[MAX][MAX], int m, int n) {
    int frequency[MAX * MAX] = { 0 };
    int maxFrequency = 0;
    int value = a[0][0];
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            int index = a[i][j];
            frequency[index]++;
            if (frequency[index] > maxFrequency) {
                maxFrequency = frequency[index];
                value = a[i][j];
            }
        }
    }
    return value;
}

int mostFrequentDigit(int a[MAX][MAX], int m, int n) {
    int digitFrequency[10] = { 0 };
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            int num = a[i][j];
            while (num != 0) {
                int digit = num % 10;
                digitFrequency[digit]++;
                num /= 10;
            }
        }
    }
    int maxFrequency = 0;
    int digit = 0;
    for (int i = 0; i < 10; i++) {
        if (digitFrequency[i] > maxFrequency) {
            maxFrequency = digitFrequency[i];
            digit = i;
        }
    }
    return digit;
}

void columnsWithMinSum(int a[MAX][MAX], int m, int n) {
    int minSum = 0;
    int first = 1;
    printf("\nCac cot co tong nho nhat:\n");
    for (int j = 0; j < n; j++) {
        int sum = 0;
        for (int i = 0; i < m; i++) {
            sum += a[i][j];
        }
        if (first || sum < minSum) {
            minSum = sum;
            first = 0;
        }
    }
    for (int j = 0; j < n; j++) {
        int sum = 0;
        for (int i = 0; i < m; i++) {
            sum += a[i][j];
        }
        if (sum == minSum) {
            printf("%d ", j);
        }
    }
    printf("\n");
}

void swapColumns(int a[MAX][MAX], int m, int col1, int col2) {
    for (int i = 0; i < m; i++) {
        int temp = a[i][col1];
        a[i][col1] = a[i][col2];
        a[i][col2] = temp;
    }
}

void swapRows(int a[MAX][MAX], int m, int row1, int row2) {
    for (int j = 0; j < m; j++) {
        int temp = a[row1][j];
        a[row1][j] = a[row2][j];
        a[row2][j] = temp;
    }
}