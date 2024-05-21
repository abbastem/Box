//
// Created by PcMax on ٢٠/٠٥/٢٠٢٤.
//

#ifndef SHORTCUTSCHEMESBOX_BOX_H
#define SHORTCUTSCHEMESBOX_BOX_H

#include "iostream"
#include "vector"

struct BOXData{
    float *arrayB;
    float *arrayM;
    int sizeB;
    int sizeM;

    void DataContainer(const float *ab, int s1, const float *am, int s2){
        sizeB = s1;
        sizeM = s2;
        arrayB = new float[sizeB];
        arrayM = new float[sizeM];

        for (int i = 0; i < sizeB; ++i) {
            arrayB[i] = ab[i];
        }
        for (int i = 0; i < sizeM; ++i) {
            arrayM[i] = am[i];
        }
    }

    void DataContainer() const {
        delete[] arrayB;
        delete[] arrayM;
    }

    float *getArrayB() const {
        return arrayB;
    }

    float *getArrayM() const {
        return arrayM;
    }

    int getSizeB() const {
        return sizeB;
    }

    int getSizeM() const {
        return sizeM;
    }
};

class box {
public:
    box() = default;

    static BOXData serise(BOXData A, BOXData B);

    static float *serise(const float B[], int sb, const float M[], int sm);

    static BOXData paralell(BOXData A, BOXData B);

    static float *paralell(const float B[], int sb, const float M[], int sm);

    static BOXData feedback(BOXData A, BOXData B, int stat);

};


#endif //SHORTCUTSCHEMESBOX_BOX_H
