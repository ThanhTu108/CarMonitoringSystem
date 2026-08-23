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

private:
    Ui::DashBoard* ui;
};