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
            cout<<"Kreci korbka"<<endl;
        }
        void zatrzymajKrecenie(){
            korbka = false;
            cout<<"Przestaje krecic korbka"<<endl;
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

class MP3Player: public Odtwarzacz{
    private:
        string plik = "muzyka_z_MP3";
    public:
        MP3Player(string plik) : plik(plik){}
        void odtwarzaj() override{
            cout<<"Odtwarzam plik: "<<plik<<endl;
        }
        void zatrzymaj() override{
            cout<<"Zatrzymuje plik: "<<plik<<endl;
        }
};

int main(int argc, char const *argv[])
{
    int decyzja;
    Odtwarzacz *user = NULL;
    Katarynka *katarynka = new Katarynka();
    CDPlayer *cdPlayer = new CDPlayer("muzyka_z_CD");
    MP3Player *mp3Player = new MP3Player("muzyka_z_MP3");
    KatarynkaAdapter *katarynkaAdapter = new KatarynkaAdapter(katarynka);

    do{
        cout<<" 1. Odtwarzacz CD \n 2. Katarynka \n 3. Odtwarzacz MP3 \n 5. Graj \n 6. Zatrzymaj \n 0. Wyjdz"<<endl;
        cin>>decyzja;
        switch(decyzja){
            case 1:
                user = cdPlayer;
                cout<<"Wybrano CD"<<endl;
                break;
            case 2:
                user = katarynkaAdapter;
                cout<<"Wybrano Katarynke"<<endl;
                break;
            case 3:
                user = mp3Player;
                cout<<"Wybrano MP3"<<endl;
                break;
            case 5:
                if(user != NULL){
                    user->odtwarzaj();
                }
                break;
            case 6:
                if(user != NULL){
                    user->zatrzymaj();
                }
                break;
            case 0:
                cout<<"Wyjscie z programu"<<endl;
                break;
        }
    }while(decyzja != 0);

    delete(katarynka, cdPlayer, katarynkaAdapter, mp3Player);
    return 0;
}
