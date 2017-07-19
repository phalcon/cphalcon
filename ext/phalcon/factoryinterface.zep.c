
#ifdef HAVE_CONFIG_H
#include "../ext_config.h"
#endif

#include <php.h>
#include "../php_ext.h"
#include "../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


ZEPHIR_INIT_CLASS(Phalcon_FactoryInterface) {

	ZEPHIR_REGISTER_INTERFACE(Phalcon, FactoryInterface, phalcon, factoryinterface, phalcon_factoryinterface_method_entry);

	return SUCCESS;

}

/**
 * @param \Phalcon\Config|array config
 */
ZEPHIR_DOC_METHOD(Phalcon_FactoryInterface, load);

