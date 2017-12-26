#include "blockbrowser.h"
#include "ui_blockbrowser.h"
#include "wallet.h"
#include "walletmodel.h"
#include "blockbrowsermodel.h"
BlockBrowser::BlockBrowser(CWallet *wallet,WalletModel *walletModel,QWidget *parent) :
    QWidget(parent),wallet(wallet),walletModel(walletModel),
    ui(new Ui::BlockBrowser)
{
    ui->setupUi(this);
    BlockBrowserModel* model = new BlockBrowserModel(wallet,walletModel);
    ui->tableView->setModel(model);
}

BlockBrowser::~BlockBrowser()
{
    delete ui;
}

void BlockBrowser::changeEvent(QEvent *e)
{
    QWidget::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;
    }
}
