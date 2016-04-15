#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QScrollArea>
#include <QToolBar>
#include <QMouseEvent>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent)
 , m_doc(NULL), m_page(NULL), m_index(0), m_scale(1.0f)
{
    m_scrollArea = new QScrollArea;
    m_scrollArea->setAlignment(Qt::AlignCenter);
    m_label = new Page;
    m_scrollArea->setWidget(m_label);
    this->setCentralWidget(m_scrollArea);
    this->setWindowState(Qt::WindowMaximized);

    createActions();
    createToolBars();
}

MainWindow::~MainWindow()
{
    if (m_page) {
            delete m_page;
            m_page = NULL;
        }
        if (m_doc) {
            delete m_doc;
            m_doc = NULL;
        }
}

void MainWindow::openDocument()
{
    QString file = QFileDialog::getOpenFileName(this,
            tr("Open PDF/XPS/EPUB/.."), ".", "PDF (*.pdf);;XPS (*.xps);;EPUB (*.epub)");
    if (file.isEmpty()) {
        return;
    }

    if (m_page) {
        delete m_page;
        m_page = NULL;
    }
    if (m_doc) {
        delete m_doc;
        m_doc = NULL;
    }
    m_doc = MuPDF::loadDocument(file);
    if (NULL == m_doc) {
        return;
    }

    if (m_doc->needsPassword()) {
        bool ok;
        QString password;
        do {
            password = QInputDialog::getText(this, tr("Enter password"),
                                                 tr("Password:"), QLineEdit::Normal,
                                                 "", &ok);
            if (!ok)
                return;
        } while (!m_doc->authPassword(password));
    }

    m_title = m_doc->title();
    m_numPages = m_doc->numPages();

    m_index = 0;
    openPage(0);
}

void MainWindow::previousPage()
{
    if (NULL == m_doc) {
        return;
    }
    if (m_index > 0) {
        --m_index;
    }
    openPage(m_index);
}

void MainWindow::nextPage()
{
    if (NULL == m_doc) {
        return;
    }
    if (m_index < m_numPages - 1) {
        ++m_index;
    }
    openPage(m_index);
}

void MainWindow::zoomIn()
{
    if (NULL == m_doc) {
        return;
    }
    if (m_scale >= 10.0f) {
        return;
    }
    m_scale += 0.1f;
    m_label->setScale(m_scale);

    updateTitle();
}

void MainWindow::zoomOut()
{
    if (NULL == m_doc) {
        return;
    }
    if (m_scale < 0.15f) {
        return;
    }
    m_scale -= 0.1f;
    m_label->setScale(m_scale);

    updateTitle();
}

void MainWindow::createActions()
{
    openAction = new QAction(tr("Open"), this);
    connect(openAction, SIGNAL(triggered()), this, SLOT(openDocument()));

    previousPageAction = new QAction(tr("Previous"), this);
    connect(previousPageAction, SIGNAL(triggered()), this, SLOT(previousPage()));

    nextPageAction = new QAction(tr("Next"), this);
    connect(nextPageAction, SIGNAL(triggered()), this, SLOT(nextPage()));

    zoomInAction = new QAction(tr("ZoomIn"), this);
    connect(zoomInAction, SIGNAL(triggered()), this, SLOT(zoomIn()));

    zoomOutAction = new QAction(tr("ZoomOut"), this);
    connect(zoomOutAction, SIGNAL(triggered()), this, SLOT(zoomOut()));
}

void MainWindow::createToolBars()
{
    m_toolBar = this->addToolBar(tr("ToolBar"));
    m_toolBar->addAction(openAction);
    m_toolBar->addAction(previousPageAction);
    m_toolBar->addAction(nextPageAction);
    m_toolBar->addAction(zoomInAction);
    m_toolBar->addAction(zoomOutAction);
}

void MainWindow::openPage(int index)
{
    if (m_page) {
        delete m_page;
        m_page = NULL;
    }
    m_page = m_doc->page(index);
    if (NULL == m_page) {
        return;
    }

    m_label->setPage(m_page, m_scale);
    m_scrollArea->verticalScrollBar();

    updateTitle();
}

void MainWindow::updateTitle()
{
    QString title;
    if (m_title.isEmpty()) {
        title = "No Title - ";
    } else {
        title = m_title + " - ";
    }
    title += "Page " + QString::number(m_index + 1)
        + "/" + QString::number(m_numPages);
    title += " - ";
    title += "Scale " + QString::number(qRound(m_scale * 100)) + "%";
    this->setWindowTitle(title);
}
