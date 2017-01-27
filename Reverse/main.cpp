#include <vector>
#include <iostream>
#include <queue>
#include <set>
using namespace std;



struct cell
{
    char colour;
    int weight;
};

cell mainfield[8][8];

char bot, human;
//цвета игроков

int maxdepth = 4, infinity = INT_MAX;

void init()
{
    for (int i = 0; i < 8; i++)
        for (int j = 0; j < 8; j++)
        {
            mainfield[i][j].colour = '_';
            mainfield[i][j].weight = 0;
        }
    
    mainfield[3][3].colour = mainfield[4][4].colour = '0';
    mainfield[3][4].colour = mainfield[4][3].colour = '1';
    
    mainfield[3][3].weight = mainfield[4][4].weight = 1;
    mainfield[3][4].weight = mainfield[4][3].weight = 1;
    
}

void print(cell field[8][8])
{
    cout << "  ";
    for (int i = 0; i < 8; i++)
        cout << i << ' ';
    cout << endl;
    
    for (int i = 0; i < 8; i++)
    {
        cout << i << ' ';
        for (int j = 0; j < 8; j++)
            if (field[i][j].colour == '_')
                cout << ' ' << ' ';
            else  cout << field[i][j].colour << ' ';
        cout << "  ";
        cout << "\n";
    }
    
}

bool Swap(char c, int i, int j, queue < pair <int, int> > &q, cell field[8][8])

// функция, где с - цвет фишки, которую мы ставим в клетку (i,j);
//в очередь кидаем фишки, которые перевернутся после хода!!!
//если фишки перевернутся, то true, иначе false

{
    char d;
    if (c == '1') d = '0';
    else d = '1';
    
    if (j < 7)
        if (field[i][j + 1].colour == d)
        {
            int k = j + 1;
            while (k < 8)
                if (field[i][k].colour != d)
                {
                    if (field[i][k].colour == c)
                    {
                        for (int m = j + 1; m <= k; m++)
                        {
                            pair <int, int> p;
                            p.first = i;
                            p.second = m;
                            q.push(p);
                        }
                    }
                    break;
                }
                else k++;
        }
    if (j > 0)
        if (field[i][j - 1].colour == d)
        {
            int k = j - 1;
            while (k >= 0)
                if (field[i][k].colour != d)
                {
                    if (field[i][k].colour == c)
                    {
                        for (int m = j - 1; m >= k; m--)
                        {
                            pair <int, int> p;
                            p.first = i;
                            p.second = m;
                            q.push(p);
                        }
                    }
                    break;
                }
                else k--;
        }
    if ((i < 7) && (j < 7))
        if (field[i + 1][j + 1].colour == d)
        {
            int k = i + 1, m = j + 1;
            while ((k < 8) && (m < 8))
                if (field[k][m].colour != d)
                {
                    if (field[k][m].colour == c)
                    {
                        int n = j + 1;
                        for (int l = i + 1; l <= k; l++)
                        {
                            pair <int, int> p;
                            p.first = l;
                            p.second = n;
                            q.push(p);
                            n++;
                        }
                    }
                    break;
                }
                else
                {
                    k++;
                    m++;
                }
        }
    if ((i > 0) && (j > 0))
        if (field[i - 1][j - 1].colour == d)
        {
            int k = i - 1, m = j - 1;
            while ((k >= 0) && (m >= 0))
                if (field[k][m].colour != d)
                {
                    if (field[k][m].colour == c)
                    {
                        int n = j - 1;
                        for (int l = i - 1; l >= k; l--)
                        {
                            pair <int, int> p;
                            p.first = l;
                            p.second = n;
                            q.push(p);
                            n--;
                        }
                    }
                    break;
                }
                else
                {
                    k--;
                    m--;
                }
        }
    if ((i > 0) && (j < 7))
        if (field[i - 1][j + 1].colour == d)
        {
            int k = i - 1, m = j + 1;
            while ((k >= 0) && (m < 8))
                if (field[k][m].colour != d)
                {
                    if (field[k][m].colour == c)
                    {
                        int n = j + 1;
                        for (int l = i - 1; l >= k; l--)
                        {
                            pair <int, int> p;
                            p.first = l;
                            p.second = n;
                            q.push(p);
                            n++;
                        }
                    }
                    break;
                }
                else
                {
                    k--;
                    m++;
                }
        }
    if ((i < 7) && (j > 0))
        if (field[i + 1][j - 1].colour == d)
        {
            int k = i + 1, m = j - 1;
            while ((m >= 0) && (k < 8))
                if (field[k][m].colour != d)
                {
                    if (field[k][m].colour == c)
                    {
                        int n = j - 1;
                        for (int l = i + 1; l <= k; l++)
                        {
                            pair <int, int> p;
                            p.first = l;
                            p.second = n;
                            q.push(p);
                            n--;
                        }
                    }
                    break;
                }
                else
                {
                    k++;
                    m--;
                }
        }
    if (i > 0)
        if (field[i - 1][j].colour == d)
        {
            int k = i - 1;
            while (k >= 0)
                if (field[k][j].colour != d)
                {
                    if (field[k][j].colour == c)
                    {
                        for (int m = i - 1; m >= k; m--)
                        {
                            pair <int, int> p;
                            p.first = m;
                            p.second = j;
                            q.push(p);
                        }
                    }
                    break;
                }
                else k--;
        }
    if (i < 7)
        if (field[i + 1][j].colour == d)
        {
            int k = i + 1;
            while (k < 8)
                if (field[k][j].colour != d)
                {
                    if (field[k][j].colour == c)
                        for (int m = i + 1; m <= k; m++)
                        {
                            pair <int, int> p;
                            p.first = m;
                            p.second = j;
                            q.push(p);
                        }
                    break;
                }
                else k++;
        }
    
    return (!q.empty());
}

