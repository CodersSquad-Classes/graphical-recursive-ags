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

int main()
{
    int recursion_val = 3;
    int direction_x = 0;
    int direction_y = 10;  

    
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