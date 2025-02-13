#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct{
    char id;
    int num;
}tcase;

// Clear console
#define clear() printf("\033[H\033[J")

//Couleur
#define couleur(param) printf("\033[%sm",param)
#define FNOIR "30"
#define BNOIR "40"
#define BBLANC "47"
#define BVERT "42"
#define FBLANC "37"
#define BROUGE "41"
#define BBLEU "44"
#define BJAUNE "43"

#define DIMENSION 13
tcase plateau[DIMENSION][DIMENSION];

int refuge[9] = {15, 22, 29, 16, 23, 30, 17, 24, 31};

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
                    plateau[j][i].id = '-';
                    plateau[j][i].num = -1; // non utilisable
                }
                if(j % 2 == 1 && i % 2 == 0){   // Ajout des murs
                    plateau[j][i].id = '|';
                    plateau[j][i].num = -1; // non utilisable
                }
                if(j % 2 == 1 && i % 2 == 1){  // Ajout du plateau
                    plateau[j][i].id = 'X';
                    plateau[j][i].num = -1; // non utilisable
                }    
            }

            if(j > 4 && j<=8){
                if(j % 2 == 0 && i % 2 == 0){
                    if((j == 8) && (i == 4 || i == 6 || i == 8)){   // Ajout du refuge
                        compteur++;
                        plateau[j][i].id = 'R'; 
                        plateau[j][i].num = compteur;
                    }
                    else if((j==6) && (i == 4 || i == 8)){   // Ajout des chats
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
                    plateau[j][i].id = '-';
                    plateau[j][i].num = -1; // non utilisable
                }
                if(j % 2 == 1 && i % 2 == 0){   // Ajout des murs
                    plateau[j][i].id = '|';
                    plateau[j][i].num = -1; // non utilisable
                }
                if(j % 2 == 1 && i % 2 == 1){   // Ajout du plateau
                    plateau[j][i].id = 'X';
                    plateau[j][i].num = -1; // non utilisable
                }
            }
            if(j > 8 && j<=DIMENSION-1){
                if(j % 2 == 0 && i % 2 == 0){   
                    if(i == 4 || i == 6 || i ==8){  // Ajout du refuge
                        compteur++;
                        plateau[j][i].id = 'R'; 
                        plateau[j][i].num = compteur;
                    }
                    else{
                        plateau[j][i].id = 'E'; //empty
                        plateau[j][i].num = -1; // non utilisable
                    }
                    
                }
                if(j % 2 == 0 && i % 2 == 1){
                    if(i == 5 || i == 7){   // Ajout des murs
                        plateau[j][i].id = '-'; 
                        plateau[j][i].num = -1; // non utilisable
                    }
                    else{
                        plateau[j][i].id = 'E'; // Empty
                        plateau[j][i].num = -1; // non utilisable
                    }
                }
                if(j % 2 == 1 && i % 2 == 0){
                    if(i ==4 || i == 6 || i == 8){
                        if( i ==4 || i == 8){
                            plateau[j][i].id = '|';
                            plateau[j][i].num = -1; // non utilisable
                        }
                        else{
                            plateau[j][i].id = 'B';
                            plateau[j][i].num = -1; // non utilisable
                        }  
                    }
                    else{
                        plateau[j][i].id = 'E';
                        plateau[j][i].num = -1; // non utilisable
                    }
                }
                if(j % 2 == 1 && i % 2 == 1){
                    if(i == 5 || i == 7){
                        plateau[j][i].id = 'X';
                        plateau[j][i].num = -1; // non utilisable
                    }
                    else{
                        plateau[j][i].id = 'E';
                        plateau[j][i].num = -1; // non utilisable
                    }
  
                }
            }
        }
    }
}

