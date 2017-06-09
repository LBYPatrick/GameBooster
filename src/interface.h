#pragma once

void languageSwitcher();
bool runasDebugMode = 0;
bool requireAdmin = 1;
int welcome(int interval = 30, bool DebugMode = runasDebugMode, bool toRunAdminCheck = requireAdmin);
