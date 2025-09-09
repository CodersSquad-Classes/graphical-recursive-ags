#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

int current_x, current_y;

ofstream lineas;

void draw(int x, int y)
{
    lineas << "(" << current_x << "," << current_y << ")";
    current_x += x;
    current_y += y;
    lineas << "(" << current_x << "," << current_y << ")" << endl;
}

void Hilbert_curve(int depth, int x, int y)
{
    if (depth > 0)
    {
        Hilbert_curve(depth -1, y, x);
    }
    draw(x,y);
    if (depth > 0)
    {
        Hilbert_curve(depth - 1, x, y);
    }
    draw(y,x);
    if (depth > 0)
    {
        Hilbert_curve(depth - 1, x, y);
    }
    draw(-x,-y);
    if (depth > 0)
    {
        Hilbert_curve(depth - 1, -y, -x);
    }
}

int main(int argc, char** argv)
{
    int recursion_val;
    int direction_x;
    int direction_y;  

    if (argc < 4)
    {
        cout << "You must write all components needed" << endl << "Example: " << argv[0] << " 3 0 10" << endl;
        return -1;
    }

    recursion_val = stoi(argv[1]);
    direction_x = stoi(argv[2]);
    direction_y = stoi(argv[3]);
    
    lineas.open("lines.txt");
    if (!lineas.is_open())
    {
        cout << "Error creating/opening lineas.txt";
        return -1;
    }
    else
    {
        Hilbert_curve(recursion_val, direction_x, direction_y);
    }
    lineas.close();
    return 0;
}