#include "mainwindow.h"

#include <QPushButton>

#include "ui_mainwindow.h"
MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);

    dashboard_window = new DashBoard(this);
    // ui->stackedWidget->addWidget(dashboard_window);
    uint8_t dashboard_idx = ui->ui_display->addWidget(dashboard_window);
    ui->ui_display->addWidget(dashboard_window);
    connect(ui->_dash_board_btn, &QPushButton::clicked, this,
            [this, dashboard_idx]() {
                ui->ui_display->setCurrentIndex(dashboard_idx);
            });
}

MainWindow::~MainWindow() {
    delete ui;
}
