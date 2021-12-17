//2D PREFIX SUM PROBLEM

/*
    A mango tree is of N x N matrix where each cell may or may not have a mango tree. Divide the matrix in 4 parts so as to maximise the number of trees present in the quadrant with the minimum number of trees.
*/


/*
    Brute force approach : 
        horizontal & vertical cut for each (i,j) then we compute sum of each sub-matrix and find minimum sum. At the end of each iteration, we keep maximizing the minimum sum obtained.
        Time Complexity = O(n^2 . n^2) {for counting and summation}
*/

/*
    Optimized approach
    create an aux. matrix M.
    Let M[x, y] be the number of mango trees in the rectangle between (0, 0) and (x, y).
    We can calculate M[x, y] as follows :
        M[x,y] = 1 + M[x-1, y] + M[x, y-1] - M[x-1, y-1], if tree found at (x,y).
        M[x,y] = 0 + M[x-1, y] + M[x, y-1] - M[x-1, y-1], if tree NOT found at (x,y).


 ------------------------------------------------------
 Top right rectangle : 
    M[N-,y] - M[x,y] : Number of mangos in rectangle defined by (x, y) and (0,0)

 Bottom left rectangle : 
    M[x, N] - M[x,y] : Number of mangos in rectangle defined by (0, N) and (x,y)


Now compute S1, S2, S3 and S4 and maximise the minimum value.

Optimised Time Complexity = O(N^2).
*/



