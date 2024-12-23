#include <stdio.h>
struct Sach {
    char id[20];
    char nameBook[50];
    char author[50];
    float price;
    char category[30];
};

struct Sach danhSachSach[100];
int soLuongSach = 0;

void nhapSach(void) {
    printf("Nhap so luong sach: ");
    scanf("%d", &soLuongSach);

    for (int i = 0; i < soLuongSach; i++) {
        printf("Nhap thong tin sach thu %d:\n", i + 1);
        printf("Ma sach: ");
        scanf("%s", danhSachSach[i].id);
        printf("Ten sach: ");
        scanf("%s", danhSachSach[i].nameBook);
        printf("Tac gia: ");
        scanf("%s", danhSachSach[i].author);
        printf("Gia tien: ");
        scanf("%f", &danhSachSach[i].price);
        printf("The loai: ");
        scanf("%s", danhSachSach[i].category);
    }
}

void hienThiSach(void) {
    printf("Danh sach sach:\n");
    for (int i = 0; i < soLuongSach; i++) {
        printf("%d. Ma sach: %s, Ten sach: %s, Tac gia: %s, Gia tien: %.2f, The loai: %s\n",
               i + 1, danhSachSach[i].id, danhSachSach[i].nameBook, danhSachSach[i].author,
               danhSachSach[i].price, danhSachSach[i].category);
    }
}

void themSach(int viTri, struct Sach sachMoi) {
    if (viTri < 0 || viTri > soLuongSach || soLuongSach >= 100) {
        printf("Vi tri khong hop le hoac danh sach da day.\n");
        return;
    }
    for (int i = soLuongSach; i > viTri; i--) {
        danhSachSach[i] = danhSachSach[i - 1];
    }
    danhSachSach[viTri] = sachMoi;
    soLuongSach++;
    printf("Them sach thanh cong!\n");
}

void xoaSachTheoMa(char *maSach) {
    for (int i = 0; i < soLuongSach; i++) {
        if (strcmp(danhSachSach[i].id, maSach) == 0) {
            for (int j = i; j < soLuongSach - 1; j++) {
                danhSachSach[j] = danhSachSach[j + 1];
            }
            soLuongSach--;
            printf("Xoa sach thanh cong!\n");
            return;
        }
    }
    printf("Khong tim thay sach voi ma %s.\n", maSach);
}

void capNhatThongTinSach(char *maSach) {
    for (int i = 0; i < soLuongSach; i++) {
        if (strcmp(danhSachSach[i].id, maSach) == 0) {
            printf("Nhap ten sach moi: ");
            scanf("%s", danhSachSach[i].nameBook);
            printf("Nhap tac gia moi: ");
            scanf("%s", danhSachSach[i].author);
            printf("Nhap gia tien moi: ");
            scanf("%f", &danhSachSach[i].price);
            printf("Nhap the loai moi: ");
            scanf("%s", danhSachSach[i].category);
            printf("Cap nhat thong tin sach thanh cong!\n");
            return;
        }
    }
    printf("Khong tim thay sach voi ma %s.\n", maSach);
}

void sapXepSach(int tangDan) {
    for (int i = 0; i < soLuongSach - 1; i++) {
        for (int j = i + 1; j < soLuongSach; j++) {
            if ((tangDan && danhSachSach[i].price > danhSachSach[j].price) || (!tangDan && danhSachSach[i].price < danhSachSach[j].price)) {
                struct Sach temp = danhSachSach[i];
                danhSachSach[i] = danhSachSach[j];
                danhSachSach[j] = temp;
            }
        }
    }
    printf("Sap xep sach thanh cong!\n");
}

void timKiemSachTheoTen(char *tenSach) {
    for (int i = 0; i < soLuongSach; i++) {
        if (strcmp(danhSachSach[i].nameBook, tenSach) == 0) {
            printf("%d. Ma sach: %s, Ten sach: %s, Tac gia: %s, Gia tien: %.2f, The loai: %s\n",
                   i + 1, danhSachSach[i].id, danhSachSach[i].nameBook, danhSachSach[i].author,
                   danhSachSach[i].price, danhSachSach[i].category);
            return;
        }
    }
    printf("Khong tim thay sach voi ten %s.\n", tenSach);
}

int main(void) {
    int choice;
    while (1) {
        printf("\nMENU\n");
        printf("1. Nhap so luong va thong tin sach\n");
        printf("2. Hien thi thong tin sach\n");
        printf("3. Them sach vao vi tri\n");
        printf("4. Xoa sach theo ma sach\n");
        printf("5. Cap nhat thong tin sach theo ma sach\n");
        printf("6. Sap xep sach theo gia (tang/giam)\n");
        printf("7. Tim kiem sach theo ten sach\n");
        printf("8. Thoat \n");
        printf("Lua chon cua ban: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                nhapSach();
                break;
            case 2:
                hienThiSach();
                break;
            case 3: {
                int viTri;
                struct Sach sachMoi;
                printf("Nhap vi tri: ");
                scanf("%d", &viTri);
                if (viTri <= soLuongSach) {
                    printf("Nhap ma sach: ");
                    scanf("%s", sachMoi.id);
                    printf("Nhap ten sach: ");
                    scanf("%s", sachMoi.nameBook);
                    printf("Nhap tac gia: ");
                    scanf("%s", sachMoi.author);
                    printf("Nhap gia tien: ");
                    scanf("%f", &sachMoi.price);
                    printf("Nhap the loai: ");
                    scanf("%s", sachMoi.category);
                    themSach(viTri - 1, sachMoi);
                } else {
                    printf("Vi tri khong hop le.\n");
                }
                break;
            }
            case 4: {
                char maSach[20];
                printf("Nhap ma sach ma ban can xoa: ");
                scanf("%s", maSach);
                xoaSachTheoMa(maSach);
                break;
            }
            case 5: {
                char maSach[20];
                printf("Nhap ma sach ma ban can cap nhat: ");
                scanf("%s", maSach);
                capNhatThongTinSach(maSach);
                break;
            }
            case 6: {
                printf("a. Giam dan theo gia\n");
                printf("b. Tang dan theo gia\n");
                char subChoice;
                scanf(" %c", &subChoice);
                if (subChoice == 'a') {
                    sapXepSach(0);
                } else if (subChoice == 'b') {
                    sapXepSach(1);
                } else {
                    printf("Lua chon cua ban khong hop le.\n");
                }
                break;
            }
            case 7: {
                char tenSach[50];
                printf("Nhap ten sach ban can tim: ");
                scanf("%s", tenSach);
                timKiemSachTheoTen(tenSach);
                break;
            }
            case 8:
                printf("Thoat chuong trinh.\n");
                return 0;
            default:
                printf("Lua chon cua ban khong hop le. Vui long thu lai.\n");
        }
    }
}

