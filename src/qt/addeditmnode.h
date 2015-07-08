#ifndef ADDEDITMNODE_H
#define ADDEDITMNODE_H

#include <QDialog>

namespace Ui {
class AddEditMNode;
}


class AddEditMNode : public QDialog
{
    Q_OBJECT

public:
    explicit AddEditMNode(QWidget *parent = 0);
    ~AddEditMNode();

protected:

private slots:
    void on_okButton_clicked();
    void on_cancelButton_clicked();

signals:

private:
    Ui::AddEditMNode *ui;
};

#endif // ADDEDITMNODE_H
