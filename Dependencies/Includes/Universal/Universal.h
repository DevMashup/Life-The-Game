#pragma once

//Input Out
#define MASH_cout std::cout
#define MASH_cin std::cin
#define MASH_endl std::endl
#define MASH_fs std::filesystem

//Data types
#define MASH_ccharp const char*
#define MASH_uint unsigned int
#define MASH_str std::string
#define MASH_vec std::vector
#define MASH_json nlohmann::json
#define MASH_f float
#define MASH_b bool
#define MASH_int64t int64_t

//Methods
#define MASH_exit exit(0)

class Universal {
public:
	void MASH_LOG(MASH_ccharp);

	void SH();
	void SH(MASH_uint);
	void SV();
	void SV(MASH_uint);
};