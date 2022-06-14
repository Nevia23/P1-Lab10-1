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
    
    char tipo[13];
    fscanf(fp, "%s %s", s->nome, s->cognome);
    fscanf(fp, "%s", tipo);
    int j;

    if (strcmp(tipo, "Non_laureato") == 0) {
        s->tipo = Non_laureato;
        for(j=0; j<N_VOTI; j++){
            fscanf(fp, "%d", s->stato.voti+j);
        }
    } else {
        s->tipo = Laureato;
        fscanf (fp, "%f", &(s->stato.media));
    }

    return;
}

void scrivi_studente(FILE* fp, Studente_extra s) {
    
    fprintf(fp, "%s %s", s.nome, s.cognome);
    int j;

    if (s.tipo == Non_laureato) {

        fprintf(fp, " Non_laureato");
        for(j=0; j < N_VOTI; j++){
            fprintf(fp, " %d", s.stato.voti[j]);
        }
    } else {

        fprintf(fp, " Laureato");
        fprintf(fp, " %2.1f", s.stato.media);
    }

    fprintf(fp, "\n");

    return;
}

void print_studente (Studente_extra s) {
    
    int i;

    printf("%s %s", s.nome, s.cognome);

    if (s.tipo == Non_laureato) {
        printf(" Non_laureato");
    } else {
        printf(" Laureato");
    }
    
    if (s.tipo == Non_laureato) {
        
        for(i=0; i<N_VOTI; i++){
            printf(" %d", s.stato.voti[i]);
        }
    } else {
        
        printf(" %2.1f", s.stato.media);
    }

    printf("\n");
}

float calcola_media(Studente_extra s) {
    int i;
    float somma = 0, count = 0;

    for (i = 0; i < N_VOTI; i++) {
        somma = somma + s.stato.voti[i];
        count++;
    }

    float media = somma / count;
    return media;
}

int sufficienza_studente(Studente_extra s) {

    float media = calcola_media(s);
    if (media >= 18) {
        return 1;
    } else {
        return 0;
    }
}

int completato_percorso(Studente_extra s) {

    int i, completato = 1;

    if(s.tipo == Laureato){
        return 1;
    }

    if (sufficienza_studente(s) == 1) {

        for (i = 0; i < N_VOTI && completato == 1; i++) {

            if (s.stato.voti[i] == -1) {
                completato = 0;
            }
        }
    } else {
        completato = 0;
    }

    if (completato == 1) {
        return 1;
    } else {
        return 0;
    }
}