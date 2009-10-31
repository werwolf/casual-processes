#include "lab1_1.h"

#include <QtCore/QFile>
#include <QtCore/QDataStream>
#include "/usr/include/qwt-qt4/qwt_interval_data.h"

lab1_1::lab1_1(QWidget *parent)
    : QWidget(parent)
{
    qwtPlot = new QwtPlot(this);
    qwtPlot->setMinimumWidth(370);
    qwtPlot->setCanvasBackground(QColor(Qt::white));
    qwtPlot->setAxisScale(QwtPlot::yLeft, 0.0, 25.0);
    qwtPlot->setAxisScale(QwtPlot::xBottom, 0.0, 1.0);

    histogram = new HistogramItem();
    histogram->setColor(Qt::darkCyan);
    histogram->attach(qwtPlot);

    grid = new QwtPlotGrid;
    grid->enableXMin(true);
    grid->enableYMin(true);
    grid->setMajPen(QPen(Qt::black, 0, Qt::DotLine));
    grid->setMinPen(QPen(Qt::gray, 0 , Qt::DotLine));
    grid->attach(qwtPlot);

    groupBox = new QGroupBox(tr("&PRN generator"));

    urandom_check = new QRadioButton(tr("/dev/urandom"));
    urandom_check->setChecked(true);

    random_check = new QRadioButton(tr("/dev/random"));

    rand_check = new QRadioButton(tr("rand(time)"));    

    generator_spb = new QSpinBox(this);
    generator_spb->setMinimum(100);
    generator_spb->setMaximum(6500);
    generator_spb->setSingleStep(100);

    label_1 = new QLabel(tr("&Generator"));
    label_1->setBuddy(generator_spb);

    interval_spb = new QSpinBox(this);
    interval_spb->setMinimum(5);
    interval_spb->setMaximum(15);
    interval_spb->setSingleStep(1);
    interval_spb->setValue(10);
    interval_spb->setEnabled(false);

    label_2 = new QLabel(tr("&Interval"));
    label_2->setBuddy(interval_spb);

    check_autoint = new QCheckBox(tr("&Automatic interval"));
    check_autoint->setChecked(true);
    connect(check_autoint, SIGNAL(clicked()), this, SLOT(enableInterval_spb()));

    QVBoxLayout *boxLayout = new QVBoxLayout(groupBox);
    boxLayout->addWidget(urandom_check);
    boxLayout->addWidget(random_check);
    boxLayout->addWidget(rand_check);

    QHBoxLayout *horizontalLayout_1 = new QHBoxLayout;
    horizontalLayout_1->addWidget(label_1);
    horizontalLayout_1->addWidget(generator_spb);

    QHBoxLayout *horizontalLayout_2 = new QHBoxLayout;
    horizontalLayout_2->addWidget(label_2);
    horizontalLayout_2->addWidget(interval_spb);

    QVBoxLayout *rightLayout = new QVBoxLayout;
    rightLayout->addWidget(groupBox);
    rightLayout->addLayout(horizontalLayout_1);
    rightLayout->addLayout(horizontalLayout_2);
    rightLayout->addWidget(check_autoint);
    rightLayout->addStretch();

    QHBoxLayout *mainlLayout = new QHBoxLayout;
    mainlLayout->addWidget(qwtPlot);
    mainlLayout->addLayout(rightLayout);
    setLayout(mainlLayout);
}

void lab1_1::enableInterval_spb()
{
    if(check_autoint->isChecked()){
        interval_spb->setEnabled(false);
    } else {
        interval_spb->setEnabled(true);
    }
}

