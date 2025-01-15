#include "motionplanning.h"
#include "ui_motionplanning.h"

MotionPlanning::MotionPlanning(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::MotionPlanning)
{
    ui->setupUi(this);
}

MotionPlanning::~MotionPlanning()
{
    delete ui;
}

