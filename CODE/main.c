#include <stdio.h>
#include <stdlib.h>
/*
    na start programu tworzony jest pierwszy obiekt.

    1.dodawanie studentów dan¹ iloœæ,
        1. tworzenie przestrzeni obiektu na koñcu listy.
            1.przejœcie do koñca listy (tylko raz)
            2.zapamiêtanie wskaŸnika do ostatniego elementu
        2. wprowadzanie danych.
        jeœl iloœæ =1 do wskaŸnika 0,
        jesli nie,
        zmniejsza iloœæ o 1,
    2.wyœwietlanie wszystkich studentów

*/
struct student{ // tworzymy strukture
    int ocena;
    char nazwisko[100];
    struct student *next_adress; // wskaxnik do nastepnego studenta
};

void add_students(int ilosc, struct student *ws_listy){ // ile i do ktorej listy
    struct student *current_student;

    current_student->next_adress=0; // nowy obiekt ma na koñcu 0, aby by³o zakoñczenie drzewa
}

void wpisz_dane_studenta(struct student *s){ // przekazujemy wskaŸnik na konkretny element
    printf("podaj ocene: \n");
    scanf("%d", &s->ocena); // tutaj to co wprowadzimy, jest przekazywane do obiektu s1
    printf("Podaj nazwisko: \n");
    scanf("%s", &s->nazwisko);  // s dla charow
}

void wyswietl( struct student s){ // wypisuje konkretny obiekt strukturalny
    printf("Student %s ma ocene %d\n", s.nazwisko, s.ocena);
}

int main()
{
    struct student *root;
    root=malloc(sizeof(struct student));
    root->next_adress=0; // aby zawsze na koñcu by³o 0

    wpisz_dane_studenta(root);

    //printf("%d\n", root); // wyœwietlamy aktualn¹ wartoœæ wskaŸnika na roota
    printf("Student %s ma ocene %d\n", &root->nazwisko, &root->ocena);
    //add_students(5, root);

    //wyswietl(*root);

    free(root);

    return 0;
}
