
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
#include "kernel/operators.h"
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"
#include "kernel/array.h"
#include "kernel/concat.h"
#include "kernel/string.h"


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */
/**
 * Phalcon\Tag is designed to simplify building of HTML tags.
 * It provides a set of helpers to generate HTML in a dynamic way.
 * This component is a class that you can extend to add more helpers.
 */
ZEPHIR_INIT_CLASS(Phalcon_Tag)
{
	ZEPHIR_REGISTER_CLASS(Phalcon, Tag, phalcon, tag, phalcon_tag_method_entry, 0);

	/**
	 * @var bool
	 */
	zend_declare_property_bool(phalcon_tag_ce, SL("autoEscape"), 1, ZEND_ACC_PROTECTED|ZEND_ACC_STATIC);
	/**
	 * DI Container
	 *
	 * @var DiInterface|null
	 */
	zend_declare_property_null(phalcon_tag_ce, SL("container"), ZEND_ACC_PROTECTED|ZEND_ACC_STATIC);
	/**
	 * Pre-assigned values for components
	 *
	 * @var array
	 */
	zend_declare_property_null(phalcon_tag_ce, SL("displayValues"), ZEND_ACC_PROTECTED|ZEND_ACC_STATIC);
	/**
	 * @var array
	 */
	zend_declare_property_null(phalcon_tag_ce, SL("documentAppendTitle"), ZEND_ACC_PROTECTED|ZEND_ACC_STATIC);
	/**
	 * @var array
	 */
	zend_declare_property_null(phalcon_tag_ce, SL("documentPrependTitle"), ZEND_ACC_PROTECTED|ZEND_ACC_STATIC);
	/**
	 * HTML document title
	 *
	 * @var string|null
	 */
	zend_declare_property_null(phalcon_tag_ce, SL("documentTitle"), ZEND_ACC_PROTECTED|ZEND_ACC_STATIC);
	/**
	 * @var string|null
	 */
	zend_declare_property_null(phalcon_tag_ce, SL("documentTitleSeparator"), ZEND_ACC_PROTECTED|ZEND_ACC_STATIC);
	/**
	 * @var int
	 */
	zend_declare_property_long(phalcon_tag_ce, SL("documentType"), 11, ZEND_ACC_PROTECTED|ZEND_ACC_STATIC);
	/**
	 * @var EscaperInterface|null
	 */
	zend_declare_property_null(phalcon_tag_ce, SL("escaperService"), ZEND_ACC_PROTECTED|ZEND_ACC_STATIC);
	/**
	 * @var UrlInterface|null
	 */
	zend_declare_property_null(phalcon_tag_ce, SL("urlService"), ZEND_ACC_PROTECTED|ZEND_ACC_STATIC);
	zephir_declare_class_constant_long(phalcon_tag_ce, SL("HTML32"), 1);

	zephir_declare_class_constant_long(phalcon_tag_ce, SL("HTML401_STRICT"), 2);

	zephir_declare_class_constant_long(phalcon_tag_ce, SL("HTML401_TRANSITIONAL"), 3);

	zephir_declare_class_constant_long(phalcon_tag_ce, SL("HTML401_FRAMESET"), 4);

	zephir_declare_class_constant_long(phalcon_tag_ce, SL("HTML5"), 5);

	zephir_declare_class_constant_long(phalcon_tag_ce, SL("XHTML10_STRICT"), 6);

	zephir_declare_class_constant_long(phalcon_tag_ce, SL("XHTML10_TRANSITIONAL"), 7);

	zephir_declare_class_constant_long(phalcon_tag_ce, SL("XHTML10_FRAMESET"), 8);

	zephir_declare_class_constant_long(phalcon_tag_ce, SL("XHTML11"), 9);

	zephir_declare_class_constant_long(phalcon_tag_ce, SL("XHTML20"), 10);

	zephir_declare_class_constant_long(phalcon_tag_ce, SL("XHTML5"), 11);

	return SUCCESS;
}

/**
 * Appends a text to current document title
 *
 * @param array|string title
 */
PHP_METHOD(Phalcon_Tag, appendTitle)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *title, title_sub, _0, _1$$3;

	ZVAL_UNDEF(&title_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(title)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &title);
	zephir_read_static_property_ce(&_0, phalcon_tag_ce, SL("documentAppendTitle"), PH_NOISY_CC | PH_READONLY);
	if (Z_TYPE_P(&_0) == IS_NULL) {
		ZEPHIR_INIT_VAR(&_1$$3);
		array_init(&_1$$3);
		zephir_update_static_property_ce(phalcon_tag_ce, ZEND_STRL("documentAppendTitle"), &_1$$3);
	}
	if (Z_TYPE_P(title) == IS_ARRAY) {
		zephir_update_static_property_ce(phalcon_tag_ce, ZEND_STRL("documentAppendTitle"), title);
	} else {
		zephir_update_static_property_array_multi_ce(phalcon_tag_ce, SL("documentAppendTitle"), title, SL("a"), 1);
	}
	ZEPHIR_MM_RESTORE();
}

/**
 * Builds a HTML input[type="check"] tag
 *
 * @param array parameters = [
 *     'class' => '',
 *     'id' => '',
 *     'name' => ''
 *     'value' => ''
 * ]
 */
PHP_METHOD(Phalcon_Tag, checkField)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL;
	zval *parameters, parameters_sub, _1;

	ZVAL_UNDEF(&parameters_sub);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(parameters)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &parameters);
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "checkbox");
	ZEPHIR_RETURN_CALL_SELF("inputfieldchecked", &_0, 0, &_1, parameters);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Builds a HTML input[type="color"] tag
 *
 * @param array parameters = [
 *     'class' => '',
 *     'id' => '',
 *     'name' => ''
 *     'value' => ''
 * ]
 */
PHP_METHOD(Phalcon_Tag, colorField)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL;
	zval *parameters, parameters_sub, _1;

	ZVAL_UNDEF(&parameters_sub);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(parameters)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &parameters);
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "color");
	ZEPHIR_RETURN_CALL_SELF("inputfield", &_0, 0, &_1, parameters);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Builds a HTML input[type="date"] tag
 *
 * @param array parameters = [
 *     'class' => '',
 *     'id' => '',
 *     'name' => ''
 *     'value' => ''
 * ]
 */
PHP_METHOD(Phalcon_Tag, dateField)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL;
	zval *parameters, parameters_sub, _1;

	ZVAL_UNDEF(&parameters_sub);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(parameters)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &parameters);
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "date");
	ZEPHIR_RETURN_CALL_SELF("inputfield", &_0, 0, &_1, parameters);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Builds a HTML input[type="datetime"] tag
 *
 * @param array parameters = [
 *     'class' => '',
 *     'id' => '',
 *     'name' => ''
 *     'value' => ''
 * ]
 */
PHP_METHOD(Phalcon_Tag, dateTimeField)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL;
	zval *parameters, parameters_sub, _1;

	ZVAL_UNDEF(&parameters_sub);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(parameters)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &parameters);
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "datetime");
	ZEPHIR_RETURN_CALL_SELF("inputfield", &_0, 0, &_1, parameters);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Builds a HTML input[type="datetime-local"] tag
 *
 * @param array parameters = [
 *     'class' => '',
 *     'id' => '',
 *     'name' => ''
 *     'value' => ''
 * ]
 */
PHP_METHOD(Phalcon_Tag, dateTimeLocalField)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL;
	zval *parameters, parameters_sub, _1;

	ZVAL_UNDEF(&parameters_sub);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(parameters)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &parameters);
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "datetime-local");
	ZEPHIR_RETURN_CALL_SELF("inputfield", &_0, 0, &_1, parameters);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Alias of Phalcon\Tag::setDefault()
 */
PHP_METHOD(Phalcon_Tag, displayTo)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *id_param = NULL, *value, value_sub;
	zval id;

	ZVAL_UNDEF(&id);
	ZVAL_UNDEF(&value_sub);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_STR(id)
		Z_PARAM_ZVAL(value)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 2, 0, &id_param, &value);
	if (UNEXPECTED(Z_TYPE_P(id_param) != IS_STRING && Z_TYPE_P(id_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'id' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(id_param) == IS_STRING)) {
		zephir_get_strval(&id, id_param);
	} else {
		ZEPHIR_INIT_VAR(&id);
	}
	ZEPHIR_CALL_SELF(NULL, "setdefault", NULL, 0, &id, value);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();
}

/**
 * Builds a HTML input[type="email"] tag
 *
 * @param array parameters = [
 *     'class' => '',
 *     'id' => '',
 *     'name' => ''
 *     'value' => ''
 * ]
 */
PHP_METHOD(Phalcon_Tag, emailField)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL;
	zval *parameters, parameters_sub, _1;

	ZVAL_UNDEF(&parameters_sub);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(parameters)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &parameters);
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "email");
	ZEPHIR_RETURN_CALL_SELF("inputfield", &_0, 0, &_1, parameters);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Builds a HTML close FORM tag
 */
PHP_METHOD(Phalcon_Tag, endForm)
{

	RETURN_STRING("</form>");
}

/**
 * Builds a HTML input[type="file"] tag
 *
 * @param array parameters = [
 *     'class' => '',
 *     'id' => '',
 *     'name' => ''
 *     'value' => ''
 * ]
 */
PHP_METHOD(Phalcon_Tag, fileField)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL;
	zval *parameters, parameters_sub, _1;

	ZVAL_UNDEF(&parameters_sub);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(parameters)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &parameters);
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "file");
	ZEPHIR_RETURN_CALL_SELF("inputfield", &_0, 0, &_1, parameters);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Builds a HTML FORM tag
 *
 * @param array parameters = [
 *     'method' => 'post',
 *     'action' => '',
 *     'parameters' => '',
 *     'name' => '',
 *     'class' => '',
 *     'id' => ''
 * ]
 */
PHP_METHOD(Phalcon_Tag, formLegacy)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *parameters = NULL, parameters_sub, params, paramsAction, action, code, _3, _0$$6, _1$$7, _2$$8;

	ZVAL_UNDEF(&parameters_sub);
	ZVAL_UNDEF(&params);
	ZVAL_UNDEF(&paramsAction);
	ZVAL_UNDEF(&action);
	ZVAL_UNDEF(&code);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_0$$6);
	ZVAL_UNDEF(&_1$$7);
	ZVAL_UNDEF(&_2$$8);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(parameters)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &parameters);
	ZEPHIR_SEPARATE_PARAM(parameters);
	if (Z_TYPE_P(parameters) != IS_ARRAY) {
		ZEPHIR_INIT_VAR(&params);
		zephir_create_array(&params, 1, 0);
		zephir_array_fast_append(&params, parameters);
	} else {
		ZEPHIR_CPY_WRT(&params, parameters);
	}
	zephir_memory_observe(&paramsAction);
	if (!(zephir_array_isset_long_fetch(&paramsAction, &params, 0, 0))) {
		ZEPHIR_OBS_NVAR(&paramsAction);
		zephir_array_isset_string_fetch(&paramsAction, &params, SL("action"), 0);
	}
	if (!(zephir_array_isset_string(&params, SL("method")))) {
		ZEPHIR_INIT_VAR(&_0$$6);
		ZVAL_STRING(&_0$$6, "post");
		zephir_array_update_string(&params, SL("method"), &_0$$6, PH_COPY | PH_SEPARATE);
	}
	ZEPHIR_INIT_VAR(&action);
	ZVAL_NULL(&action);
	if (!(ZEPHIR_IS_EMPTY(&paramsAction))) {
		ZEPHIR_CALL_SELF(&_1$$7, "geturlservice", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&action, &_1$$7, "get", NULL, 0, &paramsAction);
		zephir_check_call_status();
	}
	ZEPHIR_OBS_NVAR(parameters);
	if (zephir_array_isset_string_fetch(parameters, &params, SL("parameters"), 0)) {
		ZEPHIR_INIT_VAR(&_2$$8);
		ZEPHIR_CONCAT_SV(&_2$$8, "?", parameters);
		zephir_concat_self(&action, &_2$$8);
	}
	if (!(ZEPHIR_IS_EMPTY(&action))) {
		zephir_array_update_string(&params, SL("action"), &action, PH_COPY | PH_SEPARATE);
	}
	ZEPHIR_INIT_VAR(&_3);
	ZVAL_STRING(&_3, "<form");
	ZEPHIR_CALL_SELF(&code, "renderattributes", NULL, 0, &_3, &params);
	zephir_check_call_status();
	zephir_concat_self_str(&code, SL(">"));
	RETURN_CCTOR(&code);
}

/**
 * Converts texts into URL-friendly titles
 */
