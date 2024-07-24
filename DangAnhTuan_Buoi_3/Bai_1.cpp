//#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//#include <stdlib.h>
//#include <time.h>
//
//#define MAX 100
//
//void taoMaTranNgauNhien(int a[MAX][MAX], int m, int n, int k) {
//    srand(time(0));
//    for (int i = 0; i < m; i++) {
//        for (int j = 0; j < n; j++) {
//            a[i][j] = rand() % (k + 1);
//        }
//    }
//}
//
//void xuatMaTran(int a[MAX][MAX], int m, int n) {
//    for (int i = 0; i < m; i++) {
//        for (int j = 0; j < n; j++) {
//            printf("%4d", a[i][j]);
//        }
//        printf("\n");
//    }
//}
//
//void tinhTongTungDong(int a[MAX][MAX], int m, int n) {
//    for (int i = 0; i < m; i++) {
//        int tong = 0;
//        for (int j = 0; j < n; j++) {
//            tong += a[i][j];
//        }
//        printf("Tong dong %d: %d\n", i, tong);
//    }
//}
//
//void xuatMaxTungCot(int a[MAX][MAX], int m, int n) {
//    for (int j = 0; j < n; j++) {
//        int max = a[0][j];
//        for (int i = 1; i < m; i++) {
//            if (a[i][j] > max) {
//                max = a[i][j];
//            }
//        }
//        printf("Max cot %d: %d\n", j, max);
//    }
//}
//
//void xuatCacPhanTuDuongBien(int a[MAX][MAX], int m, int n) {
//    printf("Duong bien tren va duoi:\n");
//    for (int j = 0; j < n; j++) {
//        printf("%4d", a[0][j]);
//    }
//    printf("\n");
//    for (int j = 0; j < n; j++) {
//        printf("%4d", a[m - 1][j]);
//    }
//    printf("\nDuong bien trai va phai:\n");
//    for (int i = 1; i < m - 1; i++) {
//        printf("%4d%*s%4d\n", a[i][0], (n - 1) * 4 - 4, "", a[i][n - 1]);
//    }
//}
//
//int laCucDai(int a[MAX][MAX], int i, int j, int m, int n) {
//    int di[] = { -1, 0, 1, 0 };
//    int dj[] = { 0, 1, 0, -1 };
//    for (int k = 0; k < 4; k++) {
//        int ni = i + di[k];
//        int nj = j + dj[k];
//        if (ni >= 0 && ni < m && nj >= 0 && nj < n && a[ni][nj] >= a[i][j]) {
//            return 0;
//        }
//    }
//    return 1;
//}
//
//void xuatCacPhanTuCucDai(int a[MAX][MAX], int m, int n) {
//    printf("Cac phan tu cuc dai:\n");
//    for (int i = 0; i < m; i++) {
//        for (int j = 0; j < n; j++) {
//            if (laCucDai(a, i, j, m, n)) {
//                printf("%4d", a[i][j]);
//            }
//        }
//    }
//    printf("\n");
//}
//
//void xuatDongChiChuaSoChan(int a[MAX][MAX], int m, int n) {
//    printf("Cac dong chi chua so chan:\n");
//    for (int i = 0; i < m; i++) {
//        int chiChuaSoChan = 1;
//        for (int j = 0; j < n; j++) {
//            if (a[i][j] % 2 != 0) {
//                chiChuaSoChan = 0;
//                break;
//            }
//        }
//        if (chiChuaSoChan) {
//            for (int j = 0; j < n; j++) {
//                printf("%4d", a[i][j]);
//            }
//            printf("\n");
//        }
//    }
//}
//
//void sapXepTangTheoDong(int a[MAX][MAX], int m, int n) {
//    for (int i = 0; i < m; i++) {
//        for (int j = 0; j < n - 1; j++) {
//            for (int k = j + 1; k < n; k++) {
//                if (a[i][j] > a[i][k]) {
//                    int temp = a[i][j];
//                    a[i][j] = a[i][k];
//                    a[i][k] = temp;
//                }
//            }
//        }
//    }
//}
//
//int main() {
//    int a[MAX][MAX];
//    int m, n, k;
//    int choice;
//
//    do {
//        printf("\nMENU\n");
//        printf("1. Tao va xuat ma tran ngau nhien\n");
//        printf("2. Tinh tong gia tri tung dong\n");
//        printf("3. Xuat phan tu lon nhat tren tung cot\n");
//        printf("4. Xuat cac phan tu thuoc cac duong bien\n");
//        printf("5. Xuat cac phan tu cuc dai\n");
//        printf("6. Xuat dong chi chua so chan\n");
//        printf("7. Sap xep mang tang theo tung dong\n");
//        printf("0. Thoat\n");
//        printf("Nhap lua chon cua ban: ");
//        scanf("%d", &choice);
//
//        switch (choice) {
//        case 1:
//            printf("Nhap so dong m: ");
//            scanf("%d", &m);
//            printf("Nhap so cot n: ");
//            scanf("%d", &n);
//            printf("Nhap gia tri k: ");
//            scanf("%d", &k);
//            taoMaTranNgauNhien(a, m, n, k);
//            xuatMaTran(a, m, n);
//            break;
//        case 2:
//            tinhTongTungDong(a, m, n);
//            break;
//        case 3:
//            xuatMaxTungCot(a, m, n);
//            break;
//        case 4:
//            xuatCacPhanTuDuongBien(a, m, n);
//            break;
//        case 5:
//            xuatCacPhanTuCucDai(a, m, n);
//            break;
//        case 6:
//            xuatDongChiChuaSoChan(a, m, n);
//            break;
//        case 7:
//            sapXepTangTheoDong(a, m, n);
//            xuatMaTran(a, m, n);
//        case 0:
//            printf("Thoat chuong trinh.\n");
//            break;
//        default:
//            printf("Lua chon khong hop le. Vui long chon lai.\n");
//        }
//    } while (choice != 0);
//
//    return 0;
//}
