#ifndef UTILITYDIALOG_H
#define UTILITYDIALOG_H


#include <QObject>
#include <QDialog>
/** "Shutdown" window */
class BitcoinGUI;
class ShutdownWindow : public QWidget
{
    Q_OBJECT

public:
    ShutdownWindow(QWidget *parent=0, Qt::WindowFlags f=0);
    static QWidget *showShutdownWindow(BitcoinGUI *window);

protected:
    void closeEvent(QCloseEvent *event);
};
#endif // UTILITYDIALOG_H
