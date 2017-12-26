#ifndef BLOCKBROWSERMODEL_H
#define BLOCKBROWSERMODEL_H

#include <QAbstractTableModel>
class BlockBrowserModelPriv;
class CWallet;
class WalletModel;
class BlockBrowserModel : public QAbstractTableModel
{
    Q_OBJECT

public:
    explicit BlockBrowserModel(CWallet* wallet, WalletModel *parent = 0);

    ~BlockBrowserModel();
    // Header:
    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const override;

    // Basic functionality:
    QModelIndex index(int row, int column,
                      const QModelIndex &parent = QModelIndex()) const override;

    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    int columnCount(const QModelIndex &parent = QModelIndex()) const override;

    // Fetch data dynamically:
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
    bool setData(const QModelIndex &index, const QVariant &value, int role);

private:
    CWallet* wallet;
    WalletModel *walletModel;
    BlockBrowserModelPriv *priv;
    QStringList columns;

    friend class BlockBrowserModelPriv;
};

#endif // BLOCKBROWSERMODEL_H
