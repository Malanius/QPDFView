#ifndef PAGE_HPP
#define PAGE_HPP

#include <QWidget>
#include <QLabel>
#include <QMouseEvent>
#include <QDebug>

#include "mupdf-qt.h"

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


#endif // PAGE_HPP
