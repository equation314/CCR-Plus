#ifndef ADVANCEDCONFIGUREDIALOG_H
#define ADVANCEDCONFIGUREDIALOG_H

#include <QDialog>
#include <QListWidget>

#include "common/problem.h"
#include "configure/general/generalconfigurewidget.h"
#include "configure/compiler/compilerconfigurewidget.h"
#include "configure/testcase/testcaseconfigurewidget.h"

namespace Ui
{
class AdvancedConfigureDialog;
}

class AdvancedConfigureDialog : public QDialog
{
    Q_OBJECT
public:
    explicit AdvancedConfigureDialog(const QList<Problem*>& problems, QWidget* parent = nullptr);
    ~AdvancedConfigureDialog();

    QList<Problem*> Problems() const { return problems; }

public slots:
    void accept() override;

private:
    Ui::AdvancedConfigureDialog* ui;
    GeneralConfigureWidget* general_configure_widget;
    CompilerConfigureWidget* compiler_configure_widget;
    TestCaseConfigureWidget* testcase_configure_widget;
    Problem* current_problem;
    QList<Problem*> old_problems, problems;

    void loadFromProblem(Problem* problem);

private slots:
    void onListWidgetCurrentItemChanged(QListWidgetItem* current, QListWidgetItem* previous);
};

#endif // ADVANCEDCONFIGUREDIALOG_H