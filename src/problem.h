#ifndef PROBLEM_H
#define PROBLEM_H

#include "const.h"

class Problem
{
public:
    explicit Problem(const QString& na = "");
    ~Problem();

    void clear();
    void readConfig();
    bool saveConfig();
    void configure(const QString& typ, double timeLim, double memLim, const QString& check);
    void configureNew(const QString& typ, double timeLim, double memLim, const QString& check);

    QString name, dir, exe, checker, outFile, inFile;
    int sumScore, timeLim_checker;
    double codeLim;
    ProblemType type;

    class CompilerInfo
    {
    public:
        CompilerInfo(QString c = "", QString f = "", int t = 10) { cmd = c, file = f, timeLim = t; }

        QString cmd, file;
        int timeLim;
    };
    class Info
    {
    public:
        Info(double t = 0, double m = 0) { timeLim = t, memLim = m, in = out = sub = ""; }

        double timeLim, memLim;
        QString in, out, sub;
    };
    class Subtask
    {
    public:
        Subtask(int s = 0) { score = s; }
        ~Subtask() { point.clear(); }

        int score;
        std::vector<int> point;
    };
    std::vector<Subtask> tasks;
    std::vector<Info> que;
    std::vector<CompilerInfo> compilers;

    QList<QPair<QString, QString>> getInAndOutFile();
    CompilerInfo getCompiler(const QString& playerName);

private:
    QString addSuff(QString file);
    QString removeSuff(QString file);
};

#endif // PROBLEM_H
