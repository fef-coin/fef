#ifndef FINANCE_H
#define FINANCE_H

#include <QtWidgets/QDialog>

namespace Ui {
class Finance;
}

class Finance : public QDialog
{
    Q_OBJECT

public:
    explicit Finance(QWidget *parent = 0);
    ~Finance();

    void AddWidget(QString label,QWidget* widgets);
    void SetCurrentIndex(int index);
protected:
    void changeEvent(QEvent *e);

private:
    Ui::Finance *ui;
};

#endif // FINANCE_H
