#include "autoseed.h"

#include <sstream>

#include <QCryptographicHash>
#include <QFile>

#include <base/bittorrent/torrentinfo.h>

namespace skyeysnow {

//AutoSeed::AutoSeed(const BitTorrent::TorrentInfo &m_torrentInfo,
//                       const BitTorrent::AddTorrentParams &m_torrentParams) {
//    for (int i = 0; i < m_torrentInfo.filesCount(); i++) {
//        auto path = m_torrentInfo.filePath(i);
//        auto name = m_torrentInfo.fileName(i);
//        auto hash = m_torrentInfo.fileHash(i);
//        auto size = m_torrentInfo.fileSize(i);
//    }
//}

AutoSeed::AutoSeed()
{

}

AutoSeed::AutoSeed(const AutoSeed &other): filedata(other.filedata)
{

}

int AutoSeed::loadFiledata(libtorrent::bdecode_node node) {
    auto ret = node.dict_find("info");
    if (ret.type() == decltype(ret)::none_t) {
        return -1;
    }

    ret = ret.dict_find("files");
    if (ret.type() == decltype(ret)::none_t) {
        return -1;
    } else if (ret.type() != decltype(ret)::list_t) {
        return -1;
    }

    for (int i = 0; i < ret.list_size(); i++) {
       auto tmp = ret.list_at(i);

       auto filedata_node = tmp.dict_find("filedata");
       if (filedata_node.type() == decltype (filedata_node)::none_t) {
           this->filedata.append(QByteArray()); // NOTICE(kuriko): Append Null for placeholder
           continue;
       }

       auto filedata_data = filedata_node.string_ptr();
       auto filedata_size = filedata_node.string_length();
       this->filedata.append(QByteArray::fromRawData(filedata_data, filedata_size));
    }

    return 0;
}

QByteArray AutoSeed::getFiledata(int index) const
{
   auto ret = this->filedata[index];
   return ret;
}

int AutoSeed::alterSavePath()
{

    return 0;
}

QByteArray AutoSeed::hash(const QByteArray &data) {
    return QCryptographicHash::hash(data, QCryptographicHash::Sha1);
}

}
