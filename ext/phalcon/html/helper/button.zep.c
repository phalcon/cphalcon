
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
#include "kernel/object.h"
#include "kernel/operators.h"
#include "kernel/memory.h"


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 *
 * Implementation of this file has been influenced by AuraPHP
 * @link    https://github.com/auraphp/Aura.Html
 * @license https://github.com/auraphp/Aura.Html/blob/2.x/LICENSE
 */
/**
 * Class Button
 *
 * @property bool $forceRaw
 */
ZEPHIR_INIT_CLASS(Phalcon_Html_Helper_Button)
{
	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Html\\Helper, Button, phalcon, html_helper_button, phalcon_html_helper_abstracthelper_ce, phalcon_html_helper_button_method_entry, 0);

	/**
	 * @var bool
	 */
	zend_declare_property_bool(phalcon_html_helper_button_ce, SL("forceRaw"), 0, ZEND_ACC_PROTECTED);
	return SUCCESS;
}

/**
 * @param EscaperInterface $escaper
 * @param Doctype          $doctype
 * @param bool             $forceRaw
 */
PHP_METHOD(Phalcon_Html_Helper_Button, __construct)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_bool forceRaw;
	zval *escaper, escaper_sub, *doctype = NULL, doctype_sub, *forceRaw_param = NULL, __$true, __$false, __$null;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&escaper_sub);
	ZVAL_UNDEF(&doctype_sub);
	ZVAL_BOOL(&__$true, 1);
	ZVAL_BOOL(&__$false, 0);
	ZVAL_NULL(&__$null);
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 3)
		Z_PARAM_OBJECT_OF_CLASS(escaper, phalcon_html_escaper_escaperinterface_ce)
		Z_PARAM_OPTIONAL
		Z_PARAM_OBJECT_OF_CLASS_OR_NULL(doctype, phalcon_html_helper_doctype_ce)
		Z_PARAM_BOOL(forceRaw)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 2, &escaper, &doctype, &forceRaw_param);
	if (!doctype) {
		doctype = &doctype_sub;
		doctype = &__$null;
	}
	if (!forceRaw_param) {
		forceRaw = 0;
	} else {
		}
	ZEPHIR_CALL_PARENT(NULL, phalcon_html_helper_button_ce, getThis(), "__construct", NULL, 0, escaper, doctype);
	zephir_check_call_status();
	if (forceRaw) {
		zephir_update_property_zval(this_ptr, ZEND_STRL("forceRaw"), &__$true);
	} else {
		zephir_update_property_zval(this_ptr, ZEND_STRL("forceRaw"), &__$false);
	}
	ZEPHIR_MM_RESTORE();
}

/**
 * Produce a `<button>` tag.
 *
 * @param string $text
 * @param array  $attributes
 * @param bool   $raw
 *
 * @return string
 * @throws Exception
 */
PHP_METHOD(Phalcon_Html_Helper_Button, __invoke)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_bool raw, _0;
	zval attributes;
	zval text_zv, *attributes_param = NULL, *raw_param = NULL, _1, _2, _3;
	zend_string *text = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&text_zv);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&attributes);
	ZEND_PARSE_PARAMETERS_START(1, 3)
		Z_PARAM_STR(text)
		Z_PARAM_OPTIONAL
		ZEPHIR_Z_PARAM_ARRAY(attributes, attributes_param)
		Z_PARAM_BOOL(raw)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	if (ZEND_NUM_ARGS() > 1) {
		attributes_param = ZEND_CALL_ARG(execute_data, 2);
	}
	if (ZEND_NUM_ARGS() > 2) {
		raw_param = ZEND_CALL_ARG(execute_data, 3);
	}
	ZVAL_STR_COPY(&text_zv, text);
	if (!attributes_param) {
		ZEPHIR_INIT_VAR(&attributes);
		array_init(&attributes);
	} else {
		zephir_get_arrval(&attributes, attributes_param);
	}
	if (!raw_param) {
		raw = 0;
	} else {
		}
	_0 = raw;
	if (!(_0)) {
		zephir_memory_observe(&_1);
		zephir_read_property(&_1, this_ptr, ZEND_STRL("forceRaw"), PH_NOISY_CC);
		_0 = zephir_is_true(&_1);
	}
	ZEPHIR_INIT_VAR(&_2);
	ZVAL_STRING(&_2, "button");
	ZVAL_BOOL(&_3, _0);
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "renderfullelement", NULL, 0, &_2, &text_zv, &attributes, &_3);
	zephir_check_call_status();
	RETURN_MM();
}

