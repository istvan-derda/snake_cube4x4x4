

#include <iostream>
#include "Vector3.h"
#include <iomanip>
#include <ctime>


#ifdef DEBUG
int depth = 0;
int maxdepth = 0;
int startingpos = 0;
#endif

using namespace std;

bool solve(const char *rods, Vector3 pos, Vector3 facing, Vector3 *solution);

bool placeRod(Vector3 pos, Vector3 dir, char rod);

void removeRod(Vector3 pos, Vector3 dir, char rod);

bool tryMove(Vector3 dir, const char *rods, Vector3 pos, Vector3 *solution);

bool space[4][4][4] = { };

const char rodsN = 39;
const char rods[rodsN + 1] = {3, 1, 3, 1, 1,
                              1, 1, 2, 1, 1,
                              1, 1, 1, 2, 1,
                              3, 1, 2, 2, 3,
                              1, 2, 1, 1, 1,
                              1, 1, 1, 1, 1,
                              1, 3, 1, 3, 1,
                              3, 3, 3, 2, -1};

int main() {
    time_t start = time(0);
    cout<<ctime(&start)<<endl;

    cout << "A program for solving THE SNAKE CUBE" << endl;

    Vector3 solution[rodsN];
    Vector3 facing = Vector3(0, 0, 0);

    bool solved = false;
    for (int x = 0; x < 2; x++) {
        for (int y = 0; y < 2; y++) {
            for (int z = 0; y < 2; y++) {
#ifdef DEBUG
                startingpos++;
#endif
                Vector3 pos = Vector3(x, y, z);
                solved = solve(rods, pos, facing, solution);
#ifdef DEBUG
                maxdepth=0;
                depth=0;
#endif
                if (solved) { break; }
            }
            if (solved) { break; }
        }
        if (solved) { break; }
    }

    time_t end = time(0);
    time_t total = difftime(end, start);
    cout<<ctime(&total)<<endl;

    cout << solved << endl;
    for (int i = 0; i < rodsN; i++) {
        cout << solution[i] << endl;
    }


    return 0;
}


bool solve(const char *rods, Vector3 pos, Vector3 facing, Vector3 *solution) {
    if (*rods == -1) return true;

#ifdef DEBUG
    depth++;
    if (depth > maxdepth) { maxdepth = depth; };
    cout << setw(depth) << "|" << depth << endl;
    cout << setw(maxdepth) << "|" << maxdepth << endl;
    cout << startingpos;
#endif

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
#ifdef DEBUG
    depth--;
#endif


    return false;
}

bool tryMove(Vector3 dir, const char *rods, Vector3 pos, Vector3 *solution) {
    bool fits = placeRod(pos, dir, *rods);
    if (fits) {
        Vector3 newPos = pos + (dir * *rods);
        if (solve(rods + 1, newPos, dir, solution + 1)) {
            *solution = dir;
            return true;
        } else {
            removeRod(pos, dir, *rods);
        }
    } else {
    }
    return false;
}

bool placeRod(Vector3 pos, Vector3 dir, char rod) {

    //check if rod is within bounds
    Vector3 newPos = pos + (dir * rod);
    if (!(newPos < 4 && newPos > -1)) {
        return false;
    }

    //check for collision with placed rods
    for (int i = 1; i <= rod; i++) {
        Vector3 p = pos + dir * i;
        if (space[p.x][p.y][p.z]) {
            return false;
        }
    }
    //place rod
    for (int i = 0; i <= rod; i++) {
        Vector3 p = pos + dir * i;
        space[p.x][p.y][p.z] = true;
    }
    return true;
}

void removeRod(Vector3 pos, Vector3 dir, char rod) {
    Vector3 newPos = pos + (dir * rod);
    for (int i = 0; i <= rod; i++) {
        Vector3 p = pos + (dir * i);
        space[p.x][p.y][p.z] = false;

    }
}
