/*
** Menu.cpp for cpp_arcade in /home/villen_l/rendu/cpp_arcade/Menu.cpp
**
** Made by Lucas Villeneuve
** Login   <lucas.villeneuve@epitech.eu>
**
** Started on  Mon Mar 13 16:09:37 2017 Lucas Villeneuve
** Last update Mon Mar 13 16:09:37 2017 Lucas Villeneuve
*/

#include <thread>
#include <chrono>
#include "IGameObject.hpp"
#include "Protocol.hpp"
#include "IMap.hh"
#include "Menu.hh"

arcade::Menu::Menu(const char *nameLib)
 : libList("./lib/"), gamesList("./games/")
{
  this->loopCounter = 1;
  this->lib = 0;
  this->game = 0;
  this->gameLaunched = false;
  this->bufferCmd = arcade::CommandType::GET_MAP;
  this->setLib(nameLib);
  if (this->gamesList.getName())
    this->setGame(this->gamesList.getName());
  this->lib->playMusic("./misc/CrashTheme.wav");
//  this->lib->playMusic("./misc/Pacman/Pacman.wav");
}

void	arcade::Menu::setLib(const char *nameLib)
{
  try
    {
      this->lib = this->libLoader.getInstance(nameLib);
    }
  catch (const std::exception &e)
    {
      this->lib = 0;
      throw (e);
    }
  this->lib->openWindow();
}

void	arcade::Menu::closeLib()
{
  if (this->lib != 0)
    {
      this->lib->closeWindow();
      delete (this->lib);
      this->lib = 0;
    }
  this->libLoader.closeHandler();
}


void	arcade::Menu::setGame(const char *nameGame)
{
  try
    {
      this->game = this->gameLoader.getInstance(nameGame);
    }
  catch (const std::exception &e)
    {
      this->game = 0;
    }
}

void	arcade::Menu::closeGame()
{
  if (this->game != 0)
    {
      delete (this->game);
      this->game = 0;
    }
  this->gameLoader.closeHandler();
  this->bufferCmd = arcade::CommandType::GET_MAP;
}

void 	arcade::Menu::switchLib(const MenuIndexLib &switchType)
{
  this->lib->stopMusic();
  this->closeLib();
  if (switchType == MenuIndexLib::INCREMENT)
    this->libList.incrementIndex();
  else if (switchType == MenuIndexLib::DECREMENT)
    this->libList.decrementIndex();
  std::this_thread::sleep_for(std::chrono::milliseconds(250));
  this->setLib(this->libList.getName());
  this->lib->playMusic("./misc/CrashTheme.wav");
}

void 	arcade::Menu::switchGame(const MenuIndexLib &switchType)
{
  this->closeGame();
  if (switchType == MenuIndexLib::INCREMENT)
    this->gamesList.incrementIndex();
  else if (switchType == MenuIndexLib::DECREMENT)
    this->gamesList.decrementIndex();
  std::this_thread::sleep_for(std::chrono::milliseconds(250));
  this->setGame(this->gamesList.getName());
}

void			arcade::Menu::drawMap(const arcade::IMap *map)
{
  uint16_t		width;
  uint16_t		height;
  uint16_t		i;
  uint16_t		j;
  arcade::Position	pos;

  width = map->getWidth();
  height = map->getHeight();
  i = 0;
  while (i < height)
    {
      j = 0;
      while (j < width)
	{
	  pos.x = j;
	  pos.y = i;
	  this->lib->drawGameObject(map->getTile(pos));
	  j++;
	}
      i++;
    }
}

void	arcade::Menu::drawEnemies(const std::vector<arcade::IGameObject*> &tab)
{
  std::vector<arcade::IGameObject*>::const_iterator	it;

  it = tab.begin();
  while (it != tab.end())
    {
      this->lib->drawGameObject((*it));
      it++;
    }
}

