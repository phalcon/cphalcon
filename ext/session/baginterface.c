
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

#include "session/baginterface.h"
#include "kernel/main.h"

zend_class_entry *phalcon_session_baginterface_ce;

static const zend_function_entry phalcon_session_baginterface_method_entry[] = {
	PHP_ABSTRACT_ME(Phalcon_Session_BagInterface, initialize, NULL)
	PHP_ABSTRACT_ME(Phalcon_Session_BagInterface, destroy, NULL)
	PHP_ABSTRACT_ME(Phalcon_Session_BagInterface, set, arginfo_phalcon_session_baginterface_set)
	PHP_ABSTRACT_ME(Phalcon_Session_BagInterface, get, arginfo_phalcon_session_baginterface_get)
	PHP_ABSTRACT_ME(Phalcon_Session_BagInterface, has, arginfo_phalcon_session_baginterface_has)
	PHP_ABSTRACT_ME(Phalcon_Session_BagInterface, remove, arginfo_phalcon_session_baginterface_remove)
	PHP_FE_END
};

/**
 * Phalcon\Session\BagInterface initializer
 */
PHALCON_INIT_CLASS(Phalcon_Session_BagInterface){

	PHALCON_REGISTER_INTERFACE(Phalcon\\Session, BagInterface, session_baginterface, phalcon_session_baginterface_method_entry);

	return SUCCESS;
}

/**
 * Initializes the session bag. This method must not be called directly, the class calls it when its internal data is accesed
 */
PHALCON_DOC_METHOD(Phalcon_Session_BagInterface, initialize);

/**
 * Destroyes the session bag
 */
PHALCON_DOC_METHOD(Phalcon_Session_BagInterface, destroy);

/**
 * Setter of values
 *
 * @param string $property
 * @param string $value
 */
PHALCON_DOC_METHOD(Phalcon_Session_BagInterface, set);

/**
 * Getter of values
 *
 * @param string $property
 * @param mixed $defaultValue
 * @return mixed
 */
PHALCON_DOC_METHOD(Phalcon_Session_BagInterface, get);

/**
 * Isset property
 *
 * @param string $property
 * @return boolean
 */
PHALCON_DOC_METHOD(Phalcon_Session_BagInterface, has);

/**
 * Unset property
 *
 * @param string $property
 */
PHALCON_DOC_METHOD(Phalcon_Session_BagInterface, remove);
