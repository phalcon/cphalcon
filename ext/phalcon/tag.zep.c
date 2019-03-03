
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
#include "kernel/array.h"
#include "kernel/memory.h"
#include "kernel/object.h"
#include "kernel/operators.h"
#include "kernel/fcall.h"
#include "ext/spl/spl_exceptions.h"
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
 * Phalcon\Tag
 *
 * Phalcon\Tag is designed to simplify building of HTML tags.
 * It provides a set of helpers to generate HTML in a dynamic way.
 * This component is an abstract class that you can extend to add more helpers.
 */
ZEPHIR_INIT_CLASS(Phalcon_Tag) {

	ZEPHIR_REGISTER_CLASS(Phalcon, Tag, phalcon, tag, phalcon_tag_method_entry, 0);

	/**
	 * Pre-assigned values for components
	 */
	zend_declare_property_null(phalcon_tag_ce, SL("_displayValues"), ZEND_ACC_PROTECTED|ZEND_ACC_STATIC TSRMLS_CC);

	/**
	 * HTML document title
	 */
	zend_declare_property_null(phalcon_tag_ce, SL("_documentTitle"), ZEND_ACC_PROTECTED|ZEND_ACC_STATIC TSRMLS_CC);

	zend_declare_property_null(phalcon_tag_ce, SL("_documentAppendTitle"), ZEND_ACC_PROTECTED|ZEND_ACC_STATIC TSRMLS_CC);

	zend_declare_property_null(phalcon_tag_ce, SL("_documentPrependTitle"), ZEND_ACC_PROTECTED|ZEND_ACC_STATIC TSRMLS_CC);

	zend_declare_property_null(phalcon_tag_ce, SL("_documentTitleSeparator"), ZEND_ACC_PROTECTED|ZEND_ACC_STATIC TSRMLS_CC);

	zend_declare_property_long(phalcon_tag_ce, SL("_documentType"), 11, ZEND_ACC_PROTECTED|ZEND_ACC_STATIC TSRMLS_CC);

	/**
	 * Framework Dispatcher
	 */
	zend_declare_property_null(phalcon_tag_ce, SL("_dependencyInjector"), ZEND_ACC_PROTECTED|ZEND_ACC_STATIC TSRMLS_CC);

	zend_declare_property_null(phalcon_tag_ce, SL("_urlService"), ZEND_ACC_PROTECTED|ZEND_ACC_STATIC TSRMLS_CC);

	zend_declare_property_null(phalcon_tag_ce, SL("_dispatcherService"), ZEND_ACC_PROTECTED|ZEND_ACC_STATIC TSRMLS_CC);

	zend_declare_property_null(phalcon_tag_ce, SL("_escaperService"), ZEND_ACC_PROTECTED|ZEND_ACC_STATIC TSRMLS_CC);

	zend_declare_property_bool(phalcon_tag_ce, SL("_autoEscape"), 1, ZEND_ACC_PROTECTED|ZEND_ACC_STATIC TSRMLS_CC);

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
 * Obtains the 'escaper' service if required
 */
PHP_METHOD(Phalcon_Tag, getEscaper) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *params_param = NULL, autoescape;
	zval params;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&params);
	ZVAL_UNDEF(&autoescape);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &params_param);

	ZEPHIR_OBS_COPY_OR_DUP(&params, params_param);


	ZEPHIR_OBS_VAR(&autoescape);
	if (!(zephir_array_isset_string_fetch(&autoescape, &params, SL("escape"), 0))) {
		ZEPHIR_OBS_NVAR(&autoescape);
		zephir_read_static_property_ce(&autoescape, phalcon_tag_ce, SL("_autoEscape"), PH_NOISY_CC);
	}
	if (!(zephir_is_true(&autoescape))) {
		RETURN_MM_NULL();
	}
	ZEPHIR_RETURN_CALL_SELF("getescaperservice", NULL, 0);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Renders parameters keeping order in their HTML attributes
 */
PHP_METHOD(Phalcon_Tag, renderAttributes) {

	zend_bool _13$$11, _14$$12, _21$$16, _22$$17;
	zend_string *_3, *_7, *_12;
	zend_ulong _2, _6, _11;
	zephir_fcall_cache_entry *_18 = NULL, *_19 = NULL, *_26 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval attributes;
	zval *code_param = NULL, *attributes_param = NULL, __$null, order, escaper, attrs, attribute, value, escaped, key, newCode, *_0, _1, *_4, _5, _8, *_9, _10, _20$$12, _15$$13, _16$$13, _17$$13, _27$$17, _23$$18, _24$$18, _25$$18;
	zval code;
	zval *this_ptr = getThis();

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

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &code_param, &attributes_param);

	if (UNEXPECTED(Z_TYPE_P(code_param) != IS_STRING && Z_TYPE_P(code_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'code' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(code_param) == IS_STRING)) {
		zephir_get_strval(&code, code_param);
	} else {
		ZEPHIR_INIT_VAR(&code);
		ZVAL_EMPTY_STRING(&code);
	}
	ZEPHIR_OBS_COPY_OR_DUP(&attributes, attributes_param);


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
	ZEPHIR_INIT_VAR(&attrs);
	array_init(&attrs);
	zephir_is_iterable(&order, 0, "phalcon/tag.zep", 124);
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
			if (zephir_array_isset_fetch(&attribute, &attributes, &key, 0 TSRMLS_CC)) {
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
				if (zephir_array_isset_fetch(&attribute, &attributes, &key, 0 TSRMLS_CC)) {
					zephir_array_update_zval(&attrs, &key, &attribute, PH_COPY | PH_SEPARATE);
				}
			ZEPHIR_CALL_METHOD(NULL, &order, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&value);
	ZEPHIR_INIT_NVAR(&key);
	zephir_is_iterable(&attributes, 0, "phalcon/tag.zep", 130);
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
	zephir_is_iterable(&attrs, 0, "phalcon/tag.zep", 149);
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
				if (_14$$12) {
					ZEPHIR_INIT_NVAR(&_15$$13);
					object_init_ex(&_15$$13, phalcon_tag_exception_ce);
					ZEPHIR_INIT_NVAR(&_16$$13);
					zephir_gettype(&_16$$13, &value TSRMLS_CC);
					ZEPHIR_INIT_LNVAR(_17$$13);
					ZEPHIR_CONCAT_SVSVS(&_17$$13, "Value at index: '", &key, "' type: '", &_16$$13, "' cannot be rendered");
					ZEPHIR_CALL_METHOD(NULL, &_15$$13, "__construct", &_18, 4, &_17$$13);
					zephir_check_call_status();
					zephir_throw_exception_debug(&_15$$13, "phalcon/tag.zep", 138 TSRMLS_CC);
					ZEPHIR_MM_RESTORE();
					return;
				}
				if (zephir_is_true(&escaper)) {
					ZEPHIR_CALL_METHOD(&escaped, &escaper, "escapehtmlattr", &_19, 0, &value);
					zephir_check_call_status();
				} else {
					ZEPHIR_CPY_WRT(&escaped, &value);
				}
				ZEPHIR_INIT_LNVAR(_20$$12);
				ZEPHIR_CONCAT_SVSVS(&_20$$12, " ", &key, "=\"", &escaped, "\"");
				zephir_concat_self(&newCode, &_20$$12 TSRMLS_CC);
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
					if (_22$$17) {
						ZEPHIR_INIT_NVAR(&_23$$18);
						object_init_ex(&_23$$18, phalcon_tag_exception_ce);
						ZEPHIR_INIT_NVAR(&_24$$18);
						zephir_gettype(&_24$$18, &value TSRMLS_CC);
						ZEPHIR_INIT_LNVAR(_25$$18);
						ZEPHIR_CONCAT_SVSVS(&_25$$18, "Value at index: '", &key, "' type: '", &_24$$18, "' cannot be rendered");
						ZEPHIR_CALL_METHOD(NULL, &_23$$18, "__construct", &_18, 4, &_25$$18);
						zephir_check_call_status();
						zephir_throw_exception_debug(&_23$$18, "phalcon/tag.zep", 138 TSRMLS_CC);
						ZEPHIR_MM_RESTORE();
						return;
					}
					if (zephir_is_true(&escaper)) {
						ZEPHIR_CALL_METHOD(&escaped, &escaper, "escapehtmlattr", &_26, 0, &value);
						zephir_check_call_status();
					} else {
						ZEPHIR_CPY_WRT(&escaped, &value);
					}
					ZEPHIR_INIT_LNVAR(_27$$17);
					ZEPHIR_CONCAT_SVSVS(&_27$$17, " ", &key, "=\"", &escaped, "\"");
					zephir_concat_self(&newCode, &_27$$17 TSRMLS_CC);
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
 * Sets the dependency injector container.
 */
PHP_METHOD(Phalcon_Tag, setDI) {

	zval *dependencyInjector, dependencyInjector_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&dependencyInjector_sub);

	zephir_fetch_params(0, 1, 0, &dependencyInjector);



	zend_update_static_property(phalcon_tag_ce, ZEND_STRL("_dependencyInjector"), dependencyInjector);

}

/**
 * Internally gets the request dispatcher
 */
PHP_METHOD(Phalcon_Tag, getDI) {

	zval di;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&di);

	ZEPHIR_MM_GROW();

	ZEPHIR_OBS_VAR(&di);
	zephir_read_static_property_ce(&di, phalcon_tag_ce, SL("_dependencyInjector"), PH_NOISY_CC);
	if (Z_TYPE_P(&di) != IS_OBJECT) {
		ZEPHIR_CALL_CE_STATIC(&di, phalcon_di_ce, "getdefault", &_0, 0);
		zephir_check_call_status();
	}
	RETURN_CCTOR(&di);

}

/**
 * Returns a URL service from the default DI
 */
