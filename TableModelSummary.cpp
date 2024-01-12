#include "TableModelSummary.h"

#include <Qt>
#include <QModelIndex>


TableModelSummary::TableModelSummary(QObject *parent)
    : QAbstractTableModel{parent}
{
    table.append({"Units", "TEUs", "Total Weight", "RF", "DRY", "Class", "Full", "Mt", "40'", "40' - Weight", "20'", "20' - Weight", "BB - Units", "BB - Weight"});
    table.append({"343", "577", "7616,3", "4", "339", "18", "314", "29", "234", "6117,4", "109", "1498,6", "0", "0,0"});
    table.append({"343", "577", "7616,3", "4", "339", "18", "314", "29", "234", "6117,4", "109", "1498,6", "0", "0,0"});
    table.append({"343", "577", "7616,3", "4", "339", "18", "314", "29", "234", "6117,4", "109", "1498,6", "0", "0,0"});
    table.append({"343", "577", "7616,3", "4", "339", "18", "314", "29", "234", "6117,4", "109", "1498,6", "0", "0,0"});
    table.append({"343", "577", "7616,3", "4", "339", "18", "314", "29", "234", "6117,4", "109", "1498,6", "0", "0,0"});
    table.append({"343", "577", "7616,3", "4", "339", "18", "314", "29", "234", "6117,4", "109", "1498,6", "0", "0,0"});
    table.append({"343", "577", "7616,3", "4", "339", "18", "314", "29", "234", "6117,4", "109", "1498,6", "0", "0,0"});
    table.append({"343", "577", "7616,3", "4", "339", "18", "314", "29", "234", "6117,4", "109", "1498,6", "0", "0,0"});
}

int TableModelSummary::rowCount(const QModelIndex &) const
{
    return table.size();
}

int TableModelSummary::columnCount(const QModelIndex &) const
{
    return table.at(0).size();
}

QVariant TableModelSummary::data(const QModelIndex &index, int role) const
{
    switch (role) {
    case TableDataRole:
    {
        return table.at(index.row()).at(index.column());
    }
    case HeadingRole:
    {
        if (index.row() == 0) {
            return true;
        } else {
            return false;
        }
    }
    }

    return QVariant();
}

QHash<int, QByteArray> TableModelSummary::roleNames() const
{
    QHash<int, QByteArray> roles;
    roles[TableDataRole] = "tabledata";
    roles[HeadingRole] = "heading";
    return roles;
}

Qt::ItemFlags TableModelSummary::flags(const QModelIndex &index) const
{
    Q_UNUSED(index)
    return Qt::ItemIsSelectable | Qt::ItemIsEnabled | Qt::ItemIsEditable;
}

void TableModelSummary::setData(QModelIndex index, QString userInput, QString userInput2)
{
    qDebug() << "Current cell value: " << table[index.row()][index.column()];
    qDebug() << "Row: " << index.row();
    qDebug() << "Column: " << index.column();
    if (index.column() != 0) {
        table[index.column()][index.row()] = userInput;
        QModelIndex indexChangeOrigin = createIndex(index.column(), index.row());
        QModelIndex indexChangeDest = createIndex(index.column(), index.row());
        emit dataChanged(indexChangeOrigin, indexChangeDest);
    } else {
        qDebug() << "Can't change table header!";

    }

    // emit tableChanged();
}
