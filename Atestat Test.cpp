#include <bits/stdc++.h>

using namespace std::filesystem;
using namespace std;

int alegere;
string mesaj;

string ascii_to_hex(char c);
int Pozitie(int &a, int &b, int &c, int &d);
void Criptare(string mesaj);
void Decriptare(string mesaj);
void Mesaj();
void Extra();
string EncryptFile(string sir);

random_device rd;
mt19937 generator(rd());
uniform_int_distribution<int> intager(0, 100);

int main() {
    cout<<"Ce mesaj doresti sa il criptezi/decriptezi?"<<endl;
    getline(cin, mesaj);
    cout<<endl;
    Mesaj();
    cout<<endl;
    Extra();

    system("pause");
}

void Criptare(string mesaj) {
    string nume_bun;
    int a, b, c, d;
    int poz=Pozitie(a, b, c, d);
    int len=mesaj.size();
    for(int i=0; i<len; i++) {
        if(mesaj[i] >= 33 && mesaj[i] <= 126)
            mesaj[i]=((mesaj[i]-33+poz)%94)+33;
    }
    nume_bun=EncryptFile(mesaj);
    ofstream cript{ nume_bun + ".txt" };
    cript<<a<<" "<<b<<" "<<c<<" "<<d;
    cout<<nume_bun<<endl;
}

void Decriptare(string mesaj) {
    if(exists(mesaj + ".txt")) {
        ifstream decript(mesaj + ".txt");
        int len=mesaj.size();
        int i=0, a, b, c, d; decript >> a >> b >> c >> d;
        while(i < len) {
            if(mesaj[i]=='%') {
                
            }
            i++;
        }
    }
    else cout<<"Nu exista cheia de decodare"<<endl;
}

void Mesaj() {
        bool ok = false;
        cout<<"==================================="<<endl;
        cout<<"Alege ce doresti sa faci cu mesajul:"<<endl;
        cout<<"1. Criptarea Mesajului"<<endl;
        cout<<"2. Decriptarea Mesajului"<<endl;
        cout<<"==================================="<<endl;
        cin>>alegere;
        do {
            switch(alegere) {
                case 1: {
                    Criptare(mesaj);
                    ok = true;
                    break;
                }
                case 2: {
                    Decriptare(mesaj);
                    ok = true;
                    break;
                }
                default: {
                    cout<<"Optiune invalida!"<<endl;
                    cin>>alegere;
                    break;
                }
            }
        }while(!ok);
}

void Extra() {
    bool done=false;
    int extra=0;
    do {
        cout<<"==================================="<<endl;
        cout<<"Doresti sa mai faci ceva?"<<endl;
        cout<<"1. Da"<<endl;
        cout<<"2. Nu"<<endl;
        cout<<"==================================="<<endl;
        cin>>extra;
        switch(extra) {
            case 1: {
                Mesaj();
                break;
            }
            case 2: {
                done=true;
                break;
            }
        }
    }while(!done);
}

int Pozitie(int &a, int &b, int &c, int &d) {
    a=0, b=0, c=0, d=0;
    do {
        a=intager(generator);
        b=intager(generator);
        c=intager(generator);
        d=intager(generator);

        
    }while (a+b+c-d < 0);
    int pozitie = a+b+c-d;
    return pozitie;
}

string EncryptFile(string sir) {
    int a, b, c, d;
    string sir_bun="";
    int poz=Pozitie(a, b, c, d);
    int len=mesaj.size();
    char pula;
    for(int i=0; i<len; i++) {
        if(sir[i]==37 || sir[i]==92 || sir[i]==47 || sir[i]==58 || sir[i]==42 || sir[i]==63 || sir[i]==34 || sir[i]==60 || sir[i]==62 ||sir[i]==124)
            sir_bun+=("%" + ascii_to_hex(sir[i]));
        else sir_bun+=sir[i];
    }
    return sir_bun;
}

string DecryptFile(string sir) {

}

string ascii_to_hex(char c) {
    stringstream ah;

    ah << hex << uppercase << setw(2) << setfill('0'); 
    ah << static_cast<int>(c);

    return ah.str();
}

string hex_to_ascii(char c) {

}