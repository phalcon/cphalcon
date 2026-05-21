
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
#include "kernel/fcall.h"
#include "kernel/concat.h"
#include "kernel/memory.h"
#include "kernel/object.h"


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */
ZEPHIR_INIT_CLASS(Phalcon_Html_Exceptions_AttributeNotRenderable)
{
	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Html\\Exceptions, AttributeNotRenderable, phalcon, html_exceptions_attributenotrenderable, phalcon_html_exception_ce, phalcon_html_exceptions_attributenotrenderable_method_entry, 0);

	return SUCCESS;
}

PHP_METHOD(Phalcon_Html_Exceptions_AttributeNotRenderable, __construct)
{
	zval _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval key_zv, type_zv;
	zend_string *key = NULL, *type = NULL;

	ZVAL_UNDEF(&key_zv);
	ZVAL_UNDEF(&type_zv);
	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_STR(key)
		Z_PARAM_STR(type)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_memory_observe(&key_zv);
	ZVAL_STR_COPY(&key_zv, key);
	zephir_memory_observe(&type_zv);
	ZVAL_STR_COPY(&type_zv, type);
	ZEPHIR_INIT_VAR(&_0);
	ZEPHIR_CONCAT_SVSVS(&_0, "Value at index: \"", &key_zv, "\" type: \"", &type_zv, "\" cannot be rendered");
	ZEPHIR_CALL_PARENT(NULL, phalcon_html_exceptions_attributenotrenderable_ce, getThis(), "__construct", NULL, 0, &_0);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();
}