PHP_METHOD(Phalcon_Tag, getUrlService) {

	zval url, dependencyInjector, _0$$3, _1$$3;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&url);
	ZVAL_UNDEF(&dependencyInjector);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_1$$3);

	ZEPHIR_MM_GROW();

	ZEPHIR_OBS_VAR(&url);
	zephir_read_static_property_ce(&url, phalcon_tag_ce, SL("_urlService"), PH_NOISY_CC);
	if (Z_TYPE_P(&url) != IS_OBJECT) {
		ZEPHIR_CALL_SELF(&dependencyInjector, "getdi", NULL, 0);
		zephir_check_call_status();
		if (Z_TYPE_P(&dependencyInjector) != IS_OBJECT) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_tag_exception_ce, "A dependency injector container is required to obtain the 'url' service", "phalcon/tag.zep", 186);
			return;
		}
		ZEPHIR_INIT_VAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "url");
		ZEPHIR_CALL_METHOD(&_0$$3, &dependencyInjector, "getshared", NULL, 0, &_1$$3);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(&url, &_0$$3);
		zend_update_static_property(phalcon_tag_ce, ZEND_STRL("_urlService"), &url);
	}
	RETURN_CCTOR(&url);

}

/**
 * Returns an Escaper service from the default DI
 */
PHP_METHOD(Phalcon_Tag, getEscaperService) {

	zval escaper, dependencyInjector, _0$$3, _1$$3;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&escaper);
	ZVAL_UNDEF(&dependencyInjector);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_1$$3);

	ZEPHIR_MM_GROW();

	ZEPHIR_OBS_VAR(&escaper);
	zephir_read_static_property_ce(&escaper, phalcon_tag_ce, SL("_escaperService"), PH_NOISY_CC);
	if (Z_TYPE_P(&escaper) != IS_OBJECT) {
		ZEPHIR_CALL_SELF(&dependencyInjector, "getdi", NULL, 0);
		zephir_check_call_status();
		if (Z_TYPE_P(&dependencyInjector) != IS_OBJECT) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_tag_exception_ce, "A dependency injector container is required to obtain the 'escaper' service", "phalcon/tag.zep", 208);
			return;
		}
		ZEPHIR_INIT_VAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "escaper");
		ZEPHIR_CALL_METHOD(&_0$$3, &dependencyInjector, "getshared", NULL, 0, &_1$$3);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(&escaper, &_0$$3);
		zend_update_static_property(phalcon_tag_ce, ZEND_STRL("_escaperService"), &escaper);
	}
	RETURN_CCTOR(&escaper);

}

/**
 * Set autoescape mode in generated html
 */
PHP_METHOD(Phalcon_Tag, setAutoescape) {

	zval *autoescape_param = NULL, _0;
	zend_bool autoescape;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);

	zephir_fetch_params(0, 1, 0, &autoescape_param);

	autoescape = zephir_get_boolval(autoescape_param);


	ZEPHIR_INIT_ZVAL_NREF(_0);
	ZVAL_BOOL(&_0, autoescape);
	zend_update_static_property(phalcon_tag_ce, ZEND_STRL("_autoEscape"), &_0);

}

/**
 * Assigns default values to generated tags by helpers
 *
 * <code>
 * // Assigning "peter" to "name" component
 * Phalcon\Tag::setDefault("name", "peter");
 *
 * // Later in the view
 * echo Phalcon\Tag::textField("name"); // Will have the value "peter" by default
 * </code>
 *
 * @param string value
 */
PHP_METHOD(Phalcon_Tag, setDefault) {

	zend_bool _0$$3;
	zval *id_param = NULL, *value, value_sub;
	zval id;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&id);
	ZVAL_UNDEF(&value_sub);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &id_param, &value);

	if (UNEXPECTED(Z_TYPE_P(id_param) != IS_STRING && Z_TYPE_P(id_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'id' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(id_param) == IS_STRING)) {
		zephir_get_strval(&id, id_param);
	} else {
		ZEPHIR_INIT_VAR(&id);
		ZVAL_EMPTY_STRING(&id);
	}


	if (Z_TYPE_P(value) != IS_NULL) {
		_0$$3 = Z_TYPE_P(value) == IS_ARRAY;
		if (!(_0$$3)) {
			_0$$3 = Z_TYPE_P(value) == IS_OBJECT;
		}
		if (_0$$3) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_tag_exception_ce, "Only scalar values can be assigned to UI components", "phalcon/tag.zep", 242);
			return;
		}
	}
	zephir_update_static_property_array_multi_ce(phalcon_tag_ce, SL("_displayValues"), value TSRMLS_CC, SL("z"), 1, &id);
	ZEPHIR_MM_RESTORE();

}

/**
 * Assigns default values to generated tags by helpers
 *
 * <code>
 * // Assigning "peter" to "name" component
 * Phalcon\Tag::setDefaults(
 *     [
 *         "name" => "peter",
 *     ]
 * );
 *
 * // Later in the view
 * echo Phalcon\Tag::textField("name"); // Will have the value "peter" by default
 * </code>
 */
PHP_METHOD(Phalcon_Tag, setDefaults) {

	zend_bool merge, _0;
	zval *values_param = NULL, *merge_param = NULL, _1, _2$$3, _3$$3;
	zval values;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&values);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &values_param, &merge_param);

	ZEPHIR_OBS_COPY_OR_DUP(&values, values_param);
	if (!merge_param) {
		merge = 0;
	} else {
		merge = zephir_get_boolval(merge_param);
	}


	_0 = merge;
	if (_0) {
		ZEPHIR_OBS_VAR(&_1);
		zephir_read_static_property_ce(&_1, phalcon_tag_ce, SL("_displayValues"), PH_NOISY_CC);
		_0 = Z_TYPE_P(&_1) == IS_ARRAY;
	}
	if (_0) {
		ZEPHIR_INIT_VAR(&_2$$3);
		zephir_read_static_property_ce(&_3$$3, phalcon_tag_ce, SL("_displayValues"), PH_NOISY_CC | PH_READONLY);
		zephir_fast_array_merge(&_2$$3, &_3$$3, &values TSRMLS_CC);
		zend_update_static_property(phalcon_tag_ce, ZEND_STRL("_displayValues"), &_2$$3);
	} else {
		zend_update_static_property(phalcon_tag_ce, ZEND_STRL("_displayValues"), &values);
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * Alias of Phalcon\Tag::setDefault
 *
 * @param string value
 */
PHP_METHOD(Phalcon_Tag, displayTo) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *id_param = NULL, *value, value_sub;
	zval id;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&id);
	ZVAL_UNDEF(&value_sub);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &id_param, &value);

	if (UNEXPECTED(Z_TYPE_P(id_param) != IS_STRING && Z_TYPE_P(id_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'id' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(id_param) == IS_STRING)) {
		zephir_get_strval(&id, id_param);
	} else {
		ZEPHIR_INIT_VAR(&id);
		ZVAL_EMPTY_STRING(&id);
	}


	ZEPHIR_CALL_SELF(NULL, "setdefault", NULL, 0, &id, value);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * Check if a helper has a default value set using Phalcon\Tag::setDefault or value from $_POST
 *
 * @param string name
 */
PHP_METHOD(Phalcon_Tag, hasValue) {

	zend_bool _1;
	zval *name, name_sub, _POST, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name_sub);
	ZVAL_UNDEF(&_POST);
	ZVAL_UNDEF(&_0);

	zephir_get_global(&_POST, SL("_POST"));
	zephir_fetch_params(0, 1, 0, &name);



	zephir_read_static_property_ce(&_0, phalcon_tag_ce, SL("_displayValues"), PH_NOISY_CC | PH_READONLY);
	_1 = zephir_array_isset(&_0, name);
	if (!(_1)) {
		_1 = zephir_array_isset(&_POST, name);
	}
	RETURN_BOOL(_1);

}

/**
 * Every helper calls this function to check whether a component has a predefined
 * value using Phalcon\Tag::setDefault or value from $_POST
 *
 * @param string name
 * @return mixed
 */
PHP_METHOD(Phalcon_Tag, getValue) {

	zval params;
	zval *name, name_sub, *params_param = NULL, _POST, value, _0$$3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name_sub);
	ZVAL_UNDEF(&_POST);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&params);

	ZEPHIR_MM_GROW();
	zephir_get_global(&_POST, SL("_POST"));
	zephir_fetch_params(1, 1, 1, &name, &params_param);

	if (!params_param) {
		ZEPHIR_INIT_VAR(&params);
		array_init(&params);
	} else {
		zephir_get_arrval(&params, params_param);
	}


	ZEPHIR_OBS_VAR(&value);
	if (!(zephir_array_isset_string_fetch(&value, &params, SL("value"), 0))) {
		ZEPHIR_OBS_NVAR(&value);
		zephir_read_static_property_ce(&_0$$3, phalcon_tag_ce, SL("_displayValues"), PH_NOISY_CC | PH_READONLY);
		if (!(zephir_array_isset_fetch(&value, &_0$$3, name, 0 TSRMLS_CC))) {
			ZEPHIR_OBS_NVAR(&value);
			if (!(zephir_array_isset_fetch(&value, &_POST, name, 0 TSRMLS_CC))) {
				RETURN_MM_NULL();
			}
		}
	}
	RETURN_CCTOR(&value);

}

/**
 * Resets the request and internal values to avoid those fields will have any default value.
 * @deprecated Will be removed in 4.0.0
 */
PHP_METHOD(Phalcon_Tag, resetInput) {

	zval __$null, _0, _1, _2;
	zval *this_ptr = getThis();

	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&_0);
	array_init(&_0);
	zend_update_static_property(phalcon_tag_ce, ZEND_STRL("_displayValues"), &_0);
	zend_update_static_property(phalcon_tag_ce, ZEND_STRL("_documentTitle"), &__$null);
	ZEPHIR_INIT_VAR(&_1);
	array_init(&_1);
	zend_update_static_property(phalcon_tag_ce, ZEND_STRL("_documentAppendTitle"), &_1);
	ZEPHIR_INIT_VAR(&_2);
	array_init(&_2);
	zend_update_static_property(phalcon_tag_ce, ZEND_STRL("_documentPrependTitle"), &_2);
	zend_update_static_property(phalcon_tag_ce, ZEND_STRL("_documentTitleSeparator"), &__$null);
	ZEPHIR_MM_RESTORE();

}

