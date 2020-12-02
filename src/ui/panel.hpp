#ifndef IMPERO_UI_PANEL_H
#define IMPERO_UI_PANEL_H

#include <vector>

#include <QtWidgets/QWidget>

namespace impero {

class Command;

class Panel : public QWidget {
    Q_OBJECT
    size_t n_enabled = {}, cur = {};
public:
    explicit Panel(QWidget *p = nullptr);
    void add_command(std::string_view s, int row, int col);
signals:
    void command_selected(size_t) const;
public slots:
    void update_filter(const QString &filter);
    void move_selection(bool forward);
    void select_command() const;
};

}

#endif