void print_plateau(int affichage){ //affichche = 0 affiche pions, affichage = 1 affiche numéros
    for(int i = 0; i < DIMENSION; i++){
        for(int j = 0; j < DIMENSION; j++){
            if(plateau[i][j].id == 'S'){ // Souris
                couleur(FNOIR);
                couleur(BBLEU);
                if (affichage == 0){
                    printf(" %c ", plateau[i][j].id);
                }
                else{
                    printf("%03d", plateau[i][j].num);
                }
            }
            if(plateau[i][j].id == 'R'){ // Souris
                couleur(FNOIR);
                couleur(BJAUNE);
                if (affichage == 0){
                    printf(" %c ", plateau[i][j].id);
                }
                else{
                    printf("%03d", plateau[i][j].num);
                }
            }
            if(plateau[i][j].id == ' '){ // Case vide
                couleur(FNOIR);
                couleur(BVERT);
                if (affichage == 0){
                    //printf(" %c ", plateau[i][j].id);
                    printf("%03d", plateau[i][j].num);
                }
                else{
                    printf("%03d", plateau[i][j].num);
                }
            }
            if(plateau[i][j].id == 'C'){ // Chat
                couleur(FNOIR);
                couleur(BROUGE);
                if (affichage == 0){
                    printf(" %c ", plateau[i][j].id);
                }
                else{
                    printf("%03d", plateau[i][j].num);
                }
            }
            if(plateau[i][j].id == 'E'){ // Case inaccessible
                couleur(FNOIR);
                couleur(BNOIR);
                if (affichage == 0){
                    printf("   ");
                }
                else{
                    printf("   ");
                    //printf("%03d", plateau[i][j].num);
                }
                
            }
            if(plateau[i][j].id == 'B'){ // Case blanche refuge
                couleur(FBLANC);
                couleur(BBLANC);
                if (affichage == 0){
                    printf("   ");
                }
                else{
                    printf("   ");
                    //printf("%03d", plateau[i][j].num);
                }
            }
            if(plateau[i][j].id == 'X' || plateau[i][j].id == '-' || plateau[i][j].id == '|'){
                couleur(FNOIR);
                couleur(BBLANC);
                if (affichage == 0){
                    printf(" %c ", plateau[i][j].id);
                }
                else{
                    printf(" %c ", plateau[i][j].id);
                    //printf("%03d", plateau[i][j].num);
                }
            }
            
            couleur("0");
        }
        printf("\n");
    }
}

int regle_souris(int case_num, int new_case_num){

    // Variables de position
    int current_j = 0;
    int current_i = 0;
    int new_j = 0;
    int new_i = 0;

    // Récupération des coordonnées de la case et de la nouvelle case
    for (int i = 0; i < DIMENSION; i++){
        for (int j = 0; j < DIMENSION; j++){
            if(plateau[j][i].num == case_num){ // Case localisée dans le plateau
                current_j = j;
                current_i = i;
            }
            
            if(plateau[j][i].num == new_case_num){ // Case localisée dans le plateau
                new_j = j;
                new_i = i;
            }
        }
    }

    // Vérification des régles de déplacement

    // Vérification que la case de départ est bien une souris
    if(plateau[current_j][current_i].id != 'S'){
        printf("Déplacement impossible, la case de départ n'est pas une souris\n");
        return 0;
    }
    // Interdiction que la souris se déplace sur une case occupée
    if(plateau[new_j][new_i].id != ' ' && plateau[new_j][new_i].id != 'R'){
        printf("Déplacement impossible, case occupée ou inaccessible\n");
        return 0;
    }
    // Interdiction de reculer pour les souris
    if((new_j - current_j) < 0){
        printf("Déplacement impossible, recul interdit\n");
        return 0;
    }
    // Vérification du déplacement de 2 cases en avant ou en diagonale
    if((abs(new_j - current_j) == MOOVE && abs(new_i - current_i) == MOOVE) || 
       (abs(new_j - current_j) == MOOVE && abs(new_i - current_i) == 0) || 
       (abs(new_j - current_j) == 0 && abs(new_i - current_i) == MOOVE)){

        // Si la souris quitte un refuge, la case redevient un refuge
        if(plateau[current_j][current_i].id == 'S' && (plateau[current_j][current_i].num >= 15 && plateau[current_j][current_i].num <= 31)){
            plateau[current_j][current_i].id = 'R';
        } else {
            plateau[current_j][current_i].id = ' ';
        }
        plateau[new_j][new_i].id = 'S';
        return 1;
    }
    
    // Déplacement impossible
    printf("Déplacement impossible, mouvement non autorisé\n");
    return 0;
}

