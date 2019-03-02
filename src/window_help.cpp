/*
 * This file is part of EasyRPG Player.
 *
 * EasyRPG Player is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * EasyRPG Player is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with EasyRPG Player. If not, see <http://www.gnu.org/licenses/>.
 */

// Headers
#include "window_help.h"
#include "bitmap.h"
#include "font.h"

Window_Help::Window_Help(int ix, int iy, int iwidth, int iheight) :
	Window_Base(ix, iy, iwidth, iheight),
	align(Text::AlignLeft) {

	SetContents(Bitmap::Create(width - 16, height - 16));

	contents->Clear();
}

void Window_Help::SetText(std::string text,	Text::Alignment align) {
	if (this->text != text || this->align != align) {
		contents->Clear();

		this->text = text;
		this->align = align;

		int x = 0;
		std::string::size_type pos = 0;
		std::string::size_type nextpos = 0;
		while (nextpos != std::string::npos) {
			nextpos = text.find(' ', pos);
			auto segment = text.substr(pos, nextpos - pos);
			contents->TextDraw(x, 2, Font::ColorDefault, segment, align);
			x += Font::Default()->GetSize(segment).width;

			if (nextpos != std::string::npos) {
				x += Font::Default()->GetSize(" ").width / 2;
				pos = nextpos + 1;
			}
		}
	}
}

void Window_Help::Clear() {
	this->text = "";
	contents->Clear();
}
