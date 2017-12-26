#include "blockbrowsermodel.h"
#include "main.h"
#include "wallet.h"
#include "walletmodel.h"
#include <QMessageBox>
#include <QString>
class BlockBrowserModelPriv{
public:
    BlockBrowserModel* parent;
    CWallet *wallet;
    BlockBrowserModelPriv(CWallet *wallet, BlockBrowserModel *parent) :
        wallet(wallet),
        parent(parent)
    {
    }
    int size()
    {
        return 10;
    }
    bool index(int nHeight,CBlock& block){
        CBlockIndex* pblockindex = FindBlockByHeight(nHeight);
        if(pblockindex == NULL)
        {
            return false;
        }
        block.ReadFromDisk(pblockindex, true);
        return true;
    }
};


BlockBrowserModel::BlockBrowserModel(CWallet* wallet, WalletModel *parent):
    QAbstractTableModel(parent),
    wallet(wallet),
    walletModel(parent),
    priv(new BlockBrowserModelPriv(wallet, this))
{
    columns <<tr("Date") << tr("Index") << tr("BlockHash");
}

BlockBrowserModel::~BlockBrowserModel()
{
//    delete priv;
}


QVariant BlockBrowserModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    return "123213";
    if(orientation == Qt::Horizontal)
    {
        if(role == Qt::DisplayRole)
        {
            return columns[section];
        }
    }
}

QModelIndex BlockBrowserModel::index(int row, int column, const QModelIndex &parent) const
{
    return QModelIndex();
    CBlock data;
    if(priv->index(row,data))
    {
        return createIndex(row, column, &data);
    }
    else
    {
        return QModelIndex();
    }
}

int BlockBrowserModel::rowCount(const QModelIndex &parent) const
{
    return priv->size();
}

int BlockBrowserModel::columnCount(const QModelIndex &parent) const
{
    return columns.length();
}


bool BlockBrowserModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    return true;
}

QVariant BlockBrowserModel::data(const QModelIndex &index, int role) const
{
//    if (!index.isValid())
//        return QVariant();
//    CBlock *rec = static_cast<CBlock*>(index.internalPointer());

    QMessageBox::information(NULL,"",QObject::tr("%1").arg(index.column()));
    switch (index.column()) {
    case 1:
        return 12323;//rec->GetBlockTime();
    case 2:
        return 111;
    case 3:
        return "12312";
    default:
        return "QVariant()";
    }
}
