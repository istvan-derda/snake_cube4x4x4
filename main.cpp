

#include "Vector3.h"

using namespace std;


bool solve(const char *rods, Vector3 pos, Vector3 facing, Vector3 *solution);

bool placeRod(Vector3 pos, Vector3 dir, char rod);

void removeRod(Vector3 pos, Vector3 dir, char rod);

bool tryMove(Vector3 dir, const char *rods, Vector3 pos, Vector3 *solution);

bool space[3][3][3] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

int main() {


    const char rodsN = 40;
    const char rods[rodsN] = {
            3, 1, 3, 1, 1, 1, 1, 2, 1, 1, 1, 1, 1, 2, 1, 3, 1, 2, 2, 3, 1, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 3, 1, 3, 1, 3,
            3, 3, 2, -1};


    Vector3 solution[rodsN];
    Vector3 facing = Vector3(0, 0, 0);

    bool solved = false;
    for (int x = 0; x < 2; x++) {
        for (int y = 0; y < 2; y++) {
            for (int z = 0; y < 2; y++) {
                Vector3 pos = Vector3(x, y, z);
                solved = solve(rods, pos, facing, solution);
                if (solved) {break;}
            }
            if (solved){break;}
        }
        if (solved){break;}
    }


    return 0;
}


bool solve(const char *rods, Vector3 pos, Vector3 facing, Vector3 *solution) {
    if (*rods == -1) return true;


    Vector3 dir;
    if (facing.x == 0) {

        dir = Vector3(1, 0, 0);
        if (tryMove(dir, rods, pos, solution)) { return true; }

        dir = Vector3(-1, 0, 0);
        if (tryMove(dir, rods, pos, solution)) { return true; }

    }

    if (facing.y == 0) {

        dir = Vector3(0, 1, 0);
        if (tryMove(dir, rods, pos, solution)) { return true; }

        dir = Vector3(0, -1, 0);
        if (tryMove(dir, rods, pos, solution)) { return true; }
    }
    if (facing.z == 0) {

        dir = Vector3(0, 0, 1);
        if (tryMove(dir, rods, pos, solution)) { return true; }

        dir = Vector3(0, 0, -1);
        if (tryMove(dir, rods, pos, solution)) { return true; }

    }

    return false;
}

bool tryMove(Vector3 dir, const char *rods, Vector3 pos, Vector3 *solution) {
    bool fits = placeRod(pos, dir, *rods);
    if (fits) {
        Vector3 newPos = pos + (dir * *rods);
        if (solve(rods + 1, newPos, dir, solution)) {
            return true;
        } else {
            removeRod(pos, dir, *rods);
        }
    }
}

bool placeRod(Vector3 pos, Vector3 dir, char rod) {

    Vector3 newPos = pos + (dir * rod);
    if (newPos > 3 || newPos < 0) { return false; }

    for (int x = pos.x; x <= newPos.x; x += dir.x) {
        for (int y = pos.y; y <= newPos.y; y += dir.y) {
            for (int z = pos.z; z <= newPos.z; y += dir.z) {
                if (space[x][y][z]) { return false; }
            }
        }
    }
    for (int x = pos.x; x <= newPos.x; x += dir.x) {
        for (int y = pos.y; y <= newPos.y; y += dir.y) {
            for (int z = pos.z; z <= newPos.z; y += dir.z) {
                space[x][y][z] = true;
            }
        }
    }
}

void removeRod(Vector3 pos, Vector3 dir, char rod) {
    Vector3 newPos = pos + (dir * rod);
    for (int x = pos.x; x <= newPos.x; x += dir.x) {
        for (int y = pos.y; y <= newPos.y; y += dir.y) {
            for (int z = pos.z; z <= newPos.z; y += dir.z) {
                space[x][y][z] = false;
            }
        }
    }
}
