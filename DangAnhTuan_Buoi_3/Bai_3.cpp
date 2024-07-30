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