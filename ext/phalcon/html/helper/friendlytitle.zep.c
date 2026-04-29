
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
#include "kernel/object.h"
#include "kernel/exception.h"
#include "kernel/operators.h"


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */
/**
 * Converts text to a URL-friendly slug.
 */
ZEPHIR_INIT_CLASS(Phalcon_Html_Helper_FriendlyTitle)
{
	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Html\\Helper, FriendlyTitle, phalcon, html_helper_friendlytitle, phalcon_html_helper_abstracthelper_ce, phalcon_html_helper_friendlytitle_method_entry, 0);

	/**
	 * @var Friendly
	 */
	zend_declare_property_null(phalcon_html_helper_friendlytitle_ce, SL("friendly"), ZEND_ACC_PROTECTED);
	return SUCCESS;
}

/**
 * @param EscaperInterface $escaper
 */
PHP_METHOD(Phalcon_Html_Helper_FriendlyTitle, __construct)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *escaper, escaper_sub, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&escaper_sub);
	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(escaper, phalcon_html_escaper_escaperinterface_ce)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &escaper);
	ZEPHIR_CALL_PARENT(NULL, phalcon_html_helper_friendlytitle_ce, getThis(), "__construct", NULL, 0, escaper);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_0);
	object_init_ex(&_0, phalcon_support_helper_str_friendly_ce);
	if (zephir_has_constructor(&_0)) {
		ZEPHIR_CALL_METHOD(NULL, &_0, "__construct", NULL, 0);
		zephir_check_call_status();
	}

	zephir_update_property_zval(this_ptr, ZEND_STRL("friendly"), &_0);
	ZEPHIR_MM_RESTORE();
}

/**
 * @param string     $text
 * @param string     $separator
 * @param bool       $lowercase
 * @param mixed|null $replace
 *
 * @return string
 * @throws Exception
 */
PHP_METHOD(Phalcon_Html_Helper_FriendlyTitle, __invoke)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_bool lowercase;
	zval text_zv, separator_zv, *lowercase_param = NULL, *replace = NULL, replace_sub, __$null, ex, _2, _0$$3, _1$$3, _3$$4, _4$$4;
	zend_string *text = NULL, *separator = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&text_zv);
	ZVAL_UNDEF(&separator_zv);
	ZVAL_UNDEF(&replace_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&ex);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_3$$4);
	ZVAL_UNDEF(&_4$$4);
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 4)
		Z_PARAM_STR(text)
		Z_PARAM_OPTIONAL
		Z_PARAM_STR(separator)
		Z_PARAM_BOOL(lowercase)
		Z_PARAM_ZVAL_OR_NULL(replace)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	if (ZEND_NUM_ARGS() > 2) {
		lowercase_param = ZEND_CALL_ARG(execute_data, 3);
	}
	if (ZEND_NUM_ARGS() > 3) {
		replace = ZEND_CALL_ARG(execute_data, 4);
	}
	ZVAL_STR_COPY(&text_zv, text);
	if (!separator) {
		separator = zend_string_init(ZEND_STRL("-"), 0);
		ZVAL_STR(&separator_zv, separator);
	} else {
		ZVAL_STR_COPY(&separator_zv, separator);
	}
	if (!lowercase_param) {
		lowercase = 1;
	} else {
		}
	if (!replace) {
		replace = &replace_sub;
		replace = &__$null;
	}
	/* try_start_1: */

		zephir_read_property(&_0$$3, this_ptr, ZEND_STRL("friendly"), PH_NOISY_CC | PH_READONLY);
		if (lowercase) {
			ZVAL_BOOL(&_1$$3, 1);
		} else {
			ZVAL_BOOL(&_1$$3, 0);
		}
		ZEPHIR_RETURN_CALL_METHOD(&_0$$3, "__invoke", NULL, 0, &text_zv, &separator_zv, &_1$$3, replace);
		zephir_check_call_status_or_jump(try_end_1);
		RETURN_MM();

	try_end_1:

	if (EG(exception)) {
		ZEPHIR_INIT_VAR(&_2);
		ZVAL_OBJ(&_2, EG(exception));
		Z_ADDREF_P(&_2);
		if (zephir_is_instance_of(&_2, SL("Exception"))) {
			zend_clear_exception();
			ZEPHIR_CPY_WRT(&ex, &_2);
			ZEPHIR_INIT_VAR(&_3$$4);
			object_init_ex(&_3$$4, phalcon_html_exception_ce);
			ZEPHIR_CALL_METHOD(&_4$$4, &ex, "getmessage", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(NULL, &_3$$4, "__construct", NULL, 32, &_4$$4);
			zephir_check_call_status();
			zephir_throw_exception_debug(&_3$$4, "phalcon/Html/Helper/FriendlyTitle.zep", 57);
			ZEPHIR_MM_RESTORE();
			return;
		}
	}
}

