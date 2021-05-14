#include "MyFunction.h"

MyFunction::MyFunction(double step) {
    mStep = step;
    mAngle = 0;
}

bool MyFunction::GetNextXY(double &x, double &y) {
    if (mAngle < M_PI * 200)
    {
        double radius = sin(mAngle * 0.99);
        x = radius * cos(mAngle);
        y = radius * sin(mAngle);
        mAngle += mStep;
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}

void MyFunction::SetStep(double step) {
    mStep = step;
    Rewind();
}

void MyFunction::Rewind() {
    mAngle = 0;
}
