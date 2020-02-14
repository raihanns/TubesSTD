#include "tubes.h"
#include <iostream>

int main()
{
    mulai:
    system("cls");
    int pilihan;
    ListProgrammer L1;
    ListProject L2;
    ListRelasi L3;
    adrProgrammer P,P1,P2;
    adrProject Q,Q1,Q2;
    adrRelasi R;
    createListParent1(L1);
    createListParent2(L2);
    string username,user,prjk,tugas;

        cout<<"\n\t\t\t  Selamat datang di MENU Project Assignment \n";
        cout<<"\t\t\t\t  TUGAS BESAR STRUKTUR DATA \n";
        gotoxy(35,4);cout<<"=======L O G I N=======";
        gotoxy(35,5);cout<<"----------------------\n";
        gotoxy(35,6);cout<<"|1.| Administrator\t|"<<endl;
        gotoxy(35,7);cout<<"|2.| Manager\t\t|"<<endl;
        gotoxy(35,8);cout<<"|3.| Programmer\t|"<<endl;
        gotoxy(35,9);cout<<"|0.| Exit Program\t|"<<endl;
        gotoxy(35,10);cout<<"----------------------\n";
        gotoxy(35,11);cout<<"Masukkan Pilihan: ";
        cin>>pilihan;
        switch(pilihan){
        case 1:
            int in;
            do{
                system("cls");
                cout<<"1. Programmer"<<endl;
                cout<<"2. Projek"<<endl;
                cout<<"Masukkan Pilihan: ";
                cin>>in;
                switch(in){
                case 1:
                    int adm;
                    do{
                        system("cls");
                        cout<<"\n\t\t\t\t  Selamat datang Administrator \n";
                        cout<<"\t\t\t\t  ===MENU PROGRAMMER=== \n";
                        gotoxy(37,5);cout<<"-------------------\n";
                        gotoxy(37,6);cout<<"|1.|Input\t\t|"<<endl;
                        gotoxy(37,7);cout<<"|2.|Update\t\t|"<<endl;
                        gotoxy(37,8);cout<<"|3.|Delete\t\t|"<<endl;
                        gotoxy(37,9);cout<<"|4.|View\t\t|"<<endl;
                        gotoxy(37,10);cout<<"|5.|Back\t\t|"<<endl;
                        gotoxy(37,11);cout<<"-------------------\n";
                        gotoxy(37,12);cout<<"Masukkan Pilihan: ";
                        cin>>adm;
                        switch(adm){
                            case 1:
                                system("cls");
                                cout<<"\n\t\t\t\t  Selamat datang Administrator \n";
                                cout<<"\t\t\t\t  ===MENU INPUT PROGRAMMER=== \n";
                                gotoxy(37,5);cout<<"username: ";cin>>user;
                                createNewElmParent1(P, user);
                                P1 = SearchParent1(L1, user);
                                if (P1 == NULL){
                                    inputProgrammer(L1,P);
                                }else{
                                    while (SearchParent1(L1,user) != NULL){
                                        system("cls");
                                        cout<<"\n\t\t\t\t  Selamat datang Administrator \n";
                                        cout<<"\t\t\t\t  ===MENU INPUT PROGRAMMER=== \n";
                                        gotoxy(37,5);cout<<"Username sudah ada";
                                        gotoxy(37,6);cout<<"username: ";
                                        cin>>user;
                                    }
                                createNewElmParent1(P, user);
                                inputProgrammer(L1,P);
                                gotoxy(37,7);cout<<"Programmer berhasil didaftarkan"<<endl;
                                }
                                system("pause");
                                break;
                            case 2:
                                system("cls");
                                cout<<"\n\t\t\t\t  Selamat datang Administrator \n";
                                cout<<"\t\t\t\t  ===MENU UPDATE PROGRAMMER=== \n";
                                gotoxy(37,5);cout<<"Search: ";cin>>username;
                                P1 = SearchParent1(L1, username);
                                if (P1 != NULL){
                                    gotoxy(37,6);cout<<"Data ditemukan!"<<endl;
                                    gotoxy(37,7);cout<<"UPDATE PROGRAMMER"<<endl;
                                    gotoxy(37,8);cout<<"username lama: "<<infoProgrammer(P1)<<endl;
                                    gotoxy(37,9);cout<<"username baru: ";cin>>username;
                                    while (SearchParent1(L1,username) != NULL){
                                        system("cls");
                                        cout<<"\n\t\t\t\t  Selamat datang Administrator \n";
                                        cout<<"\t\t\t\t  ===MENU UPDATE PROGRAMMER=== \n";
                                        gotoxy(37,9);cout<<"Username sudah digunakan, masukkan username lain\n";
                                        gotoxy(37,10);cout<<"username baru: ";
                                        cin>>username;
                                    }
                                    deleteProgrammer(L1,P1);
                                    createNewElmParent1(P, username);
                                    inputProgrammer(L1,P);
                                    gotoxy(37,11);cout<<"UPDATE DATA SUKSES"<<endl;
                                }else{
                                    gotoxy(37,10);cout<<"Data tidak ditemukan"<<endl;
                                }
                                system("pause");
                                break;
                            case 3:
                                system("cls");
                                cout<<"Disini tempat DELETE Programmer"<<endl;
                                cout<<"Programmer yang ingin dihapus: ";cin>>username;
                                P1 = SearchParent1(L1, username);
                                if (P1 != NULL){
                                    deleteProgrammer(L1,P1);
                                    cout<<"Programmer ditemukan dan telah dihapus"<<endl;
                                }else{
                                    cout<<"Programmer tidak ditemukan"<<endl;
                                    while (SearchParent1(L1,username) == NULL){
                                        cout<<"Programmer yang ingin dihapus: ";cin>>username;
                                    }
                                    deleteProgrammer(L1,P1);
                                    cout<<"Programmer ditemukan dan telah dihapus"<<endl;
                                }
                                system("pause");
                                break;
                            case 4:
                                system("cls");
                                printInfoParent1(L1);
                                system("pause");
                                break;
                            case 5:
                                goto mulai;
                                break;
                                }
                        }while (adm != 0);
                        break;
                case 2:
                    int pjk;
                    do{
                        system("cls");
                        cout<<"\n\t\t\t\t  Selamat datang Administrator \n";
                        cout<<"\t\t\t\t  ===MENU PROJEK=== \n";
                        gotoxy(37,5);cout<<"-------------------\n";
                        gotoxy(37,6);cout<<"|1.|Input\t\t|"<<endl;
                        gotoxy(37,7);cout<<"|2.|Update\t\t|"<<endl;
                        gotoxy(37,8);cout<<"|3.|Delete\t\t|"<<endl;
                        gotoxy(37,9);cout<<"|4.|View\t\t|"<<endl;
                        gotoxy(37,10);cout<<"|5.|Back\t\t|"<<endl;
                        gotoxy(37,11);cout<<"-------------------\n";
                        gotoxy(37,12);cout<<"Masukkan Pilihan: ";
                        cin>>pjk;
                switch(pjk){
                    case 1:
                        system("cls");
                        cout<<"\n\t\t\t\t  Selamat datang Administrator \n";
                        cout<<"\t\t\t\t  ===MENU INPUT PROGRAMMER=== \n";
                        gotoxy(37,5);cout<<"Nama Projek: ";cin>>prjk;
                        createNewElmParent2(Q, prjk);
                        Q1 = SearchParent2(L2, prjk);
                        if (Q1 == NULL){
                            inputProject(L2,Q);
                        }else{
                            while (SearchParent2(L2,user) != NULL){
                                system("cls");
                                cout<<"\n\t\t\t\t  Selamat datang Administrator \n";
                                cout<<"\t\t\t\t  ===MENU INPUT PROJEK=== \n";
                                gotoxy(37,5);cout<<"Projek sudah ada";
                                gotoxy(37,6);cout<<"Projek: ";
                                cin>>prjk;
                                }
                            createNewElmParent2(Q, prjk);
                            inputProject(L2,Q);
                            gotoxy(37,7);cout<<"Projek berhasil didaftarkan"<<endl;
                            }
                            system("pause");
                        break;
                    case 2:
                        system("cls");
                                cout<<"\n\t\t\t\t  Selamat datang Administrator \n";
                                cout<<"\t\t\t\t  ===MENU UPDATE PROJEK=== \n";
                                gotoxy(37,5);cout<<"Search: ";cin>>tugas;
                                Q1 = SearchParent2(L2, tugas);
                                if (P1 != NULL){
                                    gotoxy(37,6);cout<<"Data ditemukan!"<<endl;
                                    gotoxy(37,7);cout<<"UPDATE PROJEK"<<endl;
                                    gotoxy(37,8);cout<<"Projek lama: "<<infoProject(Q1)<<endl;
                                    gotoxy(37,9);cout<<"Projek baru: ";cin>>tugas;
                                    while (SearchParent2(L2,tugas) != NULL){
                                        system("cls");
                                        cout<<"\n\t\t\t\t  Selamat datang Administrator \n";
                                        cout<<"\t\t\t\t  ===MENU UPDATE PROJEK=== \n";
                                        gotoxy(37,9);cout<<"Nama Projek sudah digunakan, masukkan nama projek lain\n";
                                        gotoxy(37,10);cout<<"Projek baru: ";
                                        cin>>tugas;
                                    }
                                    deleteProject(L2,Q1);
                                    createNewElmParent2(Q, tugas);
                                    inputProject(L2,Q);
                                    gotoxy(37,11);cout<<"UPDATE DATA SUKSES"<<endl;
                                }else{
                                    gotoxy(37,10);cout<<"Data tidak ditemukan"<<endl;
                                }
                                system("pause");
                                break;
                        break;
                    case 3:
                        system("cls");
                        cout<<"Projek yang ingin dihapus: ";cin>>tugas;
                        Q1 = SearchParent2(L2, tugas);
                        if (Q1 != NULL){
                            deleteProject(L2,Q1);
                            cout<<"Projek ditemukan dan telah dihapus"<<endl;
                        }else{
                            cout<<"Projek tidak ditemukan"<<endl;
                            while (SearchParent2(L2,tugas) == NULL){
                                cout<<"Projek yang ingin dihapus: ";cin>>tugas;
                            }
                            deleteProject(L2,Q1);
                            cout<<"Project ditemukan dan telah dihapus"<<endl;
                        }
                        system("pause");
                        break;
                    case 4:
                        system("cls");
                        printInfoParent2(L2);
                        system("pause");
                        break;

                        }
                        }while (pjk != 0);


                }//penutup switch programmer dan projek
            }while (in != 0); //penutup do programmer dan projek

        case 2:
            int mgr;
            do{
                system("cls");
                cout<<"===MENU MANAGER==="<<endl;
                cout<<endl;
                cout<<"1. Input"<<endl;
                cout<<"2. Update"<<endl;
                cout<<"3. Delete"<<endl;
                cout<<"4. View Total & Detail Semua Tugas"<<endl;
                cout<<"5. View Detail All Project"<<endl;
                cout<<"6. View TOP 5 Programmer"<<endl;
                cout<<"7. Back"<<endl;
                cin>>mgr;
                switch(mgr){
                    case 1:
                        system("cls");
                        cout<<"Disini tempat INPUT Tugas Manager"<<endl;
                        system("pause");
                        break;
                    case 2:
                        system("cls");
                        cout<<"Disini tempat UPDATE Tugas Manager"<<endl;
                        system("pause");
                        break;
                    case 3:
                        system("cls");
                        cout<<"Disini tempat DELETE Tugas Manager"<<endl;
                        system("pause");
                        break;
                    case 4:
                        system("cls");
                        cout<<"Disini tempat VIEW Total dan Detail Semua Penugasan"<<endl;
                        system("pause");
                        break;
                    case 5:
                        system("cls");
                        cout<<"Disini tempat VIEW DETAIL SETIAP PROJECT"<<endl;
                        system("pause");
                        break;
                    case 6:
                        system("cls");
                        cout<<"Disini tempat VIEW TOP 5 PROGRAMMER"<<endl;
                        system("pause");
                        break;
                    case 7:
                        goto mulai;
                        break;
                    }
            }while (mgr != 0);

        case 3:
            cout<<endl;
            break;

        case 0:
            break;

        default:
            gotoxy(35,12);
            cout<<"Anda salah memasukkan pilihan"<<endl;
            system("pause");
            goto mulai;

    return 0;
    }
}
