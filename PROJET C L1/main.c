#include<stdio.h>

void init_carte(char tab[20][20]) ;
void affiche_carte(char tab[20][20] , char perso[2]) ;


int main(){
char tab[20][20] ;
char perso[2] ;
int p;
int v;

//herbe =0 , fleur=1, arbre=2, rocher=3, clé=4, pièce=5, cadenas=6, piège=7, monstre=8 //

init_carte(tab) ;
affiche_carte(tab, perso) ;
if(p==10){
    printf("Vous avez perdu, le démon Licht vous a tuez, essayez à nouveau !\n ") ;
}
else if (v==0) {
    printf ("Vous avez remporté la victoire, bien joué, vous avez su surpasser les épreuves du démon Licht ne vous atteint même pas la cheville !\n") ;
}
else{
    v=v ;
}
return 0 ;
}


void init_carte(char tab[20][20]) {
  
int i ;
int j ;
int x=0 ;
int y=0 ;
for(i=0;i<20;i++){
        for(j=0;j<20;j++){
                if(i>1&&( j==0|| j==19)&&(i%2==0)){
                    tab[i][j]='7';
                }
                else if(i>1&&(j==0 || j==19)){
                    tab[i][j]='5';
                }
       
                else if(( i>2 && j>2 && (i==3 || i==19-3 || j==3 || j==19-3) && i<19-2 && j<19-2 )&& (i!=10 && i!=9)){
                    tab[i][j]='3';
                }
                else if( (i>5 && j>5 && (i==6 || i==19-6 || j==6 || j==19-6) && i<19-5 && j<19-5)&& (j!=10 && j!=9)){
                    tab[i][j]='2';
                }
               
                else if( i>8 && j>8 && (i==9 || i==19-9 || j==8 || j==19-9) && i<19-8 && j<19-8 ){
                    tab[i][j]='1';
                }
                else if( i>2 &&(i==j)&& i<19-2){
                    tab[i][j]='8';
                }
                else if( i==3 && j==2 ){
                    tab[i][j]='4';
                }
                else if( i==4 && j==2 ){
                    tab[i][j]='6';
                }
                else{
                    tab[i][j]='0';
                }
        }
    }
}


