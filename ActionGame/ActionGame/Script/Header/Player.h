#ifndef PLAYER_H
#define PLAYER_H

class Player {
public:
	int pos_x;
	int pos_y;
	int movingSpeed;
	int playerGHandle;

	Player();
	~Player();

	// �ړ�
	void Moving();
	// �`��
	void Draw();
};

#endif // !PLAYER_H