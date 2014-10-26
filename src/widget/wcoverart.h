#ifndef WCOVERART_H
#define WCOVERART_H

#include <QColor>
#include <QDomNode>
#include <QMouseEvent>
#include <QWidget>

#include "dlgcoverartfullsize.h"
#include "trackinfoobject.h"
#include "library/coverartcache.h"
#include "library/trackcollection.h"
#include "skin/skincontext.h"
#include "widget/wbasewidget.h"
#include "widget/wcoverartmenu.h"

class WCoverArt : public QWidget, public WBaseWidget {
    Q_OBJECT
  public:
    WCoverArt(QWidget* parent, TrackCollection* pTrackCollection);
    virtual ~WCoverArt();

    void setup(QDomNode node, const SkinContext& context);

  public slots:
    void slotReset();
    void slotEnable(bool);
    void slotLoadCoverArt(CoverInfo info, bool cachedOnly);

  private slots:
    void slotPixmapFound(int trackId, QPixmap pixmap);
    void slotCoverLocationUpdated(const QString& newLoc,
                                  const QString& oldLoc,
                                  QPixmap px);

  protected:
    void paintEvent(QPaintEvent*);
    void resizeEvent(QResizeEvent*);
    void mousePressEvent(QMouseEvent*);
    void leaveEvent(QEvent*);

  private:
    QPixmap scaledCoverArt(const QPixmap& normal);

    bool m_bEnable;
    WCoverArtMenu* m_pMenu;
    QPixmap m_loadedCover;
    QPixmap m_loadedCoverScaled;
    TrackDAO& m_trackDAO;
    CoverInfo m_lastRequestedCover;
    DlgCoverArtFullSize* m_pDlgFullSize;
};

#endif // WCOVERART_H