/**
 * Builds a HTML A tag using framework conventions
 *
 *<code>
 * echo Phalcon\Tag::linkTo("signup/register", "Register Here!");
 *
 * echo Phalcon\Tag::linkTo(
 *     [
 *         "signup/register",
 *         "Register Here!"
 *     ]
 * );
 *
 * echo Phalcon\Tag::linkTo(
 *     [
 *         "signup/register",
 *         "Register Here!",
 *         "class" => "btn-primary",
 *     ]
 * );
 *
 * echo Phalcon\Tag::linkTo("http://phalconphp.com/", "Phalcon", false);
 *
 * echo Phalcon\Tag::linkTo(
 *     [
 *         "http://phalconphp.com/",
 *         "Phalcon Home",
 *         false,
 *     ]
 * );
 *
 * echo Phalcon\Tag::linkTo(
 *     [
 *         "http://phalconphp.com/",
 *         "Phalcon Home",
 *         "local" => false,
 *     ]
 * );
 *
 * echo Phalcon\Tag::linkTo(
 *     [
 *         "action" => "http://phalconphp.com/",
 *         "text"   => "Phalcon Home",
 *         "local"  => false,
 *         "target" => "_new"
 *     ]
 * );
 *
 *</code>
 *
 * @param array|string parameters
 * @param string text
 * @param bool local
 */
PHP_METHOD(Phalcon_Tag, linkTo) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *parameters, parameters_sub, *text = NULL, text_sub, *local = NULL, local_sub, __$null, __$true, params, action, query, url, code, _0, _1, _2;
	zval *this_ptr = getThis();

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

	ZEPHIR_MM_GROW();
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
		zephir_create_array(&params, 3, 0 TSRMLS_CC);
		zephir_array_fast_append(&params, parameters);
		zephir_array_fast_append(&params, text);
		zephir_array_fast_append(&params, local);
	} else {
		ZEPHIR_CPY_WRT(&params, parameters);
	}
	ZEPHIR_OBS_VAR(&action);
	if (!(zephir_array_isset_long_fetch(&action, &params, 0, 0 TSRMLS_CC))) {
		ZEPHIR_OBS_NVAR(&action);
		if (!(zephir_array_isset_string_fetch(&action, &params, SL("action"), 0))) {
			ZEPHIR_INIT_NVAR(&action);
			ZVAL_STRING(&action, "");
		} else {
			zephir_array_unset_string(&params, SL("action"), PH_SEPARATE);
		}
	}
	ZEPHIR_OBS_NVAR(text);
	if (!(zephir_array_isset_long_fetch(text, &params, 1, 0 TSRMLS_CC))) {
		ZEPHIR_OBS_NVAR(text);
		if (!(zephir_array_isset_string_fetch(text, &params, SL("text"), 0))) {
			ZEPHIR_INIT_NVAR(text);
			ZVAL_STRING(text, "");
		} else {
			zephir_array_unset_string(&params, SL("text"), PH_SEPARATE);
		}
	}
	ZEPHIR_OBS_NVAR(local);
	if (!(zephir_array_isset_long_fetch(local, &params, 2, 0 TSRMLS_CC))) {
		ZEPHIR_OBS_NVAR(local);
		if (!(zephir_array_isset_string_fetch(local, &params, SL("local"), 0))) {
			ZEPHIR_INIT_NVAR(local);
			ZVAL_BOOL(local, 1);
		} else {
			zephir_array_unset_string(&params, SL("local"), PH_SEPARATE);
		}
	}
	ZEPHIR_OBS_VAR(&query);
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
	zephir_concat_self(&code, &_2 TSRMLS_CC);
	RETURN_CCTOR(&code);

}

/**
 * Builds generic INPUT tags
 *
 * @param array parameters
 */
PHP_METHOD(Phalcon_Tag, _inputField) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_bool asValue, _1$$10;
	zval *type_param = NULL, *parameters, parameters_sub, *asValue_param = NULL, params, id, value, code, name, _3, _4, _0$$6, _2$$5;
	zval type;
	zval *this_ptr = getThis();

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

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 1, &type_param, &parameters, &asValue_param);

	zephir_get_strval(&type, type_param);
	if (!asValue_param) {
		asValue = 0;
	} else {
		asValue = zephir_get_boolval(asValue_param);
	}


	ZEPHIR_INIT_VAR(&params);
	array_init(&params);
	if (Z_TYPE_P(parameters) != IS_ARRAY) {
		zephir_array_append(&params, parameters, PH_SEPARATE, "phalcon/tag.zep", 450);
	} else {
		ZEPHIR_CPY_WRT(&params, parameters);
	}
	if (asValue == 0) {
		ZEPHIR_OBS_VAR(&id);
		if (!(zephir_array_isset_long_fetch(&id, &params, 0, 0 TSRMLS_CC))) {
			zephir_array_fetch_string(&_0$$6, &params, SL("id"), PH_NOISY | PH_READONLY, "phalcon/tag.zep", 458 TSRMLS_CC);
			zephir_array_update_long(&params, 0, &_0$$6, PH_COPY | PH_SEPARATE ZEPHIR_DEBUG_PARAMS_DUMMY);
		}
		ZEPHIR_OBS_VAR(&name);
		if (zephir_array_isset_string_fetch(&name, &params, SL("name"), 0)) {
			if (ZEPHIR_IS_EMPTY(&name)) {
				zephir_array_update_string(&params, SL("name"), &id, PH_COPY | PH_SEPARATE);
			}
		} else {
			zephir_array_update_string(&params, SL("name"), &id, PH_COPY | PH_SEPARATE);
		}
		if (Z_TYPE_P(&id) == IS_STRING) {
			_1$$10 = !(zephir_memnstr_str(&id, SL("["), "phalcon/tag.zep", 473));
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
			ZEPHIR_OBS_VAR(&value);
			if (zephir_array_isset_long_fetch(&value, &params, 0, 0 TSRMLS_CC)) {
				zephir_array_update_string(&params, SL("value"), &value, PH_COPY | PH_SEPARATE);
			}
		}
	}
	zephir_array_update_string(&params, SL("type"), &type, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_VAR(&_3);
	ZVAL_STRING(&_3, "<input");
	ZEPHIR_CALL_SELF(&code, "renderattributes", NULL, 0, &_3, &params);
	zephir_check_call_status();
	zephir_read_static_property_ce(&_4, phalcon_tag_ce, SL("_documentType"), PH_NOISY_CC | PH_READONLY);
	if (ZEPHIR_GT_LONG(&_4, 5)) {
		zephir_concat_self_str(&code, SL(" />") TSRMLS_CC);
	} else {
		zephir_concat_self_str(&code, SL(">") TSRMLS_CC);
	}
	RETURN_CCTOR(&code);

}

/**
 * Builds INPUT tags that implements the checked attribute
 *
 * @param array parameters
 */
PHP_METHOD(Phalcon_Tag, _inputFieldChecked) {

	zend_bool _3$$11;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *type_param = NULL, *parameters, parameters_sub, params, value, id, code, name, currentValue, _1, _2, _6, _7, _0$$5, _4$$12, _5$$14;
	zval type;
	zval *this_ptr = getThis();

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

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &type_param, &parameters);

	zephir_get_strval(&type, type_param);


	if (Z_TYPE_P(parameters) != IS_ARRAY) {
		ZEPHIR_INIT_VAR(&params);
		zephir_create_array(&params, 1, 0 TSRMLS_CC);
		zephir_array_fast_append(&params, parameters);
	} else {
		ZEPHIR_CPY_WRT(&params, parameters);
	}
	if (!(zephir_array_isset_long(&params, 0))) {
		zephir_array_fetch_string(&_0$$5, &params, SL("id"), PH_NOISY | PH_READONLY, "phalcon/tag.zep", 522 TSRMLS_CC);
		zephir_array_update_long(&params, 0, &_0$$5, PH_COPY | PH_SEPARATE ZEPHIR_DEBUG_PARAMS_DUMMY);
	}
	ZEPHIR_OBS_VAR(&id);
	zephir_array_fetch_long(&id, &params, 0, PH_NOISY, "phalcon/tag.zep", 525 TSRMLS_CC);
	if (!(zephir_array_isset_string(&params, SL("name")))) {
		zephir_array_update_string(&params, SL("name"), &id, PH_COPY | PH_SEPARATE);
	} else {
		ZEPHIR_OBS_VAR(&name);
		zephir_array_fetch_string(&name, &params, SL("name"), PH_NOISY, "phalcon/tag.zep", 529 TSRMLS_CC);
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
	ZEPHIR_OBS_VAR(&currentValue);
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
	zephir_read_static_property_ce(&_7, phalcon_tag_ce, SL("_documentType"), PH_NOISY_CC | PH_READONLY);
	if (ZEPHIR_GT_LONG(&_7, 5)) {
		zephir_concat_self_str(&code, SL(" />") TSRMLS_CC);
	} else {
		zephir_concat_self_str(&code, SL(">") TSRMLS_CC);
	}
	RETURN_CCTOR(&code);

}

/**
 * Builds a HTML input[type="color"] tag
 *
 * @param array parameters
 */
PHP_METHOD(Phalcon_Tag, colorField) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL;
	zval *parameters, parameters_sub, _1;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&parameters_sub);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &parameters);



	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "color");
	ZEPHIR_RETURN_CALL_SELF("_inputfield", &_0, 426, &_1, parameters);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Builds a HTML input[type="text"] tag
 *
 * <code>
 * echo Phalcon\Tag::textField(
 *     [
 *         "name",
 *         "size" => 30,
 *     ]
 * );
 * </code>
 *
 * @param array parameters
 */
PHP_METHOD(Phalcon_Tag, textField) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL;
	zval *parameters, parameters_sub, _1;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&parameters_sub);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &parameters);



	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "text");
	ZEPHIR_RETURN_CALL_SELF("_inputfield", &_0, 426, &_1, parameters);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Builds a HTML input[type="number"] tag
 *
 * <code>
 * echo Phalcon\Tag::numericField(
 *     [
 *         "price",
 *         "min" => "1",
 *         "max" => "5",
 *     ]
 * );
 * </code>
 *
 * @param array parameters
 */
PHP_METHOD(Phalcon_Tag, numericField) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL;
	zval *parameters, parameters_sub, _1;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&parameters_sub);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &parameters);



	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "number");
	ZEPHIR_RETURN_CALL_SELF("_inputfield", &_0, 426, &_1, parameters);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Builds a HTML input[type="range"] tag
 *
 * @param array parameters
 */
PHP_METHOD(Phalcon_Tag, rangeField) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL;
	zval *parameters, parameters_sub, _1;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&parameters_sub);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &parameters);



	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "range");
	ZEPHIR_RETURN_CALL_SELF("_inputfield", &_0, 426, &_1, parameters);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Builds a HTML input[type="email"] tag
 *
 * <code>
 * echo Phalcon\Tag::emailField("email");
 * </code>
 *
 * @param array parameters
 */
