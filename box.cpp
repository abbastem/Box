//
// Created by PcMax on ٢٠/٠٥/٢٠٢٤.
//

#include "box.h"
#include "Git.h"


float *box::serise(const float *B, int sb, const float *M, int sm) {
    int sizeL = Git::getSizeForS(sb, sm);
    auto *L = new float[sizeL];

    int l = 0;

    for (int i = 0; i < sb; ++i) {
        for (int j = 0; j < sm; ++j) {
            if (i + j == l) {
                L[i + j] = 0;
                ++l;
            }
            L[i + j] = L[i + j] + (B[i] * M[j]);
        }
    }
    return L;
}

BOXData box::paralell(BOXData A, BOXData B) {
    int sb1 = A.getSizeB();
    int sm1 = A.getSizeM();
    int sb2 = B.getSizeB();
    int sm2 = B.getSizeM();
    bool W = true;
    int SizeBMax = Git::getMax(sb1, sb2);
    int SizeBMin = Git::getMin(sb1, sb2);


    if (sm1 == sm2) {
        for (int i = 0; i < sm1; ++i) {
            if (A.getArrayM()[i] != B.getArrayM()[i])
                W = false;
        }
        if (W) {
            auto *Lb = new float[SizeBMax];

            for (int i = 0; i < SizeBMin; ++i) {
                Lb[i] = 0;
                Lb[i] = Lb[i] + A.getArrayB()[i] + B.getArrayB()[i];
            }
            for (int i = SizeBMin; i < SizeBMax; ++i) {
                Lb[i] = 0;
                float H = (sb1 > sb2) ? A.getArrayB()[i] : B.getArrayB()[i];
                Lb[i] = Lb[i] + H;
            }
            BOXData solveParallel;
            solveParallel.DataContainer(Lb, SizeBMax, A.getArrayM(), sm1);
            return solveParallel;
        }
    }

    int sizeB1M2 = Git::getSizeForS(sb1, sm2);
    int sizeB2M1 = Git::getSizeForS(sb2, sm1);
    int sizeM1M2 = Git::getSizeForS(sm1, sm2);

    auto *LB1M2 = serise(A.getArrayB(), sb1, B.getArrayM(), sm2);
    auto *LB2M1 = serise(A.getArrayM(), sm1, B.getArrayB(), sb2);
    auto *LM1M2 = serise(A.getArrayM(), sm1, B.getArrayM(), sm2);

    int sizeB1B2 = Git::getMax(sizeB1M2, sizeB2M1);

    auto *LB1B2 = paralell(LB1M2, sizeB1M2, LB2M1, sizeB2M1);

    BOXData solveParallell;
    solveParallell.DataContainer(LB1B2, sizeB1B2, LM1M2, sizeM1M2);
    return solveParallell;

}

BOXData box::serise(BOXData A, BOXData B) {
    int sb1 = A.getSizeB();
    int sm1 = A.getSizeM();
    int sb2 = B.getSizeB();
    int sm2 = B.getSizeM();
    int sizeL1 = Git::getSizeForS(sb1, sb2);
    int sizeL2 = Git::getSizeForS(sm1, sm2);
    auto *L1 = new float[sizeL1];
    auto *L2 = new float[sizeL2];

    int l = 0;

    for (int i = 0; i < sb1; ++i) {
        for (int j = 0; j < sb2; ++j) {
            if (i + j == l) {
                L1[i + j] = 0;
                ++l;
            }
            L1[i + j] = L1[i + j] + (A.getArrayB()[i] * B.getArrayB()[j]);
        }
    }
    l = 0;
    for (int i = 0; i < sm1; ++i) {
        for (int j = 0; j < sm2; ++j) {
            if (i + j == l) {
                L2[i + j] = 0;
                ++l;
            }
            L2[i + j] = L2[i + j] + (A.getArrayM()[i] * B.getArrayM()[j]);
        }
    }

    BOXData solveSerese;
    solveSerese.DataContainer(L1, sizeL1, L2, sizeL2);
    return solveSerese;
}

float *box::paralell(const float *B, int sb, const float *M, int sm) {
    int sizeMax = Git::getMax(sb, sm);
    int sizeMin = Git::getMin(sb, sm);

    auto *L = new float[sizeMax];

    for (int i = 0; i < sizeMin; ++i) {
        L[i] = 0;
        L[i] += B[i] + M[i];
    }
    for (int i = sizeMin; i < sizeMax; ++i) {
        L[i] = 0;
        float H = (sb > sm) ? B[i] : M[i];
        L[i] += H;
    }
    return L;
}

BOXData box::feedback(BOXData A, BOXData B, int stat) {

    BOXData boxDataM = serise(A, B);

    BOXData pac;
    pac.DataContainer(boxDataM.getArrayM(), boxDataM.getSizeM(), boxDataM.getArrayM(), boxDataM.getSizeM());

    if (stat == -1) {
        for (int i = 0; i < boxDataM.getSizeB(); ++i) {
            boxDataM.getArrayB()[i] = -1 * boxDataM.getArrayB()[i];
        }
    }

    BOXData M;
    M = paralell(boxDataM, pac);

    int sizeB = Git::getSizeForS(B.getSizeB(), M.getSizeM());
    int sizeM = Git::getSizeForS(B.getSizeM(), M.getSizeB());

    auto *Lb = serise(B.getArrayB(), B.getSizeB(), M.getArrayM(), M.getSizeM());
    auto *Lm = serise(B.getArrayM(), B.getSizeM(), M.getArrayB(), M.getSizeB());

    BOXData LL;
    LL.DataContainer(Lb, sizeB, Lm, sizeM);
    return LL;
}