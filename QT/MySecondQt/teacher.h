#ifndef TEACHER_H
#define TEACHER_H

#include <QObject>

class Teacher : public QObject {
    Q_OBJECT
  public:
    explicit Teacher(QObject* parent = nullptr);

  signals:
    // 自定义信号 需要写到signals下
    // 返回类型必须是void
    // 信号只需要声明，不需要实现
    // 型号可以有参数

    void hungry();
    void hungry(QString foodName);
};

#endif  // TEACHER_H
