#ifndef PUBKEYITEM_H
#define PUBKEYITEM_H

#include <QtWidgets/QFrame>
class MultiAddress;
namespace Ui {
class PubkeyItem;
}

class PubkeyItem : public QFrame
{
    Q_OBJECT

public:
    explicit PubkeyItem(QWidget *parent = 0);
    ~PubkeyItem();
    void enableDelBtn(bool bEnable = true);
    void setModel(MultiAddress*  model);
private slots:
    void on_delButton_clicked();
protected:
    void changeEvent(QEvent *e);

private:
    Ui::PubkeyItem *ui;
    MultiAddress*  model;
};

#endif // PUBKEYITEM_H
