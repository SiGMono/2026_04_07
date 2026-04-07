#include <iostream>

using namespace std;

        //  INTERFACE
class Odtwarzacz{
    public:
        virtual void odtwarzaj() = 0;
        virtual void zatrzymaj() = 0;
};

//  Old and depreciated class to be used in the exercise to adapt
class Katarynka{
    private:
        bool korbka;
    public:
        void krecKorbka(){
            korbka = true;
        }
        void zatrzymajKrecenie(){
            korbka = false;
        }
};

        //  ADAPTER
class KatarynkaAdapter: public Odtwarzacz{
    private:
        Katarynka *katarynka;
    public:
        KatarynkaAdapter(Katarynka *katarynka){
            this->katarynka = katarynka;
        }
        void odtwarzaj(void) override{
            this->katarynka->krecKorbka();
        }
        void zatrzymaj(void) override{
            this->katarynka->zatrzymajKrecenie();
        }
};

class CDPlayer: public Odtwarzacz{
    private:
        string plik = "muzyka_z_CD";
    public:
        CDPlayer(string plik) : plik(plik){}
        void odtwarzaj() override{
            cout<<"Odtwarzam plik: "<<plik<<endl;
        }
        void zatrzymaj() override{
            cout<<"Zatrzymuje plik: "<<plik<<endl;
        }
};

class MP3Player{

};

int main(int argc, char const *argv[])
{
    int decyzja;
    Odtwarzacz *user = NULL;
    Katarynka *Katarynka = new Katarynka();
    CDPlayer *cdPlayer = new CDPlayer("muzyka_z_CD");

    do{
        cout<<"1. Odtwarzacz CD \n 2. Katarynka \n 3. Odtwarzacz MP3 \n 0. Wyjdz"<<endl;
    }while(decyzja != 0);

    delete(Katarynka,cdPlayer);
    return 0;
}
