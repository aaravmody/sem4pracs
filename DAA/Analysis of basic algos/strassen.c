#include <stdio.h>

int main()
{
   int z[2][2];
   int p, q, r, s, t, u, v;
   int i, j;
   int A[2][2] = {{12, 34}, {22, 10}};
   int B[2][2] = {{3, 4}, {2, 1}};

   p = (A[0][0] + A[1][1]) * (B[0][0] + B[1][1]);
   q = (A[1][0] + A[1][1]) * B[0][0];
   r = A[0][0] * (B[0][1] - B[1][1]);
   s = A[1][1] * (B[1][0] - B[0][0]);
   t = (A[0][0] + A[0][1]) * B[1][1];
   u = (A[1][0] - A[0][0]) * (B[0][0] + B[0][1]);
   v = (A[0][1] - A[1][1]) * (B[1][0] + B[1][1]);

   z[0][0] = p + s - t + v;
   z[0][1] = r + t;
   z[1][0] = q + s;
   z[1][1] = p + r - q + u;

   printf("\nProduct achieved using Strassen's algorithm: ");
   for (i = 0; i < 2; i++)
   {
      printf("\n");
      for (j = 0; j < 2; j++)
         printf("%d\t", z[i][j]);
   }
   return 0;
}
