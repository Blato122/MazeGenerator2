#include <iostream>
#include <chrono>

#include "Maze.h"
#include "Graph.h"

int main(int argc, char *argv[]) {
    int rows = 0;
    int cols = 0;

    if (argc == 3) {
        rows = atoi(argv[1]);
        cols = atoi(argv[2]);
    } else {
        std::cerr << "usage: ./a.out [rows] [columns]" << std::endl;
        return 1;
    }

    Graph g(rows, cols);
    auto MST = g.kruskal();

    bool keep_playing = false;
    bool new_maze = false;
    int upper = -1;
    int lower = -1;

    do {
        if (new_maze) {
            MST = g.kruskal();
            upper = lower = -1;
        } // else upper and lower stay the same and the maze doesn't change

        Maze m(rows, cols, MST, upper, lower); // upper = lower = -1 -> generate new bounds
        m.generate();
        m.print();
        m.display();

        keep_playing = m.keepPlaying();
        new_maze = m.newMaze();
        upper = m.getUpper(); 
        lower = m.getLower();
    } while (keep_playing);
}