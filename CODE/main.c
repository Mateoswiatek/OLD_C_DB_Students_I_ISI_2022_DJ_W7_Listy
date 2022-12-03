#include <stdio.h>
#include <stdlib.h>
/*
    na start programu tworzony jest pierwszy obiekt.

    1.dodawanie studentów daną ilość,
        1. tworzenie przestrzeni obiektu na końcu listy.
            1.przejście do końca listy (tylko raz)
            2.zapamiętanie wskaźnika do ostatniego elementu
        2. wprowadzanie danych.
        jeśl ilość =1 do wskaźnika 0,
        jesli nie,
        zmniejsza ilość o 1,
    2.wyświetlanie wszystkich studentów

*/
struct student{ // tworzymy strukture
    int ocena;
    char nazwisko[100];
    struct student *next_adress; // wskaxnik do nastepnego studenta
};

void add_students(int ilosc, struct student *ws_listy){ // ile i do ktorej listy
    struct student *current_student;
    printf("aktualny: %d\n", current_student);
    printf("ws listy powinno byc0 = %d\n", ws_listy);
    if(!ws_listy){
        ws_listy=malloc(sizeof(struct student));
        ws_listy->next_adress=0; // aby zawsze na końcu było 0
    }
    printf("aktualny: %d\n", current_student);
    printf("ws listy %d\n", ws_listy);
    current_student=ws_listy;
    printf("Powinny byc takie same: \n");
    printf("aktualny: %d\n", current_student);
    printf("ws listy %d\n", ws_listy);
    while(current_student->next_adress){ // dopoki istnieje kolejny obiekt, przechodzimy do kolejnego obiektu, bo musimy dojsc do ostatniego elmentu
        current_student=current_student->next_adress; // przechodzimy do kolejnych, dopóki jest nastêpny obiekt
    }
    // jestesmy na koncu listy w pętli będzie to co niżej
    wpisz_dane_studenta(current_student); //wpisujemy imie i naziwsko
    wyswietl(*current_student);
    current_student->next_adress=0; // nowy obiekt ma na końcu 0, aby było zakończeniew drzewa
}

void wpisz_dane_studenta(struct student *s){ // przekazujemy wskaźnik na konkretny element
    printf("podaj ocene: \n");
    scanf("%d", &s->ocena); // tutaj to co wprowadzimy, jest przekazywane do obiektu s
    printf("Podaj nazwisko: \n");
    scanf("%s", &s->nazwisko);  // s dla charow
}

void wyswietl( struct student s){ // wypisuje konkretny obiekt strukturalny
    printf("Student %s ma ocene %d\n", s.nazwisko, s.ocena);
}


int main()
{
    struct student *root; //pierwszy element
    root=0;

    //tu będzie while(1) a w nim case (menu co chce zrobić)
    add_students(1, root); // wpisujemy dane pierwszego studenta

    //printf("%d\n", root); // wyświetlamy aktualną wartość wskaźnika na roota
    //printf("Student %s ma ocene %d\n", &root->nazwisko, &root->ocena)

    //wyswietl(*root);

    free(root);

    return 0;
}
