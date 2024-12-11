#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// Ham nhap mang
void inputArray(int arr[], int* n) {
    printf("Nhap so phan tu cua mang: ");
    scanf("%d", n);
    printf("Nhap cac phan tu cua mang:\n");
    for (int i = 0; i < *n; i++) {
        printf("arr[%d] = ", i);
        scanf("%d", &arr[i]);
    }
}

// Ham in mang
void printArray(int arr[], int n) {
    printf("Cac phan tu trong mang la:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Ham them phan tu vao vi tri chi dinh
void insertElement(int arr[], int* n, int pos, int value) {
    if (*n >= MAX) {
        printf("Mang da day, khong the them phan tu.\n");
        return;
    }
    for (int i = *n; i > pos; i--) {
        arr[i] = arr[i - 1];
    }
    arr[pos] = value;
    (*n)++;
}

// Ham sua phan tu tai vi tri chi dinh
void editElement(int arr[], int n, int pos, int value) {
    if (pos < 0 || pos >= n) {
        printf("Vi tri khong hop le.\n");
        return;
    }
    arr[pos] = value;
}

// Ham xoa phan tu tai vi tri chi dinh
void deleteElement(int arr[], int* n, int pos) {
    if (pos < 0 || pos >= *n) {
        printf("Vi tri khong hop le.\n");
        return;
    }
    for (int i = pos; i < *n - 1; i++) {
        arr[i] = arr[i + 1];
    }
    (*n)--;
}

// Ham sap xep mang tang dan
void sortAscending(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] > arr[j]) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

// Ham sap xep mang giam dan
void sortDescending(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] < arr[j]) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

// Ham tim kiem tuyen tinh
int linearSearch(int arr[], int n, int value) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == value) {
            return i; 
        }
    }
    return -1; 
}

// Ham tim kiem nhi phan (mang phai duoc sap xep)
int binarySearch(int arr[], int n, int value) {
    int left = 0, right = n - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == value) {
            return mid;
        } else if (arr[mid] < value) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return -1;
}

int main() {
    int arr[MAX], n = 0;
    int choice, pos, value, searchResult;
    
    do {
        // In menu
        printf("\nMENU\n");
        printf("1. Nhap so phan tu va gia tri cac phan tu\n");
        printf("2. In ra gia tri cac phan tu dang quan li\n");
        printf("3. Them mot phan tu vao vi tri chi dinh\n");
        printf("4. Sua mot phan tu o vi tri chi dinh\n");
        printf("5. Xoa mot phan tu o vi tri chi dinh\n");
        printf("6. Sap xep cac phan tu\n");
        printf("   a. Giam dan\n");
        printf("   b. Tang dan\n");
        printf("7. Tim kiem phan tu\n");
        printf("   a. Tim kiem tuyen tinh\n");
        printf("   b. Tim kiem nhi phan\n");
        printf("8. Thoat\n");
        printf("Chon chuc nang (1-8): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                inputArray(arr, &n);
                break;
            case 2:
                printArray(arr, n);
                break;
            case 3:
                printf("Nhap vi tri (0 den %d) va gia tri can them: ", n);
                scanf("%d %d", &pos, &value);
                if (pos < 0 || pos > n) {
                    printf("Vi tri khong hop le.\n");
                } else {
                    insertElement(arr, &n, pos, value);
                }
                break;
            case 4:
                printf("Nhap vi tri (0 den %d) va gia tri moi: ", n - 1);
                scanf("%d %d", &pos, &value);
                if (pos < 0 || pos >= n) {
                    printf("Vi tri khong hop le.\n");
                } else {
                    editElement(arr, n, pos, value);
                }
                break;
            case 5:
                printf("Nhap vi tri (0 den %d) can xoa: ", n - 1);
                scanf("%d", &pos);
                if (pos < 0 || pos >= n) {
                    printf("Vi tri khong hop le.\n");
                } else {
                    deleteElement(arr, &n, pos);
                }
                break;
            case 6:
                printf("Chen kieu sap xep:\n");
                printf("a. Giam dan\n");
                printf("b. Tang dan\n");
                printf("Chen kieu sap xep (a/b): ");
                char sortChoice;
                getchar();  
                scanf("%c", &sortChoice);
                if (sortChoice == 'a') {
                    sortDescending(arr, n);
                } else if (sortChoice == 'b') {
                    sortAscending(arr, n);
                } else {
                    printf("Lua chon khong hop le.\n");
                }
                break;
            case 7:
                printf("Nhap phan tu can tim: ");
                scanf("%d", &value);
                printf("Chon phuong thuc tim kiem:\n");
                printf("a. Tim kiem tuyen tinh\n");
                printf("b. Tim kiem nhi phan\n");
                char searchChoice;
                getchar();  
                scanf("%c", &searchChoice);
                if (searchChoice == 'a') {
                    searchResult = linearSearch(arr, n, value);
                } else if (searchChoice == 'b') {
                    searchResult = binarySearch(arr, n, value);
                } else {
                    printf("Lua chon khong hop le.\n");
                    continue;
                }
                if (searchResult == -1) {
                    printf("Khong tim thay phan tu %d.\n", value);
                } else {
                    printf("Phan tu %d tim thay tai vi tri %d.\n", value, searchResult);
                }
                break;
            case 8:
                printf("Thoat chuong trinh.\n");
                break;
            default:
                printf("Lua chon khong hop le. Vui long chon lai.\n");
        }
    } while (choice != 8);

    return 0;
}

