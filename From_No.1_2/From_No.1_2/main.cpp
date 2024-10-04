#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string>
#include <fstream>
#include <sstream>

#include "LinkedList.h"
#include "main.h"

using namespace std;

int main(void)
{
    LinkedList List;

    // �ǂݍ��ރt�@�C���̖��O
	std::ifstream file("Scores.txt"); 
	if (!file.is_open()) {
        //�J���Ȃ������ꍇ
		printf("�t�@�C�����J���܂���ł���");
		return 0;
	}

    //�󂯎�����X�R�A�Ɩ��O�����Ă����ϐ�
    string Score, Name;

    while (file >> Score >> Name) {
        // ���O�ƃX�R�A��\��(�m�F�p)
        //printf("�X�R�A: %s ,���O: %s \n", Score, Name);
        //���X�g�̈�Ԗ����ɓ����
        LinkedList::Iterator it = List.GetEnd();
        List.Insert(it,std::stoi(Score), Name);
    }

    //���X�g�̒��g���ŏ����疖���܂ŕ\��
    //Display(List);
    LinkedList::Iterator it;
    it = List.GetBegin();
    for (it == List.GetBegin(); it != List.GetEnd(); it++)
    {
        printf("�X�R�A: %d ,���O: %s \n", (*it).Score, (*it).Name.c_str());
    }

    file.close();

	return 0;
}