void showWhereICanGo(char c, queue < pair <int, int> > & q, cell field[8][8])
//кидает в очередь клетки, куда можно сходить фишкой с цветом c
{
    char d;
    if (c == '0') d = '1';
    else d = '0';
    
    for (int i = 0; i < 8; i++)
        for (int j = 0; j < 8; j++)
            if (field[i][j].colour == '_' || field[i][j].colour == '+')
            {
                queue < pair <int, int> > q2;
                if (Swap(c, i, j, q2, field))
                {
                    pair <int, int> p;
                    p.first = i;
                    p.second = j;
                    q.push(p);
                }
            }
    
}

bool IsStable(int i, int j, cell field[8][8])
{
    if (field[i][j].weight == 2)
        return true;
    if (field[i][j].colour == '_')
        return false;
    
    if ((i == 0 || i == 7) && (j == 0 || j == 7))
        return true;
    
    if ((j != 0) && (j != 7))
        if (!(((field[i][j - 1].weight == 2) && (field[i][j - 1].colour == field[i][j].colour)) || ((field[i][j + 1].weight == 2) && (field[i][j + 1].colour == field[i][j].colour))))
            return false;
    
    if ((i != 0) && (i != 7))
        if (!(((field[i - 1][j].weight == 2) && (field[i - 1][j].colour == field[i][j].colour)) || ((field[i + 1][j].weight == 2) && (field[i + 1][j].colour == field[i][j].colour))))
            return false;
    
    if ((j != 0) && (j != 7) && (i != 0) && (i != 7))
        if (!(((field[i + 1][j - 1].weight == 2) && (field[i + 1][j - 1].colour == field[i][j].colour)) || ((field[i - 1][j + 1].weight == 2) && (field[i - 1][j + 1].colour == field[i][j].colour))))
            return false;
    
    if ((j != 0) && (j != 7) && (i != 0) && (i != 7))
        if (!(((field[i - 1][j - 1].weight == 2) && (field[i - 1][j - 1].colour == field[i][j].colour)) || ((field[i + 1][j + 1].weight == 2) && (field[i + 1][j + 1].colour == field[i][j].colour))))
            return false;
    
    return true;
}


void StepAnalisator(char c, int i, int j, cell field[8][8])
// меняет массив, переворачивает фишки и т.д. после сделанного в (i,j) хода