int regle_chat(int case_num, int new_case_num){
    // Variables de position
    int current_j = 0;
    int current_i = 0;
    int new_j = 0;
    int new_i = 0;

    // Récupération des coordonnées de la case et de la nouvelle case
    for (int i = 0; i < DIMENSION; i++){
        for (int j = 0; j < DIMENSION; j++){
            if(plateau[j][i].num == case_num){ // Case localisée dans le plateau
                current_j = j;
                current_i = i;
            }
            
            if(plateau[j][i].num == new_case_num){ // Case localisée dans le plateau
                new_j = j;
                new_i = i;
            }
        }
    }

    // Vérification des régles de déplacement

    // Vérification que la case de départ est bien un chat
    if(plateau[current_j][current_i].id != 'C'){
        printf("Déplacement impossible, la case de départ n'est pas un chat\n");
        return 0;
    }
    // Interdiction que le chat se déplace sur une case occupée
    if(plateau[new_j][new_i].id != ' '){
        printf("Déplacement impossible, case occupée ou inaccessible\n");
        return 0;
    }
    // Interdiction que le chat entre dans un refuge
    if(plateau[new_j][new_i].id == 'R'){
        printf("Déplacement impossible, les chats ne peuvent pas entrer dans un refuge\n");
        return 0;
    }

    // Vérification du déplacement de 2 cases avec une souris à manger
    if(abs(current_j - new_j) == 2 * MOOVE && abs(current_i - new_i) == 0){
        if(plateau[(current_j + new_j) / 2][current_i].id == 'S'){
            plateau[new_j][new_i].id = 'C';
            plateau[current_j][current_i].id = ' ';
            plateau[(current_j + new_j) / 2][current_i].id = ' ';
            return 1;
        }
    }
    if(abs(current_i - new_i) == 2 * MOOVE && abs(current_j - new_j) == 0){
        if(plateau[current_j][(current_i + new_i) / 2].id == 'S'){
            plateau[new_j][new_i].id = 'C';
            plateau[current_j][current_i].id = ' ';
            plateau[current_j][(current_i + new_i) / 2].id = ' ';
            return 1;
        }
    }

    // Vérification du déplacement de 1 case
    if(abs(current_j - new_j) == MOOVE && abs(current_i - new_i) == 0){
        plateau[new_j][new_i].id = 'C';
        plateau[current_j][current_i].id = ' ';
        return 1;
    }
    if(abs(current_i - new_i) == MOOVE && abs(current_j - new_j) == 0){
        plateau[new_j][new_i].id = 'C';
        plateau[current_j][current_i].id = ' ';
        return 1;
    }

    // Déplacement impossible
    printf("Déplacement impossible, mouvement non autorisé\n");
    return 0;
}

int kill_the_cat(int case_num){
    // Variables de position
    int current_j = 0;
    int current_i = 0;
    int new_j = 0;
    int new_i = 0;

    //Réponse du joueur
    int reponse;

    // Récupération des coordonnées de la case et de la nouvelle case
    for (int i = 0; i < DIMENSION; i++){
        for (int j = 0; j < DIMENSION; j++){
            if(plateau[j][i].num == case_num){ // Case localisée dans le plateau
                current_j = j;
                current_i = i;
            }
            
        }
    }

    // Vériffiaction dans les 8 directions si le chat peut manger une souris
    if(plateau[current_j][current_i].id == 'C'){ // Check chat
        // Check sur j+
        if(plateau[current_j + MOOVE][current_i].id == 'S' && plateau[current_j + (2 * MOOVE)][current_i].id == ' '){
            printf("Chat en [%d] peut manger la souris en [%d]\n", plateau[current_j][current_i].num, plateau[current_j + MOOVE][current_i].num);
            printf("Manger la souris :\n[1] Oui\n[2] Non\nQue faire : ");
            scanf("%d", &reponse);
            switch(reponse){
                case 1:
                    plateau[current_j + MOOVE][current_i].id = ' '; // Suppression de la souris
                    plateau[current_j][current_i].id = ' '; // Suppression de la pos du chat
                    plateau[current_j + (2 * MOOVE)][current_i].id = 'C'; // Déplacement du chat
                    return 0;
                case 2:
                    plateau[current_j][current_i].id = ' '; // Le chat est tué
                    return 1;
            }
        }
        // Check sur j-
        else if(plateau[current_j - MOOVE][current_i].id == 'S' && plateau[current_j - (2 * MOOVE)][current_i].id == ' '){
            printf("Chat en [%d] peut manger la souris en [%d]\n", plateau[current_j][current_i].num, plateau[current_j - MOOVE][current_i].num);
            printf("Manger la souris :\n[1] Oui\n[2] Non\nQue faire : ");
            scanf("%d", &reponse);
            switch(reponse){
                case 1:
                    plateau[current_j - MOOVE][current_i].id = ' '; // Suppression de la souris
                    plateau[current_j][current_i].id = ' '; // Suppression de la pos du chat
                    plateau[current_j - (2 * MOOVE)][current_i].id = 'C'; // Déplacement du chat
                    return 0;
                case 2:
                    plateau[current_j][current_i].id = ' '; // Le chat est tué
                    return 1;
            }
        }
        // Check sur i+
        else if(plateau[current_j][current_i + MOOVE].id == 'S' && plateau[current_j][current_i + (2 * MOOVE)].id == ' '){
            printf("Chat en [%d] peut manger la souris en [%d]\n", plateau[current_j][current_i].num, plateau[current_j][current_i + MOOVE].num);
            printf("Manger la souris :\n[1] Oui\n[2] Non\nQue faire : ");
            scanf("%d", &reponse);
            switch(reponse){
                case 1:
                    plateau[current_j][current_i + MOOVE].id = ' '; // Suppression de la souris
                    plateau[current_j][current_i].id = ' '; // Suppression de la pos du chat
                    plateau[current_j][current_i + (2 * MOOVE)].id = 'C'; // Déplacement du chat
                    return 0;
                case 2:
                    plateau[current_j][current_i].id = ' '; // Le chat est tué
                    return 1;
            }
        }
        // Check sur i-
        else if(plateau[current_j][current_i - MOOVE].id == 'S' && plateau[current_j][current_i - (2 * MOOVE)].id == ' '){
            printf("Chat en [%d] peut manger la souris en [%d]\n", plateau[current_j][current_i].num, plateau[current_j][current_i - MOOVE].num);
            printf("Manger la souris :\n[1] Oui\n[2] Non\nQue faire : ");
            scanf("%d", &reponse);
            switch(reponse){
                case 1:
                    plateau[current_j][current_i - MOOVE].id = ' '; // Suppression de la souris
                    plateau[current_j][current_i].id = ' '; // Suppression de la pos du chat
                    plateau[current_j][current_i - (2 * MOOVE)].id = 'C'; // Déplacement du chat
                    return 0;
                case 2:
                    plateau[current_j][current_i].id = ' '; // Le chat est tué
                    return 1;
            }
        }
        else{
            //Rien à signaler pour le chat
            return 2;
        }
        
    }

}

