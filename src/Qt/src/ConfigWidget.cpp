/**********************************************
 * @file ConfigWidget.cpp
 * @brief None
 * @author Half_nothing
 * @email Half_nothing@163.com
 * @version 1.0.0
 * @date 2024.03.24
 * @license GNU General Public License (GPL)
 **********************************************/

// You may need to build the project (run Qt uic code generator) to get "ui_ConfigWidget.h" resolved

#include "ConfigWidget.h"

#include "ui_ConfigWidget.h"

namespace QT {
    ConfigWidget::ConfigWidget(QWidget *parent) :
        QWidget(parent), ui(new Ui::ConfigWidget) {
        ui->setupUi(this);
        ui->startPointColorWidget->setConfigField(START_POINT_COLOR);
        ui->endPointColorWidget->setConfigField(END_POINT_COLOR);
        ui->wallPointColorWidget->setConfigField(WALL_COLOR);
        ui->searchedPointColorWidget->setConfigField(SEARCHED_POINT_COLOR);
        ui->pathPointColorWidget->setConfigField(PATH_POINT_COLOR);
    }

    ConfigWidget::~ConfigWidget() {
        delete ui;
    }
} // QT