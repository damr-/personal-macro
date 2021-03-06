#ifndef GOTOCMDWIDGET_H
#define GOTOCMDWIDGET_H

#include "cmdwidget.h"

namespace Ui {
class GotoCmdWidget;
}

class GotoCmdWidget : public CmdWidget
{
    Q_OBJECT

    public:
        explicit GotoCmdWidget(QWidget *parent = nullptr);
        ~GotoCmdWidget() override;

        void CopyTo(CmdWidget *other) override;
        QString GetCmdString() override;
        void SetSettings(QStringList settings) override;

        bool IsValidCmd() override;

        int GetTargetRow();
        int GetAmount();
        void SetCmdSettings(int targetRow, int amount);

        void ValidateRowNumber(int cmdListCmdCount);

        int TotalAmount;

        static const int TargetRowIdx = ChildIdxStart;
        static const int AmountIdx = ChildIdxStart + 1;

    private slots:
        void amountChanged(int amount);

    private:
        Ui::GotoCmdWidget *ui;
};

#endif // GOTOCMDWIDGET_H