PHP_METHOD(Phalcon_Tag, emailField) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL;
	zval *parameters, parameters_sub, _1;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&parameters_sub);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &parameters);



	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "email");
	ZEPHIR_RETURN_CALL_SELF("_inputfield", &_0, 426, &_1, parameters);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Builds a HTML input[type="date"] tag
 *
 * <code>
 * echo Phalcon\Tag::dateField(
 *     [
 *         "born",
 *         "value" => "14-12-1980",
 *     ]
 * );
 * </code>
 *
 * @param array parameters
 */
PHP_METHOD(Phalcon_Tag, dateField) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL;
	zval *parameters, parameters_sub, _1;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&parameters_sub);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &parameters);



	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "date");
	ZEPHIR_RETURN_CALL_SELF("_inputfield", &_0, 426, &_1, parameters);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Builds a HTML input[type="datetime"] tag
 *
 * @param array parameters
 */
PHP_METHOD(Phalcon_Tag, dateTimeField) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL;
	zval *parameters, parameters_sub, _1;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&parameters_sub);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &parameters);



	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "datetime");
	ZEPHIR_RETURN_CALL_SELF("_inputfield", &_0, 426, &_1, parameters);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Builds a HTML input[type="datetime-local"] tag
 *
 * @param array parameters
 */
PHP_METHOD(Phalcon_Tag, dateTimeLocalField) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL;
	zval *parameters, parameters_sub, _1;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&parameters_sub);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &parameters);



	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "datetime-local");
	ZEPHIR_RETURN_CALL_SELF("_inputfield", &_0, 426, &_1, parameters);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Builds a HTML input[type="month"] tag
 *
 * @param array parameters
 */
PHP_METHOD(Phalcon_Tag, monthField) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL;
	zval *parameters, parameters_sub, _1;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&parameters_sub);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &parameters);



	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "month");
	ZEPHIR_RETURN_CALL_SELF("_inputfield", &_0, 426, &_1, parameters);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Builds a HTML input[type="time"] tag
 *
 * @param array parameters
 */
PHP_METHOD(Phalcon_Tag, timeField) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL;
	zval *parameters, parameters_sub, _1;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&parameters_sub);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &parameters);



	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "time");
	ZEPHIR_RETURN_CALL_SELF("_inputfield", &_0, 426, &_1, parameters);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Builds a HTML input[type="week"] tag
 *
 * @param array parameters
 */
PHP_METHOD(Phalcon_Tag, weekField) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL;
	zval *parameters, parameters_sub, _1;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&parameters_sub);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &parameters);



	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "week");
	ZEPHIR_RETURN_CALL_SELF("_inputfield", &_0, 426, &_1, parameters);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Builds a HTML input[type="password"] tag
 *
 *<code>
 * echo Phalcon\Tag::passwordField(
 *     [
 *         "name",
 *         "size" => 30,
 *     ]
 * );
 *</code>
 *
 * @param array parameters
 */
PHP_METHOD(Phalcon_Tag, passwordField) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL;
	zval *parameters, parameters_sub, _1;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&parameters_sub);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &parameters);



	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "password");
	ZEPHIR_RETURN_CALL_SELF("_inputfield", &_0, 426, &_1, parameters);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Builds a HTML input[type="hidden"] tag
 *
 *<code>
 * echo Phalcon\Tag::hiddenField(
 *     [
 *         "name",
 *         "value" => "mike",
 *     ]
 * );
 *</code>
 *
 * @param array parameters
 */
PHP_METHOD(Phalcon_Tag, hiddenField) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL;
	zval *parameters, parameters_sub, _1;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&parameters_sub);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &parameters);



	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "hidden");
	ZEPHIR_RETURN_CALL_SELF("_inputfield", &_0, 426, &_1, parameters);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Builds a HTML input[type="file"] tag
 *
 *<code>
 * echo Phalcon\Tag::fileField("file");
 *</code>
 *
 * @param array parameters
 */
PHP_METHOD(Phalcon_Tag, fileField) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL;
	zval *parameters, parameters_sub, _1;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&parameters_sub);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &parameters);



	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "file");
	ZEPHIR_RETURN_CALL_SELF("_inputfield", &_0, 426, &_1, parameters);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Builds a HTML input[type="search"] tag
 *
 * @param array parameters
 */
PHP_METHOD(Phalcon_Tag, searchField) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL;
	zval *parameters, parameters_sub, _1;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&parameters_sub);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &parameters);



	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "search");
	ZEPHIR_RETURN_CALL_SELF("_inputfield", &_0, 426, &_1, parameters);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Builds a HTML input[type="tel"] tag
 *
 * @param array parameters
 */
PHP_METHOD(Phalcon_Tag, telField) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL;
	zval *parameters, parameters_sub, _1;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&parameters_sub);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &parameters);



	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "tel");
	ZEPHIR_RETURN_CALL_SELF("_inputfield", &_0, 426, &_1, parameters);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Builds a HTML input[type="url"] tag
 *
 * @param array parameters
 */
PHP_METHOD(Phalcon_Tag, urlField) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL;
	zval *parameters, parameters_sub, _1;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&parameters_sub);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &parameters);



	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "url");
	ZEPHIR_RETURN_CALL_SELF("_inputfield", &_0, 426, &_1, parameters);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Builds a HTML input[type="check"] tag
 *
 *<code>
 * echo Phalcon\Tag::checkField(
 *     [
 *         "terms",
 *         "value" => "Y",
 *     ]
 * );
 *</code>
 *
 * Volt syntax:
 *<code>
 * {{ check_field("terms") }}
 *</code>
 *
 * @param array parameters
 */
PHP_METHOD(Phalcon_Tag, checkField) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL;
	zval *parameters, parameters_sub, _1;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&parameters_sub);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &parameters);



	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "checkbox");
	ZEPHIR_RETURN_CALL_SELF("_inputfieldchecked", &_0, 427, &_1, parameters);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Builds a HTML input[type="radio"] tag
 *
 *<code>
 * echo Phalcon\Tag::radioField(
 *     [
 *         "weather",
 *         "value" => "hot",
 *     ]
 * );
 *</code>
 *
 * Volt syntax:
 *<code>
 * {{ radio_field("Save") }}
 *</code>
 *
 * @param array parameters
 */
PHP_METHOD(Phalcon_Tag, radioField) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL;
	zval *parameters, parameters_sub, _1;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&parameters_sub);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &parameters);



	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "radio");
	ZEPHIR_RETURN_CALL_SELF("_inputfieldchecked", &_0, 427, &_1, parameters);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Builds a HTML input[type="image"] tag
 *
 *<code>
 * echo Phalcon\Tag::imageInput(
 *     [
 *         "src" => "/img/button.png",
 *     ]
 * );
 *</code>
 *
 * Volt syntax:
 *<code>
 * {{ image_input("src": "/img/button.png") }}
 *</code>
 *
 * @param array parameters
 */
PHP_METHOD(Phalcon_Tag, imageInput) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL;
	zval *parameters, parameters_sub, _1, _2;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&parameters_sub);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &parameters);



	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "image");
	ZVAL_BOOL(&_2, 1);
	ZEPHIR_RETURN_CALL_SELF("_inputfield", &_0, 426, &_1, parameters, &_2);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Builds a HTML input[type="submit"] tag
 *
 *<code>
 * echo Phalcon\Tag::submitButton("Save")
 *</code>
 *
 * Volt syntax:
 *<code>
 * {{ submit_button("Save") }}
 *</code>
 *
 * @param array parameters
 */
PHP_METHOD(Phalcon_Tag, submitButton) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL;
	zval *parameters, parameters_sub, _1, _2;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&parameters_sub);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &parameters);



	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "submit");
	ZVAL_BOOL(&_2, 1);
	ZEPHIR_RETURN_CALL_SELF("_inputfield", &_0, 426, &_1, parameters, &_2);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Builds a HTML SELECT tag using a PHP array for options
 *
 *<code>
 * echo Phalcon\Tag::selectStatic(
 *     "status",
 *     [
 *         "A" => "Active",
 *         "I" => "Inactive",
 *     ]
 * );
 *</code>
 *
 * @param array parameters
 * @param array data
 */
PHP_METHOD(Phalcon_Tag, selectStatic) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL;
	zval *parameters, parameters_sub, *data = NULL, data_sub, __$null;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&parameters_sub);
	ZVAL_UNDEF(&data_sub);
	ZVAL_NULL(&__$null);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &parameters, &data);

	if (!data) {
		data = &data_sub;
		data = &__$null;
	}


	ZEPHIR_RETURN_CALL_CE_STATIC(phalcon_tag_select_ce, "selectfield", &_0, 0, parameters, data);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Builds a HTML SELECT tag using a Phalcon\Mvc\Model resultset as options
 *
 *<code>
 * echo Phalcon\Tag::select(
 *     [
 *         "robotId",
 *         Robots::find("type = "mechanical""),
 *         "using" => ["id", "name"],
 *     ]
 * );
 *</code>
 *
 * Volt syntax:
 *<code>
 * {{ select("robotId", robots, "using": ["id", "name"]) }}
 *</code>
 *
 * @param array parameters
 * @param array data
 */
PHP_METHOD(Phalcon_Tag, select) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL;
	zval *parameters, parameters_sub, *data = NULL, data_sub, __$null;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&parameters_sub);
	ZVAL_UNDEF(&data_sub);
	ZVAL_NULL(&__$null);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &parameters, &data);

	if (!data) {
		data = &data_sub;
		data = &__$null;
	}


	ZEPHIR_RETURN_CALL_CE_STATIC(phalcon_tag_select_ce, "selectfield", &_0, 0, parameters, data);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Builds a HTML TEXTAREA tag
 *
 *<code>
 * echo Phalcon\Tag::textArea(
 *     [
 *         "comments",
 *         "cols" => 10,
 *         "rows" => 4,
 *     ]
 * );
 *</code>
 *
 * Volt syntax:
 *<code>
 * {{ text_area("comments", "cols": 10, "rows": 4) }}
 *</code>
 *
 * @param array parameters
 */
