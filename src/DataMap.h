/*
* Optimal Lunar Landing Analysis
* https://github.com/dankrusi/optimal-lunar-landing-analysis
*
* Contributor(s):
* Dan Krusi <dan.krusi@nerves.ch> (original author)
*
* Permission is hereby granted, free of charge, to any person obtaining a copy of
* this software and associated documentation files (the "Software"), to deal in
* the Software without restriction, including without limitation the rights to
* use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies
* of the Software, and to permit persons to whom the Software is furnished to do
* so, subject to the following conditions:
*
* The above copyright notice and this permission notice shall be included in all
* copies or substantial portions of the Software.
*
* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
* IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
* FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
* AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
* LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
* OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
* THE SOFTWARE.
*/

#ifndef DATAMAP_H
#define DATAMAP_H

#include <QObject>
#include <QGraphicsItem>
#include <QSettings>
#include <QMap>

class MapTile;

class DataMap : public QObject
{
    Q_OBJECT

protected:
    QSettings *_settings;
    QGraphicsPixmapItem *_layer;
    int _tileSize;
    int _tilesX;
    int _tilesY;
    QMap<QString,MapTile*> _tiles;
    QString _name;

public:
    DataMap(QSettings *settings, QObject *parent = 0);
    ~DataMap();
    QGraphicsItem* layer();
    virtual void load() = 0;
    void createTiles();
    virtual void loadTileImage(int tileX, int tileY, QImage &image) = 0;
    QRgb getDataAtPixel(int x, int y);
    MapTile* getTileAtPixel(int x, int y);
    double megaPixles();
    int tileSize() { return _tileSize; };
    int tilesX() { return _tilesX; };
    int tilesY() { return _tilesY; };
    QString name() { return _name; };
    void registerTileLoading(MapTile *tile);
    void registerTileLoaded(MapTile *tile);


signals:
    void mapLoading(double progress);
    void tileLoading(MapTile *tile);
    void tileLoaded(MapTile *tile);


public slots:

};

#endif // DATAMAP_H
