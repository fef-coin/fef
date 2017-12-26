#ifndef MULTIADDRESS_H
#define MULTIADDRESS_H

#include <QtWidgets/QDialog>
class PubkeyItem;
namespace Ui {
class MultiAddress;
}
class MultiAddress : public QDialog
{
    Q_OBJECT

public:
    explicit MultiAddress(QWidget *parent = 0);
    ~MultiAddress();
    void RemovePubkeyItem(PubkeyItem* item);
private:
    void SetDelBtn(bool bEnable);
    void ResizeScrollView();
private slots:
    void on_generate_clicked();
    void on_importMultiAddress_clicked();
protected:
    void changeEvent(QEvent *e);
private slots:
    void on_addpubkey_clicked();
private:
    Ui::MultiAddress *ui;
    QList<PubkeyItem*> items;
};

#endif // MULTIADDRESS_H
