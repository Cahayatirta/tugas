    #include <stdio.h>
    #include <string.h>

    struct kompetisi
    {
        char nama[250];
        char no_peserta[11];
        int n_teori,n_praktek,total;
        float rata_rata;
    };

    int main() {
        int n;

        // meminta jumlah data yang mau dimasukan
        printf("Masukan Jumlah Peserta Kompetisi : ");
        scanf("%d", &n);

        // memanggil struct
        struct kompetisi Peserta[n];

        // lopping untuk mendapatkan data
        for (int i = 0; i < n; i++)
        {
            printf("\n Peserta ke-%d: \n", i +1);
            getchar();
            printf("Masukan Nama : ");
            fgets(Peserta[i].nama, sizeof(Peserta[i].nama), stdin);
            strtok(Peserta[i].nama, "\n");
            printf("Masukan No Peserta : ");
            scanf("%s", Peserta[i].no_peserta);
            printf("Masukan Nilai Teori : ");
            scanf("%d", &Peserta[i].n_teori);
            printf("Masukan Nilai Praktek : ");
            scanf("%d", &Peserta[i].n_praktek);
        }
        
        // lopping untuk menghitung rata rata dan meng print data
        for (int i = 0; i < n; i++)
        {
            printf("\n Peserta ke-%d \n", i + 1);
            printf("Nama : %s \n", Peserta[i].nama);
            printf("No Peserta : %s \n", Peserta[i].no_peserta);
            printf("Nilai Praktek : %d \n", Peserta[i].n_praktek);
            printf("Nilai Teori : %d \n", Peserta[i].n_teori);
            Peserta[i].total = Peserta[i].n_praktek + Peserta[i].n_teori;
            printf("Total Nilai : %d \n", Peserta[i].total);
            Peserta[i].rata_rata = Peserta[i].total / 2 ;
            printf("Rata Rata : %.2f \n", Peserta[i].rata_rata);
            if (Peserta[i].rata_rata >= 60)
            {
                printf("Status = Lulus \n");
            }else
            {
                printf("Status = Gagal \n");
            }

        }

        
        return 0;
    }