PHP_METHOD(Phalcon_Tag, friendlyTitle)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_bool lowercase;
	zval *text_param = NULL, *separator_param = NULL, *lowercase_param = NULL, *replace = NULL, replace_sub, __$null, ex, _2, _0$$3, _1$$3, _3$$4, _4$$4;
	zval text, separator;

	ZVAL_UNDEF(&text);
	ZVAL_UNDEF(&separator);
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
	zephir_fetch_params(1, 1, 3, &text_param, &separator_param, &lowercase_param, &replace);
	zephir_get_strval(&text, text_param);
	if (!separator_param) {
		ZEPHIR_INIT_VAR(&separator);
		ZVAL_STRING(&separator, "-");
	} else {
		zephir_get_strval(&separator, separator_param);
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

		ZEPHIR_INIT_VAR(&_0$$3);
		object_init_ex(&_0$$3, phalcon_support_helper_str_friendly_ce);
		if (zephir_has_constructor(&_0$$3)) {
			ZEPHIR_CALL_METHOD(NULL, &_0$$3, "__construct", NULL, 0);
			zephir_check_call_status_or_jump(try_end_1);
		}

		if (lowercase) {
			ZVAL_BOOL(&_1$$3, 1);
		} else {
			ZVAL_BOOL(&_1$$3, 0);
		}
		ZEPHIR_RETURN_CALL_METHOD(&_0$$3, "__invoke", NULL, 0, &text, &separator, &_1$$3, replace);
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
			object_init_ex(&_3$$4, phalcon_tag_exception_ce);
			ZEPHIR_CALL_METHOD(&_4$$4, &ex, "getmessage", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(NULL, &_3$$4, "__construct", NULL, 33, &_4$$4);
			zephir_check_call_status();
			zephir_throw_exception_debug(&_3$$4, "phalcon/Tag.zep", 308);
			ZEPHIR_MM_RESTORE();
			return;
		}
	}
}

/**
 * Get the document type declaration of content
 */
PHP_METHOD(Phalcon_Tag, getDocType)
{
	zval _0, _1$$3, _2$$4, _3$$4, _4$$5, _5$$5, _6$$6, _7$$6, _8$$7, _9$$7, _10$$8, _11$$8, _12$$9, _13$$9, _14$$10, _15$$10, _16$$11, _17$$11, _18$$12;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$4);
	ZVAL_UNDEF(&_3$$4);
	ZVAL_UNDEF(&_4$$5);
	ZVAL_UNDEF(&_5$$5);
	ZVAL_UNDEF(&_6$$6);
	ZVAL_UNDEF(&_7$$6);
	ZVAL_UNDEF(&_8$$7);
	ZVAL_UNDEF(&_9$$7);
	ZVAL_UNDEF(&_10$$8);
	ZVAL_UNDEF(&_11$$8);
	ZVAL_UNDEF(&_12$$9);
	ZVAL_UNDEF(&_13$$9);
	ZVAL_UNDEF(&_14$$10);
	ZVAL_UNDEF(&_15$$10);
	ZVAL_UNDEF(&_16$$11);
	ZVAL_UNDEF(&_17$$11);
	ZVAL_UNDEF(&_18$$12);
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	zephir_read_static_property_ce(&_0, phalcon_tag_ce, SL("documentType"), PH_NOISY_CC | PH_READONLY);
	do {
		if (ZEPHIR_IS_LONG(&_0, 1)) {
			ZEPHIR_INIT_VAR(&_1$$3);
			ZEPHIR_GET_CONSTANT(&_1$$3, "PHP_EOL");
			ZEPHIR_CONCAT_SV(return_value, "<!DOCTYPE html PUBLIC \"-//W3C//DTD HTML 3.2 Final//EN\">", &_1$$3);
			RETURN_MM();
		}
		if (ZEPHIR_IS_LONG(&_0, 2)) {
			ZEPHIR_INIT_VAR(&_2$$4);
			ZEPHIR_GET_CONSTANT(&_2$$4, "PHP_EOL");
			ZEPHIR_INIT_VAR(&_3$$4);
			ZEPHIR_GET_CONSTANT(&_3$$4, "PHP_EOL");
			ZEPHIR_CONCAT_SVSV(return_value, "<!DOCTYPE html PUBLIC \"-//W3C//DTD HTML 4.01//EN\"", &_2$$4, "\t\"http://www.w3.org/TR/html4/strict.dtd\">", &_3$$4);
			RETURN_MM();
		}
		if (ZEPHIR_IS_LONG(&_0, 3)) {
			ZEPHIR_INIT_VAR(&_4$$5);
			ZEPHIR_GET_CONSTANT(&_4$$5, "PHP_EOL");
			ZEPHIR_INIT_VAR(&_5$$5);
			ZEPHIR_GET_CONSTANT(&_5$$5, "PHP_EOL");
			ZEPHIR_CONCAT_SVSV(return_value, "<!DOCTYPE html PUBLIC \"-//W3C//DTD HTML 4.01 Transitional//EN\"", &_4$$5, "\t\"http://www.w3.org/TR/html4/loose.dtd\">", &_5$$5);
			RETURN_MM();
		}
		if (ZEPHIR_IS_LONG(&_0, 4)) {
			ZEPHIR_INIT_VAR(&_6$$6);
			ZEPHIR_GET_CONSTANT(&_6$$6, "PHP_EOL");
			ZEPHIR_INIT_VAR(&_7$$6);
			ZEPHIR_GET_CONSTANT(&_7$$6, "PHP_EOL");
			ZEPHIR_CONCAT_SVSV(return_value, "<!DOCTYPE html PUBLIC \"-//W3C//DTD HTML 4.01 Frameset//EN\"", &_6$$6, "\t\"http://www.w3.org/TR/html4/frameset.dtd\">", &_7$$6);
			RETURN_MM();
		}
		if (ZEPHIR_IS_LONG(&_0, 6)) {
			ZEPHIR_INIT_VAR(&_8$$7);
			ZEPHIR_GET_CONSTANT(&_8$$7, "PHP_EOL");
			ZEPHIR_INIT_VAR(&_9$$7);
			ZEPHIR_GET_CONSTANT(&_9$$7, "PHP_EOL");
			ZEPHIR_CONCAT_SVSV(return_value, "<!DOCTYPE html PUBLIC \"-//W3C//DTD XHTML 1.0 Strict//EN\"", &_8$$7, "\t\"http://www.w3.org/TR/xhtml1/DTD/xhtml1-strict.dtd\">", &_9$$7);
			RETURN_MM();
		}
		if (ZEPHIR_IS_LONG(&_0, 7)) {
			ZEPHIR_INIT_VAR(&_10$$8);
			ZEPHIR_GET_CONSTANT(&_10$$8, "PHP_EOL");
			ZEPHIR_INIT_VAR(&_11$$8);
			ZEPHIR_GET_CONSTANT(&_11$$8, "PHP_EOL");
			ZEPHIR_CONCAT_SVSV(return_value, "<!DOCTYPE html PUBLIC \"-//W3C//DTD XHTML 1.0 Transitional//EN\"", &_10$$8, "\t\"http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd\">", &_11$$8);
			RETURN_MM();
		}
		if (ZEPHIR_IS_LONG(&_0, 8)) {
			ZEPHIR_INIT_VAR(&_12$$9);
			ZEPHIR_GET_CONSTANT(&_12$$9, "PHP_EOL");
			ZEPHIR_INIT_VAR(&_13$$9);
			ZEPHIR_GET_CONSTANT(&_13$$9, "PHP_EOL");
			ZEPHIR_CONCAT_SVSV(return_value, "<!DOCTYPE html PUBLIC \"-//W3C//DTD XHTML 1.0 Frameset//EN\"", &_12$$9, "\t\"http://www.w3.org/TR/xhtml1/DTD/xhtml1-frameset.dtd\">", &_13$$9);
			RETURN_MM();
		}
		if (ZEPHIR_IS_LONG(&_0, 9)) {
			ZEPHIR_INIT_VAR(&_14$$10);
			ZEPHIR_GET_CONSTANT(&_14$$10, "PHP_EOL");
			ZEPHIR_INIT_VAR(&_15$$10);
			ZEPHIR_GET_CONSTANT(&_15$$10, "PHP_EOL");
			ZEPHIR_CONCAT_SVSV(return_value, "<!DOCTYPE html PUBLIC \"-//W3C//DTD XHTML 1.1//EN\"", &_14$$10, "\t\"http://www.w3.org/TR/xhtml11/DTD/xhtml11.dtd\">", &_15$$10);
			RETURN_MM();
		}
		if (ZEPHIR_IS_LONG(&_0, 10)) {
			ZEPHIR_INIT_VAR(&_16$$11);
			ZEPHIR_GET_CONSTANT(&_16$$11, "PHP_EOL");
			ZEPHIR_INIT_VAR(&_17$$11);
			ZEPHIR_GET_CONSTANT(&_17$$11, "PHP_EOL");
			ZEPHIR_CONCAT_SVSV(return_value, "<!DOCTYPE html PUBLIC \"-//W3C//DTD XHTML 2.0//EN\"", &_16$$11, "\t\"http://www.w3.org/MarkUp/DTD/xhtml2.dtd\">", &_17$$11);
			RETURN_MM();
		}
		if (ZEPHIR_IS_LONG(&_0, 5) || ZEPHIR_IS_LONG(&_0, 11)) {
			ZEPHIR_INIT_VAR(&_18$$12);
			ZEPHIR_GET_CONSTANT(&_18$$12, "PHP_EOL");
			ZEPHIR_CONCAT_SV(return_value, "<!DOCTYPE html>", &_18$$12);
			RETURN_MM();
		}
	} while(0);

	RETURN_MM_STRING("");
}

/**
 * Obtains the 'escaper' service if required
 */
PHP_METHOD(Phalcon_Tag, getEscaper)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *params_param = NULL, autoescape;
	zval params;

	ZVAL_UNDEF(&params);
	ZVAL_UNDEF(&autoescape);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ARRAY(params)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &params_param);
	ZEPHIR_OBS_COPY_OR_DUP(&params, params_param);
	zephir_memory_observe(&autoescape);
	if (!(zephir_array_isset_string_fetch(&autoescape, &params, SL("escape"), 0))) {
		ZEPHIR_OBS_NVAR(&autoescape);
		zephir_read_static_property_ce(&autoescape, phalcon_tag_ce, SL("autoEscape"), PH_NOISY_CC);
	}
	if (!(zephir_is_true(&autoescape))) {
		RETURN_MM_NULL();
	}
	ZEPHIR_RETURN_CALL_SELF("getescaperservice", NULL, 0);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Internally gets the request dispatcher
 */
PHP_METHOD(Phalcon_Tag, getDI)
{
	zval di;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;

	ZVAL_UNDEF(&di);
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	zephir_memory_observe(&di);
	zephir_read_static_property_ce(&di, phalcon_tag_ce, SL("container"), PH_NOISY_CC);
	if (Z_TYPE_P(&di) == IS_NULL) {
		ZEPHIR_CALL_CE_STATIC(&di, phalcon_di_di_ce, "getdefault", NULL, 0);
		zephir_check_call_status();
	}
	RETURN_CCTOR(&di);
}

/**
 * Returns an Escaper service from the default DI
 */
PHP_METHOD(Phalcon_Tag, getEscaperService)
{
	zval escaper, container, _0$$3, _1$$3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;

	ZVAL_UNDEF(&escaper);
	ZVAL_UNDEF(&container);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_1$$3);
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	zephir_memory_observe(&escaper);
	zephir_read_static_property_ce(&escaper, phalcon_tag_ce, SL("escaperService"), PH_NOISY_CC);
	if (Z_TYPE_P(&escaper) != IS_OBJECT) {
		ZEPHIR_CALL_SELF(&container, "getdi", NULL, 0);
		zephir_check_call_status();
		if (Z_TYPE_P(&container) == IS_NULL) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_tag_exception_ce, "A dependency injection container is required to access the 'escaper' service", "phalcon/Tag.zep", 403);
			return;
		}
		ZEPHIR_INIT_VAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "escaper");
		ZEPHIR_CALL_METHOD(&_0$$3, &container, "getshared", NULL, 0, &_1$$3);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(&escaper, &_0$$3);
		zephir_update_static_property_ce(phalcon_tag_ce, ZEND_STRL("escaperService"), &escaper);
	}
	RETURN_CCTOR(&escaper);
}

/**
 * Gets the current document title. The title will be automatically escaped.
 */
