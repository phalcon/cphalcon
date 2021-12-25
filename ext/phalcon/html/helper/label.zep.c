
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
#include "kernel/memory.h"
#include "kernel/operators.h"
#include "kernel/object.h"


/**
 * This file is part of the Phalcon.
 *
 * (c) Phalcon Team <team@phalcon.com>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */
/**
 * Class Label
 */
ZEPHIR_INIT_CLASS(Phalcon_Html_Helper_Label)
{
	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Html\\Helper, Label, phalcon, html_helper_label, phalcon_html_helper_abstracthelper_ce, phalcon_html_helper_label_method_entry, 0);

	return SUCCESS;
}

/**
 * Produce a `<label>` tag.
 *
 * @param string $label
 * @param array  $attributes
 * @param bool   $raw
 *
 * @return string
 * @throws Exception
 */
PHP_METHOD(Phalcon_Html_Helper_Label, __invoke)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_bool raw;
	zval attributes;
	zval *label_param = NULL, *attributes_param = NULL, *raw_param = NULL, _0, _1;
	zval label;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&label);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&attributes);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 3)
		Z_PARAM_STR(label)
		Z_PARAM_OPTIONAL
		Z_PARAM_ARRAY(attributes)
		Z_PARAM_BOOL(raw)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 2, &label_param, &attributes_param, &raw_param);
	zephir_get_strval(&label, label_param);
	if (!attributes_param) {
		ZEPHIR_INIT_VAR(&attributes);
		array_init(&attributes);
	} else {
		zephir_get_arrval(&attributes, attributes_param);
	}
	if (!raw_param) {
		raw = 0;
	} else {
		raw = zephir_get_boolval(raw_param);
	}


	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "label");
	if (raw) {
		ZVAL_BOOL(&_1, 1);
	} else {
		ZVAL_BOOL(&_1, 0);
	}
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "renderfullelement", NULL, 0, &_0, &label, &attributes, &_1);
	zephir_check_call_status();
	RETURN_MM();
}

