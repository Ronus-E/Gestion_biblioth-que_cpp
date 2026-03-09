//Nom : RAMANANA Mirindra Michel
//Num�ro d'inscription : 12ISST23-1331FGCIGInfo

#include <iostream>
#include <cstdlib>
#include <fstream>

using namespace std;



//Variables globales :
ofstream ajout_on;
ifstream ajout_in;
ofstream emprunt_on;
ifstream emprunt_in;
int nbre_livre,i,j,k,l;
string champs1,champs2,line,line2,titre,auteur,quantiter,genre;
string titre_tab[255],auteur_tab[255],quantiter_tab[255],genre_tab[255];
string nom_emprunt,titre_emprunt,auteur_emprunt,nbre_emprunt,date_emprunt;
string nom_emprunt_tab[255],titre_emprunt_tab[255],auteur_emprunt_tab[255],nbre_emprunt_tab[255],date_emprunt_tab[255];



//Fonctions et proc�dure :

void sauvegarder(){
    int valeur;
    ifstream fichierLecture("./donnee.json");
    if(fichierLecture>>valeur){
    i=valeur;
    }else{
        valeur=0;
    }
    fichierLecture.close();
    valeur++;
    ofstream fichierEcriture("./donnee.json");
    fichierEcriture<<valeur;
    fichierEcriture.close();
    i=valeur;
}

void cls(){
    system("cls");
}

struct champs1{
    string titre;
    string auteur;
    string quantiter;
    string genre;
};

void menu(){
    cls();
    cout << "VOICI LE MENU :" << endl;
    cout << "   1. Ajouter un livre " << endl;
    cout << "   2. Rechercher un livre  " << endl;
    cout << "   3. Inventaire des livres  " << endl;
    cout << "   4. Emprunter un livre " << endl;
    cout << "   5. Listes des livres emprunt�s  " << endl;
    cout << "   6. QUITTER " << endl;
}

void ajout_livre(){
    cls();
    cout<<"BIENVENUE DANS L'AJOUT D'UN LIVRE "<<endl<<endl<<endl;
    ajout_on.open("./.ajout des livres.json",ios::app);
    cout<<"Veuillez entrer le nombre de livre a inserer :";cin>>nbre_livre;

for(int g=1;g<=nbre_livre;g++){
            i;
            sauvegarder();
            cin.ignore();
                cout<<"Livre "<<i<<" :"<<endl<<endl;
            cout<<"     Titre du livre :";
            getline(cin,titre);
            ajout_on<<titre<<endl;
            titre_tab[i]=titre;

            cout<<"     Nom de l'auteur :";
            getline(cin,auteur);
            ajout_on<<auteur<<endl;
            auteur_tab[i]=auteur;

            cout<<"     Quantiter :";
            getline(cin,quantiter);
            ajout_on<<quantiter<<endl;
            quantiter_tab[i]=quantiter;

            cout<<"     Genre :";
            getline(cin,genre);
            ajout_on<<genre<<endl;
            genre_tab[i]=genre;

            cout<<"AJOUT DU LIVRE "<<titre_tab[i]<<" AVEC SUCCES !";
            i+=0;
            j++;

        cin.ignore();

}
    ajout_on.close();
    cin.ignore();
    getline(cin,champs1);
}

void recherche_livre(){
    cls();
    cout<<"RECHERCHER UN LIVRE"<<endl<<endl;
    string recherche;
    cout << "Veuiller entrer votre recherche par titre du livre ou par le nom de l'auteur : ";cin>>recherche;
    cout << "Voici les resultats du recherche : "<<endl<<endl;
    cin.ignore();
    for(i=1;i<=j;i++){
        if(recherche==titre_tab[i]||recherche==auteur_tab[i]){
                        cout<<"Resultats :"<<endl;
                        cout<<"     Titre :"<<titre_tab[i]<<endl;
                        cout<<"     Auteur :"<<auteur_tab[i]<<endl;
                        cout<<"     Quantiter :"<<quantiter_tab[i]<<endl;
                        cout<<"     Genre :"<<genre_tab[i]<<endl<<endl;

       }
    }
    cin.ignore();
}

