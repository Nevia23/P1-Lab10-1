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
        /*
        fclose(fp);
        printf("File letto\n\n");
        
        fp = fopen("studenti.txt","w");

        for (i = 0; i < n_stud; i++) {
            if (completato_percorso(s[i]) == 0) {
                *s[i].stato = "Laureato";
            }
        }

        for(i=n_stud-1; i>=0; i--){
            scrivi_studente(fp, s[i]);
        }

        fclose(fp);
        */
    }
}