PHP_METHOD(Phalcon_Tag, textArea) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *parameters, parameters_sub, params, id, name, content, code, _1, _2, _3, _0$$6;
	zval *this_ptr = getThis();

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

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &parameters);



	if (Z_TYPE_P(parameters) != IS_ARRAY) {
		ZEPHIR_INIT_VAR(&params);
		zephir_create_array(&params, 1, 0 TSRMLS_CC);
		zephir_array_fast_append(&params, parameters);
	} else {
		ZEPHIR_CPY_WRT(&params, parameters);
	}
	if (!(zephir_array_isset_long(&params, 0))) {
		if (zephir_array_isset_string(&params, SL("id"))) {
			zephir_array_fetch_string(&_0$$6, &params, SL("id"), PH_NOISY | PH_READONLY, "phalcon/tag.zep", 981 TSRMLS_CC);
			zephir_array_update_long(&params, 0, &_0$$6, PH_COPY | PH_SEPARATE ZEPHIR_DEBUG_PARAMS_DUMMY);
		}
	}
	ZEPHIR_OBS_VAR(&id);
	zephir_array_fetch_long(&id, &params, 0, PH_NOISY, "phalcon/tag.zep", 985 TSRMLS_CC);
	if (!(zephir_array_isset_string(&params, SL("name")))) {
		zephir_array_update_string(&params, SL("name"), &id, PH_COPY | PH_SEPARATE);
	} else {
		ZEPHIR_OBS_VAR(&name);
		zephir_array_fetch_string(&name, &params, SL("name"), PH_NOISY, "phalcon/tag.zep", 989 TSRMLS_CC);
		if (ZEPHIR_IS_EMPTY(&name)) {
			zephir_array_update_string(&params, SL("name"), &id, PH_COPY | PH_SEPARATE);
		}
	}
	if (!(zephir_array_isset_string(&params, SL("id")))) {
		zephir_array_update_string(&params, SL("id"), &id, PH_COPY | PH_SEPARATE);
	}
	if (zephir_array_isset_string(&params, SL("value"))) {
		ZEPHIR_OBS_VAR(&content);
		zephir_array_fetch_string(&content, &params, SL("value"), PH_NOISY, "phalcon/tag.zep", 1000 TSRMLS_CC);
		zephir_array_unset_string(&params, SL("value"), PH_SEPARATE);
	} else {
		ZEPHIR_CALL_SELF(&content, "getvalue", NULL, 0, &id, &params);
		zephir_check_call_status();
	}
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "<textarea");
	ZEPHIR_CALL_SELF(&code, "renderattributes", NULL, 0, &_1, &params);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(&_2, "htmlspecialchars", NULL, 177, &content);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_3);
	ZEPHIR_CONCAT_SVS(&_3, ">", &_2, "</textarea>");
	zephir_concat_self(&code, &_3 TSRMLS_CC);
	RETURN_CCTOR(&code);

}

/**
 * Builds a HTML FORM tag
 *
 * <code>
 * echo Phalcon\Tag::form("posts/save");
 *
 * echo Phalcon\Tag::form(
 *     [
 *         "posts/save",
 *         "method" => "post",
 *     ]
 * );
 * </code>
 *
 * Volt syntax:
 * <code>
 * {{ form("posts/save") }}
 * {{ form("posts/save", "method": "post") }}
 * </code>
 *
 * @param array parameters
 */
PHP_METHOD(Phalcon_Tag, form) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *parameters = NULL, parameters_sub, params, paramsAction, action, code, _3, _0$$6, _1$$7, _2$$8;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&parameters_sub);
	ZVAL_UNDEF(&params);
	ZVAL_UNDEF(&paramsAction);
	ZVAL_UNDEF(&action);
	ZVAL_UNDEF(&code);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_0$$6);
	ZVAL_UNDEF(&_1$$7);
	ZVAL_UNDEF(&_2$$8);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &parameters);

	ZEPHIR_SEPARATE_PARAM(parameters);


	if (Z_TYPE_P(parameters) != IS_ARRAY) {
		ZEPHIR_INIT_VAR(&params);
		zephir_create_array(&params, 1, 0 TSRMLS_CC);
		zephir_array_fast_append(&params, parameters);
	} else {
		ZEPHIR_CPY_WRT(&params, parameters);
	}
	ZEPHIR_OBS_VAR(&paramsAction);
	if (!(zephir_array_isset_long_fetch(&paramsAction, &params, 0, 0 TSRMLS_CC))) {
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
		zephir_concat_self(&action, &_2$$8 TSRMLS_CC);
	}
	if (!(ZEPHIR_IS_EMPTY(&action))) {
		zephir_array_update_string(&params, SL("action"), &action, PH_COPY | PH_SEPARATE);
	}
	ZEPHIR_INIT_VAR(&_3);
	ZVAL_STRING(&_3, "<form");
	ZEPHIR_CALL_SELF(&code, "renderattributes", NULL, 0, &_3, &params);
	zephir_check_call_status();
	zephir_concat_self_str(&code, SL(">") TSRMLS_CC);
	RETURN_CCTOR(&code);

}

/**
 * Builds a HTML close FORM tag
 */
PHP_METHOD(Phalcon_Tag, endForm) {

	zval *this_ptr = getThis();


	RETURN_STRING("</form>");

}

/**
 * Set the title of view content
 *
 *<code>
 * Phalcon\Tag::setTitle("Welcome to my Page");
 *</code>
 */
PHP_METHOD(Phalcon_Tag, setTitle) {

	zval *title_param = NULL;
	zval title;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&title);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &title_param);

	zephir_get_strval(&title, title_param);


	zend_update_static_property(phalcon_tag_ce, ZEND_STRL("_documentTitle"), &title);
	ZEPHIR_MM_RESTORE();

}

/**
 * Set the title separator of view content
 *
 *<code>
 * Phalcon\Tag::setTitleSeparator("-");
 *</code>
 */
PHP_METHOD(Phalcon_Tag, setTitleSeparator) {

	zval *titleSeparator_param = NULL;
	zval titleSeparator;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&titleSeparator);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &titleSeparator_param);

	zephir_get_strval(&titleSeparator, titleSeparator_param);


	zend_update_static_property(phalcon_tag_ce, ZEND_STRL("_documentTitleSeparator"), &titleSeparator);
	ZEPHIR_MM_RESTORE();

}

/**
 * Appends a text to current document title
 */
