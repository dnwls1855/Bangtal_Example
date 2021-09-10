#include <bangtal>            // 방탈 라이브러리를 사용하기 위한 헤더 포함하기
using namespace bangtal;      // bangtal 네임 스페이스를 사용한다고 선언하기

int main()
{	
	//장면 두개 생성
	auto room1 = Scene::create("룸1", "Images/배경-1.png");
	auto room2 = Scene::create("룸2", "Images/배경-2.png");
	
	
	//장면 1 문 설정(클릭하면 열리고 장면 2로 넘어감)
	auto door1 = Object::create("Images/문-오른쪽-닫힘.png", room1, 800, 270);
	auto closed1 = true;
	door1->setOnMouseCallback([&](auto object, auto x, auto y, auto action) -> bool {
		if (closed1) {
			object->setImage("Images/문-오른쪽-열림.png");
			closed1 = false;
		}
		else {
			room2->enter();
		}
		return true;
		});

	//장면 2 왼쪽 문 설정(열려있고 클릭하면 장면 1로 넘어감)
	auto door2 = Object::create("Images/문-왼쪽-열림.png", room2, 320, 270);
	door2->setOnMouseCallback([&](auto object, auto x, auto y, auto action) -> bool {
		room1->enter();
		return true;
		});

	//장면 2 스위치 설정(누르면 숨겨진 문이 생김)
	auto switch1 = Object::create("Images/스위치.png", room2, 730, 450);
	switch1->setScale(1.5f);
	auto door3 = Object::create("Images/문-오른쪽-닫힘.png", room2, 800, 270, false);
	switch1->setOnMouseCallback([&](auto object, auto x, auto y, auto action) -> bool {
		door3->show();
		return true;
		
		});

	//장면 2 숨겨진 문 설정(누르면 열리고 한 번 더 누르면 게임 종료)
	auto closed3 = true;
	door3->setOnMouseCallback([&](auto object, auto x, auto y, auto action) -> bool {
		if (closed3) {
			object->setImage("Images/문-오른쪽-열림.png");
			closed3 = false;
		}
		else {
			endGame();
		}
		return true;
		});

	startGame(room1);
}