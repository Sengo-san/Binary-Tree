#pragma once
#include "BinTree.h"

class SBinTree : public BinTree
{
public:
	SBinTree() : BinTree() {};
	SBinTree(int n);	//n - ���������� ������, ����� ��������
	SBinTree(int* a, int n);	//a - ������ ������, n - ���������� ������

	SBinTree(const SBinTree&);
/*�� ����������������?*///	SBinTree& operator= (const SBinTree&);
	virtual ~SBinTree() {};	

	virtual void Add(int k, Node* p) override;
	//���������� ���� � ������ k � ������ � ������ p
	virtual void Del(Node* p) override; 		//�������� ���� p
	virtual void Delroot() override; 			//�������� �����

	virtual Node* FindKey(int k, Node* p) override;
	virtual Node* FindMax(Node* p) override;
	virtual Node* FindMin(Node* p) override;

};


