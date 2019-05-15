// Copyright 2014 GSI, Inc. All rights reserved.
//
//
//

// DDS
#include "SMFWChannel.h"
#include "UserDefaults.h"

using namespace dds;
using namespace std;
using namespace dds::protocol_api;

CSMFWChannel::CSMFWChannel(boost::asio::io_context& _service,
                           const std::string& _inputName,
                           const std::string& _outputName,
                           uint64_t _protocolHeaderID,
                           protocol_api::EMQOpenType _inputOpenType,
                           protocol_api::EMQOpenType _outputOpenType)
    : CBaseSMChannelImpl<CSMFWChannel>(
          _service, _inputName, _outputName, _protocolHeaderID, _inputOpenType, _outputOpenType)
{
    // Leader adds output for itself
    this->addOutput(_protocolHeaderID,
                    user_defaults_api::CUserDefaults::instance().getSMAgentInputName(),
                    EMQOpenType::OpenOrCreate);
}

CSMFWChannel::~CSMFWChannel()
{
    removeMessageQueue();
}

bool CSMFWChannel::on_rawMessage(CProtocolMessage::protocolMessagePtr_t _currentMsg, const SSenderInfo& _sender)
{
    return false;
}
