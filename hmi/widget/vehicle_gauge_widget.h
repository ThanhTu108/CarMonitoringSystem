#pragma once

#include <QPaintEvent>
#include <QPainter>
#include <QWidget>
#include <QtMath>

class VehicleGauge : public QWidget {
    Q_OBJECT;

public:
    explicit VehicleGauge(QWidget* parent = nullptr);
    ~VehicleGauge();

protected:
    void paintEvent(QPaintEvent* event);

private:
    void draw_speed(QPainter& painter);
    void draw_odo(QPainter& painter);

    double m_speed{0.0};
    double m_odo{0.0};

    const int min_width = 200;
    const int min_height = 200;
};