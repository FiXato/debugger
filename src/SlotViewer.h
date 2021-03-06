#ifndef SLOTVIEWER_H
#define SLOTVIEWER_H

#include <QFrame>

struct MemoryLayout;
class QString;

class SlotViewer : public QFrame
{
	Q_OBJECT;
public:
	SlotViewer(QWidget* parent = 0);

	void refresh();
	void setMemoryLayout(MemoryLayout* ml);
	void slotsUpdated(const QString& message);

	QSize sizeHint() const;

private:
	void resizeEvent(QResizeEvent* e);
	void paintEvent(QPaintEvent* e);

	int frameL, frameR, frameT, frameB;
	int headerSize1, headerSize2, headerSize3, headerSize4;
	int headerHeight;

	MemoryLayout* memLayout;

	bool slotsChanged[4];
	bool segmentsChanged[4];
};

#endif // SLOTVIEWER_H
