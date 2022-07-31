Link - https://binarysearch.com/problems/Unidirectional-Word-Search

bool solve(vector<vector<string>>& board, string word) {
    int n = board.size();
    int m = board[0].size();

    for (int i = 0; i < n; i++) {
        string a = "";
        for (int j = 0; j < m; j++) {
            a += board[i][j];
        }
        if (a.find(word) != std::string::npos) {
            return true;
        }
    }

    for (int i = 0; i < m; i++) {
        string a = "";
        for (int j = 0; j < n; j++) {
            a += board[j][i];
        }
        if (a.find(word) != std::string::npos) {
            return true;
        }
    }

return false;
}