PHP_METHOD(Phalcon_Tag, getTitle)
{
	zval _1;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_10 = NULL, *_12 = NULL, *_19 = NULL, *_21 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *prepend_param = NULL, *append_param = NULL, __$true, items, output, title, documentTitle, documentAppendTitle, documentPrependTitle, documentTitleSeparator, escaper, _0, _2, _3, _4$$3, _6$$3, _5$$4, tmp$$5, *_7$$5, _8$$5, _9$$6, _11$$7, _13$$9, _15$$9, _14$$10, *_16$$11, _17$$11, _18$$12, _20$$13;
	zend_bool prepend, append;

	ZVAL_BOOL(&__$true, 1);
	ZVAL_UNDEF(&items);
	ZVAL_UNDEF(&output);
	ZVAL_UNDEF(&title);
	ZVAL_UNDEF(&documentTitle);
	ZVAL_UNDEF(&documentAppendTitle);
	ZVAL_UNDEF(&documentPrependTitle);
	ZVAL_UNDEF(&documentTitleSeparator);
	ZVAL_UNDEF(&escaper);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_6$$3);
	ZVAL_UNDEF(&_5$$4);
	ZVAL_UNDEF(&tmp$$5);
	ZVAL_UNDEF(&_8$$5);
	ZVAL_UNDEF(&_9$$6);
	ZVAL_UNDEF(&_11$$7);
	ZVAL_UNDEF(&_13$$9);
	ZVAL_UNDEF(&_15$$9);
	ZVAL_UNDEF(&_14$$10);
	ZVAL_UNDEF(&_17$$11);
	ZVAL_UNDEF(&_18$$12);
	ZVAL_UNDEF(&_20$$13);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(0, 2)
		Z_PARAM_OPTIONAL
		Z_PARAM_BOOL(prepend)
		Z_PARAM_BOOL(append)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 0, 2, &prepend_param, &append_param);
	if (!prepend_param) {
		prepend = 1;
	} else {
		}
	if (!append_param) {
		append = 1;
	} else {
		}
	ZEPHIR_INIT_VAR(&_1);
	zephir_create_array(&_1, 1, 0);
	zephir_array_update_string(&_1, SL("escape"), &__$true, PH_COPY | PH_SEPARATE);
	ZEPHIR_CALL_SELF(&_0, "getescaper", NULL, 0, &_1);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(&escaper, &_0);
	ZEPHIR_INIT_VAR(&items);
	array_init(&items);
	ZEPHIR_INIT_VAR(&output);
	ZVAL_STRING(&output, "");
	zephir_read_static_property_ce(&_2, phalcon_tag_ce, SL("documentTitle"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&documentTitle, &escaper, "escapehtml", NULL, 0, &_2);
	zephir_check_call_status();
	zephir_read_static_property_ce(&_3, phalcon_tag_ce, SL("documentTitleSeparator"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&documentTitleSeparator, &escaper, "escapehtml", NULL, 0, &_3);
	zephir_check_call_status();
	if (prepend) {
		zephir_read_static_property_ce(&_4$$3, phalcon_tag_ce, SL("documentPrependTitle"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_4$$3) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_5$$4);
			array_init(&_5$$4);
			zephir_update_static_property_ce(phalcon_tag_ce, ZEND_STRL("documentPrependTitle"), &_5$$4);
		}
		zephir_memory_observe(&_6$$3);
		zephir_read_static_property_ce(&_6$$3, phalcon_tag_ce, SL("documentPrependTitle"), PH_NOISY_CC);
		ZEPHIR_CPY_WRT(&documentPrependTitle, &_6$$3);
		if (!(ZEPHIR_IS_EMPTY(&documentPrependTitle))) {
			ZEPHIR_CALL_FUNCTION(&tmp$$5, "array_reverse", NULL, 297, &documentPrependTitle);
			zephir_check_call_status();
			zephir_is_iterable(&tmp$$5, 0, "phalcon/Tag.zep", 443);
			if (Z_TYPE_P(&tmp$$5) == IS_ARRAY) {
				ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&tmp$$5), _7$$5)
				{
					ZEPHIR_INIT_NVAR(&title);
					ZVAL_COPY(&title, _7$$5);
					ZEPHIR_CALL_METHOD(&_9$$6, &escaper, "escapehtml", &_10, 0, &title);
					zephir_check_call_status();
					zephir_array_append(&items, &_9$$6, PH_SEPARATE, "phalcon/Tag.zep", 441);
				} ZEND_HASH_FOREACH_END();
			} else {
				ZEPHIR_CALL_METHOD(NULL, &tmp$$5, "rewind", NULL, 0);
				zephir_check_call_status();
				while (1) {
					ZEPHIR_CALL_METHOD(&_8$$5, &tmp$$5, "valid", NULL, 0);
					zephir_check_call_status();
					if (!zend_is_true(&_8$$5)) {
						break;
					}
					ZEPHIR_CALL_METHOD(&title, &tmp$$5, "current", NULL, 0);
					zephir_check_call_status();
						ZEPHIR_CALL_METHOD(&_11$$7, &escaper, "escapehtml", &_12, 0, &title);
						zephir_check_call_status();
						zephir_array_append(&items, &_11$$7, PH_SEPARATE, "phalcon/Tag.zep", 441);
					ZEPHIR_CALL_METHOD(NULL, &tmp$$5, "next", NULL, 0);
					zephir_check_call_status();
				}
			}
			ZEPHIR_INIT_NVAR(&title);
		}
	}
	if (!(ZEPHIR_IS_EMPTY(&documentTitle))) {
		zephir_array_append(&items, &documentTitle, PH_SEPARATE, "phalcon/Tag.zep", 447);
	}
	if (append) {
		zephir_read_static_property_ce(&_13$$9, phalcon_tag_ce, SL("documentAppendTitle"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_13$$9) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_14$$10);
			array_init(&_14$$10);
			zephir_update_static_property_ce(phalcon_tag_ce, ZEND_STRL("documentAppendTitle"), &_14$$10);
		}
		zephir_memory_observe(&_15$$9);
		zephir_read_static_property_ce(&_15$$9, phalcon_tag_ce, SL("documentAppendTitle"), PH_NOISY_CC);
		ZEPHIR_CPY_WRT(&documentAppendTitle, &_15$$9);
		if (!(ZEPHIR_IS_EMPTY(&documentAppendTitle))) {
			zephir_is_iterable(&documentAppendTitle, 0, "phalcon/Tag.zep", 461);
			if (Z_TYPE_P(&documentAppendTitle) == IS_ARRAY) {
				ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&documentAppendTitle), _16$$11)
				{
					ZEPHIR_INIT_NVAR(&title);
					ZVAL_COPY(&title, _16$$11);
					ZEPHIR_CALL_METHOD(&_18$$12, &escaper, "escapehtml", &_19, 0, &title);
					zephir_check_call_status();
					zephir_array_append(&items, &_18$$12, PH_SEPARATE, "phalcon/Tag.zep", 459);
				} ZEND_HASH_FOREACH_END();
			} else {
				ZEPHIR_CALL_METHOD(NULL, &documentAppendTitle, "rewind", NULL, 0);
				zephir_check_call_status();
				while (1) {
					ZEPHIR_CALL_METHOD(&_17$$11, &documentAppendTitle, "valid", NULL, 0);
					zephir_check_call_status();
					if (!zend_is_true(&_17$$11)) {
						break;
					}
					ZEPHIR_CALL_METHOD(&title, &documentAppendTitle, "current", NULL, 0);
					zephir_check_call_status();
						ZEPHIR_CALL_METHOD(&_20$$13, &escaper, "escapehtml", &_21, 0, &title);
						zephir_check_call_status();
						zephir_array_append(&items, &_20$$13, PH_SEPARATE, "phalcon/Tag.zep", 459);
					ZEPHIR_CALL_METHOD(NULL, &documentAppendTitle, "next", NULL, 0);
					zephir_check_call_status();
				}
			}
			ZEPHIR_INIT_NVAR(&title);
		}
	}
	if (ZEPHIR_IS_EMPTY(&documentTitleSeparator)) {
		ZEPHIR_INIT_NVAR(&documentTitleSeparator);
		ZVAL_STRING(&documentTitleSeparator, "");
	}
	if (!(ZEPHIR_IS_EMPTY(&items))) {
		ZEPHIR_INIT_NVAR(&output);
		zephir_fast_join(&output, &documentTitleSeparator, &items);
	}
	RETURN_CCTOR(&output);
}

/**
 * Gets the current document title separator
 */
PHP_METHOD(Phalcon_Tag, getTitleSeparator)
{
	zval _0;

	ZVAL_UNDEF(&_0);
	zephir_read_static_property_ce(&_0, phalcon_tag_ce, SL("documentTitleSeparator"), PH_NOISY_CC | PH_READONLY);
	RETURN_CTORW(&_0);
}

/**
 * Returns a URL service from the default DI
 */
PHP_METHOD(Phalcon_Tag, getUrlService)
{
	zval url, container, _0$$3, _1$$3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;

	ZVAL_UNDEF(&url);
	ZVAL_UNDEF(&container);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_1$$3);
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	zephir_memory_observe(&url);
	zephir_read_static_property_ce(&url, phalcon_tag_ce, SL("urlService"), PH_NOISY_CC);
	if (Z_TYPE_P(&url) != IS_OBJECT) {
		ZEPHIR_CALL_SELF(&container, "getdi", NULL, 0);
		zephir_check_call_status();
		if (Z_TYPE_P(&container) == IS_NULL) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_tag_exception_ce, "A dependency injection container is required to access the 'url' service", "phalcon/Tag.zep", 498);
			return;
		}
		ZEPHIR_INIT_VAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "url");
		ZEPHIR_CALL_METHOD(&_0$$3, &container, "getshared", NULL, 0, &_1$$3);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(&url, &_0$$3);
		zephir_update_static_property_ce(phalcon_tag_ce, ZEND_STRL("urlService"), &url);
	}
	RETURN_CCTOR(&url);
}

/**
 * Every helper calls this function to check whether a component has a
 * predefined value using Phalcon\Tag::setDefault() or value from $_POST
 */
PHP_METHOD(Phalcon_Tag, getValue)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval params;
	zval *name, name_sub, *params_param = NULL, _POST, value, _0$$3;

	ZVAL_UNDEF(&name_sub);
	ZVAL_UNDEF(&_POST);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&params);
	ZEND_PARSE_PARAMETERS_START(1, 2)
		Z_PARAM_ZVAL(name)
		Z_PARAM_OPTIONAL
		Z_PARAM_ARRAY(params)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_get_global(&_POST, SL("_POST"));
	zephir_fetch_params(1, 1, 1, &name, &params_param);
	if (!params_param) {
		ZEPHIR_INIT_VAR(&params);
		array_init(&params);
	} else {
		zephir_get_arrval(&params, params_param);
	}
	zephir_memory_observe(&value);
	if (!(zephir_array_isset_string_fetch(&value, &params, SL("value"), 0))) {
		ZEPHIR_OBS_NVAR(&value);
		zephir_read_static_property_ce(&_0$$3, phalcon_tag_ce, SL("displayValues"), PH_NOISY_CC | PH_READONLY);
		if (!(zephir_array_isset_fetch(&value, &_0$$3, name, 0))) {
			ZEPHIR_OBS_NVAR(&value);
			if (!(zephir_array_isset_fetch(&value, &_POST, name, 0))) {
				RETURN_MM_NULL();
			}
		}
	}
	RETURN_CCTOR(&value);
}

/**
 * Check if a helper has a default value set using Phalcon\Tag::setDefault()
 * or value from $_POST
 */
PHP_METHOD(Phalcon_Tag, hasValue)
{
	zend_bool _1;
	zval *name, name_sub, _POST, _0;

	ZVAL_UNDEF(&name_sub);
	ZVAL_UNDEF(&_POST);
	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(name)
	ZEND_PARSE_PARAMETERS_END();
	zephir_get_global(&_POST, SL("_POST"));
	zephir_fetch_params_without_memory_grow(1, 0, &name);
	zephir_read_static_property_ce(&_0, phalcon_tag_ce, SL("displayValues"), PH_NOISY_CC | PH_READONLY);
	_1 = zephir_array_isset(&_0, name);
	if (!(_1)) {
		_1 = zephir_array_isset(&_POST, name);
	}
	RETURN_BOOL(_1);
}

/**
 * Builds a HTML input[type="hidden"] tag
 *
 * @param array parameters = [
 *     'class' => '',
 *     'name' => '',
 *     'src' => '',
 *     'id' => '',
 *     'value' => ''
 * ]
 */
PHP_METHOD(Phalcon_Tag, hiddenField)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL;
	zval *parameters, parameters_sub, _1;

	ZVAL_UNDEF(&parameters_sub);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(parameters)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &parameters);
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "hidden");
	ZEPHIR_RETURN_CALL_SELF("inputfield", &_0, 0, &_1, parameters);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Builds HTML IMG tags
 *
 * @param array|string parameters = [
 *     'src' => '',
 *     'class' => '',
 *     'id' => '',
 *     'name' => ''
 * ]
 */
