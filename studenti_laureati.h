#define N_VOTI 5
#include <stdio.h>

typedef struct studenti
{
    char nome[256];
    char cognome[256];
    char stato[256];
    float media;
    int voti[N_VOTI];
} Studente_extra;

int conta_linee(FILE* fp);

void leggi_studente(FILE* fp, Studente_extra* s);
void scrivi_studente(FILE* fp, Studente_extra s);
void print_studente (Studente_extra s);

float calcola_media(Studente_extra s);
int sufficienza_studente(Studente_extra s);
int completato_percorso(Studente_extra s);