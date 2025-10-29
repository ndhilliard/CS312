#ifndef DIVIDE_H
#define DIVIDE_H

#include <iostream>

namespace divide
{
    double MaxCrossSubArray(double A[],int& lo,int md,int& hi)
    {
        double lsum = 0, rsum = 0, sum = 0;
        int mxlo = lo, mxhi = hi;

        for(int i = md;i >= lo;i -= 1)
        {
            sum += A[i];

            if(i == md || sum > lsum)
            {
                lsum = sum;
                mxlo = i;
            }
        }

        sum = 0;

        for(int i = md + 1;i <= hi;i += 1)
        {
            sum += A[i];

            if(i == md + 1 || sum > rsum)
            {
                rsum = sum;
                mxhi = i;
            }
        }

        lo = mxlo;
        hi = mxhi;
        return (lsum + rsum);
    }

    double MaxSubArray(double A[],int& lo,int& hi)
    {
        if(lo == hi)
        {
            return A[lo];
        }
        else 
        {
            int md = lo + (hi - lo) / 2;
            int llo, lhi, clo, chi, rlo, rhi;
            double lsum, csum, rsum;

            llo = lo;
            lhi = md;
            lsum = MaxSubArray(A,llo,lhi);
            rlo = md + 1;
            rhi = hi;
            rsum = MaxSubArray(A,rlo,rhi);
            clo = lo;
            chi = hi;
            csum = MaxCrossSubArray(A,clo,md,chi);

            if(lsum >= rsum && lsum >= csum)
            {
                lo = llo;
                hi = lhi;
                return lsum;
            }
            else if(rsum >= lsum && rsum >= csum)
            {
                lo = rlo;
                hi = rhi;
                return rsum;
            }
            lo = clo;
            hi = chi;
            return csum;
        }
    }
}
#endif