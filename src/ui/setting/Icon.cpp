#include "include/ui/setting/Icon.hpp"

#include "include/global/NekoGui.hpp"

#include <QPainter>

QPixmap Icon::GetTrayIcon(Icon::TrayIconStatus status) {
    QPixmap pixmap;

    // software embedded icon
    auto pixmap_read = QPixmap(QString(":/neko/") + "nekobox" + ".png");
    if (!pixmap_read.isNull()) pixmap = pixmap_read;

    // software pack icon
    pixmap_read = QPixmap(QString("../") + "nekobox" + ".png");
    if (!pixmap_read.isNull()) pixmap = pixmap_read;

    // user icon
    pixmap_read = QPixmap(QString("./") + "nekobox" + ".png");
    if (!pixmap_read.isNull()) pixmap = pixmap_read;

    if (status == TrayIconStatus::NONE) return pixmap;

    auto p = QPainter(&pixmap);

    auto side = pixmap.width();
    auto radius = side * 0.4;
    auto d = side * 0.4;
    auto margin = side * 0.04;

    if (status == TrayIconStatus::RUNNING) {
        p.setBrush(QBrush(Qt::darkGreen));
    } else if (status == TrayIconStatus::SYSTEM_PROXY) {
        p.setBrush(QBrush(Qt::blue));
    } else if (status == TrayIconStatus::VPN) {
        p.setBrush(QBrush(Qt::red));
    } else if (status == TrayIconStatus::DNS) {
        p.setBrush(QBrush(Qt::darkMagenta));
    }
    p.drawRoundedRect(
        QRect(side - d - margin,
              side - d - margin,
              d,
              d),
        radius,
        radius);
    p.end();

    return pixmap;
}

QPixmap Icon::GetMaterialIcon(const QString &name) {
    QPixmap pixmap(":/icon/material/" + name + ".png");
    return pixmap;
}
