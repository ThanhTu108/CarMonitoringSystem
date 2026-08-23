#include "dashboard.h"

#include "ui_dashboard.h"
#include "vehicle_gauge_widget.h"

DashBoard::DashBoard(QWidget* parent)
    : QMainWindow(parent), ui(new Ui::DashBoard) {
    ui->setupUi(this);

    connect(this, &DashBoard::speeds_changed, ui->vehicle_gauge,
            &VehicleGauge::set_speed);
}

DashBoard::~DashBoard() {
    delete ui;
}
void DashBoard::set_speed(uint32_t speed) {
    this->current_speed = speed;

    emit speeds_changed(static_cast<double>(speed));
}
void DashBoard::get_speed_can() {
    // receive speed from canbus
    // value = receive....
    uint32_t speed_can = 200;
    set_speed(speed_can);
}