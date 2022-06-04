// ListDouble.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <windows.h>

using namespace std;

//структура элемента(узла) списка
struct Element
{
	//данные
	double Data;
	//связь с другими узлами
	//указатель на следующий элемент списка
	Element* Next;
};
//Класс односвязный список
class List
{
	//Адрес первого элемента(головного узла), указатель на "голову" списка
	Element* Head;
	//Адрес последнего элемента(хвостового узла), указатель на "хвост" списка
	Element* Tail;
	//Текущее кол-во элементов(узлов) в списке
	int Count;
public:
	//прототипы методов
	//Конструктор по умолчанию
	List();
	//Деструктор
	~List();
	//Метод добавления узла в конец списка
	void PushBack(double);
	//Метод добавления узла в указанное списка
	//добавляет элемент в список после указанного узла, поумолчанию в начало списка
	void Push(double , Element* = nullptr);
	//Метод удаления головного узла
	void DelHead();

	void Del(int);
	//Метод очистки списка
	void DelAll();
	//реализовать метод удаления указанного узла
	//метод пока содержимого списка
	void Show()const;
	//метод получения кол-ва узлов в списке
	int GetCount()const;
	//метод получения адреса заданного элемента
	Element* GetElement(int)const;
};

int main()
{
	/*SetConsoleCP(1251);
	SetConsoleOutputCP(1251);*/
	List Spisok;
	double Value;//bufer dlya vvoda
	int Count = 0;
	do
	{
		cout << "Enter Value " << Count << endl;
		cout << "Enter 0 for EXIT" << endl;
		cin >> Value;
		if (Value != 0)
		{
			Spisok.PushBack(Value);
			Count++;
		}
		system("cls");

	} while (Value != 0);
	Spisok.Show();
	cout << "Enter the Value for search: ";
	cin >> Value;
	for (int i = 1; i < Spisok.GetCount(); i++)
	{
		//Spisok.GetElement(i)->Data == Value
		if (Spisok.GetElement(i)->Data == Value)
		{
			//Spisik.Del(i);		//
			cout << "Enter new Value: ";
			cin >> Value;
			Spisok.GetElement(i)->Data = Value;
			break;
		}
	}
	Spisok.Show();
	//Spisok.Push(5.45);
	//Spisok.Show();
	//Spisok.Push(9.44, Spisok.GetElement(2));
	//Spisok.Show();
	//Spisok.DelAll();
	//Spisok.Show();
}
//Конструктор по умолчанию
List::List()
{
	//при создании список пуст
	Head = Tail = nullptr; //голова и хвост никуда не указывают
	Count = 0;
}
//Деструктор
List::~List()
{
	//вызывает метод удаления всех узлов из списка DelAll()
	DelAll();
}
//Метод добавления узла в конец списка
void List::PushBack(double data)
{
	//создаем новый элемент(выделяем память)
	Element* temp = new Element;
	//заполняем узел данными
	temp->Data = data;
	//следующий элемент отсутствует, так как узел добавляется в конец списка
	temp->Next = nullptr;
	//если добавляемый элемент единственный в списке(то есть до него не было элементов)
	if (Head == nullptr) //if(Count==0) //if(Tail==nullptr)
	{
		Head = Tail = temp; //то на него будут указывать и голова и хвост списка
	}
	else //иначе, узел не единственный
	{
		Tail->Next = temp; //бвыший последним узел теперь указывает на новый элемент
		//как на слдующий за собой
		Tail = temp; //указатель на хвост списка теперь указывает на новый элемент
	}
	Count++; //увеличиваем кол-во элементов в списке
}
//Метод добавления узла в указанное списка
//добавляет элемент в список после указанного узла, по умолчанию в начало списка
void List::Push(double data, Element* Node)
{
	//создаем новый элемент(выделяем память)
	Element* temp = new Element;
	//заполняем узел данными
	temp->Data = data;
	//если добавляем узел в начало списка(головной элемент)
	if (Node == nullptr)
	{
		//если список был пуст, то добавляемый узел удиснтвенный,
		if (Head == nullptr) //if(Count==0) //if(Tail==nullptr)
		{
			temp->Next = nullptr; //после него нет узлов
			Head = Tail = temp; //он станет и головой и хвостом списка
		}
		else //если уже есть головной элемент, помещаем узел пред головным
		{
			temp->Next = Head; //новый узел указывает на бывший головным элемент, как на следующий за собой,
			Head = temp;	  //а сам становится головным
		}
	}
	else //добавление узла после указанного
	{
		temp->Next = Node->Next; //новый узел указывает туда, куда указывал узел, после которого добавляется новый узел
		Node->Next = temp; //узел, после которого добавляется новый, указывает на новый узел, как на следующий за собой
	}
	Count++; //увеличиваем кол-во элементов в списке
}
//Метод удаления головного узла
void List::DelHead()
{
	//если в списке есть элементы
	if (Head != nullptr) //if (Head)
	{
		//запоминаем адрес головного(удаляемого) узла
		Element* temp = Head;
		//Передаем голову следующему узлу
		Head = Head->Next;
		//Уменьшаем текущее кол-во узлов
		Count--;
		//освобождаем память, выделенную под удаляемый элемент
		delete temp;
	}
	else cout << "List is empty" << endl;
}

void List::Del(int index)
{

	if (index > 0 && index <= Count)
	{
		if (index == 1)
		{
			DelHead();
			return;
		}
		else
		{
			//esli ne golovu
		}
		{
			Element* Del = GetElement(index);
			//1 variant
			//GetElement(index - 1)->Next = Del->Next;
			//2 variant
			Element* Prev = GetElement(index - 1);
			Prev->Next = Del->Next;
			delete Del;

		}
	}

}
//Метод очистки списка
void List::DelAll()
{
	//пока в списке есть узлы(элементы)
	do
	{
		DelHead(); //удаляем по одному элементу из начала списка
	} while (Head != nullptr);
	Tail = nullptr; //когда все узлы будут удалены, Head станет nullptr,
	//а Tail нужно обнулить вручную
}
//реализовать метод удаления указанного узла
//метод пока содержимого списка
void List::Show()const
{
	//создаем указатель на элемент списка и помещаем в него адрес головного элемента
	Element* temp = Head;
	//пока не дошли до конца списка
	while (temp != nullptr)
	{
		//выводим данные узла на экран
		cout << temp->Data << endl;
		//переходим к следующему узлу
		temp = temp->Next;
	}
}
//метод получения кол-ва узлов в списке
int List::GetCount()const
{
	return Count; //возвращает текущее кол-во элементов
}
//метод получения адреса заданного элемента
Element* List::GetElement(int index)const
{
	//порядковый номер узла в списке
	if (index > 0 && index <= Count)
	{
		if (index == 1) return Head; //если указали первый узел, вернем адрес головы(который хранит указатель Head)
		else
			if (index == Count)return Tail;  //если указали первый узел, вернем адрес хвоста(который хранит указатель Tail)
			else
			{
				//создаем указатель на элемент списка и помещаем в него адрес головного элемента
				Element* temp = Head;
				for (int i = 1; i < index - 1; i++)//чтобы найти 3-й узел(адрес 3-го узла) нудно дойти до 2-го
				{
					temp = temp->Next; //переходим к следующему узлу			
				}
				return temp->Next; //возвращаем адрес из поля Next предыдущего узла от искомого
			}
	}
	else
	{
		cout << "there is no element with such a number!" << endl;
		return nullptr;
	}
}