PHP_METHOD(Phalcon_Tag, image)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_bool local;
	zval *parameters = NULL, parameters_sub, *local_param = NULL, __$null, params, code, src, _5, _6, _0$$5, _1$$8, _2$$9, _3$$9, _4$$9;

	ZVAL_UNDEF(&parameters_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&params);
	ZVAL_UNDEF(&code);
	ZVAL_UNDEF(&src);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_0$$5);
	ZVAL_UNDEF(&_1$$8);
	ZVAL_UNDEF(&_2$$9);
	ZVAL_UNDEF(&_3$$9);
	ZVAL_UNDEF(&_4$$9);
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(0, 2)
		Z_PARAM_OPTIONAL
		Z_PARAM_ZVAL_OR_NULL(parameters)
		Z_PARAM_BOOL(local)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 0, 2, &parameters, &local_param);
	if (!parameters) {
		parameters = &parameters_sub;
		parameters = &__$null;
	}
	if (!local_param) {
		local = 1;
	} else {
		}
	if (Z_TYPE_P(parameters) != IS_ARRAY) {
		ZEPHIR_INIT_VAR(&params);
		zephir_create_array(&params, 1, 0);
		zephir_array_fast_append(&params, parameters);
	} else {
		ZEPHIR_CPY_WRT(&params, parameters);
		if (zephir_array_isset_long(&params, 1)) {
			zephir_memory_observe(&_0$$5);
			zephir_array_fetch_long(&_0$$5, &params, 1, PH_NOISY, "phalcon/Tag.zep", 581);
			local = zephir_get_boolval(&_0$$5);
		}
	}
	if (!(zephir_array_isset_string(&params, SL("src")))) {
		zephir_memory_observe(&src);
		if (zephir_array_isset_long_fetch(&src, &params, 0, 0)) {
			zephir_array_update_string(&params, SL("src"), &src, PH_COPY | PH_SEPARATE);
		} else {
			ZEPHIR_INIT_VAR(&_1$$8);
			ZVAL_STRING(&_1$$8, "");
			zephir_array_update_string(&params, SL("src"), &_1$$8, PH_COPY | PH_SEPARATE);
		}
	}
	if (local) {
		ZEPHIR_CALL_SELF(&_2$$9, "geturlservice", NULL, 0);
		zephir_check_call_status();
		zephir_array_fetch_string(&_4$$9, &params, SL("src"), PH_NOISY | PH_READONLY, "phalcon/Tag.zep", 597);
		ZEPHIR_CALL_METHOD(&_3$$9, &_2$$9, "getstatic", NULL, 0, &_4$$9);
		zephir_check_call_status();
		zephir_array_update_string(&params, SL("src"), &_3$$9, PH_COPY | PH_SEPARATE);
	}
	ZEPHIR_INIT_VAR(&_5);
	ZVAL_STRING(&_5, "<img");
	ZEPHIR_CALL_SELF(&code, "renderattributes", NULL, 0, &_5, &params);
	zephir_check_call_status();
	zephir_read_static_property_ce(&_6, phalcon_tag_ce, SL("documentType"), PH_NOISY_CC | PH_READONLY);
	if (ZEPHIR_GT_LONG(&_6, 5)) {
		zephir_concat_self_str(&code, SL(" />"));
	} else {
		zephir_concat_self_str(&code, SL(">"));
	}
	RETURN_CCTOR(&code);
}

/**
 * Builds a HTML input[type="image"] tag
 *
 * @param array parameters = [
 *     'class' => '',
 *     'name' => '',
 *     'src' => '',
 *     'id' => ''
 * ]
 */
PHP_METHOD(Phalcon_Tag, imageInput)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL;
	zval *parameters, parameters_sub, _1, _2;

	ZVAL_UNDEF(&parameters_sub);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(parameters)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &parameters);
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "image");
	ZVAL_BOOL(&_2, 1);
	ZEPHIR_RETURN_CALL_SELF("inputfield", &_0, 0, &_1, parameters, &_2);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Builds a SCRIPT[type="javascript"] tag
 *
 * @param array|string parameters = [
 *     'local' => false,
 *     'src' => '',
 *     'type' => 'text/javascript'
 *     'rel' => ''
 * ]
 */
PHP_METHOD(Phalcon_Tag, javascriptInclude)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_bool local, _3;
	zval *parameters = NULL, parameters_sub, *local_param = NULL, __$null, params, code, _4, _11, _12, _0$$3, _1$$5, _2$$7, _5$$8, _6$$10, _7$$11, _8$$12, _9$$12, _10$$12;

	ZVAL_UNDEF(&parameters_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&params);
	ZVAL_UNDEF(&code);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_11);
	ZVAL_UNDEF(&_12);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_1$$5);
	ZVAL_UNDEF(&_2$$7);
	ZVAL_UNDEF(&_5$$8);
	ZVAL_UNDEF(&_6$$10);
	ZVAL_UNDEF(&_7$$11);
	ZVAL_UNDEF(&_8$$12);
	ZVAL_UNDEF(&_9$$12);
	ZVAL_UNDEF(&_10$$12);
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(0, 2)
		Z_PARAM_OPTIONAL
		Z_PARAM_ZVAL_OR_NULL(parameters)
		Z_PARAM_BOOL(local)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 0, 2, &parameters, &local_param);
	if (!parameters) {
		parameters = &parameters_sub;
		parameters = &__$null;
	}
	if (!local_param) {
		local = 1;
	} else {
		}
	if (Z_TYPE_P(parameters) != IS_ARRAY) {
		ZEPHIR_INIT_VAR(&params);
		zephir_create_array(&params, 2, 0);
		zephir_array_fast_append(&params, parameters);
		ZEPHIR_INIT_VAR(&_0$$3);
		ZVAL_BOOL(&_0$$3, local);
		zephir_array_fast_append(&params, &_0$$3);
	} else {
		ZEPHIR_CPY_WRT(&params, parameters);
	}
	if (zephir_array_isset_long(&params, 1)) {
		zephir_memory_observe(&_1$$5);
		zephir_array_fetch_long(&_1$$5, &params, 1, PH_NOISY, "phalcon/Tag.zep", 650);
		local = zephir_get_boolval(&_1$$5);
	} else {
		if (zephir_array_isset_string(&params, SL("local"))) {
			zephir_memory_observe(&_2$$7);
			zephir_array_fetch_string(&_2$$7, &params, SL("local"), PH_NOISY, "phalcon/Tag.zep", 653);
			local = zephir_get_boolval(&_2$$7);
			zephir_array_unset_string(&params, SL("local"), PH_SEPARATE);
		}
	}
	_3 = !(zephir_array_isset_string(&params, SL("type")));
	if (_3) {
		zephir_read_static_property_ce(&_4, phalcon_tag_ce, SL("documentType"), PH_NOISY_CC | PH_READONLY);
		_3 = ZEPHIR_LT_LONG(&_4, 5);
	}
	if (_3) {
		ZEPHIR_INIT_VAR(&_5$$8);
		ZVAL_STRING(&_5$$8, "text/javascript");
		zephir_array_update_string(&params, SL("type"), &_5$$8, PH_COPY | PH_SEPARATE);
	}
	if (!(zephir_array_isset_string(&params, SL("src")))) {
		if (zephir_array_isset_long(&params, 0)) {
			zephir_array_fetch_long(&_6$$10, &params, 0, PH_NOISY | PH_READONLY, "phalcon/Tag.zep", 665);
			zephir_array_update_string(&params, SL("src"), &_6$$10, PH_COPY | PH_SEPARATE);
		} else {
			ZEPHIR_INIT_VAR(&_7$$11);
			ZVAL_STRING(&_7$$11, "");
			zephir_array_update_string(&params, SL("src"), &_7$$11, PH_COPY | PH_SEPARATE);
		}
	}
	if (local) {
		ZEPHIR_CALL_SELF(&_8$$12, "geturlservice", NULL, 0);
		zephir_check_call_status();
		zephir_array_fetch_string(&_10$$12, &params, SL("src"), PH_NOISY | PH_READONLY, "phalcon/Tag.zep", 675);
		ZEPHIR_CALL_METHOD(&_9$$12, &_8$$12, "getstatic", NULL, 0, &_10$$12);
		zephir_check_call_status();
		zephir_array_update_string(&params, SL("src"), &_9$$12, PH_COPY | PH_SEPARATE);
	}
	ZEPHIR_INIT_VAR(&_11);
	ZVAL_STRING(&_11, "<script");
	ZEPHIR_CALL_SELF(&code, "renderattributes", NULL, 0, &_11, &params);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(&_11);
	ZEPHIR_GET_CONSTANT(&_11, "PHP_EOL");
	ZEPHIR_INIT_VAR(&_12);
	ZEPHIR_CONCAT_SV(&_12, "></script>", &_11);
	zephir_concat_self(&code, &_12);
	RETURN_CCTOR(&code);
}

/**
 * Builds a HTML A tag using framework conventions
 *
 * @param array|string $parameters = [
 *     'action' => '',
 *     'text' => '',
 *     'local' => false,
 *     'query' => '',
 *     'class' => '',
 *     'name' => '',
 *     'href' => '',
 *     'id' => ''
 * ]
 * @param string text
 * @param bool local
 */
PHP_METHOD(Phalcon_Tag, linkTo)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *parameters, parameters_sub, *text = NULL, text_sub, *local = NULL, local_sub, __$null, __$true, params, action, query, url, code, _0, _1, _2;

	ZVAL_UNDEF(&parameters_sub);
	ZVAL_UNDEF(&text_sub);
	ZVAL_UNDEF(&local_sub);
	ZVAL_NULL(&__$null);
	ZVAL_BOOL(&__$true, 1);
	ZVAL_UNDEF(&params);
	ZVAL_UNDEF(&action);
	ZVAL_UNDEF(&query);
	ZVAL_UNDEF(&url);
	ZVAL_UNDEF(&code);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 3)
		Z_PARAM_ZVAL(parameters)
		Z_PARAM_OPTIONAL
		Z_PARAM_ZVAL_OR_NULL(text)
		Z_PARAM_ZVAL(local)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 2, &parameters, &text, &local);
	if (!text) {
		text = &text_sub;
		ZEPHIR_CPY_WRT(text, &__$null);
	} else {
		ZEPHIR_SEPARATE_PARAM(text);
	}
	if (!local) {
		local = &local_sub;
		ZEPHIR_CPY_WRT(local, &__$true);
	} else {
		ZEPHIR_SEPARATE_PARAM(local);
	}
	if (Z_TYPE_P(parameters) != IS_ARRAY) {
		ZEPHIR_INIT_VAR(&params);
		zephir_create_array(&params, 3, 0);
		zephir_array_fast_append(&params, parameters);
		zephir_array_fast_append(&params, text);
		zephir_array_fast_append(&params, local);
	} else {
		ZEPHIR_CPY_WRT(&params, parameters);
	}
	zephir_memory_observe(&action);
	if (!(zephir_array_isset_long_fetch(&action, &params, 0, 0))) {
		ZEPHIR_OBS_NVAR(&action);
		if (!(zephir_array_isset_string_fetch(&action, &params, SL("action"), 0))) {
			ZEPHIR_INIT_NVAR(&action);
			ZVAL_STRING(&action, "");
		} else {
			zephir_array_unset_string(&params, SL("action"), PH_SEPARATE);
		}
	}
	ZEPHIR_OBS_NVAR(text);
	if (!(zephir_array_isset_long_fetch(text, &params, 1, 0))) {
		ZEPHIR_OBS_NVAR(text);
		if (!(zephir_array_isset_string_fetch(text, &params, SL("text"), 0))) {
			ZEPHIR_INIT_NVAR(text);
			ZVAL_STRING(text, "");
		} else {
			zephir_array_unset_string(&params, SL("text"), PH_SEPARATE);
		}
	}
	ZEPHIR_OBS_NVAR(local);
	if (!(zephir_array_isset_long_fetch(local, &params, 2, 0))) {
		ZEPHIR_OBS_NVAR(local);
		if (!(zephir_array_isset_string_fetch(local, &params, SL("local"), 0))) {
			ZEPHIR_INIT_NVAR(local);
			ZVAL_BOOL(local, 1);
		} else {
			zephir_array_unset_string(&params, SL("local"), PH_SEPARATE);
		}
	}
	zephir_memory_observe(&query);
	if (zephir_array_isset_string_fetch(&query, &params, SL("query"), 0)) {
		zephir_array_unset_string(&params, SL("query"), PH_SEPARATE);
	} else {
		ZEPHIR_INIT_NVAR(&query);
		ZVAL_NULL(&query);
	}
	ZEPHIR_CALL_SELF(&url, "geturlservice", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_0, &url, "get", NULL, 0, &action, &query, local);
	zephir_check_call_status();
	zephir_array_update_string(&params, SL("href"), &_0, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "<a");
	ZEPHIR_CALL_SELF(&code, "renderattributes", NULL, 0, &_1, &params);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_2);
	ZEPHIR_CONCAT_SVS(&_2, ">", text, "</a>");
	zephir_concat_self(&code, &_2);
	RETURN_CCTOR(&code);
}

/**
 * Builds a HTML input[type="month"] tag
 *
 * @param array parameters = [
 *     'class' => '',
 *     'name' => '',
 *     'src' => '',
 *     'id' => '',
 *     'value' => ''
 * ]
 */
PHP_METHOD(Phalcon_Tag, monthField)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL;
	zval *parameters, parameters_sub, _1;

	ZVAL_UNDEF(&parameters_sub);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(parameters)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &parameters);
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "month");
	ZEPHIR_RETURN_CALL_SELF("inputfield", &_0, 0, &_1, parameters);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Builds a HTML input[type="number"] tag
 *
 * @param array parameters = [
 *     'class' => '',
 *     'name' => '',
 *     'src' => '',
 *     'id' => '',
 *     'value' => ''
 * ]
 */
