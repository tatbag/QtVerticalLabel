#ifndef VERTICALLABEL_H
#define VERTICALLABEL_H

#include <QWidget>
#include <QLabel>

static const int MIN_MARGIN = 5;

class VerticalLabel : public QLabel
{
    Q_OBJECT
public:
    explicit VerticalLabel(const QString &text, QWidget *parent = nullptr);

protected:
    void paintEvent(QPaintEvent *event) override;
    QSize sizeHint() const override;
};
