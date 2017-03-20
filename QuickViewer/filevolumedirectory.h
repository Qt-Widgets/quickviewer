#ifndef FILEVOLUMEDIRECTORY_H
#define FILEVOLUMEDIRECTORY_H

#include <QObject>
#include "filevolume.h"

class FileVolumeDirectory : public IFileVolume
{
    Q_OBJECT
public:
    /**
     * @brief 新しいディレクトリを設定する
     * @param dir
     */
    explicit FileVolumeDirectory(QObject* parent, QString dir);

    QString currentPath();
    QImage currentImage();

public:
    /**
     * @brief 現在のファイルリストの中で次のファイルに移動する
     * @return 成功/失敗(ファイルリスト終端等)
     */
    bool nextFile();
    /**
     * @brief 現在のファイルリストの中で前のファイルに移動する
     * @return 成功/失敗(ファイルリスト終端等)
     */
    bool prevFile();
    /**
     * @brief 現在のファイルリストの中で指定されたidx値に対応するファイルに移動する(最大値はディレクトリまたはアーカイブの画像数-1)
     * @return 成功/失敗(ファイルリスト終端等)
     */
    bool setIndexedFile(int idx);
    /**
     * @brief 次のディレクトリまたはアーカイブに移動する
     * @return 成功/失敗(正常にファイルリストを取得できなかった場合)
     */
    bool nextVolume();
    /**
     * @brief 前のディレクトリまたはアーカイブに移動する
     * @return 成功/失敗(正常にファイルリストを取得できなかった場合)
     */
    bool prevVolume();
    /**
     * @brief ボリュームが持つページ数を返す
     * @return ボリュームが持つページ数
     */
    int size();

protected:
    QDir m_directory;
    QList<QString> m_filelist;
    int m_cnt;
    /**
     * @brief m_current　現在選択中のファイル名
     */
    QString m_current;
    /**
     * @brief m_cachedPath キャッシュされた現在の画像のファイルパス
     */
    QString m_cachedPath;
    /**
     * @brief m_cachedImage キャッシュされた現在の画像
     */
    QImage m_cachedImage;
};

#endif // FILEVOLUMEDIRECTORY_H
