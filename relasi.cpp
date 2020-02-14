#include "tubes.h"


void createListRelasi(ListRelasi &L){
    first(L) = NULL;
}





void createNewElmRelasi(adrRelasi &P, adrProgrammer &Q, adrProject &R){
    P = new Relasi;
    RProgrammer(P) = Q;
    RProject(P) = R;
    next(P) = NULL;
}




void insertFirstRelasi(ListRelasi &L, adrRelasi P){
    adrRelasi Q;
    Q = first(L);
    while (next(Q) != first(L))
        Q= next(Q);
    if (first(L) == NULL){
        first(L) = P;
        next(P) = first(L);
    }
    else{
        next(P) = first(L);
        next(Q) = P;
        first(L) = P;
    }
}


void insertAfterRelasi (ListRelasi &L,adrRelasi &Prec ,adrRelasi &P)
{
    next(P) = next(Prec);
    next(Prec) = next(P);
}

void insertLastRelasi (ListRelasi &L, adrRelasi P)
{
    adrRelasi Q = first(L);
    while (next(Q) != first(L)) //Q = last(L)
    {
        Q = next(Q);
    }
    if (first(L) != null)
    {
        next(P) =first(L);
        next(Q) = P;
    }
    else
    {
        insertFirstRelasi(L,P);
    }
}

void deleteFirstRelasi (ListRelasi &L, adrRelasi &P)
{
    adrRelasi Q = first(L);
    while (next(Q) != first(L)) //Q = last(L)
    {
        Q = next(Q);
    }
    first(L) = next(P);
    next(Q) = next(P);
    next(P) = NULL;
}

void deleteAfterRelasi (ListRelasi &L, adrRelasi &P, adrRelasi Prec)
{
    next(Prec) = next(P);
    next(P) = NULL;
}


void deleteLastRelasi (ListRelasi &L, adrRelasi &P)
{
    adrRelasi Q = first(L);
    while (next(next(Q)) != first(L)) // Q = prev(last(L))
    {
        Q = next(Q);
    }
    next(Q) = first(L);
    next(P) = NULL;
}

adrRelasi SearchRelasi(ListRelasi L, adrProgrammer P, adrProject Q, string X)
{
    adrRelasi S = first(L);
    while (S != NULL)
    {
        if (status(S) == X)
        {
            return S;
        }
        S = next(S);
    }
    return NULL;

}

void printInfoRelasi (ListRelasi L)
{
    adrRelasi P;
    P = first(L);
    while (next(P) != first(L))
        {
            cout<<infoProgrammer(RProgrammer(P))<<endl;
            cout<<infoProject(RProject(P))<<endl;
            cout<<status(P)<<endl;
            P = next(P);
        }
}

void inputPenugasan (ListRelasi &L, adrRelasi P)
{
    insertFirstRelasi(L,P);
}
void deletePenugasan (ListRelasi &L, adrRelasi &P)
{
    if (first(L) != NULL)
    {
        adrRelasi Q = first(L);
        while (next(Q) != first(L)) //Q = last(L)
        {
            Q = next(Q);
        }
        if (P == first(L))
        {
            deleteFirstRelasi(L,P);
        }
        else if (P = Q)
        {
            deleteLastRelasi(L,P);
        }
//        else
//        {
//            deleteAfterRelasi(L,P,Prec);
//        }
    }
}
void viewPenugasan (ListRelasi &L)
{
    printInfoRelasi(L);
}

void Project(ListRelasi &L)
{

}
void top5Programmer (ListRelasi &L)
{

}
