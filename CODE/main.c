#include <stdio.h>
#include <stdlib.h>

#define WYJSCIE 9
int a=1;

// przy warunkach (chodzi o * przy charach)  *ws_poprzedni->nazwisko==F_nazwisko
/*
    na start programu tworzony jest pierwszy obiekt.

    1.dodawanie studentów dan¹ iloœæ,
        1. tworzenie przestrzeni obiektu na koñcu listy.
            X 1.przejœcie do koñca listy (tylko raz)
            X 2.zapamiêtanie wskaŸnika do ostatniego elementu
        2. wprowadzanie danych

    2.wyœwietlanie wszystkich studentów

    czyszczenie po ka¿dym przejsciu, po kazdym wpisanym studencie

*/

struct student{
    int ocena;
    char nazwisko[100];
    struct student *next_adress;
};

void wyswietl( struct student s){
    printf("Student %s ma ocene %d\n", s.nazwisko, s.ocena);
}

void wpisz_dane_studenta(struct student *s){ //wskaźnik bo zmieniamy
    printf("podaj ocene: \n");
    scanf("%d", &s->ocena);
    printf("Podaj nazwisko: \n");
    scanf("%s", s->nazwisko);
    s->next_adress=0;
}

void add_students(int ilosc, struct student *root, int czy_pierwszy_raz){ // bo za pierwszym razem musimy tam gdzie jestemsy dodac
    struct student *ws_listy;
    int i=0;
    ws_listy=root; // chcemy zmieniac lokalnie

    if(a){ // pierwszy student jesli wskazuje na 0
        wpisz_dane_studenta(root);
        i++;
        a=0;
    }
    while(ws_listy->next_adress){  // przejscie do ostatniego elementu
        ws_listy=ws_listy->next_adress;
    }

    for(i; i<ilosc;i++){
        ws_listy->next_adress=malloc(sizeof(struct student)); // (1) pole w struct wpisujemy adres do kolejnego

        ws_listy=ws_listy->next_adress;                       // (2) //wskaznik wskazuje na nowy element

        if(ws_listy==NULL){printf("\n====\n  blad pamieci\n====\n"); return;}

        wpisz_dane_studenta(ws_listy);                        // (3) wpisujemy dane studenta
    }
}

void wyswietl_all(struct student *root){
    struct student *lista_studentow;
    lista_studentow=root;
    wyswietl(*root); // roota
    while(lista_studentow->next_adress){
        lista_studentow=lista_studentow->next_adress;
        wyswietl(*lista_studentow);
    }
}

void znajdz(struct student *root, int tryb, int F_ocena, char F_nazwisko){ // tryb= 0-ocena 1-nazwisko
    struct student *ws_poprzedni, *lista_studentow;
    int dzialanie;
    printf("co chcesz zrobic ze znalezionymi\n0 - wyswietlic\n1 - usunac\n");
    scanf("%d", &dzialanie);
    ws_poprzedni=root;

    if(tryb) printf("tryb =1\n");
    printf("szukane = %d\n", F_nazwisko);
    printf("poprzedni_nazwisko = %d\n", *ws_poprzedni->nazwisko);
    if(tryb && *ws_poprzedni->nazwisko==F_nazwisko) printf("warunek zostal spelniony\n");

    //dla pierwszego elementu
    if( ((!tryb) && ws_poprzedni->ocena==F_ocena ) || (tryb && ws_poprzedni->nazwisko==F_nazwisko) ){
        if(dzialanie){
            wyswietl(*ws_poprzedni);
        }
        else{
            wyswietl(*ws_poprzedni);
        }
    }

    /*
    while(ws_poprzedni->next_adress){
    if( ((!tryb) && ws_poprzedni->ocena==F_ocena ) || (tryb && ws_poprzedni->nazwisko==F_nazwisko) ){
        student=ws_poprzedni->next_adress;
    }

    ws_poprzedni=ws_poprzedni->next_adress;
    */
}


int main()
{
    struct student *root=0;

    root=malloc(sizeof(struct student));
    root->next_adress=0;
    root->ocena = 0;

    printf("root basic= %d\n",root);

    while(1){
        int wybor, ilosc, pom;
        int F_ocena=0;
        char F_nazwisko= ' ';

        //system("cls");
        printf("Wybierz dzialanie:\n0 - dodawanie studentow\n1 - wyswietlanie wszystkich studentow\n");
        printf("2 - OCENA znajdywanie studenta\n3 - NAZWISKO znajdywnie studenta\n%d - wyjscie\n", WYJSCIE);
        scanf("%d", &wybor);

        system("cls"); // oczyszczanie konsoli
        switch(wybor){
        case 0:
            printf("Podaj liczbe studentow: \n");
            scanf("%d", &ilosc);
            add_students(ilosc, root, a);
            break;
        case 1:
            printf("wyswietlanie wszystkich studentow: \n");
            wyswietl_all(root);
            break;
        case 2:
            printf("podaj ocene:\n");
            scanf("%d", &F_ocena);
            znajdz(root, 0, F_ocena, ' ');
            break;
        case 3:
            printf("podaj nazwisko:\n");
            scanf("%s", &F_nazwisko);
            znajdz(root, 1, 0, F_nazwisko);
            break;
        case WYJSCIE:
            //free(root);
            printf("dzieki za skorzystanie z programu\n");
            fflush(stdout); // z bufora na stdout (standardowe wyjście); // pokazac ze bez tego nie wypisze // ew mozna zamienic z free(root)
            return 0;

        }

    if(wybor!=WYJSCIE){
        pom=0;
        printf("wrocic do menu? 0/1\n", &pom);
        scanf("%d", &pom);
        if(!pom) break;
        }
    }
    printf("dzieki za skorzystanie z programu\n");
    return 0;
}