PHP_METHOD(Phalcon_Tag, appendTitle) {

	zval *title, title_sub, _0, _1$$3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&title_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &title);



	ZEPHIR_OBS_VAR(&_0);
	zephir_read_static_property_ce(&_0, phalcon_tag_ce, SL("_documentAppendTitle"), PH_NOISY_CC);
	if (Z_TYPE_P(&_0) == IS_NULL) {
		ZEPHIR_INIT_VAR(&_1$$3);
		array_init(&_1$$3);
		zend_update_static_property(phalcon_tag_ce, ZEND_STRL("_documentAppendTitle"), &_1$$3);
	}
	if (Z_TYPE_P(title) == IS_ARRAY) {
		zend_update_static_property(phalcon_tag_ce, ZEND_STRL("_documentAppendTitle"), title);
	} else {
		zephir_update_static_property_array_multi_ce(phalcon_tag_ce, SL("_documentAppendTitle"), title TSRMLS_CC, SL("a"), 1);
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * Prepends a text to current document title
 */
PHP_METHOD(Phalcon_Tag, prependTitle) {

	zval *title, title_sub, _0, _1$$3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&title_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &title);



	ZEPHIR_OBS_VAR(&_0);
	zephir_read_static_property_ce(&_0, phalcon_tag_ce, SL("_documentPrependTitle"), PH_NOISY_CC);
	if (Z_TYPE_P(&_0) == IS_NULL) {
		ZEPHIR_INIT_VAR(&_1$$3);
		array_init(&_1$$3);
		zend_update_static_property(phalcon_tag_ce, ZEND_STRL("_documentPrependTitle"), &_1$$3);
	}
	if (Z_TYPE_P(title) == IS_ARRAY) {
		zend_update_static_property(phalcon_tag_ce, ZEND_STRL("_documentPrependTitle"), title);
	} else {
		zephir_update_static_property_array_multi_ce(phalcon_tag_ce, SL("_documentPrependTitle"), title TSRMLS_CC, SL("a"), 1);
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * Gets the current document title.
 * The title will be automatically escaped.
 *
 * <code>
 * Tag::prependTitle('Hello');
 * Tag::setTitle('World');
 * Tag::appendTitle('from Phalcon');
 *
 * echo Tag::getTitle();             // Hello World from Phalcon
 * echo Tag::getTitle(false);        // World from Phalcon
 * echo Tag::getTitle(true, false);  // Hello World
 * echo Tag::getTitle(false, false); // World
 * </code>
 *
 * <code>
 * {{ get_title() }}
 * </code>
 */
PHP_METHOD(Phalcon_Tag, getTitle) {

	zval _1;
	zephir_fcall_cache_entry *_9 = NULL, *_11 = NULL, *_17 = NULL, *_19 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *prepend_param = NULL, *append_param = NULL, __$true, items, output, title, documentTitle, documentAppendTitle, documentPrependTitle, documentTitleSeparator, escaper, _0, _2, _3, _4$$3, _5$$4, tmp$$5, *_6$$5, _7$$5, _8$$6, _10$$7, _12$$9, _13$$10, *_14$$11, _15$$11, _16$$12, _18$$13;
	zend_bool prepend, append;
	zval *this_ptr = getThis();

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
	ZVAL_UNDEF(&_5$$4);
	ZVAL_UNDEF(&tmp$$5);
	ZVAL_UNDEF(&_7$$5);
	ZVAL_UNDEF(&_8$$6);
	ZVAL_UNDEF(&_10$$7);
	ZVAL_UNDEF(&_12$$9);
	ZVAL_UNDEF(&_13$$10);
	ZVAL_UNDEF(&_15$$11);
	ZVAL_UNDEF(&_16$$12);
	ZVAL_UNDEF(&_18$$13);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 2, &prepend_param, &append_param);

	if (!prepend_param) {
		prepend = 1;
	} else {
		prepend = zephir_get_boolval(prepend_param);
	}
	if (!append_param) {
		append = 1;
	} else {
		append = zephir_get_boolval(append_param);
	}


	ZEPHIR_INIT_VAR(&_1);
	zephir_create_array(&_1, 1, 0 TSRMLS_CC);
	zephir_array_update_string(&_1, SL("escape"), &__$true, PH_COPY | PH_SEPARATE);
	ZEPHIR_CALL_SELF(&_0, "getescaper", NULL, 0, &_1);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(&escaper, &_0);
	ZEPHIR_INIT_VAR(&items);
	array_init(&items);
	ZEPHIR_INIT_VAR(&output);
	ZVAL_STRING(&output, "");
	zephir_read_static_property_ce(&_2, phalcon_tag_ce, SL("_documentTitle"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&documentTitle, &escaper, "escapehtml", NULL, 0, &_2);
	zephir_check_call_status();
	zephir_read_static_property_ce(&_3, phalcon_tag_ce, SL("_documentTitleSeparator"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&documentTitleSeparator, &escaper, "escapehtml", NULL, 0, &_3);
	zephir_check_call_status();
	if (prepend) {
		ZEPHIR_OBS_VAR(&_4$$3);
		zephir_read_static_property_ce(&_4$$3, phalcon_tag_ce, SL("_documentPrependTitle"), PH_NOISY_CC);
		if (Z_TYPE_P(&_4$$3) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_5$$4);
			array_init(&_5$$4);
			zend_update_static_property(phalcon_tag_ce, ZEND_STRL("_documentPrependTitle"), &_5$$4);
		}
		ZEPHIR_OBS_VAR(&documentPrependTitle);
		zephir_read_static_property_ce(&documentPrependTitle, phalcon_tag_ce, SL("_documentPrependTitle"), PH_NOISY_CC);
		if (!(ZEPHIR_IS_EMPTY(&documentPrependTitle))) {
			ZEPHIR_CALL_FUNCTION(&tmp$$5, "array_reverse", NULL, 206, &documentPrependTitle);
			zephir_check_call_status();
			zephir_is_iterable(&tmp$$5, 0, "phalcon/tag.zep", 1183);
			if (Z_TYPE_P(&tmp$$5) == IS_ARRAY) {
				ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&tmp$$5), _6$$5)
				{
					ZEPHIR_INIT_NVAR(&title);
					ZVAL_COPY(&title, _6$$5);
					ZEPHIR_CALL_METHOD(&_8$$6, &escaper, "escapehtml", &_9, 0, &title);
					zephir_check_call_status();
					zephir_array_append(&items, &_8$$6, PH_SEPARATE, "phalcon/tag.zep", 1181);
				} ZEND_HASH_FOREACH_END();
			} else {
				ZEPHIR_CALL_METHOD(NULL, &tmp$$5, "rewind", NULL, 0);
				zephir_check_call_status();
				while (1) {
					ZEPHIR_CALL_METHOD(&_7$$5, &tmp$$5, "valid", NULL, 0);
					zephir_check_call_status();
					if (!zend_is_true(&_7$$5)) {
						break;
					}
					ZEPHIR_CALL_METHOD(&title, &tmp$$5, "current", NULL, 0);
					zephir_check_call_status();
						ZEPHIR_CALL_METHOD(&_10$$7, &escaper, "escapehtml", &_11, 0, &title);
						zephir_check_call_status();
						zephir_array_append(&items, &_10$$7, PH_SEPARATE, "phalcon/tag.zep", 1181);
					ZEPHIR_CALL_METHOD(NULL, &tmp$$5, "next", NULL, 0);
					zephir_check_call_status();
				}
			}
			ZEPHIR_INIT_NVAR(&title);
		}
	}
	if (!(ZEPHIR_IS_EMPTY(&documentTitle))) {
		zephir_array_append(&items, &documentTitle, PH_SEPARATE, "phalcon/tag.zep", 1187);
	}
	if (append) {
		ZEPHIR_OBS_VAR(&_12$$9);
		zephir_read_static_property_ce(&_12$$9, phalcon_tag_ce, SL("_documentAppendTitle"), PH_NOISY_CC);
		if (Z_TYPE_P(&_12$$9) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_13$$10);
			array_init(&_13$$10);
			zend_update_static_property(phalcon_tag_ce, ZEND_STRL("_documentAppendTitle"), &_13$$10);
		}
		ZEPHIR_OBS_VAR(&documentAppendTitle);
		zephir_read_static_property_ce(&documentAppendTitle, phalcon_tag_ce, SL("_documentAppendTitle"), PH_NOISY_CC);
		if (!(ZEPHIR_IS_EMPTY(&documentAppendTitle))) {
			zephir_is_iterable(&documentAppendTitle, 0, "phalcon/tag.zep", 1201);
			if (Z_TYPE_P(&documentAppendTitle) == IS_ARRAY) {
				ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&documentAppendTitle), _14$$11)
				{
					ZEPHIR_INIT_NVAR(&title);
					ZVAL_COPY(&title, _14$$11);
					ZEPHIR_CALL_METHOD(&_16$$12, &escaper, "escapehtml", &_17, 0, &title);
					zephir_check_call_status();
					zephir_array_append(&items, &_16$$12, PH_SEPARATE, "phalcon/tag.zep", 1199);
				} ZEND_HASH_FOREACH_END();
			} else {
				ZEPHIR_CALL_METHOD(NULL, &documentAppendTitle, "rewind", NULL, 0);
				zephir_check_call_status();
				while (1) {
					ZEPHIR_CALL_METHOD(&_15$$11, &documentAppendTitle, "valid", NULL, 0);
					zephir_check_call_status();
					if (!zend_is_true(&_15$$11)) {
						break;
					}
					ZEPHIR_CALL_METHOD(&title, &documentAppendTitle, "current", NULL, 0);
					zephir_check_call_status();
						ZEPHIR_CALL_METHOD(&_18$$13, &escaper, "escapehtml", &_19, 0, &title);
						zephir_check_call_status();
						zephir_array_append(&items, &_18$$13, PH_SEPARATE, "phalcon/tag.zep", 1199);
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
		zephir_fast_join(&output, &documentTitleSeparator, &items TSRMLS_CC);
	}
	RETURN_CCTOR(&output);

}

/**
 * Renders the title with title tags. The title is automaticall escaped
 *
 * <code>
 * Tag::prependTitle('Hello');
 * Tag::setTitle('World');
 * Tag::appendTitle('from Phalcon');
 *
 * echo Tag::renderTitle();             // <title>Hello World from Phalcon</title>
 * echo Tag::renderTitle(false);        // <title>World from Phalcon</title>
 * echo Tag::renderTitle(true, false);  // <title>Hello World</title>
 * echo Tag::renderTitle(false, false); // <title>World</title>
 * </code>
 *
 * <code>
 * {{ render_title() }}
 * </code>
 */
PHP_METHOD(Phalcon_Tag, renderTitle) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *prepend_param = NULL, *append_param = NULL, _0, _1, _2, _3;
	zend_bool prepend, append;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 2, &prepend_param, &append_param);

	if (!prepend_param) {
		prepend = 1;
	} else {
		prepend = zephir_get_boolval(prepend_param);
	}
	if (!append_param) {
		append = 1;
	} else {
		append = zephir_get_boolval(append_param);
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
 * Gets the current document title separator
 *
 * <code>
 * echo Phalcon\Tag::getTitleSeparator();
 * </code>
 *
 * <code>
 * {{ get_title_separator() }}
 * </code>
 */
PHP_METHOD(Phalcon_Tag, getTitleSeparator) {

	zval _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);


	zephir_read_static_property_ce(&_0, phalcon_tag_ce, SL("_documentTitleSeparator"), PH_NOISY_CC | PH_READONLY);
	RETURN_CTORW(&_0);

}

/**
 * Builds a LINK[rel="stylesheet"] tag
 *
 * <code>
 * echo Phalcon\Tag::stylesheetLink("http://fonts.googleapis.com/css?family=Rosario", false);
 * echo Phalcon\Tag::stylesheetLink("css/style.css");
 * </code>
 *
 * Volt Syntax:
 *<code>
 * {{ stylesheet_link("http://fonts.googleapis.com/css?family=Rosario", false) }}
 * {{ stylesheet_link("css/style.css") }}
 *</code>
 *
 * @param array parameters
 */
PHP_METHOD(Phalcon_Tag, stylesheetLink) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_bool local;
	zval *parameters = NULL, parameters_sub, *local_param = NULL, __$null, params, code, _10, _11, _0$$3, _1$$5, _2$$7, _3$$8, _4$$10, _5$$11, _6$$12, _7$$12, _8$$12, _9$$13, _12$$14, _13$$14, _14$$15, _15$$15;
	zval *this_ptr = getThis();

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

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 2, &parameters, &local_param);

	if (!parameters) {
		parameters = &parameters_sub;
		parameters = &__$null;
	}
	if (!local_param) {
		local = 1;
	} else {
		local = zephir_get_boolval(local_param);
	}


	if (Z_TYPE_P(parameters) != IS_ARRAY) {
		ZEPHIR_INIT_VAR(&params);
		zephir_create_array(&params, 2, 0 TSRMLS_CC);
		zephir_array_fast_append(&params, parameters);
		ZEPHIR_INIT_VAR(&_0$$3);
		ZVAL_BOOL(&_0$$3, local);
		zephir_array_fast_append(&params, &_0$$3);
	} else {
		ZEPHIR_CPY_WRT(&params, parameters);
	}
	if (zephir_array_isset_long(&params, 1)) {
		ZEPHIR_OBS_VAR(&_1$$5);
		zephir_array_fetch_long(&_1$$5, &params, 1, PH_NOISY, "phalcon/tag.zep", 1281 TSRMLS_CC);
		local = zephir_get_boolval(&_1$$5);
	} else {
		if (zephir_array_isset_string(&params, SL("local"))) {
			ZEPHIR_OBS_VAR(&_2$$7);
			zephir_array_fetch_string(&_2$$7, &params, SL("local"), PH_NOISY, "phalcon/tag.zep", 1284 TSRMLS_CC);
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
			zephir_array_fetch_long(&_4$$10, &params, 0, PH_NOISY | PH_READONLY, "phalcon/tag.zep", 1295 TSRMLS_CC);
			zephir_array_update_string(&params, SL("href"), &_4$$10, PH_COPY | PH_SEPARATE);
		} else {
			ZEPHIR_INIT_VAR(&_5$$11);
			ZVAL_STRING(&_5$$11, "");
			zephir_array_update_string(&params, SL("href"), &_5$$11, PH_COPY | PH_SEPARATE);
		}
	}
	if (local == 1) {
		ZEPHIR_CALL_SELF(&_6$$12, "geturlservice", NULL, 0);
		zephir_check_call_status();
		zephir_array_fetch_string(&_8$$12, &params, SL("href"), PH_NOISY | PH_READONLY, "phalcon/tag.zep", 1305 TSRMLS_CC);
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
	zephir_read_static_property_ce(&_11, phalcon_tag_ce, SL("_documentType"), PH_NOISY_CC | PH_READONLY);
	if (ZEPHIR_GT_LONG(&_11, 5)) {
		ZEPHIR_INIT_VAR(&_12$$14);
		ZEPHIR_GET_CONSTANT(&_12$$14, "PHP_EOL");
		ZEPHIR_INIT_VAR(&_13$$14);
		ZEPHIR_CONCAT_SV(&_13$$14, " />", &_12$$14);
		zephir_concat_self(&code, &_13$$14 TSRMLS_CC);
	} else {
		ZEPHIR_INIT_VAR(&_14$$15);
		ZEPHIR_GET_CONSTANT(&_14$$15, "PHP_EOL");
		ZEPHIR_INIT_VAR(&_15$$15);
		ZEPHIR_CONCAT_SV(&_15$$15, ">", &_14$$15);
		zephir_concat_self(&code, &_15$$15 TSRMLS_CC);
	}
	RETURN_CCTOR(&code);

}

