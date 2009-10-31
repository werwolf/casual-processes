#include "lab1_3.h"

#include <QtCore/qmath.h>
#include <QtCore/QFile>
#include <QtCore/QDataStream>

lab1_3::lab1_3()
{
    qwtPlot = new QwtPlot(this);
    qwtPlot->setMinimumWidth(370);
    qwtPlot->setCanvasBackground(QColor(Qt::white));
    qwtPlot->setAxisScale(QwtPlot::xBottom, 0.0, 10.0);
    qwtPlot->setAxisScale(QwtPlot::yLeft, 0.0, 10.0);

    //qwtPlot->setAxisMaxMajor(QwtPlot::xBottom, 10.0);
    //qwtPlot->setAxisMaxMinor(QwtPlot::xBottom, 5.0);
    //qwtPlot->setAxisMaxMinor(QwtPlot::yLeft, 10.0);
    //qwtPlot->setAxisMaxMajor(QwtPlot::yLeft, 5.0);
    //qwtPlot->setAxisScaleEngine(QwtPlot::xBottom, new QwtLog10ScaleEngine);
    //qwtPlot->setAxisScaleEngine(QwtPlot::yLeft, new QwtLog10ScaleEngine);

    cGraph = new QwtPlotCurve("y = 1/sqrt(x)");
    cGraph->setRenderHint(QwtPlotItem::RenderAntialiased);
    //cGraph->setPen(QPen(Qt::darkGreen, 3, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin));
    cGraph->setPen(QPen(Qt::darkGreen));
    cGraph->attach(qwtPlot);

    QwtSymbol sym;
    sym.setStyle(QwtSymbol::XCross);
    sym.setSize(5,5);
    sym.setPen(QColor(Qt::blue));

    cPoint = new QwtPlotCurve();
    cPoint->setStyle(QwtPlotCurve::NoCurve);
    cPoint->setSymbol(sym);
    cPoint->setRenderHint(QwtPlotItem::RenderAntialiased);
    cPoint->attach(qwtPlot);

    grid = new QwtPlotGrid;
    grid->enableXMin(true);
    grid->enableYMin(true);
    grid->setMajPen(QPen(Qt::black, 0, Qt::DotLine));
    grid->setMinPen(QPen(Qt::gray, 0 , Qt::DotLine));
    grid->attach(qwtPlot);

    groupBox = new QGroupBox(tr("&PRN generator"));

    urandom_check = new QRadioButton(tr("/dev/urandom"));
    random_check = new QRadioButton(tr("/dev/random"));
    rand_check = new QRadioButton(tr("rand(time)"));

    #ifdef linux
        urandom_check->setChecked(true);
    #else
        urandom_check->setEnabled(false);
        random_check->setEnabled(false);
        rand_check->setChecked(true);
    #endif

    generator_spb = new QSpinBox(this);
    generator_spb->setMinimum(100);
    generator_spb->setMaximum(6500);
    generator_spb->setSingleStep(100);

    label_1 = new QLabel(tr("&Generator"));
    label_1->setBuddy(generator_spb);

    label_2 = new QLabel(tr("<center><b>Function: <font color=blue>\"Sin(PI*x)\"<font color=black><p>on interval [0;1]"));

    QVBoxLayout *boxLayout = new QVBoxLayout(groupBox);
    boxLayout->addWidget(urandom_check);
    boxLayout->addWidget(random_check);
    boxLayout->addWidget(rand_check);

    QHBoxLayout *horizontalLayout_1 = new QHBoxLayout;
    horizontalLayout_1->addWidget(label_1);
    horizontalLayout_1->addWidget(generator_spb);

    QVBoxLayout *rightLayout = new QVBoxLayout;
    rightLayout->addWidget(groupBox);
    rightLayout->addLayout(horizontalLayout_1);
    rightLayout->addWidget(label_2);
    rightLayout->addStretch();

    QHBoxLayout *mainlLayout = new QHBoxLayout;
    mainlLayout->addWidget(qwtPlot);
    mainlLayout->addLayout(rightLayout);
    setLayout(mainlLayout);
}

