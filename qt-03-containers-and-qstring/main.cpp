#include <QCoreApplication>
#include <QDebug>
#include <QStack>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QList<QString> names;
    QString output = "";

    names << "Mary" << "Ann" << "Charlynn" << "Marylynn" << "Margaret"
          << "Kate" << "Rose" << "Gwendolyn";

    // TODO: using Java-style iterators print the longest name from the list
    // use QString::arg to output message with this name

    QListIterator<QString> j_iter(names);

    while(j_iter.hasNext())
    {
        if(j_iter.next().length() > output.length())
        {
            output = j_iter.peekPrevious();
        }
    }

    qDebug() << "Java-style iterators: " << output;
    output.clear();

    // TODO: using STL-style iterators print the shortest name from the list
    // use QString::prepend and append to output message with this name

    for(QList<QString>::Iterator cpp_iter = names.begin(); cpp_iter != names.end(); ++cpp_iter)
    {
        if(cpp_iter->length() > output.length())
        {
            output = *cpp_iter;
        }
    }

    qDebug() << "Cpp-style iterators: " << output;
    output.clear();

    // TODO: using foreach and QStringList show all names with "lynn" suffix
    // and print it separated by ',' as one string

    QStringList str_list(names);

    for(const auto& i : str_list)
    {
        if(i.contains("lynn"))
        {
            if(!output.isEmpty())
            {
                output.append(',');
            }

            output.append(i);
        }
    }

    qDebug() << "All names with \"lynn\" suffix:" << output;

    // print all names in reverse order
    // TODO: 1. Using QStack
    QStack<QString> mystack;
    qDebug() << "All names in reverse order using QStack:";

    for(const auto& i : names)
    {
        mystack.push(i);
    }

    while(!mystack.empty())
    {
         qDebug() << mystack.pop();
    }

    // TODO: 2. Using other QList
    QList<QString> new_names(names);
    qDebug() << "All names in reverse order using other QList:";

    for(auto i = new_names.rbegin(); i != new_names.rend(); ++i)
    {
         qDebug() << *i;
    }

    // TODO: 3. Without other containers
    qDebug() << "All names in reverse order without other containers:";

    for(auto i = names.rbegin(); i != names.rend(); ++i)
    {
         qDebug() << *i;
    }

    return a.exec();
}
