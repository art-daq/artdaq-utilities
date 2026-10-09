#ifndef ARTDAQ_UTILITIES_ARTDAQ_UTILITIES_PLUGINS_MAKEGPMPLUGINS_HH_
#define ARTDAQ_UTILITIES_ARTDAQ_UTILITIES_PLUGINS_MAKEGPMPLUGINS_HH_

// Using LibraryManager, find the correct library and return an instance
// of the specified generator.

#include "fhiclcpp/fwd.h"

#include <memory>
#include <string>

/**
 * \brief The artdaq namespace
 */
namespace artdaq {
class GPMPublisher;
class GPMSubscriber;

/**
 * \brief Load a given GPMPublisher plugin and return a pointer to it
 * \param generator_plugin_spec Name of the GPMPublisher plugin
 * \param ps ParameterSet with which to configure the GPMPublisher
 * \param application_name Application name of the calling application
 * \return std::unique_ptr to the new GPMPublisher instance
 */
std::unique_ptr<GPMPublisher>
makeGPMPublisher(std::string const& generator_plugin_spec,
                 fhicl::ParameterSet const& ps, std::string const& application_name);

/**
 * \brief Load a given GPMSubscriber plugin and return a pointer to it
 * \param generator_plugin_spec Name of the GPMSubscriber plugin
 * \param ps ParameterSet with which to configure the GPMSubscriber
 * \param application_name Application name of the calling application
 * \return std::unique_ptr to the new GPMSubscriber instance
 */
std::unique_ptr<GPMSubscriber>
makeGPMSubscriber(std::string const& generator_plugin_spec,
                  fhicl::ParameterSet const& ps, std::string const& application_name);
}  // namespace artdaq
#endif  // ARTDAQ_UTILITIES_ARTDAQ_UTILITIES_PLUGINS_MAKEGPMPLUGINS_HH_
