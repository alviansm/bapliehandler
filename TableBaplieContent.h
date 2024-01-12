#ifndef TABLEBAPLIECONTENT_H
#define TABLEBAPLIECONTENT_H

#include <QObject>
#include <qqml.h>
#include <QAbstractTableModel>

class TableBaplieContent : public QAbstractTableModel
{
    Q_OBJECT
    QML_ELEMENT
    QML_ADDED_IN_VERSION(1, 1)
    enum TableRoles {
        TableDataRole = Qt::UserRole + 1,
        HeadingRole
    };

public:
    explicit TableBaplieContent(QObject *parent = nullptr);

    int rowCount(const QModelIndex & = QModelIndex()) const override;
    int columnCount(const QModelIndex & = QModelIndex()) const override;
    QVariant data(const QModelIndex &index, int role) const override;
    QHash<int, QByteArray> roleNames() const override;

signals:

private:
    QVector<QVector<QString>> table;

};

#endif // TABLEBAPLIECONTENT_H
