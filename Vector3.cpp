//
// Created by istvan on 27.12.19.
//

#include "Vector3.h"


Vector3::Vector3() {
    this->x = 0;
    this->y = 0;
    this->z = 0;
}

Vector3::Vector3(int x, int y, int z) : x(x), y(y), z(z) {};

Vector3 Vector3::operator+(Vector3 b) {
    return Vector3(b.x + this->x, b.y + this->y, b.z + this->z);
}

Vector3 Vector3::operator*(int b) {
    return Vector3(b * this->x, b * this->y, b * this->z);
}


bool Vector3::operator<(int b) {
    if (this->x > b) return false;
    if (this->y > b) return false;
    if (this->z > b) return false;
    return true;
}

bool Vector3::operator>(int b) {
    if (this->x < b) return false;
    if (this->y < b) return false;
    if (this->z < b) return false;
    return true;
}

