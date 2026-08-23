#pragma once

#include <QMainWindow>
#include <QStackedWidget>

#include "camera.h"
#include "dashboard.h"
QT_BEGIN_NAMESPACE

namespace Ui {
    class MainWindow;
}

QT_END_NAMESPACE

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    explicit MainWindow(QWidget* parent = nullptr);
    ~MainWindow();
    void onDashboardClicked();

private:
    Ui::MainWindow* ui;
    DashBoard* dashboard_window = nullptr;
    Camera* camera_window = nullptr;
};
