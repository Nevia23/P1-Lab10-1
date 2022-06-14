#include <stdio.h>
#include <stdlib.h>
#include "studenti_laureati.h"

int main(){
    FILE *fp;
    fp = fopen("studenti.txt","r");
    if (fp==NULL){
        printf("Il file non puo' essere aperto\n");
    }
    else {
        int n_stud = conta_linee(fp), i;
        Studente_extra s[n_stud];

        rewind(fp);

        for(i=0; i<n_stud; i++){
            leggi_studente(fp, s+i);
            print_studente(s[i]);
        }
        
        fclose(fp);
        
        for (i = 0; i < n_stud; i++) {
            if (s[i].tipo == Non_laureato && completato_percorso(s[i]) == 0) {
                s[i].stato.media = calcola_media(s[i]);
                s[i].tipo = Laureato;
            }
        }

        fp = fopen("studenti_ord.txt","w");

        for(i = 0; i < n_stud; i++){
            scrivi_studente(fp, s[i]);
        }

        fclose(fp);
        
    }
}