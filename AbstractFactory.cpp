#include <iostream>
#include <cmath>

using namespace std;

#pragma region Sofa

class Sofa{
public:
    virtual void print() = 0;
};

class VictorianSofa: public Sofa{
public:
    virtual void print() {
        cout << "VictorianSofa"<< endl;
    }
};

class ModernSofa: public Sofa{
public:
    virtual void print() {
        cout << "ModernSofa"<< endl;
    }
};

class ArtDecoSofa: public Sofa{
public:
    virtual void print() {
        cout << "ArtDoceSofa"<< endl;
    }
};

#pragma endregion

#pragma region Armchair

class Armchair{
public:
    virtual void print() = 0;
};

class VictorianArmchair: public Armchair{
public:
    virtual void print() {
        cout << "VictorianSofa"<< endl;
    }
};

class ModernArmchair: public Armchair{
public:
    virtual void print() {
        cout << "ModernSofa"<< endl;
    }
};

class ArtDecoArmchair: public Armchair{
public:
    virtual void print() {
        cout << "ArtDoceSofa"<< endl;
    }
};

#pragma endregion

#pragma region Table

class Table{
public:
    virtual void print() = 0;
};

class VictorianTable: public Table{
public:
    virtual void print() {
        cout << "VictorianTable"<< endl;
    }
};

class ModernTable: public Table{
public:
    virtual void print() {
        cout << "ModernTable"<< endl;
    }
};

class ArtDecoTable: public Table{
public:
    virtual void print() {
        cout << "ArtDecoTable"<< endl;
    }
};

#pragma endregion

class Factory{
public:
    virtual Armchair* CreateArmCheir() = 0;
    virtual Sofa* CreateSofa() = 0;
    virtual Table* CreateTable() = 0;
};

class VictorianFactory: public Factory{
public:
    virtual Armchair* CreateArmCheir(){
        return new VictorianArmchair();
    }

    virtual  Sofa* CreateSofa(){
        return new VictorianSofa();
    }

    virtual Table* CreateTable(){
        return new VictorianTable();
    }
};

class ModernFactory: public Factory{
public:
    virtual Armchair* CreateArmCheir(){
        return new ModernArmchair();
    }

    virtual  Sofa* CreateSofa(){
        return new ModernSofa();
    }

    virtual Table* CreateTable(){
        return new ModernTable();
    }
};


class ArtDecoFactory: public Factory{
public:
    virtual Armchair* CreateArmCheir(){
        return new ArtDecoArmchair();
    }

    virtual  Sofa* CreateSofa(){
        return new ArtDecoSofa();
    }

    virtual Table* CreateTable(){
        return new ArtDecoTable();
    }
};


class Client{
private:
    Factory* factory = nullptr;


public:
    void setFactory(Factory* factory){
        this->factory = factory;
    }

    Factory* getFactory(){
        return factory;
    }

    Client(Factory* factory){
        this->factory = factory;
    }
};

int main(){

    VictorianFactory victorianFactory;
    ModernFactory modernFactory;
    ArtDecoFactory artDecoArmchair;

    Client client(&victorianFactory);

    client.getFactory()->CreateSofa()->print();
    client.getFactory()->CreateTable()->print();

    client.setFactory(&artDecoArmchair);

    client.getFactory()->CreateSofa()->print();
    client.getFactory()->CreateTable()->print();
}