#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <algorithm>// dung de bien doi du lieu!
using namespace std;


class MeCung {
    private:
    int n, m;
    vector<vector<int>> grid;
    pair<int,int> loiVo, loiRa;
    public:
    MeCung(int n, int m, vector<vector<int>> mat,
    pair<int,int> vao, pair<int,int> ra) {
        this->n = n;
        this->m = m;
        grid = mat;
        loiVo = vao;
        loiRa = ra;
    }
    bool laTuong(int x, int y) {
        if(x < 0 || y < 0 || x >= n || y >= m) return true;
        return grid[x][y] == 1;
    }
    bool laLoiRa(int x, int y) {
        return (x == loiRa.first && y == loiRa.second);
    }
    pair<int,int> getLoiVo() { return loiVo; }
    pair<int,int> getLoiRa() { return loiRa; }


    void hienThiMeCung(int x, int y, const vector<vector<bool>>& khamPha) {
        cout << "\n=== ME CUNG ===\n";
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < m; ++j) {
                if(i == x && j == y) {
                        cout << "R ";
                } else if(i == loiRa.first && j == loiRa.second) {
                        cout << "X ";
                } else if(i == loiVo.first && j == loiVo.second) {
                        cout << "S ";
                } else if(grid[i][j] == 1) {
                        cout << "# ";
                } else if(khamPha[i][j]) {
                        cout << ". ";
                } else {
                        cout << "  ";
                }
            }
            cout << endl;
        }
        cout << "- Giai thich:\n";
        cout << "R = Robot    X = Dich den   S = Cua vao\n";
        cout << "# = Tuong   . = Da di   [ ] = Chua di\n";
    }
};


class CamBienXe {
    private:
    MeCung *maze;
    public:
    CamBienXe(MeCung *m) { maze = m; }
    bool coTuong(int x, int y) {
        return maze->laTuong(x,y);
    }
};


class BanDo {
    private:
    vector<vector<bool>> khamPha;
    public:
    BanDo(int n, int m) {
        khamPha.assign(n, vector<bool>(m, false));
    }
    void capNhat(int x, int y) {
        khamPha[x][y] = true;
    }
    const vector<vector<bool>>& getBanDoKhamPha() const {
        return khamPha;
    }
};


class XeRobot {
    private:
    int x, y;
    MeCung *maze;
    CamBienXe *camBien;
    BanDo *banDo;
    public:
    XeRobot(MeCung *m, CamBienXe *cb, BanDo *bd) {
        maze = m;
        camBien = cb;
        banDo = bd;
        auto start = maze->getLoiVo();
        x = start.first;
        y = start.second;
        banDo->capNhat(x,y);
        cout << "Robot bat dau o: (" << x << "," << y << ")\n";
    }


void inTrangThai() {
    cout << "Vi tri hien tai: (" << x << "," << y << ")\n";
maze->hienThiMeCung(x, y, banDo->getBanDoKhamPha());
}


// BFS tm ng i
vector<pair<int,int>> timDuong() {
    auto start = maze->getLoiVo();
    auto goal  = maze->getLoiRa();
    int n = 7, m = 7; // v m cung 7x7
    vector<vector<bool>> visited(n, vector<bool>(m,false));
    map<pair<int,int>, pair<int,int>> parent;
    queue<pair<int,int>> q;


    q.push(start);
    visited[start.first][start.second] = true;


    int dx[4] = {-1,1,0,0};
    int dy[4] = {0,0,-1,1};


    while(!q.empty()) {
        auto cur = q.front(); q.pop();
        if(cur == goal) break;
        for(int k=0;k<4;k++) {
            int nx = cur.first + dx[k];
            int ny = cur.second + dy[k];
            if(!camBien->coTuong(nx,ny) && !visited[nx][ny]) {
                    visited[nx][ny] = true;
                        parent[{nx,ny}] = cur;
                            q.push({nx,ny});
            }
        }
    }


    // reconstruct path
    vector<pair<int,int>> path;
    if(!visited[goal.first][goal.second]) {
        cout << "Khong tim thay duong!\n";
        return path;
    }
    for(pair<int,int> at = goal; at != start; at = parent[at]) {
        path.push_back(at);
    }
    path.push_back(start);
    reverse(path.begin(), path.end());
    return path;
}


void tuLai() {
    auto path = timDuong();
    if(path.empty()) return;
    cout << "\n=== BAT DAU TU LAI ===\n";
    for(auto &p : path) {
        x = p.first; y = p.second;
        banDo->capNhat(x,y);
        inTrangThai();
        if(maze->laLoiRa(x,y)) {
            cout << ">>> Xe Robot da den dich thanh cong!\n";
        }
    }
}
};


int main() {
    vector<vector<int>> mat = {
        {1,1,1,1,1,1,1}, // 1 = tuong, 0 = duong
        {1,0,0,0,1,0,1},
        {1,0,1,0,0,0,1},
        {1,0,1,1,1,0,1},
        {1,0,1,0,0,0,1},
        {1,1,0,0,1,0,1},
        {1,1,1,1,1,1,1}
    };


    pair<int,int> vao = {1,1};
    pair<int,int> ra  = {5,5};


    MeCung maze(7,7,mat,vao,ra);
    CamBienXe cb(&maze);
    BanDo bd(7,7);
    XeRobot robot(&maze, &cb, &bd);


    robot.tuLai();


    return 0;
}