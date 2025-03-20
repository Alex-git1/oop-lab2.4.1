#include "Vector.h"
#include <iostream>
#include <cmath>
#include <sstream>

Vector::Vector() : size(0), elements(nullptr) {}

Vector::Vector(int size) : size(size) {
    if (size < 0) {
        cerr << "Error: size can't be negative!" << endl;
        this->size = 0;
        elements = nullptr;
    }
    else {
        elements = new int[size];
        for (int i = 0; i < size; ++i) {
            elements[i] = 0; 
        }
    }
}

Vector::Vector(int size, const int* values) : size(size) {
    if (size < 0) {
        cerr << "Error: size can't be negative!" << endl;
        this->size = 0;
        elements = nullptr;
    }
    else {
        elements = new int[size];
        for (int i = 0; i < size; ++i) {
            elements[i] = values[i];
        }
    }
}


Vector::Vector(const Vector& other) : size(other.size) {
    elements = new int[size];
    for (int i = 0; i < size; ++i) {
        elements[i] = other.elements[i];
    }
}

Vector::~Vector() {
    delete[] elements;
}

int Vector::getSize() const {
    return size;
}

void Vector::setSize(int newSize) {
    if (newSize < 0) {
        cerr << "Error: size can't be negative!" << endl;
        return;
    }
    int* newElements = new int[newSize];
    for (int i = 0; i < newSize; ++i) {
        newElements[i] = (i < size) ? elements[i] : 0; 
    }
    delete[] elements;
    elements = newElements;
    size = newSize;
}

int Vector::getElement(int index) const {
    if (index >= 0 && index < size) {
        return elements[index];
    }
    else {
        cerr << "Error: index is out of vectors border!" << endl;
        return 0; 
    }
}

void Vector::setElement(int index, int value) {
    if (index >= 0 && index < size) {
        elements[index] = value;
    }
    else {
        cerr << "Error: index is out of vectors border!" << endl;
    }
}

Vector Vector::operator+(const Vector& other) const {
    if (size != other.size) {
        cerr << "Error: vectors aren't equal!" << endl;
        return Vector();
    }
    Vector result(size);
    for (int i = 0; i < size; ++i) {
        result.elements[i] = elements[i] + other.elements[i];
    }
    return result;
}

bool Vector::operator==(const Vector& other) const {
    if (size != other.size) return false;
    for (int i = 0; i < size; ++i) {
        if (elements[i] != other.elements[i]) return false;
    }
    return true;
}

bool Vector::operator!=(const Vector& other) const {
    return !(*this == other);
}

double Vector::norm() const {
    if (size == 0) return 0;
    int min = elements[0], max = elements[0];
    for (int i = 1; i < size; ++i) {
        if (elements[i] < min) min = elements[i];
        if (elements[i] > max) max = elements[i];
    }
    return abs(max - min);
}

Vector& Vector::operator=(const Vector& other) {
    if (this != &other) {
        delete[] elements;
        size = other.size;
        elements = new int[size];
        for (int i = 0; i < size; ++i) {
            elements[i] = other.elements[i];
        }
    }
    return *this;
}

int Vector::operator[](int index) const {
    return getElement(index);
}

int& Vector::operator[](int index) {
    if (index >= 0 && index < size) {
        return elements[index];
    }
    else {
        cerr << "Error: index is out of vectors border!" << endl;
        static int dummy = 0; 
        return dummy;
    }
}

Vector::operator string() const {
    stringstream ss;
    ss << "[";
    for (int i = 0; i < size; ++i) {
        ss << elements[i];
        if (i < size - 1) ss << ", ";
    }
    ss << "]";
    return ss.str();
}

ostream& operator<<(ostream& os, const Vector& vec) {
    os << static_cast<string>(vec);
    return os;
}

istream& operator>>(istream& is, Vector& vec) {
    cout << "input size for vector: ";
    int newSize;
    is >> newSize;

    if (newSize < 0) {
        cerr << "Error: size can't be negative!" << endl;
        return is;
    }

    vec.setSize(newSize); 

    cout << "Input " << newSize << " vector's elements: ";
    for (int i = 0; i < newSize; ++i) {
        is >> vec.elements[i];
    }

    return is;
}