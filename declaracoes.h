#ifndef DECLARACOES_H_INCLUDED
#define DECLARACOES_H_INCLUDED

#endif // DECLARACOES_H_INCLUDED

#define TECLA_CIMA 72
#define TECLA_BAIXO 80
#define TECLA_ESQUERDA 75
#define TECLA_DIREITA 77
#define TECLA_ENTER 13
#define TECLA_ESPACO 32
#define TECLA_ESC 27
#define TECLA_s 115
#define TECLA_S 83
#define TECLA_n 110
#define TECLA_N 78

#define PAREDE (char)178

#define CORACAO (char)003
#define PAUS (char)005
#define DIAMANTE (char)004
#define ESPADA (char)006
#define PARAGRAFO (char)245
#define PEDEMOSCA (char)244

#define SETACIMA (char)024
#define SETABAIXO (char)025
#define SETADIREITA (char)026
#define SETAESQUERDA (char)027
//#define

// Define cores
enum {
    COLOR_BLACK,
    COLOR_BLUE,
    COLOR_GREEN,
    COLOR_CYAN,
    COLOR_RED,
    COLOR_MAGENTA,
    COLOR_BROWN,
    COLOR_GREY,
    COLOR_DARKGREY,
    COLOR_LIGHTBLUE,
    COLOR_LIGHTGREEN,
    COLOR_LIGHTCYAN,
    COLOR_LIGHTRED,
    COLOR_LIGHTMAGENTA,
    COLOR_YELLOW,
    COLOR_WHITE
};

// Define coordenadas da janela
void setWindow(int Width, int Height);

// Posiciona cursor em x e y
void gotoxy(int x, int y);

// Define cor de fundo
void setBackgroundColor(int c);

// Define cor do caracter
void setColor(int ForgC);

int wherex();

int wherey();


typedef struct lista{
    int x, y;
    char simbolo;
    struct lista *prox;
} lista;

typedef struct {
    int x, y;
} coord;

typedef struct {
    int x, y;
    char *simbolo;
} selecSeta;

typedef struct {
    int origemX, origemY,
        tamanhoX, tamanhoY,
        opcoesX, opcoesY,
        setaX, setaY,
        tituloX, tituloY;
        coord legenda, descricao;
} telaInicialDimensoes;

typedef struct {
    coord origem, tamanho, titulo, tituloSecao1, tituloSecao2, itens, pontos, comandos, acoes, descricao, instrucao, seta, opcoes;
    int linhaSeparacaoX;
} telaComoJogarDimensoes;

typedef struct {
    coord origem, tamanho, titulo, descricao, instrucao, seta, opcoes;
    int meio;
} telaPontuacaoDimensoes;

typedef struct {
    coord origem, tamanho, separacao, labelPontuacao, campoPontuacao, labelTempo, campoTempo, obstaculo, barreira, personagem;
} telaPartidaDimensoes;

char tecla;
int selecPos, opcaoSelec, foiPressionado, enterPressionado, pontuacao, adicionouItens;
selecSeta *seta, *setaRastro;

lista *paredes, *itens, *personagens, *persRastro, *persCopia;

int tempo, pontuacao;
time_t tempoAnterior, tempoAtual;

const char *telaInicialMenuOpcoes[3] = {"Jogar", "Como jogar", "Sair"};
const char *telaComoJogarMenuOpcoes[2] = {"Jogar", "Voltar"};
const char *telaPontuacaoMenuOpcoes[2] = {"Jogar novamente", "Menu inicial"};
//const char telaComoJogarItens[6] = {PAUS, CORACAO, ESPADA, DIAMANTE, PARAGRAFO, PEDEMOSCA};
const char telaComoJogarItens[6] = {'A', 'B', 'C', 'D', 'X', 'Y'};
const char *telaComoJogarPontos[6] = {"+50", "+150", "+200", "+500", "-100", "-200"};
const char telaComoJogarComandos[5] = {'^', 'v', '>', '<', 'X'};
const char *telaComoJogarAcoes[5] = {"Cima", "Baixo", "Direita", "Esquerda", "Sair"};



