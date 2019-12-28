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
    return x < b && y < b && z < b;
}

bool Vector3::operator>(int b) {
    return x > b && y > b && z > b;
}

bool Vector3::operator!=(const Vector3 b) {
    return b.x != x || b.y != y || b.z != z;
}

