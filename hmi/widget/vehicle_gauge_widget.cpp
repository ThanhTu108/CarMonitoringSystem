#include "vehicle_gauge_widget.h"

VehicleGauge::VehicleGauge(QWidget* parent) : QWidget(parent) {
    setMinimumSize(min_width, min_height);
}
VehicleGauge::~VehicleGauge() {
}

void VehicleGauge::paintEvent(QPaintEvent* event) {
    Q_UNUSED(event);
    QPainter painter(this);

    painter.setRenderHint(QPainter::Antialiasing);
    // painter.fillRect(rect(), Qt::black);
    draw_speed_scale(painter);
    draw_speed_needle(painter);
    draw_odo(painter);
}

void VehicleGauge::draw_speed_scale(QPainter& painter) {
    const int width = this->width();
    const int height = this->height();

    const QPointF center(width / 2.0, height * 0.53);

    const double radius = qMin(width, height) * 0.45;
    QPen circle_pen(Qt::black);
    circle_pen.setWidth(3);

    painter.setPen(circle_pen);
    painter.setBrush(Qt::NoBrush);
    painter.drawEllipse(center, radius, radius);

    constexpr int max_speed = 220;
    constexpr int major_step = 20;
    constexpr int minor_step = 5;

    constexpr double start_angle = 225.0;
    constexpr double sweep_angle = 270.0;

    QFont font;
    font.setPointSize(9);
    font.setBold(true);

    painter.setFont(font);

    QPen major_pen(Qt::black, 2);
    QPen minor_pen(Qt::black, 1);

    for (int speed = 0; speed <= max_speed; speed += minor_step) {
        const double ratio = static_cast<double>(speed) / max_speed;
        const double angle =
            qDegreesToRadians(start_angle - ratio * sweep_angle);
        const double outer_radius = radius;

        const bool is_major = (speed % major_step == 0);
        const double inner_radius = radius - (is_major ? 15 : 7);

        // x = x0+ R*cos(P)
        QPointF outer(center.x() + outer_radius * qCos(angle),
                      center.y() - outer_radius * qSin(angle));
        QPointF inner(center.x() + inner_radius * qCos(angle),
                      center.y() - inner_radius * qSin(angle));
        painter.setPen(is_major ? major_pen : minor_pen);
        painter.drawLine(inner, outer);

        if (is_major) {
            const double text_radius = radius * 0.65;

            QPointF text_position(center.x() + text_radius * qCos(angle),
                                  center.y() - text_radius * qSin(angle));

            QRectF text_rect(text_position.x() - 20,
                             text_position.y() - 10, 40, 20);
            painter.setPen(Qt::black);
            painter.drawText(text_rect, Qt::AlignCenter,
                             QString::number(speed));
        }
    }
}
void VehicleGauge::draw_odo(QPainter& painter) {
}

void VehicleGauge::draw_speed_needle(QPainter& painter) {
    // for debug
    const int m_current_speed = 100;

    const int width = this->width();
    const int height = this->height();

    // get center point of circle
    const QPointF center(width / 2.0, height * 0.53);
    const double radius = qMin(width, height) * 0.45;
    constexpr int max_speed = 220;
    constexpr double start_angle = 225.0;
    constexpr double sweep_angle = 270.0;

    // Get current speed between 0 - max speed
    const double clamp_speed =
        qBound(0.0, static_cast<double>(m_current_speed),
               static_cast<double>(max_speed));

    // Calculate angle corresponding to speed
    const double ratio = clamp_speed / max_speed;
    const double angle =
        qDegreesToRadians(start_angle - ratio * sweep_angle);

    const double needle_lenghth = radius * 0.55;

    painter.save();

    QPen needle_pen(Qt::red);
    needle_pen.setWidth(3);
    needle_pen.setCapStyle(Qt::RoundCap);
    painter.setPen(needle_pen);

    // Calculate position of needle
    QPointF needle_tip(center.x() + needle_lenghth * qCos(angle),
                       center.y() - needle_lenghth * qSin(angle));

    painter.drawLine(center, needle_tip);

    // draw circle at center of needle tip
    painter.setPen(Qt::NoPen);
    painter.setBrush(Qt::black);
    painter.drawEllipse(center, 3.0, 3.0);

    painter.setBrush(Qt::red);
    painter.drawEllipse(center, 2.0, 2.0);

    painter.restore();
}