#include <stdio.h>
#include <string.h>

struct nilai
{
    char nama[20];
    char nim[11];
    float uts,uas,tugas,kuis,rata_rata;
};

int main() {
    int n;

    // meminta jumlah data yang mau dimasukan
    printf("Masukan Jumlah Mahasiswa:");
    scanf("%d", &n);

    // memanggil struct
    struct nilai KelasD[n];
    
    // integer yang dibuat penomeran di data
    int data = 1;

    // lopping untuk mendapatkan data
    for (int i = 0; i < n; i++)
    {
        printf("\nMahasiswa ke-%d: \n", data);
        getchar();
        printf("Masukan Nama : ");
        fgets(KelasD[i].nama, sizeof(KelasD[i].nama), stdin);
        strtok(KelasD[i].nama, "\n");
        printf("Masukan Nim : ");
        scanf("%s", KelasD[i].nim);
        printf("Masukan Nilai UTS : ");
        scanf("%f", &KelasD[i].uts);
        printf("Masukan Nilai UAS : ");
        scanf("%f", &KelasD[i].uas);
        printf("Masukan Nilai Tugas : ");
        scanf("%f", &KelasD[i].tugas);
        printf("Masukan Nilai Kuis : ");
        scanf("%f", &KelasD[i].kuis);
        data++;
    }
    
    // lopping untuk menghitung rata rata dan meng print data
    for (int i = 0; i < n; i++)
    {
        printf("\nMahasiswa ke-%d \n", i + 1);
        printf("Nama : %s \n", KelasD[i].nama);
        printf("NIM : %s \n", KelasD[i].nim);
        printf("UAS : %f \n", KelasD[i].uas);
        printf("UTS : %f \n", KelasD[i].uts);
        printf("Tugas : %f \n", KelasD[i].tugas);
        printf("Kuis : %f \n", KelasD[i].kuis);
        KelasD[i].uas = KelasD[i].uas * 30 / 100;
        KelasD[i].uts = KelasD[i].uts * 30 / 100;
        KelasD[i].tugas = KelasD[i].tugas * 20 / 100;
        KelasD[i].kuis = KelasD[i].kuis * 20 / 100;
        KelasD[i].rata_rata = KelasD[i].uas + KelasD[i].uts + KelasD[i].tugas + KelasD[i].kuis;
        printf("Rata Rata : %f \n", KelasD[i].rata_rata);
    }


    printf("\nHasil : \n");
    // meng print hasil
    for (int i = 0; i < n; i++)
    {
        if (KelasD[i].rata_rata >= 80 && KelasD[i].rata_rata <= 100)
        {
            printf("%s Mendapatkan Nilai A \n", KelasD[i].nama);
        }else if (KelasD[i].rata_rata >= 65 && KelasD[i].rata_rata < 80)
        {
            printf("%s Mendapatkan Nilai B \n", KelasD[i].nama);
        }else if (KelasD[i].rata_rata >= 50 && KelasD[i].rata_rata < 65)
        {
            printf("%s Mendapatkan Nilai B \n", KelasD[i].nama);
        }
    }


    return 0;
}
