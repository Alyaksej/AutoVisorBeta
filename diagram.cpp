#include "diagram.h"
#include "ui_diagram.h"
#include "qcustomplot.h"

Diagram::Diagram(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Diagram)
{
    ui->setupUi(this);
}

Diagram::~Diagram()
{
    delete ui;
}
