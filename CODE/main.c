#include <stdio.h>
#include <stdlib.h>

#define WYJSCIE 9
struct student *root; //pierwszy element
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

void add_students(int ilosc, struct student *ws_listy){ // ile i do ktorej listy
    struct student *current_student, *new_student;
    int i=0;
    if(!ws_listy){ //jesli nie ma jeszcze listy
        ws_listy=malloc(sizeof(struct student));
        printf("przed zmiana\n");
        *root=ws_listy; // przypisanie roota do pierwszego elemtnu
        printf("po zmianie\n");
        fflush(stdout);

        wpisz_dane_studenta(ws_listy);
        ws_listy->next_adress=0;
        i++; // bo juz jednego utworzylismy
    }
    current_student=ws_listy;

    while(current_student->next_adress){              // Dopoki istnieje kolejny obiekt, przechodzimy do kolejnego obiektu, bo musimy dojsc do ostatniego elmentu
        current_student=current_student->next_adress; // Przechodzimy do kolejnych, dopóki jest nastepny obiekt
    }
    // jestesmy na koncu listy, current wskazuje na ostatni obiekt
    for(i; i<ilosc;i++){

        current_student->next_adress=malloc(sizeof(struct student)); // (1) w aktualneej strokturze wpisujemy adres do kolejnego

        current_student=current_student->next_adress; // (2) //current zaczyna wskazywaæ na nowo utworzony

        if(current_student==NULL){printf("\n=========================\n      blad pamieci\n=========================\n"); return 0;}

        wpisz_dane_studenta(current_student); // (3) wpisujemy dane studenta
    }
}

void wpisz_dane_studenta(struct student *s){ // przekazujemy wskaŸnik na konkretny element
    printf("podaj ocene: \n");
    scanf("%d", &s->ocena); // tutaj to co wprowadzimy, jest przekazywane do obiektu s
    printf("Podaj nazwisko: \n");
    scanf("%s", &s->nazwisko);  // s dla charow
    s->next_adress=0;
}

void wyswietl( struct student s){ // wypisuje konkretny obiekt strukturalny
    printf("Student %s ma ocene %d\n", s.nazwisko, s.ocena);
}

void wyswietl_all(struct student *lista_studentow){
    system("cls");
    if(!lista_studentow){
            printf("Nie ma zadnego studenta na liscie dodaj wybierajac z menu 1\n");
            return 0; // nie ma elementow
    }
    else{
        while(lista_studentow->next_adress){
            wyswietl(*lista_studentow);
            lista_studentow=lista_studentow->next_adress;
        }
        wyswietl(*lista_studentow);
    }
}

int main()
{
    while(1){
        int wybor, ilosc, pom;

        printf("Wybierz dzialanie:\n0 - dodawanie studentow(nawet jesli nie ma jeszcze listy)\n1 - wyswietlanie wszystkich studentow\n");
        printf("2 - znajdywanie studenta / tow, rozbudowac o wybor np wszyscy co maja dana ocene\nw tym zrobic tez dodatkowe operacje co z tymi zrobic(wyswietlic, usunac)\n %d - wyjscie\n", WYJSCIE);
        scanf("%d", &wybor);

        system("cls"); // oczyszczanie konsoli
        switch(wybor){
        case 0:
            printf("Podaj liczbe studentow: \n");
            scanf("%d", &ilosc);
            system("cls");
            add_students(ilosc, root); // wpisujemy dane studentow, tyle ile wpisano

            printf("root %d\n",root);

            printf("chcesz wyswietlic? 0/1 \n");
            scanf("%d", &pom);
            if(pom) wyswietl_all(root);
            break;
        case 1:
            printf("wyswietlanie wszystkich studentow\n");
            wyswietl_all(root);
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
        printf("wrocic do menu? 0/1\n", &pom);
        scanf("%d", &pom);
        if(!pom) break;

    }
        system("cls");
        free(root);
    }
    printf("dzieki za skorzystanie z programu\n");
    return 0;
}
