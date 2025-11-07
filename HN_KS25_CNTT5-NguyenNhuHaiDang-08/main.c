#include <stdio.h>

int main() {
    int arr[100];
    int n = 0;   // số phần tử hiện tại
    int choice;
    int i, j, temp, value, index, found;

    do {
        printf("\n===== MENU =====\n");
        printf("1. Nhap so luong va gia tri tung phan tu\n");
        printf("2. In ra cac gia tri trong mang\n");
        printf("3. Tinh tong cac so nguyen to trong mang\n");
        printf("4. In ra cac phan tu o vi tri le trong mang\n");
        printf("5. Them mot phan tu vao cuoi mang\n");
        printf("6. Xoa phan tu tai vi tri k (nguoi dung nhap)\n");
        printf("7. Sap xep mang theo thu tu giam dan (bubble sort)\n");
        printf("8. Kiem tra su ton tai cua phan tu (Linear Search)\n");
        printf("9. In ra cac phan tu xuat hien dung 1 lan trong mang\n");
        printf("10. Cap nhat tat ca so am trong mang thanh 0\n");
        printf("0. Thoat chuong trinh\n");
        printf("=================\n");
        printf("Nhap lua chon: ");
        scanf("%d", &choice);

        switch(choice) {

            case 1:
                printf("Nhap so luong phan tu: ");
                scanf("%d", &n);
                if (n <= 0 || n > 100) {
                    printf("So luong khong hop le!\n");
                    n = 0;
                    break;
                }
                for (i = 0; i < n; i++) {
                    printf("arr[%d] = ", i);
                    scanf("%d", &arr[i]);
                }
                break;

            case 2:
                if (n == 0) {
                    printf("Mang rong!\n");
                    break;
                }
                printf("Cac phan tu trong mang: ");
                for (i = 0; i < n; i++)
                    printf("%d ", arr[i]);
                printf("\n");
                break;

            case 3:
                if (n == 0) {
                    printf("Mang rong!\n");
                    break;
                }
                {
                    int sum = 0;
                    for (i = 0; i < n; i++) {
                        if (arr[i] < 2) continue;
                        int prime = 1;
                        for (j = 2; j * j <= arr[i]; j++) {
                            if (arr[i] % j == 0) {
                                prime = 0;
                                break;
                            }
                        }
                        if (prime) sum += arr[i];
                    }
                    printf("Tong cac so nguyen to = %d\n", sum);
                }
                break;

            case 4:
                if (n == 0) {
                    printf("Mang rong!\n");
                    break;
                }
                printf("Cac phan tu o vi tri le: ");
                for (i = 1; i < n; i += 2)
                    printf("%d ", arr[i]);
                printf("\n");
                break;

            case 5:
                if (n >= 100) {
                    printf("Mang day!\n");
                    break;
                }
                printf("Nhap gia tri muon them: ");
                scanf("%d", &value);
                arr[n] = value;
                n++;
                printf("Da them vao cuoi mang.\n");
                break;

            case 6:
                if (n == 0) {
                    printf("Mang rong!\n");
                    break;
                }
                printf("Nhap vi tri k can xoa: ");
                scanf("%d", &index);
                if (index < 0 || index >= n) {
                    printf("Vi tri khong hop le!\n");
                    break;
                }
                for (i = index; i < n - 1; i++)
                    arr[i] = arr[i + 1];
                n--;
                printf("Da xoa phan tu tai vi tri %d.\n", index);
                break;

            case 7:
                if (n == 0) {
                    printf("Mang rong!\n");
                    break;
                }
                for (i = 0; i < n - 1; i++) {
                    for (j = 0; j < n - 1 - i; j++) {
                        if (arr[j] < arr[j + 1]) { // Đổi dấu để giảm dần
                            temp = arr[j];
                            arr[j] = arr[j + 1];
                            arr[j + 1] = temp;
                        }
                    }
                }
                printf("Mang da duoc sap xep giam dan.\n");
                break;

            case 8:
                if (n == 0) {
                    printf("Mang rong!\n");
                    break;
                }
                printf("Nhap gia tri can tim: ");
                scanf("%d", &value);
                found = 0;
                for (i = 0; i < n; i++) {
                    if (arr[i] == value) {
                        printf("Phan tu %d ton tai o vi tri %d\n", value, i);
                        found = 1;
                        break;
                    }
                }
                if (!found)
                    printf("Khong tim thay phan tu!\n");
                break;

            case 9:
                if (n == 0) {
                    printf("Mang rong!\n");
                    break;
                }
                printf("Cac phan tu xuat hien dung 1 lan: ");
                for (i = 0; i < n; i++) {
                    int count = 0;
                    for (j = 0; j < n; j++) {
                        if (arr[i] == arr[j])
                            count++;
                    }
                    if (count == 1)
                        printf("%d ", arr[i]);
                }
                printf("\n");
                break;

            case 10:
                if (n == 0) {
                    printf("Mang rong!\n");
                    break;
                }
                for (i = 0; i < n; i++) {
                    if (arr[i] < 0)
                        arr[i] = 0;
                }
                printf("Da cap nhat tat ca so am thanh 0.\n");
                break;

            case 0:
                printf("Thoat chuong trinh.\n");
                break;

            default:
                printf("Lua chon khong hop le!\n");
        }

    } while (choice != 0);

    return 0;
}
