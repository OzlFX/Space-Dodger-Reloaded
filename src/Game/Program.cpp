#include <KeplerEngine/Core/EntryPoint.h>
#include <KeplerEngine/Core/Application.h>
#include <KeplerEngine/Core/KeplerEngine.h>

/* We want to allow the client program to create objects and scenes using the layer system. Create scene in client??? -> Scene pushed to scene manager through system 
   and added to the layer as a layer 'component' */

class Program : public KE::Application
{
public:

	/// Consider using a layer system to push game content to the engine
	Program()
	{
		
	}

	~Program() {}
};

std::unique_ptr<KE::Application> KE::CreateApplication()
{
	return std::make_unique<Program>();
}