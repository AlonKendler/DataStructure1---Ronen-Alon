#include "main.h"

int main()
{
    int N;
    masterHeap<pair>* master=new masterHeap<pair>();
    bool reset = false;
    bool error = false;
    Action res;
    
    cin >> N;
    for(int i=0;i<N;i++)
    {
        res=getAction(error); 
        if(!error)
        {
            switch (res)
            {
            case Action::aMax:
                error = maxWarapper(reset, master);
                break;
            case Action::bDeleteMax:
                error = deleteMaxWarapper(reset, master);
                break;
            case Action::cMin:
                error = minWarapper(reset, master);
                break;
            case Action::dDeleteMin:
                error = deleteMinWarapper(reset, master);
                break;
            case Action::eCreateEmpty:
                if(!reset)
                {
                    cin.ignore(10000,'\n');
                    master->CreateEmpty();
                    reset = true;
                }
                else
                {
                    error=true;
                }
                break;
            case Action::fInsert:
                error = insertWarapper(reset, master);
                break;
            case Action::gMedian:
                error = medianWarapper(reset, master);
                break;
            default:
                error = true;
                break;
            }
        }

        if(error)
        {
            cout << "wrong input\n";
            i=N;
        }

    }

    delete master;

    if(N<=0)
    {
        cout << "wrong input\n";
    }

}

Action getAction(bool& error)
{
    char a;
    if(cin >> a)
    {
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
    else
    {
        error=true;
        return Action::notValid;
    }
}

bool maxWarapper(bool reset, masterHeap<pair>* master)
{
    if(reset)
    {
        if(master->getItemCount()>0)
        {
            const pair& val = master->max();
            cout << val.getKey() << " " << val.getValue() << '\n';
            cin.ignore(10000,'\n');
            return false;
        }
    }

    return true;
}

bool deleteMaxWarapper(bool reset, masterHeap<pair>* master)
{
    if(reset)
    {
        if(master->getItemCount()>0)
        {
            const pair& val = master->deleteMax();
            cout << val.getKey() << " " << val.getValue() << '\n';
            delete &val;
            cin.ignore(10000,'\n');
            return false;
        }
    }
    return true;
}

bool minWarapper(bool reset, masterHeap<pair>* master)
{
    if(reset)
    {
        if(master->getItemCount()>0)
        {
            const pair& val = master->min();
            cout << val.getKey() << " " << val.getValue() << '\n';
            cin.ignore(10000,'\n');
            return false;
        }
    }
    return true;
}

bool deleteMinWarapper(bool reset, masterHeap<pair>* master)
{
    if(reset)
    {
        if(master->getItemCount()>0)
        {
            const pair& val = master->deleteMin();
            cout << val.getKey() << " " << val.getValue() << '\n';
            delete &val;
            cin.ignore(10000,'\n');
            return false;
        }
    }
    return true;
}

bool insertWarapper(bool reset, masterHeap<pair>* master)
{
    pair *add = nullptr;

    char str[1024];
    int priority=0;

    if(reset)
    {
        if(cin >> priority)
        {
            if(cin.get())
            {
                cin.getline(str,1024);

                add = new pair(priority,string(str));

                master->insert(*add);
                return false;

            }
        }
    }

    return true;
}

bool medianWarapper(bool reset, masterHeap<pair>* master)
{
    if(reset)
    {
        if(master->getItemCount()>0)
        {
            const pair& val = master->median();
            cout << val.getKey() << " " << val.getValue() << '\n';
            cin.ignore(10000,'\n');
            return false;
        }
    }

    return true;
}


