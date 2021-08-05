#include <KeplerEngine/Core/EntryPoint.h>
#include <KeplerEngine/Core/Application.h>

class Program : public KE::Application
{
public:

	Program() {}
	~Program() {}
};

std::unique_ptr<KE::Application> KE::CreateApplication()
{
	return std::make_unique<Program>();
}