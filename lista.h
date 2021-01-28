lista *lst_cria(){
    return NULL;
}
lista *lst_criaNo(int x, int y, char simbolo){
    lista *novo;
    novo = (lista *) malloc(sizeof(lista));

    novo->x = x;
    novo->y = y;
    novo->simbolo = simbolo;
    novo->prox = NULL;

    return novo;
}
lista *lst_criaNoRand(telaPartidaDimensoes td){
    lista *itemNovo;
    itemNovo = (lista *) malloc(sizeof(lista));

    srand(time(NULL));

    itemNovo->x = (rand()%td.tamanho.x)+td.separacao.x;
    itemNovo->y = (rand()%td.tamanho.y)+td.separacao.y-1;
    itemNovo->prox = NULL;

    int tipo;
    tipo = rand()%6;

    switch(tipo){
        case 0:
            itemNovo->simbolo = 'A';

            break;
        case 1:
            itemNovo->simbolo = 'B';

            break;
        case 2:
            itemNovo->simbolo = 'C';

            break;
        case 3:
            itemNovo->simbolo = 'D';

            break;
        case 4:
            itemNovo->simbolo = 'X';

            break;
        case 5:
            itemNovo->simbolo = 'Y';

            break;
    }

    return itemNovo;
}
lista *lst_insere(lista *l, lista *no){
    no->prox = l;

    return no;
}
lista *lst_retira(lista *l, int x, int y){
    lista *ant, *p;

    ant = NULL;
    p = l;

    while(p != NULL){
        if(p->x == x && p->y == y){
            break;
        }
        ant = p;
        p = p->prox;
    }

    if(p == NULL){
        return l;
    }

    if(ant == NULL){
        l = p->prox;
    }else{
        ant->prox = p->prox;
    }

    free(p);
    return l;
}
void lst_imprime(lista *l){
    lista *p;
    p = l;
    gotoxy(p->x, p->y);
    printf("%c", p->simbolo);
}
void lst_imprimeTodos(lista *l){
    lista *p;
    p = l;
    while(p != NULL){
        gotoxy(p->x, p->y);
        printf("%c", p->simbolo);
        p = p->prox;
    }
}
int lst_sobreposto(lista *no, lista* listaP){
    lista *lp;

    lp = listaP;
    while(lp != NULL){
        if(lp->x == no->x && lp->y == no->y){
            return 1;
        }
        lp = lp->prox;
    }

    return 0;
}
lista *lst_noGet(lista *lista1, int x, int y){
    lista *p;

    p = lista1;
    while(p != NULL){
        if(p->x == x && p->y == y){
            return p;
        }
        p = p->prox;
    }
    return NULL;
}

lista *lst_libera(lista *lista1){
    lista *p, *ant;

    ant = NULL;
    p = lista1;

    while(p != NULL){
        ant = p;
        p = p->prox;
        free(ant);
    }

    return NULL;
}
