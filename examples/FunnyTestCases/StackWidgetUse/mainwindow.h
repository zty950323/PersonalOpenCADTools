#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMap>
#include <QMainWindow>
#include <QPushButton>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class ZsIndexedButton : public QPushButton
{
    Q_OBJECT

public:
    inline explicit ZsIndexedButton(QWidget* parent = nullptr) : QPushButton(parent)
    {
        index = 0;
    };

    inline explicit ZsIndexedButton(const QString &text, QWidget *parent = nullptr) : QPushButton(text, parent)
    {
        index = 0;
    };

    virtual ~ZsIndexedButton()
    {

    };

    inline long long getIndex(void)
    {
        return index;
    }

    inline void setIndex(const long long & index)
    {
        this->index = index;
    }

private:
    long long index;
};

enum class SenderControls
{
    COMBOBOX,
    BUTTONS
};

class QTableWidget;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void initUi();
    void initConnections();
    void initData();
    void choseToHide(const SenderControls& control);
    void messageBoxUse(void);

protected:
    void keyPressEvent(QKeyEvent* event) override;

private slots:
    void buttonChangePages(bool checked = false);

private:
    Ui::MainWindow *ui;
    QMap<QString ,ZsIndexedButton *> m_buttons;
    QTableWidget * m_table_widget = nullptr;
};
#endif // MAINWINDOW_H
