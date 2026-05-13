
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
#include "kernel/fcall.h"
#include "kernel/operators.h"
#include "kernel/memory.h"
#include "kernel/object.h"


ZEPHIR_INIT_CLASS(phalcon_18__closure)
{
	ZEPHIR_REGISTER_CLASS(phalcon, 18__closure, phalcon, 18__closure, phalcon_18__closure_method_entry, ZEND_ACC_FINAL_CLASS);

	return SUCCESS;
}

PHP_METHOD(phalcon_18__closure, __invoke)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval options, attributes;
	zval *name_param = NULL, *options_param = NULL, *attributes_param = NULL;
	zval name;

	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&options);
	ZVAL_UNDEF(&attributes);
	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_ZVAL(name_param)
		ZEPHIR_Z_PARAM_ARRAY(options, options_param)
		ZEPHIR_Z_PARAM_ARRAY(attributes, attributes_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 3, 0, &name_param, &options_param, &attributes_param);
	zephir_get_strval(&name, name_param);
	zephir_get_arrval(&options, options_param);
	zephir_get_arrval(&attributes, attributes_param);
	object_init_ex(return_value, phalcon_forms_element_select_ce);
	ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 0, &name, &options, &attributes);
	zephir_check_call_status();
	RETURN_MM();
}

