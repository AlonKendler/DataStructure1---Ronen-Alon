#include "main.h"

int main()
{
    int N;
    cin >> N;
    masterHeap<pair>* master=new masterHeap<pair>();
    bool reset = false;
    bool error = false;
    for(int i=0;i<N;i++)
    {
        switch (getAction())
        {
        case Action::aMax:
            error = maxWarapper(reset, master);
            break;
        case Action::bDeleteMax:
            
            break;
        case Action::cMin:
            /* if(reset)
            {
                const int& val = master->min();
                cout << val << '\n';
                cin.ignore(10000,'\n');
            }
            else
            {
                cout << "no\n";
                cin.ignore(10000,'\n');
            } */
            break;
        case Action::dDeleteMin:
            /* if(reset)
            {
                const int& val = master->deleteMin();
                cout << val << '\n';
                delete &val;
                cin.ignore(10000,'\n');
            }
            else
            {
                cout << "no\n";
                cin.ignore(10000,'\n');
            } */
            break;
        case Action::eCreateEmpty:
            cin.ignore(10000,'\n');
            master->CreateEmpty();
            reset = true;
            break;
        case Action::fInsert:
            error = insertWarapper(reset, master);
            break;
        case Action::gMedian:
            /* if(reset)
            {
                const int& val = master->median();
                cout << val << '\n';
                cin.ignore(10000,'\n');
            }
            else
            {
                cout << "no\n";
                cin.ignore(10000,'\n');
            } */
            break;
        default:
            cout <<"bad\n";
            break;
        }

        if(error)
        {
            cout << "wrong input";
            i=N;
        }

    }

}

Action getAction()
{
    char a;
    cin >> a;
    switch (a)
    {
    case 'a':
        return Action::aMax;
        break;
    case 'b':
        return Action::bDeleteMax;
        break;
    case 'c':
        return Action::cMin;
        break;
    case 'd':
        return Action::dDeleteMin;
        break;
    case 'e':
        return Action::eCreateEmpty;
        break;
    case 'f':
        return Action::fInsert;
        break;
    case 'g':
        return Action::gMedian;
        break;
    default:
        return Action::notValid;
        break;
    }
}

bool maxWarapper(bool reset, masterHeap<pair>* master)
{
    if(reset)
    {
        if(master->getItemCount()>0)
        {
            const pair& val = master->max();
            cout << val.getKey() << val.getValue() << '\n';
            cin.ignore(10000,'\n');
            return false;
        }
    }

    return true;
}

bool deleteMaxWarapper(bool reset, masterHeap<pair>* master)
{
    /* if(reset)
    {
        const pair& val = master->deleteMax();
        cout << val << '\n';
        delete &val;
        cin.ignore(10000,'\n');
    } */
    return false;
}

bool minWarapper(bool reset, masterHeap<pair>* master)
{
    return false;
}

bool deleteMinWarapper(bool reset, masterHeap<pair>* master)
{
    return false;
}

bool insertWarapper(bool reset, masterHeap<pair>* master)
{
    pair *add = nullptr;

    string s;
    int priority=0;

    if(reset)
    {
        if(cin >> priority)
        {
            if(cin.get())
            {
                cin >> s;
                cin.ignore(10000,'\n');

                add = new pair(priority,s);

                master->insert(*add);
                return false;

            }
        }
    }

    return true;
}

bool medianWarapper(bool reset, masterHeap<pair>* master)
{
    return false;
}


