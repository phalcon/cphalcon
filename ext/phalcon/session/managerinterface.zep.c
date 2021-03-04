
#ifdef HAVE_CONFIG_H
#include "../../ext_config.h"
#endif

#include <php.h>
#include "../../php_ext.h"
#include "../../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


/**
 * This file is part of the Phalcon.
 *
 * (c) Phalcon Team <team@phalcon.com>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */
/**
 * Phalcon\Session
 *
 * Interface for the Phalcon\Session\Manager
 */
ZEPHIR_INIT_CLASS(Phalcon_Session_ManagerInterface) {

	ZEPHIR_REGISTER_INTERFACE(Phalcon\\Session, ManagerInterface, phalcon, session_managerinterface, phalcon_session_managerinterface_method_entry);

	zephir_declare_class_constant_long(phalcon_session_managerinterface_ce, SL("SESSION_ACTIVE"), 2);

	zephir_declare_class_constant_long(phalcon_session_managerinterface_ce, SL("SESSION_DISABLED"), 0);

	zephir_declare_class_constant_long(phalcon_session_managerinterface_ce, SL("SESSION_NONE"), 1);

	return SUCCESS;

}

/**
 * Alias: Gets a session variable from an application context
 */
ZEPHIR_DOC_METHOD(Phalcon_Session_ManagerInterface, __get);
/**
 * Alias: Check whether a session variable is set in an application context
 */
ZEPHIR_DOC_METHOD(Phalcon_Session_ManagerInterface, __isset);
/**
 * Alias: Sets a session variable in an application context
 */
ZEPHIR_DOC_METHOD(Phalcon_Session_ManagerInterface, __set);
/**
 * Alias: Removes a session variable from an application context
 */
ZEPHIR_DOC_METHOD(Phalcon_Session_ManagerInterface, __unset);
/**
 * Check whether the session has been started
 */
ZEPHIR_DOC_METHOD(Phalcon_Session_ManagerInterface, exists);
/**
 * Destroy/end a session
 */
ZEPHIR_DOC_METHOD(Phalcon_Session_ManagerInterface, destroy);
/**
 * Gets a session variable from an application context
 */
ZEPHIR_DOC_METHOD(Phalcon_Session_ManagerInterface, get);
/**
 * Returns the session id
 */
ZEPHIR_DOC_METHOD(Phalcon_Session_ManagerInterface, getId);
/**
 * Returns the stored session adapter
 */
ZEPHIR_DOC_METHOD(Phalcon_Session_ManagerInterface, getAdapter);
/**
 * Returns the name of the session
 */
ZEPHIR_DOC_METHOD(Phalcon_Session_ManagerInterface, getName);
/**
 * Get internal options
 */
ZEPHIR_DOC_METHOD(Phalcon_Session_ManagerInterface, getOptions);
/**
 * Check whether a session variable is set in an application context
 */
ZEPHIR_DOC_METHOD(Phalcon_Session_ManagerInterface, has);
/**
 * Removes a session variable from an application context
 */
ZEPHIR_DOC_METHOD(Phalcon_Session_ManagerInterface, remove);
/**
 * Sets a session variable in an application context
 */
ZEPHIR_DOC_METHOD(Phalcon_Session_ManagerInterface, set);
/**
 * Set the adapter for the session
 */
ZEPHIR_DOC_METHOD(Phalcon_Session_ManagerInterface, setAdapter);
/**
 * Set session Id
 */
ZEPHIR_DOC_METHOD(Phalcon_Session_ManagerInterface, setId);
/**
 * Set the session name. Throw exception if the session has started
 * and do not allow poop names
 *
 * @throws InvalidArgumentException
 */
ZEPHIR_DOC_METHOD(Phalcon_Session_ManagerInterface, setName);
/**
 * Sets session's options
 */
ZEPHIR_DOC_METHOD(Phalcon_Session_ManagerInterface, setOptions);
/**
 * Returns the status of the current session.
 */
ZEPHIR_DOC_METHOD(Phalcon_Session_ManagerInterface, status);
/**
 * Starts the session (if headers are already sent the session will not be
 * started)
 */
ZEPHIR_DOC_METHOD(Phalcon_Session_ManagerInterface, start);
/**
 * Regenerates the session id using the adapter.
 */
ZEPHIR_DOC_METHOD(Phalcon_Session_ManagerInterface, regenerateId);
