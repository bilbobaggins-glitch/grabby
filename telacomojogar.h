#ifndef TELACOMOJOGAR_H_INCLUDED
#define TELACOMOJOGAR_H_INCLUDED

#endif // TELACOMOJOGAR_H_INCLUDED

void telaComoJogarExecutar(int origemX, int origemY){
    enterPressionado = 0;
    foiPressionado = 0;
    opcaoSelec = 0;
    tecla = '\n';

    telaComoJogarDimensoes td;

    td.origem.x = origemX;
    td.origem.y = origemY;
    td.tamanho.x = 70;
    td.tamanho.y = 35;

    int meio = td.origem.x+((int)(td.tamanho.x/2));

    td.linhaSeparacaoX = meio;

    td.titulo.x = meio-2;
    td.titulo.y = td.origem.y+2;
    td.descricao.x = meio-18;
    td.descricao.y = td.titulo.y+2;
    td.tituloSecao1.x = meio-5;
    td.tituloSecao1.y = td.descricao.y+4;
    td.itens.x = meio-7;
    td.itens.y = td.tituloSecao1.y+2;
    td.pontos.x = meio+2;
    td.pontos.y = td.itens.y;
    td.tituloSecao2.x = meio-7;
    td.tituloSecao2.y = td.pontos.y+7;
    td.comandos.x = meio-7;
    td.comandos.y = td.tituloSecao2.y+2;
    td.acoes.x = meio+2;
    td.acoes.y = td.comandos.y;
    td.opcoes.x = meio-2;
    td.opcoes.y = td.acoes.y+6;
    td.seta.x = td.opcoes.x-3;
    td.seta.y = td.opcoes.y;
    td.instrucao.x = meio-11;
    td.instrucao.y = td.opcoes.y+4;

    telaComoJogarMostrar(td);

    while(!enterPressionadoVer()){
        telaComoJogarAtualizar();
        foiPressionado = 0;
    }

    telaComoJogarRedirecionar();
}

void telaComoJogarAtualizar(){
    teclaPressionada();
    setaAtualizar(2);
}

void telaComoJogarRedirecionar(){
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

void telaComoJogarMostrar(telaComoJogarDimensoes td){
    telaComoJogarFrameExibir(td);
    telaComoJogarTituloExibir(td);
    telaComoJogarDescricaoExibir(td);
    telaComoJogarIntrucaoExibir(td);
    telaComoJogarSubtitulo1Exibir(td);
    telaComoJogarSubtitulo2Exibir(td);
    telaComoJogarItensExibir(td, telaComoJogarItens, 6);
    telaComoJogarPontosExibir(td, telaComoJogarPontos, 6);
    telaComoJogarComandosExibir(td, telaComoJogarComandos, 5);
    telaComoJogarAcoesExibir(td, telaComoJogarAcoes, 5);
    telaComoJogarMenuOpcoesExibir(td, telaComoJogarMenuOpcoes, 2);
//
    setaIni();
    setaDeterminarComoJogar(td);
    opcaoSelec = 0;
//
    telaInicialOpcaoSelecExibir();
}

void telaComoJogarFrameExibir(telaComoJogarDimensoes td){
    retanguloVazioImprimir(PAREDE, td.origem.x, td.origem.y, td.tamanho.x, td.tamanho.y);
}

void telaComoJogarTituloExibir(telaComoJogarDimensoes td){
    gotoxy(td.titulo.x, td.titulo.y);
    printf("GRABBY");
}

void telaComoJogarDescricaoExibir(telaComoJogarDimensoes td){
    gotoxy(td.descricao.x, td.descricao.y);
    printf("O jogo consiste em conseguir a maior pontuacao"); quebralinha(td.descricao);
    printf("possivel dentro de 90 segundos coletando os"); quebralinha(td.descricao);
    printf("itens que surgem no mapa. ");
}

void telaComoJogarIntrucaoExibir(telaComoJogarDimensoes td){
    gotoxy(td.instrucao.x, td.instrucao.y);
    printf("Use as setas %c ou %c do teclado", '^', 'v');
    quebralinha(td.instrucao);
    printf("para selecionar a opcao ");
    quebralinha(td.instrucao);
    printf("e aperte ENTER para continuar.");
}

void telaComoJogarSubtitulo1Exibir(telaComoJogarDimensoes td){
    gotoxy(td.tituloSecao1.x, td.tituloSecao1.y);
    printf("Itens | Pontos");
}

void telaComoJogarSubtitulo2Exibir(telaComoJogarDimensoes td){
    gotoxy(td.tituloSecao2.x, td.tituloSecao2.y);
    printf("Comandos | Acao");
}

void telaComoJogarItensExibir(telaComoJogarDimensoes td, const char itens[], int tamanho){
    int i;

    for(i = 0; i < tamanho; i++){
        gotoxy(td.itens.x, td.itens.y+i);
        printf("%c", itens[i]);
        tracejar(td.linhaSeparacaoX);
        printf(":");
    }
}

void telaComoJogarPontosExibir(telaComoJogarDimensoes td, const char *pontos[], int tamanho){
    int i;
    for(i = 0; i < tamanho; i++){
        gotoxy(td.pontos.x, td.pontos.y+i);
        printf("%s", pontos[i]);
    }
}

void telaComoJogarComandosExibir(telaComoJogarDimensoes td, const char comandos[], int tamanho){
    int i;
    for(i = 0; i < tamanho; i++){
        gotoxy(td.comandos.x, td.comandos.y+i);
        if(i < 4){
            printf("%c", comandos[i]);
        }else{
            printf("ESC");
        }
        tracejar(td.linhaSeparacaoX);
        printf(":");

    }
}

void telaComoJogarAcoesExibir(telaComoJogarDimensoes td, const char *acao[], int tamanho){
    int i;
    for(i = 0; i < tamanho; i++){
        gotoxy(td.acoes.x, td.acoes.y+i);
        printf("%s", acao[i]);
        tracejar(td.linhaSeparacaoX);
    }
}