void telaPartidaExecutar(int origemX, int origemY);
void telaPartidaMostrar(telaPartidaDimensoes td);
void telaPartidaAtualizar(telaPartidaDimensoes td);
void tempoAtualizar(telaPartidaDimensoes td);
void tempoApaga(telaPartidaDimensoes td);
void tempoImprime(telaPartidaDimensoes td);
int tempoTerminou();
void telaPartidaFrameExibir(telaPartidaDimensoes td);
void telaPartidaSeparacaoExibir(telaPartidaDimensoes td);
void telaPartidaLabelPontuacaoExibir(telaPartidaDimensoes td);
void telaPartidaCampoPontuacaoExibir(telaPartidaDimensoes td);
void telaPartidaLabelTempoExibir(telaPartidaDimensoes td);
void telaPartidaCampoTempoExibir(telaPartidaDimensoes td);
void telaPartidaBarreiraExibir(telaPartidaDimensoes td);
void telaPartidaObstaculoExibir(telaPartidaDimensoes td);

void telaComoJogarFrameExibir(telaComoJogarDimensoes td);
void telaComoJogarExecutar(int origemX, int origemY);
void telaComoJogarMostrar(telaComoJogarDimensoes td);
void telaComoJogarTituloExibir(telaComoJogarDimensoes td);
void telaComoJogarDescricaoExibir(telaComoJogarDimensoes td);
void telaComoJogarLegendaExibir(telaComoJogarDimensoes td);
void telaComoJogarSubtitulo1Exibir(telaComoJogarDimensoes td);
void telaComoJogarSubtitulo1Exibir(telaComoJogarDimensoes td);
void telaComoJogarItensExibir(telaComoJogarDimensoes td, const char itens[], int tamanho);
void telaComoJogarPontosExibir(telaComoJogarDimensoes td, const char *pontos[], int tamanho);
void telaComoJogarComandosExibir(telaComoJogarDimensoes td, const char comandos[], int tamanho);
void telaComoJogarAcoesExibir(telaComoJogarDimensoes td, const char *comandos[], int tamanho);
void telaComoJogarAtualizar();

void tracejar(int posicaoX);
void quebralinha(coord coord1);

void telaInicialLegendaExibir(telaInicialDimensoes td);
void telaInicialDescricaoExibir(telaInicialDimensoes td);

int retaImprimir(char caractere, int origemX, int origemY, int distancia, int angulo);
void retanguloCheioImprimir(char caractere, int origemX, int origemY, int tamanhoX, int tamanhoY);
void retanguloVazioImprimir(char caractere, int origemX, int origemY, int tamanhoX, int tamanhoY);

void telaInicialFrameExibir(telaInicialDimensoes td);
void telaInicialTituloExibir(telaInicialDimensoes td);

void telaPontuacaoExecutar(int origemX, int origemY);
void telaPontuacaoMostrar(telaPontuacaoDimensoes td);
void telaPontuacaoFrameExibir(telaPontuacaoDimensoes td);
void telaPontuacaoTituloExibir(telaPontuacaoDimensoes td);
void telaPontuacaoDescricaoExibir(telaPontuacaoDimensoes td);
void telaPontuacaoIntrucaoExibir(telaPontuacaoDimensoes td);
void telaPontuacaoAtualizar();
void telaPontuacaoRedirecionar();

void menuOpcoesExibir(const char *opcoes[], int tamanho);

void telaInicialMenuOpcoesExibir(telaInicialDimensoes td, const char *opcoes[], int tamanho);
void telaInicialOpcaoSelecExibir();
void telaInicialMostrar(telaInicialDimensoes td);

void selecMover(int opcoesQntd);
void setaAtualizar();

void telaInicialAtualizar();
void telaInicialExecutar();
void menuInicialExecutar();

void mover(lista *p, char tecla);
void setaIni();
void setaDeterminar(telaInicialDimensoes td);
void setaRastroAtualizar();
void imprimir(selecSeta *s);

// Cria uma nova lista
lista *lst_cria();
// Insere um novo elemento na lista com as coordenadas informadas
lista *lst_insere(lista *l, lista *no);
// Imprime objetos da lista
void lst_imprime(lista *l);
//verifica se há algum elemento na posição desejada
int lst_sobreposto(lista *no, lista *listaP);
// Retira um elemento que esteja nas coordenadas x e y
lista *lst_retira(lista *l, int x, int y);
lista *lst_criaNoRand(telaPartidaDimensoes td);


