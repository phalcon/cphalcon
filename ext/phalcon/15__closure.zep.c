
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


ZEPHIR_INIT_CLASS(phalcon_15__closure)
{
	ZEPHIR_REGISTER_CLASS(phalcon, 15__closure, phalcon, 15__closure, phalcon_15__closure_method_entry, ZEND_ACC_FINAL_CLASS);

	return SUCCESS;
}

PHP_METHOD(phalcon_15__closure, __invoke)
{

	RETURN_MEMBER(getThis(), "doctype");
}

