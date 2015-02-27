#include "highlighter.h"

Highlighter::Highlighter(QTextDocument *parent)
    : QSyntaxHighlighter(parent)
{
}

Highlighter::~Highlighter()
{

}

void Highlighter::setFormatType(int type)
{
    this->highlightingRules.clear();

    switch (type)
    {
    case XML_TYPE:
        this->setXMLTypeRule();
        break;
    default:
        break;
    }
}

void Highlighter::highlightBlock(const QString &text)
{
    foreach (const HighlightingRule &rule, this->highlightingRules)
    {
        QRegExp expression(rule.pattern);
        int index = expression.indexIn(text);
        while (index >= 0)
        {
            int length = expression.matchedLength();
            setFormat(index, length, rule.format);
            index = expression.indexIn(text, index + length);
        }
    }
}

void Highlighter::setXMLTypeRule()
{
    HighlightingRule rule;

    this->quotationFormat.setForeground(Qt::darkGreen);
    rule.pattern = QRegExp("\".*\"");
    rule.pattern.setMinimal(true);
    rule.format = this->quotationFormat;
    this->highlightingRules.append(rule);
}
