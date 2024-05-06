#include "Snake.h"
#include<SDL.h>
#include<SDL_image.h>


void Snake::Move() {
	if (trick == false &&  pause == false) {
		std::cout << 1;
		pos_head.x += velocity.X;
		pos_head.y += velocity.Y;
	}
}

void Snake::stopMoving() {
	velocity.X = 0;
	velocity.Y = 0;
}

bool Snake::eatCherry(Cherry& cherry, SDL_Renderer* renderer) {
	if (pause == false) {
		tailNearHead++;
		tailEnd++;
		tail[tailNearHead % 10000] = pos_head;
		//storage position to avoid loop number 0
		//checkDirection only working when press nagavition button so...
		//update direction for all tail because it's only update one tail
		checkDirection[tailNearHead % 10000] = checkDirection[tailNearHead % 10000 - 1];
		//}
		if (cherry.PosX == pos_head.x * 25 && cherry.PosY == pos_head.y * 25) {
			//	sound.playSound("assets/sound/eatCherry.wav");
			cherry.generateCherry();
			tailEnd--;
			tail_size++;
			return true;
		}
		else return false;
	}
}

void Snake::renderAngle(SDL_Renderer* renderer, SDL_Texture* texture, int x, int y, int w, int h, int angle) {
	SDL_Rect dstRect = { x, y, w, h };
	SDL_RenderCopyEx(renderer, texture, NULL, &dstRect, angle, NULL, SDL_FLIP_NONE);
}

//snake_storage();
void Snake::drawHead(SDL_Renderer* renderer) {
	SDL_Surface* tmpSurface = IMG_Load("assets/images/snake_head1.png");
	SDL_Texture* tmpTexture = SDL_CreateTextureFromSurface(renderer, tmpSurface);
	SDL_Rect desrect;
	desrect.x = 25 * pos_head.x;
	desrect.y = 25 * pos_head.y;
	desrect.h = snakeWidth;
	desrect.w = snakeHeight;
	renderAngle(renderer, tmpTexture, desrect.x, desrect.y, desrect.w, desrect.h, headAngle);
	SDL_DestroyTexture(tmpTexture);
	SDL_FreeSurface(tmpSurface);
}