PHP_METHOD(Phalcon_Tag, numericField)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL;
	zval *parameters, parameters_sub, _1;

	ZVAL_UNDEF(&parameters_sub);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(parameters)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &parameters);
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "number");
	ZEPHIR_RETURN_CALL_SELF("inputfield", &_0, 0, &_1, parameters);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Builds a HTML input[type="password"] tag
 *
 * @param array parameters = [
 *     'class' => '',
 *     'name' => '',
 *     'src' => '',
 *     'id' => '',
 *     'value' => ''
 * ]
 */
PHP_METHOD(Phalcon_Tag, passwordField)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL;
	zval *parameters, parameters_sub, _1;

	ZVAL_UNDEF(&parameters_sub);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(parameters)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &parameters);
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "password");
	ZEPHIR_RETURN_CALL_SELF("inputfield", &_0, 0, &_1, parameters);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Prepends a text to current document title
 *
 * @param array|string title
 */
PHP_METHOD(Phalcon_Tag, prependTitle)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *title, title_sub, _0, _1$$3;

	ZVAL_UNDEF(&title_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(title)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &title);
	zephir_read_static_property_ce(&_0, phalcon_tag_ce, SL("documentPrependTitle"), PH_NOISY_CC | PH_READONLY);
	if (Z_TYPE_P(&_0) == IS_NULL) {
		ZEPHIR_INIT_VAR(&_1$$3);
		array_init(&_1$$3);
		zephir_update_static_property_ce(phalcon_tag_ce, ZEND_STRL("documentPrependTitle"), &_1$$3);
	}
	if (Z_TYPE_P(title) == IS_ARRAY) {
		zephir_update_static_property_ce(phalcon_tag_ce, ZEND_STRL("documentPrependTitle"), title);
	} else {
		zephir_update_static_property_array_multi_ce(phalcon_tag_ce, SL("documentPrependTitle"), title, SL("a"), 1);
	}
	ZEPHIR_MM_RESTORE();
}

/**
 * Parses the preload element passed and sets the necessary link headers
 */
PHP_METHOD(Phalcon_Tag, preload)
{
	zval _10$$5;
	zend_bool _1;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *parameters, parameters_sub, attributes, container, header, href, link, params, response, _2, _3, _0$$3, _4$$7, _5$$5, _6$$5, _7$$5, _8$$5, _9$$5;

	ZVAL_UNDEF(&parameters_sub);
	ZVAL_UNDEF(&attributes);
	ZVAL_UNDEF(&container);
	ZVAL_UNDEF(&header);
	ZVAL_UNDEF(&href);
	ZVAL_UNDEF(&link);
	ZVAL_UNDEF(&params);
	ZVAL_UNDEF(&response);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_4$$7);
	ZVAL_UNDEF(&_5$$5);
	ZVAL_UNDEF(&_6$$5);
	ZVAL_UNDEF(&_7$$5);
	ZVAL_UNDEF(&_8$$5);
	ZVAL_UNDEF(&_9$$5);
	ZVAL_UNDEF(&_10$$5);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(parameters)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &parameters);
	ZEPHIR_INIT_VAR(&params);
	array_init(&params);
	if (Z_TYPE_P(parameters) != IS_ARRAY) {
		ZEPHIR_INIT_VAR(&_0$$3);
		zephir_create_array(&_0$$3, 1, 0);
		zephir_array_fast_append(&_0$$3, parameters);
		ZEPHIR_CPY_WRT(&params, &_0$$3);
	} else {
		ZEPHIR_CPY_WRT(&params, parameters);
	}
	zephir_memory_observe(&href);
	zephir_array_isset_long_fetch(&href, &params, 0, 0);
	ZEPHIR_CALL_SELF(&container, "getdi", NULL, 0);
	zephir_check_call_status();
	_1 = zephir_is_true(&container);
	if (_1) {
		ZEPHIR_INIT_VAR(&_3);
		ZVAL_STRING(&_3, "response");
		ZEPHIR_CALL_METHOD(&_2, &container, "has", NULL, 0, &_3);
		zephir_check_call_status();
		_1 = zephir_is_true(&_2);
	}
	if (_1) {
		if (zephir_array_isset_long(&params, 1)) {
			zephir_memory_observe(&attributes);
			zephir_array_fetch_long(&attributes, &params, 1, PH_NOISY, "phalcon/Tag.zep", 842);
		} else {
			ZEPHIR_INIT_VAR(&_4$$7);
			zephir_create_array(&_4$$7, 1, 0);
			add_assoc_stringl_ex(&_4$$7, SL("as"), SL("style"));
			ZEPHIR_CPY_WRT(&attributes, &_4$$7);
		}
		ZEPHIR_INIT_VAR(&_5$$5);
		ZVAL_STRING(&_5$$5, "response");
		ZEPHIR_CALL_METHOD(&response, &container, "get", NULL, 0, &_5$$5);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&link);
		object_init_ex(&link, phalcon_html_link_link_ce);
		ZEPHIR_INIT_NVAR(&_5$$5);
		ZEPHIR_INIT_VAR(&_6$$5);
		ZVAL_STRING(&_6$$5, "'");
		ZEPHIR_INIT_VAR(&_7$$5);
		ZVAL_STRING(&_7$$5, "");
		zephir_fast_str_replace(&_5$$5, &_6$$5, &_7$$5, &href);
		ZEPHIR_INIT_VAR(&_8$$5);
		ZVAL_STRING(&_8$$5, "preload");
		ZEPHIR_CALL_METHOD(NULL, &link, "__construct", NULL, 499, &_8$$5, &_5$$5, &attributes);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(&_8$$5);
		object_init_ex(&_8$$5, phalcon_html_link_serializer_header_ce);
		if (zephir_has_constructor(&_8$$5)) {
			ZEPHIR_CALL_METHOD(NULL, &_8$$5, "__construct", NULL, 0);
			zephir_check_call_status();
		}

		ZEPHIR_INIT_VAR(&_10$$5);
		zephir_create_array(&_10$$5, 1, 0);
		zephir_array_fast_append(&_10$$5, &link);
		ZEPHIR_CALL_METHOD(&_9$$5, &_8$$5, "serialize", NULL, 500, &_10$$5);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&header);
		ZEPHIR_CONCAT_SV(&header, "Link: ", &_9$$5);
		ZEPHIR_CALL_METHOD(NULL, &response, "setrawheader", NULL, 0, &header);
		zephir_check_call_status();
	}
	RETURN_CCTOR(&href);
}

/**
 * Builds a HTML input[type="radio"] tag
 *
 * @param array parameters = [
 *     'class' => '',
 *     'name' => '',
 *     'src' => '',
 *     'id' => '',
 *     'value' => ''
 * ]
 */
PHP_METHOD(Phalcon_Tag, radioField)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL;
	zval *parameters, parameters_sub, _1;

	ZVAL_UNDEF(&parameters_sub);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(parameters)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &parameters);
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "radio");
	ZEPHIR_RETURN_CALL_SELF("inputfieldchecked", &_0, 0, &_1, parameters);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Builds a HTML input[type="range"] tag
 *
 * @param array parameters = [
 *     'class' => '',
 *     'name' => '',
 *     'src' => '',
 *     'id' => '',
 *     'value' => ''
 * ]
 */
PHP_METHOD(Phalcon_Tag, rangeField)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL;
	zval *parameters, parameters_sub, _1;

	ZVAL_UNDEF(&parameters_sub);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(parameters)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &parameters);
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "range");
	ZEPHIR_RETURN_CALL_SELF("inputfield", &_0, 0, &_1, parameters);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Renders parameters keeping order in their HTML attributes
 *
 * @param array attributes = [
 *     'rel' => null,
 *     'type' => null,
 *     'for' => null,
 *     'src' => null,
 *     'href' => null,
 *     'action' => null,
 *     'id' => null,
 *     'name' => null,
 *     'value' => null,
 *     'class' => null
 * ]
 */
PHP_METHOD(Phalcon_Tag, renderAttributes)
{
	zend_bool _13$$11, _14$$12, _21$$16, _22$$17;
	zend_string *_3, *_7, *_12;
	zend_ulong _2, _6, _11;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_18 = NULL, *_19 = NULL, *_26 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval attributes;
	zval *code_param = NULL, *attributes_param = NULL, __$null, order, escaper, attrs, attribute, value, escaped, key, newCode, *_0, _1, *_4, _5, _8, *_9, _10, _20$$12, _15$$13, _16$$13, _17$$13, _27$$17, _23$$18, _24$$18, _25$$18;
	zval code;

	ZVAL_UNDEF(&code);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&order);
	ZVAL_UNDEF(&escaper);
	ZVAL_UNDEF(&attrs);
	ZVAL_UNDEF(&attribute);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&escaped);
	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&newCode);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&_10);
	ZVAL_UNDEF(&_20$$12);
	ZVAL_UNDEF(&_15$$13);
	ZVAL_UNDEF(&_16$$13);
	ZVAL_UNDEF(&_17$$13);
	ZVAL_UNDEF(&_27$$17);
	ZVAL_UNDEF(&_23$$18);
	ZVAL_UNDEF(&_24$$18);
	ZVAL_UNDEF(&_25$$18);
	ZVAL_UNDEF(&attributes);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_STR(code)
		Z_PARAM_ARRAY(attributes)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 2, 0, &code_param, &attributes_param);
	if (UNEXPECTED(Z_TYPE_P(code_param) != IS_STRING && Z_TYPE_P(code_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'code' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(code_param) == IS_STRING)) {
		zephir_get_strval(&code, code_param);
	} else {
		ZEPHIR_INIT_VAR(&code);
	}
	ZEPHIR_OBS_COPY_OR_DUP(&attributes, attributes_param);
	ZEPHIR_INIT_VAR(&order);
	zephir_create_array(&order, 10, 0);
	zephir_array_update_string(&order, SL("rel"), &__$null, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&order, SL("type"), &__$null, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&order, SL("for"), &__$null, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&order, SL("src"), &__$null, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&order, SL("href"), &__$null, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&order, SL("action"), &__$null, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&order, SL("id"), &__$null, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&order, SL("name"), &__$null, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&order, SL("value"), &__$null, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&order, SL("class"), &__$null, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_VAR(&attrs);
	array_init(&attrs);
	zephir_is_iterable(&order, 0, "phalcon/Tag.zep", 937);
	if (Z_TYPE_P(&order) == IS_ARRAY) {
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&order), _2, _3, _0)
		{
			ZEPHIR_INIT_NVAR(&key);
			if (_3 != NULL) { 
				ZVAL_STR_COPY(&key, _3);
			} else {
				ZVAL_LONG(&key, _2);
			}
			ZEPHIR_INIT_NVAR(&value);
			ZVAL_COPY(&value, _0);
			ZEPHIR_OBS_NVAR(&attribute);
			if (zephir_array_isset_fetch(&attribute, &attributes, &key, 0)) {
				zephir_array_update_zval(&attrs, &key, &attribute, PH_COPY | PH_SEPARATE);
			}
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &order, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_1, &order, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_1)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&key, &order, "key", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&value, &order, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_OBS_NVAR(&attribute);
				if (zephir_array_isset_fetch(&attribute, &attributes, &key, 0)) {
					zephir_array_update_zval(&attrs, &key, &attribute, PH_COPY | PH_SEPARATE);
				}
			ZEPHIR_CALL_METHOD(NULL, &order, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&value);
	ZEPHIR_INIT_NVAR(&key);
	zephir_is_iterable(&attributes, 0, "phalcon/Tag.zep", 943);
	if (Z_TYPE_P(&attributes) == IS_ARRAY) {
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&attributes), _6, _7, _4)
		{
			ZEPHIR_INIT_NVAR(&key);
			if (_7 != NULL) { 
				ZVAL_STR_COPY(&key, _7);
			} else {
				ZVAL_LONG(&key, _6);
			}
			ZEPHIR_INIT_NVAR(&value);
			ZVAL_COPY(&value, _4);
			if (!(zephir_array_isset(&attrs, &key))) {
				zephir_array_update_zval(&attrs, &key, &value, PH_COPY | PH_SEPARATE);
			}
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &attributes, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_5, &attributes, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_5)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&key, &attributes, "key", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&value, &attributes, "current", NULL, 0);
			zephir_check_call_status();
				if (!(zephir_array_isset(&attrs, &key))) {
					zephir_array_update_zval(&attrs, &key, &value, PH_COPY | PH_SEPARATE);
				}
			ZEPHIR_CALL_METHOD(NULL, &attributes, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&value);
	ZEPHIR_INIT_NVAR(&key);
	ZEPHIR_CALL_SELF(&_8, "getescaper", NULL, 0, &attributes);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(&escaper, &_8);
	zephir_array_unset_string(&attrs, SL("escape"), PH_SEPARATE);
	ZEPHIR_CPY_WRT(&newCode, &code);
	zephir_is_iterable(&attrs, 0, "phalcon/Tag.zep", 967);
	if (Z_TYPE_P(&attrs) == IS_ARRAY) {
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&attrs), _11, _12, _9)
		{
			ZEPHIR_INIT_NVAR(&key);
			if (_12 != NULL) { 
				ZVAL_STR_COPY(&key, _12);
			} else {
				ZVAL_LONG(&key, _11);
			}
			ZEPHIR_INIT_NVAR(&value);
			ZVAL_COPY(&value, _9);
			_13$$11 = Z_TYPE_P(&key) == IS_STRING;
			if (_13$$11) {
				_13$$11 = Z_TYPE_P(&value) != IS_NULL;
			}
			if (_13$$11) {
				_14$$12 = Z_TYPE_P(&value) == IS_ARRAY;
				if (!(_14$$12)) {
					_14$$12 = Z_TYPE_P(&value) == IS_RESOURCE;
				}
				if (UNEXPECTED(_14$$12)) {
					ZEPHIR_INIT_NVAR(&_15$$13);
					object_init_ex(&_15$$13, phalcon_tag_exception_ce);
					ZEPHIR_INIT_NVAR(&_16$$13);
					zephir_gettype(&_16$$13, &value);
					ZEPHIR_INIT_NVAR(&_17$$13);
					ZEPHIR_CONCAT_SVSVS(&_17$$13, "Value at index: '", &key, "' type: '", &_16$$13, "' cannot be rendered");
					ZEPHIR_CALL_METHOD(NULL, &_15$$13, "__construct", &_18, 33, &_17$$13);
					zephir_check_call_status();
					zephir_throw_exception_debug(&_15$$13, "phalcon/Tag.zep", 954);
					ZEPHIR_MM_RESTORE();
					return;
				}
				if (zephir_is_true(&escaper)) {
					ZEPHIR_CALL_METHOD(&escaped, &escaper, "escapehtmlattr", &_19, 0, &value);
					zephir_check_call_status();
				} else {
					ZEPHIR_CPY_WRT(&escaped, &value);
				}
				ZEPHIR_INIT_NVAR(&_20$$12);
				ZEPHIR_CONCAT_SVSVS(&_20$$12, " ", &key, "=\"", &escaped, "\"");
				zephir_concat_self(&newCode, &_20$$12);
			}
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &attrs, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_10, &attrs, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_10)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&key, &attrs, "key", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&value, &attrs, "current", NULL, 0);
			zephir_check_call_status();
				_21$$16 = Z_TYPE_P(&key) == IS_STRING;
				if (_21$$16) {
					_21$$16 = Z_TYPE_P(&value) != IS_NULL;
				}
				if (_21$$16) {
					_22$$17 = Z_TYPE_P(&value) == IS_ARRAY;
					if (!(_22$$17)) {
						_22$$17 = Z_TYPE_P(&value) == IS_RESOURCE;
					}
					if (UNEXPECTED(_22$$17)) {
						ZEPHIR_INIT_NVAR(&_23$$18);
						object_init_ex(&_23$$18, phalcon_tag_exception_ce);
						ZEPHIR_INIT_NVAR(&_24$$18);
						zephir_gettype(&_24$$18, &value);
						ZEPHIR_INIT_NVAR(&_25$$18);
						ZEPHIR_CONCAT_SVSVS(&_25$$18, "Value at index: '", &key, "' type: '", &_24$$18, "' cannot be rendered");
						ZEPHIR_CALL_METHOD(NULL, &_23$$18, "__construct", &_18, 33, &_25$$18);
						zephir_check_call_status();
						zephir_throw_exception_debug(&_23$$18, "phalcon/Tag.zep", 954);
						ZEPHIR_MM_RESTORE();
						return;
					}
					if (zephir_is_true(&escaper)) {
						ZEPHIR_CALL_METHOD(&escaped, &escaper, "escapehtmlattr", &_26, 0, &value);
						zephir_check_call_status();
					} else {
						ZEPHIR_CPY_WRT(&escaped, &value);
					}
					ZEPHIR_INIT_NVAR(&_27$$17);
					ZEPHIR_CONCAT_SVSVS(&_27$$17, " ", &key, "=\"", &escaped, "\"");
					zephir_concat_self(&newCode, &_27$$17);
				}
			ZEPHIR_CALL_METHOD(NULL, &attrs, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&value);
	ZEPHIR_INIT_NVAR(&key);
	RETURN_CCTOR(&newCode);
}

