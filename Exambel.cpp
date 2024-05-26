//
// Created by PcMax on ٢٢/٠٥/٢٠٢٤.
//

#include "Exambel.h"
#include "box.h"
#include "start.h"


void Exambel::Start_Exambel() {

    BOXData boxData1, boxData2, boxData3, boxData4, boxData5, solveBoxe1 , solveBoxe2;

    std::string S = "Series";
    std::string P = "Parallel";
    std::string F = "Feedback";


    float ab1[]{1, 4};
    int sizeAB1 = sizeof(ab1) / sizeof(ab1[0]);
    float am1[]{2};
    int sizeAM1 = sizeof(am1) / sizeof(am1[0]);

    float ab2[]{1,5};
    int sizeAB2 = sizeof(ab2) / sizeof(ab2[0]);
    float am2[]{3};
    int sizeAM2 = sizeof(am2) / sizeof(am2[0]);

    float ab3[]{5, 5};
    int sizeAB3 = sizeof(ab1) / sizeof(ab1[0]);
    float am3[]{9};
    int sizeAM3 = sizeof(am1) / sizeof(am1[0]);

    float ab4[]{6, 7};
    int sizeAB4 = sizeof(ab1) / sizeof(ab1[0]);
    float am4[]{2};
    int sizeAM4 = sizeof(am1) / sizeof(am1[0]);

    float ab5[]{4, 7};
    int sizeAB5 = sizeof(ab1) / sizeof(ab1[0]);
    float am5[]{4};
    int sizeAM5 = sizeof(am1) / sizeof(am1[0]);

    boxData1.DataContainer(ab1, sizeAB1, am1, sizeAM1);
    boxData2.DataContainer(ab2, sizeAB2, am2, sizeAM2);
    boxData3.DataContainer(ab3, sizeAB3, am3, sizeAM3);
    boxData4.DataContainer(ab4, sizeAB4, am4, sizeAM4);
    boxData5.DataContainer(ab5, sizeAB5, am5, sizeAM5);


    solveBoxe1 = box::serise(boxData1, boxData2);
    start::printData(1, 2, S);
    start::Print(solveBoxe1);

    solveBoxe1 = box::paralell(solveBoxe1, boxData3);
    start::printData(111, 3, P);
    start::Print(solveBoxe1);

    solveBoxe2 = box::serise(boxData4, boxData5);
    start::printData(4, 5, S);
    start::Print(solveBoxe2);

    boxData1.DataContainer();

    boxData1 = box::feedback(solveBoxe1, solveBoxe2, -1);
    start::printData(111, 6, F);
    start::Print(boxData1);

    boxData1.DataContainer();
    boxData2.DataContainer();
    boxData3.DataContainer();
    boxData4.DataContainer();
    boxData5.DataContainer();
    solveBoxe1.DataContainer();
    solveBoxe2.DataContainer();
}