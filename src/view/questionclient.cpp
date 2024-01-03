#include "questionclient.h"

#include <QString>
#include <QStringList>
#include <QVector>
#include <QPushButton>

QuestionClient::QuestionClient(int id, const QString& questionText, const QVector<OptionClient> &options) :
    questionId(id),
    questionText(questionText),
    options(options)
{

}

// constructor mặc định
QuestionClient::QuestionClient() :
    questionId(0),
    questionText(""),
    options(QVector<OptionClient>())
{

}

