
#ifdef HAVE_CONFIG_H
#include "../../ext_config.h"
#endif

#include <php.h>
#include "../../php_ext.h"
#include "../../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


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
 */
ZEPHIR_DOC_METHOD(Phalcon_Session_BagInterface, __isset);

