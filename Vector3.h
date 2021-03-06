//
// Created by istvan on 27.12.19.
//
#include <iostream>

#ifndef INC_4X4X4_VECTOR3_H
#define INC_4X4X4_VECTOR3_H

class Vector3 {

public:
    int x, y, z;

    Vector3();

    Vector3(int x, int y, int z);

    /**
     * Vector addition
     * @param b other vector
     * @return sum of the two vectors
     */
    Vector3 operator+(Vector3 b);

    /**
     * Vector scalar multiplication
     * @param b scalar
     * @return product of vector and scalar
     */
    Vector3 operator*(int b);

    /**
     * checks if any field of the vector is bigger than b
     * @param b number to compare with
     * @return b bigger than any field of the vector
     */
    bool operator<(int b);

    /**
     * checks if any field of the vector is smaller than b
     * @param b number to compare with
     * @return b bigger than any field of the vector
     */
    bool operator>(int b);

    friend std::ostream &operator<<(std::ostream &output, const Vector3 &vector3) {
        return output << "(" << vector3.x << ", " << vector3.y << ", " << vector3.z << ")";
    }

    /**
    * not equals
    * @param b
    * @return true if any field does not equal
    */
    bool operator!=(const Vector3 b);

};


#endif //INC_4X4X4_VECTOR3_H
