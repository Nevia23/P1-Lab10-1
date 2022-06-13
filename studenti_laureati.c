#include <stdio.h>
#include "studenti_laureati.h"

int conta_linee(FILE* fp) {

    char c = fgetc(fp);
    int linee = 1;
    while(c!=EOF){
        if(c=='\n'){
            linee++;
        }
        c = fgetc(fp);
    }
    rewind(fp);
    return linee;
}

void leggi_studente(FILE* fp, Studente_extra* s) {
    
    fscanf(fp, "%s %s %s", s->nome, s->cognome, s->stato);
    int j;

    if (s->stato == "Non_laureato") {
        
        for(j=0; j<N_VOTI; j++){
            fscanf(fp, "%d", s->voti+j);
        }
    } else {
        printf("ARGH");
        fscanf (fp, " %f", s->media);
    }

    return;
}

void scrivi_studente(FILE* fp, Studente_extra s) {
    
    fprintf(fp, "%s %s %s", s.nome, s.cognome, s.stato);
    int j;

    if (s.stato == "Non_laureato") {
        for(j=0; j<N_VOTI; j++){
            fprintf(fp, " %d", s.voti[j]);
        }
    } else {
        fprintf(fp, " %f", s.media);
    }

    fprintf(fp, "\n");

    return;
}

void print_studente (Studente_extra s) {
    
    int i;

    printf("%s %s %s", s.nome, s.cognome, s.stato);
    
    if (s.stato == "Non_laureato") {
        for(i=0; i<N_VOTI; i++){
            printf(" %d", s.voti[i]);
        }
    } else {
        printf(" %f", s.media);
    }

    printf("\n");
}

float calcola_media(Studente_extra s) {
    int i;
    float somma = 0, count = 0;

    for (i = 0; i < N_VOTI; i++) {
        if (s.voti[i] != -1) {
            somma = somma + s.voti[i];
            count++;
        }
    }
    
    if (count != 0) {
        float media = somma / count;
        return media;
    } else {
        return -1;
    }
}

int sufficienza_studente(Studente_extra s) {

    if (calcola_media(s) >= 18) {
        return 1;
    } else {
        return 0;
    }
}

int completato_percorso(Studente_extra s) {

    int i, completato = 0;

    if (sufficienza_studente(s) == 1) {

        for (i = 0; i < N_VOTI && completato == 0; i++) {

            if (s.voti[i] == -1) {
                completato = 1;
            }
        }
    }

    if (completato == 1) {
        s.media = calcola_media (s);
        return 1;
    } else {
        return 0;
    }
}