
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
#include "kernel/array.h"
#include "kernel/fcall.h"
#include "kernel/operators.h"
#include "kernel/exception.h"
#include "kernel/concat.h"
#include "kernel/string.h"


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */
/**
 * Phalcon\Html\Helper\AbstractHelper
 *
 * Abstract class for all html helpers
 */
ZEPHIR_INIT_CLASS(Phalcon_Html_Helper_AbstractHelper) {

	ZEPHIR_REGISTER_CLASS(Phalcon\\Html\\Helper, AbstractHelper, phalcon, html_helper_abstracthelper, phalcon_html_helper_abstracthelper_method_entry, ZEND_ACC_EXPLICIT_ABSTRACT_CLASS);

	/**
	 * @var <EscaperInterface>
	 */
	zend_declare_property_null(phalcon_html_helper_abstracthelper_ce, SL("escaper"), ZEND_ACC_PROTECTED TSRMLS_CC);

	return SUCCESS;

}

/**
 * Constructor
 */
PHP_METHOD(Phalcon_Html_Helper_AbstractHelper, __construct) {

	zval *escaper, escaper_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&escaper_sub);

	zephir_fetch_params(0, 1, 0, &escaper);



	zephir_update_property_zval(this_ptr, SL("escaper"), escaper);

}

/**
 * Keeps all the attributes sorted - same order all the tome
 */
PHP_METHOD(Phalcon_Html_Helper_AbstractHelper, orderAttributes) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *overrides_param = NULL, *attributes_param = NULL, __$null, order, intersect, results, _0;
	zval overrides, attributes;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&overrides);
	ZVAL_UNDEF(&attributes);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&order);
	ZVAL_UNDEF(&intersect);
	ZVAL_UNDEF(&results);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &overrides_param, &attributes_param);

	zephir_get_arrval(&overrides, overrides_param);
	zephir_get_arrval(&attributes, attributes_param);


	ZEPHIR_INIT_VAR(&order);
	zephir_create_array(&order, 10, 0 TSRMLS_CC);
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
	ZEPHIR_CALL_FUNCTION(&intersect, "array_intersect_key", NULL, 3, &order, &attributes);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&results);
	zephir_fast_array_merge(&results, &intersect, &attributes TSRMLS_CC);
	ZEPHIR_INIT_VAR(&_0);
	zephir_fast_array_merge(&_0, &overrides, &results TSRMLS_CC);
	ZEPHIR_CPY_WRT(&results, &_0);
	zephir_array_unset_string(&results, SL("escape"), PH_SEPARATE);
	RETURN_CCTOR(&results);

}

/**
 * Renders all the attributes
 */
