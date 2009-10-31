#ifndef MAINWINDOWIMPL_H
#define MAINWINDOWIMPL_H
//
#include <QMainWindow>
#include <QtGui>
#include <QtCore/QDebug>
#include "lab1_1.h"
#include "lab1_2.h"
#include "lab1_3.h"

//
class MainWindowImpl : public QMainWindow
{
Q_OBJECT
public:
	MainWindowImpl( QWidget * parent = 0, Qt::WFlags f = 0 );

private slots:
    void progress_val(int &pgss);
    void debug_info_sgn(QString &text);
    void about();
    void on_start_button_clicked();

private:
    void createActions();
    void createMenus();
    void createContextMenu();
    void createToolBars();
    void createStatusBar();
    void readSettings();
    void writeSettings();
    
    QWidget *c_widget;
    QProgressBar *progressBar;
    QTabWidget *tabWidget;
    QTextBrowser *textBrowser;
    
    lab1_1 *lab1_1_widget;
    lab1_2 *lab1_2_widget;
    lab1_3 *lab1_3_widget;

    QMenu *fileMenu;
    QMenu *optionsMenu;
    QMenu *helpMenu;
    QToolBar *menuToolBar;
    QAction *openAction;
    QAction *startAction;
    QAction *exitAction;
    QAction *clearAction;
    QAction *debug_infoAction;
    QAction *aboutAction;
    QAction *aboutQtAction;
};
#endif




