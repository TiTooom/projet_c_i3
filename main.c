#include <stdio.h>

typedef struct{
    char id;
    int num;
}tcase;

//Couleur
#define couleur(param) printf("\033[%sm",param)
#define FNOIR "30"
#define BNOIR "40"
#define BBLANC "47"
#define BVERT "42"

#define DIMENSION 13
tcase plateau[DIMENSION][DIMENSION];

#define MOOVE 2 

void init_plateau(){
    int compteur = 0;
    for(int i = 0; i < DIMENSION; i++){
        for(int j = 0; j < DIMENSION; j++){
            compteur;
            if(j <= 4){ // 5 premieres lignes
                if(j % 2 == 0 && i % 2 == 0){   // Ajout des souris
                    compteur++;
                    plateau[j][i].id = 'S';
                    plateau[j][i].num = compteur;
                }
                if(j % 2 == 0 && i % 2 == 1){   // Ajout des murs
                    compteur++;
                    plateau[j][i].id = '-';
                    plateau[j][i].num = compteur;
                }
                if(j % 2 == 1 && i % 2 == 0){   // Ajout des murs
                    compteur++;
                    plateau[j][i].id = '|';
                    plateau[j][i].num = compteur;
                }
                if(j % 2 == 1 && i % 2 == 1){  // Ajout du plateau
                    compteur++;
                    plateau[j][i].id = 'X';
                    plateau[j][i].num = compteur;
                }    
            }

            if(j > 4 && j<=8){
                if(j % 2 == 0 && i % 2 == 0){
                    if((j==6) && (i == 4 || i == 8)){   // Ajout des chats
                        compteur++;
                        plateau[j][i].id = 'C'; 
                        plateau[j][i].num = compteur;
                    }
                    else{   // Ajout places libres
                        compteur++;
                        plateau[j][i].id = ' '; 
                        plateau[j][i].num = compteur;
                    }
                }
                if(j % 2 == 0 && i % 2 == 1){   // Ajout des murs
                    compteur++;
                    plateau[j][i].id = '-';
                    plateau[j][i].num = compteur;
                }
                if(j % 2 == 1 && i % 2 == 0){   // Ajout des murs
                    compteur++;
                    plateau[j][i].id = '|';
                    plateau[j][i].num = compteur;
                }
                if(j % 2 == 1 && i % 2 == 1){   // Ajout du plateau
                    compteur++;
                    plateau[j][i].id = 'X';
                    plateau[j][i].num = compteur;
                }
            }
            if(j > 8 && j<=DIMENSION-1){
                if(j % 2 == 0 && i % 2 == 0){   
                    if(i == 4 || i == 6 || i ==8){  // Ajout des espaces 
                        compteur++;
                        plateau[j][i].id = ' '; 
                        plateau[j][i].num = compteur;
                    }
                    else{
                        compteur++;
                        plateau[j][i].id = 'E'; //empty
                        plateau[j][i].num = compteur;
                    }
                    
                }
                if(j % 2 == 0 && i % 2 == 1){
                    if(i == 5 || i == 7){   // Ajout des murs
                        compteur++;
                        plateau[j][i].id = '-'; 
                        plateau[j][i].num = compteur;
                    }
                    else{
                        compteur++;
                        plateau[j][i].id = 'E'; // Empty
                        plateau[j][i].num = compteur;
                    }
                }
                if(j % 2 == 1 && i % 2 == 0){
                    if(i ==4 || i == 8){
                        compteur++;
                        plateau[j][i].id = '|';
                        plateau[j][i].num = compteur;
                    }
                    else{
                        compteur++;
                        plateau[j][i].id = 'E';
                        plateau[j][i].num = compteur;

                    }
                    
                }
                if(j % 2 == 1 && i % 2 == 1){
                    if(i == 5 || i == 7){
                        compteur++;
                        plateau[j][i].id = 'X';
                        plateau[j][i].num = compteur;
                    }
                    else{
                        compteur++;
                        plateau[j][i].id = 'E';
                        plateau[j][i].num = compteur;
                    }
  
                }
            }
        }
    }
}

void print_plateau(){
    for(int i = 0; i < DIMENSION; i++){
        for(int j = 0; j < DIMENSION; j++){
            if(plateau[i][j].id == 'S' || plateau[i][j].id == 'C' || plateau[i][j].id == ' '){
                couleur(FNOIR);
                couleur(BVERT);
                printf(" %c ", plateau[i][j].id);
            }
            if(plateau[i][j].id == 'E'){
                couleur(FNOIR);
                couleur(BNOIR);
                printf("   ");
            }
            if(plateau[i][j].id == 'X' || plateau[i][j].id == '-' || plateau[i][j].id == '|'){
                couleur(FNOIR);
                couleur(BBLANC);
                printf(" %c ", plateau[i][j].id);
            }
            
            couleur("0");
        }
        printf("\n");
    }
}

int main(void){
    init_plateau();
    print_plateau();
    return 0;
}