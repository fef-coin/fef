#include "pubitem.h"
#include "ui_pubitem.h"

pubitem::pubitem(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::pubitem)
{
    ui->setupUi(this);
    ui->delButton->setDisabled(true);
}

void pubitem::enableDelBtn(bool bEnable)
{
    ui->delButton->setDisabled(bEnable);
}

pubitem::~pubitem()
{
    delete ui;
}

void pubitem::changeEvent(QEvent *e)
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
