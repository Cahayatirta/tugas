#include <stdio.h>
#include <string.h>


struct Pasien
{
    char nama[250];
    int tinggi, berat;
};


int main() {
    int n, berat_terendah,tinggi_terendah;
    int nama_tinggi_terendah, nama_berat_terendah;

    printf("Masukan Jumlah Data: ");
    scanf("%d", &n);
    struct Pasien kelasD[n];

    for (int i = 0; i < n; i++)
    {
        printf("Data %d \n", i + 1 );
        getchar();
        printf("nama : ");
        fgets(kelasD[i].nama, sizeof(kelasD[i].nama), stdin);
        strtok(kelasD[i].nama, "\n");
        printf("tinggi : ");
        scanf("%d", &kelasD[i].tinggi);
        printf("berat : ");
        scanf("%d", &kelasD[i].berat);
        if (kelasD[0].tinggi < kelasD[i].tinggi )
        {
            tinggi_terendah = kelasD[0].tinggi;
            nama_tinggi_terendah = 0;
        }else
        {
            tinggi_terendah = kelasD[i].tinggi;
            nama_tinggi_terendah = i;
        }
        if (kelasD[0].berat < kelasD[i].berat )
        {
            berat_terendah = kelasD[0].berat;
            nama_berat_terendah = 0;
        }else
        {
            berat_terendah = kelasD[i].berat;
            nama_berat_terendah = i;
        }
    }

// print
printf("berat terendah : %d (%s)\n", berat_terendah, kelasD[nama_berat_terendah].nama );
printf("tinggi terendah : %d (%s)\n", tinggi_terendah, kelasD[nama_tinggi_terendah].nama);
return 0;
}

