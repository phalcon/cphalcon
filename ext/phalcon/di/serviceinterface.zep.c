
#ifdef HAVE_CONFIG_H
#include "../../ext_config.h"
#endif

#include <php.h>
#include "../../php_ext.h"
#include "../../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


/**
 * Phalcon\Di\ServiceInterface
 *
 * Represents a service in the services container
 */
ZEPHIR_INIT_CLASS(Phalcon_Di_ServiceInterface) {

	ZEPHIR_REGISTER_INTERFACE(Phalcon\\Di, ServiceInterface, phalcon, di_serviceinterface, phalcon_di_serviceinterface_method_entry);

	return SUCCESS;

}

/**
 * Returns the service's name
 *
 * @param string
 */
ZEPHIR_DOC_METHOD(Phalcon_Di_ServiceInterface, getName);

/**
 * Sets if the service is shared or not
 */
ZEPHIR_DOC_METHOD(Phalcon_Di_ServiceInterface, setShared);

/**
 * Check whether the service is shared or not
 */
ZEPHIR_DOC_METHOD(Phalcon_Di_ServiceInterface, isShared);

/**
 * Set the service definition
 *
 * @param mixed definition
 */
ZEPHIR_DOC_METHOD(Phalcon_Di_ServiceInterface, setDefinition);

/**
 * Returns the service definition
 *
 * @return mixed
 */
ZEPHIR_DOC_METHOD(Phalcon_Di_ServiceInterface, getDefinition);

/**
 * Resolves the service
 *
 * @param array parameters
 * @param \Phalcon\DiInterface dependencyInjector
 * @return mixed
 */
ZEPHIR_DOC_METHOD(Phalcon_Di_ServiceInterface, resolve);

/**
 * Changes a parameter in the definition without resolve the service
 */
ZEPHIR_DOC_METHOD(Phalcon_Di_ServiceInterface, setParameter);

/**
 * Restore the internal state of a service
 */
ZEPHIR_DOC_METHOD(Phalcon_Di_ServiceInterface, __set_state);

