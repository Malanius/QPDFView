#include "page.hpp"

Page::Page(QWidget *parent) : QLabel(parent),
      m_page(nullptr), m_scale(10.0f)
{

}

Page::~Page()
{
}

void Page::setPage(MuPDF::Page *page, float scale)
{
    m_page = page;
    m_scale = scale;
    updatePage();
}

void Page::setScale(float scale)
{
    m_scale = scale;
    updatePage();
}

void Page::mousePressEvent(QMouseEvent *event)
{
    m_pressPoint = event->localPos();
}

void Page::mouseReleaseEvent(QMouseEvent *event)
{
    QPointF point;
    float x0, y0, x1, y1;

    if (!m_page) {
        return;
    }

    point = event->localPos();
    if (point != m_pressPoint) {
        if (m_pressPoint.x() > point.x()) {
            x0 = point.x();
            x1 = m_pressPoint.x();
        } else {
            x0 = m_pressPoint.x();
            x1 = point.x();
        }
        if (m_pressPoint.y() > point.y()) {
            y0 = point.y();
            y1 = m_pressPoint.y();
        } else {
            y0 = m_pressPoint.y();
            y1 = point.y();
        }
        QRectF rect(x0, y0, x1 - x0, y1 - y0);
        rect = MuPDF::mapToOrigin(rect, m_scale, m_scale);
        qDebug() << m_page->text(rect);
    }
}

void Page::updatePage()
{
    QImage image;

    if (!m_page) {
        return;
    }

    image = m_page->renderImage(m_scale, m_scale);
    this->setPixmap(QPixmap::fromImage(image));
    this->resize(this->sizeHint());
}