void 				arcade::Menu::update()
{
  arcade::Position		pos;
  arcade::Position		posScore;
  arcade::CommandType 		cmd;

  cmd = this->lib->processInput();
  if (cmd != arcade::CommandType::ILLEGAL && cmd != arcade::CommandType::WHERE_AM_I && cmd != arcade::CommandType::GET_MAP)
    this->bufferCmd = cmd;
  posScore.x = 900;
  posScore.y = 50;
  pos.x = 10;
  if (this->lib->isKeyPressed(arcade::Input(arcade::InputState::KEY_PRESSED, arcade::InputKey::NUM2)))
    this->switchLib(MenuIndexLib::DECREMENT);
  else if (this->lib->isKeyPressed(arcade::Input(arcade::InputState::KEY_PRESSED, arcade::InputKey::NUM3)))
    this->switchLib(MenuIndexLib::INCREMENT);
  if (this->lib->isKeyPressed(arcade::Input(arcade::InputState::KEY_PRESSED, arcade::InputKey::NUM4)))
    this->switchGame(MenuIndexLib::DECREMENT);
  else if (this->lib->isKeyPressed(arcade::Input(arcade::InputState::KEY_PRESSED, arcade::InputKey::NUM5)))
    this->switchGame(MenuIndexLib::INCREMENT);
  if (this->lib->isKeyPressed(arcade::Input(arcade::InputState::KEY_PRESSED, arcade::InputKey::ENTER))
      && !this->gameLaunched)
    {
      if (this->game != 0)
	{
	  this->game->launch();
	  this->gameLaunched = true;
	}
      else if (this->gamesList.getName())
	{
	  this->setGame(this->gamesList.getName());
	  this->gameLaunched = true;
	}
      std::this_thread::sleep_for(std::chrono::milliseconds(250));
    }

  if (this->gameLaunched)
    {
      if (this->loopCounter % 240 == 0)
	{
	  if (!this->game->playRound(this->bufferCmd))
	    {
	      this->drawMap(this->game->getMap());
	      this->lib->drawGameObject(this->game->getPlayer());
	      this->drawEnemies(this->game->getEnemies());
	      this->gameLaunched = false;
	      this->closeGame();
	    }
	  else
	    {
	      this->drawMap(this->game->getMap());
	      this->lib->drawGameObject(this->game->getPlayer());
	      this->drawEnemies(this->game->getEnemies());
	      this->lib->drawText("Score : " + this->game->getScore(),
				  posScore);
	    }
	}
    }
  else
    {
      pos.y = 0;
      this->lib->drawText("Controls :", pos);
      pos.y = 35;
      this->lib->drawText("2 : Prev. lib", pos);
      pos.y = 60;
      this->lib->drawText("3 : Next lib", pos);
      pos.y = 75;
      if (this->game != 0)
	this->lib->drawText("4 : Launch " + this->game->getName(), pos);
      else
	this->lib->drawText("4 : Set game and launch", pos);
      pos.y = 120;
      this->lib->drawText("8 : Reset game", pos);
      pos.y = 135;
      this->lib->drawText("9 : Return to menu", pos);
    }
  if (this->lib->isKeyPressed(arcade::Input(arcade::InputState::KEY_PRESSED, arcade::InputKey::NUM8)))
    {
      if (this->gameLaunched)
	{
	  this->closeGame();
	  if (this->gamesList.getName())
	    this->setGame(this->gamesList.getName());
	  std::this_thread::sleep_for(std::chrono::milliseconds(250));
	}
    }
  if (this->lib->isKeyPressed(arcade::Input(arcade::InputState::KEY_PRESSED, arcade::InputKey::NUM9)))
    {
      if (this->gameLaunched)
	{
	  this->gameLaunched = false;
	  this->closeGame();
	  std::this_thread::sleep_for(std::chrono::milliseconds(250));
	}
    }

}

void								arcade::Menu::loopMenu()
{
  std::chrono::time_point<std::chrono::system_clock>		prev;
  std::chrono::time_point<std::chrono::system_clock>		cur;
  std::chrono::milliseconds					lag(std::chrono::milliseconds(0));
  std::chrono::milliseconds					timestep(std::chrono::milliseconds(16));
  std::chrono::time_point<std::chrono::system_clock>::duration	elapsed;

/*
  const int FRAMES_PER_SECOND = 25;
  const int SKIP_TICKS = 1000 / FRAMES_PER_SECOND;
*/

//  std::chrono::duration = std::chrono::time_point::time_since_epoch();
/*
  long next_game_tick =
  int sleep_time = 0;
*/

/*
 prev = std::chrono::system_clock::now();
*/
  while (!this->lib->isEventQuit() &&
	 !this->lib->isKeyPressed(arcade::Input(arcade::InputState::KEY_PRESSED, arcade::InputKey::ESCAPE)))
    {
/*
      cur = std::chrono::system_clock::now();
      elapsed = cur - prev;
      prev = cur;
      lag += std::chrono::duration_cast<std::chrono::milliseconds>(elapsed);
*/

/*
      next_game_tick += std::chrono::duration_cast<std::chrono::milliseconds>(SKIP_TICKS);
*/

      if (this->loopCounter % 240 == 0)
	this->lib->clear();
      this->update();
      if (this->loopCounter % 240 == 0)
	this->lib->display();


      this->loopCounter++;
      if (this->loopCounter > 240)
	this->loopCounter = 1;


/*
      while (lag >= timestep)
	lag -= timestep;
*/
    }
  this->closeGame();
  this->closeLib();
}