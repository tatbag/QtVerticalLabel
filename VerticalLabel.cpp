VerticalLabel::VerticalLabel(const QString &text, QWidget *parent)
    : QLabel(text, parent)
{
    setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
}

void VerticalLabel::paintEvent(QPaintEvent *event) {
    Q_UNUSED(event);
    QPainter painter(this);
    painter.setRenderHint(QPainter::TextAntialiasing, true);
    painter.translate(0, height());
    painter.rotate(-90);
    QRect rotatedRect(0, 0, height(), width());
    painter.drawText(rotatedRect, Qt::AlignCenter, text());
}

QSize VerticalLabel::sizeHint() const
{
    QFontMetrics fm(font());
    QSize originalSize = fm.size(Qt::TextSingleLine, text());
    return QSize(originalSize.height() + MIN_MARGIN, originalSize.width() + MIN_MARGIN);
}
