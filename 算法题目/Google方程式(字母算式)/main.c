#include <stdio.h>

//WWWDOT - GOOGLE = DOTCOM

int yes_or_no(int W, int D, int O, int T, int G, int L, int E, int C, int M)
{
    long WWWDOT = W*100000 + W*10000 + W*1000 + D*100 + O*10 + T;
    long GOOGLE = G*100000 + O*10000 + O*1000 + G*100 + L*10 + E;
    long DOTCOM = D*100000 + O*10000 + T*1000 + C*100 + O*10 + M;
    if(WWWDOT - GOOGLE == DOTCOM)
    {
        printf("%d-%d=%d\n",WWWDOT,GOOGLE,DOTCOM);
        return 0;
    }
    return 1;
}

int no(int W, int D, int O, int T, int G, int L, int E, int C, int M)
{
    int num[10] = {0};
    num[W]++;
    num[D]++;
    num[O]++;
    num[T]++;
    num[G]++;
    num[L]++;
    num[E]++;
    num[C]++;
    num[M]++;
    for (int i = 0; i < 10; i++)
    {
        if(num[i] > 1)
        {
            return 1;
        }
    }
    return 0;
}

int main(int argc, char const *argv[])
{
    for (int W = 1; W <= 9; W++) {
        for (int D = 1; D <= 9; D++) {
            for (int O = 0; O <= 9; O++) {
                for (int T = 0; T <= 9; T++) {
                    for (int G = 1; G <= 9; G++) {
                        for (int L = 0; L <= 9; L++) {
                            for (int E = 0; E <= 9; E++) {
                                for (int C = 0; C <= 9; C++) {
                                    for (int M = 0; M <= 9; M++) {
                                        if(!no(W,D,O,T,G,L,E,C,M))
                                        {
                                            if(!yes_or_no(W,D,O,T,G,L,E,C,M))
                                            {
                                                printf("W=%d D=%d O=%d T=%d G=%d L=%d E=%d C=%d M=%d\n",W,D,O,T,G,L,E,C,M);
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    return 0;
}