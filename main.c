#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef enum {
    JALAN_KAKI,
    OJEK,
    BIKUN
} ModaTransportasi;

typedef enum {
    AMAN,
    CUKUP_AMAN,
    BERISIKO
} TingkatKeamanan;

typedef struct {
    char nama_rute[120];
    char tujuan[60];
    ModaTransportasi moda;
    int skor_total;
} Rute;

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

    return 0;
}