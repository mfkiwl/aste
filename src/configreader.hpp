#pragma once

#include <fstream>
#include <iostream>
#include <string>
#include <vector>

#include <mpi.h>

#include "json.hpp"
#include "logger.hpp"
#include "mesh.hpp"

#include "precice/Participant.hpp"

using json = nlohmann::json;

namespace aste {
/**
 * @brief ASTE Interface is used for store meshes and related data about a mesh.
 *
 */
struct asteInterface {
  std::string              meshName;         // Meshname in preCICE config
  std::string              meshFilePrefix;   // Meshfile (.vtk/vtu) prefix
  std::vector<std::string> writeVectorNames; // Datanames of write type vectors
  std::vector<std::string> readVectorNames;  // Datanames of read type vectors
  std::vector<std::string> writeScalarNames; // Datanames of write type scalars
  std::vector<std::string> readScalarNames;  // Datanames of read type scalars
  std::vector<MeshName>    meshes;           // A list of meshfiles
  Mesh                     mesh;             // Mesh data structure in ASTE
};

/**
 * @brief ASTE Configuration class which contain current configuration for ASTE
 *
 */
class asteConfig {
public:
  /**
   * @brief Parser for ASTE config file
   *
   * @param asteConfigFile
   */
  void                       load(const std::string &asteConfigFile);
  std::string                preciceConfigFilename; // preCICE config file
  std::vector<asteInterface> asteInterfaces;        // Vector of ASTE interfaces(meshes)
  std::string                participantName;       // The name of participant in preCICE config
  int                        startdt;
};

} // namespace aste
