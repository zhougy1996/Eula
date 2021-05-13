#include "Eula.h"
class Sandbox : public Eula::Application
{
public:
    Sandbox()
    {

    }

    ~Sandbox()
    {

    }


};

Eula::Application* Eula::CreateApplication()
{
    return new Sandbox();
}