void Snake::drawTail(SDL_Renderer* renderer) {
for (int i = 1; i < tail_size; i++) {
	SDL_Texture* tmpTexture = NULL;
	SDL_Surface* tmpSurface = NULL;
	pos tail_pos = tail[(tailEnd + i) % 10000];
	if (checkCorner[(tailEnd + i) % 10000] > 0) {
		//check the snake go up right
		if (tail[(tailEnd + i + 1) % 10000].x > tail[(tailEnd + i) % 10000].x &&
			tail[(tailEnd + i - 1) % 10000].y > tail[(tailEnd + i) % 10000].y) {
			renderTail(renderer, tmpSurface, tmpTexture, "assets/images/rightUp.png", tail_pos);
		}
		//check the snake go up left
		if (tail[(tailEnd + i + 1) % 10000].x < tail[(tailEnd + i) % 10000].x &&
			tail[(tailEnd + i - 1) % 10000].y > tail[(tailEnd + i) % 10000].y) {
			renderTail(renderer, tmpSurface, tmpTexture, "assets/images/leftUp.png", tail_pos);
		}
		//check the snake go down right
		else if (tail[(tailEnd + i + 1) % 10000].x > tail[(tailEnd + i) % 10000].x &&
			tail[(tailEnd + i - 1) % 10000].y < tail[(tailEnd + i) % 10000].y) {
			renderTail(renderer, tmpSurface, tmpTexture, "assets/images/rightDown.png", tail_pos);
		}
		//check the snake go down left
		else if (tail[(tailEnd + i + 1) % 10000].x < tail[(tailEnd + i) % 10000].x &&
			tail[(tailEnd + i - 1) % 10000].y < tail[(tailEnd + i) % 10000].y) {
			renderTail(renderer, tmpSurface, tmpTexture, "assets/images/leftDown.png", tail_pos);
		}
		//check the snake go right up
		else if (tail[(tailEnd + i) % 10000].y > tail[(tailEnd + i + 1) % 10000].y &&
			tail[(tailEnd + i) % 10000].x > tail[(tailEnd + i - 1) % 10000].x) {
			renderTail(renderer, tmpSurface, tmpTexture, "assets/images/right_LeftUp.png", tail_pos);
		}
		//check the snake go right down 
		else if (tail[(tailEnd + i) % 10000].y < tail[(tailEnd + i + 1) % 10000].y &&
			tail[(tailEnd + i) % 10000].x > tail[(tailEnd + i - 1) % 10000].x) {
			renderTail(renderer, tmpSurface, tmpTexture, "assets/images/right_RightDown.png", tail_pos);
		}
		//check the snake go left up
		else if (tail[(tailEnd + i + 1) % 10000].y < tail[(tailEnd + i) % 10000].y &&
			tail[(tailEnd + i - 1) % 10000].x > tail[(tailEnd + i) % 10000].x) {
			renderTail(renderer, tmpSurface, tmpTexture, "assets/images/left_RightUp.png", tail_pos);

		}
		//check the snake go left down
		else if (tail[(tailEnd + i + 1) % 10000].y > tail[(tailEnd + i) % 10000].y &&
			tail[(tailEnd + i - 1) % 10000].x > tail[(tailEnd + i) % 10000].x) {
			renderTail(renderer, tmpSurface, tmpTexture, "assets/images/left_LeftDown.png", tail_pos);
		}

		//=========check the snake go out of window========
		//check go in
		//up left
		if (tail[(tailEnd + i) % 10000].y == 2 && tail[(tailEnd + i + 1) % 10000].x < tail[(tailEnd + i) % 10000].x &&
			tail[(tailEnd + i - 1) % 10000].y == 23) {
			renderTail(renderer, tmpSurface, tmpTexture, "assets/images/leftDown.png", tail_pos);
		}
		// up right
		else if (tail[(tailEnd + i) % 10000].y == 2 && tail[(tailEnd + i + 1) % 10000].x > tail[(tailEnd + i) % 10000].x &&
			tail[(tailEnd + i - 1) % 10000].y == 23) {
			renderTail(renderer, tmpSurface, tmpTexture, "assets/images/rightDown.png", tail_pos);
		}
		//down left
		else if (tail[(tailEnd + i) % 10000].y == 23 && tail[(tailEnd + i + 1) % 10000].x < tail[(tailEnd + i) % 10000].x &&
			tail[(tailEnd + i - 1) % 10000].y == 2) {
			renderTail(renderer, tmpSurface, tmpTexture, "assets/images/leftUp.png", tail_pos);
		}
		//down right
		else if (tail[(tailEnd + i) % 10000].y == 23 && tail[(tailEnd + i + 1) % 10000].x > tail[(tailEnd + i) % 10000].x &&
			tail[(tailEnd + i - 1) % 10000].y == 2) {
			renderTail(renderer, tmpSurface, tmpTexture, "assets/images/rightUp.png", tail_pos);
		}
		//left up
		else if (tail[(tailEnd + i) % 10000].x == 0 && tail[(tailEnd + i + 1) % 10000].y < tail[(tailEnd + i) % 10000].y &&
			tail[(tailEnd + i - 1) % 10000].x == 23) {
			renderTail(renderer, tmpSurface, tmpTexture, "assets/images/right_LeftUp.png", tail_pos);
		}
		//left down
		else if (tail[(tailEnd + i) % 10000].x == 0 && tail[(tailEnd + i + 1) % 10000].y > tail[(tailEnd + i) % 10000].y &&
			tail[(tailEnd + i - 1) % 10000].x == 23) {
			renderTail(renderer, tmpSurface, tmpTexture, "assets/images/right_RightDown.png", tail_pos);
		}
		//right up
		else if (tail[(tailEnd + i) % 10000].x == 23 && tail[(tailEnd + i + 1) % 10000].y < tail[(tailEnd + i) % 10000].y &&
			tail[(tailEnd + i - 1) % 10000].x == 0) {
			renderTail(renderer, tmpSurface, tmpTexture, "assets/images/left_RightUp.png", tail_pos);
		}
		//right down
		else if (tail[(tailEnd + i) % 10000].x == 23 && tail[(tailEnd + i + 1) % 10000].y > tail[(tailEnd + i) % 10000].y &&
			tail[(tailEnd + i - 1) % 10000].x == 0) {
			renderTail(renderer, tmpSurface, tmpTexture, "assets/images/left_LeftDown.png", tail_pos);
		}

		//check go out
		if (tail[(tailEnd + i) % 10000].y != 22 && tail[(tailEnd + i) % 10000].y != 3 &&
			tail[(tailEnd + i) % 10000].x != 1 && tail[(tailEnd + i) % 10000].x != 22) {
			//=======check the snake go up ==========
			//check the snake go left
			if (tail[(tailEnd + i) % 10000].y < tail[(tailEnd + i + 1) % 10000].y &&
				tail[(tailEnd + i) % 10000].x < tail[(tailEnd + i - 1) % 10000].x &&
				tail[(tailEnd + i + 1) % 10000].y == 23 && tail[(tailEnd + i) % 10000].y == 2) {
				renderTail(renderer, tmpSurface, tmpTexture, "assets/images/left_RightUp.png", tail_pos);
			}
			//check the snake go right
			else if (tail[(tailEnd + i) % 10000].y < tail[(tailEnd + i + 1) % 10000].y &&
				tail[(tailEnd + i) % 10000].x > tail[(tailEnd + i - 1) % 10000].x &&
				tail[(tailEnd + i + 1) % 10000].y == 23 && tail[(tailEnd + i) % 10000].y == 2) {
				renderTail(renderer, tmpSurface, tmpTexture, "assets/images/right_LeftUp.png", tail_pos);
			}

			//========check the snake go down========
			//check the snake go left
			else if (tail[(tailEnd + i) % 10000].y > tail[(tailEnd + i + 1) % 10000].y &&
				tail[(tailEnd + i) % 10000].x < tail[(tailEnd + i - 1) % 10000].x &&
				tail[(tailEnd + i) % 10000].y == 23 && tail[(tailEnd + i + 1) % 10000].y == 2) {
				renderTail(renderer, tmpSurface, tmpTexture, "assets/images/left_LeftDown.png", tail_pos);
			}
			//check the snake go right
			else if (tail[(tailEnd + i) % 10000].y > tail[(tailEnd + i + 1) % 10000].y &&
				tail[(tailEnd + i) % 10000].x > tail[(tailEnd + i - 1) % 10000].x &&
				tail[(tailEnd + i) % 10000].y == 23 && tail[(tailEnd + i + 1) % 10000].y == 2) {
				renderTail(renderer, tmpSurface, tmpTexture, "assets/images/right_RightDown.png", tail_pos);
			}

			//========check the snake go left========
			//check the snake go up
			else if (tail[(tailEnd + i) % 10000].y < tail[(tailEnd + i - 1) % 10000].y &&
				tail[(tailEnd + i) % 10000].x < tail[(tailEnd + i + 1) % 10000].x &&
				tail[(tailEnd + i + 1) % 10000].x == 23 && tail[(tailEnd + i) % 10000].x == 0) {
				renderTail(renderer, tmpSurface, tmpTexture, "assets/images/leftUp.png", tail_pos);
			}
			//check the snake go down
			else if (tail[(tailEnd + i) % 10000].y > tail[(tailEnd + i - 1) % 10000].y &&
				tail[(tailEnd + i) % 10000].x < tail[(tailEnd + i + 1) % 10000].x &&
				tail[(tailEnd + i + 1) % 10000].x == 23 && tail[(tailEnd + i) % 10000].x == 0) {
				renderTail(renderer, tmpSurface, tmpTexture, "assets/images/leftDown.png", tail_pos);
			}

			//========check the snake go right========
			//check the snake go up
			else if (tail[(tailEnd + i) % 10000].y < tail[(tailEnd + i - 1) % 10000].y &&
				tail[(tailEnd + i) % 10000].x > tail[(tailEnd + i + 1) % 10000].x &&
				tail[(tailEnd + i + 1) % 10000].x == 0 && tail[(tailEnd + i) % 10000].x == 23) {
				renderTail(renderer, tmpSurface, tmpTexture, "assets/images/rightUp.png", tail_pos);
			}
			//check the snake go down
			else if (tail[(tailEnd + i) % 10000].y > tail[(tailEnd + i - 1) % 10000].y &&
				tail[(tailEnd + i) % 10000].x > tail[(tailEnd + i + 1) % 10000].x &&
				tail[(tailEnd + i + 1) % 10000].x == 0 && tail[(tailEnd + i) % 10000].x == 23) {
				renderTail(renderer, tmpSurface, tmpTexture, "assets/images/rightDown.png", tail_pos);
			}
		}
	}

	//tail normal handle
	else {
		tmpSurface = IMG_Load("assets/images/snakee.png");
		tmpTexture = SDL_CreateTextureFromSurface(renderer, tmpSurface);
		SDL_Rect desrect;
		desrect.x = tail_pos.x * 25;
		desrect.y = tail_pos.y * 25;
		desrect.h = snakeHeight;
		desrect.w = snakeWidth;
		if (checkDirection[(tailEnd + i) % 10000] == 1)
			renderAngle(renderer, tmpTexture, desrect.x, desrect.y, desrect.w, desrect.h, 90);
		else if ((checkDirection[(tailEnd + i) % 10000] == 2))
			renderAngle(renderer, tmpTexture, desrect.x, desrect.y, desrect.w, desrect.h, 0);
		SDL_DestroyTexture(tmpTexture);
		SDL_FreeSurface(tmpSurface);
	}

}



//small tail handle
if (tail_size > 0)
	for (int i = 0; i < 1; i++) {
		pos tail_pos = tail[(tailEnd + i) % 10000];
		SDL_Surface* tailSurface = IMG_Load("assets/images/tail.png");
		SDL_Texture* tailTexture = SDL_CreateTextureFromSurface(renderer, tailSurface);
		SDL_Rect desrect;
		desrect.x = tail_pos.x * 25;
		desrect.y = tail_pos.y * 25;
		desrect.h = 25;
		desrect.w = snakeHeight;

		//========check snake go out the window==========

		//checkDirection[(tailEnd + i) % 10000] == 1 -> up or down
		//checkDirection[(tailEnd + i) % 10000] == 2 -> left or right

		//check the snake go up
		if (tail[(tailEnd + i) % 10000].y == 2 && checkDirection[(tailEnd + i) % 10000] == 1 &&
			tail[(tailEnd + i + 1) % 10000].y == 23) {
			renderAngle(renderer, tailTexture, desrect.x, desrect.y, desrect.w, desrect.h, -90);
		}
		//check the snake go down
		else if (tail[(tailEnd + i) % 10000].y == 23 && checkDirection[(tailEnd + i) % 10000] == 1 &&
			tail[(tailEnd + i + 1) % 10000].y == 2) {
			renderAngle(renderer, tailTexture, desrect.x, desrect.y, desrect.w, desrect.h, 90);
		}
		//check the snake go left
		else if (tail[(tailEnd + i) % 10000].x == 0 && checkDirection[(tailEnd + i) % 10000] == 2 &&
			tail[(tailEnd + i + 1) % 10000].x == 23) {
			renderAngle(renderer, tailTexture, desrect.x, desrect.y, desrect.w, desrect.h, 180);
		}
		//check the snake go right
		else if (tail[(tailEnd + i) % 10000].x == 23 && checkDirection[(tailEnd + i) % 10000] == 2 &&
			tail[(tailEnd + i + 1) % 10000].x == 0) {
			renderAngle(renderer, tailTexture, desrect.x, desrect.y, desrect.w, desrect.h, 0);
		}

		//normal movement
		else {
			//left
			if (tail[(tailEnd + i + 1) % 10000].x < tail[(tailEnd + i) % 10000].x)
				renderAngle(renderer, tailTexture, desrect.x, desrect.y, desrect.w, desrect.h, 180);
			//right
			else if (tail[(tailEnd + i + 1) % 10000].x > tail[(tailEnd + i) % 10000].x)
				renderAngle(renderer, tailTexture, desrect.x, desrect.y, desrect.w, desrect.h, 0);
			//down
			else if (tail[(tailEnd + i + 1) % 10000].y > tail[(tailEnd + i) % 10000].y)
				renderAngle(renderer, tailTexture, desrect.x, desrect.y, desrect.w, desrect.h, 90);
			//up
			else if (tail[(tailEnd + i + 1) % 10000].y < tail[(tailEnd + i) % 10000].y)
				renderAngle(renderer, tailTexture, desrect.x, desrect.y, desrect.w, desrect.h, -90);
		}
		SDL_DestroyTexture(tailTexture);
		SDL_FreeSurface(tailSurface);
	}

}

