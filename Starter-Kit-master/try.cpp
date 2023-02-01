#include <iostream>
#include <string>
#include <vector>
#include <cstdlib> // for system()
#include <ctime>   // for time() in srand( time(NULL) );
#include <iomanip> // for setw()
using namespace std;

class g_board
{
private:
    vector<vector<char>> map_;
    int dimX_, dimY_;
public:
    g_board(int dimX = 11, int dimY = 5);
    void init(int dimX, int dimY);
    void display() const;
};

g_board::g_board(int dimX, int dimY)
    : dimX_{dimX}, dimY_{dimY}
{
    init(dimX, dimY);
}

void g_board::init(int dimX, int dimY)
{
    dimX_ = dimX;
    dimY_ = dimY;
    const char ALIEN = 'A';
    const char ZOMBIE = 'Z';
    char objects[] = {' ', ' ', ' ', ' ', '<', '>', '^', 'v', 'r', 'p', 'h'};
    int noOfObjects = 11;
    map_.resize(dimY_);
    for (int i = 0; i < dimY_; ++i)
    {
        map_[i].resize(dimX_);
    }
    for (int i = 0; i < dimY_; ++i)
    {
        for (int j = 0; j < dimX_; ++j)
        {
            if (i == dimY_ / 2 && (j == dimX_ / 2 || j == dimX_ / 2 + 1))
            {
                if (j == dimX_ / 2)
                    map_[i][j] = ALIEN;
                else
                    map_[i][j] = ZOMBIE;
            }
            else
            {
                int objNo = rand() % noOfObjects;
                map_[i][j] = objects[objNo];
            }
        }
    }
}


void g_board::display() const
{
    cout << " --__--__--__--__--__--__--__--_" << endl;
    cout << " =       Alien VS Zombies      =" << endl;
    cout << " __--__--__--__--__--__--__--__-" << endl;
    // for each row
    for (int i = dimY_ - 1; i >= 0; --i)
    {
        // display upper border of the row
        cout << "   ";
        for (int j = 0; j < dimX_; ++j)
        {
            cout << "+---";
        }
        cout << "+" << endl;
        // display row number
        cout << setw(2) << (i + 1) << " ";
        // display cell content and border of each column
        for (int j = 0; j < dimX_; ++j)
        {
            cout << "| " << map_[i][j] << " ";
        }
        cout << "|" << endl;
    }
    // display lower border of the last row
    cout << "   ";
    for (int j = 0; j < dimX_; ++j)
    {
        cout << "+---";
    }
    cout << "+" << endl;
    // display column number
    cout << "    ";
    for (int j = 0; j < dimX_; ++j)
    {
        cout << " " << (j + 1) << "  ";
    }
    cout << endl
         << endl;
}
void test1_1()
{
    g_board g_board;
    g_board.display();
}
int main()
{
    int dimX = 11, dimY = 5;
    char choice;
    cout << "Do you want to change the default number of rows and columns (Default settings : 11x5)? (y/n): ";
    cin >> choice;
    if (choice == 'y')
    {
        cout << "Enter the number of columns: ";
        cin >> dimX;
        cout << "Enter the number of rows: ";
        cin >> dimY;
    }
    g_board gameBoard(dimX, dimY);
    gameBoard.display();
    

    return 0;

    srand(1);          // use this for fixed map during testing
    srand(time(NULL)); // try this for random map
    test1_1();
}
