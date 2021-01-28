#ifndef FIGURASGEOMETRICAS_H_INCLUDED
#define FIGURASGEOMETRICAS_H_INCLUDED

#endif // FIGURASGEOMETRICAS_H_INCLUDED

int retaImprimir(char caractere, int origemX, int origemY, int distancia, int angulo){ //tratar erros possíveis!!! é complicado!!!
    int i;

    if(origemX >= 0 &&
       origemY >= 0 &&
       distancia >= 0 &&
       !(angulo == 90 && origemY-distancia < 0) &&
       !(angulo == 180 && origemX-distancia < 0) &&
       (angulo == 0 || angulo == 90 || angulo == 180 || angulo == 270)){

       switch(angulo){
            case 0:{
                for(i = origemX; i < origemX+distancia; i++){
                    gotoxy(i, origemY);
                    printf("%c", caractere);
                }
            } break;
            case 90:{
                for(i = origemY; i > origemY-distancia; i--){
                    gotoxy(origemX, i);
                    printf("%c", caractere);
                }
            } break;
            case 180:{
                for(i = origemX; i > origemX-distancia; i--){
                    gotoxy(i, origemY);
                    printf("%c", caractere);
                }
            } break;
            case 270:{
                for(i = origemY; i < origemY+distancia; i++){
                    gotoxy(origemX, i);
                    printf("%c", caractere);
                }
            }
       }

        return 1;
    }
    return 0;
}

void retanguloCheioImprimir(char caractere, int origemX, int origemY, int tamanhoX, int tamanhoY){
    int i;

    for(i = origemY; i < origemY+tamanhoY; i++){
        retaImprimir(caractere, origemX, i, tamanhoX, 0);
    }
}

void retanguloVazioImprimir(char caractere, int origemX, int origemY, int tamanhoX, int tamanhoY){
    retaImprimir(caractere, origemX, origemY, tamanhoX, 0);
    retaImprimir(caractere, origemX+tamanhoX, origemY, tamanhoY, 270);
    retaImprimir(caractere, origemX+tamanhoX, origemY+tamanhoY, tamanhoX, 180);
    retaImprimir(caractere, origemX, origemY+tamanhoY, tamanhoY, 90);
}

lista *retaInvisivel(lista *lista1, char caractere, int origemX, int origemY, int distancia, int angulo){ //tratar erros possíveis!!! é complicado!!!
    int i;

    if(origemX >= 0 &&
       origemY >= 0 &&
       distancia >= 0 &&
       !(angulo == 90 && origemY-distancia < 0) &&
       !(angulo == 180 && origemX-distancia < 0) &&
       (angulo == 0 || angulo == 90 || angulo == 180 || angulo == 270)){

       switch(angulo){
            case 0:{
                for(i = origemX; i < origemX+distancia; i++){
                    lista *no = lst_criaNo(i, origemY, caractere);
                    lista1 = lst_insere(lista1, no);
                }
            } break;
            case 90:{
                for(i = origemY; i > origemY-distancia; i--){
                    lista *no = lst_criaNo(origemX, i, caractere);
                    lista1 = lst_insere(lista1, no);
                }
            } break;
            case 180:{
                for(i = origemX; i > origemX-distancia; i--){
                    lista *no = lst_criaNo(i, origemY, caractere);
                    lista1 = lst_insere(lista1, no);
                }
            } break;
            case 270:{
                for(i = origemY; i < origemY+distancia; i++){
                    lista *no = lst_criaNo(origemX, i, caractere);
                    lista1 = lst_insere(lista1, no);
                }
            }
       }

        return lista1;
    }
    return 0;
}

lista *retanguloCheioInvisivel(lista *lista1, char caractere, int origemX, int origemY, int tamanhoX, int tamanhoY){
    int i;

    for(i = origemY; i < origemY+tamanhoY; i++){
        lista1 = retaInvisivel(lista1, caractere, origemX, i, tamanhoX, 0);
    }

    return lista1;
}

lista *retanguloVazioInvisivel(lista *lista1, char caractere, int origemX, int origemY, int tamanhoX, int tamanhoY){
    lista1 = retaInvisivel(lista1, caractere, origemX, origemY, tamanhoX, 0);
    lista1 = retaInvisivel(lista1, caractere, origemX+tamanhoX, origemY, tamanhoY, 270);
    lista1 = retaInvisivel(lista1, caractere, origemX+tamanhoX, origemY+tamanhoY, tamanhoX, 180);
    lista1 = retaInvisivel(lista1, caractere, origemX, origemY+tamanhoY, tamanhoY, 90);
}
