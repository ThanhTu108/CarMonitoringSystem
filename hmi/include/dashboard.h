#pragma once

#include <QMainWindow>

#include "vehicle_gauge_widget.h"
QT_BEGIN_NAMESPACE

namespace Ui {
    class DashBoard;
}

QT_END_NAMESPACE

class DashBoard : public QMainWindow {
    Q_OBJECT
public:
    explicit DashBoard(QWidget* parent = nullptr);
    ~DashBoard();

    void set_speed(uint32_t speed);
    void get_speed_can();

signals:
    void speeds_changed(double speed);

private:
    Ui::DashBoard* ui;

    uint32_t current_speed;
};