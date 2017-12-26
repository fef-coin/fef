#ifndef BLOCKBROWSER_H
#define BLOCKBROWSER_H

#include <QtWidgets/QWidget>
class CWallet;
class WalletModel;
namespace Ui {
class BlockBrowser;
}

class BlockBrowser : public QWidget
{
    Q_OBJECT

public:
    explicit BlockBrowser(CWallet *wallet,WalletModel *walletModel,QWidget *parent = 0);
    ~BlockBrowser();

protected:
    void changeEvent(QEvent *e);

private:
    Ui::BlockBrowser *ui;
    CWallet *wallet;
    WalletModel *walletModel;

};

#endif // BLOCKBROWSER_H