PHP_METHOD(Phalcon_Html_Helper_AbstractHelper, renderAttributes) {

	zend_bool _4$$3, _5$$4, _6$$4, _14$$6, _15$$7, _16$$7;
	zend_string *_3;
	zend_ulong _2;
	zephir_fcall_cache_entry *_10 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *attributes_param = NULL, key, result, value, *_0, _1, _11$$4, _12$$4, _13$$4, _7$$5, _8$$5, _9$$5, _20$$7, _21$$7, _22$$7, _17$$8, _18$$8, _19$$8;
	zval attributes;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&attributes);
	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&result);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_11$$4);
	ZVAL_UNDEF(&_12$$4);
	ZVAL_UNDEF(&_13$$4);
	ZVAL_UNDEF(&_7$$5);
	ZVAL_UNDEF(&_8$$5);
	ZVAL_UNDEF(&_9$$5);
	ZVAL_UNDEF(&_20$$7);
	ZVAL_UNDEF(&_21$$7);
	ZVAL_UNDEF(&_22$$7);
	ZVAL_UNDEF(&_17$$8);
	ZVAL_UNDEF(&_18$$8);
	ZVAL_UNDEF(&_19$$8);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &attributes_param);

	zephir_get_arrval(&attributes, attributes_param);


	ZEPHIR_INIT_VAR(&result);
	ZVAL_STRING(&result, "");
	zephir_is_iterable(&attributes, 0, "phalcon/html/helper/abstracthelper.zep", 89);
	if (Z_TYPE_P(&attributes) == IS_ARRAY) {
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&attributes), _2, _3, _0)
		{
			ZEPHIR_INIT_NVAR(&key);
			if (_3 != NULL) { 
				ZVAL_STR_COPY(&key, _3);
			} else {
				ZVAL_LONG(&key, _2);
			}
			ZEPHIR_INIT_NVAR(&value);
			ZVAL_COPY(&value, _0);
			_4$$3 = Z_TYPE_P(&key) == IS_STRING;
			if (_4$$3) {
				_4$$3 = Z_TYPE_P(&value) != IS_NULL;
			}
			if (_4$$3) {
				_5$$4 = Z_TYPE_P(&value) == IS_ARRAY;
				if (!(_5$$4)) {
					_5$$4 = Z_TYPE_P(&value) == IS_RESOURCE;
				}
				_6$$4 = _5$$4;
				if (!(_6$$4)) {
					_6$$4 = Z_TYPE_P(&value) == IS_OBJECT;
				}
				if (_6$$4) {
					ZEPHIR_INIT_NVAR(&_7$$5);
					object_init_ex(&_7$$5, phalcon_html_exception_ce);
					ZEPHIR_INIT_NVAR(&_8$$5);
					zephir_gettype(&_8$$5, &value TSRMLS_CC);
					ZEPHIR_INIT_LNVAR(_9$$5);
					ZEPHIR_CONCAT_SVSVS(&_9$$5, "Value at index: '", &key, "' type: '", &_8$$5, "' cannot be rendered");
					ZEPHIR_CALL_METHOD(NULL, &_7$$5, "__construct", &_10, 4, &_9$$5);
					zephir_check_call_status();
					zephir_throw_exception_debug(&_7$$5, "phalcon/html/helper/abstracthelper.zep", 81 TSRMLS_CC);
					ZEPHIR_MM_RESTORE();
					return;
				}
				zephir_read_property(&_11$$4, this_ptr, SL("escaper"), PH_NOISY_CC | PH_READONLY);
				ZEPHIR_CALL_METHOD(&_12$$4, &_11$$4, "escapehtmlattr", NULL, 0, &value);
				zephir_check_call_status();
				ZEPHIR_INIT_LNVAR(_13$$4);
				ZEPHIR_CONCAT_VSVS(&_13$$4, &key, "=\"", &_12$$4, "\" ");
				zephir_concat_self(&result, &_13$$4 TSRMLS_CC);
			}
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &attributes, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_1, &attributes, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_1)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&key, &attributes, "key", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&value, &attributes, "current", NULL, 0);
			zephir_check_call_status();
				_14$$6 = Z_TYPE_P(&key) == IS_STRING;
				if (_14$$6) {
					_14$$6 = Z_TYPE_P(&value) != IS_NULL;
				}
				if (_14$$6) {
					_15$$7 = Z_TYPE_P(&value) == IS_ARRAY;
					if (!(_15$$7)) {
						_15$$7 = Z_TYPE_P(&value) == IS_RESOURCE;
					}
					_16$$7 = _15$$7;
					if (!(_16$$7)) {
						_16$$7 = Z_TYPE_P(&value) == IS_OBJECT;
					}
					if (_16$$7) {
						ZEPHIR_INIT_NVAR(&_17$$8);
						object_init_ex(&_17$$8, phalcon_html_exception_ce);
						ZEPHIR_INIT_NVAR(&_18$$8);
						zephir_gettype(&_18$$8, &value TSRMLS_CC);
						ZEPHIR_INIT_LNVAR(_19$$8);
						ZEPHIR_CONCAT_SVSVS(&_19$$8, "Value at index: '", &key, "' type: '", &_18$$8, "' cannot be rendered");
						ZEPHIR_CALL_METHOD(NULL, &_17$$8, "__construct", &_10, 4, &_19$$8);
						zephir_check_call_status();
						zephir_throw_exception_debug(&_17$$8, "phalcon/html/helper/abstracthelper.zep", 81 TSRMLS_CC);
						ZEPHIR_MM_RESTORE();
						return;
					}
					zephir_read_property(&_20$$7, this_ptr, SL("escaper"), PH_NOISY_CC | PH_READONLY);
					ZEPHIR_CALL_METHOD(&_21$$7, &_20$$7, "escapehtmlattr", NULL, 0, &value);
					zephir_check_call_status();
					ZEPHIR_INIT_LNVAR(_22$$7);
					ZEPHIR_CONCAT_VSVS(&_22$$7, &key, "=\"", &_21$$7, "\" ");
					zephir_concat_self(&result, &_22$$7 TSRMLS_CC);
				}
			ZEPHIR_CALL_METHOD(NULL, &attributes, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&value);
	ZEPHIR_INIT_NVAR(&key);
	RETURN_CCTOR(&result);

}

