
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
 * Phalcon\Session\BagInterface
 *
 * Interface for Phalcon\Session\Bag
 */
ZEPHIR_INIT_CLASS(Phalcon_Session_BagInterface) {

	ZEPHIR_REGISTER_INTERFACE(Phalcon\\Session, BagInterface, phalcon, session_baginterface, phalcon_session_baginterface_method_entry);

	return SUCCESS;

}

/**
 * Getter of values
 */
ZEPHIR_DOC_METHOD(Phalcon_Session_BagInterface, __get);

/**
 * Isset property
 */
ZEPHIR_DOC_METHOD(Phalcon_Session_BagInterface, __isset);

/**
 * Setter of values
 */
ZEPHIR_DOC_METHOD(Phalcon_Session_BagInterface, __set);

/**
 * Destroys the session bag
 */
ZEPHIR_DOC_METHOD(Phalcon_Session_BagInterface, destroy);

/**
 * Getter of values
 */
ZEPHIR_DOC_METHOD(Phalcon_Session_BagInterface, get);

/**
 * Isset property
 */
ZEPHIR_DOC_METHOD(Phalcon_Session_BagInterface, has);

/**
 * Initializes the session bag. This method must not be called directly, the
 * class calls it when its internal data is accessed
 */
ZEPHIR_DOC_METHOD(Phalcon_Session_BagInterface, initialize);

/**
 * Setter of values
 */
ZEPHIR_DOC_METHOD(Phalcon_Session_BagInterface, set);

