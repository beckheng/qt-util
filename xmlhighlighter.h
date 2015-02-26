#ifndef XMLHIGHLIGHTER_H
#define XMLHIGHLIGHTER_H

#include <QSyntaxHighlighter>
#include <QTextCharFormat>
#include <QTextDocument>

class XMLHighlighter : public QSyntaxHighlighter
{
    Q_OBJECT

public:
    XMLHighlighter(QTextDocument *parent = 0);
    ~XMLHighlighter();

protected:
    void highlightBlock(const QString &text) Q_DECL_OVERRIDE;

private:
    struct HighlightingRule
        {
            QRegExp pattern;
            QTextCharFormat format;
        };
        QVector<HighlightingRule> highlightingRules;

        QTextCharFormat quotationFormat;
};

#endif // XMLHIGHLIGHTER_H
