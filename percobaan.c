#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Pembayaran {
    char nama[200];
    char nim[11];
    int ukt;
    int nominal;
    struct Pembayaran *next;
} Pembayaran;

int main() {
    int pilihan;
    char keluar;
    Pembayaran *head = NULL, *baru = NULL, *tail = NULL;
    int count = 0, total_bayar;
    int maks_antrian; 

    printf("Program Antrian Pembayaran UKT\n");
    printf("Input Maks Antrian dalam 1 waktu ");
    scanf("%d", &maks_antrian);

    while (1) {
        printf("\n\nMenu : \n1. Tambah Antrian\n2. Proses Pembayaran\n3. Lihat Antrian\n4. Keluar\n");
        scanf("%d", &pilihan);

        switch (pilihan) {
            case 1:
                    if (count != maks_antrian)
                    {
                        baru = (Pembayaran*)malloc(sizeof(Pembayaran));
                        if (baru == NULL) {
                            printf("Gagal mengalokasikan memori.");
                            exit(1);
                        }

                        printf("\nInput Data Mahasiswa\n");
                        printf("Nama : ");
                        getchar();
                        fgets(baru->nama, sizeof(baru->nama), stdin);
                        strtok(baru->nama, "\n");
                        printf("Nim : ");
                        fgets(baru->nim, sizeof(baru->nim), stdin);
                        strtok(baru->nim, "\n");
                        printf("UKT : ");
                        scanf("%d", &baru->ukt);
                        printf("Nominal : ");
                        scanf("%d", &baru->nominal);
                        printf("\nData Berhasil Ditambahkan\n");

                        baru->next = NULL;

                        if (head == NULL) {
                            head = baru;
                            tail = baru;
                        } else {
                            tail->next = baru;
                            tail = tail->next;
                        }
                        count++;
                    }else
                    {
                        printf("\njumlah antrian sudah mencapai batas Maksimum yaitu %d", count);
                    }
                break;
            case 2:
                if (head == NULL)
                {
                    printf("\nAntrian Kosong\n");
                }
                else
                {   
                    struct Pembayaran *temp = head;
                    printf("\nData Mahasiswa\n");
                    printf("Nama : %s\n", temp->nama );
                    printf("Nim : %s\n", temp->nim );
                    printf("UKT : %d\n", temp->ukt );
                    printf("Nominal : Rp.%d\n", temp->nominal );
                    printf("Masukan Nominal Bayar :");
                    scanf("%d", &total_bayar);
                    temp->nominal -= total_bayar;
                    while (temp->nominal > 0)
                    {
                        printf("\nUang Yang Anda Masukan Kurang : Rp.%d\n Masukan Nominal Bayar : ", temp->nominal );
                        scanf("%d", &total_bayar);
                        temp->nominal -= total_bayar;
                    }
                    if (temp->nominal == 0)
                    {
                        printf("Uang yang Anda Masukan Sudah Pas\n");
                    }else if (temp->nominal < 0)
                    {
                        printf("\nKembalian : %d \n", abs(temp->nominal));
                    }
                    count--;
                    head = temp->next;
                }
            break;
            case 3:
                if (head == NULL)
                {
                    printf("\nAntrian Kosong\n");
                }
                else
                {
                    struct Pembayaran *temp = head;
                    printf("\nDaftar Antrian\n");
                    printf("| %-40s | %-11s | %3s | %-16s | \n\n", "Nama", "NIM", "UKT", "Nominal");
                    while (temp != NULL)
                    {
                        printf("| %-40s | %-11s | %-3d | Rp.%-13d |\n", temp->nama, temp->nim, temp->ukt, temp->nominal);
                        temp = temp->next;
                    }
                }
            break;
            case 4:
                printf("\nApakah Anda Yakin (Y/T) ?");
                scanf(" %c", &keluar);
                if (keluar == 'y' || keluar == 'Y') {
                    printf("\nTerimaksih\n");
                    exit(0);
                } else {
                    break;
                }
            default:
                printf("\nPilihan Tidak Tersedia\n");
                break;
        }
    }

    return 0;
}
