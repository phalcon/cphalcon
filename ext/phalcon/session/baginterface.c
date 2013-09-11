
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
 * Phalcon\Session\BagInterface
 *
 * Interface for Phalcon\Session\Bag
 */
ZEPHIR_INIT_CLASS(Phalcon_Session_BagInterface) {

	ZEPHIR_REGISTER_INTERFACE(Phalcon\\Session, BagInterface, phalcon, session_baginterface, phalcon_session_baginterface_method_entry);


	return SUCCESS;

}

/**
 * Initializes the session bag. This method must not be called directly, the class calls it when its internal data is accesed
 */
ZEPHIR_DOC_METHOD(Phalcon_Session_BagInterface, initialize);

/**
 * Destroyes the session bag
 */
ZEPHIR_DOC_METHOD(Phalcon_Session_BagInterface, destroy);

/**
 * Setter of values
 *
 * @param string property
 * @param string value
 */
ZEPHIR_DOC_METHOD(Phalcon_Session_BagInterface, set);

/**
 * Getter of values
 *
 * @param string property
 * @param mixed defaultValue
 * @return mixed
 */
ZEPHIR_DOC_METHOD(Phalcon_Session_BagInterface, get);

/**
 * Isset property
 *
 * @param string property
 * @return boolean
 */
ZEPHIR_DOC_METHOD(Phalcon_Session_BagInterface, has);

/**
 * Setter of values
 *
 * @param string property
 * @param string value
 */
ZEPHIR_DOC_METHOD(Phalcon_Session_BagInterface, __set);

/**
 * Getter of values
 *
 * @param string property
 * @return mixed
 */
ZEPHIR_DOC_METHOD(Phalcon_Session_BagInterface, __get);

/**
 * Isset property
 *
 * @param string property
 * @return boolean
 */
ZEPHIR_DOC_METHOD(Phalcon_Session_BagInterface, __isset);

