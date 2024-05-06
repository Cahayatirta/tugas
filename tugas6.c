#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Pembayaran
{
    char nama[200];
    char nim[11];
    int ukt;
    int nominal;
    struct Pembayaran *next;
};

struct Queue
{
    struct Pembayaran *front, *rear;
    int count;
};

struct Queue *createQueue()
{
    struct Queue *q = (struct Queue *)malloc(sizeof(struct Queue));
    q->front = q->rear = NULL;
    q->count = 0;
    return q;
}

void enqueue(struct Queue *q, struct Pembayaran data)
{
    struct Pembayaran *temp = (struct Pembayaran *)malloc(sizeof(struct Pembayaran));
    strcpy(temp->nama, data.nama);
    strcpy(temp->nim, data.nim);
    temp->ukt = data.ukt;
    temp->nominal = data.nominal;
    temp->next = NULL;
    if (q->rear == NULL)
    {
        q->front = q->rear = temp;
    }
    else
    {
        q->rear->next = temp;
        q->rear = temp;
    }
    q->count++;
}

void dequeue(struct Queue *q)
{
    if (q->front == NULL)
        return;
    struct Pembayaran *temp = q->front;
    q->front = q->front->next;
    free(temp);
    q->count--;
}

void display(struct Queue *q)
{
    if (q->front == NULL)
    {
        printf("\nAntrian Kosong\n");
        return;
    }
    struct Pembayaran *temp = q->front;
    printf("\nDaftar Antrian\n");
    printf("| %-40s | %-11s | %3s | %-16s | \n\n", "Nama", "NIM", "UKT", "Nominal");
    while (temp != NULL)
    {
        printf("| %-40s | %-11s | %-3d | Rp.%-13d |\n", temp->nama, temp->nim, temp->ukt, temp->nominal);
        temp = temp->next;
    }
}

int main()
{
    int maks_antrian, pilihan, total_bayar;
    char keluar;
    printf("Program Antrian Pembayaran UKT\n");
    printf("Input maks antrian : ");
    scanf("%d", &maks_antrian);
    struct Queue *q = createQueue();

    while (1)
    {
        printf("\n\nMenu : \n1. Tambah Antrian\n2. Proses Pembayaran\n3. Lihat Antrian\n4. Keluar\n");
        scanf("%d", &pilihan);
        switch (pilihan)
        {
        case 1:
            if (q->count >= maks_antrian)
            {
                printf("\nJumlah antrian sudah mencapai batas maksimum yaitu %d", maks_antrian);
            }
            else
            {
                struct Pembayaran data;
                printf("\nInput Data Mahasiswa\n");
                getchar();
                printf("Nama : ");
                fgets(data.nama, sizeof(data.nama), stdin);
                strtok(data.nama, "\n");
                printf("Nim : ");
                fgets(data.nim, sizeof(data.nim), stdin);
                strtok(data.nim, "\n");
                printf("UKT : ");
                scanf("%d", &data.ukt);
                printf("Nominal : ");
                scanf("%d", &data.nominal);
                enqueue(q, data);
                printf("\nData Berhasil Ditambahkan\n");
            }
            break;
        case 2:
            if (q->count != 0)
            {
                printf("\nData mahasiswa\n");
                printf("Nama : %s\n", q->front->nama);
                printf("Nim : %s\n", q->front->nim);
                printf("UKT : %d\n", q->front->ukt);
                printf("Nominal : %d\n", q->front->nominal);
                printf("Masukan Nominal Bayar : ");
                scanf("%d", &total_bayar);
                while (total_bayar > q->front->nominal)
                {
                    printf("\nUang yang anda masukan melebihi total pembayaran sebesar %d\nMasukan Nominal Bayar : ", q->front->nominal);
                    scanf("%d", &total_bayar);
                }
                q->front->nominal -= total_bayar;
                if (q->front->nominal == 0)
                {
                    dequeue(q);
                    printf("\nPembayaran Berhasil\n");
                }
                else
                {
                    printf("\nUang yang anda masukan kurang\n");
                }
            }
            else
            {
                printf("\nAntrian Kosong\n");
            }
            break;
        case 3:
            display(q);
            break;
        case 4:
            printf("\nApakah Anda Yakin (Y/T) ?");
            scanf(" %c", &keluar);
            if (keluar == 'y' || keluar == 'Y')
            {
                printf("\nTerimaksih\n");
                exit(0);
            }
            else
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
