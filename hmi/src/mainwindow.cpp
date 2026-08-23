#include "mainwindow.h"

#include <QPushButton>

#include "ui_mainwindow.h"
MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);

    // dashboard display
    dashboard_window = new DashBoard(this);
    ui->ui_display->addWidget(dashboard_window);

    // camera display
    camera_window = new Camera(this);
    // ui->ui_display->addWidget(camera_window);

    uint8_t dashboard_idx = ui->ui_display->addWidget(dashboard_window);
    connect(ui->_dash_board_btn, &QPushButton::clicked, this,
            [this, dashboard_idx]() {
                ui->ui_display->setCurrentIndex(dashboard_idx);
            });

    uint8_t camera_idx = ui->ui_display->addWidget(camera_window);
    connect(ui->_camera_btn, &QPushButton::clicked, this,
            [this, camera_idx]() {
                ui->ui_display->setCurrentIndex(camera_idx);
            });

    ui->ui_display->setCurrentIndex(dashboard_idx);
}

MainWindow::~MainWindow() {
    delete ui;
}
