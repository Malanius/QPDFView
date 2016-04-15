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

class QScrollArea;
class QToolBar;
class QAction;
class Page;

namespace Ui {
class MainWindow;
}

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
   // Ui::MainWindow *ui;
    void createActions();
    void createToolBars();
    void openPage(int index);
    void updateTitle();

    QScrollArea *scrollArea;
    Page *label;
    QToolBar *toolBar;
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


class Page : public QLabel
{
public:

    Page(QWidget *parent = 0);
    ~Page();
    void setPage(MuPDF::Page *page, float scale = 1.0f);
    void setScale(float scale);

protected:
    virtual void mousePressEvent(QMouseEvent *event);
    virtual void mouseReleaseEvent(QMouseEvent *event);

private:
    void updatePage();

    MuPDF::Page *m_page;
    float m_scale;
    QPointF m_pressPoint;
};

#endif // MAINWINDOW_H
