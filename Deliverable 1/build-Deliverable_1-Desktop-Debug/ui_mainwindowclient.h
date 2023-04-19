/********************************************************************************
** Form generated from reading UI file 'mainwindowclient.ui'
**
** Created by: Qt User Interface Compiler version 5.9.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOWCLIENT_H
#define UI_MAINWINDOWCLIENT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableView>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindowClient
{
public:
    QAction *actionDo_Something;
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QPushButton *homePageSwitchButton;
    QPushButton *queryPageSwitchButton;
    QPushButton *viewAnimalPageSwitchButton;
    QPushButton *logoutButton;
    QStackedWidget *stackedWidget;
    QWidget *HomePage;
    QVBoxLayout *verticalLayout_5;
    QTabWidget *tabWidget;
    QWidget *tab;
    QVBoxLayout *verticalLayout_4;
    QTextEdit *textEdit_3;
    QWidget *tab_2;
    QWidget *QueryDatabasePage;
    QVBoxLayout *verticalLayout_2;
    QLabel *label;
    QTextEdit *textEdit;
    QPushButton *pushButton;
    QTextEdit *textEdit_2;
    QWidget *ViewAnimalPage;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout_3;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout_3;
    QTableView *tableView_viewAnimals;
    QHBoxLayout *horizontalLayout_4;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *viewSelectedAnimal;
    QSpacerItem *horizontalSpacer;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindowClient)
    {
        if (MainWindowClient->objectName().isEmpty())
            MainWindowClient->setObjectName(QStringLiteral("MainWindowClient"));
        MainWindowClient->resize(1172, 699);
        actionDo_Something = new QAction(MainWindowClient);
        actionDo_Something->setObjectName(QStringLiteral("actionDo_Something"));
        centralWidget = new QWidget(MainWindowClient);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        verticalLayout = new QVBoxLayout(centralWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        homePageSwitchButton = new QPushButton(centralWidget);
        homePageSwitchButton->setObjectName(QStringLiteral("homePageSwitchButton"));

        horizontalLayout->addWidget(homePageSwitchButton);

        queryPageSwitchButton = new QPushButton(centralWidget);
        queryPageSwitchButton->setObjectName(QStringLiteral("queryPageSwitchButton"));

        horizontalLayout->addWidget(queryPageSwitchButton);

        viewAnimalPageSwitchButton = new QPushButton(centralWidget);
        viewAnimalPageSwitchButton->setObjectName(QStringLiteral("viewAnimalPageSwitchButton"));

        horizontalLayout->addWidget(viewAnimalPageSwitchButton);

        logoutButton = new QPushButton(centralWidget);
        logoutButton->setObjectName(QStringLiteral("logoutButton"));

        horizontalLayout->addWidget(logoutButton);


        verticalLayout->addLayout(horizontalLayout);

        stackedWidget = new QStackedWidget(centralWidget);
        stackedWidget->setObjectName(QStringLiteral("stackedWidget"));
        stackedWidget->setMinimumSize(QSize(0, 50));
        HomePage = new QWidget();
        HomePage->setObjectName(QStringLiteral("HomePage"));
        verticalLayout_5 = new QVBoxLayout(HomePage);
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setContentsMargins(11, 11, 11, 11);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        tabWidget = new QTabWidget(HomePage);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setEnabled(true);
        tabWidget->setUsesScrollButtons(true);
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        verticalLayout_4 = new QVBoxLayout(tab);
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setContentsMargins(11, 11, 11, 11);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        textEdit_3 = new QTextEdit(tab);
        textEdit_3->setObjectName(QStringLiteral("textEdit_3"));

        verticalLayout_4->addWidget(textEdit_3);

        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        tabWidget->addTab(tab_2, QString());

        verticalLayout_5->addWidget(tabWidget);

        stackedWidget->addWidget(HomePage);
        QueryDatabasePage = new QWidget();
        QueryDatabasePage->setObjectName(QStringLiteral("QueryDatabasePage"));
        verticalLayout_2 = new QVBoxLayout(QueryDatabasePage);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        label = new QLabel(QueryDatabasePage);
        label->setObjectName(QStringLiteral("label"));

        verticalLayout_2->addWidget(label);

        textEdit = new QTextEdit(QueryDatabasePage);
        textEdit->setObjectName(QStringLiteral("textEdit"));
        textEdit->setMaximumSize(QSize(16777215, 50));

        verticalLayout_2->addWidget(textEdit);

        pushButton = new QPushButton(QueryDatabasePage);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        verticalLayout_2->addWidget(pushButton);

        textEdit_2 = new QTextEdit(QueryDatabasePage);
        textEdit_2->setObjectName(QStringLiteral("textEdit_2"));

        verticalLayout_2->addWidget(textEdit_2);

        stackedWidget->addWidget(QueryDatabasePage);
        ViewAnimalPage = new QWidget();
        ViewAnimalPage->setObjectName(QStringLiteral("ViewAnimalPage"));
        horizontalLayoutWidget = new QWidget(ViewAnimalPage);
        horizontalLayoutWidget->setObjectName(QStringLiteral("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(9, 576, 16, 16));
        horizontalLayout_3 = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        layoutWidget = new QWidget(ViewAnimalPage);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(9, 9, 1141, 571));
        verticalLayout_3 = new QVBoxLayout(layoutWidget);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        tableView_viewAnimals = new QTableView(layoutWidget);
        tableView_viewAnimals->setObjectName(QStringLiteral("tableView_viewAnimals"));

        verticalLayout_3->addWidget(tableView_viewAnimals);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalSpacer_2 = new QSpacerItem(37, 17, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_2);

        viewSelectedAnimal = new QPushButton(layoutWidget);
        viewSelectedAnimal->setObjectName(QStringLiteral("viewSelectedAnimal"));

        horizontalLayout_4->addWidget(viewSelectedAnimal);

        horizontalSpacer = new QSpacerItem(37, 17, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer);


        verticalLayout_3->addLayout(horizontalLayout_4);

        stackedWidget->addWidget(ViewAnimalPage);

        verticalLayout->addWidget(stackedWidget);

        MainWindowClient->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindowClient);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1172, 22));
        MainWindowClient->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindowClient);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindowClient->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindowClient);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindowClient->setStatusBar(statusBar);

        retranslateUi(MainWindowClient);

        stackedWidget->setCurrentIndex(1);
        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindowClient);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindowClient)
    {
        MainWindowClient->setWindowTitle(QApplication::translate("MainWindowClient", "MainWindow", Q_NULLPTR));
        actionDo_Something->setText(QApplication::translate("MainWindowClient", "Do Something", Q_NULLPTR));
        homePageSwitchButton->setText(QApplication::translate("MainWindowClient", "Home", Q_NULLPTR));
        queryPageSwitchButton->setText(QApplication::translate("MainWindowClient", "Query the Database", Q_NULLPTR));
        viewAnimalPageSwitchButton->setText(QApplication::translate("MainWindowClient", "View Animal", Q_NULLPTR));
        logoutButton->setText(QApplication::translate("MainWindowClient", "Logout", Q_NULLPTR));
        textEdit_3->setHtml(QApplication::translate("MainWindowClient", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Sans'; font-size:10pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Hello, welcome to our adoption centre. We here at cuACs Animal Adoption Centre are please to help you with all of your animal finding needs. </p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Here at cuACS, we believe that no request is too big or too small. We will do our very best to help you find the animal that best suits your"
                        " needs. We believe that we have the best system in town that will match you with the animal of your dreams. If you don't believe us, why don't you try coming in and checking our some of our animals and see what our magical matching algorithm of awesomeness has in store for you.</p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">We hope to see you soon!</p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">	~ The KAJG Team</p></body></html>", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("MainWindowClient", "Tab 1", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("MainWindowClient", "Tab 2", Q_NULLPTR));
        label->setText(QApplication::translate("MainWindowClient", "List of tables in database (3): animals, animals_phys_attr, animals_non_phys_attr", Q_NULLPTR));
        textEdit->setHtml(QApplication::translate("MainWindowClient", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Sans'; font-size:10pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">SELECT * FROM animals NATURAL JOIN (SELECT * FROM animals_phys_attr NATURAL JOIN animals_non_phys_attr)</p></body></html>", Q_NULLPTR));
        pushButton->setText(QApplication::translate("MainWindowClient", "Run Query", Q_NULLPTR));
        viewSelectedAnimal->setText(QApplication::translate("MainWindowClient", "View Selected Animal", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindowClient: public Ui_MainWindowClient {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOWCLIENT_H
