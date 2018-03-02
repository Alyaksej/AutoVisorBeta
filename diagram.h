#ifndef DIAGRAM_H
#define DIAGRAM_H

#include <QWidget>

#include <qcustomplot.h>

namespace Ui {
class Diagram;
}

class Diagram : public QWidget
{
    Q_OBJECT

public:
    explicit Diagram(QWidget *parent = 0);
    ~Diagram();

private:
    Ui::Diagram *ui;
};

#endif // DIAGRAM_H
