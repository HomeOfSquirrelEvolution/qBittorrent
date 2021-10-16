#include "autoreseed.h"

#include <sstream>

#include <QCryptographicHash>
#include <QFile>

#include <base/bittorrent/torrentinfo.h>

namespace skyeysnow {

AutoReseed::AutoReseed(const BitTorrent::TorrentInfo &m_torrentInfo,
                       const BitTorrent::AddTorrentParams &m_torrentParams) {
    for (int i = 0; i < m_torrentInfo.filesCount(); i++) {
        auto path = m_torrentInfo.filePath(i);
        auto name = m_torrentInfo.fileName(i);
        auto hash = m_torrentInfo.fileHash(i);
        auto size = m_torrentInfo.fileSize(i);
    }
}

QByteArray AutoReseed::hash(const QByteArray &data) {
    return QCryptographicHash::hash(data, QCryptographicHash::Sha1);
}

}
