#include <iostream>
#include "Windows.h"


using namespace std;


class Block {
public:
    bool solid = false;
    int id; // 0 = head, 1 = body, 2 = tail
    int dir;
    Block(bool _solid = false, int _id = 0,  int _dir = 0): solid(_solid), id(_id), dir(_dir){}
};


class Map {
public:
    int size;
    Block* map;
    Map(int _size = 5) : size(_size) {
        map = new Block[size, size];
    }
    ~Map() {
        delete[] map;
    }
};


int main() {
    static int deltaTime = 300;

    Map map = Map();
    while (!(GetKeyState(VK_ESCAPE) & 0x8000)) {
        if (GetKeyState(VK_LEFT) & 0x8000) {
            cout << "left" << endl;
        }
        else if (GetKeyState(VK_RIGHT) & 0x8000) {
            cout << "right" << endl;
        }
        else if (GetKeyState(VK_UP) & 0x8000) {
            cout << "up" << endl;
        }
        else if (GetKeyState(VK_DOWN) & 0x8000) {
            cout << "left" << endl;
        }
        Sleep(300);
        system("cls");
    }
    
    


	return 1;
}