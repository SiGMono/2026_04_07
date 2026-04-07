#include <iostream>

using namespace std;

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



int main(int argc, char const *argv[])
{
    
    return 0;
}