void lab1_1::on_start_button_clicked()
{
    const quint8  range = 1;                      //range of random numbers generator
    quint8   k = 0;                               //quantity of intervals
    qreal    interval_width;                      //width of one interval
    quint16  count;                               //number of tests == quality of test
    quint16  i;                                   //other counter
    quint8   g = 0;                               //counter for Range namber
    qreal    randomValue = 0.0;                   //current random number from PRN-generanor
    quint16  i_rV;                                //current random numbe in integer
    QVector<quint32>  quant_int_rand(k);          //array of quantity random nuvber !!!"arr from 0 to k-1"
    int      val_pgss = 0;                        //value for signal "progress_val(int &pgss)"
    QString  degug_info_str;                      //formated debug info string
    QString  str;                                 //tempory string

    const float hi_table[] = {00.00, 3.841, 5.991, 7.815, 9.488,    //table of Hi^2
                              11.07, 12.59, 14.07, 15.51, 16.92,    //p == 0.05 , or 95%
                              18.31, 19.68, 21.03, 22.36, 23.68};   //'v' from "1" to "14"

    count = generator_spb->value();

    if(interval_spb->isEnabled()){
        k = interval_spb->value();
    } else {
        k = 1 + 3.321 * log10 (count);
        k++;
        interval_spb->setValue(k);
    }

    quant_int_rand.resize(k);

    interval_width = range;
    interval_width /= k;

    if(debug_bool)
    {
        str = ":: count of experiments = %1 \t:: quality = %2   ::\n"
              ":: intervals = %3 \t:: interval width= %4 ::\n";
        degug_info_str += str.arg(count).arg(count/k).arg(k).arg(interval_width);
    }

//CHOOSE GENERATOR FROM "/dev/urandom" FILE
    if(urandom_check->isChecked())
    {
        if (debug_bool) degug_info_str += "URandom select.\n";

        QFile file_u("/dev/urandom");
        if(!file_u.open(QIODevice::ReadOnly))
        {
            if (debug_bool) degug_info_str += "File '/dev/urandom' opening failed.";
            return;
        }
        QDataStream randomStream(&file_u);

        for(i = 0; i < count; ++i)
        {
            randomStream >> i_rV;
            randomValue = i_rV;
            randomValue /= 65535.0;
            for(quint8 j = 0; j < k; ++j)
            {
                if(randomValue >= j*interval_width && randomValue < (j+1)*interval_width)
                {
                    ++quant_int_rand[j];
                    break;
                }
                if(randomValue == range){++g;}
            }

            if(debug_bool)
            {
                str = ":: i = %1   :: X = %2 ::\n";
                degug_info_str += str.arg(i).arg(randomValue);
            }

            emit progress_val(val_pgss = 100*(i+1) / count);
        }

        file_u.close();
        if (debug_bool) degug_info_str += "URandom file closing.\n";
    }

//CHOOSE GENERATOR FROM "/dev/random" FILE
    if(random_check->isChecked())
    {
        if (debug_bool) degug_info_str += "Random select.\n";

        QFile file_r("/dev/random");
        if(!file_r.open(QIODevice::ReadOnly))
        {
            if (debug_bool) degug_info_str += "File '/dev/random' opening failed.";
            return;
        }
        QDataStream randomStream(&file_r);

        for(i = 0; i < count; ++i)
        {
            randomStream >> i_rV;
            randomValue = i_rV;
            randomValue /= 65535;
            for(quint8 j = 0; j < k; ++j)
            {
                if(randomValue >= j*interval_width && randomValue < (j+1)*interval_width)
                {
                    ++quant_int_rand[j];
                    break;
                }
                if(randomValue == range){++g;}
            }

            if(debug_bool)
            {
                str = ":: i = %1   :: X = %2 ::\n";
                degug_info_str += str.arg(i).arg(randomValue);
            }
            emit progress_val(val_pgss = 100*(i+1) / count);
        }

        file_r.close();
        if(debug_bool)
        {
            degug_info_str += "Random file closing.\n";
            emit debug_info_sgn(degug_info_str);
        }
    }

//CHOOSE "rand" GENERATOR
    if(rand_check->isChecked())
    {
        if (debug_bool) degug_info_str += "Rand select.\n";
        qsrand(time(NULL));
        for(i = 0; i < count; ++i)
        {
            randomValue = qrand() % 1000000+1;
            randomValue /= 1000000.0;
            for(int j = 0; j < k; ++j)
            {
                if(randomValue >= j*interval_width && randomValue < (j+1)*interval_width)
                {
                    ++quant_int_rand[j];
                    break;
                }
                if(randomValue == range){++g;}
            }

            if(debug_bool)
            {
                str = ":: i = %1   :: X = %2 ::\n";
                degug_info_str += str.arg(i).arg(randomValue);
            }
            emit progress_val(val_pgss = 100*(i+1) / count);
        }
    }

    count -= g;
/***************************************************************************************/

//CALCULATE Hi_2
    double Hi_2 = 0.0;
    double temp = 0.0;

    for( i = 0; i < k; ++i ){
        temp = abs(k * quant_int_rand[i] - count);          //qDebug()<<"temp ="<<temp;
        temp *= temp;                                       //qDebug()<<"temp^2 ="<<temp;
        Hi_2 += temp;                                       //qDebug()<<"Hi_2 +="<<Hi_2;
    }
    Hi_2 /= k * count;                                      //qDebug()<<"Hi_2 ="<<Hi_2;
/***************************************************************************************/

//CREATE AND SHOW LNFO LABEL
    str = "X** = %1. Distribution %2, by criterion X**.\nTable Hi** = %3";
    if(Hi_2 <= hi_table[k-1]){
        degug_info_str += str.arg(Hi_2).arg("uniform with probability of < 95%").arg(hi_table[k-1]);
    } else {
        degug_info_str += str.arg(Hi_2).arg("UNuniform (or uniform with probability of > 95%)").arg(hi_table[k-1]);
    }
    emit debug_info_sgn(degug_info_str);
/***************************************************************************************/

//PLOT DATA HISTOGRAM
    QwtArray<QwtDoubleInterval> intervals(k);
    QwtArray<double> values(k);

    double pos = 0.0;
    for ( i = 0; i < quint16 (intervals.size()); ++i )
        {
            const qreal width = interval_width;
            const int value = quant_int_rand[i];

            intervals[i] = QwtDoubleInterval(pos, pos + double(width));
            values[i] = value;

            pos += width;
        }

    histogram->setData(QwtIntervalData(intervals, values));

    qwtPlot->setAxisScale(QwtPlot::yLeft, 0.0, 2*count/k);
    qwtPlot->replot();
}

void lab1_1::setDegugInfo(bool bdi)
{
    debug_bool = bdi;
}
