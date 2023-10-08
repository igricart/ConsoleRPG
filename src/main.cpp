#include "Game.h"
// TRY GPT
#include "ChatGPT/include/ChatGPT.h"
#include "ChatGPT/include/Error.h"
#include <spdlog/spdlog.h>
#include <spdlog/sinks/stdout_color_sinks.h>
#include <cstdlib>

int main()
{
  // 1. Create a colorized stdout sink
  auto color_sink = std::make_shared<spdlog::sinks::stdout_color_sink_mt>();

  // 2. Set the pattern to display the message and optionally the level
  color_sink->set_pattern("%^%v%$");

  // 3. Set the colors for the info and debug levels
  color_sink->set_color(spdlog::level::info, color_sink->white);
  color_sink->set_color(spdlog::level::debug, color_sink->cyan);

  // 4. Create a logger with the color sink
  auto logger = std::make_shared<spdlog::logger>("global", color_sink);

  // 5. Register the logger as the global logger
  spdlog::set_default_logger(logger);
  spdlog::set_level(spdlog::level::debug);  // Set global log level to debug

#ifdef NDEBUG
  spdlog::info("Release build");
#else
  spdlog::info("Debug build");
#endif

  srand(time(NULL));

  Game game;
  game.initGame();

  while (game.getPlaying())
  {
    game.mainMenu();
  }

  return 0;
}