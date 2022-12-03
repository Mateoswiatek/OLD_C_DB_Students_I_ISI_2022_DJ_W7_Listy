#include <stdio.h>
#include <stdlib.h>

#define WYJSCIE 9

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

void add_students(int ilosc, struct student *root){
    struct student *ws_listy;
    ws_listy=root; // chcemy zmieniac lokalnie
    while(ws_listy->next_adress){  // przejscie do ostatniego elementu
        ws_listy=ws_listy->next_adress;
    }

    for(int i=0; i<ilosc;i++){
        ws_listy->next_adress=malloc(sizeof(struct student)); // (1) pole w struct wpisujemy adres do kolejnego

        ws_listy=ws_listy->next_adress;                       // (2) //wskaznik wskazuje na nowy element

        if(ws_listy==NULL){printf("\n====\n  blad pamieci\n====\n"); return;}

        wpisz_dane_studenta(ws_listy);                        // (3) wpisujemy dane studenta
    }
}

void wyswietl_all(struct student *root){
    struct student *lista_studentow;
    lista_studentow=root;
    if(!(lista_studentow->next_adress)) printf("nie ma studentow\n");
    while(lista_studentow->next_adress){
        lista_studentow=lista_studentow->next_adress;
        wyswietl(*lista_studentow);
    }
}

int main()
{
    struct student *root=0;

    root=malloc(sizeof(struct student));
    root->next_adress=0;
    root->ocena = 0;

    //printf("root %d\n",root);

    while(1){
        int wybor, ilosc, pom;

        system("cls");
        printf("Wybierz dzialanie:\n0 - dodawanie studentow\n1 - wyswietlanie wszystkich studentow\n");
        printf("2 - znajdywanie studenta / tow, rozbudowac o wybor np wszyscy co maja dana ocene\nw tym zrobic tez dodatkowe operacje co z tymi zrobic(wyswietlic, usunac)\n%d - wyjscie\n", WYJSCIE);
        scanf("%d", &wybor);

        system("cls"); // oczyszczanie konsoli
        switch(wybor){
        case 0:
            printf("Podaj liczbe studentow: \n");
            scanf("%d", &ilosc);
            add_students(ilosc, root);
            break;
        case 1:
            printf("wyswietlanie wszystkich studentow: \n");
            wyswietl_all(root);
            break;
        case 2:
            printf("szukasz po:\n0 - ocenie\n1 - nazwisku\n");
            scanf("%d", &pom);
            // tu dalej CDN

            break;
        case WYJSCIE:
            free(root);
            printf("dzieki za skorzystanie z programu\n");
            fflush(stdout); // z bufora na stdout (standardowe wyjście); // pokazac ze bez tego nie wypisze // ew mozna zamienic z free(root)
            return 0;

        }

    //printf("%d\n", root); // wyœwietlamy aktualn¹ wartoœæ wskaŸnika na roota
    //printf("Student %s ma ocene %d\n", &root->nazwisko, &root->ocena)
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
