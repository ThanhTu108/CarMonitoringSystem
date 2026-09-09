#pragma once

#include "gauge_config.h"

class QPainter;
class QRectF;
class QPointF;

class GaugePainter {
public:
    GaugePainter() = default;
    ~GaugePainter() = default;

    explicit GaugePainter(const GaugeConfig& config);
    void set_config(const GaugeConfig& config);

private:
    GaugeConfig m_config;
    static constexpr int minor_count = 5;

    void draw_back_ground(QPainter& painter, const QRectF& rect);
    void draw_ticks(QPainter& painter, const QRectF& rect);
    double value_to_angle(double value);
    QPointF point_circle(const QPointF& center, double radius,
                         double angle) const;
    // void draw_line(const QPointF& inner, const QPointF& outter);
};