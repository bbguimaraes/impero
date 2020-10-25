#ifndef IMPERO_UI_WIDGET_H
#define IMPERO_UI_WIDGET_H

#include <QtWidgets/QWidget>

class QLineEdit;

namespace impero {

class Widget : public QWidget {
    Q_OBJECT
    void keyPressEvent(QKeyEvent *e) override;
public:
    Widget(QWidget *p = nullptr);
    void add_edit(QLineEdit *e);
    void add_panel(QWidget *w);
signals:
    void selection_moved(bool forward);
};

}

#endif
