#ifndef QVALIDATEDLINEEDIT_H
#define QVALIDATEDLINEEDIT_H

#include <QLineEdit>

/** Line edit that can be marked as "invalid" to show input validation feedback. When marked as invalid,
   it will get a red background until it is focused.
 */
class QValidatedLineEdit : public QLineEdit
{
    Q_OBJECT

public:
    explicit QValidatedLineEdit(QWidget *parent = 0);
    void clear();
    void setCheckValidator(const QValidator *v);

protected:
    void focusInEvent(QFocusEvent *evt);
    void focusOutEvent(QFocusEvent *evt);

private:
    bool valid;
    const QValidator *checkValidator;

public slots:
    void setValid(bool valid);
    void setEnabled(bool enabled);

private slots:
    void markValid();
    void checkValidity();
};

#endif // QVALIDATEDLINEEDIT_H
