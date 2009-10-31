#ifndef LAB1_1_H
#define LAB1_1_H

#include <QtGui/QWidget>
#include <QtGui/QPen>
#include <QtGui/QCheckBox>
#include <QtGui/QGroupBox>
#include <QtGui/QLabel>
#include <QtGui/QRadioButton>
#include <QtGui/QSpinBox>
#include <QtGui/QVBoxLayout>
#include <QtGui/QHBoxLayout>
#include "/usr/include/qwt-qt4/qwt_plot.h"
#include "/usr/include/qwt-qt4/qwt_plot_grid.h"
#include "histogram_item.h"

class lab1_1 : public QWidget
{
    Q_OBJECT

public:
    lab1_1(QWidget *parent = 0);

signals:
    void progress_val(int &pgss);
    void debug_info_sgn(QString &text);

public slots:
    void on_start_button_clicked();
    void setDegugInfo(bool);

private slots:
    void enableInterval_spb();

private:
    QwtPlot *qwtPlot;
    HistogramItem *histogram;
    QwtPlotGrid *grid;
    QGroupBox *groupBox;
    QRadioButton *urandom_check;    
    QRadioButton *random_check;
    QRadioButton *rand_check;
    QLabel *label_1;
    QLabel *label_2;
    QSpinBox *generator_spb;
    QSpinBox *interval_spb;
    QCheckBox *check_autoint;

    bool  debug_bool;
};

#endif // LAB1_1_H
