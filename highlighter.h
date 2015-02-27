#ifndef HIGHLIGHTER_H
#define HIGHLIGHTER_H

#include <QSyntaxHighlighter>
#include <QTextCharFormat>
#include <QTextDocument>

enum {NONE = 0, XML_TYPE = 1};

class Highlighter : public QSyntaxHighlighter
{
    Q_OBJECT

public:
    Highlighter(QTextDocument *parent = 0);
    ~Highlighter();

    void setFormatType(int type);

protected:
    void highlightBlock(const QString &text) Q_DECL_OVERRIDE;

private:
    void setXMLTypeRule();

private:
    struct HighlightingRule
        {
            QRegExp pattern;
            QTextCharFormat format;
        };

    QVector<HighlightingRule> highlightingRules;

    QTextCharFormat quotationFormat;

    int currentType;
};

#endif // HIGHLIGHTER_H
