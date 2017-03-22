
#ifdef HAVE_CONFIG_H
#include "../../../ext_config.h"
#endif

#include <php.h>
#include "../../../php_ext.h"
#include "../../../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


/**
 * Phalcon\Mvc\Model\BinderInterface
 *
 * Interface for Phalcon\Mvc\Model\Binder
 */
ZEPHIR_INIT_CLASS(Phalcon_Mvc_Model_BinderInterface) {

	ZEPHIR_REGISTER_INTERFACE(Phalcon\\Mvc\\Model, BinderInterface, phalcon, mvc_model_binderinterface, phalcon_mvc_model_binderinterface_method_entry);

	return SUCCESS;

}

/**
 * Gets active bound models
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_Model_BinderInterface, getBoundModels);

/**
 * Gets cache instance
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_Model_BinderInterface, getCache);

/**
 * Sets cache instance
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_Model_BinderInterface, setCache);

/**
 * Bind models into params in proper handler
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_Model_BinderInterface, bindToHandler);

