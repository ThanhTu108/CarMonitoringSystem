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

    void draw_back_ground(QPainter& painter, const QRectF& rect);
};