/**
 * Builds a SCRIPT[type="javascript"] tag
 *
 * <code>
 * echo Phalcon\Tag::javascriptInclude("http://ajax.googleapis.com/ajax/libs/jquery/2.2.3/jquery.min.js", false);
 * echo Phalcon\Tag::javascriptInclude("javascript/jquery.js");
 * </code>
 *
 * Volt syntax:
 * <code>
 * {{ javascript_include("http://ajax.googleapis.com/ajax/libs/jquery/2.2.3/jquery.min.js", false) }}
 * {{ javascript_include("javascript/jquery.js") }}
 * </code>
 *
 * @param array parameters
 */
PHP_METHOD(Phalcon_Tag, javascriptInclude) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_bool local, _3;
	zval *parameters = NULL, parameters_sub, *local_param = NULL, __$null, params, code, _4, _11, _12, _0$$3, _1$$5, _2$$7, _5$$8, _6$$10, _7$$11, _8$$12, _9$$12, _10$$12;
	zval *this_ptr = getThis();

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

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 2, &parameters, &local_param);

	if (!parameters) {
		parameters = &parameters_sub;
		parameters = &__$null;
	}
	if (!local_param) {
		local = 1;
	} else {
		local = zephir_get_boolval(local_param);
	}


	if (Z_TYPE_P(parameters) != IS_ARRAY) {
		ZEPHIR_INIT_VAR(&params);
		zephir_create_array(&params, 2, 0 TSRMLS_CC);
		zephir_array_fast_append(&params, parameters);
		ZEPHIR_INIT_VAR(&_0$$3);
		ZVAL_BOOL(&_0$$3, local);
		zephir_array_fast_append(&params, &_0$$3);
	} else {
		ZEPHIR_CPY_WRT(&params, parameters);
	}
	if (zephir_array_isset_long(&params, 1)) {
		ZEPHIR_OBS_VAR(&_1$$5);
		zephir_array_fetch_long(&_1$$5, &params, 1, PH_NOISY, "phalcon/tag.zep", 1353 TSRMLS_CC);
		local = zephir_get_boolval(&_1$$5);
	} else {
		if (zephir_array_isset_string(&params, SL("local"))) {
			ZEPHIR_OBS_VAR(&_2$$7);
			zephir_array_fetch_string(&_2$$7, &params, SL("local"), PH_NOISY, "phalcon/tag.zep", 1356 TSRMLS_CC);
			local = zephir_get_boolval(&_2$$7);
			zephir_array_unset_string(&params, SL("local"), PH_SEPARATE);
		}
	}
	_3 = !(zephir_array_isset_string(&params, SL("type")));
	if (_3) {
		zephir_read_static_property_ce(&_4, phalcon_tag_ce, SL("_documentType"), PH_NOISY_CC | PH_READONLY);
		_3 = ZEPHIR_LT_LONG(&_4, 5);
	}
	if (_3) {
		ZEPHIR_INIT_VAR(&_5$$8);
		ZVAL_STRING(&_5$$8, "text/javascript");
		zephir_array_update_string(&params, SL("type"), &_5$$8, PH_COPY | PH_SEPARATE);
	}
	if (!(zephir_array_isset_string(&params, SL("src")))) {
		if (zephir_array_isset_long(&params, 0)) {
			zephir_array_fetch_long(&_6$$10, &params, 0, PH_NOISY | PH_READONLY, "phalcon/tag.zep", 1367 TSRMLS_CC);
			zephir_array_update_string(&params, SL("src"), &_6$$10, PH_COPY | PH_SEPARATE);
		} else {
			ZEPHIR_INIT_VAR(&_7$$11);
			ZVAL_STRING(&_7$$11, "");
			zephir_array_update_string(&params, SL("src"), &_7$$11, PH_COPY | PH_SEPARATE);
		}
	}
	if (local == 1) {
		ZEPHIR_CALL_SELF(&_8$$12, "geturlservice", NULL, 0);
		zephir_check_call_status();
		zephir_array_fetch_string(&_10$$12, &params, SL("src"), PH_NOISY | PH_READONLY, "phalcon/tag.zep", 1377 TSRMLS_CC);
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
	zephir_concat_self(&code, &_12 TSRMLS_CC);
	RETURN_CCTOR(&code);

}

/**
 * Builds HTML IMG tags
 *
 * <code>
 * echo Phalcon\Tag::image("img/bg.png");
 *
 * echo Phalcon\Tag::image(
 *     [
 *         "img/photo.jpg",
 *         "alt" => "Some Photo",
 *     ]
 * );
 * </code>
 *
 * Volt Syntax:
 * <code>
 * {{ image("img/bg.png") }}
 * {{ image("img/photo.jpg", "alt": "Some Photo") }}
 * {{ image("http://static.mywebsite.com/img/bg.png", false) }}
 * </code>
 *
 * @param  array parameters
 */
PHP_METHOD(Phalcon_Tag, image) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_bool local;
	zval *parameters = NULL, parameters_sub, *local_param = NULL, __$null, params, code, src, _5, _6, _0$$5, _1$$8, _2$$9, _3$$9, _4$$9;
	zval *this_ptr = getThis();

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

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 2, &parameters, &local_param);

	if (!parameters) {
		parameters = &parameters_sub;
		parameters = &__$null;
	}
	if (!local_param) {
		local = 1;
	} else {
		local = zephir_get_boolval(local_param);
	}


	if (Z_TYPE_P(parameters) != IS_ARRAY) {
		ZEPHIR_INIT_VAR(&params);
		zephir_create_array(&params, 1, 0 TSRMLS_CC);
		zephir_array_fast_append(&params, parameters);
	} else {
		ZEPHIR_CPY_WRT(&params, parameters);
		if (zephir_array_isset_long(&params, 1)) {
			ZEPHIR_OBS_VAR(&_0$$5);
			zephir_array_fetch_long(&_0$$5, &params, 1, PH_NOISY, "phalcon/tag.zep", 1418 TSRMLS_CC);
			local = zephir_get_boolval(&_0$$5);
		}
	}
	if (!(zephir_array_isset_string(&params, SL("src")))) {
		ZEPHIR_OBS_VAR(&src);
		if (zephir_array_isset_long_fetch(&src, &params, 0, 0 TSRMLS_CC)) {
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
		zephir_array_fetch_string(&_4$$9, &params, SL("src"), PH_NOISY | PH_READONLY, "phalcon/tag.zep", 1434 TSRMLS_CC);
		ZEPHIR_CALL_METHOD(&_3$$9, &_2$$9, "getstatic", NULL, 0, &_4$$9);
		zephir_check_call_status();
		zephir_array_update_string(&params, SL("src"), &_3$$9, PH_COPY | PH_SEPARATE);
	}
	ZEPHIR_INIT_VAR(&_5);
	ZVAL_STRING(&_5, "<img");
	ZEPHIR_CALL_SELF(&code, "renderattributes", NULL, 0, &_5, &params);
	zephir_check_call_status();
	zephir_read_static_property_ce(&_6, phalcon_tag_ce, SL("_documentType"), PH_NOISY_CC | PH_READONLY);
	if (ZEPHIR_GT_LONG(&_6, 5)) {
		zephir_concat_self_str(&code, SL(" />") TSRMLS_CC);
	} else {
		zephir_concat_self_str(&code, SL(">") TSRMLS_CC);
	}
	RETURN_CCTOR(&code);

}

/**
 * Converts texts into URL-friendly titles
 *
 *<code>
 * echo Phalcon\Tag::friendlyTitle("These are big important news", "-")
 *</code>
 */
