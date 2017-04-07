#include "nitrosendconfig.h"
#include "ui_nitrosendconfig.h"

#include "bitcoinunits.h"
#include "guiconstants.h"
#include "optionsmodel.h"
#include "walletmodel.h"
#include "init.h"

#include <QMessageBox>
#include <QPushButton>
#include <QKeyEvent>
#include <QSettings>

NitrosendConfig::NitrosendConfig(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::NitrosendConfig),
    model(0)
{
    ui->setupUi(this);

    connect(ui->buttonBasic, SIGNAL(clicked()), this, SLOT(clickBasic()));
    connect(ui->buttonHigh, SIGNAL(clicked()), this, SLOT(clickHigh()));
    connect(ui->buttonMax, SIGNAL(clicked()), this, SLOT(clickMax()));
}

NitrosendConfig::~NitrosendConfig()
{
    delete ui;
}

void NitrosendConfig::setModel(WalletModel *model)
{
    this->model = model;
}

void NitrosendConfig::clickBasic()
{
    configure(true, 1000, 2);

    QString strAmount(BitcoinUnits::formatWithUnit(
        model->getOptionsModel()->getDisplayUnit(), 1000 * COIN));
    QMessageBox::information(this, tr("Nitrosend Configuration"),
        tr(
            "Nitrosend was successfully set to basic (%1 and 2 rounds). You can change this at any time by opening Aspire's configuration screen."
        ).arg(strAmount)
    );

    close();
}

void NitrosendConfig::clickHigh()
{
    configure(true, 1000, 8);

    QString strAmount(BitcoinUnits::formatWithUnit(
        model->getOptionsModel()->getDisplayUnit(), 1000 * COIN));
    QMessageBox::information(this, tr("Nitrosend Configuration"),
        tr(
            "Nitrosend was successfully set to high (%1 and 8 rounds). You can change this at any time by opening Aspire's configuration screen."
        ).arg(strAmount)
    );

    close();
}

void NitrosendConfig::clickMax()
{
    configure(true, 1000, 16);

    QString strAmount(BitcoinUnits::formatWithUnit(
        model->getOptionsModel()->getDisplayUnit(), 1000 * COIN));
    QMessageBox::information(this, tr("Nitrosend Configuration"),
        tr(
            "Nitrosend was successfully set to maximum (%1 and 16 rounds). You can change this at any time by opening Aspire's configuration screen."
        ).arg(strAmount)
    );

    close();
}

void NitrosendConfig::configure(bool enabled, int coins, int rounds) {

    QSettings settings;

    settings.setValue("nNitrosendRounds", rounds);
    settings.setValue("nAnonymizeDarkcoinAmount", coins);

    nNitrosendRounds = rounds;
    nAnonymizeDarkcoinAmount = coins;
}
