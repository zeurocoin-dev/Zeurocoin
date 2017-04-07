#ifndef NITROSENDCONFIG_H
#define NITROSENDCONFIG_H

#include <QDialog>

namespace Ui {
    class NitrosendConfig;
}
class WalletModel;

/** Multifunctional dialog to ask for passphrases. Used for encryption, unlocking, and changing the passphrase.
 */
class NitrosendConfig : public QDialog
{
    Q_OBJECT

public:

    NitrosendConfig(QWidget *parent = 0);
    ~NitrosendConfig();

    void setModel(WalletModel *model);


private:
    Ui::NitrosendConfig *ui;
    WalletModel *model;
    void configure(bool enabled, int coins, int rounds);

private slots:

    void clickBasic();
    void clickHigh();
    void clickMax();
};

#endif // NITROSENDCONFIG_H