void inventaire(){
    cls();
    cout<<"BIENVENUE DANS L'INVENTAIRE DES LIVRES"<<endl<<endl;
    ajout_in.open("./.ajout des livres.json");
    getline(ajout_in,line);
    ajout_in.seekg(0);
    if(line==""){
        cout<<"La liste est vide , veuillez en ajouter ";
    }else{
        cout<<"Voici les inventaires des livres : "<<endl<<endl;
        for(i=1;i<=j;i++){
                cout<<"Livre "<<i<<" :"<<endl;
                getline(ajout_in,line);
                cout<<"     Titre :"<<line<<endl;
                getline(ajout_in,line);
                cout<<"     Auteur :"<<line<<endl;
                getline(ajout_in,line);
                cout<<"     Quantiter :"<<line<<endl;
                getline(ajout_in,line);
                cout<<"     Genre :"<<line<<endl<<endl<<endl;
                l++;
            }
        }
    ajout_in.close();
    cin.ignore();
    getline(cin,line);
}

void emprunt(){
    cls();
    cout<<"BIENVENUE DANS L'EMPRUNT D'UN LIVRE"<<endl<<endl;

    emprunt_on.open("./.emprunter.json",ios::app);
    cin.ignore();
        cout<<"Nom de l'empreteur :";
        getline(cin,nom_emprunt);
        emprunt_on<<nom_emprunt<<endl;
        nom_emprunt_tab[i]=nom_emprunt;

        cout<<"Titre du livre emprunter :";
        getline(cin,titre_emprunt);
        emprunt_on<<titre_emprunt<<endl;
        titre_emprunt_tab[i]=titre_emprunt;

        cout<<"Nom de l'auteur du livre emprunter :";
        getline(cin,auteur_emprunt);
        emprunt_on<<auteur_emprunt<<endl;
        auteur_emprunt_tab[i]=auteur_emprunt;

        cout<<"Nombre de livre emprunter :";
        getline(cin,nbre_emprunt);
        emprunt_on<<nbre_emprunt<<endl;
        nbre_emprunt_tab[i]=nbre_emprunt;

        cout<<"Date :";
        getline(cin,date_emprunt);
        emprunt_on<<date_emprunt<<endl;
        date_emprunt_tab[i]=date_emprunt;

        k++;
        cout<<"ENREGISTRER AVEC SUCCES !"<<endl;

    emprunt_on.close();
    cin.ignore();
    getline(cin,champs2);
}

void listes_emprunt(){
    cls();
    cout<<"BIENVENUE DANS LA LISTES DES EMPRUNTS DES LIVRES"<<endl<<endl;
    emprunt_in.open("./.emprunter.json");
    getline(emprunt_in,line2);
    emprunt_in.seekg(0);
    if(line2==""){
        cout<<"La liste des est vide , personnes n'a emprunter aucun livre";
    }else{
        cout<<"Voici les empreteurs d'un livre : "<<endl<<endl;
        for(i=1;i<=k;i++){
                cout<<"Empreteur "<<i<<" :"<<endl;
                getline(emprunt_in,line2);
                cout<<"     Nom de l'empreteur :"<<line2<<endl;
                getline(emprunt_in,line2);
                cout<<"     Titre du livre emprunter :"<<line2<<endl;
                getline(emprunt_in,line2);
                cout<<"     Nom de l'auteur du livre emprunter :"<<line2<<endl;
                getline(emprunt_in,line2);
                cout<<"     Nombre de livre emprunter :"<<line2<<endl;
                getline(emprunt_in,line2);
                cout<<"     Date :"<<line2<<endl<<endl<<endl;
            }
        }
    emprunt_in.close();
    cin.ignore();
    getline(cin,line2);
}

//Fonction principale
int main()
{
    while(1){
    menu();
    int choix;
    cout << "Veuiller choisir un choix : ";cin>>choix;
        switch(choix){
            case 1: ajout_livre();break;
            case 2: recherche_livre();break;
            case 3: inventaire();break;
            case 4: emprunt();break;
            case 5: listes_emprunt();break;
            case 6: cout<<"Au revoir ..."; return 0;
            default:cout << "Choix invalide !Veuillez rechoisir votre choix"<<endl<<endl;
        }
    }
    return 0;
}
