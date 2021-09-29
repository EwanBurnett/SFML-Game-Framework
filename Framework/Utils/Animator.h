#pragma once
#include <SFML/Graphics.hpp>
#include "../Managers/ResourceManager.h"
#include <list>
#include <string>

class Animator
{
public:
	struct Animation
	{
		std::string m_name;
		std::string m_textureName;
		std::vector<sf::IntRect> m_frames;
		sf::Time m_duration;
		bool m_isLooping;

		Animation(std::string const& name, std::string const& textureName, sf::Time const& duration, bool looping) :
			m_name(name),
			m_textureName(textureName),
			m_duration(duration),
			m_isLooping(looping)
		{}

		//Add Frames Horizontally
		void AddFrames(sf::Vector2i const& startFrom, sf::Vector2i const& frameSize, unsigned int frames)
		{
			sf::Vector2i currentFrame = startFrom;
			currentFrame.x *= frameSize.x;
			currentFrame.y *= frameSize.y;

			for (unsigned int i = 0; i < frames; i++) {
				//Add current frame from position and frame size
				m_frames.push_back(sf::IntRect(currentFrame.x, currentFrame.y, frameSize.x, frameSize.y));
				//Advance current frame
				currentFrame.x += frameSize.x;
				//currentFrame.y += frameSize.y; //<-- this might not work
			}
		}
	};

	Animator(sf::Sprite& sprite);

	Animator::Animation& CreateAnimation(std::string const& name, std::string const& textureName, sf::Time const& duration, bool looping = false); // Creates an animation
																																			   
	void Update(sf::Time const& dt);

	bool SwitchAnimation(std::string const& name); //Changes between animations, with their name as a reference.
	std::string GetCurrentAnimationName() const; //Gets the name of the animation currently playing

private:
	//Returns the animation with the passed name
	//Returns nullptr if no animation is found
	Animator::Animation* FindAnimation(std::string const& name);

	void SwitchAnimation(Animator::Animation* animation); //Overload for SwitchAnimation()

	//Reference to the sprite
	sf::Sprite& m_Sprite;
	sf::Time m_CurrentTime;
	std::list<Animator::Animation> m_Animations;
	Animator::Animation* m_CurrentAnimation;
};

