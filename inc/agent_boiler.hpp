#ifndef AGENT_BOILER_HPP
#define AGENT_BOILER_HPP

#include "protocol.hpp"
#include "agent_controler.hpp"

#include <boost/asio.hpp>

using boost::asio::ip::tcp;

namespace sb {

class AgentBoiler : public AgentControler{
public: 
    AgentBoiler();

    ~AgentBoiler() noexcept = default;

    unsigned short port() const override;
    unsigned short sender_port() const override;
    ProtocolType protocol() const override;
    bool check_event(Protocol const& a_event, Protocol& a_command) override;
    int event_type() const override;
    
private:
    unsigned short m_port;
    unsigned short m_sender_port;
    int m_event_type;
};

extern "C" AgentControler* create_agent() {
    return new AgentBoiler();
}

}//namespace sb

#endif // AGENT_BOILER_HPP
