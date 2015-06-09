
#ifdef HAVE_CONFIG_H
#include "../../ext_config.h"
#endif

#include <php.h>
#include "../../php_ext.h"
#include "../../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


/**
 * Phalcon\Session\AdapterInterface
 *
 * Interface for Phalcon\Session adapters
 */
ZEPHIR_INIT_CLASS(Phalcon_Session_AdapterInterface) {

	ZEPHIR_REGISTER_INTERFACE(Phalcon\\Session, AdapterInterface, phalcon, session_adapterinterface, phalcon_session_adapterinterface_method_entry);

	return SUCCESS;

}

/**
 * Starts session, optionally using an adapter
 */
ZEPHIR_DOC_METHOD(Phalcon_Session_AdapterInterface, start);

/**
 * Sets session options
 */
ZEPHIR_DOC_METHOD(Phalcon_Session_AdapterInterface, setOptions);

/**
 * Get internal options
 */
ZEPHIR_DOC_METHOD(Phalcon_Session_AdapterInterface, getOptions);

/**
 * Gets a session variable from an application context
 *
 * @param string index
 * @param mixed defaultValue
 * @return mixed
 */
ZEPHIR_DOC_METHOD(Phalcon_Session_AdapterInterface, get);

/**
 * Sets a session variable in an application context
 *
 * @param string index
 * @param string value
 */
ZEPHIR_DOC_METHOD(Phalcon_Session_AdapterInterface, set);

/**
 * Check whether a session variable is set in an application context
 */
ZEPHIR_DOC_METHOD(Phalcon_Session_AdapterInterface, has);

/**
 * Removes a session variable from an application context
 */
ZEPHIR_DOC_METHOD(Phalcon_Session_AdapterInterface, remove);

/**
 * Returns active session id
 */
ZEPHIR_DOC_METHOD(Phalcon_Session_AdapterInterface, getId);

/**
 * Check whether the session has been started
 */
ZEPHIR_DOC_METHOD(Phalcon_Session_AdapterInterface, isStarted);

/**
 * Destroys the active session
 */
ZEPHIR_DOC_METHOD(Phalcon_Session_AdapterInterface, destroy);

