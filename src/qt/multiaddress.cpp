#include "multiaddress.h"
#include "ui_multiaddress.h"
#include "pubkeyitem.h"
#include <QScrollBar>
#include <QMessageBox>
MultiAddress::MultiAddress(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MultiAddress)
{
    ui->setupUi(this);
    this->setWindowTitle(tr("Create Multisig"));
    PubkeyItem* item = new PubkeyItem(this);
    item->setModel(this);
    ui->entries->addWidget(item);
    items.append(item);
    ResizeScrollView();

    ui->multitype->setId(ui->r2of2,1);
    ui->multitype->setId(ui->r2of3,2);
    ui->multitype->setId(ui->r3of3,3);
}

MultiAddress::~MultiAddress()
{
    delete ui;
}

void MultiAddress::changeEvent(QEvent *e)
{
    QDialog::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;
    }
}

void MultiAddress::on_addpubkey_clicked()
{
    if(items.size() == 3)
    {
        return;
    }
    PubkeyItem* item = new PubkeyItem(this);
    item->setModel(this);
    ui->entries->addWidget(item);
    items.append(item);
    SetDelBtn(false);
    ResizeScrollView();
}


void MultiAddress::ResizeScrollView()
{
    ui->scrollAreaWidgetContents->resize(ui->scrollAreaWidgetContents->sizeHint());
    QScrollBar* bar = ui->scrollArea->verticalScrollBar();
    if(bar)
        bar->setSliderPosition(bar->maximum());
}

void MultiAddress::RemovePubkeyItem(PubkeyItem* item)
{
    items.removeOne(item);
    ui->entries->removeWidget(item);
    delete item;
    ResizeScrollView();
    if(items.size() == 1)
    {
        for(int i = 0;i<items.size();i++)
        {
            items[i]->enableDelBtn(true);
        }
    }
}

void MultiAddress::SetDelBtn(bool bEnable)
{
    for(int i = 0;i<items.size();i++)
    {
        items[i]->enableDelBtn(bEnable);
    }
}


void MultiAddress::on_generate_clicked()
{

    QMessageBox::information(NULL,"",tr("%1").arg(ui->multitype->checkedId()));
}

void MultiAddress::on_importMultiAddress_clicked()
{
    QMessageBox::information(NULL,"","");
}
