#include <bangtal>            // ��Ż ���̺귯���� ����ϱ� ���� ��� �����ϱ�
using namespace bangtal;      // bangtal ���� �����̽��� ����Ѵٰ� �����ϱ�

int main()
{	
	//��� �ΰ� ����
	auto room1 = Scene::create("��1", "Images/���-1.png");
	auto room2 = Scene::create("��2", "Images/���-2.png");
	
	
	//��� 1 �� ����(Ŭ���ϸ� ������ ��� 2�� �Ѿ)
	auto door1 = Object::create("Images/��-������-����.png", room1, 800, 270);
	auto closed1 = true;
	door1->setOnMouseCallback([&](auto object, auto x, auto y, auto action) -> bool {
		if (closed1) {
			object->setImage("Images/��-������-����.png");
			closed1 = false;
		}
		else {
			room2->enter();
		}
		return true;
		});

	//��� 2 ���� �� ����(�����ְ� Ŭ���ϸ� ��� 1�� �Ѿ)
	auto door2 = Object::create("Images/��-����-����.png", room2, 320, 270);
	door2->setOnMouseCallback([&](auto object, auto x, auto y, auto action) -> bool {
		room1->enter();
		return true;
		});

	//��� 2 ����ġ ����(������ ������ ���� ����)
	auto switch1 = Object::create("Images/����ġ.png", room2, 730, 450);
	switch1->setScale(1.5f);
	auto door3 = Object::create("Images/��-������-����.png", room2, 800, 270, false);
	switch1->setOnMouseCallback([&](auto object, auto x, auto y, auto action) -> bool {
		door3->show();
		return true;
		
		});

	//��� 2 ������ �� ����(������ ������ �� �� �� ������ ���� ����)
	auto closed3 = true;
	door3->setOnMouseCallback([&](auto object, auto x, auto y, auto action) -> bool {
		if (closed3) {
			object->setImage("Images/��-������-����.png");
			closed3 = false;
		}
		else {
			endGame();
		}
		return true;
		});

	startGame(room1);
}