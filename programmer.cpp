#include "tubes.h"
void gotoxy(int x, int y){
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
void createListParent1(ListProgrammer &L){
    first(L) = NULL;
}

void createNewElmParent1 (adrProgrammer &P, string X){
    P = new Programmer;
    infoProgrammer(P) = X;
    prev(P) = null;
    next(P) = null;
}

void insertFirstParent1(ListProgrammer &L, adrProgrammer P){
    if (first(L) == NULL)
        first(L) = P;
    else{
        next(P) = first(L);
        prev(first(L)) = P;
        first(L) = P;
    }
}

void insertAfterParent1 (ListProgrammer &L,adrProgrammer &Prec ,adrProgrammer &P){
        next(P) = next(Prec);
        prev(P) = Prec;
        next(Prec) = P;
        prev(next(P)) = P;
}

void insertLastParent1 (ListProgrammer &L, adrProgrammer P){
    if (first(L) != null){
        prev(P) = last(L);
        next(last(L)) = P;
        last(L) = P;
    }else{
        first(L) = P;
        last(L) = P;
    }
}

void deleteFirstParent1 (ListProgrammer &L, adrProgrammer P){
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

void deleteAfterParent1 (ListProgrammer &L, adrProgrammer Prec, adrProgrammer P){
    P = next(Prec);
    next(Prec) = next(P);
    prev(next(P)) = prev(P);
    next(P) = NULL;
    prev(P) = NULL;
}
void deleteLastParent1 (ListProgrammer &L, adrProgrammer P){
    if (first(L) != NULL){
        P = last(L);
        last(L) = prev(P);
        next(last(L)) = NULL;
        prev(P) = NULL;
    }
}
adrProgrammer SearchParent1 (ListProgrammer L, string X){
    adrProgrammer Q = first(L);
    while(Q != NULL){
        if(infoProgrammer(Q) == X){
            return Q;
        }
        Q = next(Q);
    }
    return NULL;
}

void printInfoParent1 (ListProgrammer L){
    adrProgrammer P;
    P = first(L);
    int i = 1;
    int tab = 3;
    cout<<"-------------------------\n";
    cout<<"|    LIST PROGRAMMER    |\n";
    cout<<"-------------------------\n";
    while (P != null){
            cout<<"|"<<i<<" |"<<infoProgrammer(P);
            gotoxy(24,tab);cout<<"|"<<endl;
            tab = tab+1;
            P = next(P);
            i = i+1;
        }
    cout<<"-------------------------\n";
}
void inputProgrammer (ListProgrammer &L, adrProgrammer P){
    adrProgrammer Prec;
    if (first(L) != NULL){
        if (infoProgrammer(P) < infoProgrammer(first(L)))
            insertFirstParent1(L,P);
        else if (infoProgrammer(P)> infoProgrammer(last(L)))
            insertLastParent1(L, P);
        else
        {
            Prec = first(L);
            while (infoProgrammer(P) > infoProgrammer(Prec)){
                Prec = next(Prec);
            }
            Prec = prev(Prec);
            insertAfterParent1(L,Prec, P);
        }
    }else{
        first(L) = P;
        last(L) = P;
    }
}
void deleteProgrammer(ListProgrammer &L, adrProgrammer P){
    if (first(L) != NULL){
        if (P== first(L)){
            deleteFirstParent1(L,P);
        }else if(P == last(L)){
            deleteLastParent1(L,P);
        }else{
            deleteAfterParent1(L,prev(P),P);
        }
    }
}
void viewProgrammer (ListProgrammer &L){

}
