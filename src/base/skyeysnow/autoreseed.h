#ifndef AUTORESEED_H
#define AUTORESEED_H

#include <QCryptographicHash>
#include <QFile>

#include <base/bittorrent/addtorrentparams.h>
#include <base/bittorrent/torrentinfo.h>

namespace skyeysnow {

class AutoReseed
{
public:
    AutoReseed() = delete;
    AutoReseed(const BitTorrent::TorrentInfo &m_torrentInfo,
               const BitTorrent::AddTorrentParams &m_torrentParams);

private:
    QByteArray hash(const QByteArray &data);
};

}

#endif // AUTORESEED_H
