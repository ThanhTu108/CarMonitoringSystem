#include "mainwindow.h"

#include <QPushButton>
#include <iostream>

#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);

    connect(ui->Dashboard_btn, &QPushButton::clicked, this,
            [this]() { std::cout << "button is click\n"; });
    connect(ui->setting_btn, &QPushButton::clicked, this,
            [this]() { std::cout << "setting is click\n"; });
}

MainWindow::~MainWindow() {
    delete ui;
}