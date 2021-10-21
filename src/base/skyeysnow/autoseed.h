#ifndef AUTORESEED_H
#define AUTORESEED_H

#include <QCryptographicHash>
#include <QFile>
#include <QMap>

#include <base/bittorrent/addtorrentparams.h>

#include <libtorrent/bdecode.hpp>

namespace skyeysnow {

class AutoSeed
{
public:
    AutoSeed();
    AutoSeed(const AutoSeed& other);

    AutoSeed &operator=(const AutoSeed &other) = default;

    ~AutoSeed() = default;

    int loadFiledata(libtorrent::bdecode_node root);

    QByteArray getFiledata(int index) const;

//    int dump_filedata();
private:
    QByteArray hash(const QByteArray &data);

    QVector<QByteArray> filedata;
};
}


#endif // AUTORESEED_H
