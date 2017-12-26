#include "pubkeyitem.h"
#include "ui_pubkeyitem.h"
#include "multiaddress.h"
#include <QMessageBox>
PubkeyItem::PubkeyItem(QWidget *parent) :
    QFrame(parent),
    ui(new Ui::PubkeyItem)
{
    ui->setupUi(this);
    ui->delButton->setDisabled(true);
}

PubkeyItem::~PubkeyItem()
{
    delete ui;
}

void PubkeyItem::setModel(MultiAddress*  model)
{
    this->model = model;
}

void PubkeyItem::changeEvent(QEvent *e)
{
    QFrame::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;
    }
}

void PubkeyItem::enableDelBtn(bool bEnable)
{
    ui->delButton->setDisabled(bEnable);
}

void PubkeyItem::on_delButton_clicked()
{
    model->RemovePubkeyItem(this);
}
