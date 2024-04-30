#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Pembayaran
{
    char nama[200];
    char nim[11];
    int ukt;
    int nominal;
};


int main() {
    int maks_antrian, maks_data, pilihan,status = 0, data_depan = -1, data_belakang = -1, total_bayar = 0;
    printf("Program Antrian Pembayaran UKT\n");
    printf("Input maks antrian : ");
    scanf("%d", &maks_antrian);
    printf("Input maks data : ");
    scanf("%d", &maks_data);
    maks_data += maks_antrian;
    struct Pembayaran Data[maks_data];

    while (1)
    {
        printf("\nMenu : \n1. Tambah Antrian\n2. Proses Pembayaran\n3. Lihat Antrian\n4. Keluar\n");
        scanf("%d", &pilihan);
        switch (pilihan)
        {
        case 1:
            if (status >= maks_antrian)
            {
                printf("jumlah antiran sudah mencapai batas maksimul yaitu %d", status);
            }else
            {
                if (data_belakang + 1 == maks_data)
                {
                    printf("Sudah Mencapai batas data harian");
                    break;
                }
                printf("Input Data Mahasiswa\n");
                getchar();
                printf("Nama : ");
                fgets(Data[data_belakang + 1].nama, sizeof(Data[data_belakang + 1].nama), stdin);
                strtok(Data[data_belakang + 1].nama, "\n");
                printf("Nim : ");
                fgets(Data[data_belakang + 1].nim, sizeof(Data[data_belakang + 1].nim), stdin);
                strtok(Data[data_belakang + 1].nim, "\n");
                printf("UKT : ");
                scanf("%d", &Data[data_belakang + 1].ukt);
                printf("Nominal : ");
                scanf("%d", &Data[data_belakang + 1].nominal);
                printf("\nData Berhasil Ditambahkan\n");
                data_belakang++;
                status++;
            }
            break;
        case 2:
                if (status != 0)
                {
                    printf("Data mahasiswa\n");
                    printf("Nama : %s\n", Data[data_depan + 1].nama);
                    printf("Nim : %s\n", Data[data_depan + 1].nim);
                    printf("UKT : %d\n", Data[data_depan + 1].ukt);
                    printf("Nominal : %d\n", Data[data_depan + 1].nominal);
                    printf("Masukan Nominal Bayar : ");
                    scanf("%d", &total_bayar);
                    Data[data_depan + 1].nominal = total_bayar - Data[data_depan + 1].nominal;

                    while (Data[data_depan + 1].nominal < 0)
                    {
                        printf("\nUang yang anda masukan kurang %d\nMasukan Nominal Bayar : ", abs(Data[data_depan + 1].nominal));
                        scanf("%d", &total_bayar);
                        Data[data_depan + 1].nominal = total_bayar + Data[data_depan + 1].nominal;
                    }
                    if (Data[data_depan + 1].nominal == 0) 
                    {
                        printf("Uang yang anda masukan sudah pas\n");
                        data_depan++;
                        status--;
                    }else if (Data[data_depan + 1].nominal > 0)
                    {
                        printf("Kembalian : %d \n", Data[data_depan + 1].nominal);
                        data_depan++;
                        status--;
                    }
                }else
                {
                    printf("Antiran Kosong\n");
                }
            break;
        default:
            break;
        }
    }
     

    return 0;
}