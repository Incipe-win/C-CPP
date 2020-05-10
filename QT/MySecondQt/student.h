#ifndef STUDENT_H
#define STUDENT_H

#include <QObject>

class Student : public QObject {
    Q_OBJECT
  public:
    explicit Student(QObject* parent = nullptr);

  signals:

  public slots:
    // 自定义槽函数
    // 高版本可以不需要写到这里
    void treat();
    // 槽函数需要声明，也需要实现
    // 返回值是void
    // 可以有参数，可以重载
    void treat(QString foodName);
};

#endif  // STUDENT_H
