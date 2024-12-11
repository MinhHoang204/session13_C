#include <stdio.h>
#include <stdbool.h>

// Ham kiem tra so nguyen to
bool isPrime(int n) {
    if (n <= 1) return false;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) return false;
    }
    return true;
}

// Ham nhap gia tri cac phan tu cua mang
void inputMatrix(int arr[][100], int n, int m) {
    printf("Nhap gia tri cac phan tu cua ma tran:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("Nhap phan tu arr[%d][%d]: ", i, j);
            scanf("%d", &arr[i][j]);
        }
    }
}

// Ham in ma tran
void printMatrix(int arr[][100], int n, int m) {
    printf("Ma tran:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}

// Ham in cac phan tu o goc cua ma tran
void printCorners(int arr[][100], int n, int m) {
    printf("Cac phan tu o goc cua ma tran:\n");
    printf("arr[0][0]: %d\n", arr[0][0]);
    printf("arr[0][%d]: %d\n", m - 1, arr[0][m - 1]);
    printf("arr[%d][0]: %d\n", n - 1, arr[n - 1][0]);
    printf("arr[%d][%d]: %d\n", n - 1, m - 1, arr[n - 1][m - 1]);
}

// Ham in cac phan tu o duong bien cua ma tran
void printBorder(int arr[][100], int n, int m) {
    printf("Cac phan tu nam tren duong bien cua ma tran:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (i == 0 || i == n - 1 || j == 0 || j == m - 1) {
                printf("%d ", arr[i][j]);
            } else {
                printf("0 ");
            }
        }
        printf("\n");
    }
}

// Ham in cac phan tu nam tren duong cheo chinh va cheo phu
void printDiagonals(int arr[][100], int n, int m) {
    printf("Cac phan tu nam tren duong cheo chinh va cheo phu:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (i == j || i + j == n - 1) {
                printf("%d ", arr[i][j]);
            } else {
                printf("0 ");
            }
        }
        printf("\n");
    }
}

// Ham in cac phan tu la so nguyen to cua ma tran
void printPrimes(int arr[][100], int n, int m) {
    printf("Cac phan tu la so nguyen to trong ma tran:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (isPrime(arr[i][j])) {
                printf("%d ", arr[i][j]);
            }
        }
    }
    printf("\n");
}

int main() {
    int n, m;
    int arr[100][100];

    // Nhap so hang va so cot cua ma tran
    printf("Nhap so hang cua ma tran: ");
    scanf("%d", &n);
    printf("Nhap so cot cua ma tran: ");
    scanf("%d", &m);

    int choice;
    do {
        // In menu
        printf("\nMENU\n");
        printf("1. Nhap gia tri cac phan tu cua mang\n");
        printf("2. In gia tri cac phan tu cua mang theo ma tran\n");
        printf("3. In ra cac phan tu o goc theo ma tran\n");
        printf("4. In ra cac phan tu nam tren duong bien theo ma tran\n");
        printf("5. In ra cac phan tu nam tren duong cheo chinh va cheo phu theo ma tran\n");
        printf("6. In ra cac phan tu la so nguyen to theo ma tran\n");
        printf("7. Thoat\n");
        printf("Chon chuc nang (1-7): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                inputMatrix(arr, n, m);
                break;
            case 2:
                printMatrix(arr, n, m);
                break;
            case 3:
                printCorners(arr, n, m);
                break;
            case 4:
                printBorder(arr, n, m);
                break;
            case 5:
                printDiagonals(arr, n, m);
                break;
            case 6:
                printPrimes(arr, n, m);
                break;
            case 7:
                printf("Thoat chuong trinh.\n");
                break;
            default:
                printf("Lua chon khong hop le. Vui long chon lai.\n");
        }
    } while (choice != 7);

    return 0;
}

