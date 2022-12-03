#include <stdio.h>
#include <stdlib.h>
/*
    na start programu tworzony jest pierwszy obiekt.

    1.dodawanie studentów dan¹ iloœæ,
        1. tworzenie przestrzeni obiektu na koñcu listy.
            X 1.przejœcie do koñca listy (tylko raz)
            X 2.zapamiêtanie wskaŸnika do ostatniego elementu
        2. wprowadzanie danych

    2.wyœwietlanie wszystkich studentów

*/
struct student{
    int ocena;
    char nazwisko[100];
    struct student *next_adress;
};

void add_students(int ilosc, struct student *ws_listy){ // ile i do ktorej listy
    struct student *current_student, *new_student;
    int i=0;
    if(!ws_listy){ //jeœli nie ma jeszcze listy
        ws_listy=malloc(sizeof(struct student));
        wpisz_dane_studenta(ws_listy);
        ws_listy->next_adress=0;
        printf("zerowy\n");
        wyswietl(ws_listy);
        printf("inne\n\n");
        i++; // bo juz jednego utworzylismy
    }
    current_student=ws_listy;

    while(current_student->next_adress){              // dopoki istnieje kolejny obiekt, przechodzimy do kolejnego obiektu, bo musimy dojsc do ostatniego elmentu
        current_student=current_student->next_adress; // przechodzimy do kolejnych, dopóki jest nastepny obiekt
    }
    // jestesmy na koncu listy, current wskazuje na ostatni obiekt
    for(i; i<ilosc;i++){ //jpg paint

        current_student->next_adress=malloc(sizeof(struct student)); // (1) w aktualneej strokturze wpisujemy adres do kolejnego

        printf("poprzedni:\n"); // do testow
        wyswietl(current_student);

        current_student=current_student->next_adress; // (2)

        printf("randomowe\n");
        wyswietl(current_student);

        wpisz_dane_studenta(current_student); // (3) wpisujemy dane studenta

        printf("aktualnie wpisany\n");
        wyswietl(current_student);
    }

    /*
    for(i; i<ilosc;i++){
        new_student=malloc(sizeof(struct student));
        current_student->next_adress=new_student; // w aktualneej strokturze wpisujemy adres do kolejnego
        wpisz_dane_studenta(new_student); // wpisujemy dane studenta
        printf("poprzedni\n"); // do testow
        wyswietl(current_student);
        printf("aktualnie wpisany\n");
        wyswietl(*new_student);
        current_student=new_student; // zaczynamy wskazywac na nowo utworzonego, w petli
    }*/





    current_student->next_adress=0; // ostatni obiekt ma na koñcu 0, aby by³o zakoñczeniew drzewa
}

void wpisz_dane_studenta(struct student *s){ // przekazujemy wskaŸnik na konkretny element
    printf("podaj ocene: \n");
    scanf("%d", &s->ocena); // tutaj to co wprowadzimy, jest przekazywane do obiektu s
    printf("Podaj nazwisko: \n");
    scanf("%s", &s->nazwisko);  // s dla charow
    s->next_adress=0;
}

void wyswietl( struct student s){ // wypisuje konkretny obiekt strukturalny
    printf("Student %s ma ocene %d, nastepny wskaznik to %d\n", s.nazwisko, s.ocena, s.next_adress);
}


int main()
{
    struct student *root; //pierwszy element
    root=0;

    //tu bêdzie while(1) a w nim case (menu co chce zrobiæ)
    add_students(3, root); // wpisujemy dane pierwszego studenta

    //printf("%d\n", root); // wyœwietlamy aktualn¹ wartoœæ wskaŸnika na roota
    //printf("Student %s ma ocene %d\n", &root->nazwisko, &root->ocena)

    //wyswietl(*root);

    free(root);

    return 0;
}
