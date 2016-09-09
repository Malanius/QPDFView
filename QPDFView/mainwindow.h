#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QImage>
#include <QDebug>
#include <QLabel>
#include <QFileDialog>
#include <QInputDialog>
#include <QScrollArea>

#include "mupdf-qt.h"
#include "page.hpp"

class QScrollArea;
class QToolBar;
class QAction;
class Page;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:

    void openDocument();
    void previousPage();
    void nextPage();
    void zoomIn();
    void zoomOut();

private:

    void createActions();
    void createToolBars();
    void openPage(int index);
    void updateTitle();

    QScrollArea *m_scrollArea;
    Page *m_label;
    QToolBar *m_toolBar;
    QAction *openAction;
    QAction *previousPageAction;
    QAction *nextPageAction;
    QAction *zoomInAction;
    QAction *zoomOutAction;
    MuPDF::Document *m_doc;
    MuPDF::Page *m_page;

    QString m_title;
    int m_numPages;
    int m_index;
    float m_scale;
};

#endif // MAINWINDOW_H
