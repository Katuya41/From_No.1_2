#pragma once
#include <string>

  class LinkedList;

/**
 *�f�[�^������\���̂ł��B
 *
 * @param Score �X�R�A
 * @param Name  ���O
 */
struct DATA
{
    std::string Score;
    std::string Name;
};

//    /*
//     * ���X�g�̓��e��擪���珇�Ԃɏo�͂���֐��ł��B
//     */
//void Display(LinkedList _list) {
//    LinkedList::Iterator it;
//    it = _list.GetBegin();
//
//    while ((*it) != nullptr) {
//        printf("�X�R�A: %s ,���O: %s \n", (*it)->Data.Score.c_str(), (*it)->Data.Name.c_str());
//        it++;
//        //++it;
//    }
//}
