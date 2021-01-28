#ifndef TELAINICIAL_H_INCLUDED
#define TELAINICIAL_H_INCLUDED

#endif // TELAINICIAL_H_INCLUDED

void telaInicialFrameExibir(telaInicialDimensoes td){
    retanguloVazioImprimir(PAREDE, td.origemX, td.origemY, td.tamanhoX, td.tamanhoY);
}

void telaInicialTituloExibir(telaInicialDimensoes td){
    gotoxy(td.tituloX, td.tituloY);
    printf("GRABBY");
}

void telaInicialMenuOpcoesExibir(telaInicialDimensoes td, const char *opcoes[], int tamanho){
    gotoxy(td.opcoesX, td.opcoesY);
    menuOpcoesExibir(opcoes, tamanho);
};

void telaComoJogarMenuOpcoesExibir(telaComoJogarDimensoes td, const char *opcoes[], int tamanho){
    gotoxy(td.opcoes.x, td.opcoes.y);
    menuOpcoesExibir(opcoes, tamanho);
};

void telaPontuacaoMenuOpcoesExibir(telaPontuacaoDimensoes td, const char *opcoes[], int tamanho){
    gotoxy(td.opcoes.x, td.opcoes.y);
    menuOpcoesExibir(opcoes, tamanho);
};

void telaInicialOpcaoSelecExibir(){
    imprimir(seta);
}

void telaInicialMostrar(telaInicialDimensoes td){
    telaInicialFrameExibir(td);
    telaInicialTituloExibir(td);
    telaInicialDescricaoExibir(td);
    telaInicialLegendaExibir(td);
    telaInicialMenuOpcoesExibir(td, telaInicialMenuOpcoes, 3);

    setaIni();
    setaDeterminar(td);
    opcaoSelec = 0;

    telaInicialOpcaoSelecExibir();
}

void telaInicialAtualizar(){
    teclaPressionada();
    setaAtualizar(3);
}

void telaInicialLegendaExibir(telaInicialDimensoes td){
    gotoxy(td.legenda.x, td.legenda.y);
    printf("Use as setas %c ou %c do teclado", '^', 'v');
    quebralinha(td.legenda);
    printf("para selecionar a opcao ");
    quebralinha(td.legenda);
    printf("e aperte ENTER para continuar.");
}

void telaInicialDescricaoExibir(telaInicialDimensoes td){
    gotoxy(td.descricao.x, td.descricao.y);
    printf("Escolha uma das opcoes abaixo: ");
}

void telaInicialRedirecionar(){
    system("cls");
    switch(opcaoSelec){
        case 0:
            telaPartidaExecutar(5, 5);

            break;
        case 1:
            telaComoJogarExecutar(5, 5);

            break;
        case 2:
            exit(1);

            break;
    }
}

void telaInicialExecutar(int origemX, int origemY){
    enterPressionado = 0;
    foiPressionado = 0;
    opcaoSelec = 0;
    tecla = '\n';

    telaInicialDimensoes td;

    td.origemX = origemX;
    td.origemY = origemY;
    td.tamanhoX = 45;
    td.tamanhoY = 15;

    td.tituloX = ((int)(td.tamanhoX/2))+td.origemX-7;
    td.tituloY = td.origemY+2;
    td.descricao.x = td.tituloX-9;
    td.descricao.y = td.tituloY+2;
    td.opcoesX = td.descricao.x+7;
    td.opcoesY = td.descricao.y+2;
    td.setaX = td.opcoesX-3;
    td.setaY = td.opcoesY;
    td.legenda.x = td.descricao.x;
    td.legenda.y = td.opcoesY+5;

    telaInicialMostrar(td);

    while(!enterPressionadoVer()){
        telaInicialAtualizar(2, 2);
        foiPressionado = 0;
    }

    telaInicialRedirecionar();
}

