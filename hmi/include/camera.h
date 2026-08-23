#pragma once
#include <QMainWindow>

QT_BEGIN_NAMESPACE

namespace Ui {
    class Camera;
}

QT_END_NAMESPACE

class Camera : public QMainWindow {
    Q_OBJECT
public:
    explicit Camera(QWidget* parent = nullptr);
    ~Camera();

private:
    Ui::Camera* ui;
};