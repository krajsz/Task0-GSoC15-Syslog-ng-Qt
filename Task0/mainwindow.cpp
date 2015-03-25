#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent)
{
}

MainWindow::~MainWindow()
{
}

void MainWindow::Init(const QString& _windowName,const QSize& _windowSize)
{
    this->setWindowTitle(_windowName);
    this->setFixedSize(_windowSize);

    this->m_yamlYext = new QLabel(this);

    this->m_yamlYext->setText("Please open your file!");
    this->m_yamlYext->move(QPoint(10,8));
    this->m_yamlYext->adjustSize();

    this->m_open_file_button = new QPushButton("&Open file",this);
    this->m_open_file_button->move(this->width() - 110, 8);
    this->m_open_file_button->setObjectName("mFileDialogButton");
    this->m_open_file_button->resize(QSize(100,30));
    this->m_open_file_button->show();


    QMetaObject::connectSlotsByName(this);
}

void MainWindow::SetPainterColor(QPainter& painter, int i)
{
    if (!m_yaml_handler->getShapes()[i].GetProperty("color").as<std::string>().compare("red"))
    {
        painter.setPen(Qt::red);
        painter.setBrush(Qt::red);
    }
    else
    if (!m_yaml_handler->getShapes()[i].GetProperty("color").as<std::string>().compare("green"))
    {
        painter.setPen(Qt::green);
        painter.setBrush(Qt::green);

    }
    else
    if (!m_yaml_handler->getShapes()[i].GetProperty("color").as<std::string>().compare("blue"))
    {
        painter.setPen(Qt::blue);
        painter.setBrush(Qt::blue);

    }
    else
    if (!m_yaml_handler->getShapes()[i].GetProperty("color").as<std::string>().compare("black"))
    {
         painter.setPen(Qt::black);
         painter.setBrush(Qt::black);

    }
}

void MainWindow::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    if (m_is_file_loaded)
    {
        if (m_yaml_handler->getShapes().size() > 0)
        {
            this->m_yamlYext->setText(QString("File loaded, which contains ") + QString::number(m_yaml_handler->getShapes().size()) + QString(" shapes!"));
            this->m_yamlYext->adjustSize();
            for (size_t i = 0; i < m_yaml_handler->getShapes().size(); i++)
            {
                if (!m_yaml_handler->getShapes()[i].getName().compare("circle"))
                {
                    SetPainterColor(painter, i);
                    painter.drawEllipse(100,100,m_yaml_handler->getShapes()[i].GetProperty("radius").as<int>(),m_yaml_handler->getShapes()[i].GetProperty("radius").as<int>());
                }
                else
                if (!m_yaml_handler->getShapes()[i].getName().compare("rectangle"))
                {
                    SetPainterColor(painter, i);
                    painter.drawRect(100, 200,  m_yaml_handler->getShapes()[i].GetProperty("width").as<int>(), m_yaml_handler->getShapes()[i].GetProperty("height").as<int>());
                }
            }
        }
        else
        {
            std::cout << "Shape count is: 0" << std::endl;
        }
    }
}

void MainWindow::keyPressEvent(QKeyEvent * event)
{
    if (event->key() == Qt::Key_Escape)
    {
        this->close();
    }
}

void MainWindow::on_mFileDialogButton_clicked()
{
    QString file_name  = QFileDialog::getOpenFileName(this,tr("Open your YAML file"),QDir::currentPath(),tr("YAML Files [ *.yaml , *.YAML ]"));

    if (file_name.compare(""))
    {
        this->m_is_file_loaded = true;

        this->m_yaml_handler = new Yaml_Handler(file_name.toStdString());
        this->m_yaml_handler->LoadAll();
        this->repaint();
    }
}

