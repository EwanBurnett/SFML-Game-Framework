#include "Animator.h"

Animator::Animator(sf::Sprite& sprite) :
	m_Sprite(sprite), m_CurrentTime(), m_CurrentAnimation(nullptr) //Initialises all of our data
{
}

Animator::Animation& Animator::CreateAnimation(std::string const& name, std::string const& textureName, sf::Time const& duration, bool looping)
{
	m_Animations.push_back(
		Animator::Animation(name, textureName, duration, looping));

	//If we don't have any other animations, use that as the current animation
	if (m_CurrentAnimation == nullptr)
		SwitchAnimation(&m_Animations.back());

	return m_Animations.back();
}

void Animator::Update(sf::Time const& dt)
{
	//If we don't have any animations, return
	if (m_CurrentAnimation == nullptr)
		return;

	m_CurrentTime += dt;

	///Get the current animation frame
	float scaledTime = (m_CurrentTime.asSeconds() / m_CurrentAnimation->m_duration.asSeconds());
	int numFrames = m_CurrentAnimation->m_frames.size();
	int currentFrame = static_cast<int>(scaledTime * numFrames);

	//If the animation is looping, calculate the correct frame
	if (m_CurrentAnimation->m_isLooping)
		currentFrame %= numFrames;
	else if (currentFrame >= numFrames) //if the current frame is greater than the number of frames
		currentFrame = numFrames - 1; //Show the last frame.

	//Sets the texture rect, depending on the frame.
	m_Sprite.setTextureRect(m_CurrentAnimation->m_frames[currentFrame]);
}

bool Animator::SwitchAnimation(std::string const& name)
{
	auto animation = FindAnimation(name);
	if (animation != nullptr) {
		SwitchAnimation(animation);
		return true;
	}

	return false;
}

std::string Animator::GetCurrentAnimationName() const
{
	if (m_CurrentAnimation != nullptr)
		return m_CurrentAnimation->m_name;

	return "";
}

Animator::Animation* Animator::FindAnimation(std::string const& name)
{
	for (auto it = m_Animations.begin(); it != m_Animations.end(); ++it) {
		if (it->m_name == name)
			return &*it; //Loops over each animation in the list, trying to find the animation.
	}
	return nullptr;
}

void Animator::SwitchAnimation(Animator::Animation* animation)
{
	//Change the sprite texture
	if (animation != nullptr)
		m_Sprite.setTexture(ResourceManager::GetTexture(animation->m_textureName));

	m_CurrentAnimation = animation;
	m_CurrentTime = sf::Time::Zero; //Resets the time
}
