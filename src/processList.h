#pragma once
#include <string>
const unsigned int num_games = 32;
const unsigned int num_negativeProcesses = 11;
const unsigned int num_blacklistPrograms = 3;

std::string blacklistPrograms [num_blacklistPrograms] = {
	"bittorrentie",
	"QTalk",
	"TaobaoProtect"
};

std::string negativeProgram_processes[num_negativeProcesses] = {
	"chrome",
	"MicrosoftEdge",
	"cloudmusic",
	"Spotify",
	"Photoshop",
	"WINWORD",
	"POWERPNT",
	"googledrivesync",
	"clion64",
	"corelDRW",
	"idea64"
};

std::string negativeProgram_names[num_negativeProcesses] = {
	"Google Chrome",
	"Microsoft Edge",
	"Netease Music",
	"Spotify",
	"Adobe Photoshop",
	"Microsoft Word",
	"Microsoft PowerPoint",
	"Google Drive",
	"CLion",
	"CorelDRAW X8",
	"Intelij Idea"
};

std::string game_processNames[num_games] = {
	"WatchDogs",					//Watch Dogs
	"Game",							//Warface
	"WatchDogs2",					//Watch Dogs 2
	"JustCause3",					//Just Cause 3
	"MirrorsEdgeCatalyst",			//Mirrors' Edge Catalyst
	"HITMAN",						//HITMAN 6
	"LolClient",					//League of Legends
	"GTA5",							//GTA5
	"SimCity",						//Simcity 5
	"NFS14",						//NFS 18 Rivals
	"NFS13",						//NFS 17 Most Wanted
	"TrackmaniaTurbo",				//TrackMania Turbo
	"Warframe.x64",					//Warframe
	"factorio",						//Factorio
	"PlantsVsZombies",				//PvZ...I'm weird, right?
	"OSU",							//OSU!
	"NFS16",						//Need for Speed 2015
	"dirt3_game",					//DiRT 3
	"arma2",						//ArmA 2
	"arma3",						//ArmA 3
	"ShooterGame",					//ARK: Survival Evolved
	"starwarsbattlefront",			//Star Wars: Battlefront
	"MetroLL",						//Metro Last Light
	"DXHRDC",						//Deus Ex: Human Revolution - Director's Cut
	"payday2_win32_release",		//Pay Day 2
	"fallout4",						//Fallout 4
	"RainbowSix",					//Rainbow Six Siege
	"KSP_x64",						//Kerbal Space Program
	"FalloutShelter",				//Fallout Shelter
	"forzamotorsportapex",			//Forza Motorsport 6 : Apex
	"forza_x64_release_final",		//Forza Horizon 3
	"codoMP_client_shipRetail"		//Call Of Duty Online
};

std::string game_names[num_games] = {
	"Watch Dogs",
	"Warface",
	"Watch Dogs 2",
	"Just Cause 3",
	"Mirrors' Edge Catalyst",
	"HITMAN 6",
	"LOL",
	"Grand Theft Auto 5",
	"SimCity 5",
	"Need For Speed 18 Rivals",
	"Need For Speed 17 Most Wanted",
	"TrackMania Turbo",
	"Warframe",
	"Factorio",
	"PlantVSZombies",
	"OSU!",
	"Need for Speed 2015",
	"DiRT 3",
	"ArmA 2",
	"ArmA 3",
	"ARK: Survival Evolved",
	"Star Wars: Battlefront",
	"Metro Last Light",
	"Deus Ex: Human Revolution - Director's Cut",
	"Pay Day 2",
	"Fallout 4",
	"Rainbow Six Siege",
	"Kerbal Space Program",
	"Fallout Shelter",
	"Forza Motorsport 6 : Apex",
	"Forza Horizon 3",
	"Call Of Duty Online"
};