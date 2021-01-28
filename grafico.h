#ifndef GRAFICO_H_INCLUDED
#define GRAFICO_H_INCLUDED

#endif // GRAFICO_H_INCLUDED

void tracejar(int posicaoX){
    int i;

    for(i = wherex(); i <= posicaoX; i++){
        gotoxy(i, wherey());
        printf(".");
    }
}
void quebralinha(coord coord1){
    gotoxy(coord1.x, wherey()+1);
}