PHP_METHOD(Phalcon_Tag, friendlyTitle) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_bool lowercase, _6$$4;
	zval *text_param = NULL, *separator_param = NULL, *lowercase_param = NULL, *replace = NULL, replace_sub, __$null, friendly, locale, search, _0, _1, _15, _17, _2$$3, _3$$3, _4$$3, _5$$3, *_7$$6, _8$$6, _9$$7, _10$$7, _11$$8, _12$$8, _13$$9, _14$$9, _16$$10, _18$$11;
	zval text, separator;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&text);
	ZVAL_UNDEF(&separator);
	ZVAL_UNDEF(&replace_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&friendly);
	ZVAL_UNDEF(&locale);
	ZVAL_UNDEF(&search);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_15);
	ZVAL_UNDEF(&_17);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_5$$3);
	ZVAL_UNDEF(&_8$$6);
	ZVAL_UNDEF(&_9$$7);
	ZVAL_UNDEF(&_10$$7);
	ZVAL_UNDEF(&_11$$8);
	ZVAL_UNDEF(&_12$$8);
	ZVAL_UNDEF(&_13$$9);
	ZVAL_UNDEF(&_14$$9);
	ZVAL_UNDEF(&_16$$10);
	ZVAL_UNDEF(&_18$$11);

	ZEPHIR_MM_GROW();
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
		lowercase = zephir_get_boolval(lowercase_param);
	}
	if (!replace) {
		replace = &replace_sub;
		replace = &__$null;
	}


	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "iconv");
	ZEPHIR_CALL_FUNCTION(&_1, "extension_loaded", NULL, 123, &_0);
	zephir_check_call_status();
	if (zephir_is_true(&_1)) {
		ZVAL_LONG(&_2$$3, 6);
		ZEPHIR_INIT_VAR(&_3$$3);
		ZVAL_STRING(&_3$$3, "en_US.UTF-8");
		ZEPHIR_CALL_FUNCTION(&locale, "setlocale", NULL, 203, &_2$$3, &_3$$3);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(&_3$$3);
		ZVAL_STRING(&_3$$3, "UTF-8");
		ZEPHIR_INIT_VAR(&_4$$3);
		ZVAL_STRING(&_4$$3, "ASCII//TRANSLIT");
		ZEPHIR_CALL_FUNCTION(&_5$$3, "iconv", NULL, 204, &_3$$3, &_4$$3, &text);
		zephir_check_call_status();
		zephir_get_strval(&text, &_5$$3);
	}
	if (zephir_is_true(replace)) {
		_6$$4 = Z_TYPE_P(replace) != IS_ARRAY;
		if (_6$$4) {
			_6$$4 = Z_TYPE_P(replace) != IS_STRING;
		}
		if (_6$$4) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_tag_exception_ce, "Parameter replace must be an array or a string", "phalcon/tag.zep", 1473);
			return;
		}
		if (Z_TYPE_P(replace) == IS_ARRAY) {
			zephir_is_iterable(replace, 0, "phalcon/tag.zep", 1479);
			if (Z_TYPE_P(replace) == IS_ARRAY) {
				ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(replace), _7$$6)
				{
					ZEPHIR_INIT_NVAR(&search);
					ZVAL_COPY(&search, _7$$6);
					ZEPHIR_INIT_NVAR(&_9$$7);
					ZEPHIR_INIT_NVAR(&_10$$7);
					ZVAL_STRING(&_10$$7, " ");
					zephir_fast_str_replace(&_9$$7, &search, &_10$$7, &text TSRMLS_CC);
					zephir_get_strval(&text, &_9$$7);
				} ZEND_HASH_FOREACH_END();
			} else {
				ZEPHIR_CALL_METHOD(NULL, replace, "rewind", NULL, 0);
				zephir_check_call_status();
				while (1) {
					ZEPHIR_CALL_METHOD(&_8$$6, replace, "valid", NULL, 0);
					zephir_check_call_status();
					if (!zend_is_true(&_8$$6)) {
						break;
					}
					ZEPHIR_CALL_METHOD(&search, replace, "current", NULL, 0);
					zephir_check_call_status();
						ZEPHIR_INIT_NVAR(&_11$$8);
						ZEPHIR_INIT_NVAR(&_12$$8);
						ZVAL_STRING(&_12$$8, " ");
						zephir_fast_str_replace(&_11$$8, &search, &_12$$8, &text TSRMLS_CC);
						zephir_get_strval(&text, &_11$$8);
					ZEPHIR_CALL_METHOD(NULL, replace, "next", NULL, 0);
					zephir_check_call_status();
				}
			}
			ZEPHIR_INIT_NVAR(&search);
		} else {
			ZEPHIR_INIT_VAR(&_13$$9);
			ZEPHIR_INIT_VAR(&_14$$9);
			ZVAL_STRING(&_14$$9, " ");
			zephir_fast_str_replace(&_13$$9, replace, &_14$$9, &text TSRMLS_CC);
			zephir_get_strval(&text, &_13$$9);
		}
	}
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_STRING(&_0, "/[^a-zA-Z0-9\\/_|+ -]/");
	ZEPHIR_INIT_VAR(&_15);
	ZVAL_STRING(&_15, "");
	ZEPHIR_CALL_FUNCTION(&friendly, "preg_replace", NULL, 21, &_0, &_15, &text);
	zephir_check_call_status();
	if (lowercase) {
		ZEPHIR_INIT_VAR(&_16$$10);
		zephir_fast_strtolower(&_16$$10, &friendly);
		ZEPHIR_CPY_WRT(&friendly, &_16$$10);
	}
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_STRING(&_0, "/[\\/_|+ -]+/");
	ZEPHIR_CALL_FUNCTION(&_17, "preg_replace", NULL, 21, &_0, &separator, &friendly);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(&friendly, &_17);
	ZEPHIR_INIT_NVAR(&_0);
	zephir_fast_trim(&_0, &friendly, &separator, ZEPHIR_TRIM_BOTH TSRMLS_CC);
	ZEPHIR_CPY_WRT(&friendly, &_0);
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_STRING(&_0, "iconv");
	ZEPHIR_CALL_FUNCTION(&_17, "extension_loaded", NULL, 123, &_0);
	zephir_check_call_status();
	if (zephir_is_true(&_17)) {
		ZVAL_LONG(&_18$$11, 6);
		ZEPHIR_CALL_FUNCTION(NULL, "setlocale", NULL, 203, &_18$$11, &locale);
		zephir_check_call_status();
	}
	RETURN_CCTOR(&friendly);

}

/**
 * Set the document type of content
 */
PHP_METHOD(Phalcon_Tag, setDocType) {

	zend_bool _0;
	zval *doctype_param = NULL, _1$$3, _2$$4;
	zend_long doctype;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$4);

	zephir_fetch_params(0, 1, 0, &doctype_param);

	doctype = zephir_get_intval(doctype_param);


	_0 = doctype < 1;
	if (!(_0)) {
		_0 = doctype > 11;
	}
	if (_0) {
		ZEPHIR_INIT_ZVAL_NREF(_1$$3);
		ZVAL_LONG(&_1$$3, 5);
		zend_update_static_property(phalcon_tag_ce, ZEND_STRL("_documentType"), &_1$$3);
	} else {
		ZEPHIR_INIT_ZVAL_NREF(_2$$4);
		ZVAL_LONG(&_2$$4, doctype);
		zend_update_static_property(phalcon_tag_ce, ZEND_STRL("_documentType"), &_2$$4);
	}

}

/**
 * Get the document type declaration of content
 */
PHP_METHOD(Phalcon_Tag, getDocType) {

	zval _0, _1$$3, _2$$4, _3$$4, _4$$5, _5$$5, _6$$6, _7$$6, _8$$7, _9$$7, _10$$8, _11$$8, _12$$9, _13$$9, _14$$10, _15$$10, _16$$11, _17$$11, _18$$12;
	zval *this_ptr = getThis();

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

	ZEPHIR_MM_GROW();

	zephir_read_static_property_ce(&_0, phalcon_tag_ce, SL("_documentType"), PH_NOISY_CC | PH_READONLY);
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
 * Builds a HTML tag
 */
PHP_METHOD(Phalcon_Tag, tagHtml) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_bool selfClose, onlyStart, useEol;
	zval *tagName_param = NULL, *parameters = NULL, parameters_sub, *selfClose_param = NULL, *onlyStart_param = NULL, *useEol_param = NULL, __$null, params, localCode, _1, _3$$11;
	zval tagName, _0, _2$$10;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&tagName);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2$$10);
	ZVAL_UNDEF(&parameters_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&params);
	ZVAL_UNDEF(&localCode);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_3$$11);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 4, &tagName_param, &parameters, &selfClose_param, &onlyStart_param, &useEol_param);

	zephir_get_strval(&tagName, tagName_param);
	if (!parameters) {
		parameters = &parameters_sub;
		parameters = &__$null;
	}
	if (!selfClose_param) {
		selfClose = 0;
	} else {
		selfClose = zephir_get_boolval(selfClose_param);
	}
	if (!onlyStart_param) {
		onlyStart = 0;
	} else {
		onlyStart = zephir_get_boolval(onlyStart_param);
	}
	if (!useEol_param) {
		useEol = 0;
	} else {
		useEol = zephir_get_boolval(useEol_param);
	}


	if (Z_TYPE_P(parameters) != IS_ARRAY) {
		ZEPHIR_INIT_VAR(&params);
		zephir_create_array(&params, 1, 0 TSRMLS_CC);
		zephir_array_fast_append(&params, parameters);
	} else {
		ZEPHIR_CPY_WRT(&params, parameters);
	}
	ZEPHIR_INIT_VAR(&_0);
	ZEPHIR_CONCAT_SV(&_0, "<", &tagName);
	ZEPHIR_CALL_SELF(&localCode, "renderattributes", NULL, 0, &_0, &params);
	zephir_check_call_status();
	zephir_read_static_property_ce(&_1, phalcon_tag_ce, SL("_documentType"), PH_NOISY_CC | PH_READONLY);
	if (ZEPHIR_GT_LONG(&_1, 5)) {
		if (selfClose) {
			zephir_concat_self_str(&localCode, SL(" />") TSRMLS_CC);
		} else {
			zephir_concat_self_str(&localCode, SL(">") TSRMLS_CC);
		}
	} else {
		if (onlyStart) {
			zephir_concat_self_str(&localCode, SL(">") TSRMLS_CC);
		} else {
			ZEPHIR_INIT_VAR(&_2$$10);
			ZEPHIR_CONCAT_SVS(&_2$$10, "></", &tagName, ">");
			zephir_concat_self(&localCode, &_2$$10 TSRMLS_CC);
		}
	}
	if (useEol) {
		ZEPHIR_INIT_VAR(&_3$$11);
		ZEPHIR_GET_CONSTANT(&_3$$11, "PHP_EOL");
		zephir_concat_self(&localCode, &_3$$11 TSRMLS_CC);
	}
	RETURN_CCTOR(&localCode);

}

/**
 * Builds a HTML tag closing tag
 *
 *<code>
 * echo Phalcon\Tag::tagHtmlClose("script", true);
 *</code>
 */
PHP_METHOD(Phalcon_Tag, tagHtmlClose) {

	zend_bool useEol;
	zval *tagName_param = NULL, *useEol_param = NULL, _0$$3;
	zval tagName;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&tagName);
	ZVAL_UNDEF(&_0$$3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &tagName_param, &useEol_param);

	zephir_get_strval(&tagName, tagName_param);
	if (!useEol_param) {
		useEol = 0;
	} else {
		useEol = zephir_get_boolval(useEol_param);
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

