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
#include "IGameObject.hh"
#include "Map.hh"
#include "Menu.hh"

arcade::Menu::Menu(const char *nameLib)
 : libList("./lib/"), gamesList("./games/")
{
  this->playerName = "";
  this->lib = 0;
  this->game = 0;
  this->gameLaunched = false;
  this->cmd = arcade::CommandType::ILLEGAL;
  this->bufferCmd = arcade::CommandType::PLAY;
  this->setLib(nameLib);
  this->lib->playMusic("./misc/CrashTheme.wav");
}

arcade::Menu::~Menu()
{
  this->closeGame();
  this->closeLib();
}

void	arcade::Menu::setLib(const char *nameLib)
{
  try
    {
      this->lib = this->libLoader.getInstance(nameLib, "entry_lib");
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
      this->game = this->gameLoader.getInstance(nameGame, "entry_game");
      this->game->setPlayerName(this->playerName);
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
}

void 	arcade::Menu::switchLib(const MenuIndexLib &switchType)
{
  if (switchType == MenuIndexLib::INCREMENT)
    this->libList.incrementIndex();
  else if (switchType == MenuIndexLib::DECREMENT)
    this->libList.decrementIndex();
  if (this->gameLaunched)
    {
      this->lib->stopMusic();
      this->closeLib();
      this->setLib(this->libList.getName());
    }
  std::this_thread::sleep_for(std::chrono::milliseconds(250));
}

void 	arcade::Menu::switchGame(const MenuIndexLib &switchType)
{
  if (switchType == MenuIndexLib::INCREMENT)
    this->gamesList.incrementIndex();
  else if (switchType == MenuIndexLib::DECREMENT)
    this->gamesList.decrementIndex();
  if (this->gameLaunched)
    {
      this->closeGame();
      this->setGame(this->gamesList.getName());
    }
  std::this_thread::sleep_for(std::chrono::milliseconds(250));
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

void	arcade::Menu::drawEnemies(const std::vector<arcade::games::IGameObject*> &tab)
{
  std::vector<arcade::games::IGameObject*>::const_iterator	it;

  it = tab.begin();
  while (it != tab.end())
    {
      this->lib->drawGameObject((*it));
      it++;
    }
}

void	arcade::Menu::drawStrings(const std::vector<arcade::games::IGameObject*> &strings)
{
  std::vector<arcade::games::IGameObject*>::const_iterator	it;

  it = strings.begin();
  while (it != strings.end())
    {
      this->lib->drawText((*it)->getSprite(), (*it)->getPos());
      it++;
    }
}

void	arcade::Menu::eventHandler()
{
  int 	c;

  this->cmd = this->lib->processInput();
  if (this->cmd != arcade::CommandType::ILLEGAL && this->cmd != arcade::CommandType::PLAY)
    this->bufferCmd = this->cmd;
  if (this->cmd == arcade::CommandType::PREV_LIB)
    this->switchLib(MenuIndexLib::DECREMENT);
  else if (this->cmd == arcade::CommandType::NEXT_LIB)
    this->switchLib(MenuIndexLib::INCREMENT);
  if (this->cmd == arcade::CommandType::PREV_GAME)
    this->switchGame(MenuIndexLib::DECREMENT);
  else if (this->cmd == arcade::CommandType::NEXT_GAME)
    this->switchGame(MenuIndexLib::INCREMENT);
  if (this->cmd == arcade::CommandType::LAUNCH && !this->gameLaunched && this->gamesList.getName())
    {
      this->bufferCmd = arcade::CommandType::PLAY;
      this->setGame(this->gamesList.getName());
      this->gameLaunched = true;
      std::this_thread::sleep_for(std::chrono::milliseconds(250));
    }
  if (this->cmd == arcade::CommandType::RESET && this->gameLaunched)
    {
      this->bufferCmd = arcade::CommandType::PLAY;
      this->closeGame();
      if (this->gamesList.getName())
	this->setGame(this->gamesList.getName());
      std::this_thread::sleep_for(std::chrono::milliseconds(250));
    }
  if (this->cmd == arcade::CommandType::MENU && this->gameLaunched)
    {
      this->gameLaunched = false;
      this->closeGame();
      std::this_thread::sleep_for(std::chrono::milliseconds(250));
    }
  if (this->cmd == arcade::CommandType::SHOOT && !this->gameLaunched)
    {
      this->lib->stopMusic();
      this->closeLib();
      this->setLib(this->libList.getName());
      std::this_thread::sleep_for(std::chrono::milliseconds(250));
    }
  if ((c = this->lib->getKey()) != -1 && this->playerName.size() < 8
      && ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')))
    this->playerName += c;
  else if (this->playerName.size() > 0 && c == '\b')
    this->playerName.pop_back();
}

void 			arcade::Menu::update()
{
  arcade::Position	pos;
  int 			i;

  pos.x = 0;
  if (this->gameLaunched)
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
	  this->drawStrings(this->game->getStrings());
	}
    }
  else
    {
      pos.y = 0;
      this->lib->drawText("Controls :", pos);
      pos.y += 1;
      this->lib->drawText("2 : Prev. lib", pos);
      pos.y += 1;
      this->lib->drawText("3 : Next lib", pos);
      pos.y += 1;
      this->lib->drawText("4 : Prev. game", pos);
      pos.y += 1;
      this->lib->drawText("5 : Next game", pos);
      pos.y += 1;
      this->lib->drawText("8 : Reset game", pos);
      pos.y += 1;
      this->lib->drawText("9 : Return to menu", pos);
      pos.y += 1;
      this->lib->drawText("Space : Change graphic library", pos);
      pos.y += 2;
      this->lib->drawText("Name : ", pos);
      pos.x += 7;
      this->lib->drawText(this->playerName, pos);
      i = 0;
      pos.x = 20;
      pos.y = 2;
      while (i < static_cast<int>(this->gamesList.getSize()))
	{
	  pos.y += 1;
	  pos.x -= 4;
	  if (i == this->gamesList.getIndex())
	    this->lib->drawText("[X]", pos);
	  else
	    this->lib->drawText("[ ]", pos);
	  pos.x += 4;
	  this->lib->drawText(this->gamesList[i], pos);
	  i++;
	}
      pos.x = 10;
      pos.y += 8;
      i = 0;
      while (i < static_cast<int>(this->libList.getSize()))
	{
	  pos.y++;
	  pos.x -= 4;
	  if (i == this->libList.getIndex())
	    this->lib->drawText("[X]", pos);
	  else
	    this->lib->drawText("[ ]", pos);
	  pos.x += 4;
	  this->lib->drawText(this->libList[i], pos);
	  i++;
	}
    }
}

void								arcade::Menu::loopMenu()
{
  std::chrono::time_point<std::chrono::system_clock>		prev;
  std::chrono::time_point<std::chrono::system_clock>		cur;

  std::this_thread::sleep_for(std::chrono::milliseconds(250));
  while (!this->lib->isEventQuit())
    {
      prev = std::chrono::system_clock::now();
      while (std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now() - prev) < std::chrono::milliseconds(128))
	{
	  this->eventHandler();
	  if (this->cmd == arcade::CommandType::EXIT)
	    return;
	}
      this->lib->winClear();
      this->update();
      this->lib->display();
    }
}