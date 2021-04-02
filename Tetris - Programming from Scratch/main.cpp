#include <iostream>
#include <thread>
#include <chrono>
#include <vector>

#include <Windows.h>
#include <cstdio>

std::wstring tetromino[7]{};
int nFieldWidth{ 12 };
int nFieldHeight{ 18 };
unsigned char *pField{ nullptr };

int nScreenWidth{ 120 }; // 80 | Actual: 120
int nScreenHeight{ 30 }; // 30 | Actual: 30

int Rotate(int px, int py, int r)
{
	switch (r % 4)
	{
		case 0: { return py * 4 + px; }
		case 1: { return 12 + py - (px * 4); }
		case 2: { return 15 - (py * 4) - px; }
		case 3: { return 3 - py + (px * 4); }
	}

	return 0;
}

bool doesPieceFit(int nTetromino, int nRotation, int nPosX, int nPosY)
{
	for (int px{ 0 }; px < 4; ++px)
	{
		for (int py{ 0 }; py < 4; ++py)
		{
			// Get index into piece
			int pi{ Rotate(px, py, nRotation) };

			// Get index into field
			int fi{ (nPosY + py) * nFieldWidth + (nPosX + px) };

			if (nPosX + px >= 0 && nPosX + px < nFieldWidth)
			{
				if (nPosY + py >= 0 && nPosY + py < nFieldHeight)
				{
					if (tetromino[nTetromino][pi] != L'.' && pField[fi] != 0) // Was == L'X'
					{
						return false; // Fail on first hit
					}
				}
			}
		}
	}

	return true;
}

