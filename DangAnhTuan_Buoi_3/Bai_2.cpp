#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 100

void taoMaTranNgauNhien(int a[MAX][MAX], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            a[i][j] = rand() % 100;  // Random number between 0 and 99
        }
    }
}

void xuatMaTran(int a[MAX][MAX], int n) {
    printf("\nMa tran:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%4d", a[i][j]);
        }
        printf("\n");
    }
}

void xuatPhanTuDuongCheoChinh(int a[MAX][MAX], int n) {
    printf("\nCac phan tu tren duong cheo chinh:\n");
    for (int i = 0; i < n; i++) {
        printf("%4d", a[i][i]);
    }
    printf("\n");
}

int main() {
    int a[MAX][MAX];
    int n;
    int choice;

    srand(time(0));

    do {
        printf("Nhap cap ma tran vuong n (n >= 5): ");
        scanf("%d", &n);
    } while (n < 5);

    taoMaTranNgauNhien(a, n);
    xuatMaTran(a, n);

    while (1) {
        printf("\nMenu:\n");
        printf("0. Thoat\n");
        printf("1. Xuat cac phan tu tren duong cheo chinh\n");
        printf("Chon: ");
        scanf("%d", &choice);

        switch (choice) {
        case 0:
            return 0;
        case 1:
            xuatPhanTuDuongCheoChinh(a, n);
            break;
        default:
            printf("Lua chon khong hop le!\n");
            break;
        }
    }

    return 0;
}
