#include <conio.h>


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
    Map map = Map();
    //ƒа, € скопировал этот код с overflow, зато он работает.
    if (_getch() == '\033') { // if the first value is esc
        _getch(); // skip the [
        switch (_getch()) { // the real value
        case 'A':
            // code for arrow up
            break;
        case 'B':
            // code for arrow down
            break;
        case 'C':
            // code for arrow right
            break;
        case 'D':
            // code for arrow left
            break;
        }
    }


	return 1;
}