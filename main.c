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

Rute semuaRute[] = {


};

int filterRute(){

}

#define JUMLAH_RUTE 18

char daftarTujuan[10][50];

void hitungSkorSemua(){
}

void cetakModa(ModaTransportasi){

}

void cetakTingkat(TingkatKeamanan){

}

void sortRute(){

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