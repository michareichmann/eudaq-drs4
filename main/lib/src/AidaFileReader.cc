#include <iostream>
#include <list>
#include <iostream>
#include "jsoncons/json.hpp"
#include "eudaq/JSONimpl.hh"
#include "eudaq/FileNamer.hh"
#include "eudaq/AidaPacket.hh"
#include "eudaq/Logger.hh"
#include "eudaq/FileSerializer.hh"
#include "eudaq/AidaFileReader.hh"


namespace eudaq {

  AidaFileReader::AidaFileReader(const std::string & file )
    : m_filename( file ), m_runNumber( -1 )
  {
	  m_des = new FileDeserializer( m_filename );
	  m_des->read( m_json_config );
  }

  AidaFileReader::~AidaFileReader() {
	  if ( m_des )
		  delete m_des;
  }

  bool AidaFileReader::readNext() {
	  if ( !m_des || !m_des->HasData() )
		  return false;
	  m_packet = PacketFactory::Create( *m_des );
	  return true;
  }

  std::string AidaFileReader::getJsonPacketInfo() {
	  if ( !m_packet )
		  return "";

	  auto json = m_packet->toJson( AidaPacket::JSON_HEADER | AidaPacket::JSON_METADATA | AidaPacket::JSON_DATA );
	  return json->to_string();
  }


  std::vector<uint64_t> AidaFileReader::getData() {
	  return m_packet->GetData();
  }


}
