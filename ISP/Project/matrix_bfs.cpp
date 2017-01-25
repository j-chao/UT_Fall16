/* Name:      Justin Chao
 * UT EID:    jc55395
 * Program:   matrix_bfs.cpp finds the shortest path through a generated binary
 *            maze using breadth-first search.
 * Reference: http://www.geeksforgeeks.org/shortest-path-in-a-binary-maze/
 */

#include <stdio.h>
#include <string.h>
#include <limits.h>
#include <math.h>
#include <iostream>
#include <queue>
using namespace std;
#define ROW 10
#define COL 10

// Point structure to store matrix cell cordinates
struct Point {
	int x;
	int y;
};

// Node structure for queue used in BFS
struct queueNode {
	Point pt; // The cordinates of a cell
	int dist; // cell's distance of from the source
};

// functions to be called
void fillMatrix(int matrix[ROW][COL]);
int BFS(int mat[][COL], Point src, Point dest);
bool isValid(int row, int col);
void printMatrix (int matrix[ROW][COL]);

// These arrays are used to get row and column
// numbers of 4 neighbors of a given cell
int rowNum[] = {-1, 0, 0, 1};
int colNum[] = {0, -1, 1, 0};


int main() {
    printf ("================= PROGRAM START =================");
    int mat[ROW][COL];
    int xs, ys, xd, yd;

    // randomly fill matrix
    fillMatrix(mat);
    printMatrix(mat);

    // prompt user for starting/destination cells
    cout << "\nEnter starting cell coordinates: x  y " << endl;
    scanf ("%d %d", &xs, &ys);
    cout << "Enter destination cell coordinates: x  y " << endl;
    scanf ("%d %d", &xd, &yd);

    // specify source and destination cells
	Point source = {xs, ys};
	Point dest = {xd, yd};

    printf ("\nStarting cell:      [%d, %d]\n", source.x, source.y);
    printf ("Destination cell:   [%d, %d]\n", dest.x, dest.y);

	int dist = BFS(mat, source, dest);

	if (dist != INT_MAX)
		cout << "\nShortest Path length: " << dist ;
	else
		cout << "\nNo possible paths.";


    printf ("\n\n================== PROGRAM END ==================");
	return 0;
}

// randomly fill binary matrix
void fillMatrix(int matrix[ROW][COL]) {
    int i, j;
    for (i=0; i<ROW; i++) {
        for (j=0; j<COL; j++) {
            matrix[i][j] = 1;
        }
    }

    // randomly select 20% of cells to be 0
    int num_blocks = ROW*COL*0.2;    
    int row_blocks[num_blocks];
    int col_blocks[num_blocks];
    for (i=0; i<num_blocks; i++) {
        row_blocks[i] = rand() % ROW;
        col_blocks[i] = rand() % COL;
    }
    
    // replace cells in matrix with selected block cells
    for (i=0; i<num_blocks; i++) {
        matrix[row_blocks[i]][col_blocks[i]] = 0;
    } 

    // ensure source and dest cells are 1
    matrix[0][0] = 1; 
    matrix[ROW-1][COL-1] = 1;
}

// BFS for shortest path between a given source cell to a destination cell.
int BFS(int mat[][COL], Point src, Point dest) {
    Point array[100];
    int count = 0;

	// check source and destination cell of the matrix have value 1
	if (!mat[src.x][src.y] || !mat[dest.x][dest.y]) 
		return INT_MAX;

	bool visited[ROW][COL];
	memset(visited, false, sizeof visited);
	
	// Mark the source cell as visited
	visited[src.x][src.y] = true;

    // Create a queue for BFS
    queue <queueNode> q;
	
	// distance of source cell is 0
	queueNode s = {src, 0};
	q.push(s); // Enqueue source cell

	// Do a BFS starting from source cell
	while (!q.empty()) {
		queueNode curr = q.front();
		Point pt = curr.pt;

		// If we have reached the destination cell, we are done
		if (pt.x == dest.x && pt.y == dest.y) 
            return curr.dist;

		// Otherwise dequeue the front cell in the queue and enqueue adjacent cells
		q.pop();

		for (int i=0; i<4; i++) {
			int row = pt.x + rowNum[i];
			int col = pt.y + colNum[i];
			
			// if adjacent cell is valid, has path and not visited yet, enqueue it.
			if (isValid(row, col) && mat[row][col] && !visited[row][col]) {
				// mark cell as visited and enqueue it
				visited[row][col] = true;
				queueNode Adjcell = { {row, col}, curr.dist + 1 };
				q.push(Adjcell);
			}
		}
	}
    
	// return -1 if destination cannot be reached
	return INT_MAX;
}


// check whether given cell (row, col) is a valid cell or not.
bool isValid(int row, int col) {
	// return true if row number and column number is in range
	return (row >= 0) && (row < ROW) &&
		(col >= 0) && (col < COL);
}

// function to print matrix
void printMatrix (int matrix[ROW][COL]) {
    int i, j;
    printf ("\n");
    printf ("Matrix: \n");
    for (i=0; i<ROW; i++) {
        for (j=0; j<COL; j++) {
            printf ("%d  ", matrix[i][j]);
        }
        printf ("\n");
    }
}
