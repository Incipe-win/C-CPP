#ifndef SMALLWIDGET_H
#define SMALLWIDGET_H

#include <QWidget>

namespace Ui {
    class SmallWidget;
}

class SmallWidget : public QWidget {
    Q_OBJECT

  public:
    explicit SmallWidget(QWidget* parent = nullptr);
    ~SmallWidget();
    void setValue(int value);
    int getValue();

  private:
    Ui::SmallWidget* ui;
};

#endif  // SMALLWIDGET_H