/**
 * Renders the title with title tags. The title is automatically escaped
 */
PHP_METHOD(Phalcon_Tag, renderTitle)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *prepend_param = NULL, *append_param = NULL, _0, _1, _2, _3;
	zend_bool prepend, append;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZEND_PARSE_PARAMETERS_START(0, 2)
		Z_PARAM_OPTIONAL
		Z_PARAM_BOOL(prepend)
		Z_PARAM_BOOL(append)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 0, 2, &prepend_param, &append_param);
	if (!prepend_param) {
		prepend = 1;
	} else {
		}
	if (!append_param) {
		append = 1;
	} else {
		}
	if (prepend) {
		ZVAL_BOOL(&_1, 1);
	} else {
		ZVAL_BOOL(&_1, 0);
	}
	if (append) {
		ZVAL_BOOL(&_2, 1);
	} else {
		ZVAL_BOOL(&_2, 0);
	}
	ZEPHIR_CALL_SELF(&_0, "gettitle", NULL, 0, &_1, &_2);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_3);
	ZEPHIR_GET_CONSTANT(&_3, "PHP_EOL");
	ZEPHIR_CONCAT_SVSV(return_value, "<title>", &_0, "</title>", &_3);
	RETURN_MM();
}

/**
 * Resets the request and internal values to avoid those fields will have
 * any default value.
 *
 * @deprecated Will be removed in 4.0.0
 */
PHP_METHOD(Phalcon_Tag, resetInput)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval __$null, _0, _1, _2;

	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	ZEPHIR_INIT_VAR(&_0);
	array_init(&_0);
	zephir_update_static_property_ce(phalcon_tag_ce, ZEND_STRL("displayValues"), &_0);
	zephir_update_static_property_ce(phalcon_tag_ce, ZEND_STRL("documentTitle"), &__$null);
	ZEPHIR_INIT_VAR(&_1);
	array_init(&_1);
	zephir_update_static_property_ce(phalcon_tag_ce, ZEND_STRL("documentAppendTitle"), &_1);
	ZEPHIR_INIT_VAR(&_2);
	array_init(&_2);
	zephir_update_static_property_ce(phalcon_tag_ce, ZEND_STRL("documentPrependTitle"), &_2);
	zephir_update_static_property_ce(phalcon_tag_ce, ZEND_STRL("documentTitleSeparator"), &__$null);
	ZEPHIR_MM_RESTORE();
}

/**
 * Builds a HTML input[type="search"] tag
 *
 * @param array parameters = [
 *     'class' => '',
 *     'name' => '',
 *     'src' => '',
 *     'id' => '',
 *     'value' => ''
 * ]
 */
PHP_METHOD(Phalcon_Tag, searchField)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL;
	zval *parameters, parameters_sub, _1;

	ZVAL_UNDEF(&parameters_sub);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(parameters)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &parameters);
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "search");
	ZEPHIR_RETURN_CALL_SELF("inputfield", &_0, 0, &_1, parameters);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Builds a HTML SELECT tag using a Phalcon\Mvc\Model resultset as options
 *
 * @param array parameters = [
 *     'id' => '',
 *     'name' => '',
 *     'value' => '',
 *     'useEmpty' => false,
 *     'emptyValue' => '',
 *     'emptyText' => '',
 * ]
 */
PHP_METHOD(Phalcon_Tag, select)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *parameters, parameters_sub, *data = NULL, data_sub, __$null;

	ZVAL_UNDEF(&parameters_sub);
	ZVAL_UNDEF(&data_sub);
	ZVAL_NULL(&__$null);
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 2)
		Z_PARAM_ZVAL(parameters)
		Z_PARAM_OPTIONAL
		Z_PARAM_ZVAL_OR_NULL(data)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 1, &parameters, &data);
	if (!data) {
		data = &data_sub;
		data = &__$null;
	}
	ZEPHIR_RETURN_CALL_CE_STATIC(phalcon_tag_select_ce, "selectfield", NULL, 0, parameters, data);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Builds a HTML SELECT tag using a PHP array for options
 *
 * @param array parameters = [
 *     'id' => '',
 *     'name' => '',
 *     'value' => '',
 *     'useEmpty' => false,
 *     'emptyValue' => '',
 *     'emptyText' => '',
 * ]
 */
PHP_METHOD(Phalcon_Tag, selectStatic)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *parameters, parameters_sub, *data = NULL, data_sub, __$null;

	ZVAL_UNDEF(&parameters_sub);
	ZVAL_UNDEF(&data_sub);
	ZVAL_NULL(&__$null);
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 2)
		Z_PARAM_ZVAL(parameters)
		Z_PARAM_OPTIONAL
		Z_PARAM_ZVAL_OR_NULL(data)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 1, &parameters, &data);
	if (!data) {
		data = &data_sub;
		data = &__$null;
	}
	ZEPHIR_RETURN_CALL_CE_STATIC(phalcon_tag_select_ce, "selectfield", NULL, 0, parameters, data);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Set autoescape mode in generated HTML
 */
PHP_METHOD(Phalcon_Tag, setAutoescape)
{
	zval *autoescape_param = NULL, _0;
	zend_bool autoescape;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_BOOL(autoescape)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &autoescape_param);
	ZVAL_UNDEF(&_0);
	ZVAL_BOOL(&_0, autoescape);
	zephir_update_static_property_ce(phalcon_tag_ce, ZEND_STRL("autoEscape"), &_0);
}

/**
 * Assigns default values to generated tags by helpers
 */
PHP_METHOD(Phalcon_Tag, setDefault)
{
	zend_bool _0$$3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *id_param = NULL, *value, value_sub;
	zval id;

	ZVAL_UNDEF(&id);
	ZVAL_UNDEF(&value_sub);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_STR(id)
		Z_PARAM_ZVAL(value)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 2, 0, &id_param, &value);
	if (UNEXPECTED(Z_TYPE_P(id_param) != IS_STRING && Z_TYPE_P(id_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'id' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(id_param) == IS_STRING)) {
		zephir_get_strval(&id, id_param);
	} else {
		ZEPHIR_INIT_VAR(&id);
	}
	if (Z_TYPE_P(value) != IS_NULL) {
		_0$$3 = Z_TYPE_P(value) == IS_ARRAY;
		if (!(_0$$3)) {
			_0$$3 = Z_TYPE_P(value) == IS_OBJECT;
		}
		if (UNEXPECTED(_0$$3)) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_tag_exception_ce, "Only scalar values can be assigned to UI components", "phalcon/Tag.zep", 1060);
			return;
		}
	}
	zephir_update_static_property_array_multi_ce(phalcon_tag_ce, SL("displayValues"), value, SL("z"), 1, &id);
	ZEPHIR_MM_RESTORE();
}

/**
 * Assigns default values to generated tags by helpers
 */
PHP_METHOD(Phalcon_Tag, setDefaults)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_bool merge, _0;
	zval *values_param = NULL, *merge_param = NULL, _1, _2$$3, _3$$3;
	zval values;

	ZVAL_UNDEF(&values);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$3);
	ZEND_PARSE_PARAMETERS_START(1, 2)
		Z_PARAM_ARRAY(values)
		Z_PARAM_OPTIONAL
		Z_PARAM_BOOL(merge)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 1, &values_param, &merge_param);
	ZEPHIR_OBS_COPY_OR_DUP(&values, values_param);
	if (!merge_param) {
		merge = 0;
	} else {
		}
	_0 = merge;
	if (_0) {
		zephir_memory_observe(&_1);
		zephir_read_static_property_ce(&_1, phalcon_tag_ce, SL("displayValues"), PH_NOISY_CC);
		_0 = Z_TYPE_P(&_1) == IS_ARRAY;
	}
	if (_0) {
		ZEPHIR_INIT_VAR(&_2$$3);
		zephir_read_static_property_ce(&_3$$3, phalcon_tag_ce, SL("displayValues"), PH_NOISY_CC | PH_READONLY);
		zephir_fast_array_merge(&_2$$3, &_3$$3, &values);
		zephir_update_static_property_ce(phalcon_tag_ce, ZEND_STRL("displayValues"), &_2$$3);
	} else {
		zephir_update_static_property_ce(phalcon_tag_ce, ZEND_STRL("displayValues"), &values);
	}
	ZEPHIR_MM_RESTORE();
}

/**
 * Sets the dependency injector container.
 */
PHP_METHOD(Phalcon_Tag, setDI)
{
	zval *container, container_sub;

	ZVAL_UNDEF(&container_sub);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(container, phalcon_di_diinterface_ce)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &container);
	zephir_update_static_property_ce(phalcon_tag_ce, ZEND_STRL("container"), container);
}

/**
 * Set the document type of content
 */
PHP_METHOD(Phalcon_Tag, setDocType)
{
	zend_bool _0;
	zval *doctype_param = NULL, _1$$3, _2$$4;
	zend_long doctype;

	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$4);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(doctype)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &doctype_param);
	_0 = doctype < 1;
	if (!(_0)) {
		_0 = doctype > 11;
	}
	if (_0) {
		ZVAL_UNDEF(&_1$$3);
		ZVAL_LONG(&_1$$3, 5);
		zephir_update_static_property_ce(phalcon_tag_ce, ZEND_STRL("documentType"), &_1$$3);
	} else {
		ZVAL_UNDEF(&_2$$4);
		ZVAL_LONG(&_2$$4, doctype);
		zephir_update_static_property_ce(phalcon_tag_ce, ZEND_STRL("documentType"), &_2$$4);
	}
}

