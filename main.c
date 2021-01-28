#include <stdio.h>
#include <stdlib.h>
#include <conio.h> // kbhit e getch
#include <unistd.h> // usleep
#include <time.h> // time
#include <windows.h> // Beep e SetConsoleTitle

#include "declaracoes.h"

#include "lista.h"
#include "console.h"
#include "comum.h"
#include "figurasgeometricas.h"
#include "grafico.h"
#include "telacomojogar.h"
#include "telainicial.h"
#include "telapontuacao.h"
#include "telapartida.h"

int main(){
    telaInicialExecutar(5, 5);

    gotoxy(80, 30);

    return 0;
}
