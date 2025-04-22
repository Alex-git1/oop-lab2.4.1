#pragma once
#include <iostream>
#include <cmath>
#include <sstream>

using namespace std;

class Vector {
private:
    int* elements; 
    int size;      

public:

    Vector();                                   
    Vector(int size);                           
    Vector(int size, const int* values);        
    Vector(const Vector& other);                
    ~Vector();                                  

    int getSize() const;                        
    void setSize(int newSize);                  
    int getElement(int index) const;            
    void setElement(int index, int value);      

    friend Vector operator+(const Vector& l, const Vector& r);
    friend bool operator==(const Vector& v1, const Vector& v2);
    friend bool operator!=(const Vector& v1, const Vector& v2);
    double norm() const;                        

    Vector& operator=(const Vector& other);     
    int operator[](int index) const;            // читання
    int& operator[](int index);                 // запис

    friend std::ostream& operator<<(std::ostream& os, const Vector& vec);
    friend std::istream& operator>>(std::istream& is, Vector& vec);

    operator std::string() const;               
};