#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string>
#include <fstream>
#include <sstream>

#include "LinkedList.h"

using namespace std;

int main(void)
{
    LinkedList List;

    // 読み込むファイルの名前
	std::ifstream file("Scores.txt"); 
	if (!file.is_open()) {
        //開かなかった場合
		printf("ファイルが開けませんでした");
		return 0;
	}

    //受け取ったスコアと名前を入れておく変数
    string Score, Name;

    while (file >> Score >> Name) {
        // 名前とスコアを表示(確認用)
        //printf("スコア: %s ,名前: %s \n", Score, Name);
        //リストの一番末尾に入れる
        List.InsertLast(Score, Name);
    }

    //リストの中身を最初から末尾まで表示
    List.display();

	return 0;
}