void affiche_carte(char tab[20][20] , char perso[2]) {

    int i ;
    int j ;
    int n ;
    int c=0 ;
    int v=10 ;
    int p=0 ;
    int x=0 ;
    int y=0 ;
    perso[0]='X' ;

    while ((v>0)&&(p<10)){
        for(i=0; i<20; i=i+1){
                for(j=0; j<20; j=j+1){
        if ((i==x)&&(j==y)){
            printf("%c ",perso[0]);
    }
        else{
            printf("%c ", tab[i][j]) ;
    }
    }
        printf("\n") ;
    }
    printf("Déplacements: Quitter:\n     8           0\n   4   6\n     2\n") ;
    scanf("%d",&n) ;
      switch(n) {
        case 0:
            printf("appuyer sur les touches ctrl et c en même temps\n") ;
            break ;
        case 2:
            if (x>=19) {
            printf("impossible de descendre !\n") ;
        }
            else if((tab[x+1][y]=='2')||(tab[x+1][y]=='3')) {
            printf("impossible de descendre !\n") ;
        }
            else if (tab[x+1][y]=='7') {
            v=v-1 ;
            x=x+1 ;
            tab[x][y]='0';
            printf("Il te reste %d vie(s)\n",v) ;
        }
            else if (tab[x+1][y]=='8') {
            v=v-2 ;
            x=x+1 ;
            printf("Il te reste %d vie(s)\n",v) ;
        }
            else if(tab[x+1][y]=='5'){
            p=p+1 ;
            x=x+1 ;
            tab[x][y]='0' ;
            printf("Tu possède %d pièce(s)\n",p) ;
        }
            else if(tab[x+1][y]=='4'){
            c=c+1 ;
            x=x+1 ;
            tab[x][y]='0' ;
            printf("Tu possède %d clé\n",c) ;
        }
            else if((tab[x+1][y]=='6')&&(c>0)){
            p=p+3 ;
            c=c-1 ;
            x=x+1 ;
            tab[x][y]='0' ;
            printf("Tu possède %d pièces\n",p) ;
        }
                else {
                x=x+1 ;
        }
            break ;
        case 4:
            if (y<=0){
            printf("impossible d'aller à gauche !\n") ;
        }
            else if((tab[x][y-1]=='2')||(tab[x][y-1]=='3')) {
            printf("impossible d'aller à gauche !\n") ;
        }
            else if(tab[x][y-1]=='8') {
            v=v-2 ;
            y=y-1 ;
            printf("Il te reste %d vie(s)\n",v) ;
        }
            else if (tab[x][y-1]=='7') {
            v=v-1 ;
            y=y-1 ;
            tab[x][y]='0' ;
            printf("Il te reste %d vie(s)\n",v) ;
        }
            else if(tab[x][y-1]=='5'){
            p=p+1 ;
            y=y-1 ;
            tab[x][y]='0' ;
            printf("Tu possède %d pièce(s)\n",p) ;
        }
            else if(tab[x][y-1]=='4'){
            c=c+1 ;
            y=y-1 ;
            tab[x][y]='0' ;
            printf("Tu possède %d clé\n",c) ;
        }
            else if((tab[x][y-1]=='6')&&(c>0)){
            p=p+3 ;
            c=c-1 ;
            y=y-1 ;
            tab[x][y]='0' ;
            printf("Tu possède %d pièces\n",p) ;
        }
                else {
                y=y-1 ;
        }
                break ;
        case 6:
            if (y>=19){
            printf("impossible d'aller à droite !\n") ;
        }
            else if((tab[x][y+1]=='2')||(tab[x][y+1]=='3')) {
            printf("impossible d'aller à droite !\n") ;
        }
            else if(tab[x][y+1]=='8') {
            v=v-2 ;
            y=y+1 ;
            printf("Il te reste %d vie(s)\n",v) ;
        }
            else if(tab[x][y+1]=='7') {
            v=v-1 ;
            y=y+1 ;
            tab[x][y]='0' ;
            printf("Il te reste %d vie(s)\n",v) ;
        }
            else if(tab[x][y+1]=='5'){
            p=p+1 ;
            y=y+1 ;
            tab[x][y]='0' ;
            printf("Tu possède %d pièce(s)\n",p) ;
        }
            else if(tab[x][y+1]=='4'){
            c=c+1 ;
            y=y+1 ;
            tab[x][y]='0' ;
            printf("Tu possède %d clé\n",c) ;
        }
            else if((tab[x][y+1]=='6')&&(c>0)){
            p=p+3 ;
            c=c-1 ;
            y=y+1 ;
            tab[x][y]='0' ;
            printf("Tu possède %d pièces\n",p) ;
        }
                else {
                y=y+1 ;
        }
                   break ;
        case 8:
            if (x<=0){
            printf("impossible de monter !\n") ;
        }
            else if((tab[x-1][y]=='2')||(tab[x-1][y]=='3')) {
            printf("impossible de monter !\n") ;
        }
            else if(tab[x-1][y]=='8'){
            v=v-2 ;
            y=y+1 ;
            printf("Il te reste %d vie(s)\n",v) ;
        }
            else if(tab[x-1][y]=='7') {
            v=v-1 ;
            y=y+1 ;
            tab[x][y]='0' ;
            printf("Il te reste %d vie(s)\n",v) ;
        }
            else if(tab[x-1][y]=='5'){
            p=p+1 ;
            x=x-1 ;
            tab[x][y]='0' ;
            printf("Tu possède %d pièce(s)\n",p) ;
        }
            else if(tab[x-1][y]=='4'){
            c=c+1 ;
            x=x-1 ;
            tab[x][y]='0' ;
            printf("Tu possède %d clé\n",c) ;
        }
            else if((tab[x-1][y]=='6')&&(c>0)){
            p=p+3 ;
            c=c-1 ;
            x=x-1 ;
            tab[x][y]='0' ;
            printf("Tu possède %d pièces\n",p) ;
        }
                else {
                x=x-1 ;
        }
                break ;
        default :
            printf("erreur de saisie, le personnage ne bouge pas :\n") ;
    }
    }
    }
