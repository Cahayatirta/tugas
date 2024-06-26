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
    int maks_antrian, pilihan,status = 0, data_depan = -1, data_belakang = -1, total_bayar = 0, print;
    char keluar;
    printf("Program Antrian Pembayaran UKT\n");
    printf("Input maks antrian : ");
    scanf("%d", &maks_antrian);
    struct Pembayaran Data[maks_antrian];

    while (1)
    {
        printf("\n\nMenu : \n1. Tambah Antrian\n2. Proses Pembayaran\n3. Lihat Antrian\n4. Keluar\n");
        scanf("%d", &pilihan);
        switch (pilihan)
        {
        // CASE 1 tambah antiran
        case 1:
            if (status >= maks_antrian)
            {
                printf("\njumlah antiran sudah mencapai batas Maksimum yaitu %d", status);
            }else
            {
                if (data_belakang == maks_antrian)
                {
                    data_belakang = -1;
                }
                data_belakang++;
                printf("\nInput Data Mahasiswa\n");
                getchar();
                printf("Nama : ");
                fgets(Data[data_belakang].nama, sizeof(Data[data_belakang].nama), stdin);
                strtok(Data[data_belakang].nama, "\n");
                printf("Nim : ");
                fgets(Data[data_belakang].nim, sizeof(Data[data_belakang].nim), stdin);
                strtok(Data[data_belakang].nim, "\n");
                printf("UKT : ");
                scanf("%d", &Data[data_belakang].ukt);
                printf("Nominal : ");
                scanf("%d", &Data[data_belakang].nominal);
                printf("\nData Berhasil Ditambahkan\n");
                status++;
            }
            break;
        case 2:
                if (status != 0)
                {
                    data_depan++;
                    printf("\nData mahasiswa\n");
                    printf("Nama : %s\n", Data[data_depan].nama);
                    printf("Nim : %s\n", Data[data_depan].nim);
                    printf("UKT : %d\n", Data[data_depan].ukt);
                    printf("Nominal : %d\n", Data[data_depan].nominal);
                    printf("Masukan Nominal Bayar : ");
                    scanf("%d", &total_bayar);
                    Data[data_depan].nominal -= total_bayar ;

                    while (Data[data_depan].nominal > 0)
                    {
                        printf("\nUang yang anda masukan kurang %d\nMasukan Nominal Bayar : ", Data[data_depan].nominal);
                        scanf("%d", &total_bayar);
                        Data[data_depan].nominal -= total_bayar ;
                    }
                    if (Data[data_depan].nominal == 0) 
                    {
                        printf("\nUang yang anda masukan sudah pas\n");
                    }else if (Data[data_depan].nominal < 0)
                    {
                        printf("\nKembalian : %d \n", abs(Data[data_depan].nominal));
                    }
                }else
                {
                    printf("\nAntrian Kosong\n");
                }
            status--;
            break;
        case 3:
            if (status == 0)
            {
                printf("\nAntrian Kosong\n");
            }else{
                print = 0;
                printf("\nDaftar Antrian\n");
                printf("| %-40s | %-11s | %3s | %-16s | \n\n", "Nama", "NIM", "UKT", "Nominal");
                for (int i = data_depan + 1; print < status + 1 ; i++)
                {
                    if (i == maks_antrian && i != status)
                    {
                        i = 0;
                    }
                    printf("| %-40s | %-11s | %-3d | Rp.%-13d |\n", Data[i].nama, Data[i].nim, Data[i].ukt, Data[i].nominal);
                    print ++;
                }
            }
        break;
            
        case 4:
            printf("\nApakah Anda Yakin (Y/T) ?");
            scanf(" %c", &keluar);
            if (keluar == 'y' || keluar == 'Y')
            {
                printf("\nTerimaksih\n");
                exit(0);
            }else
            {
                break;
            }
        default:
            printf("\nPilihan Tidak Tersedia\n");
            break;
        }
    }
     

    return 0;
}