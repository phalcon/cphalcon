
/*
  +------------------------------------------------------------------------+
  | Phalcon Framework                                                      |
  +------------------------------------------------------------------------+
  | Copyright (c) 2011-2014 Phalcon Team (http://www.phalconphp.com)       |
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

#include "session/adapterinterface.h"
#include "kernel/main.h"

zend_class_entry *phalcon_session_adapterinterface_ce;

static const zend_function_entry phalcon_session_adapterinterface_method_entry[] = {
	PHP_ABSTRACT_ME(Phalcon_Session_AdapterInterface, start, arginfo_phalcon_session_adapterinterface_start)
	PHP_ABSTRACT_ME(Phalcon_Session_AdapterInterface, setOptions, arginfo_phalcon_session_adapterinterface_setoptions)
	PHP_ABSTRACT_ME(Phalcon_Session_AdapterInterface, getOptions, arginfo_phalcon_session_adapterinterface_getoptions)
	PHP_ABSTRACT_ME(Phalcon_Session_AdapterInterface, get, arginfo_phalcon_session_adapterinterface_get)
	PHP_ABSTRACT_ME(Phalcon_Session_AdapterInterface, set, arginfo_phalcon_session_adapterinterface_set)
	PHP_ABSTRACT_ME(Phalcon_Session_AdapterInterface, has, arginfo_phalcon_session_adapterinterface_has)
	PHP_ABSTRACT_ME(Phalcon_Session_AdapterInterface, remove, arginfo_phalcon_session_adapterinterface_remove)
	PHP_ABSTRACT_ME(Phalcon_Session_AdapterInterface, getId, arginfo_phalcon_session_adapterinterface_getid)
	PHP_ABSTRACT_ME(Phalcon_Session_AdapterInterface, isStarted, arginfo_phalcon_session_adapterinterface_isstarted)
	PHP_ABSTRACT_ME(Phalcon_Session_AdapterInterface, destroy, arginfo_phalcon_session_adapterinterface_destroy)
	PHP_FE_END
};

/**
 * Phalcon\Session\AdapterInterface initializer
 */
PHALCON_INIT_CLASS(Phalcon_Session_AdapterInterface){

	PHALCON_REGISTER_INTERFACE(Phalcon\\Session, AdapterInterface, session_adapterinterface, phalcon_session_adapterinterface_method_entry);

	return SUCCESS;
}

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
