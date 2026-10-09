#ifndef ARTDAQ_UTILITIES_ARTDAQ_UTILITIES_PLUGINS_METRICMACROS_HH_
#define ARTDAQ_UTILITIES_ARTDAQ_UTILITIES_PLUGINS_METRICMACROS_HH_

#include "artdaq-utilities/Plugins/MetricPlugin.hh"
namespace fhicl {
class ParameterSet;
}  // namespace fhicl
#include "cetlib/compiler_macros.h"

#include <memory>
#include <string>

namespace artdaq {
/**
 * \brief Make a MetricPlugin instance, loading the plugin if necessary
 * \param ps ParameterSet used to configure the MetricPlugin instance
 * \param app_name Name of the application sending metrics
 * \return A std::unique_ptr<artdaq::MetricPlugin> to the new instance
 */
typedef std::unique_ptr<artdaq::MetricPlugin> makeFunc_t(fhicl::ParameterSet const& ps, std::string const& app_name);
}  // namespace artdaq

#ifndef EXTERN_C_FUNC_DECLARE_START
// NOLINTNEXTLINE
#define EXTERN_C_FUNC_DECLARE_START extern "C" {
#endif

// NOLINTNEXTLINE
#define DEFINE_ARTDAQ_METRIC(klass)                                                                  \
	EXTERN_C_FUNC_DECLARE_START                                                                      \
	std::unique_ptr<artdaq::MetricPlugin>                                                            \
	make(fhicl::ParameterSet const& ps, std::string const& app_name, std::string const& metric_name) \
	{                                                                                                \
		return std::unique_ptr<artdaq::MetricPlugin>(new klass(ps, app_name, metric_name));          \
	}                                                                                                \
	}

#endif  // ARTDAQ_UTILITIES_ARTDAQ_UTILITIES_PLUGINS_METRICMACROS_HH_
