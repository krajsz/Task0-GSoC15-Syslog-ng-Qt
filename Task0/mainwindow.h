#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include <QPainter>
#include <QPushButton>
#include <QKeyEvent>
#include <QDir>
#include <QFileDialog>
#include <QString>

#include "yaml_handler.h"


/**
 * @brief The MainWindow class which contains the elements of the simple ui.
 */

class MainWindow : public QMainWindow
{
Q_OBJECT
public:
    explicit MainWindow(QWidget* parent = 0);
    ~MainWindow();

    void Init(const QString &_windowName, const QSize &_windowSize);

private:

    QLabel*       m_yamlYext;
    QPushButton*  m_open_file_button;
    Yaml_Handler* m_yaml_handler;
    bool          m_is_file_loaded = false;

    void paintEvent(QPaintEvent*);
    void keyPressEvent(QKeyEvent *);

    void SetPainterColor(QPainter& painter, int i);

private slots:
    void on_mFileDialogButton_clicked();

};

#endif // MAINWINDOW_H