bool Snake::tailCollision() {
if (trick == false && pause == false) {
	for (int i = 0; i < tail_size; i++) {
		pos tail_pos = tail[(tailEnd + i) % 10000];
		if (pos_head.x == tail_pos.x && pos_head.y == tail_pos.y) {
			return true;
		}
	}
	for (int j = 0; j < getObstaclesLevel.size(); j++) {
		if (pos_head.x == getObstaclesLevel[j].first && pos_head.y == getObstaclesLevel[j].second) {
			return true;
		}
	}
}
return false;

}

//check duplicate direction to avoid spam direction so that it won't be disappear tail
//checkConer will spam the direction of snake so that normal tail will be disappear

//checkDirection[(tailEnd + i) % 10000] == 1 -> up or down
//checkDirection[(tailEnd + i) % 10000] == 2 -> left or right
void Snake::turnUp() {
	if (pause == false) {
		isUpping = 1;
		if (isDowning == 1)
			checkDuplicateDirectionDown = 1;
		else
			checkDuplicateDirectionDown = 0;

		checkDuplicateDirectionRight = 0;
		checkDuplicateDirectionLeft = 0;
		if (velocity.Y != 1 && checkDuplicateDirectionUp != 1) {
			velocity.X = 0;
			velocity.Y = -1;
			headAngle = -90;
			checkDirection[tailNearHead % 10000] = 1;
			checkCorner[tailNearHead % 10000] = 1;
			//check duplicate direction
			checkDuplicateDirectionUp = 1;
		}
	}
}

