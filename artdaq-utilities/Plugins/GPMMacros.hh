#ifndef ARTDAQ_UTILITIES_ARTDAQ_UTILITIES_PLUGINS_GPMMACROS_HH_
#define ARTDAQ_UTILITIES_ARTDAQ_UTILITIES_PLUGINS_GPMMACROS_HH_

#include "artdaq-utilities/Plugins/GPMPublisher.hh"
#include "artdaq-utilities/Plugins/GPMSubscriber.hh"

#include "cetlib/compiler_macros.h"
#include "fhiclcpp/fwd.h"

#include <memory>
#include <string>

namespace artdaq {
/**
 * \brief Make a MetricPlugin instance, loading the plugin if necessary
 * \param ps ParameterSet used to configure the MetricPlugin instance
 * \param application_name Name of the application sending metrics
 * \return A std::unique_ptr<artdaq::MetricPlugin> to the new instance
 */
typedef std::unique_ptr<artdaq::GPMPublisher> makeFunc_t(fhicl::ParameterSet const& ps, std::string const& application_name);

// typedef std::unique_ptr<artdaq::GPMSubscriber> makeFunc_t(fhicl::ParameterSet const& ps, std::string const& application_name);
}  // namespace artdaq

#ifndef EXTERN_C_FUNC_DECLARE_START
// NOLINTNEXTLINE(build/define_used)
#define EXTERN_C_FUNC_DECLARE_START extern "C" {
#endif

// NOLINTNEXTLINE
#define DEFINE_GPM_PUBLISHER(klass)                                                    \
	EXTERN_C_FUNC_DECLARE_START                                                        \
	std::unique_ptr<artdaq::GPMPublisher>                                              \
	make(fhicl::ParameterSet const& ps, std::string const& application_name)           \
	{                                                                                  \
		return std::unique_ptr<artdaq::GPMPublisher>(new klass(ps, application_name)); \
	}                                                                                  \
	}

// NOLINTNEXTLINE
#define DEFINE_GPM_SUBSCRIBER(klass)                                                    \
	EXTERN_C_FUNC_DECLARE_START                                                         \
	std::unique_ptr<artdaq::GPMSubscriber>                                              \
	make(fhicl::ParameterSet const& ps, std::string const& application_name)            \
	{                                                                                   \
		return std::unique_ptr<artdaq::GPMSubscriber>(new klass(ps, application_name)); \
	}                                                                                   \
	}

#endif  // ARTDAQ_UTILITIES_ARTDAQ_UTILITIES_PLUGINS_GPMMACROS_HH_
