#ifndef PUBITEM_H
#define PUBITEM_H

#include <QtWidgets/QWidget>

namespace Ui {
class pubitem;
}

class pubitem : public QWidget
{
    Q_OBJECT

public:
    explicit pubitem(QWidget *parent = 0);
    ~pubitem();
    void enableDelBtn(bool bEnable = true);
protected:
    void changeEvent(QEvent *e);

private:
    Ui::pubitem *ui;
};

#endif // PUBITEM_H
