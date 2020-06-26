#include "kb_searchfiles.h"
#include <io.h>

int kb::search_files(
	const std::string iDirname,
	const char* iStrext1,
	std::vector<std::string>& oVec1
)
{
	std::string strext1 = iStrext1;

	struct _finddata_t header_file;
	intptr_t hFile = 0;

	if ((hFile = _findfirst((iDirname + strext1).c_str(), &header_file)) == -1L)
		return -1;

	// 見つかった名前を連結して新しいパスを作成
	oVec1.push_back(header_file.name);

	//	DICOM File を読み込んで単純に閾値処理をしてみる
	int kk = 0;
	while (_findnext(hFile, &header_file) == 0) {

		// １文字目が"."".."とかは無視して続行
		if (header_file.name[0] == '.')
			continue;

		// 見つかった名前を連結して新しいパスを作成
		oVec1.push_back(header_file.name);

		kk++;
	}
	return kk;
}
