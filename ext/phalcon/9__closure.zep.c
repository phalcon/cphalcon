
#ifdef HAVE_CONFIG_H
#include "../ext_config.h"
#endif

#include <php.h>
#include "../php_ext.h"
#include "../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/object.h"


ZEPHIR_INIT_CLASS(phalcon_9__closure)
{
	ZEPHIR_REGISTER_CLASS(phalcon, 9__closure, phalcon, 9__closure, phalcon_9__closure_method_entry, ZEND_ACC_FINAL_CLASS);

	zend_declare_property_null(phalcon_9__closure_ce, SL("definition"), ZEND_ACC_PUBLIC|ZEND_ACC_STATIC);
	return SUCCESS;
}

PHP_METHOD(phalcon_9__closure, __invoke)
{
	zval definition;

	ZVAL_UNDEF(&definition);
	zephir_read_static_property_ce(&definition, phalcon_9__closure_ce, SL("definition"), PH_NOISY_CC);

	RETVAL_ZVAL(&definition, 1, 0);
	return;
}