void Snake::turnDown() {
	if (pause == false) {
		isDowning = 1;
		if (isUpping == 1)
			checkDuplicateDirectionUp = 1;
		else
			checkDuplicateDirectionUp = 0;

		checkDuplicateDirectionRight = 0;
		checkDuplicateDirectionLeft = 0;
		if (velocity.Y != -1 && checkDuplicateDirectionDown != 1) {
			velocity.X = 0;
			velocity.Y = 1;
			headAngle = 90;
			checkDirection[tailNearHead % 10000] = 1;
			checkCorner[tailNearHead % 10000] = 2;
			//check duplicate direction
			checkDuplicateDirectionDown = 1;
		}
	}
}

void Snake::turnRight() {
	if (pause == false) {
		isGoingRight = 1;
		if (isGoingLeft == 1)
			checkDuplicateDirectionLeft = 1;
		else
			checkDuplicateDirectionLeft = 0;

		checkDuplicateDirectionDown = 0;
		checkDuplicateDirectionUp = 0;
		if (velocity.X != -1 && checkDuplicateDirectionRight != 1) {
			velocity.X = 1;
			velocity.Y = 0;
			headAngle = 0;
			checkDirection[tailNearHead % 10000] = 2;
			checkCorner[tailNearHead % 10000] = 3;
			//check duplicate direction
			checkDuplicateDirectionRight = 1;
		}
	}
}

