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

void xuatPhanTuSongSongDuongCheoChinh(int a[MAX][MAX], int n) {
    printf("\nCac phan tu thuoc duong cheo song song voi duong cheo chinh:\n");
    for (int i = 0; i < n - 1; i++) {
        printf("%4d", a[i][i + 1]);
    }
    printf("\n");
    for (int i = 1; i < n; i++) {
        printf("%4d", a[i][i - 1]);
    }
    printf("\n");
}


int timPhanTuLonNhatTamGiacTren(int a[MAX][MAX], int n) {
    int max = a[0][1];
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (a[i][j] > max) {
                max = a[i][j];
            }
        }
    }
    return max;
}

void sapXepzigzag(int a[MAX][MAX], int n) {
    int temp[MAX * MAX];
    int k = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            temp[k++] = a[i][j];
        }
    }

    for (int i = 0; i < k - 1; i++) {
        for (int j = i + 1; j < k; j++) {
            if (temp[i] > temp[j]) {
                int swap = temp[i];
                temp[i] = temp[j];
                temp[j] = swap;
            }
        }
    }

    k = 0;
    for (int i = 0; i < n; i++) {
        if (i % 2 == 0) {
            for (int j = 0; j < n; j++) {
                a[i][j] = temp[k++];
            }
        }
        else {
            for (int j = n - 1; j >= 0; j--) {
                a[i][j] = temp[k++];
            }
        }
    }
}

void sapXepDuongCheoChinh(int a[MAX][MAX], int n) {
    int temp[MAX];

    for (int i = 0; i < n; i++) {
        temp[i] = a[i][i];
    }

    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (temp[i] > temp[j]) {
                int swap = temp[i];
                temp[i] = temp[j];
                temp[j] = swap;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        a[i][i] = temp[i];
    }
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
        printf("2. Xuat cac phan tu thuoc duong cheo song song voi duong cheo chinh\n");
        printf("3. Tim phan tu max thuoc tam giac tren cua duong cheo chinh\n");
        printf("4. Sap xep ma tran tang dan theo kieu zic-zac\n");
        printf("5. Sap xep duong cheo chinh tang dan tu tren xuong duoi\n");
        printf("Chon: ");
        scanf("%d", &choice);

        switch (choice) {
        case 0:
            return 0;
        case 1:
            xuatPhanTuDuongCheoChinh(a, n);
            break;
        case 2:
            xuatPhanTuSongSongDuongCheoChinh(a, n);
            break;
        case 3:
            printf("Phan tu max thuoc tam giac tren cua duong cheo chinh: %d\n", timPhanTuLonNhatTamGiacTren(a, n));
            break;
        case 4:
            sapXepzigzag(a, n);
            xuatMaTran(a, n);
            break;
        case 5:
            sapXepDuongCheoChinh(a, n);
            xuatMaTran(a, n);
            break;

        default:
            printf("Lua chon khong hop le!\n");
            break;
        }
    }

    return 0;
}
