#ifndef LAB1_2_H
#define LAB1_2_H

#include <QtGui/QPen>
#include <QtGui/QCheckBox>
#include <QtGui/QGroupBox>
#include <QtGui/QLabel>
#include <QtGui/QRadioButton>
#include <QtGui/QSpinBox>
#include <QtGui/QVBoxLayout>
#include <QtGui/QHBoxLayout>
#include "/usr/include/qwt-qt4/qwt_plot.h"
#include "/usr/include/qwt-qt4/qwt_data.h"
#include "/usr/include/qwt-qt4/qwt_plot_curve.h"
#include "/usr/include/qwt-qt4/qwt_plot_grid.h"
#include "/usr/include/qwt-qt4/qwt_symbol.h"

class lab1_2 : public QWidget
{
    Q_OBJECT

public:
    lab1_2();

signals:
    void progress_val(int &pgss);
    void debug_info_sgn(QString &text);

public slots:
    void on_start_button_clicked();
    void setDegugInfo(bool);

private:
    QwtPlot *qwtPlot;
    QwtPlotCurve *cSin;
    QwtPlotCurve *cPoint;
    QwtPlotGrid *grid;
    QGroupBox *groupBox;
    QRadioButton *urandom_check;
    QRadioButton *random_check;
    QRadioButton *rand_check;
    QLabel *label_1;
    QLabel *label_2;
    QSpinBox *generator_spb;

    bool  debug_bool;
};

class SinData: public QwtData
{
private:
    size_t d_size;
    double(*d_y)(double);

public:
    SinData(double(*y)(double), size_t size) : d_size(size), d_y(y) {}

    virtual QwtData *copy() const { return new SinData(d_y, d_size); }
    virtual size_t size() const { return d_size; }
    virtual double x(size_t i) const { return 0.001 * i; }
    virtual double y(size_t i) const { return d_y(3.141592654 * x(i)); }
};

class VectorData: public QwtData
{
private:
    QVector<double> _x;
    QVector<double> _y;

public:
    VectorData(QVector<double> x, QVector<double> y):
    _x(x), _y(y) { Q_ASSERT(_x.size() == _y.size()); }

    QwtData* copy () const { return new VectorData(_x, _y); }
    size_t size() const { return _x.size(); }
    double x(size_t i) const { return _x[i]; }
    double y(size_t i) const { return _y[i]; }
};

#endif // LAB1_2_H