{
    
    queue < pair <int, int> > q, q2;
    pair <int, int> p;
    p.first = i;
    p.second = j;
    
    Swap(c, i, j, q, field);
    
    q.push(p);
    while (!q.empty())
    {
        pair <int, int> p = q.front();
        q.pop();
        field[p.first][p.second].colour = c;
        q2.push(p);
    }
    
    //q2,q3 нужны для проверки стабильности новых фишек;
    
    bool fl = true;
    while (fl)
    {
        queue < pair <int, int> > q3;
        fl = false;
        while (!q2.empty()) {
            pair <int, int> p;
            p = q2.front();
            q2.pop();
            if (IsStable(p.first, p.second, field))
            {
                fl = true;
                field[p.first][p.second].weight = 2;
            }
            else
            {
                q3.push(p);
                field[p.first][p.second].weight = 1;
            }
        }
        q2 = q3;
    }
}

bool HumanStep(char c)
//процедура считывания хода для человека
{
    queue < pair <int, int> > q;
    showWhereICanGo(c, q, mainfield);
    if (q.empty())
        return false;
    
    while (!q.empty())
    {
        pair <int, int> p = q.front();
        q.pop();
        mainfield[p.first][p.second].colour = '+';
    }
    print(mainfield);
    
    cout << "Введите координаты новой фишки:" << "\n";
    int i, j;
    cin >> i >> j;
    while (mainfield[i][j].colour != '+') {
        cout << "Так нельзя! Ходите в другую клетку." << "\n";
        cin >> i >> j;
    }
    
    for (int i = 0; i < 8; i++)
        for (int j = 0; j < 8; j++)
            if (mainfield[i][j].colour == '+')
                mainfield[i][j].colour = '_';
    StepAnalisator(c, i, j, mainfield);
    cout << "Вы сделали ход и поле игры теперь выглядит так:" << endl;
    print(mainfield);
    return true;
}

double  numberOfStableCoins(cell grid[8][8], char yours)
{
    int res = 0;
    for (int i = 0; i < 8; i++)
        for (int j = 0; j < 8; j++)
        {
            if (grid[i][j].weight == 2 && grid[i][j].colour == yours) //isStable must make weight of stable coins = 2
                ++res;
        }
    return res;
}

double numberOfCoins(cell grid[8][8], char yours)
{
    int res = 0;
    for (int i = 0; i < 8; i++)
        for (int j = 0; j < 8; j++)
        {
            if ((grid[i][j].weight != 0) && grid[i][j].colour == yours) //isStable must make weight of existed coins = 1
                ++res;
        }
    return res;
}

