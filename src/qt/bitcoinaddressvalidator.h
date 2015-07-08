#ifndef BITCOINADDRESSVALIDATOR_H
#define BITCOINADDRESSVALIDATOR_H

#include <QValidator>

/** Base48 entry widget validator.
   Corrects near-miss characters and refuses characters that are no part of base48.
 */

class BitcoinAddressEntryValidator : public QValidator
{
    Q_OBJECT

public:
    explicit BitcoinAddressEntryValidator(QObject *parent);

    State validate(QString &input, int &pos) const;
};

/** Bitcoin address widget validator, checks for a valid bitcoin address.
 */
class BitcoinAddressCheckValidator : public QValidator
{
    Q_OBJECT

public:
    explicit BitcoinAddressCheckValidator(QObject *parent);

    State validate(QString &input, int &pos) const;
};


#endif // BITCOINADDRESSVALIDATOR_H
