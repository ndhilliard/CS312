#ifndef BRUTE_H
#define BRUTE_H

namespace brute
{
    double MaxSubArray(double A[],int& lo,int& hi)
    {
        double sum, max = 0;
        int mxlo = lo, mxhi = hi;

        for(int i = 0;i <= hi;i += 1)
        {
            sum = 0.0;

            for(int j = i;j <= hi;j += 1)
            {
                sum += A[j];

                if((i == lo && j == lo) || sum > max)
                {
                    max = sum;
                    mxlo = i;
                    mxhi = j;
                }
            }
        }

        lo = mxlo;
        hi = mxhi;
        return max;
    }
}
#endif //BRUTE_H