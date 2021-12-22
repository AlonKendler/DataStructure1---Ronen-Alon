#include "main.h"

int main()
{
    int N;
    cin >> N;
    masterHeap<int>* master=new masterHeap<int>();
    bool reset = false;
    int * pr=nullptr;
    for(int i=0;i<N;i++)
    {
        switch (getAction())
        {
        case Action::aMax:
            maxWarapper(reset, master);
            break;
        case Action::bDeleteMax:
            if(reset)
            {
                const int& val = master->deleteMax();
                cout << val << '\n';
                delete &val;
                cin.ignore(10000,'\n');
            }
            else
            {
                cout << "no\n";
                cin.ignore(10000,'\n');
            }
            break;
        case Action::cMin:
            if(reset)
            {
                const int& val = master->min();
                cout << val << '\n';
                cin.ignore(10000,'\n');
            }
            else
            {
                cout << "no\n";
                cin.ignore(10000,'\n');
            }
            break;
        case Action::dDeleteMin:
            if(reset)
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
            }
            break;
        case Action::eCreateEmpty:
            cin.ignore(10000,'\n');
            master->CreateEmpty();
            reset = true;
            break;
        case Action::fInsert:
            if(reset)
            {
                pr = new int();
                cin >> *pr;
                cin.ignore(10000,'\n');
                master->insert(*pr);
            }
            else
            {
                cout << "no\n";
                cin.ignore(10000,'\n');
            }
            break;
        case Action::gMedian:
            if(reset)
            {
                const int& val = master->median();
                cout << val << '\n';
                cin.ignore(10000,'\n');
            }
            else
            {
                cout << "no\n";
                cin.ignore(10000,'\n');
            }
            break;
        default:
            cout <<"bad\n";
            break;
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

bool maxWarapper(bool reset, masterHeap<int>* master)
{
    if(reset)
    {
        if(master->getItemCount()>0)
        {
            const int& val = master->max();
            cout << val << '\n';
            cin.ignore(10000,'\n');
            return true;
        }
    }

    return false;
}

bool deleteMaxWarapper(bool reset, masterHeap<int>* master)
{
    
}

bool minWarapper(bool reset, masterHeap<int>* master)
{

}

bool deleteMinWarapper(bool reset, masterHeap<int>* master)
{

}

bool insertWarapper(bool reset, masterHeap<int>* master)
{

}

bool medianWarapper(bool reset, masterHeap<int>* master)
{

}


