int kadane(int arr[], int &start, int &finish, int n)
{
    int max_sum = 0, sum = 0;
    int i = 0, j = 0;
    finish = -1;
    
    while(j<n)
    {
        sum += arr[j];
        if(sum > max_sum)
        {
            start = i;
            finish = j;
            max_sum = sum;
        }
        else if(sum < 0)
        {
            i = j+1;
            sum = 0;
        }
        j++;
    }
    
        
    if (finish != -1)
        return max_sum;
 
    ///  Special Case: When all numbers in arr[] are negative
    max_sum = arr[0];
    start = finish = 0;
 
    for (i = 1; i < n; i++)
    {
        if (arr[i] > max_sum)
        {
            max_sum = arr[i];
            start = finish = i;
        }
    }

    return max_sum;
}

int maximumSumRectangle(int ROW, int COL, vector<vector<int>> M) 
{
    int maxSum = INT_MIN, finalLeft, finalRight, finalTop, finalBottom;
 
    int left, right, i;
    int temp[ROW], sum, start, finish;

    for (left = 0; left < COL; ++left) {
        memset(temp, 0, sizeof(temp));

        for (right = left; right < COL; ++right) {

            for (i = 0; i < ROW; ++i)
                temp[i] += M[i][right];

            sum = kadane(temp, start, finish, ROW);

            if (sum > maxSum) {
                maxSum = sum;
                finalLeft = left;
                finalRight = right;
                finalTop = start;
                finalBottom = finish;
            }
        }
    }
 
    /* Uncomment this to print the corner points of maximum sum submatrix
    cout << "(Top, Left) ("<< finalTop << ", " << finalLeft << ")" << endl;
    cout << "(Bottom, Right) (" << finalBottom << ", " << finalRight << ")" << endl;
    */
    return maxSum;
}