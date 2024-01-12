#include "TableBaplieContent.h"

TableBaplieContent::TableBaplieContent(QObject *parent)
    : QAbstractTableModel{parent}
{
    table.append({"Disch Port", "Bay", "Slot", "Container Id", "Size", "Weight", "Type", "Class", "Setting", "Height", "Full", "Load Port", "Optional Port", "Carrier Port", "Del Port"});
    table.append({"HAM", "041", "041708", "CCLU 2112341", "20", "08000", "GP", " ", " ", "8'6", "Full", "CWN", " ", "CSC", "DEHAM"});
}

int TableBaplieContent::rowCount(const QModelIndex &) const
{
    return table.size();
}

int TableBaplieContent::columnCount(const QModelIndex &) const
{
    return table.at(0).size();
}

QVariant TableBaplieContent::data(const QModelIndex &index, int role) const
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

QHash<int, QByteArray> TableBaplieContent::roleNames() const
{
    QHash<int, QByteArray> roles;
    roles[TableDataRole] = "tabledata";
    roles[HeadingRole] = "heading";
    return roles;
}