void Snake::turnLeft() {
	if (pause == false) {
		isGoingLeft = 1;
		if (isGoingRight == 1)
			checkDuplicateDirectionRight = 1;
		else
			checkDuplicateDirectionRight = 0;

		checkDuplicateDirectionDown = 0;
		checkDuplicateDirectionUp = 0;
		isGoingLeft = 1;
		if (velocity.X != 1 && checkDuplicateDirectionLeft != 1) {
			velocity.X = -1;
			velocity.Y = 0;
			headAngle = 180;
			checkDirection[tailNearHead % 10000] = 2;
			checkCorner[tailNearHead % 10000] = 4;
			//check duplicate direction
			checkDuplicateDirectionLeft = 1;
		}
	}
}


void Snake::renderTail(SDL_Renderer * renderer, SDL_Surface * tmpSurface, SDL_Texture * tmpTexture, std::string path, pos tail_pos) {
	SDL_Rect desrect;
	tmpSurface = IMG_Load(path.c_str());
	tmpTexture = SDL_CreateTextureFromSurface(renderer, tmpSurface);
	desrect.x = tail_pos.x * 25;
	desrect.y = tail_pos.y * 25;
	desrect.h = snakeHeight;
	desrect.w = snakeWidth;
	SDL_RenderCopy(renderer, tmpTexture, NULL, &desrect);
	SDL_DestroyTexture(tmpTexture);
	SDL_FreeSurface(tmpSurface);
}




void Snake::goOutOfWindow() {
	if (pos_head.x < 0)pos_head.x = (WIDTH / 25) - 1;
	if (pos_head.x >= WIDTH / 25)pos_head.x = 0;
	if (pos_head.y < 2)pos_head.y = (HEIGHT / 25) - 1;
	if (pos_head.y >= HEIGHT / 25)pos_head.y = 2;
}

void Snake::draw(SDL_Renderer * renderer, Snake & snake) {
	//if (tail_size > 0)
	snake.drawTail(renderer);
}