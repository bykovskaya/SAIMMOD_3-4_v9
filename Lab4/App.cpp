#include "App.h"
#include <qmessagebox.h>

App::App(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);

    ui.lineEditP_1->setText("0.4");
    ui.lineEditP_2->setText("0.5");

    connect(ui.button, SIGNAL(clicked()), this, SLOT(RunImitation()));
}

void App::RunImitation()
{
  double _p1 = ui.lineEditP_1->text().toDouble();
  double _p2 = ui.lineEditP_2->text().toDouble();
  
  model.clear();
  model.setProbabilities(_p1, _p2);
  model.simulate(1000);

  QString result = "";
  std::map<QString, unsigned int> res = model.getResult();

  int i = 0;
  for (const auto el : res)
  {
    result += "[" + el.first + "]: " + QString::number((double)res[el.first]/model.getTicks()) + "\n";
    //result += QString::number(i++) + " -> [" + el.first + "]: " + QString::number((double)res[el.first]) + "\n";
  }

  result += "\nA = " + QString::number(model.getA()) + "\n";
  result += "Lc = " + QString::number(model.getLc()) + "\n";
  result += "Wc = " + QString::number(model.getWc()) + "\n";
  result += "Lq = " + QString::number(model.getLq()) + "\n";
  result += "Aq = " + QString::number(model.getAq()) + "\n";
  result += "Wq = " + QString::number(model.getWq()) + "\n";
  result += "Po = " + QString::number(model.getPotk()) + "\n";
  result += "Q = " + QString::number(model.getQ()) + "\n";

  ui.resultTextEdit->setText(result);
}
