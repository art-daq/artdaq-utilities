// Defines the interface that all general-purpose-messaging subscribers in ARTDAQ must implement

#ifndef ARTDAQ_UTILITIES_ARTDAQ_UTILITIES_PLUGINS_GPMSUBSCRIBER_HH_
#define ARTDAQ_UTILITIES_ARTDAQ_UTILITIES_PLUGINS_GPMSUBSCRIBER_HH_

#include "fhiclcpp/ParameterSet.h"

#include <string>

namespace artdaq {
/**
 * \brief The GPMSubscriber class defines the interface that artdaq applications use to publish
 * general-purpose messages.
 */
class GPMSubscriber
{
public:
	explicit GPMSubscriber(fhicl::ParameterSet const& ps, std::string const& application_name)
	    : pset(ps)
	    , application_name_(application_name)
	{
	}

	/**
	 * \brief Default virtual Desctructor
	 */
	virtual ~GPMSubscriber() = default;

	///////////////////////////////////////////////////////////////////////////
	//
	// Interface Functions: These should be reimplemented in plugin classes!
	//
	///////////////////////////////////////////////////////////////////////////

	/**
	 * \brief Binds the subscriber to the specified implementation-specific endpoint.
	 */
	virtual int bind(std::string const&) = 0;

	/**
	 * \brief Publishes the specified text string.
	 */
	virtual int send(std::string const&) = 0;

protected:
	fhicl::ParameterSet pset;       ///< The ParameterSet used to configure the MetricPlugin
	std::string application_name_;  ///< Name of the application which is sending metrics to this plugin
};
}  // End namespace artdaq

#endif  // ARTDAQ_UTILITIES_ARTDAQ_UTILITIES_PLUGINS_GPMSUBSCRIBER_HH_
