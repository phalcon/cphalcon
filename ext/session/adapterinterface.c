
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

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"
#include "php_phalcon.h"
#include "phalcon.h"

#include "kernel/main.h"

/**
 * Phalcon\Session\AdapterInterface initializer
 */
PHALCON_INIT_CLASS(Phalcon_Session_AdapterInterface){

	PHALCON_REGISTER_INTERFACE(Phalcon\\Session, AdapterInterface, session_adapterinterface, phalcon_session_adapterinterface_method_entry);

	return SUCCESS;
}

/**
 * Phalcon\Session construtor
 *
 * @param array $options
 */
PHALCON_DOC_METHOD(Phalcon_Session_AdapterInterface, __construct);

/**
 * Starts session, optionally using an adapter
 *
 * @param array $options
 */
PHALCON_DOC_METHOD(Phalcon_Session_AdapterInterface, start);

/**
 * Sets session options
 *
 * @param array $options
 */
PHALCON_DOC_METHOD(Phalcon_Session_AdapterInterface, setOptions);

/**
 * Get internal options
 *
 * @return array
 */
PHALCON_DOC_METHOD(Phalcon_Session_AdapterInterface, getOptions);

/**
 * Gets a session variable from an application context
 *
 * @param string $index
 * @param mixed $defaultValue
 * @return mixed
 */
PHALCON_DOC_METHOD(Phalcon_Session_AdapterInterface, get);

/**
 * Sets a session variable in an application context
 *
 * @param string $index
 * @param string $value
 */
PHALCON_DOC_METHOD(Phalcon_Session_AdapterInterface, set);

/**
 * Check whether a session variable is set in an application context
 *
 * @param string $index
 * @return boolean
 */
PHALCON_DOC_METHOD(Phalcon_Session_AdapterInterface, has);

/**
 * Removes a session variable from an application context
 *
 * @param string $index
 */
PHALCON_DOC_METHOD(Phalcon_Session_AdapterInterface, remove);

/**
 * Returns active session id
 *
 * @return string
 */
PHALCON_DOC_METHOD(Phalcon_Session_AdapterInterface, getId);

/**
 * Check whether the session has been started
 *
 * @return boolean
 */
PHALCON_DOC_METHOD(Phalcon_Session_AdapterInterface, isStarted);

/**
 * Destroys the active session
 *
 * @return boolean
 */
PHALCON_DOC_METHOD(Phalcon_Session_AdapterInterface, destroy);

