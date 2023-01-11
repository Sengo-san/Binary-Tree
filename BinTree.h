#pragma once

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <iostream>

#include <fstream>

#include <cstdlib>
#include <stdlib.h>
#include <stdio.h>

#include <queue>

class Node
{
	int key;//���� ����������
	Node* left, *right, *parent;

public:
	Node(int k =0, Node*L=NULL, Node *R=NULL, Node*P=NULL) //key, L, R, P
	{
		key = k;
		left = L;
		right = R;
		parent = P;
	}
	int getkey() { if (this != NULL) return key; else return (-1); }
	
	friend class BinTree;
	friend class SBinTree;
	friend class OSBinTree;

};

class BinTree
{
	//friend class SBinTree;
protected:
	Node* root;
	Node* tree (int n, Node* p);	//������ �������� ���������������� ������ � n ���������, p-������
	Node* TreeM (int n, Node* p, int* a, int &i); //������ �������� ���������������� ������ �� �������, p-������
	void copy (Node* q, Node* p, int f); //������� ����� ������ � ������ q, p-������ ������ ������		
										//(f==0 ���� ������������ ���������� ������ ����� �������� ��� p, f==1 - ������)
public:
	Node* GetRoot() { return root; }
	BinTree() { root = NULL; }
	BinTree (int n);// ���������� �� ���-�� ������ n, ����� ������������ �������� 
	BinTree(int* a, int n);//���������� �� ������� ������ a[], n - ���-�� ������
	BinTree (const BinTree&);
	
	BinTree& operator= (const BinTree&); 
	
	virtual ~BinTree();
	virtual void Add (int k, Node* p);//���������� ���� � ������ k  � ������ � ������ p (�� � p!)
	virtual void Del(Node* p); //������� ���� p
	virtual void Delroot();

	void TreeTraversall_LCR (Node *p); //����� ������ � ������ p � ������� ����-������-�����
	void TreeTraversall_LRC (Node* p);
	void TreeTraversall_RLC(Node* p);
	void WidthTraversall(Node* p); //����� ������ � ������ p � ������ (����������� �������, ���� � ���: push, pop, front, back, empty), ���� ������� �� �������

	virtual Node* FindKey(int k, Node* p);//����� ���� � ������ k ����� �������� p
	virtual Node* FindMax (Node* p);
	virtual Node* FindMin (Node* p);

	int FindHigh (Node* p);//����� ������ ������ � ������ p
	int Count(Node* p, int& i);//������� ����� ����� � ������ � ������ p

	void clear();//����������� ������, �����  �����

	void Print(Node* p, int k, int c);//k - ������ �� ����� ������� �������
};