/**
 * Set the title of view content
 */
PHP_METHOD(Phalcon_Tag, setTitle)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *title_param = NULL;
	zval title;

	ZVAL_UNDEF(&title);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(title)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &title_param);
	zephir_get_strval(&title, title_param);
	zephir_update_static_property_ce(phalcon_tag_ce, ZEND_STRL("documentTitle"), &title);
	ZEPHIR_MM_RESTORE();
}

/**
 * Set the title separator of view content
 */
PHP_METHOD(Phalcon_Tag, setTitleSeparator)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *titleSeparator_param = NULL;
	zval titleSeparator;

	ZVAL_UNDEF(&titleSeparator);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(titleSeparator)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &titleSeparator_param);
	zephir_get_strval(&titleSeparator, titleSeparator_param);
	zephir_update_static_property_ce(phalcon_tag_ce, ZEND_STRL("documentTitleSeparator"), &titleSeparator);
	ZEPHIR_MM_RESTORE();
}

/**
 * Builds a LINK[rel="stylesheet"] tag
 */
PHP_METHOD(Phalcon_Tag, stylesheetLink)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_bool local;
	zval *parameters = NULL, parameters_sub, *local_param = NULL, __$null, params, code, _10, _11, _0$$3, _1$$5, _2$$7, _3$$8, _4$$10, _5$$11, _6$$12, _7$$12, _8$$12, _9$$13, _12$$14, _13$$14, _14$$15, _15$$15;

	ZVAL_UNDEF(&parameters_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&params);
	ZVAL_UNDEF(&code);
	ZVAL_UNDEF(&_10);
	ZVAL_UNDEF(&_11);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_1$$5);
	ZVAL_UNDEF(&_2$$7);
	ZVAL_UNDEF(&_3$$8);
	ZVAL_UNDEF(&_4$$10);
	ZVAL_UNDEF(&_5$$11);
	ZVAL_UNDEF(&_6$$12);
	ZVAL_UNDEF(&_7$$12);
	ZVAL_UNDEF(&_8$$12);
	ZVAL_UNDEF(&_9$$13);
	ZVAL_UNDEF(&_12$$14);
	ZVAL_UNDEF(&_13$$14);
	ZVAL_UNDEF(&_14$$15);
	ZVAL_UNDEF(&_15$$15);
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(0, 2)
		Z_PARAM_OPTIONAL
		Z_PARAM_ZVAL_OR_NULL(parameters)
		Z_PARAM_BOOL(local)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 0, 2, &parameters, &local_param);
	if (!parameters) {
		parameters = &parameters_sub;
		parameters = &__$null;
	}
	if (!local_param) {
		local = 1;
	} else {
		}
	if (Z_TYPE_P(parameters) != IS_ARRAY) {
		ZEPHIR_INIT_VAR(&params);
		zephir_create_array(&params, 2, 0);
		zephir_array_fast_append(&params, parameters);
		ZEPHIR_INIT_VAR(&_0$$3);
		ZVAL_BOOL(&_0$$3, local);
		zephir_array_fast_append(&params, &_0$$3);
	} else {
		ZEPHIR_CPY_WRT(&params, parameters);
	}
	if (zephir_array_isset_long(&params, 1)) {
		zephir_memory_observe(&_1$$5);
		zephir_array_fetch_long(&_1$$5, &params, 1, PH_NOISY, "phalcon/Tag.zep", 1129);
		local = zephir_get_boolval(&_1$$5);
	} else {
		if (zephir_array_isset_string(&params, SL("local"))) {
			zephir_memory_observe(&_2$$7);
			zephir_array_fetch_string(&_2$$7, &params, SL("local"), PH_NOISY, "phalcon/Tag.zep", 1132);
			local = zephir_get_boolval(&_2$$7);
			zephir_array_unset_string(&params, SL("local"), PH_SEPARATE);
		}
	}
	if (!(zephir_array_isset_string(&params, SL("type")))) {
		ZEPHIR_INIT_VAR(&_3$$8);
		ZVAL_STRING(&_3$$8, "text/css");
		zephir_array_update_string(&params, SL("type"), &_3$$8, PH_COPY | PH_SEPARATE);
	}
	if (!(zephir_array_isset_string(&params, SL("href")))) {
		if (zephir_array_isset_long(&params, 0)) {
			zephir_array_fetch_long(&_4$$10, &params, 0, PH_NOISY | PH_READONLY, "phalcon/Tag.zep", 1144);
			zephir_array_update_string(&params, SL("href"), &_4$$10, PH_COPY | PH_SEPARATE);
		} else {
			ZEPHIR_INIT_VAR(&_5$$11);
			ZVAL_STRING(&_5$$11, "");
			zephir_array_update_string(&params, SL("href"), &_5$$11, PH_COPY | PH_SEPARATE);
		}
	}
	if (local) {
		ZEPHIR_CALL_SELF(&_6$$12, "geturlservice", NULL, 0);
		zephir_check_call_status();
		zephir_array_fetch_string(&_8$$12, &params, SL("href"), PH_NOISY | PH_READONLY, "phalcon/Tag.zep", 1156);
		ZEPHIR_CALL_METHOD(&_7$$12, &_6$$12, "getstatic", NULL, 0, &_8$$12);
		zephir_check_call_status();
		zephir_array_update_string(&params, SL("href"), &_7$$12, PH_COPY | PH_SEPARATE);
	}
	if (!(zephir_array_isset_string(&params, SL("rel")))) {
		ZEPHIR_INIT_VAR(&_9$$13);
		ZVAL_STRING(&_9$$13, "stylesheet");
		zephir_array_update_string(&params, SL("rel"), &_9$$13, PH_COPY | PH_SEPARATE);
	}
	ZEPHIR_INIT_VAR(&_10);
	ZVAL_STRING(&_10, "<link");
	ZEPHIR_CALL_SELF(&code, "renderattributes", NULL, 0, &_10, &params);
	zephir_check_call_status();
	zephir_read_static_property_ce(&_11, phalcon_tag_ce, SL("documentType"), PH_NOISY_CC | PH_READONLY);
	if (ZEPHIR_GT_LONG(&_11, 5)) {
		ZEPHIR_INIT_VAR(&_12$$14);
		ZEPHIR_GET_CONSTANT(&_12$$14, "PHP_EOL");
		ZEPHIR_INIT_VAR(&_13$$14);
		ZEPHIR_CONCAT_SV(&_13$$14, " />", &_12$$14);
		zephir_concat_self(&code, &_13$$14);
	} else {
		ZEPHIR_INIT_VAR(&_14$$15);
		ZEPHIR_GET_CONSTANT(&_14$$15, "PHP_EOL");
		ZEPHIR_INIT_VAR(&_15$$15);
		ZEPHIR_CONCAT_SV(&_15$$15, ">", &_14$$15);
		zephir_concat_self(&code, &_15$$15);
	}
	RETURN_CCTOR(&code);
}

/**
 * Builds a HTML input[type="submit"] tag
 */
PHP_METHOD(Phalcon_Tag, submitButton)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL;
	zval *parameters, parameters_sub, _1, _2;

	ZVAL_UNDEF(&parameters_sub);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(parameters)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &parameters);
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "submit");
	ZVAL_BOOL(&_2, 1);
	ZEPHIR_RETURN_CALL_SELF("inputfield", &_0, 0, &_1, parameters, &_2);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Builds a HTML tag
 */
PHP_METHOD(Phalcon_Tag, tagHtml)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_bool selfClose, onlyStart, useEol;
	zval *tagName_param = NULL, *parameters = NULL, parameters_sub, *selfClose_param = NULL, *onlyStart_param = NULL, *useEol_param = NULL, __$null, params, localCode, _1, _3$$11;
	zval tagName, _0, _2$$10;

	ZVAL_UNDEF(&tagName);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2$$10);
	ZVAL_UNDEF(&parameters_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&params);
	ZVAL_UNDEF(&localCode);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_3$$11);
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 5)
		Z_PARAM_STR(tagName)
		Z_PARAM_OPTIONAL
		Z_PARAM_ZVAL_OR_NULL(parameters)
		Z_PARAM_BOOL(selfClose)
		Z_PARAM_BOOL(onlyStart)
		Z_PARAM_BOOL(useEol)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 4, &tagName_param, &parameters, &selfClose_param, &onlyStart_param, &useEol_param);
	zephir_get_strval(&tagName, tagName_param);
	if (!parameters) {
		parameters = &parameters_sub;
		parameters = &__$null;
	}
	if (!selfClose_param) {
		selfClose = 0;
	} else {
		}
	if (!onlyStart_param) {
		onlyStart = 0;
	} else {
		}
	if (!useEol_param) {
		useEol = 0;
	} else {
		}
	if (Z_TYPE_P(parameters) != IS_ARRAY) {
		ZEPHIR_INIT_VAR(&params);
		zephir_create_array(&params, 1, 0);
		zephir_array_fast_append(&params, parameters);
	} else {
		ZEPHIR_CPY_WRT(&params, parameters);
	}
	ZEPHIR_INIT_VAR(&_0);
	ZEPHIR_CONCAT_SV(&_0, "<", &tagName);
	ZEPHIR_CALL_SELF(&localCode, "renderattributes", NULL, 0, &_0, &params);
	zephir_check_call_status();
	zephir_read_static_property_ce(&_1, phalcon_tag_ce, SL("documentType"), PH_NOISY_CC | PH_READONLY);
	if (ZEPHIR_GT_LONG(&_1, 5)) {
		if (selfClose) {
			zephir_concat_self_str(&localCode, SL(" />"));
		} else {
			zephir_concat_self_str(&localCode, SL(">"));
		}
	} else {
		if (onlyStart) {
			zephir_concat_self_str(&localCode, SL(">"));
		} else {
			ZEPHIR_INIT_VAR(&_2$$10);
			ZEPHIR_CONCAT_SVS(&_2$$10, "></", &tagName, ">");
			zephir_concat_self(&localCode, &_2$$10);
		}
	}
	if (useEol) {
		ZEPHIR_INIT_VAR(&_3$$11);
		ZEPHIR_GET_CONSTANT(&_3$$11, "PHP_EOL");
		zephir_concat_self(&localCode, &_3$$11);
	}
	RETURN_CCTOR(&localCode);
}

/**
 * Builds a HTML tag closing tag
 */
PHP_METHOD(Phalcon_Tag, tagHtmlClose)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_bool useEol;
	zval *tagName_param = NULL, *useEol_param = NULL, _0$$3;
	zval tagName;

	ZVAL_UNDEF(&tagName);
	ZVAL_UNDEF(&_0$$3);
	ZEND_PARSE_PARAMETERS_START(1, 2)
		Z_PARAM_STR(tagName)
		Z_PARAM_OPTIONAL
		Z_PARAM_BOOL(useEol)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 1, &tagName_param, &useEol_param);
	zephir_get_strval(&tagName, tagName_param);
	if (!useEol_param) {
		useEol = 0;
	} else {
		}
	if (useEol) {
		ZEPHIR_INIT_VAR(&_0$$3);
		ZEPHIR_GET_CONSTANT(&_0$$3, "PHP_EOL");
		ZEPHIR_CONCAT_SVSV(return_value, "</", &tagName, ">", &_0$$3);
		RETURN_MM();
	}
	ZEPHIR_CONCAT_SVS(return_value, "</", &tagName, ">");
	RETURN_MM();
}

/**
 * Builds a HTML input[type="tel"] tag
 *
 * @param array parameters = [
 *     'id' => '',
 *     'name' => '',
 *     'value' => '',
 *     'class' => ''
 * ]
 */
PHP_METHOD(Phalcon_Tag, telField)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL;
	zval *parameters, parameters_sub, _1;

	ZVAL_UNDEF(&parameters_sub);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(parameters)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &parameters);
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "tel");
	ZEPHIR_RETURN_CALL_SELF("inputfield", &_0, 0, &_1, parameters);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Builds a HTML TEXTAREA tag
 *
 * @paraym array parameters = [
 *     'id' => '',
 *     'name' => '',
 *     'value' => '',
 *     'class' => ''
 * ]
 */