void lab1_3::on_start_button_clicked()
{
    quint16  count;                             //number of tests == quality of test == quantity of points
    quint16  i;                                 //other counter
    quint16  ok_point = 0;                      //number of normal point
    double   x_random = 0.0;                    //current X random number from PRN-generanor
    double   y_random = 0.0;                    //current Y random number from PRN-generanor
    quint16  i_rV;                              //current random numbe in integer
    double   S = 0.0;                           //Our required area
    int      val_pgss = 0;                      //value for signal "progress_val(int &pgss)"
    QString  degug_info_str;                    //formated debug info string
    QString  str;                               //tempory string

//->->->->->->->->->->->->->->->->->->->->->
    count = generator_spb->value();     //->
                                        //->
    QVector<double> x[count];           //->
    QVector<double> y[count];           //->
//->->->->->->->->->->->->->->->->->->->->->->->->->->->->->->->->->->->->->->->->->->->->
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
            x_random = i_rV;
            x_random /= 65535.0;
            x[0].append(x_random);

            randomStream >> i_rV;
            y_random = i_rV;
            y_random /= 65535.0;
            y[0].append(y_random);

            if(y_random <= sin(x_random * 3.141592654)) ++ok_point;

            if(debug_bool)
            {
                str = ":: i = %1\t:: X = %2\t:: Y = %3\t:: OK = %4\n";
                degug_info_str += str.arg(i).arg(x_random).arg(y_random).arg(ok_point);
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
            x_random = i_rV;
            x_random /= 65535.0;
            x[0].append(x_random);

            randomStream >> i_rV;
            y_random = i_rV;
            y_random /= 65535.0;
            y[0].append(y_random);

            if(y_random <= sin(x_random * 3.141592654)) ++ok_point;

            if(debug_bool)
            {
                str = ":: i = %1\t:: X = %2\t:: Y = %3\t:: OK = %4\n";
                degug_info_str += str.arg(i).arg(x_random).arg(y_random).arg(ok_point);
            }

            emit progress_val(val_pgss = 100*(i+1) / count);
        }

        file_r.close();
        if(debug_bool) degug_info_str += "Random file closing.\n";
    }

//CHOOSE "rand" GENERATOR
    if(rand_check->isChecked())
    {
        if (debug_bool) degug_info_str += "Rand select.\n";
        qsrand(time(NULL));
        for(i = 0; i < count; ++i)
        {
            x_random = qrand() % 1000000+1;
            x_random /= 1000000.0;
            x[0].append(x_random);

            y_random = qrand() % 1000000+1;
            y_random /= 1000000.0;
            y[0].append(y_random);

            if(y_random <= sin(x_random * 3.141592654)) ++ok_point;

            if(debug_bool)
            {
                str = ":: i = %1\t:: X = %2\t:: Y = %3\t:: OK = %4\n";
                degug_info_str += str.arg(i).arg(x_random).arg(y_random).arg(ok_point);
            }

            emit progress_val(val_pgss = 100*(i+1) / count);
        }
    }

//->->->->->->->->->->->->->->->->->->->->->->->->->->->->->->->->->->->->->->->->->->->->
//CREATE AND SHOW LNFO RESULT - LABEL
    str = ":: count = %1 :: points = %2 ::\n";
    degug_info_str += str.arg(count).arg(ok_point);

//CALCULATE AND SWOW ANSWER - LABEL
    S = ok_point;
    S /= count;
    str = ":: S (our) = %1 :: S (real) = 2/PI ~ 0.63662 ::\n";
    degug_info_str += str.arg(S);
    emit debug_info_sgn(degug_info_str);

//->->->->->->->->->->->->->->->->->->->->->->->->->->->->->->->->->->->->->->->->->->->->
//PLOT SIN AND POINTS
    const unsigned int nPoints = 10000;
    cGraph->setData(RealData(nPoints));
    //cPoint->setData(VectorData(*x, *y));
    qwtPlot->replot();
}

void lab1_3::setDegugInfo(bool bdi)
{
    debug_bool = bdi;
}

