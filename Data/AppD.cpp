#include "AppD.h"

MASH_str AppD::Folder = " ";
MASH_str AppD::File = " ";
MASH_json AppD::Data;

//Can be viewed in file
MASH_str AppD::User = " ";
MASH_str AppD::Father = " ";
MASH_str AppD::Mother = " ";
MASH_str AppD::PoB = " ";
MASH_str AppD::DoB = " ";
MASH_str AppD::ToB = " ";
MASH_uint AppD::Age = 9;
MASH_str AppD::Currency = " ";
MASH_str AppD::currentCity = " ";
MASH_uint AppD::walletAmount = 1000.00;

void AppD::CreateData()
{
	Universal u;

	RandomO rO;

	MASH_str name;

	MASH_cout << "To begin, please type your name: ";
	getline(MASH_cin, name);
	char Capitalized = toupper(name[0]);
	User = Capitalized + name.substr(1);

	u.SV();

	CreateFolder();
	CreateFile();
}

void AppD::CreateFolder()
{
	Universal u;

	Folder = "." + User + "'s Data";

	if (!MASH_fs::exists(Folder)) {
		if (MASH_fs::create_directory(Folder)) {
			u.MASH_LOG("Successfully created directory");
			u.SV(2);
		}
		else
		{
			u.MASH_LOG("[ERROR]: Could not create Directory");
			u.SV(2);
		}
	}
	else
	{
		u.MASH_LOG("[ERROR]: Folder already exists");
		u.SV(2);
	}
}

