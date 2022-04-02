#include <iostream>
#include <string>

using namespace  std;

class animal{
public:
    virtual void type ()=0;
};

class dog : public animal{
    string breed;
public:
    dog(const string &breed) : breed(breed) {}

    void type(){
        cout<<"Tengo un perro de raza " << breed;
    }
};


class DecoratorA : public animal{
    string color;
    animal &Animal;
public:

    DecoratorA(const string &color, animal &animal) : color(color), Animal(animal) {}

    void type(){
        Animal.type();
        cout<<", es de color "<< color;
    }

};

class DecoratorB : public animal{
    int age;
    animal &Animal;
public:
    DecoratorB(int age, animal &animal) : age(age), Animal(animal) {}
    void type(){
        Animal.type();
        cout<<" y tiene "<< age<< " anios";
    }
};




int main(){
    dog p1("Bulldog");
    dog p2("Golden retriever");

    p1.type();
    cout<<endl;
    p2.type();
    cout<<endl;

    //Decorador Color

    DecoratorA DogColorp1("Blanco", p1); // decorador color del perro
    DecoratorA DogColorp2("Dorado", p2);

    DogColorp1.type();
    cout<<endl;
    DogColorp2.type();
    cout<<endl;

    //Decorador anios

    DecoratorB agep1(5, p1);
    DecoratorB agep2(1, p2);

    agep1.type();
    cout<<endl;
    agep2.type();
    cout<<endl;



    //Decorar un decorador

    DecoratorB dog1(6, DogColorp1);
    DecoratorB dog2(3, DogColorp2);


    dog1.type();
    cout<<endl;
    dog2.type();
    cout<<endl;


return 0;
}