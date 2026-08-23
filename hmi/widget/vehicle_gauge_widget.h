#pragma once

#include <QPaintEvent>
#include <QPainter>
#include <QWidget>
#include <QtCore>
#include <QtMath>

class VehicleGauge : public QWidget {
    Q_OBJECT;

public:
    explicit VehicleGauge(QWidget* parent = nullptr);
    ~VehicleGauge();

protected:
    void paintEvent(QPaintEvent* event);

private:
    void draw_speed_scale(QPainter& painter);
    void draw_odo(QPainter& painter);
    void draw_speed_needle(QPainter& painter);

    double m_speed{0.0};
    double m_odo{0.0};

    const int min_width = 200;
    const int min_height = 200;
};