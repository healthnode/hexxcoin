#ifndef MNODECONFIGDIALOG_H
#define MNODECONFIGDIALOG_H

#include <QDialog>

namespace Ui {
    class MNodeConfigDialog;
}

QT_BEGIN_NAMESPACE
class QModelIndex;
QT_END_NAMESPACE

/** Dialog showing transaction details. */
class MNodeConfigDialog : public QDialog
{
    Q_OBJECT

public:
    explicit MNodeConfigDialog(QWidget *parent = 0, QString nodeAddress = "123.456.789.123:9999", QString privkey="MASTERNODEPRIVKEY");
    ~MNodeConfigDialog();

private:
    Ui::MNodeConfigDialog *ui;
};

#endif // MNODECONFIGDIALOG_H
