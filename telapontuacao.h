#ifndef TELAPONTUACAO_H_INCLUDED
#define TELAPONTUACAO_H_INCLUDED

#endif // TELAPONTUACAO_H_INCLUDED

void telaPontuacaoExecutar(int origemX, int origemY){
    enterPressionado = 0;
    foiPressionado = 0;
    opcaoSelec = 0;
    tecla = '\n';

    telaPontuacaoDimensoes td;

    td.origem.x = origemX;
    td.origem.y = origemY;
    td.tamanho.x = 45;
    td.tamanho.y = 15;

//    td.meio = (int)((td.origem.x+td.tamanho.x)/2);
    td.meio = ((int)(td.tamanho.x/2))+td.origem.x;

    td.titulo.x = td.meio-7;
    td.titulo.y = td.origem.y+2;
    td.descricao.x = td.titulo.x-9;
    td.descricao.y = td.titulo.y+2;
    td.opcoes.x = td.descricao.x+7;
    td.opcoes.y = td.descricao.y+2;
    td.seta.x = td.opcoes.x-3;
    td.seta.y = td.opcoes.y;
    td.instrucao.x = td.descricao.x;
    td.instrucao.y = td.opcoes.y+5;

    telaPontuacaoMostrar(td);

    while(!enterPressionadoVer()){
        telaPontuacaoAtualizar();
        foiPressionado = 0;
    }

    telaPontuacaoRedirecionar();
}
void telaPontuacaoMostrar(telaPontuacaoDimensoes td){
    telaPontuacaoFrameExibir(td);
    telaPontuacaoTituloExibir(td);
    telaPontuacaoDescricaoExibir(td);
    telaPontuacaoIntrucaoExibir(td);
    telaPontuacaoMenuOpcoesExibir(td, telaPontuacaoMenuOpcoes, 2);
//
    setaIni();
    setaDeterminarPontuacao(td);
    opcaoSelec = 0;
//
    telaInicialOpcaoSelecExibir();
}
void telaPontuacaoFrameExibir(telaPontuacaoDimensoes td){
    retanguloVazioImprimir(PAREDE, td.origem.x, td.origem.y, td.tamanho.x, td.tamanho.y);
}
void telaPontuacaoTituloExibir(telaPontuacaoDimensoes td){
    gotoxy(td.titulo.x, td.titulo.y);
    printf("GRABBY");
}
void telaPontuacaoDescricaoExibir(telaPontuacaoDimensoes td){
    gotoxy(td.descricao.x, td.descricao.y);
    printf("Voce atingiu %d pontos!", pontuacao);
}
void telaPontuacaoIntrucaoExibir(telaPontuacaoDimensoes td){
    gotoxy(td.instrucao.x, td.instrucao.y);
    printf("Use as setas %c ou %c do teclado", '^', 'v');
    quebralinha(td.instrucao);
    printf("para selecionar a opcao ");
    quebralinha(td.instrucao);
    printf("e aperte ENTER para continuar.");
}
void telaPontuacaoAtualizar(){
    teclaPressionada();
    setaAtualizar(2);
}
void telaPontuacaoRedirecionar(){
    system("cls");
    switch(opcaoSelec){
        case 0:
            telaPartidaExecutar(5, 5);

            break;
        case 1:
            telaInicialExecutar(5, 5);

            break;
    }
}
