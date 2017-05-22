
#ifdef HAVE_CONFIG_H
#include "../../../../ext_config.h"
#endif

#include <php.h>
#include "../../../../php_ext.h"
#include "../../../../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


/**
 * Phalcon\Mvc\Model\Binder\BindableInterface
 *
 * Interface for bindable classes
 */
ZEPHIR_INIT_CLASS(Phalcon_Mvc_Model_Binder_BindableInterface) {

	ZEPHIR_REGISTER_INTERFACE(Phalcon\\Mvc\\Model\\Binder, BindableInterface, phalcon, mvc_model_binder_bindableinterface, phalcon_mvc_model_binder_bindableinterface_method_entry);

	return SUCCESS;

}

/**
 * Return the model name or models names and parameters keys associated with this class
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_Model_Binder_BindableInterface, getModelName);