/**
 * Renders an element
 */
PHP_METHOD(Phalcon_Html_Helper_AbstractHelper, renderElement) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval attributes;
	zval *tag_param = NULL, *text_param = NULL, *attributes_param = NULL, attrs, escapedAttrs, escapedText, _0, _1$$3, _2$$3, _3$$3;
	zval tag, text;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&tag);
	ZVAL_UNDEF(&text);
	ZVAL_UNDEF(&attrs);
	ZVAL_UNDEF(&escapedAttrs);
	ZVAL_UNDEF(&escapedText);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&attributes);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 1, &tag_param, &text_param, &attributes_param);

	zephir_get_strval(&tag, tag_param);
	zephir_get_strval(&text, text_param);
	if (!attributes_param) {
		ZEPHIR_INIT_VAR(&attributes);
		array_init(&attributes);
	} else {
		zephir_get_arrval(&attributes, attributes_param);
	}


	ZEPHIR_INIT_VAR(&escapedAttrs);
	ZVAL_STRING(&escapedAttrs, "");
	zephir_read_property(&_0, this_ptr, SL("escaper"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&escapedText, &_0, "escapehtml", NULL, 0, &text);
	zephir_check_call_status();
	if (zephir_fast_count_int(&attributes TSRMLS_CC) > 0) {
		ZEPHIR_INIT_VAR(&_1$$3);
		array_init(&_1$$3);
		ZEPHIR_CALL_METHOD(&attrs, this_ptr, "orderattributes", NULL, 0, &_1$$3, &attributes);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_2$$3);
		ZEPHIR_CALL_METHOD(&_3$$3, this_ptr, "renderattributes", NULL, 0, &attrs);
		zephir_check_call_status();
		zephir_fast_trim(&_2$$3, &_3$$3, NULL , ZEPHIR_TRIM_RIGHT TSRMLS_CC);
		ZEPHIR_INIT_NVAR(&escapedAttrs);
		ZEPHIR_CONCAT_SV(&escapedAttrs, " ", &_2$$3);
	}
	ZEPHIR_CONCAT_SVVSVSVS(return_value, "<", &tag, &escapedAttrs, ">", &escapedText, "</", &tag, ">");
	RETURN_MM();

}

/**
 * Produces a self close tag i.e. <img />
 */
PHP_METHOD(Phalcon_Html_Helper_AbstractHelper, selfClose) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval attributes;
	zval *tag_param = NULL, *attributes_param = NULL, attrs, escapedAttrs, _0$$3, _1$$3, _2$$3;
	zval tag;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&tag);
	ZVAL_UNDEF(&attrs);
	ZVAL_UNDEF(&escapedAttrs);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&attributes);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &tag_param, &attributes_param);

	zephir_get_strval(&tag, tag_param);
	if (!attributes_param) {
		ZEPHIR_INIT_VAR(&attributes);
		array_init(&attributes);
	} else {
		zephir_get_arrval(&attributes, attributes_param);
	}


	ZEPHIR_INIT_VAR(&escapedAttrs);
	ZVAL_STRING(&escapedAttrs, "");
	if (zephir_fast_count_int(&attributes TSRMLS_CC) > 0) {
		ZEPHIR_INIT_VAR(&_0$$3);
		array_init(&_0$$3);
		ZEPHIR_CALL_METHOD(&attrs, this_ptr, "orderattributes", NULL, 0, &_0$$3, &attributes);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_1$$3);
		ZEPHIR_CALL_METHOD(&_2$$3, this_ptr, "renderattributes", NULL, 0, &attrs);
		zephir_check_call_status();
		zephir_fast_trim(&_1$$3, &_2$$3, NULL , ZEPHIR_TRIM_RIGHT TSRMLS_CC);
		ZEPHIR_INIT_NVAR(&escapedAttrs);
		ZEPHIR_CONCAT_SV(&escapedAttrs, " ", &_1$$3);
	}
	ZEPHIR_CONCAT_SVVS(return_value, "<", &tag, &escapedAttrs, "/>");
	RETURN_MM();

}

