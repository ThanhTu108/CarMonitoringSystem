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
    painter.setBrush(Qt::black);
    painter.setPen(Qt::NoPen);
    painter.drawEllipse(rect);
    painter.restore();
}

void GaugePainter::draw_ticks(QPainter& painter, const QRectF& rect) {
    painter.save();
    const QPointF center = rect.center();
    const double radius = qMin(rect.width(), rect.height()) / 2.0;

    QPen major_pen(Qt::white);
    major_pen.setWidth(2);

    QPen minor_pen(Qt::white);
    minor_pen.setWidth(1);

    // painter.setPen(std::move(pen));

    const double min_val = m_config.get_minvalue();
    const double max_val = m_config.get_maxvalue();
    const double major_step = m_config.get_step();
    const double minor_step = major_step / minor_count;

    if (major_step <= 0 || max_val <= min_val || minor_count <= 0) {
        painter.restore();
        return;
    }

    const double total_range = max_val - min_val;
    const int total_step = qRound(total_range / minor_step);

    for (int i = 0; i < total_step; i++) {
        double curr_val = min_val + (i * minor_step);
        if (curr_val > max_val) break;
        const double angle = value_to_angle(curr_val);

        bool is_major = (i % minor_count == 0);
        double outer_radius_factor = 0.9;
        double inner_radius_factor;

        if (is_major) {
            inner_radius_factor = 0.82;
            painter.setPen(major_pen);
        } else {
            inner_radius_factor = 0.85;
            painter.setPen(minor_pen);
        }
        const QPointF outter =
            point_circle(center, radius * outer_radius_factor, angle);
        const QPointF inner =
            point_circle(center, radius * inner_radius_factor, angle);
        painter.drawLine(inner, outter);
    }

    painter.restore();
}

// void value_to_angle