#pragma once

template<class T>
struct TNode {
	T val;
	TNode<T>* pNext;
};

template<class T>
class TListStack {
public:
	TListStack() {
		pFirst = nullptr;
	}
	~TListStack() {
		while (!is_empty()) {
			pop();
		}
	}
	void clear() {
		while (!is_empty()) {
			pop();
		}
	}
	bool is_empty()const {
		return pFirst == nullptr;
	}
	void push(T el) {
		TNode<T>* newElem = new TNode<T>; //ссылка чтобы не было проблем с областью видимости
		newElem->val = el;
		newElem->pNext = pFirst;
		pFirst = newElem;
	}
	T pop() {
		if (is_empty()) {
			throw - 1;
		}
		T el = pFirst->val;
		TNode<T>* p = pFirst;
		pFirst = pFirst->pNext;
		delete p;
		return el;
	}
	T top() {
		if (is_empty()) {
			throw - 1;
		}
		return pFirst->val;
	}
private:
	TNode<T>* pFirst;
};
