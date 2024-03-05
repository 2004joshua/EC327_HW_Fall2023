#ifndef PERSON_H
#define PERSON_H

class Person{
    private:
        double weight;
        double height; 
        char name[100];
    public:
        Person();
        Person(double weight, double height, char name[]);

        void setWeight(double weight);
        double getWeight();

        void setHeight(double height);
        double getheight();

        void setName(char name[]);
        char* getName();

        double getBMI();

};

#endif 