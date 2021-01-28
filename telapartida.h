#ifndef TELAPARTIDA_H_INCLUDED
#define TELAPARTIDA_H_INCLUDED
#endif // TELAPARTIDA_H_INCLUDED

void telaPartidaExecutar(int origemX, int origemY){
    tempo = 90;
    pontuacao = 0;

    enterPressionado = 0;
    foiPressionado = 0;
    opcaoSelec = 0;
    tecla = '\n';

    tempoAtual = time(NULL);
    tempoAnterior = time(NULL);

    telaPartidaDimensoes td;

    td.origem.x = origemX;
    td.origem.y = origemY;
    td.tamanho.x = 60;
    td.tamanho.y = 25;

    td.separacao.x = td.origem.x;
    td.separacao.y = td.origem.y+2;

    td.labelPontuacao.x = td.origem.x+3;
    td.labelPontuacao.y = td.origem.y+1;
    td.campoPontuacao.x = td.origem.x+18;
    td.campoPontuacao.y = td.labelPontuacao.y;

    td.labelTempo.x = td.campoPontuacao.x+5;
    td.labelTempo.y = td.campoPontuacao.y;
    td.campoTempo.x = td.labelTempo.x+7;
    td.campoTempo.y = td.labelTempo.y;

    td.obstaculo.x = td.separacao.x+40;
    td.obstaculo.y = td.separacao.y+5;
    td.barreira.x = td.separacao.x;
    td.barreira.y = td.separacao.y+10;

    td.personagem.x = td.separacao.x+4;
    td.personagem.y = td.separacao.y+4;

    telaPartidaMostrar(td);

    telaPartidaCarregar(td);

    while(!tempoTerminou()){
        telaPartidaAtualizar(td);
        usleep(500);
    }

    telaPartidaDescarregar();

    telaPartidaRedirecionar();
}
void telaPartidaMostrar(telaPartidaDimensoes td){
    telaPartidaFrameExibir(td);
    telaPartidaSeparacaoExibir(td);
    telaPartidaLabelPontuacaoExibir(td);
    telaPartidaCampoPontuacaoExibir(td);
    telaPartidaLabelTempoExibir(td);
    telaPartidaCampoTempoExibir(td);
    telaPartidaBarreiraExibir(td);
    telaPartidaObstaculoExibir(td);
}
void telaPartidaFrameExibir(telaPartidaDimensoes td){
    retanguloVazioImprimir(PAREDE, td.origem.x, td.origem.y, td.tamanho.x, td.tamanho.y);
}
void telaPartidaSeparacaoExibir(telaPartidaDimensoes td){
    retaImprimir('-', td.separacao.x, td.separacao.y, td.tamanho.x, 0);
}
void telaPartidaLabelPontuacaoExibir(telaPartidaDimensoes td){
    gotoxy(td.labelPontuacao.x, td.labelPontuacao.y);
    printf("Pontuacao: ");
}
void telaPartidaCampoPontuacaoExibir(telaPartidaDimensoes td){
    gotoxy(td.campoPontuacao.x, td.campoPontuacao.y);
    printf("%d", pontuacao);
}
void telaPartidaLabelTempoExibir(telaPartidaDimensoes td){
    gotoxy(td.labelTempo.x, td.labelTempo.y);
    printf("Tempo: ");
}
void telaPartidaCampoTempoExibir(telaPartidaDimensoes td){
    gotoxy(td.campoTempo.x, td.campoTempo.y);
    printf("%d", tempo);
}
void telaPartidaBarreiraExibir(telaPartidaDimensoes td){
    retaImprimir('-', td.barreira.x, td.barreira.y, 10, 0);
    retaImprimir('-', td.barreira.x+10, td.barreira.y, 10, 270);
}
void telaPartidaObstaculoExibir(telaPartidaDimensoes td){
    retanguloCheioImprimir('-', td.obstaculo.x, td.obstaculo.y, 8, 8);
}
void telaPartidaCarregar(telaPartidaDimensoes td){
    personagemCarregar(td);
    paredesCarregar(td);
    itensCarregar(td);
}
void personagemCarregar(telaPartidaDimensoes td){
    personagens = lst_cria();

    lista *personagemNovo;
    personagemNovo = lst_criaNo(td.personagem.x, td.personagem.y, 'O');

    personagens = lst_insere(personagens, personagemNovo);
    lst_imprime(personagens);
}
void paredesCarregar(telaPartidaDimensoes td){
    paredes = retanguloVazioInvisivel(paredes, PAREDE, td.separacao.x, td.separacao.y, td.tamanho.x, td.tamanho.y-(td.separacao.y - td.origem.y));
    paredes = retaInvisivel(paredes, PAREDE, td.barreira.x, td.barreira.y, 10, 0);
    paredes = retaInvisivel(paredes, PAREDE, td.barreira.x+10, td.barreira.y, 10, 270);
    paredes = retanguloCheioInvisivel(paredes, PAREDE, td.obstaculo.x, td.obstaculo.y, 8, 8);

    lst_imprimeTodos(paredes);
}
void itensCarregar(telaPartidaDimensoes td){
    int quantidade;
    quantidade = 4;

    itens = lst_cria();
    while(quantidade > 0){
        lista *itemNovo;
        itemNovo = lst_criaNoRand(td);

        if(lst_sobreposto(itemNovo, itens) == 0 && lst_sobreposto(itemNovo, paredes) == 0){
            itens = lst_insere(itens, itemNovo);
            lst_imprime(itemNovo);
            quantidade--;
        }
    }

    adicionouItens = 1;
}
void telaPartidaDescarregar(){
    personagens = lst_libera(personagens);
    paredes = lst_libera(paredes);
    itens = lst_libera(itens);
}
void telaPartidaRedirecionar(){
    system("cls");
    telaPontuacaoExecutar(5, 5);
}
int tempoTerminou(){
    if(tempo <= 0){
        return 1;
    }
    return 0;
}
void telaPartidaAtualizar(telaPartidaDimensoes td){
    teclaPressionada();
    tempoAtualizar(td);
    personagemAtualizar(td);
}
void tempoAtualizar(telaPartidaDimensoes td){
    tempoAnterior = tempoAtual;
    tempoAtual = time(NULL);

    if(!adicionouItens){
        tempo = tempo - (int)(tempoAtual - tempoAnterior);

        tempoApaga(td);
        tempoImprime(td);
    }else{
        adicionouItens = 0;
    }
}
void tempoApaga(telaPartidaDimensoes td){
    gotoxy(td.campoTempo.x, td.campoTempo.y);
    printf("  ");
}
void tempoImprime(telaPartidaDimensoes td){
    gotoxy(td.campoTempo.x, td.campoTempo.y);
    printf("%d", tempo);
}
void personagemAtualizar(telaPartidaDimensoes td){
    if(foiPressionado == 1){
        persCopiaIni();
        mover(persCopia, tecla);
        if(lst_sobreposto(persCopia, paredes) == 0){
            persRastroIni();
            mover(personagens, tecla);
            lst_imprime(persRastro);
            lst_imprime(personagens);
        }

        if(lst_sobreposto(personagens, itens) == 1){
            lista *no;
            no = lst_noGet(itens, personagens->x, personagens->y);
            if(no != NULL){
                itens = lst_retira(itens, no->x, no->y);
                atualizaPontuacao(no->simbolo);
                itensAdiciona(td);
                pontuacaoApaga();
                setColor(COLOR_YELLOW);
                pontuacaoImprime();
                setColor(COLOR_GREY);
            }
        }
    }
    foiPressionado = 0;
}
void atualizaPontuacao(int simboloNo){
    switch(simboloNo){
        case 'A':
            pontuacao = pontuacao+50;

            break;
        case 'B':
            pontuacao = pontuacao+100;

            break;
        case 'C':
            pontuacao = pontuacao+150;

            break;
        case 'D':
            pontuacao = pontuacao+500;

            break;
        case 'X':
            pontuacao = pontuacao-100;

            break;
        case 'Y':
            pontuacao = pontuacao-200;

            break;
    }
}
void pontuacaoApaga(telaPartidaDimensoes td){
    gotoxy(td.campoPontuacao.x, td.campoPontuacao.y);
    printf("     ");
}
void pontuacaoImprime(telaPartidaDimensoes td){
    gotoxy(td.campoPontuacao.x, td.campoPontuacao.y);
    printf("%d", pontuacao);
}
void itensAdiciona(telaPartidaDimensoes td){
    int quantidade;
    quantidade = 2;

    while(quantidade > 0){
        lista *itemNovo;
        itemNovo = lst_criaNoRand(td);

        if(lst_sobreposto(itemNovo, itens) == 0 && lst_sobreposto(itemNovo, paredes) == 0){
            itens = lst_insere(itens, itemNovo);
            lst_imprime(itemNovo);
            quantidade--;
        }
    }

    adicionouItens = 1;
}


