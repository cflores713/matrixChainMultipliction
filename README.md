# matrixChainMultipliction
Calculates the amount of scalar multiplications required to combine matrices.

When combining matrices together by multiplication, it is necessary that the number of columns in the first matrix are equal to the number of rows in the second matrix. The resulting matrix will be the dimensions of the other values not used. For example: M[3][4] * M[4][2] = M[3][2]. The number of scalar multiplications performed in this operation is the product of the three unique values 3 * 4 * 2. Which demonstrates that it would take 12 multiplications to get the result.


When multiplying many matrices together it is apparent that the dimensions of the matrices will change as the arithmetic operations are performed. Therefore, the order in which the multiplications are performed will result in either more multiplications performed or less. This program will find the appropriate pattern to multiply matrices together to perform the MOST amount of scalar multiplications or the LEAST amount of scalar multiplications.


![Image of dim](https://github.com/cflores713/matrixChainMultipliction/blob/master/ss1.png)
The following matrices can be chained together because the inner dimensions match. For combining neighboring matricies simply multiply the unique dimensions. 


For example, Matrix 1[6][2] and Matrix 2[2][8] will result in  6 * 2 * 8 = 96 multiplications.
The values are memoized in an array for a quick reference.
![Image of dim](https://github.com/cflores713/matrixChainMultipliction/blob/master/ss2.png)

When proceeding to the next step you must be careful! Now we have two possible patterns. We could combine three matrices by multiplying (M1 * M2) * M3 or by combing M1 * (M2 * M3). The order will result in a different amount. Since we are looking for the least amount of multiplications we will choose the pattern that returns the smallest amount of scalar multiplications.


![Image of dim](https://github.com/cflores713/matrixChainMultipliction/blob/master/ss3.png)
If we combined (M1 * M2) * M3 that would give us 28 multiplications and that is much lower than combing M1 * (M2 * M3) which gave us 108 multiplications. Continue to do this to fill up the array and remember to compare all possible combinations. It is important to only mutliply neighboring matricies together (because matricies can only be combined by their direct neighbor).


![Image of dim](https://github.com/cflores713/matrixChainMultipliction/blob/master/ss4.png)
![Image of dim](https://github.com/cflores713/matrixChainMultipliction/blob/master/ss5.png)
Once you are done with filling the array you can refer to your array to see which values gave you the lowest number. The combination of arrays that produced that number will indicate which pattern to follow.


![Image of dim](https://github.com/cflores713/matrixChainMultipliction/blob/master/ss6.png)

We should combine the matrices by : [ M1 * (M2 * M3) ] * [M4 * M5] to perform the least amount of scalar multiplications. 
