#include "qtutil.h"

#include <QDateTime>

QtUtil::QtUtil()
{
}

QString QtUtil::getCurrentYMD()
{
    return QDateTime::currentDateTime().toString("yyyyMMdd");
}