void AppD::CreateFile()
{
	Universal u;

	RandomO rO;

	File = Folder + "/Life Data.json";

	try {
		// Open the file for both reading and writing
		std::fstream fileStream(File, std::ios::in | std::ios::out);

		if (!fileStream.is_open()) {
			// The file doesn't exist, create it
			std::ofstream outputFile(File);
			outputFile << "{}" << std::endl;  // Write an empty JSON object to initialize the file
			outputFile.close();

			// Initialize game data
			rO.LifeData();
			if (RandomO::MoB < 10) {
				ToB = std::to_string(RandomO::HoB) + ":0" + std::to_string(RandomO::MoB) + " " + RandomO::AMorPM;
			}
			else {
				ToB = std::to_string(RandomO::HoB) + ":" + std::to_string(RandomO::MoB) + " " + RandomO::AMorPM;
			}
			if (RandomO::YoB < 1401) {
				Currency = "Gold Coins";
			}
			else if (RandomO::YoB > 1400 && RandomO::YoB < 1801) {
				Currency = "Silver Coins";
			}
			else {
				Currency = "Dollars";
			}
			PoB = RandomO::PoB;
			DoB = RandomO::DMoB + ", " + std::to_string(RandomO::YoB) + " " + RandomO::BCorAD;
			currentCity = RandomO::PoB;
			
			Father = RandomO::Father + " " + RandomO::lastName;
			Mother = RandomO::Mother + " " + RandomO::lastName;

			Data = {
				{"Birth Certificate", {
					{"Place of Birth", PoB},
					{"Date of Birth", DoB},
					{"Time of Birth", ToB},
					{"Parents", {
						{"Father", Father },
						{"Mother", Mother}
					}},
				}},
			};

			std::ofstream outputFilesec(File);
			outputFilesec << std::setw(4) << Data << std::endl;  // Write an empty JSON object to initialize the file
		}
		else {
			// Read the contents of the file into the json data structure
			fileStream >> Data;

			if (Data.is_null()) {
				// File is null, initialize game data
				rO.LifeData();
				if (RandomO::MoB < 10) {
					ToB = std::to_string(RandomO::HoB) + ":0" + std::to_string(RandomO::MoB) + " " + RandomO::AMorPM;
				}
				else {
					ToB = std::to_string(RandomO::HoB) + ":" + std::to_string(RandomO::MoB) + " " + RandomO::AMorPM;
				}
				if (RandomO::YoB < 1401) {
					Currency = "Gold Coins";
				}
				else if (RandomO::YoB > 1400 && RandomO::YoB < 1801) {
					Currency = "Silver Coins";
				}
				else {
					Currency = "Dollars";
				}
				PoB = RandomO::PoB;
				DoB = RandomO::DMoB + ", " + std::to_string(RandomO::YoB) + " " + RandomO::BCorAD;
				currentCity = RandomO::PoB;

				Father = RandomO::Father + " " + RandomO::lastName;
				Mother = RandomO::Mother + " " + RandomO::lastName;

				Data = {
					{"Birth Certificate", {
						{"Place of Birth", PoB},
						{"Date of Birth", DoB},
						{"Time of Birth", ToB},
						{"Parents", {
							{"Father", Father},
							{"Mother", Mother}
						}},
					}},
				};
			}
			else {
				DoB = Data["Birth Certificate"]["Date of Birth"];
				PoB = Data["Birth Certificate"]["Place of Birth"];
				ToB = Data["Birth Certificate"]["Time of Birth"];;
				Father = Data["Birth Certificate"]["Parents"]["Father"];
				Mother = Data["Birth Certificate"]["Parents"]["Mother"];
				Age = Data["Age"];
				Currency = Data["Currency"];
				currentCity = Data["Current City"];
				walletAmount = Data["Wallet"];

				MASH_vec<char> nums;
				MASH_uint firstNum = 0;
				MASH_uint position = 0;
				MASH_uint numBeforeComma = 0;
				MASH_uint Counter = 0;

				for (MASH_uint i = 0; i < DoB.size(); i++) {
					if (DoB[i] == '0' || DoB[i] == '1' || DoB[i] == '2' || DoB[i] == '3' || DoB[i] == '4' || DoB[i] == '5' || DoB[i] == '6' || DoB[i] == '7' || DoB[i] == '8' || DoB[i] == '9') {
						nums.push_back(DoB[i]);
						//Finnd how many numbers are before the comma
						if ((DoB[static_cast<std::basic_string<char, std::char_traits<char>, std::allocator<char>>::size_type>(i) + 1] == ',' && Counter == 0) || (DoB[static_cast<std::basic_string<char, std::char_traits<char>, std::allocator<char>>::size_type>(i) + 2] == ',' && Counter == 0)) { //Finds the coomma
							if (DoB[static_cast<std::basic_string<char, std::char_traits<char>, std::allocator<char>>::size_type>(i) + 1] == ',') {
								numBeforeComma = 1;
							}
							if (DoB[static_cast<std::basic_string<char, std::char_traits<char>, std::allocator<char>>::size_type>(i) + 2] == ',') {
								numBeforeComma = 2;
							}
			
							Counter++;
						}

						if (numBeforeComma == 1) {
							if (nums.size() == 2) {
								firstNum = i; //ouputs 9(index, not number
								RandomO::YoB = std::stoi(DoB.substr(firstNum, 1));
							}
							else if (nums.size() == 3) {
								RandomO::YoB = std::stoi(DoB.substr(firstNum, 2));
							}
							else if (nums.size() == 4) {
								RandomO::YoB = std::stoi(DoB.substr(firstNum, 3));
							}
							else if (nums.size() == 5) {
								RandomO::YoB = std::stoi(DoB.substr(firstNum, 4));
								MASH_cout << RandomO::YoB;
							}
						}
						else if (numBeforeComma == 2) {
							if (nums.size() == 3) {
								firstNum = i;
								RandomO::YoB = std::stoi(DoB.substr(firstNum, 1));
							}
							else if (nums.size() == 4) {
								RandomO::YoB = std::stoi(DoB.substr(firstNum, 2));
							}
							else if (nums.size() == 5) {
								RandomO::YoB = std::stoi(DoB.substr(firstNum, 3));
							}
							else if (nums.size() == 6) {
								RandomO::YoB = std::stoi(DoB.substr(firstNum, 4));
							}
						}
						position = i;
					}

					if (DoB[i] == 'A' || DoB[i] == 'B') {
						if (i > position) {
							RandomO::BCorAD = DoB.substr(i, 3);
						}
					}
				}


				fileStream.close();
			}
		}

	}
	catch (const std::exception& e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}

	UpdateData();
}



void AppD::UpdateData()
{
	std::ifstream input(File);
	input >> Data;
	//input.close();

	Data["Age"] = Age;
	Data["Currency"] = Currency;
	Data["Current City"] = currentCity;
	Data["Wallet"] = walletAmount;

	std::ofstream output(File);
	output << std::setw(4) << Data << MASH_endl;
	output.close();
}
