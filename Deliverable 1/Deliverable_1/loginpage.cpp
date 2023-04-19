#include "loginpage.h"
#include "ui_loginpage.h"

LoginPage* LoginPage::instance = 0;

// Singleton Design Pattern.
LoginPage* LoginPage::getInstance(QWidget *parent){
    if (instance == 0){ instance = new LoginPage(parent); }
    return instance;
}

//LoginPage* LoginPage::getInstance(){
//    if (instance == 0){ instance = new LoginPage(); }
//    return instance;
//}

//LoginPage::LoginPage() :
//    ui(new Ui::LoginPage)
//{
//    qDebug() << "LoginPage()";
//    ui->setupUi(this);
//    centerScreen();
//}

LoginPage::LoginPage(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::LoginPage)
{
    qDebug() << "LoginPage()";
    ui->setupUi(this);
    centerScreen();
    db.loadDatabase();
    loginInfo = db.getCompleteLoginListPtr();
}

LoginPage::~LoginPage()
{
    qDebug() << "~LoginPage()";
    delete ui;
    db.closeDatabase();
    QApplication::quit();
}

void LoginPage::centerScreen(){
    int screenWidth = QGuiApplication::primaryScreen()->geometry().width();
    int screenHeight = QGuiApplication::primaryScreen()->geometry().height();
    int width = this->geometry().width();
    int height = this->geometry().height();
    this->setGeometry((screenWidth/2) - (width/2), (screenHeight/2) - (height/2), width, height);
}

void LoginPage::on_pushButton_Login_clicked(){ authenticate(); }
void LoginPage::on_lineEdit_username_returnPressed(){ authenticate(); }
void LoginPage::on_lineEdit_password_returnPressed(){ authenticate(); }


void LoginPage::authenticate(){
    QString username = ui-> lineEdit_username -> text();
    QString password = ui-> lineEdit_password -> text();

//    qDebug() << *loginInfo;
//    qDebug() << (*loginInfo)[0].value(1);
    for (int i = 0; i < loginInfo->size(); i++){
        if (username == (*loginInfo)[i].value(1) && password == (*loginInfo)[i].value(2)){
            if ((*loginInfo)[i].value(0).toInt() == 0){
                launchMainWindow(1, -1);
                break;
            } else {
                launchMainWindow(2, (*loginInfo)[i].value(0).toInt());
                break;
            }
        } else if (i == loginInfo->size()-1){
            QMessageBox::warning(this, "Login", "Username and password is incorrect!");
        }
    }

//    if(username == "Staff" && password == "admin123"){
//        launchMainWindow(1); // 1 = launch as staff
//    } else if(username == "Client" && password == "client123"){
//        launchMainWindow(2); // 2 = launch as client
//    } else { QMessageBox::warning(this, "Login", "Username and password is incorrect!"); }
}

void LoginPage::launchMainWindow(int status, int id){
    hide();
    mainWindow = new MainWindow(this, &db, status, id);
    mainWindow->show();
}


void LoginPage::closeEvent(QCloseEvent *event){
    QApplication::quit();
    event->accept();
}


