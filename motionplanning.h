#ifndef MOTIONPLANNING_H
#define MOTIONPLANNING_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class MotionPlanning; }
QT_END_NAMESPACE

class MotionPlanning : public QWidget
{
    Q_OBJECT

public:
    MotionPlanning(QWidget *parent = nullptr);
    ~MotionPlanning();

private:
    Ui::MotionPlanning *ui;
};
#endif // MOTIONPLANNING_H
