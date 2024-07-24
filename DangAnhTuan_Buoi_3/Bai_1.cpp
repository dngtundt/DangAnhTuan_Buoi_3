#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 100

void taoMaTranNgauNhien(int a[MAX][MAX], int m, int n, int k) {
    srand(time(0));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            a[i][j] = rand() % (k + 1);
        }
    }
}

void xuatMaTran(int a[MAX][MAX], int m, int n) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            printf("%4d", a[i][j]);
        }
        printf("\n");
    }
}

void tinhTongTungDong(int a[MAX][MAX], int m, int n) {
    for (int i = 0; i < m; i++) {
        int tong = 0;
        for (int j = 0; j < n; j++) {
            tong += a[i][j];
        }
        printf("Tong dong %d: %d\n", i, tong);
    }
}

void xuatMaxTungCot(int a[MAX][MAX], int m, int n) {
    for (int j = 0; j < n; j++) {
        int max = a[0][j];
        for (int i = 1; i < m; i++) {
            if (a[i][j] > max) {
                max = a[i][j];
            }
        }
        printf("Max cot %d: %d\n", j, max);
    }
}

int main() {
    int a[MAX][MAX];
    int m, n, k;
    int choice;

    do {
        printf("\nMENU\n");
        printf("1. Tao va xuat ma tran ngau nhien\n");
        printf("2. Tinh tong gia tri tung dong\n");
        printf("3. Xuat phan tu lon nhat tren tung cot\n");
        printf("0. Thoat\n");
        printf("Nhap lua chon cua ban: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Nhap so dong m: ");
            scanf("%d", &m);
            printf("Nhap so cot n: ");
            scanf("%d", &n);
            printf("Nhap gia tri k: ");
            scanf("%d", &k);
            taoMaTranNgauNhien(a, m, n, k);
            xuatMaTran(a, m, n);
            break;

        case 2:
            tinhTongTungDong(a, m, n);
            break;

        case 3:
            xuatMaxTungCot(a, m, n);
            break;

        case 0:
            printf("Thoat chuong trinh.\n");
            break;
        default:
            printf("Lua chon khong hop le. Vui long chon lai.\n");
        }
    } while (choice != 0);

    return 0;
}
