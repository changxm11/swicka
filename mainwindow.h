#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMenu>
#include <QMenuBar>
#include <QAction>

#include "yahoo_loader.h"
#include "ohlc_memory_provider.h"
#include "view.h"

class QGraphicsScene;
class QSplitter;

class MainWindow : public QMainWindow {
	Q_OBJECT
	public:
		MainWindow(QWidget *parent = 0);

	private:
		void createMenus();
		void createActions();

		void doLoadYahooStock(QString stock);

		OHLCMemoryProvider* source;
		YahooLoader* yl;

		View *view;

		QMenu* fileMenu;
		QAction* exitAction;
		QAction* loadYahooStockAction;
		QAction* exportImageAction;

	private slots:
		void loadYahooStock();
		void exportImage();
		void dataPointHovered(QDateTime time, float price);
		void drawData();
};

#endif