double Heuristic(cell grid[8][8])
{
    //print(grid);
    double my_tiles = 0;
    double opp_tiles = 0;
    double mob = 0;
    double stab = 0;
    double par = 0;
    double cor = 0;
    double cls = 0;
    
    //parity of coins
    my_tiles = numberOfCoins(grid, bot);
    opp_tiles = numberOfCoins(grid, human);
    if (my_tiles > opp_tiles)
        par = 100 * (my_tiles - opp_tiles) / (my_tiles + opp_tiles);
    else
        par = -100 * (opp_tiles - my_tiles) / (my_tiles + opp_tiles);
    
    //corner occupancy
    my_tiles = opp_tiles = 0;
    if (grid[0][0].colour == bot) my_tiles++;
    else if (grid[0][0].colour == human) opp_tiles++;
    if (grid[0][7].colour == bot) my_tiles++;
    else if (grid[0][7].colour == human) opp_tiles++;
    if (grid[7][0].colour == bot) my_tiles++;
    else if (grid[7][0].colour == human) opp_tiles++;
    if (grid[7][7].colour == bot) my_tiles++;
    else if (grid[7][7].colour == human) opp_tiles++;
    cor = 25 * (my_tiles - opp_tiles);
    
    //corner closeness
    my_tiles = opp_tiles = 0;
    if (grid[0][0].colour == '_')   {
        if (grid[0][1].colour == bot) my_tiles++;
        else if (grid[0][1].colour == human) opp_tiles++;
        if (grid[1][1].colour == bot) my_tiles++;
        else if (grid[1][1].colour == human) opp_tiles++;
        if (grid[1][0].colour == bot) my_tiles++;
        else if (grid[1][0].colour == human) opp_tiles++;
    }
    if (grid[0][7].colour == '_')   {
        if (grid[0][6].colour == bot) my_tiles++;
        else if (grid[0][6].colour == human) opp_tiles++;
        if (grid[1][6].colour == bot) my_tiles++;
        else if (grid[1][6].colour == human) opp_tiles++;
        if (grid[1][7].colour == bot) my_tiles++;
        else if (grid[1][7].colour == human) opp_tiles++;
    }
    if (grid[7][0].colour == '_')   {
        if (grid[7][1].colour == bot) my_tiles++;
        else if (grid[7][1].colour == human) opp_tiles++;
        if (grid[6][1].colour == bot) my_tiles++;
        else if (grid[6][1].colour == human) opp_tiles++;
        if (grid[6][0].colour == bot) my_tiles++;
        else if (grid[6][0].colour == human) opp_tiles++;
    }
    if (grid[7][7].colour == '_')   {
        if (grid[6][7].colour == bot) my_tiles++;
        else if (grid[6][7].colour == human) opp_tiles++;
        if (grid[6][6].colour == bot) my_tiles++;
        else if (grid[6][6].colour == human) opp_tiles++;
        if (grid[7][6].colour == bot) my_tiles++;
        else if (grid[7][6].colour == human) opp_tiles++;
    }
    cls = -12 * (my_tiles - opp_tiles);
    
    //mobility
    queue <pair <int, int> > q;
    showWhereICanGo(bot, q, grid);
    my_tiles = q.size();
    queue<pair < int, int > > q1;
    showWhereICanGo(human, q1, grid);
    opp_tiles = q1.size();
    if (my_tiles > opp_tiles)
        mob = (100.0 * my_tiles) / (my_tiles + opp_tiles);
    else if (my_tiles < opp_tiles)
        mob = -(100.0 * opp_tiles) / (my_tiles + opp_tiles);
    else mob = 0;
    
    //stability
    my_tiles = numberOfStableCoins(grid, bot);
    opp_tiles = numberOfStableCoins(grid, human);
    if (my_tiles > opp_tiles)
        stab = (100.0 * my_tiles) / (my_tiles + opp_tiles);
    else if (my_tiles < opp_tiles)
        stab = -(100.0 * opp_tiles) / (my_tiles + opp_tiles);
    else stab = 0;
    
    //final weighted score
    double result = 0;
    result = (801.724 * cor) + (382.026 * cls) + (100 * stab) + (78.922 * mob) + (10 * par);
    
    //cout << "Значение функции для поля:" << endl;
    //print(grid);
    //cout << result << endl;
    return result;
}

double AlphaBeta(cell field[8][8], int depth, double alpha, double beta, char c)
//возвращает значение функции в узле, принимает массив и глубину, а так же альфа/бета и цвет игрока
{
    if (depth >= maxdepth)
        return Heuristic(field);
    
    char d;
    if (c == bot) d = human;
    else d = bot;
    
    queue < pair <int, int> > q;
    
    showWhereICanGo(c, q, field);
    
    if (q.empty())
    {
        showWhereICanGo(d, q, field);
        if (q.empty())   // = терминальное состояние, т.е. кто-то выиграл
            return Heuristic(field);
        else             // ПРОПУСК ХОДА !
            return AlphaBeta(field, depth, alpha, beta, d);
    }
    
    //уровень минимума (человек уменьшает вероятность победы бота)
    if (c == human)
    {
        double v = infinity;
        while (!q.empty())
        {
            pair <int, int> p = q.front();
            q.pop();
            cell field2[8][8];
            for (int i = 0; i < 8; i++)
                for (int j = 0; j < 8; j++)
                    field2[i][j] = field[i][j];
            
            StepAnalisator(human, p.first, p.second, field2);
            //print(field2);
            double v1 = AlphaBeta(field2, depth+1, alpha, beta, d);
            if (v1 < v)
                v = v1;
            if (v1 < beta)
                beta = v1;
            if (alpha >= beta)
                break;
        }
        return v;
    }
    else
        //уровень максимума - бот увеличивает вероятность победы
    {
        double v = -infinity;
        while (!q.empty())
        {
            pair <int, int> p = q.front();
            q.pop();
            cell field2[8][8];
            for (int i = 0; i < 8; i++)
                for (int j = 0; j < 8; j++)
                    field2[i][j] = field[i][j];
            
            StepAnalisator(bot, p.first, p.second, field2);
            //print(field2);
            
            double v1 = AlphaBeta(field2, depth+1, alpha, beta, d);
            if (v1 > v)
                v = v1;
            if (v1 > alpha)
                alpha = v1;
            if (alpha >= beta)
                break;
        }
        return v;
    }
}

