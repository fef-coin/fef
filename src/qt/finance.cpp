#include "finance.h"
#include "ui_finance.h"

Finance::Finance(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Finance)
{
    ui->setupUi(this);
}

Finance::~Finance()
{
    delete ui;
}

void Finance::changeEvent(QEvent *e)
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
void Finance::SetCurrentIndex(int index)
{
    ui->tabWidget->setCurrentIndex(index);
}
void Finance::AddWidget(QString label,QWidget* widgets)
{
    ui->tabWidget->addTab(widgets,label);
}
