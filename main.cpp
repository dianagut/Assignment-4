#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "Movie.h"
#include <vector>
#include "Inventory.h"
using namespace std;

int main() {
    ifstream infile("data4movies.txt");
    string line;
    Inventory inv;

    while (getline(infile, line))
    {
        Movie* m = Movie::fromLine(line);
        if (m) {
            inv.addItem(m);
        }
    }


}