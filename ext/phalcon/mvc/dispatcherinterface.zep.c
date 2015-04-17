
#ifdef HAVE_CONFIG_H
#include "../../ext_config.h"
#endif

#include <php.h>
#include "../../php_ext.h"
#include "../../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


/**
 * Phalcon\Mvc\DispatcherInterface
 *
 * Interface for Phalcon\Mvc\Dispatcher
 */
ZEPHIR_INIT_CLASS(Phalcon_Mvc_DispatcherInterface) {

	ZEPHIR_REGISTER_INTERFACE(Phalcon\\Mvc, DispatcherInterface, phalcon, mvc_dispatcherinterface, phalcon_mvc_dispatcherinterface_method_entry);

	zend_class_implements(phalcon_mvc_dispatcherinterface_ce TSRMLS_CC, 1, phalcon_dispatcherinterface_ce);
	return SUCCESS;

}

/**
 * Sets the default controller suffix
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_DispatcherInterface, setControllerSuffix);

/**
 * Sets the default controller name
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_DispatcherInterface, setDefaultController);

/**
 * Sets the controller name to be dispatched
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_DispatcherInterface, setControllerName);

/**
 * Gets last dispatched controller name
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_DispatcherInterface, getControllerName);

/**
 * Returns the lastest dispatched controller
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_DispatcherInterface, getLastController);

/**
 * Returns the active controller in the dispatcher
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_DispatcherInterface, getActiveController);

