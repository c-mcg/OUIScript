#include "scope/OUI_ScopeLoader.h"
#include "scope/OUI_Linker.h"

#include "util/OUI_StringUtil.h"

#include <iostream>

int main() {

	std::unordered_map<oui::String, oui::Scope*> scopes = oui::loadScopes("./data/test.scp");

	std::cout << "Loaded scopes... null ? " << (scopes.size() == 0) << std::endl;

	for (auto it = scopes.begin(); it != scopes.end(); it++) {
		std::cout << "Scope: " << oui::convertUTF16to8(it->first).c_str() << std::endl;

		for (auto it2 = it->second->variables.begin(); it2 != it->second->variables.end(); it2++) {
			std::cout << "\tname=" << oui::convertUTF16to8(oui::getVariableName(it2->first)).c_str() << " val=" << oui::convertUTF16to8(it2->second->toString()).c_str() << std::endl;
		}
	}

	system("pause");
	return 0;
}