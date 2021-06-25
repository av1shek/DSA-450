// https://www.geeksforgeeks.org/largest-area-rectangular-sub-matrix-equal-number-1s-0s/

/*
Another approach is
i) calculate prefix sum for each row,  n*O(n) = O(n^2),  in a new matrix
ii) calculate prefix sum for each col n*O(n) = O(n^2),  in another new matrix
iii) For each (i, j) check submatrix of len (1 to n) = n^2 * O(n) = O(n^3)

So overall complexity will be same O(n^3) but it will take more extra space
as compared to maximum submatrix which is discussed in the above link.

*/