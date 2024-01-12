#ifndef TABLEMODELSUMMARY_H
#define TABLEMODELSUMMARY_H

#include <QObject>
#include <qqml.h>
#include <QAbstractTableModel>
#include <QAbstractItemModel>
#include <Qt>
#include <QModelIndex>

class TableModelSummary : public QAbstractTableModel
{
    Q_OBJECT
    QML_ELEMENT
    QML_ADDED_IN_VERSION(0, 1)
    enum TableRoles {
        TableDataRole = Qt::UserRole + 1,
        HeadingRole
    };

    // Q_PROPERTY(QVector<QVector<QString>> table READ table WRITE setTable NOTIFY tableChanged FINAL)

public:
    explicit TableModelSummary(QObject *parent = nullptr);

    int rowCount(const QModelIndex & = QModelIndex()) const override;
    int columnCount(const QModelIndex & = QModelIndex()) const override;
    QVariant data(const QModelIndex &index, int role) const override;
    QHash<int, QByteArray> roleNames() const override;
    Qt::ItemFlags flags(const QModelIndex &index) const override;

signals:
    void tableChanged();

public slots:
    void setData(QModelIndex index, QString userInput, QString);

private:
    QVector<QVector<QString>> table;

};

#endif // TABLEMODELSUMMARY_H
