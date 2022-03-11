#include <stdio.h>
#include <stdlib.h>

typedef struct simpul Dnode;
struct simpul
{
    int data;
    Dnode *prev, *next;
};

void menu();
void masukkan();
void hapuskan();
void alokasi();
void awal();
void akhir();
void setelah();
void sebelum();
void hapusAwal();
void hapusAkhir();
void hapusTertentu();
void tampil();

Dnode *head = NULL, *p, *hapus;

int main()
{
    menu();

    return 0;
}

void menu()
{
    int pilihan;

    do
    {
        puts("Menu Utama");
        puts("1. Insert");
        puts("2. Delete");
        puts("3. Keluar");
        printf("Masukkan pilihan Anda : ");
        scanf("%d", &pilihan);
        if (head == NULL && pilihan == 2)
            puts("Linked List masih kosong tidak bisa melakukan operasi delete");
        else
        {
            switch (pilihan)
            {
            case 1:
                masukkan();
                break;
            case 2:
                hapuskan();
                break;
            case 3:
                exit(0);
            }
            tampil();
        }
    } while (pilihan != 3);
}

void masukkan()
{
    int pilih;

    puts("\nMenu Insert");
    puts("1. Insert Awal");
    puts("2. Insert Akhir");
    puts("3. Insert After");
    puts("4. Insert Before");
    printf("Masukkan pilihan Anda : ");
    scanf("%d", &pilih);
    if (head == NULL && pilih == 3 || head == NULL && pilih == 4)
    {
        puts("Tidak bisa melakukan insert after dan before karena DLL masih kosong");
        exit(0);
    }
    else
    {
        alokasi();
        switch (pilih)
        {
        case 1:
            awal();
            break;
        case 2:
            akhir();
            break;
        case 3:
            setelah();
            break;
        case 4:
            sebelum();
            break;
        }
    }
}

void hapuskan()
{
    int pilih;

    puts("\nMenu Delete");
    puts("1. Delete Awal");
    puts("2. Delete Akhir");
    puts("3. Delete Tertentu");
    printf("Masukkan pilihan Anda : ");
    scanf("%d", &pilih);
    switch (pilih)
    {
    case 1:
        hapusAwal();
        break;
    case 2:
        hapusAkhir();
        break;
    case 3:
        hapusTertentu();
        break;
    }
}

void alokasi()
{
    int x;

    printf("Data yang mau disimpan ? ");
    scanf("%d", &x);
    p = (Dnode *)malloc(sizeof(Dnode));
    if (p == NULL)
    {
        puts("Pemesanan Gagal");
        exit(0);
    }
    else
    {
        p->data = x;
        p->next = NULL;
        p->prev = NULL;
    }
}

void hapusAwal()
{
    hapus = head;
    head = head->next;
    if (head != NULL)
        head->prev = NULL;
    free(hapus);
    hapus = NULL;
}

void hapusAkhir()
{
    hapus = head;
    while (hapus->next != NULL)
        hapus = hapus->next;
    if (hapus == head)
    {
        head = head->next;
    }
    else
    {
        hapus->prev->next = NULL;
    }
    free(hapus);
    hapus == NULL;
}

void hapusTertentu()
{
    int key;

    hapus = head;
    printf("Data yang mau dihapus ? ");
    scanf("%d", &key);
    if (hapus->data == key)
    {
        head = head->next;
        if (head != NULL)
            head->prev == NULL;
    }
    else
    {
        while (hapus->data != key)
        {
            if (hapus->next == NULL)
            {
                printf("Data %d tidak ada di dalam DLL\n", key);
                exit(0);
            }
            hapus = hapus->next;
        }
        if (hapus->next == NULL)
            hapus->prev->next = NULL;
        else
        {
            hapus->prev->next = hapus->next;
            hapus->next->prev = hapus->prev;
        }
    }
    free(hapus);
    hapus == NULL;
}

void sebelum()
{
    int key;
    Dnode *before;

    printf("Sisip before brp ? ");
    scanf("%d", &key);
    before = head;
    while (before->data != key)
    {
        if (before->next == NULL)
        {
            puts("Data Tidak ada dalam DLL");
            exit(0);
        }
        before = before->next;
    }
    p->next = before;
    if (before->prev == NULL)
        head = p;
    else
    {
        before->prev->next = p;
        p->prev = before->prev;
    }

    before->prev = p;
}

void setelah()
{
    Dnode *after;
    int key;

    printf("Sisip after brp ? ");
    scanf("%d", &key);
    after = head;
    while (after->data != key)
    {
        if (after->next == NULL)
        {
            printf("%d tidak ada di DLL\n", key);
            return;
        }
        after = after->next;
    }
    p->next = after->next;
    if (after->next != NULL)
        after->next->prev = p;
    after->next = p;
    p->prev = after;
}

void akhir()
{
    Dnode *tail;

    tail = head;
    if (head == NULL)
        head = p;
    else
    {
        while (tail->next != NULL)
            tail = tail->next;
        p->prev = tail;
        tail->next = p;
        tail = p;
    }
}

void awal()
{
    if (head != NULL)
    {
        p->next = head;
        head->prev = p;
    }
    head = p;
}

void tampil()
{
    Dnode *baca;

    puts("\nIsi dari DLL");
    baca = head;
    while (baca != NULL)
    {
        printf("%d\n", baca->data);
        baca = baca->next;
    }
    if (head == NULL)
        puts("Kosong\n");
}
