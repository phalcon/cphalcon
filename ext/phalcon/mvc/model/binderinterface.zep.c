
#ifdef HAVE_CONFIG_H
#include "../../../ext_config.h"
#endif

#include <php.h>
#include "../../../php_ext.h"
#include "../../../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */
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
 * Bind models into params in proper handler
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_Model_BinderInterface, bindToHandler);
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
