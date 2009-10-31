#include "mainwindowimpl.h"
//
MainWindowImpl::MainWindowImpl( QWidget * parent, Qt::WFlags f) 
	: QMainWindow(parent, f)
{	
    c_widget = new QWidget();

    lab1_1_widget = new lab1_1();
    connect(lab1_1_widget, SIGNAL(progress_val(int &)), this, SLOT(progress_val(int &)));
    connect(lab1_1_widget, SIGNAL(debug_info_sgn(QString &)), this, SLOT(debug_info_sgn(QString &)));
    lab1_1_widget->setDegugInfo(false);

    lab1_2_widget = new lab1_2();
    connect(lab1_2_widget, SIGNAL(progress_val(int &)), this, SLOT(progress_val(int &)));
    connect(lab1_2_widget, SIGNAL(debug_info_sgn(QString &)), this, SLOT(debug_info_sgn(QString &)));
    lab1_2_widget->setDegugInfo(false);

    lab1_3_widget = new lab1_3();
    connect(lab1_3_widget, SIGNAL(progress_val(int &)), this, SLOT(progress_val(int &)));
    connect(lab1_3_widget, SIGNAL(debug_info_sgn(QString &)), this, SLOT(debug_info_sgn(QString &)));
    lab1_3_widget->setDegugInfo(false);

    tabWidget = new QTabWidget();
    tabWidget->addTab(lab1_1_widget, "Lab 1-1");
    tabWidget->addTab(lab1_2_widget, "Lab 1-2");
    tabWidget->addTab(lab1_3_widget, "Lab 1-3");

    textBrowser = new QTextBrowser();
    textBrowser->setMaximumHeight(80);

    QVBoxLayout *mainLayout = new QVBoxLayout(c_widget);
    mainLayout->addWidget(tabWidget);
    mainLayout->addWidget(textBrowser);

    setCentralWidget(c_widget);

    createActions();
    createMenus();
    createToolBars();
    createStatusBar();

    setWindowIcon(QIcon(":/images/icon.png"));
}

void MainWindowImpl::createActions()
{
    openAction = new QAction(tr("&Open..."), this);
    openAction->setIcon(QIcon(":/images/open.png"));
    openAction->setShortcut(tr("Ctrl+O"));
    openAction->setStatusTip(tr("Open an existing spreadsheet file"));

    startAction = new QAction(tr("&Start..."), this);
    startAction->setIcon(QIcon(":/images/start.png"));
    startAction->setShortcut(tr("Alt+S"));
    startAction->setStatusTip(tr("Start progress"));
    connect(startAction, SIGNAL(triggered()), this, SLOT(on_start_button_clicked()));

    clearAction = new QAction(tr("&Clear..."), this);
    clearAction->setIcon(QIcon(":/images/clear.png"));
    clearAction->setShortcut(tr("Alt+C"));
    clearAction->setStatusTip(tr("Clear state"));
    connect(clearAction, SIGNAL(triggered()), textBrowser, SLOT(clear()));

    exitAction = new QAction(tr("&Exit..."), this);
    exitAction->setIcon(QIcon(":/images/exit.png"));
    exitAction->setShortcut(tr("Ctrl+E"));
    exitAction->setStatusTip(tr("Exit"));
    connect(exitAction, SIGNAL(triggered()), this, SLOT(close()));

    debug_infoAction = new QAction(tr("Show debug info"), this);
    debug_infoAction->setCheckable(true);
    debug_infoAction->setChecked(false);
    debug_infoAction->setStatusTip(tr("Show debug info during progress"));
    connect(debug_infoAction, SIGNAL(toggled(bool)), lab1_1_widget, SLOT(setDegugInfo(bool)));
    connect(debug_infoAction, SIGNAL(toggled(bool)), lab1_2_widget, SLOT(setDegugInfo(bool)));

    aboutAction = new QAction(tr("&About"), this);
    aboutAction->setStatusTip(tr("Show the application's About box"));
    connect(aboutAction, SIGNAL(triggered()), this, SLOT(about()));

    aboutQtAction = new QAction(tr("About &Qt"), this);
    aboutQtAction->setStatusTip(tr("Show the Qt library's About box"));
    connect(aboutQtAction, SIGNAL(triggered()), qApp, SLOT(aboutQt()));
}

void MainWindowImpl::createMenus()
{
    fileMenu = menuBar()->addMenu(tr("&File"));
    fileMenu->addAction(openAction);
    fileMenu->addSeparator();
    fileMenu->addAction(exitAction);

    optionsMenu = menuBar()->addMenu(tr("&Options"));
    optionsMenu->addAction(debug_infoAction);

    helpMenu = menuBar()->addMenu(tr("&Help"));
    helpMenu->addAction(aboutAction);
    helpMenu->addAction(aboutQtAction);
}

void MainWindowImpl::createToolBars()
{
    menuToolBar = addToolBar(tr("&Menu"));
    menuToolBar->addAction(startAction);
    menuToolBar->addAction(clearAction);
    menuToolBar->addAction(exitAction);
    //menuToolBar->addSeparator();
}

void MainWindowImpl::createStatusBar()
{
    progressBar = new QProgressBar();
    progressBar->setAlignment(Qt::AlignHCenter);
    progressBar->setMaximumHeight(16);
    progressBar->setVisible(false);

    statusBar()->addWidget(progressBar,100);
}

void MainWindowImpl::progress_val(int &pgss)
{
    progressBar->setVisible(true);
    progressBar->setValue(pgss);
    if(progressBar->maximum() == pgss){
        progressBar->setVisible(false);
    }
}

void MainWindowImpl::debug_info_sgn(QString &text)
{
    textBrowser->setText(text);
}

void MainWindowImpl::about()
{
    QMessageBox::about(this, tr("About Lab"),
            tr("<h2>Casual process.</h2>"
               "<p>Copyright &copy; 2009 Werwolf corp."
               "<p>Golphomid Nazar, KM-72 groupe."
               "<p>LAB 1-1 :  Check of the generator of pseudo-random numbers "
               "on uniformity of distribution by criterion of X<sup>2</sup>."
               "<p>demonstrates QAction, QMainWindow, QMenuBar, "
               "QStatusBar, QTableWidget, QToolBar, and many other "
               "Qt classes."));
}

void MainWindowImpl::on_start_button_clicked()
{
    if(tabWidget->currentWidget() == lab1_1_widget){
        lab1_1_widget->on_start_button_clicked();
    }

    if(tabWidget->currentWidget() == lab1_2_widget){
        lab1_2_widget->on_start_button_clicked();
    }

    if(tabWidget->currentWidget() == lab1_3_widget){
        lab1_3_widget->on_start_button_clicked();
    }
}
