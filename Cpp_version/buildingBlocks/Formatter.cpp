#include "card.h"
#include "filereader.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"

using namespace std;
using std::string;

QStringList selectionCards = {"Blur",     "Counterspell",   "Fireball",
                              "Identify", "Invisebility",   "Locate_Object",
                              "Shatter",  "Vicious_Mockery"};
std::vector<std::string> cards = {
    "Github\\MythicRealm\\MythicRealm\\blur.json",
    "Github\\MythicRealm\\MythicRealm\\fireball.json",
    "Github\\MythicRealm\\MythicRealm\\counterspell.json",
    "Github\\MythicRealm\\MythicRealm\\shatter.json",
    "Github\\MythicRealm\\MythicRealm\\identify.json"};

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
  ui->setupUi(this);

  for (int i = 0; i < selectionCards.size(); i++) {
    QListWidgetItem* item = new QListWidgetItem;

    item->setText(selectionCards[i]);
    item->setIcon(QIcon("card-games.png"));
    item->setCheckState(Qt::Unchecked);

    ui->listWidget->addItem(item);
  }

  dnd::FileReader* fileReader = new dnd::FileReader();

  for (size_t i = 0; i < cards.size(); i++) {
    QJsonObject jsonObject = fileReader->readJsonFile(cards[i]);

    dnd::Card* c1 = new dnd::Card(jsonObject);
    c1->printCardInfo();

    delete c1;
  }
  delete fileReader;
}

MainWindow::~MainWindow() { delete ui; }

void MainWindow::on_listWidget_itemClicked(QListWidgetItem* item) {
  if (item->checkState() == Qt::Checked) {
    qDebug() << "Clicked" << item->text();
  }
  if (item->checkState() == Qt::Unchecked) {
    qDebug() << "Closed" << item->text();
  }
}
