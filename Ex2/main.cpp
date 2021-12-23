#include "main.h"

int main()
{
    int N;
    masterHeap<pair>* master=new masterHeap<pair>();// the main data structure
    bool reset = false;// checks if the structure was reset before use
    bool error = false;// a central error flag to make error handling simple
    Action res;// the action inserted
    
    cin >> N;
    for(int i=0;i<N;i++)
    {
        res=getAction(error);// get input while checking the command is valid 
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
                if(!reset) // the structure should only be reset once according to requirments (input4e.txt is the example to this)
                {
                    cin.ignore(10000,'\n');// ignore any other string after an e command till line feed
                    master->CreateEmpty(N);
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

        if(error)// central error handling while clearing all memmory
        {
            cout << "wrong input\n";
            i=N;
        }

    }

    delete master;

    if(N<=0)// special case when N is negetive. (the flag isn't updated in this case)
    {
        cout << "wrong input\n";
    }

}


/**
 * @brief Get input and convert to an action
 * 
 * @param error - will be set to true if input isn't a valid command
 * @return Action - the action to preform
 */
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
            error=true;
            break;
        }
    }
    else
    {
        error=true;
        return Action::notValid;
    }
}

/**
 * @brief a simple error checking for structure's max function
 * 
 * @param reset - was the structure reset?
 * @param master - the structure
 * @return true - if an error happend
 * @return false - all good :)
 */
bool maxWarapper(bool reset, masterHeap<pair>* master)
{
    if(reset)
    {
        if(master->getItemCount()>0)
        {
            const pair* val = master->max();
            cout << val->getKey() << " " << val->getValue() << '\n';
            cin.ignore(10000,'\n');
            return false;
        }
    }

    return true;
}

/**
 * @brief same as maxWrapper except it uses deleteMax and frees the removed element
 * 
 * @param reset - was the structure reset?
 * @param master - the structure
 * @return true - if an error happend
 * @return false - all good :)
 */
bool deleteMaxWarapper(bool reset, masterHeap<pair>* master)
{
    if(reset)
    {
        if(master->getItemCount()>0)
        {
            const pair* val = master->deleteMax();
            cout << val->getKey() << " " << val->getValue() << '\n';
            delete val;
            cin.ignore(10000,'\n');
            return false;
        }
    }
    return true;
}

/**
 * @brief a simple error checking for structure's min function
 * 
 * @param reset - was the structure reset?
 * @param master - the structure
 * @return true - if an error happend
 * @return false - all good :)
 */
bool minWarapper(bool reset, masterHeap<pair>* master)
{
    if(reset)
    {
        if(master->getItemCount()>0)
        {
            const pair* val = master->min();
            cout << val->getKey() << " " << val->getValue() << '\n';
            cin.ignore(10000,'\n');
            return false;
        }
    }
    return true;
}

/**
 * @brief same as minWrapper except it uses deleteMin and frees the removed element
 * 
 * @param reset - was the structure reset?
 * @param master - the structure
 * @return true - if an error happend
 * @return false - all good :)
 */
bool deleteMinWarapper(bool reset, masterHeap<pair>* master)
{
    if(reset)
    {
        if(master->getItemCount()>0)
        {
            const pair* val = master->deleteMin();
            cout << val->getKey() << " " << val->getValue() << '\n';
            delete val;
            cin.ignore(10000,'\n');
            return false;
        }
    }
    return true;
}

/**
 * @brief this wrapper allocates the inputed pair of priority and string 
 * and inserts a pointer to it to the structure
 * 
 * @param reset - was the structure reset?
 * @param master - the structure
 * @return true - if an error happend
 * @return false - all good :)
 */
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

/**
 * @brief a simple error checking for structure's median function
 * 
 * @param reset - was the structure reset?
 * @param master - the structure
 * @return true - if an error happend
 * @return false - all good :)
 */
bool medianWarapper(bool reset, masterHeap<pair>* master)
{
    if(reset)
    {
        if(master->getItemCount()>0)
        {
            const pair* val = master->median();
            cout << val->getKey() << " " << val->getValue() << '\n';
            cin.ignore(10000,'\n');
            return false;
        }
    }

    return true;
}

