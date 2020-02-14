#include "tubes.h"

void createListParent2(ListProject &L){
    first(L) = NULL;
}
void createNewElmParent2 (adrProject &P, string X){
    P = new Project;
    infoProject(P) = X;
    prev(P) = null;
    next(P) = null;
}
void insertFirstParent2(ListProject &L, adrProject P){
    if (first(L) == NULL)
        first(L) = P;
    else{
        next(P) = first(L);
        prev(first(L)) = P;
        first(L) = P;
    }
}

void insertAfterParent2 (ListProject &L,adrProject &Prec ,adrProject &P){
        next(P) = next(Prec);
        prev(P) = Prec;
        next(Prec) = P;
        prev(next(P)) = P;
}

void insertLastParent2 (ListProject &L, adrProject P)
{
     if (first(L) != null){
        prev(P) = last(L);
        next(last(L)) = P;
        last(L) = P;
    }else{
        first(L) = P;
        last(L) = P;
    }
}

void deleteFirstParent2 (ListProject &L, adrProject &P)
{
    if (first(L) != NULL){
        if(next(first(L)) == NULL){
            first(L) = NULL;
            last(L) = NULL;
        }else{
            P = first(L);
            first(L) = next(P);
            next(P) = NULL;
            prev(first(L)) = NULL;
        }
    }
}

void deleteAfterParent2 (ListProject &L, adrProject &P, adrProject Prec)
{
    P = next(Prec);
    next(Prec) = next(P);
    prev(next(P)) = prev(P);
    next(P) = NULL;
    prev(P) = NULL;
}
void deleteLastParent2 (ListProject &L, adrProject &P)
{
    if (first(L) != NULL){
        P = last(L);
        last(L) = prev(P);
        next(last(L)) = NULL;
        prev(P) = NULL;
    }
}

adrProject SearchParent2 (ListProject L, string X)
{
    adrProject Q = first(L);
    while(Q != NULL){
        if(infoProject(Q) == X){
            return Q;
        }
        Q = next(Q);
    }
    return NULL;
}
void printInfoParent2 (ListProject L)
{
    adrProject P;
    P = first(L);
    int i = 1;
    int tab = 3;
    cout<<"-------------------------\n";
    cout<<"|      LIST PROJEK      |\n";
    cout<<"-------------------------\n";
    while (P != null){
            cout<<"|"<<i<<" |"<<infoProject(P);
            gotoxy(24,tab);cout<<"|"<<endl;
            tab = tab+1;
            P = next(P);
            i = i+1;
        }
    cout<<"-------------------------\n";
}

void inputProject (ListProject &L, adrProject P)
{
    adrProject Prec;
    if (first(L) != NULL){
        if (infoProject(P) < infoProject(first(L)))
            insertFirstParent2(L,P);
        else if (infoProject(P)> infoProject(last(L)))
            insertLastParent2(L, P);
        else
        {
            Prec = first(L);
            while (infoProject(P) > infoProject(Prec)){
                Prec = next(Prec);
            }
            Prec = prev(Prec);
            insertAfterParent2(L,Prec, P);
        }
    }else{
        first(L) = P;
        last(L) = P;
    }
}
void deleteProject (ListProject &L, adrProject &P)
{
    if (first(L) != NULL){
        if (P== first(L)){
            deleteFirstParent2(L,P);
        }else if(P == last(L)){
            deleteLastParent2(L,P);
        }else{
            deleteAfterParent2(L,prev(P),P);
        }
    }
}
void viewProject (ListProject &L)
{

}
