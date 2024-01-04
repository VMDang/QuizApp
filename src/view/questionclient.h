#ifndef QUESTIONCLIENT_H
#define QUESTIONCLIENT_H

#include<QString>
#include<QStringList>
#include<QVector>

struct OptionClient {
    int optionId;
    QString text;

    OptionClient() : optionId(0), text("") {}
    OptionClient(int id, const QString& t) : optionId(id), text(t) {}
};

class QuestionClient
{
public:
    explicit QuestionClient(int id, const QString& questionText, const QVector<OptionClient>& options);
    QuestionClient();

    int questionId;
    QString questionText;
    QVector<OptionClient> options;
};

#endif // QUESTIONCLIENT_H