PHP_METHOD(Phalcon_Tag, textArea)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *parameters, parameters_sub, params, id, name, content, code, _1, _2, _3, _0$$6;

	ZVAL_UNDEF(&parameters_sub);
	ZVAL_UNDEF(&params);
	ZVAL_UNDEF(&id);
	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&content);
	ZVAL_UNDEF(&code);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_0$$6);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(parameters)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &parameters);
	if (Z_TYPE_P(parameters) != IS_ARRAY) {
		ZEPHIR_INIT_VAR(&params);
		zephir_create_array(&params, 1, 0);
		zephir_array_fast_append(&params, parameters);
	} else {
		ZEPHIR_CPY_WRT(&params, parameters);
	}
	if (!(zephir_array_isset_long(&params, 0))) {
		if (zephir_array_isset_string(&params, SL("id"))) {
			zephir_array_fetch_string(&_0$$6, &params, SL("id"), PH_NOISY | PH_READONLY, "phalcon/Tag.zep", 1279);
			zephir_array_update_long(&params, 0, &_0$$6, PH_COPY | PH_SEPARATE ZEPHIR_DEBUG_PARAMS_DUMMY);
		}
	}
	zephir_memory_observe(&id);
	zephir_array_fetch_long(&id, &params, 0, PH_NOISY, "phalcon/Tag.zep", 1283);
	if (!(zephir_array_isset_string(&params, SL("name")))) {
		zephir_array_update_string(&params, SL("name"), &id, PH_COPY | PH_SEPARATE);
	} else {
		zephir_memory_observe(&name);
		zephir_array_fetch_string(&name, &params, SL("name"), PH_NOISY, "phalcon/Tag.zep", 1288);
		if (ZEPHIR_IS_EMPTY(&name)) {
			zephir_array_update_string(&params, SL("name"), &id, PH_COPY | PH_SEPARATE);
		}
	}
	if (!(zephir_array_isset_string(&params, SL("id")))) {
		zephir_array_update_string(&params, SL("id"), &id, PH_COPY | PH_SEPARATE);
	}
	if (zephir_array_isset_string(&params, SL("value"))) {
		zephir_memory_observe(&content);
		zephir_array_fetch_string(&content, &params, SL("value"), PH_NOISY, "phalcon/Tag.zep", 1300);
		zephir_array_unset_string(&params, SL("value"), PH_SEPARATE);
	} else {
		ZEPHIR_CALL_SELF(&content, "getvalue", NULL, 0, &id, &params);
		zephir_check_call_status();
	}
	if (UNEXPECTED(Z_TYPE_P(&content) == IS_NULL)) {
		ZEPHIR_INIT_NVAR(&content);
		ZVAL_STRING(&content, "");
	}
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "<textarea");
	ZEPHIR_CALL_SELF(&code, "renderattributes", NULL, 0, &_1, &params);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(&_2, "htmlspecialchars", NULL, 286, &content);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_3);
	ZEPHIR_CONCAT_SVS(&_3, ">", &_2, "</textarea>");
	zephir_concat_self(&code, &_3);
	RETURN_CCTOR(&code);
}

/**
 * Builds a HTML input[type="text"] tag
 *
 * @param array parameters = [
 *     'id' => '',
 *     'name' => '',
 *     'value' => '',
 *     'class' => ''
 * ]
 */
PHP_METHOD(Phalcon_Tag, textField)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL;
	zval *parameters, parameters_sub, _1;

	ZVAL_UNDEF(&parameters_sub);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(parameters)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &parameters);
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "text");
	ZEPHIR_RETURN_CALL_SELF("inputfield", &_0, 0, &_1, parameters);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Builds a HTML input[type="time"] tag
 *
 * @param array parameters = [
 *     'id' => '',
 *     'name' => '',
 *     'value' => '',
 *     'class' => ''
 * ]
 */
PHP_METHOD(Phalcon_Tag, timeField)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL;
	zval *parameters, parameters_sub, _1;

	ZVAL_UNDEF(&parameters_sub);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(parameters)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &parameters);
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "time");
	ZEPHIR_RETURN_CALL_SELF("inputfield", &_0, 0, &_1, parameters);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Builds a HTML input[type="url"] tag
 *
 * @param array parameters = [
 *     'id' => '',
 *     'name' => '',
 *     'value' => '',
 *     'class' => ''
 * ]
 */
PHP_METHOD(Phalcon_Tag, urlField)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL;
	zval *parameters, parameters_sub, _1;

	ZVAL_UNDEF(&parameters_sub);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(parameters)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &parameters);
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "url");
	ZEPHIR_RETURN_CALL_SELF("inputfield", &_0, 0, &_1, parameters);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Builds a HTML input[type="week"] tag
 *
 * @param array parameters = [
 *     'id' => '',
 *     'name' => '',
 *     'value' => '',
 *     'class' => ''
 * ]
 */
PHP_METHOD(Phalcon_Tag, weekField)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL;
	zval *parameters, parameters_sub, _1;

	ZVAL_UNDEF(&parameters_sub);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(parameters)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &parameters);
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "week");
	ZEPHIR_RETURN_CALL_SELF("inputfield", &_0, 0, &_1, parameters);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Builds generic INPUT tags
 *
 * @param array parameters = [
 *     'id' => '',
 *     'name' => '',
 *     'value' => '',
 *     'class' => '',
 *     'type' => ''
 * ]
 */
PHP_METHOD(Phalcon_Tag, inputField)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_bool asValue, _1$$10;
	zval *type_param = NULL, *parameters, parameters_sub, *asValue_param = NULL, params, id, value, code, name, _3, _4, _0$$6, _2$$5;
	zval type;

	ZVAL_UNDEF(&type);
	ZVAL_UNDEF(&parameters_sub);
	ZVAL_UNDEF(&params);
	ZVAL_UNDEF(&id);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&code);
	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_0$$6);
	ZVAL_UNDEF(&_2$$5);
	ZEND_PARSE_PARAMETERS_START(2, 3)
		Z_PARAM_STR(type)
		Z_PARAM_ZVAL(parameters)
		Z_PARAM_OPTIONAL
		Z_PARAM_BOOL(asValue)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 2, 1, &type_param, &parameters, &asValue_param);
	zephir_get_strval(&type, type_param);
	if (!asValue_param) {
		asValue = 0;
	} else {
		}
	ZEPHIR_INIT_VAR(&params);
	array_init(&params);
	if (Z_TYPE_P(parameters) != IS_ARRAY) {
		zephir_array_append(&params, parameters, PH_SEPARATE, "phalcon/Tag.zep", 1398);
	} else {
		ZEPHIR_CPY_WRT(&params, parameters);
	}
	if (asValue == 0) {
		zephir_memory_observe(&id);
		if (!(zephir_array_isset_long_fetch(&id, &params, 0, 0))) {
			zephir_array_fetch_string(&_0$$6, &params, SL("id"), PH_NOISY | PH_READONLY, "phalcon/Tag.zep", 1405);
			zephir_array_update_long(&params, 0, &_0$$6, PH_COPY | PH_SEPARATE ZEPHIR_DEBUG_PARAMS_DUMMY);
		}
		zephir_memory_observe(&name);
		if (zephir_array_isset_string_fetch(&name, &params, SL("name"), 0)) {
			if (ZEPHIR_IS_EMPTY(&name)) {
				zephir_array_update_string(&params, SL("name"), &id, PH_COPY | PH_SEPARATE);
			}
		} else {
			zephir_array_update_string(&params, SL("name"), &id, PH_COPY | PH_SEPARATE);
		}
		if (Z_TYPE_P(&id) == IS_STRING) {
			_1$$10 = !(zephir_memnstr_str(&id, SL("["), "phalcon/Tag.zep", 1420));
			if (_1$$10) {
				_1$$10 = !(zephir_array_isset_string(&params, SL("id")));
			}
			if (_1$$10) {
				zephir_array_update_string(&params, SL("id"), &id, PH_COPY | PH_SEPARATE);
			}
		}
		ZEPHIR_CALL_SELF(&_2$$5, "getvalue", NULL, 0, &id, &params);
		zephir_check_call_status();
		zephir_array_update_string(&params, SL("value"), &_2$$5, PH_COPY | PH_SEPARATE);
	} else {
		if (!(zephir_array_isset_string(&params, SL("value")))) {
			zephir_memory_observe(&value);
			if (zephir_array_isset_long_fetch(&value, &params, 0, 0)) {
				zephir_array_update_string(&params, SL("value"), &value, PH_COPY | PH_SEPARATE);
			}
		}
	}
	zephir_array_update_string(&params, SL("type"), &type, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_VAR(&_3);
	ZVAL_STRING(&_3, "<input");
	ZEPHIR_CALL_SELF(&code, "renderattributes", NULL, 0, &_3, &params);
	zephir_check_call_status();
	zephir_read_static_property_ce(&_4, phalcon_tag_ce, SL("documentType"), PH_NOISY_CC | PH_READONLY);
	if (ZEPHIR_GT_LONG(&_4, 5)) {
		zephir_concat_self_str(&code, SL(" />"));
	} else {
		zephir_concat_self_str(&code, SL(">"));
	}
	RETURN_CCTOR(&code);
}

/**
 * Builds INPUT tags that implements the checked attribute
 */
PHP_METHOD(Phalcon_Tag, inputFieldChecked)
{
	zend_bool _3$$11;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *type_param = NULL, *parameters, parameters_sub, params, value, id, code, name, currentValue, _1, _2, _6, _7, _0$$5, _4$$12, _5$$14;
	zval type;

	ZVAL_UNDEF(&type);
	ZVAL_UNDEF(&parameters_sub);
	ZVAL_UNDEF(&params);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&id);
	ZVAL_UNDEF(&code);
	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&currentValue);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_0$$5);
	ZVAL_UNDEF(&_4$$12);
	ZVAL_UNDEF(&_5$$14);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_STR(type)
		Z_PARAM_ZVAL(parameters)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 2, 0, &type_param, &parameters);
	zephir_get_strval(&type, type_param);
	if (Z_TYPE_P(parameters) != IS_ARRAY) {
		ZEPHIR_INIT_VAR(&params);
		zephir_create_array(&params, 1, 0);
		zephir_array_fast_append(&params, parameters);
	} else {
		ZEPHIR_CPY_WRT(&params, parameters);
	}
	if (!(zephir_array_isset_long(&params, 0))) {
		zephir_array_fetch_string(&_0$$5, &params, SL("id"), PH_NOISY | PH_READONLY, "phalcon/Tag.zep", 1466);
		zephir_array_update_long(&params, 0, &_0$$5, PH_COPY | PH_SEPARATE ZEPHIR_DEBUG_PARAMS_DUMMY);
	}
	zephir_memory_observe(&id);
	zephir_array_fetch_long(&id, &params, 0, PH_NOISY, "phalcon/Tag.zep", 1469);
	if (!(zephir_array_isset_string(&params, SL("name")))) {
		zephir_array_update_string(&params, SL("name"), &id, PH_COPY | PH_SEPARATE);
	} else {
		zephir_memory_observe(&name);
		zephir_array_fetch_string(&name, &params, SL("name"), PH_NOISY, "phalcon/Tag.zep", 1474);
		if (ZEPHIR_IS_EMPTY(&name)) {
			zephir_array_update_string(&params, SL("name"), &id, PH_COPY | PH_SEPARATE);
		}
	}
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "[");
	ZEPHIR_INIT_VAR(&_2);
	zephir_fast_strpos(&_2, &id, &_1, 0 );
	if (!(zephir_is_true(&_2))) {
		if (!(zephir_array_isset_string(&params, SL("id")))) {
			zephir_array_update_string(&params, SL("id"), &id, PH_COPY | PH_SEPARATE);
		}
	}
	zephir_memory_observe(&currentValue);
	if (zephir_array_isset_string_fetch(&currentValue, &params, SL("value"), 0)) {
		zephir_array_unset_string(&params, SL("value"), PH_SEPARATE);
		ZEPHIR_CALL_SELF(&value, "getvalue", NULL, 0, &id, &params);
		zephir_check_call_status();
		_3$$11 = Z_TYPE_P(&value) != IS_NULL;
		if (_3$$11) {
			_3$$11 = ZEPHIR_IS_EQUAL(&currentValue, &value);
		}
		if (_3$$11) {
			ZEPHIR_INIT_VAR(&_4$$12);
			ZVAL_STRING(&_4$$12, "checked");
			zephir_array_update_string(&params, SL("checked"), &_4$$12, PH_COPY | PH_SEPARATE);
		}
		zephir_array_update_string(&params, SL("value"), &currentValue, PH_COPY | PH_SEPARATE);
	} else {
		ZEPHIR_CALL_SELF(&value, "getvalue", NULL, 0, &id, &params);
		zephir_check_call_status();
		if (Z_TYPE_P(&value) != IS_NULL) {
			ZEPHIR_INIT_VAR(&_5$$14);
			ZVAL_STRING(&_5$$14, "checked");
			zephir_array_update_string(&params, SL("checked"), &_5$$14, PH_COPY | PH_SEPARATE);
		}
		zephir_array_update_string(&params, SL("value"), &value, PH_COPY | PH_SEPARATE);
	}
	zephir_array_update_string(&params, SL("type"), &type, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_VAR(&_6);
	ZVAL_STRING(&_6, "<input");
	ZEPHIR_CALL_SELF(&code, "renderattributes", NULL, 0, &_6, &params);
	zephir_check_call_status();
	zephir_read_static_property_ce(&_7, phalcon_tag_ce, SL("documentType"), PH_NOISY_CC | PH_READONLY);
	if (ZEPHIR_GT_LONG(&_7, 5)) {
		zephir_concat_self_str(&code, SL(" />"));
	} else {
		zephir_concat_self_str(&code, SL(">"));
	}
	RETURN_CCTOR(&code);
}

