# matrixChainMultipliction
Calculates the amount of scalar multiplications required to combine matrices.

When combining matrices together by multiplication, it is necessary that the number of columns in the first matrix are equal to the number of rows in the second matrix. The resulting matrix will be the dimensions of the other values not used. For example: M[3][4] * M[4][2] = M[3][2]. The number of scalar multiplications performed in this operation is the product of the three unique values 3*4*2. Which demonstrates that it would take 12 multiplications to get the result.

When multiplying many matrices together it is apparent that the dimensions of the matrices will change as the arithmetic operations are performed. Therefore, the order in which the multiplications are performed will result in either more multiplications performed or less. This program will find the appropriate pattern to multiply matrices together to perform the MOST amount of scalar multiplications or the LEAST amount of scalar multiplications.
