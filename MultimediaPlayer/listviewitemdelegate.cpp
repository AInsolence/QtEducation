#include "listviewitemdelegate.h"
#include <QFileInfo>
#include <QRegExp>

ListViewItemDelegate::ListViewItemDelegate(QObject* obj)
    : QStyledItemDelegate (obj)
{

}

QString ListViewItemDelegate::displayText(const QVariant &value,
                                          const QLocale &locale) const
{
    Q_UNUSED(locale)

    // get file name from path
    auto fileName = QFileInfo(value.toString()).fileName();
    // delete file extention
    QRegExp exp("\\.[^.]*$");
    fileName.remove(exp);

    return fileName;
}
