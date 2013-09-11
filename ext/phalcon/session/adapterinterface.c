
#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"
#include "php_test.h"
#include "test.h"

#include "kernel/main.h"


/*
 +------------------------------------------------------------------------+
 | Phalcon Framework                                                      |
 +------------------------------------------------------------------------+
 | Copyright (c) 2011-2013 Phalcon Team (http://www.phalconphp.com)       |
 +------------------------------------------------------------------------+
 | This source file is subject to the New BSD License that is bundled     |
 | with this package in the file docs/LICENSE.txt.                        |
 |                                                                        |
 | If you did not receive a copy of the license and are unable to         |
 | obtain it through the world-wide-web, please send an email             |
 | to license@phalconphp.com so we can send you a copy immediately.       |
 +------------------------------------------------------------------------+
 | Authors: Andres Gutierrez <andres@phalconphp.com>                      |
 |          Eduar Carvajal <eduar@phalconphp.com>                         |
 +------------------------------------------------------------------------+
 */
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
 * Phalcon\Session construtor
 *
 * @param array options
 */
ZEPHIR_DOC_METHOD(Phalcon_Session_AdapterInterface, __construct);
/**
 * Starts session, optionally using an adapter
 *
 * @param array options
 */
ZEPHIR_DOC_METHOD(Phalcon_Session_AdapterInterface, start);
/**
 * Sets session options
 *
 * @param array options
 */
ZEPHIR_DOC_METHOD(Phalcon_Session_AdapterInterface, setOptions);
/**
 * Get internal options
 *
 * @return array
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
 *
 * @param string index
 * @return boolean
 */
ZEPHIR_DOC_METHOD(Phalcon_Session_AdapterInterface, has);
/**
 * Removes a session variable from an application context
 *
 * @param string index
 */
ZEPHIR_DOC_METHOD(Phalcon_Session_AdapterInterface, remove);
/**
 * Returns active session id
 *
 * @return string
 */
ZEPHIR_DOC_METHOD(Phalcon_Session_AdapterInterface, getId);
/**
 * Check whether the session has been started
 *
 * @return boolean
 */
ZEPHIR_DOC_METHOD(Phalcon_Session_AdapterInterface, isStarted);
/**
 * Destroys the active session
 *
 * @return boolean
 */
ZEPHIR_DOC_METHOD(Phalcon_Session_AdapterInterface, destroy);
