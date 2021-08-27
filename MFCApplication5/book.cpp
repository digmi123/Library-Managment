#include "pch.h"
#include "book.h"



CString book::getName() {
	return name;
}

book::book(CString barcode) {
	this->barcode = barcode;
}

CString book::GetBarcode() {
	return barcode;
}

void book::setName(CString newName) {
	this->name = newName;
}

void book::setAuthor(CString author) {
	this->author = author;
}

void book::setPages(int num) {
	this->pages = num;
}

void book::setQuantity(int num) {
	this->quantity = num;
}

CString book::getAuthor() {
	return this->author;
}

int book::getPages() {
	return this->pages;
}

int book::getQuantity() {
	return this->quantity;
}
void book::setageRestrict(int age)
{
	
}
int book::getageRestrict()
{
	return 0;
}