int check_victory() {
    int souris_count = 0;
    int chat_count = 0;
    int refuge_count = 0;

    for (int i = 0; i < DIMENSION; i++) {
        for (int j = 0; j < DIMENSION; j++) {
            if (plateau[i][j].id == 'S') { // Comptage Souris
                souris_count++;
            }
            if (plateau[i][j].id == 'C') { // Comptage Chats
                chat_count++;
            }
            for (int k = 0; k < 9; k++){ // Comptage des souris dans les refuges
                if(plateau[i][j].num == refuge[k] && plateau[i][j].id == 'S'){
                    refuge_count++;
                }
            }
        }
    }

    if (refuge_count == 9) { // Toutes les souris sont dans les refuges
        printf("Victoire des souris, toutes les souris sont dans les refuges !\n");
        return 1;
    }

    // Souris toutes mangées
    if (souris_count == 0) { // Aucune souris sur le plateau
        printf("Victoire des chats, toutes les souris ont été mangées !\n");
        return 1;
    }

    // Les chats ont été tués
    if (chat_count == 0) { // Aucun chat sur le plateau
        printf("Victoire des souris, tous les chats ont été tués !\n");
        return 1;
    }

    return 0;
}

void game_loop() {
    int case_num = 0;
    int new_case_num = 0;
    int check_cat = 0;
    while (check_victory() == 0) {

        // Clear console
        clear();
        print_plateau(1);


        if (check_victory()) {
            break;
        }

        printf("[SOURIS] Quelle case à déplacer ?\n");
        scanf("%d", &case_num);
        printf("[SOURIS] Où déplacer la case ?\n");
        scanf("%d", &new_case_num);
        while (regle_souris(case_num, new_case_num) != 1) {
            sleep(1);
            clear();
            print_plateau(1);
            printf("[SOURIS] Quelle case à déplacer ?\n");
            scanf("%d", &case_num);
            printf("[SOURIS] Où déplacer la case ?\n");
            scanf("%d", &new_case_num);
        }

        // Clear console
        clear();
        print_plateau(1);

        if (check_victory()) {
            break;
        }

        printf("[CHAT] Quelle case à déplacer ?\n");
        scanf("%d", &case_num);
        check_cat = kill_the_cat(case_num);
        
        if(check_cat == 2){
            printf("[CHAT] Où déplacer la case ?\n");
            scanf("%d", &new_case_num);
            while (regle_chat(case_num, new_case_num) != 1) {
                sleep(1);
                clear();
                print_plateau(1);
                printf("[CHAT] Quelle case à déplacer ?\n");
                scanf("%d", &case_num);
                printf("[CHAT] Où déplacer la case ?\n");
                scanf("%d", &new_case_num);
            }
        }
    }
}

int main(void){
    init_plateau();
    game_loop();



    return 0;
}