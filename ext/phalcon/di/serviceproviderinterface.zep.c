
#ifdef HAVE_CONFIG_H
#include "../../ext_config.h"
#endif

#include <php.h>
#include "../../php_ext.h"
#include "../../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


/**
 * Phalcon\Di\ServiceProviderInterface
 *
 * Should be implemented by service providers, or such components,
 * which register a service in the service container.
 *
 * <code>
 * namespace Acme;
 *
 * use Phalcon\DiInterface;
 * use Phalcon\Di\ServiceProviderInterface;
 *
 * class SomeServiceProvider implements ServiceProviderInterface
 * {
 *     public function register(DiInterface $di)
 *     {
 *         $di->setShared('service', function () {
 *             // ...
 *         });
 *     }
 * }
 * </code>
 */
ZEPHIR_INIT_CLASS(Phalcon_Di_ServiceProviderInterface) {

	ZEPHIR_REGISTER_INTERFACE(Phalcon\\Di, ServiceProviderInterface, phalcon, di_serviceproviderinterface, phalcon_di_serviceproviderinterface_method_entry);

	return SUCCESS;

}

/**
 * Registers a service provider.
 */
ZEPHIR_DOC_METHOD(Phalcon_Di_ServiceProviderInterface, register);

