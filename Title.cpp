#include "Title.h"

void Title::Initialize()
{
}

SceneType Title::Update()
{
	if (GetAsyncKeyState(VK_RETURN))
	{
		return SceneType::INGAME;
	}

    return SceneType::NONE;
}

void Title::Render()
{
	Panel::SetColor(Red);
	Panel::Print("                    --- Press Enter Key ---                     ", 16, 2);

	Panel::SetColor(SkyBlue);
	Panel::Print("	                 ____										  ", 16, 4);
	Panel::Print("                /___.`--.____ .--. ____.--(					  ", 16, 5);
	Panel::Print("                       .'_.- (    ) -._'.						  ", 16, 6);
	Panel::Print("                     .'.'    |'..'|    '.'.					  ", 16, 7);
	Panel::Print("              .-.  .' /'--.__|____|__.--'\\ '.  .-.			  ", 16, 8);
	Panel::Print("             (O).)-| |  \\    |    |    /  | |-(.(O)			  ", 16, 9);
	Panel::Print("              `-'  '-'-._'-./      \\.-'_.-'-'  `-'			  ", 16, 10);
	Panel::Print("                 _ | |   '-.________.-'   | | _				  ", 16, 11);
	Panel::Print("              .' _ | |     |   __   |     | | _ '.			  ", 16, 16);
	Panel::Print("             / .' ''.|     | /    \\ |     |.'' '. \\			  ", 16, 13);
	Panel::Print("             | |( )| '.    ||      ||    .' |( )| |			  ", 16, 14);
	Panel::Print("             \\ '._.'   '.  | \\    / |  .'   '._.' /			  ", 16, 15);
	Panel::Print("              '.__ ______'.|__'--'__|.'______ __.'			  ", 16, 16);
	Panel::Print("             .'_.-|         |------|         |-._'.			  ", 16, 17);
	Panel::Print("            //\\\\  |         |--::--|         |  //\\\\			  ", 16, 18);
	Panel::Print("           //  \\\\ |         |--::--|         | //  \\\\			  ", 16, 19);
	Panel::Print("          //    \\\\|        /|--::--|\\        |//    \\\\		  ", 16, 20);
	Panel::Print("         / '._.-'/|_______/ |--::--| \\_______|\\`-._.' \\		  ", 16, 21);
	Panel::Print("        / __..--'        /__|--::--|__\\        `--..__ \\		  ", 16, 22);
	Panel::Print("       / /               '-.|--::--|.-'               \\ \\		  ", 16, 23);
	Panel::Print("      / /                   |--::--|                   \\ \\	  ", 16, 24);
	Panel::Print("     / /                    |--::--|                    \\ \\	  ", 16, 25);
	Panel::Print(" _.-'  `-._                 _..||.._                  _.-` '-._ ", 16, 26);
	Panel::Print("'--..__..--' LGB           '-.____.-'                '--..__..-'", 16, 27);
}

void Title::Release()
{
}

Title::Title()
{
}

Title::~Title()
{
}
