#ifndef COMUM_H_INCLUDED
#define COMUM_H_INCLUDED

#endif // COMUM_H_INCLUDED


void setaIni(){
    seta = (selecSeta *) malloc(sizeof(selecSeta));
    seta->x = 0;
    seta->y = 0;
    seta->simbolo = ">>";
}
void setaDeterminar(telaInicialDimensoes td){
    seta->x = td.setaX;
    seta->y = td.setaY;
}
void setaDeterminarComoJogar(telaComoJogarDimensoes td){
    seta->x = td.seta.x;
    seta->y = td.seta.y;
}
void setaDeterminarPontuacao(telaPontuacaoDimensoes td){
    seta->x = td.seta.x;
    seta->y = td.seta.y;
}
void setaRastroAtualizar(){
    setaRastro = (selecSeta *) malloc(sizeof(selecSeta));
    *setaRastro = *seta;
    setaRastro->simbolo = "  ";
}
void imprimir(selecSeta *s){
    gotoxy(s->x, s->y);
    printf("%s", s->simbolo);
}

void persRastroIni(){
    persRastro = (lista *) malloc(sizeof(lista));
    *persRastro = *personagens;
    persRastro->simbolo = ' ';
}

void persCopiaIni(){
    persCopia = (lista *) malloc(sizeof(lista));
    *persCopia = *personagens;
}


void mover(lista *p, char tecla){
    switch(tecla){
        case TECLA_CIMA:
            p->y--;

            break;
        case TECLA_BAIXO:
            p->y++;

            break;
        case TECLA_DIREITA:
            p->x++;

            break;
        case TECLA_ESQUERDA:
            p->x--;

            break;
    }
}

void menuInicialExecutar(){
    printf("Colete os itens em 90 segundos"); printf("\n");
    printf("\n");
    printf("%c : Personagem", (char)184); printf("\n");
    printf("Item : Pontuacao"); printf("\n");
    printf("\n");
    printf("%c : +150", (char)005); printf("\n");
    printf("%c : +50", (char)003); printf("\n");
    printf("%c : -200", (char)245); printf("\n");
    printf("\n");
    printf("Comandos"); printf("\n");
    printf("\n");
    printf("%c : CIMA", (char)TECLA_CIMA); printf("\n");
    printf("%c : BAIXO", (char)TECLA_BAIXO); printf("\n");
    printf("%c : DIREITA", (char)TECLA_DIREITA); printf("\n");
    printf("%c : ESQUERDA", (char)TECLA_ESQUERDA); printf("\n");
    printf("ESC : SAIR"); printf("\n");
    printf("\n");

    tecla = getch();

    if(tecla == TECLA_ESC){
        exit(1);
    }
}

void menuOpcoesExibir(const char *opcoes[], int tamanho){
    int i;

    int x = wherex();
    int y = wherey();

    for(i = 0; i < tamanho; i++){
        gotoxy(x, y+i);
        printf("%s", opcoes[i]);
    }
}

void selecMover(int opcoesQntd){
    switch(tecla){
        case TECLA_CIMA:
            if(opcaoSelec > 0){
                seta->y--;
                opcaoSelec--;
            }

            break;
        case TECLA_BAIXO:
            if(opcaoSelec < opcoesQntd-1){
                seta->y++;
                opcaoSelec++;
            }

            break;
    }
}

void setaAtualizar(int opcoesQntd){
    if((tecla == TECLA_BAIXO || tecla == TECLA_CIMA ||
        tecla == TECLA_ESQUERDA || tecla == TECLA_DIREITA) &&
       foiPressionado == 1){
        setaRastroAtualizar();
        selecMover(opcoesQntd);
        imprimir(setaRastro);
        imprimir(seta);
    }
}

void teclaPressionada(){
    if(kbhit()){
        tecla = getch();
        fflush(stdin);

        foiPressionado = 1;
    }
}

int enterPressionadoVer(){
    if(tecla == TECLA_ENTER){
        return 1;
    }
    return 0;
}
