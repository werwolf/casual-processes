#ifndef CURVEDATA_H
#define CURVEDATA_H

#include </usr/local/qwt-5.2.0/include/qwt_array.h>
#include </usr/local/qwt-5.2.0/include/qwt_plot.h>

class CurveData
{
public:
    CurveData();

    void append(double *x, double *y, int count);

    int count() const;
    int size() const;
    const double *x() const;
    const double *y() const;

private:
    int d_count;
    QwtArray<double> d_x;
    QwtArray<double> d_y;
};

#endif // CURVEDATA_H
