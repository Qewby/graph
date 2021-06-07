#ifndef GRAPH_MYFUNCTION_H
#define GRAPH_MYFUNCTION_H

#include <cmath>

#include "../libs/mathplot.h"

class MyFunction : public mpFXY {
public:
    MyFunction(double step);

    void Rewind() override;
    bool GetNextXY(double &x, double &y) override;
    void SetStep(double step);

private:
    double mAngle;
    double mStep;
};


#endif //GRAPH_MYFUNCTION_H
