#include "gauge_painter.h"

#include <QPainter>
#include <QRectF>
GaugePainter::GaugePainter(const GaugeConfig& config)
    : m_config(config) {};

void GaugePainter::set_config(const GaugeConfig& config) {
    this->m_config = config;
}

// private function
void GaugePainter::draw_back_ground(QPainter& painter,
                                    const QRectF& rect) {
    painter.save();
    painter.setRenderHint(QPainter::Antialiasing);
    painter.restore();
}
