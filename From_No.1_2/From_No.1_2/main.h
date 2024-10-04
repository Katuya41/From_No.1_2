#pragma once
#include <string>

  class LinkedList;

/**
 *データを入れる構造体です。
 *
 * @param Score スコア
 * @param Name  名前
 */
struct DATA
{
    std::string Score;
    std::string Name;
};

//    /*
//     * リストの内容を先頭から順番に出力する関数です。
//     */
//void Display(LinkedList _list) {
//    LinkedList::Iterator it;
//    it = _list.GetBegin();
//
//    while ((*it) != nullptr) {
//        printf("スコア: %s ,名前: %s \n", (*it)->Data.Score.c_str(), (*it)->Data.Name.c_str());
//        it++;
//        //++it;
//    }
//}
