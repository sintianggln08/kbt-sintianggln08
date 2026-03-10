#include <stdio.h> 
#include <string.h> 

struct Tiket {
    char namaPenumpang[50];
    char tujuan[50];
    char jamKeberangkatan[10];
    char tanggalKeberangkatan[15];
    int harga;
};

int main() {
    int pilihanMenu;
    int pilihanRute;
    struct Tiket tiketPembelian;
    char kembaliKeMenu;

    do {
        printf("===========================================\n");
        printf("       SISTEM TICKETING KOPERASI BINTANG TAPANULI (KBT)\n");
        printf("===========================================\n");
        printf("1. Beli Tiket\n");
        printf("2. Lihat Daftar Harga Rute\n");
        printf("3. Keluar\n");
        printf("-------------------------------------------\n");
        printf("Masukkan pilihan Anda (1-3): ");
        scanf("%d", &pilihanMenu); 

        while (getchar() != '\n'); 

        switch (pilihanMenu) {
            case 1: 
                printf("\n--- FORM PEMBELIAN TIKET ---\n");
                printf("Nama Penumpang: ");
                fgets(tiketPembelian.namaPenumpang, sizeof(tiketPembelian.namaPenumpang), stdin);
                tiketPembelian.namaPenumpang[strcspn(tiketPembelian.namaPenumpang, "\n")] = 0;

                printf("\nPilih Tujuan:\n");
                printf("1. Balige - Medan (Rp 100.000)\n");
                printf("2. Balige - Tarutung (Rp 40.000)\n");
                printf("3. Balige - Pematangsiantar (Rp 75.000)\n");
                printf("4. Balige - Sibolga (Rp 90.000)\n");
                printf("Masukkan pilihan rute (1-4): ");
                scanf("%d", &pilihanRute);
                while (getchar() != '\n'); 

                switch (pilihanRute) {
                    case 1:
                        strcpy(tiketPembelian.tujuan, "Balige - Medan");
                        strcpy(tiketPembelian.jamKeberangkatan, "08:00 WIB");
                        strcpy(tiketPembelian.tanggalKeberangkatan, "2024-06-15");
                        tiketPembelian.harga = 100000;
                        break;
                    case 2:
                        strcpy(tiketPembelian.tujuan, "Balige - Tarutung");
                        strcpy(tiketPembelian.jamKeberangkatan, "10:00 WIB");
                        strcpy(tiketPembelian.tanggalKeberangkatan, "2024-06-15");
                        tiketPembelian.harga = 40000;
                        break;
                    case 3:
                        strcpy(tiketPembelian.tujuan, "Balige - Pematangsiantar");
                        strcpy(tiketPembelian.jamKeberangkatan, "09:30 WIB");
                        strcpy(tiketPembelian.tanggalKeberangkatan, "2024-06-15");
                        tiketPembelian.harga = 75000;
                        break;
                    case 4:
                        strcpy(tiketPembelian.tujuan, "Balige - Sibolga");
                        strcpy(tiketPembelian.jamKeberangkatan, "11:00 WIB");
                        strcpy(tiketPembelian.tanggalKeberangkatan, "2024-06-15");
                        tiketPembelian.harga = 90000;
                        break;
                    default:
                        printf("Pilihan rute tidak valid. Pembelian dibatalkan.\n");
                        tiketPembelian.harga = 0; 
                        break;
                }

                if (tiketPembelian.harga > 0) {
                    printf("\n--- STRUK PEMBAYARAN TIKET ---\n");
                    printf("===============================\n");
                    printf("Nama Penumpang   : %s\n", tiketPembelian.namaPenumpang);
                    printf("Tujuan           : %s\n", tiketPembelian.tujuan);
                    printf("Jam Keberangkatan: %s\n", tiketPembelian.jamKeberangkatan);
                    printf("Tgl Keberangkatan: %s\n", tiketPembelian.tanggalKeberangkatan);
                    printf("Harga Tiket      : Rp %d\n", tiketPembelian.harga);
                    printf("===============================\n");
                    printf("Pembelian tiket berhasil! Selamat jalan.\n");
                }
                break;

            case 2: 
                printf("\n--- DAFTAR HARGA RUTE KBT ---\n");
                printf("===========================================\n");
                printf("Rute                      | Harga\n");
                printf("-------------------------------------------\n");
                printf("Balige - Medan            | Rp 100.000\n");
                printf("Balige - Tarutung         | Rp 40.000\n");
                printf("Balige - Pematangsiantar  | Rp 75.000\n");
                printf("Balige - Sibolga          | Rp 90.000\n");
                printf("===========================================\n");
                break;

            case 3: 
                printf("\nTerima kasih telah menggunakan Sistem Ticketing KBT. Sampai jumpa!\n");
                break;

            default: 
                printf("\nPilihan tidak valid. Mohon masukkan angka 1, 2, atau 3.\n");
                break;
        }
        if (pilihanMenu != 3) { 
            printf("\nApakah Anda ingin kembali ke menu utama? (y/n): ");
            scanf(" %c", &kembaliKeMenu); 
        } else {
            kembaliKeMenu = 'n'; 
        }

    } while (kembaliKeMenu == 'y' || kembaliKeMenu == 'Y'); 

    return 0; 
}
