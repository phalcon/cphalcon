
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
ZEPHIR_INIT_CLASS(Phalcon_Session_BagInterface)
{
	ZEPHIR_REGISTER_INTERFACE(Phalcon\\Session, BagInterface, phalcon, session_baginterface, phalcon_session_baginterface_method_entry);

	return SUCCESS;
}

ZEPHIR_DOC_METHOD(Phalcon_Session_BagInterface, __get);
ZEPHIR_DOC_METHOD(Phalcon_Session_BagInterface, __isset);
ZEPHIR_DOC_METHOD(Phalcon_Session_BagInterface, __set);
ZEPHIR_DOC_METHOD(Phalcon_Session_BagInterface, __unset);
ZEPHIR_DOC_METHOD(Phalcon_Session_BagInterface, init);
ZEPHIR_DOC_METHOD(Phalcon_Session_BagInterface, get);
ZEPHIR_DOC_METHOD(Phalcon_Session_BagInterface, set);
ZEPHIR_DOC_METHOD(Phalcon_Session_BagInterface, has);
ZEPHIR_DOC_METHOD(Phalcon_Session_BagInterface, remove);
ZEPHIR_DOC_METHOD(Phalcon_Session_BagInterface, clear);
