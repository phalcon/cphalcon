
#ifdef HAVE_CONFIG_H
#include "../../../ext_config.h"
#endif

#include <php.h>
#include "../../../php_ext.h"
#include "../../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/object.h"
#include "kernel/memory.h"


/**
 * Phalcon\Mvc\Router\DefaultValue
 *
 * Allows to pass default values to routes
 */
ZEPHIR_INIT_CLASS(Phalcon_Mvc_Router_DefaultValue) {

	ZEPHIR_REGISTER_CLASS(Phalcon\\Mvc\\Router, DefaultValue, phalcon, mvc_router_defaultvalue, phalcon_mvc_router_defaultvalue_method_entry, 0);

	zend_declare_property_null(phalcon_mvc_router_defaultvalue_ce, SL("_defaultValue"), ZEND_ACC_PROTECTED TSRMLS_CC);

	return SUCCESS;

}

PHP_METHOD(Phalcon_Mvc_Router_DefaultValue, __construct) {

	zval *defaultValue;

	zephir_fetch_params(0, 1, 0, &defaultValue);



	zephir_update_property_this(this_ptr, SL("_defaultValue"), defaultValue TSRMLS_CC);

}

