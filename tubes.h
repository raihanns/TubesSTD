#ifndef TUBES_H_INCLUDED
#define TUBES_H_INCLUDED

#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>

#define infoProgrammer(L) L->infoProgrammer
#define infoProject(L) L->infoProject
#define RProgrammer(L) L->RProgrammer
#define RProject(L) L->RProject

#define last(L) L.last
#define first(L) L.first
#define next(P) P->next
#define prev(P) P->prev
#define jumlahTugas(P) P->jumlahTugas
#define status(P) P-> status
#define null NULL

using namespace std;

typedef struct Programmer *adrProgrammer;
typedef struct Project *adrProject;
typedef struct Relasi *adrRelasi;

typedef struct Programmer
{
    string infoProgrammer;
    int jumlahTugas;
    adrProgrammer next;
    adrProgrammer prev;
};

typedef struct Project
{
    string infoProject;
    adrProject next;
    adrProject prev;
};

typedef struct Relasi
{
    string status;
    adrProgrammer RProgrammer; //pointer to parent dengan info programmer
    adrProject RProject; //pointer to parent dengan info project
    adrRelasi next; // pointer to next node dari list relasi
};

struct ListProgrammer
{
    adrProgrammer first;
    adrProgrammer last;
};

struct ListProject
{
    adrProject first;
    adrProject last;
};

struct ListRelasi
{
    adrRelasi first; //circular first linked list
};
void gotoxy(int x, int y);

void createListParent1 (ListProgrammer &L);
void createListParent2 (ListProject &L);
void createListRelasi (ListRelasi &L);

void createNewElmParent1 (adrProgrammer &P, string X);
void createNewElmParent2 (adrProject &P, string X);
void createNewElmRelasi (adrRelasi &P, adrProgrammer Q, adrProject R);

void insertFirstParent1 (ListProgrammer &L, adrProgrammer P);
void insertFirstParent2 (ListProject &L, adrProject P);
void insertFirstRelasi (ListRelasi &L, adrRelasi P);

void insertAfterParent1 (ListProgrammer &L,adrProgrammer &Prec ,adrProgrammer &P);
void insertAfterParent2 (ListProject &L,adrProject &Prec ,adrProject &P);
void insertAfterRelasi (ListRelasi &L,adrRelasi &Prec ,adrRelasi &P);

void insertLastParent1 (ListProgrammer &L, adrProgrammer P);
void insertLastParent2 (ListProject &L, adrProject P);
void insertLastRelasi (ListRelasi &L, adrRelasi P);

void deleteFirstParent1 (ListProgrammer &L, adrProgrammer P);
void deleteFirstParent2 (ListProgrammer &L, adrProject &P);
void deleteFirstRelasi (ListRelasi &L, adrRelasi &P);

void deleteAfterParent1 (ListProgrammer &L, adrProgrammer P, adrProgrammer Prec);
void deleteAfterParent2 (ListProject &L, adrProject &P, adrProject Prec);
void deleteAfterRelasi (ListRelasi &L, adrRelasi &P, adrRelasi Prec);

void deleteLastParent1 (ListProgrammer &L, adrProgrammer P);
void deleteLastParent2 (ListProject &L, adrProject &P);
void deleteLastRelasi (ListRelasi &L, adrRelasi &P);

adrProgrammer SearchParent1 (ListProgrammer L, string X);
adrProject SearchParent2 (ListProject L, string X);
adrRelasi SearchRelasi (ListRelasi L, string X);

void printInfoParent1 (ListProgrammer L);
void printInfoParent2 (ListProject L);
void printInfoRelasi (ListRelasi L);

//procedure untuk administrator
void inputProgrammer (ListProgrammer &L, adrProgrammer P);
void deleteProgrammer (ListProgrammer &L, adrProgrammer P);
void viewProgrammer (ListProgrammer &L);

void inputProject (ListProject &L, adrProject P);
void deleteProject (ListProject &L, adrProject &P);
void viewProject (ListProject &L);

//void sortParent1(ListProgrammer L, adrProgrammer P);

//procedure untuk manager
void inputPenugasan (ListRelasi &L, adrRelasi P);
void deletePenugasan (ListRelasi &L, adrRelasi &P);
void viewPenugasan (ListRelasi &L);
void top5Programmer (ListRelasi &L);

//procedure untuk programmer
#endif // TUBES_H_INCLUDED
