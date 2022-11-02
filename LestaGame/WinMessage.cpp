#include "WinMessage.h"

WinMessage::WinMessage()
{
	win_texture.loadFromFile("./../LestaGame/images/you_win_message.png");
	win_sprite.setTexture(win_texture);
	win_sprite.setPosition(-20.f, -20.f);

	press_any_texture.loadFromFile("./../LestaGame/images/press_message.png");
	press_any_sprite.setTexture(press_any_texture);
	press_any_sprite.setPosition(195.f, 650.f);

	invitation_texture.loadFromFile("./../LestaGame/images/invitation_message.png");
	invitation_sprite.setTexture(invitation_texture);
	invitation_sprite.setPosition(155.f, -5.f);

	font.loadFromFile("./../LestaGame/font/calibri.ttf");
	info_message.setFont(font); // select the font
	info_message.setString("use \"left/right/up/down\" buttons to move selector");// set the string to display
	info_message.setCharacterSize(28); // in pixels
	info_message.setFillColor(Color::Blue); // set the color
	info_message.setStyle(Text::Bold);// set the text style
	info_message.move(20, 12);
	info_message1 = info_message;
	info_message.setString("use \"space\" button to interact");// set the string to display
	info_message1.setPosition(20, 42);

	white_rect.move(15, 15);
	white_rect.setFillColor(Color(160, 160, 160));
	white_rect.setSize(Vector2f(640, 66));

}

void WinMessage::TextBlink(Sprite& sprite, uint32_t speed) 
{
	sprite.setColor(Color(255, 255, 255, blink));

	if (blink_state == BlinkState::Falling)
	{
		blink -= speed;
		if (blink <= 50)
		{
			blink_state = BlinkState::Growing;
		}
	}

	if (blink_state == BlinkState::Growing)
	{
		blink += speed;
		if (blink >= 250)
		{
			blink_state = BlinkState::Falling;
		}
	}
}

void WinMessage::DrawMessage(RenderWindow& window)
{
	//TextBlink(this->press_any_sprite, 1);
	window.draw(press_any_sprite);
	window.draw(win_sprite);
}

void WinMessage::DrawInvitationMessage(RenderWindow& window)
{
	window.draw(white_rect);
	window.draw(info_message);
	window.draw(info_message1);
	//window.draw(invitation_sprite);
}