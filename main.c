#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef enum {
    JALAN_KAKI = 0,
    SEPEDA     = 1,
    MOTOR      = 2,
    OJEK       = 3,
    BIKUN      = 4,
    KRL        = 5
} ModaTransportasi;

typedef enum {
    AMAN        = 2,
    CUKUP_AMAN  = 1,
    BERISIKO    = 0
} TingkatKeamanan;

typedef struct {
    char             nama_rute[120];
    char             asal[60];
    char             tujuan[60];
    ModaTransportasi moda;
    float            jarak_km;
    int              waktu_menit;
    int              estimasi_biaya;
    int              skor_lampu;
    int              skor_kepadatan;
    int              skor_gsm;
    int              skor_kriminal;
    int              skor_total;
    TingkatKeamanan  tingkat;
    char             catatan[100];
} Rute;

#define JUMLAH_RUTE    18
#define JUMLAH_TUJUAN   6

const char *DAFTAR_TUJUAN[JUMLAH_TUJUAN] = {
    "Kukusan Teknik",
    "Kukusan Kelurahan",
    "Area Fakultas Hukum",
    "Stasiun UI",
    "Stasiun Pondok Cina",
    "Resimen Mahasiswa"
};

Rute semuaRute[JUMLAH_RUTE] = {
    {"Jalan kaki via Jl. Kukusan Raya", "Fakultas Teknik UI", "Kukusan Teknik", JALAN_KAKI, 0.8f, 10, 0, 21, 20, 23, 20, 0, AMAN, ""},
    {"Ojek online via Jl. Kukusan Raya", "Fakultas Teknik UI", "Kukusan Teknik", OJEK, 0.8f, 4, 8000, 21, 20, 23, 20, 0, AMAN, ""},
    {"Jalan kaki via Gang Belakang Teknik", "Fakultas Teknik UI", "Kukusan Teknik", JALAN_KAKI, 0.6f, 8, 0, 6, 5, 14, 5, 0, BERISIKO, ""},
    {"Bikun lalu jalan kaki dari Halte Kukusan", "Fakultas Teknik UI", "Kukusan Kelurahan", BIKUN, 2.0f, 12, 0, 22, 22, 24, 21, 0, AMAN, ""},
    {"Ojek online via Jl. Margonda – Jl. Kukusan", "Fakultas Teknik UI", "Kukusan Kelurahan", OJEK, 2.2f, 8, 12000, 20, 18, 24, 18, 0, AMAN, ""},
    {"Jalan kaki via Jl. Kukusan Kelurahan Dalam", "Fakultas Teknik UI", "Kukusan Kelurahan", JALAN_KAKI, 1.5f, 20, 0, 10, 12, 18, 10, 0, CUKUP_AMAN, ""},
    {"Bikun via Jl. Dalam Kampus", "Fakultas Teknik UI", "Area Fakultas Hukum", BIKUN, 1.8f, 10, 0, 24, 23, 25, 23, 0, AMAN, ""},
    {"Jalan kaki via Jl. Dalam Kampus UI", "Fakultas Teknik UI", "Area Fakultas Hukum", JALAN_KAKI, 1.8f, 22, 0, 24, 22, 25, 22, 0, AMAN, ""},
    {"Jalan kaki via Pinggir Danau UI", "Fakultas Teknik UI", "Area Fakultas Hukum", JALAN_KAKI, 2.0f, 25, 0, 4, 5, 16, 6, 0, BERISIKO, ""},
    {"Bikun ke Halte Stasiun UI", "Fakultas Teknik UI", "Stasiun UI", BIKUN, 1.2f, 8, 0, 23, 24, 25, 23, 0, AMAN, ""},
    {"Ojek online via Jl. Margonda", "Fakultas Teknik UI", "Stasiun UI", OJEK, 1.3f, 5, 10000, 23, 25, 25, 22, 0, AMAN, ""},
    {"Jalan kaki via Jl. Margonda", "Fakultas Teknik UI", "Stasiun UI", JALAN_KAKI, 1.3f, 16, 0, 22, 24, 25, 20, 0, AMAN, ""},
    {"Bikun ke Halte Pondok Cina lalu jalan kaki", "Fakultas Teknik UI", "Stasiun Pondok Cina", BIKUN, 2.5f, 15, 0, 22, 21, 24, 21, 0, AMAN, ""},
    {"Ojek online via Jl. Margonda", "Fakultas Teknik UI", "Stasiun Pondok Cina", OJEK, 2.6f, 9, 14000, 21, 20, 24, 20, 0, AMAN, ""},
    {"Jalan kaki via Jl. Dalam Kampus – Pondok Cina", "Fakultas Teknik UI", "Stasiun Pondok Cina", JALAN_KAKI, 2.4f, 30, 0, 14, 13, 20, 12, 0, CUKUP_AMAN, ""},
    {"Jalan kaki via Jl. Dalam Kampus UI", "Fakultas Teknik UI", "Resimen Mahasiswa", JALAN_KAKI, 1.1f, 14, 0, 23, 21, 24, 22, 0, AMAN, ""},
    {"Bikun lalu turun di halte terdekat", "Fakultas Teknik UI", "Resimen Mahasiswa", BIKUN, 1.0f, 7, 0, 23, 22, 24, 22, 0, AMAN, ""},
    {"Ojek online via Jl. Dalam Kampus", "Fakultas Teknik UI", "Resimen Mahasiswa", OJEK, 1.1f, 5, 8000, 23, 21, 24, 22, 0, AMAN, ""}
};

void hitungSkorSemua() {
    int i;
    for (i = 0; i < JUMLAH_RUTE; i++) {
        semuaRute[i].skor_total = semuaRute[i].skor_lampu + 
                                     semuaRute[i].skor_kepadatan + 
                                  semuaRute[i].skor_gsm + 
                                  semuaRute[i].skor_kriminal;
        
        if (semuaRute[i].skor_total >= 70) {
            semuaRute[i].tingkat = AMAN;
        } else if (semuaRute[i].skor_total >= 40) {
            semuaRute[i].tingkat = CUKUP_AMAN;
        } else {
            semuaRute[i].tingkat = BERISIKO;
        }
    }
}

void cetakModa(ModaTransportasi m) {
    if (m == JALAN_KAKI) printf("Jalan kaki");
    else if (m == SEPEDA) printf("Sepeda");
    else if (m == MOTOR) printf("Motor");
    else if (m == OJEK) printf("Ojek online");
    else if (m == BIKUN) printf("Bus Kuning");
    else printf("KRL");
}

void cetakTingkat(TingkatKeamanan t) {
    if (t == AMAN) printf("AMAN");
    else if (t == CUKUP_AMAN) printf("CUKUP AMAN");
    else printf("BERISIKO");
}

void sortRute(Rute arr[], int n) {
    int i, j;
    Rute temp;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j].skor_total < arr[j+1].skor_total) {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}


int main(){
    printf("1. Kukusan Teknik\n");
printf("0. Keluar\n");
printf("1. Kukusan Teknik\n");
printf("0. Keluar\n");
printf("1. Kukusan Teknik\n");
printf("0. Keluar\n");
 printf("1. Kukusan Teknik\n");
printf("0. Keluar\n");
printf("1. Kukusan Teknik\n");
printf("0. Keluar\n");
printf("1. Kukusan Teknik\n");
printf("0. Keluar\n");
    return 0;
}