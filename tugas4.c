#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char judul[200];
    int halaman;
    char penulis[200];
} Buku;

int main() {
    int n, jumlah_buku = 0, pilihan;
    char konfirmasi;

    printf("Program Tumpukan Buku:\n");
    printf("<================================================================================================> \n");
    printf("Ketik Jumlah Maksimum Tumpukan: ");
    scanf("%d", &n);
    Buku Buku[n];

     do {
        printf("\n Menu: \n");
        printf("1. Tambah Buku \n");
        printf("2. Ambil Buku \n");
        printf("3. Keluar \n");
        printf("\n Pilihan: ");
        scanf("%d", &pilihan);

         switch (pilihan) {
            case 1:
                if (jumlah_buku < n) {
                    getchar();
                    printf("\nMasukkan Judul Buku: ");
                    fgets(Buku[jumlah_buku].judul, sizeof(Buku[jumlah_buku].judul), stdin);
                    strtok(Buku[jumlah_buku].judul, "\n");
                    printf("Jumlah halaman: ");
                    scanf("%d", &Buku[jumlah_buku].halaman);
                    getchar();
                    printf("Nama Penulis: ");
                    fgets(Buku[jumlah_buku].penulis, sizeof(Buku[jumlah_buku].penulis), stdin);
                    strtok(Buku[jumlah_buku].penulis, "\n");
                    printf("Buku berhasil ditambahkan!\n");
                    jumlah_buku++;
                } else {
                    printf("Tumpukan buku sudah penuh!\n");
                }
                break;
            case 2:
                if (jumlah_buku > 0) {
                    printf("Apakah Anda yakin (Y/T): ");
                    scanf(" %c", &konfirmasi);
                    if (konfirmasi == 'Y' || konfirmasi == 'y') {
                        printf("Buku dengan judul %s telah diambil\n", Buku[jumlah_buku - 1].judul);
                        jumlah_buku--;
                    }
                } else {
                    printf("Tidak ada buku yang bisa diambil.\n");
                }
                break;
            case 3:
                printf("Apakah Anda yakin (Y/T): ");
                scanf(" %c", &konfirmasi);
                if (konfirmasi == 'Y' || konfirmasi == 'y') {
                    printf("<================================================================================================> \n");
                    printf("Terima kasih\n");
                    exit(0);
                }
                break;
            default:
                printf("Pilihan tidak valid.\n");
        }
    } while (1);

    return 0;
}