int main()
{
	// Resize window
	/*HWND hwnd = GetConsoleWindow();
	if (hwnd != NULL)
	{
		MoveWindow(hwnd, 200, 200, 680, 400, TRUE);
	}*/

	wchar_t *screen{ new wchar_t[nScreenWidth * nScreenHeight] };
	for (int i{ 0 }; i < (nScreenWidth * nScreenHeight); ++i) { screen[i] = L' '; }
	HANDLE hConsole{ CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL) };
	SetConsoleActiveScreenBuffer(hConsole);
	DWORD dwBytesWritten{ 0 };

	tetromino[0].append(L"..X...X...X...X.");
	tetromino[1].append(L"..X..XX..X......");
	tetromino[2].append(L".X...XX...X.....");
	tetromino[3].append(L".....XX..XX.....");
	tetromino[4].append(L"..X..XX...X.....");
	tetromino[5].append(L".....XX...X...X.");
	tetromino[6].append(L".....XX..X...X..");

	pField = new unsigned char[nFieldWidth * nFieldHeight];
	for (int x{ 0 }; x < nFieldWidth; ++x)
	{
		for (int y{ 0 }; y < nFieldHeight; ++y)
		{
			pField[y * nFieldWidth + x] = (x == 0 || x == nFieldWidth - 1 || y == nFieldHeight - 1) ? 9 : 0;
		}
	}

	bool bGameOver{ false };

	int nCurrentPiece{ 0 };
	int nCurrentRotation{ 0 };
	int nCurrentX{ nFieldWidth / 2 };
	int nCurrentY{ 0 };

	bool bKey[4];
	bool bRotateHold{ false };

	int nSpeed{ 20 };
	int nSpeedCount{ 0 };
	bool bForceDown{ false };
	int nPieceCount{ 0 };
	int nScore{ 0 };

	std::vector<int> vLines{};

	while (!bGameOver)
	{
		// Game Timing
		std::this_thread::sleep_for(std::chrono::milliseconds(50)); // Game Tick
		++nSpeedCount;
		bForceDown = (nSpeedCount == nSpeed);

		// Input
		for (int k{ 0 }; k < 4; ++k)
		{
			// L Arrow, R Arrow, D Arrow, R Key
			bKey[k] = (0x8000 & GetAsyncKeyState((unsigned char)("\x27\x25\x28R"[k]))) != 0;
		}

		// Game Logic
		nCurrentX += (bKey[0] && doesPieceFit(nCurrentPiece, nCurrentRotation, nCurrentX + 1, nCurrentY)) ? 1 : 0;
		nCurrentX -= (bKey[1] && doesPieceFit(nCurrentPiece, nCurrentRotation, nCurrentX - 1, nCurrentY)) ? 1 : 0;
		nCurrentY += (bKey[2] && doesPieceFit(nCurrentPiece, nCurrentRotation, nCurrentX, nCurrentY + 1)) ? 1 : 0;

		if (bKey[3])
		{
			nCurrentRotation += (!bRotateHold && doesPieceFit(nCurrentPiece, nCurrentRotation + 1, nCurrentX, nCurrentY)) ? 1 : 0;
			bRotateHold = true;
		}
		else
		{
			bRotateHold = false;
		}

		if (bForceDown)
		{
			nSpeedCount = 0;

			if (doesPieceFit(nCurrentPiece, nCurrentRotation, nCurrentX, nCurrentY + 1))
			{
				++nCurrentY;
			}
			else
			{
				// Lock the current piece in the field
				for (int px{ 0 }; px < 4; ++px)
				{
					for (int py{ 0 }; py < 4; ++py)
					{
						if (tetromino[nCurrentPiece][Rotate(px, py, nCurrentRotation)] != L'.') // Was == L'X'
						{
							pField[(nCurrentY + py) * nFieldWidth + (nCurrentX + px)] = nCurrentPiece + 1;
						}
					}
				}

				++nPieceCount;
				if (nPieceCount % 10 == 0)
				{
					if (nSpeed >= 10)
					{
						--nSpeed;
					}
				}

				// Check if we have created any lines
				for (int py{ 0 }; py < 4; ++py)
				{
					if (nCurrentY + py < nFieldHeight - 1)
					{
						bool bLine{ true };
						for (int px{ 1 }; px < nFieldWidth - 1; ++px)
						{
							bLine &= (pField[(nCurrentY + py) * nFieldWidth + px]) != 0;

						}

						if (bLine)
						{
							for (int px{ 1 }; px < nFieldWidth - 1; ++px)
							{
								pField[(nCurrentY + py) * nFieldWidth + px] = 8;
							}

							vLines.push_back(nCurrentY + py);
						}
					}
				}

				nScore += 25;
				if (!vLines.empty())
				{
					nScore += (1 << vLines.size()) * 100;
				}

				// Choose the next piece
				nCurrentX = nFieldWidth / 2;
				nCurrentY = 0;
				nCurrentRotation = 0;
				nCurrentPiece = rand() % 7;

				// If the piece does not fit
				bGameOver = !doesPieceFit(nCurrentPiece, nCurrentRotation, nCurrentX, nCurrentY);
			}
		}

		// Render Output


		// Draw Field
		for (int x{ 0 }; x < nFieldWidth; ++x)
		{
			for (int y{ 0 }; y < nFieldHeight; ++y)
			{
				screen[(y + 2) * nScreenWidth + (x + 2)] = L" ABCDEFG=#"[pField[y * nFieldWidth + x]];
			}
		}

		// Draw Current Piece
		for (int px{ 0 }; px < 4; ++px)
		{
			for (int py{ 0 }; py < 4; ++py)
			{
				if (tetromino[nCurrentPiece][Rotate(px, py, nCurrentRotation)] != L'.') // == L'X'
				{
					screen[(nCurrentY + py + 2) * nScreenWidth + (nCurrentX + px + 2)] = nCurrentPiece + 65;
				}
			}
		}

		// Draw Score 
		// _snwprintf for g++, swprintf_s for VS
		swprintf_s(&screen[2 * nScreenWidth + nFieldWidth + 6], 16, L"SCORE: %8d", nScore);

		if (!vLines.empty())
		{
			WriteConsoleOutputCharacter(hConsole, screen, nScreenWidth * nScreenHeight, { 0, 0 }, &dwBytesWritten);
			std::this_thread::sleep_for(std::chrono::milliseconds(400));

			for (auto &v : vLines)
			{
				for (int px{ 1 }; px < nFieldWidth - 1; ++px)
				{
					for (int py{ v }; py > 0; --py)
					{
						pField[py * nFieldWidth + px] = pField[(py - 1) * nFieldWidth + px];
					}

					pField[px] = 0;
				}
			}

			vLines.clear();
		}

		// Display Frame
		WriteConsoleOutputCharacter(hConsole, screen, nScreenWidth * nScreenHeight, { 0, 0 }, &dwBytesWritten);
	}

	// Game Over
	CloseHandle(hConsole);
	std::cout << "Game Over! Score: " << nScore << '\n';
	system("pause");

	return 0;
}