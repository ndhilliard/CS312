#ifndef KADANE_H
#define KADANE_H

namespace kadane
{
    double MaxSubArray(double A[],int& lo,int& hi)
    {
        double sum = 0, max = 0;
        int mxlo = lo, mxhi = hi, s = lo;      

        for(int i = lo;i <= hi;i += 1)
        {
            sum += A[i];

            if(i == lo || sum >= max)
            {
                max = sum;
                mxhi = i;
		mxlo = s;
            }

            if(sum < 0)
            {
                sum = 0;
                s = i + 1;
            }
        }
        lo = mxlo;
        hi = mxhi;
        return max;
    }
}

#endif 
