/**********************************************
* @file BmpImage8Bit.h
 * @brief 8位位图文件操作类头文件
 * @author Half_nothing
 * @email Half_nothing@163.com
 * @version 1.0.0
 * @date 2024.3.3
 * @license GNU General Public License (GPL)
 **********************************************/
#ifndef DAC_BMPIMAGE8BIT_H
#define DAC_BMPIMAGE8BIT_H

#include <string>
#include "BmpImage.hpp"

/**
 * @class BmpImage8Bit
 * @brief 8位位图文件操作类
 */
class BmpImage8Bit final : public BmpImage<uint8_t> {
public:
    BmpImage8Bit();

    void readImage(const std::string &filename) override;

    void saveImage(const std::string &filename) override;

    void toQPixMap(QPixmap &pixmap) override;

    void bfs(QPainter &painter, QPoint start, QPoint end) override;

    void dfs(QPainter &painter, QPoint start, QPoint end) override;

    void aStar(QPainter &painter, QPoint start, QPoint end) override;
};

#endif