bool StepGenerator()
//генерит координаты для бота (через минимакс) и делает туда ход
{
    queue <pair <int, int> > q;
    showWhereICanGo(bot, q, mainfield);
    if (q.empty())
        return false;
    
    double v = -infinity;
    pair <int, int> ans;
    
    while (!q.empty())
    {
        pair <int, int> p = q.front();
        q.pop();
        cell field[8][8];
        for (int i = 0; i < 8; i++)
            for (int j = 0; j < 8; j++)
                field[i][j] = mainfield[i][j];
        
        StepAnalisator(bot, p.first, p.second, field);
        
        double vi = AlphaBeta(field, 0, v, infinity, human);
        if (vi > v)
        {
            v = vi;
            ans = p;
        }
        
    }
    StepAnalisator(bot, ans.first, ans.second, mainfield);
    cout << "SMART BOT made a step at (" << ans.first << ',' << ans.second << ')' << endl;
    //print(mainfield);
    return true;
}

bool StupidStepGenerator()
//глупый бот, играющий рандомом
{
    queue <pair <int, int> > q;
    showWhereICanGo(bot, q, mainfield);
    if (q.empty())
        return false;
    
    unsigned long n = q.size();
    n = rand() % n + 1;
    for (int i = 1; i < n; i++)
        q.pop();
    pair <int, int> ans = q.front();
    
    StepAnalisator(bot, ans.first, ans.second, mainfield);
    cout << "STUPID BOT made a random step at (" << ans.first << ',' << ans.second << ')' << endl;
    print(mainfield);
    return true;
}

bool withbot, smartbot;

bool Step(char c)
{
    if (withbot)
    {
        if (c == bot)
        {
            if (smartbot)
            {
                return StepGenerator();
            }
            else
            {
                return StupidStepGenerator();
            }
        }
        else
        {
            return HumanStep(human);
        }
    }
    else
    {
        return HumanStep(c);
    }
}


void Game()
{
    setlocale(LC_ALL, "Russian");
    cout << "Добро пожаловать! Начинают единички. Вот как вы можете сходить:" << endl;
    char c = '1';
    bool fl = false;
    
    while (true) {
        if (Step(c))
            fl = false;
        else
            if (fl) {
                cout << endl << "Конец игры." << endl << endl;
                int numbot = numberOfCoins(mainfield, bot), numhuman = numberOfCoins(mainfield, human);
                
                if (numbot == numhuman) cout << "Ничья!" << endl;
                if (numbot > numhuman) cout << "Вы проиграли" << endl;
                if (numbot < numhuman) cout << "Вы победили" << endl;
                cout << endl;
                break;
            }
            else
            {
                fl = true;
                cout << "Передача хода противнику" << endl;
            }
        if (c == bot) c = human;
        else c = bot;
    }
    
}

int main()
{
    setlocale(LC_ALL, "Russian");
    init();
    cout << "Если вы хотите играть с ботом - введите 1" << endl;
    char c;
    cin >> c;
    if (c == '1')
        withbot = true;
    else withbot = false;
    
    if (withbot)
    {
        cout << "Если вы хотите играть черными(единички) - введите 1, иначе введите любой другой символ" << endl;
        cin >> c;
        if (c == '1')
        {
            bot = '0';
            human = '1';
        }
        else
        {
            bot = '1';
            human = '0';
        }
        cout << "Если вы хотите умного бота - введите 1, иначе введите любой другой символ" << endl;
        cin >> c;
        if (c == '1')
            smartbot = true;
        else smartbot = false;
    }
    Game();
    return 0;
}
