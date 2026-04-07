#include <iostream>

using namespace std;

        //  Old and depreciated class to be used in the exercise to adapt
class Katarynka{
    private:
        bool korbka;
    public:
        Katarynka(){
            this->korbka = false;
        }
        void krecKorbka(){
            if(this->korbka == true){
                cout<<"Korbka juz sie kreci nie trzeba jej rozkrecac"<<endl;
            }else{
                this->korbka = true;
                cout<<"Korbka zaczela sie krecic"<<endl;
            }
        }
        void zatrzymajKrecenie(){
            if(this->korbka == false){
                cout<<"Korbka juz jest zatrzymana nie trzeba jej zatrzymywac"<<endl;
            }else{
                this->korbka = false;
                cout<<"Korbka zostala zatrzymana"<<endl;
            }
        }
};

        //  INTERFACE
class Odtwarzacz{
    public:
        virtual void odtwarzaj() = 0;
        virtual void zatrzymaj() = 0;
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

int main(int argc, char const *argv[])
{
    
    return 0;
}
