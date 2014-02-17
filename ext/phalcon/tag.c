
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
#include "kernel/memory.h"
#include "kernel/array.h"
#include "kernel/object.h"
#include "kernel/operators.h"
#include "kernel/fcall.h"
#include "kernel/hash.h"
#include "kernel/concat.h"
#include "kernel/exception.h"
#include "kernel/string.h"


/*
 +------------------------------------------------------------------------+
 | Phalcon Framework                                                      |
 +------------------------------------------------------------------------+
 | Copyright (c) 2011-2014 Phalcon Team (http://www.phalconphp.com)       |
 +------------------------------------------------------------------------+
 | This source file is subject to the New BSD License that is bundled     |
 | with this package in the file docs/LICENSE.txt.                        |
 |                                                                        |
 | If you did not receive a copy of the license and are unable to         |
 | obtain it through the world-wide-web, please send an email             |
 | to license@phalconphp.com so we can send you a copy immediately.       |
 +------------------------------------------------------------------------+
 | Authors: Andres Gutierrez <andres@phalconphp.com>                      |
 |          Eduar Carvajal <eduar@phalconphp.com>                         |
 |          Nikolaos Dimopoulos <nikos@phalconphp.com>                    |
 +------------------------------------------------------------------------+
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
	 * Pre-asigned values for components
	 */
	zend_declare_property_null(phalcon_tag_ce, SL("_displayValues"), ZEND_ACC_PROTECTED|ZEND_ACC_STATIC TSRMLS_CC);

	/**
	 * HTML document title
	 */
	zend_declare_property_null(phalcon_tag_ce, SL("_documentTitle"), ZEND_ACC_PROTECTED|ZEND_ACC_STATIC TSRMLS_CC);

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

	zend_declare_class_constant_long(phalcon_tag_ce, SL("HTML32"), 1 TSRMLS_CC);

	zend_declare_class_constant_long(phalcon_tag_ce, SL("HTML401_STRICT"), 2 TSRMLS_CC);

	zend_declare_class_constant_long(phalcon_tag_ce, SL("HTML401_TRANSITIONAL"), 3 TSRMLS_CC);

	zend_declare_class_constant_long(phalcon_tag_ce, SL("HTML401_FRAMESET"), 4 TSRMLS_CC);

	zend_declare_class_constant_long(phalcon_tag_ce, SL("HTML5"), 5 TSRMLS_CC);

	zend_declare_class_constant_long(phalcon_tag_ce, SL("XHTML10_STRICT"), 6 TSRMLS_CC);

	zend_declare_class_constant_long(phalcon_tag_ce, SL("XHTML10_TRANSITIONAL"), 7 TSRMLS_CC);

	zend_declare_class_constant_long(phalcon_tag_ce, SL("XHTML10_FRAMESET"), 8 TSRMLS_CC);

	zend_declare_class_constant_long(phalcon_tag_ce, SL("XHTML11"), 9 TSRMLS_CC);

	zend_declare_class_constant_long(phalcon_tag_ce, SL("XHTML20"), 10 TSRMLS_CC);

	zend_declare_class_constant_long(phalcon_tag_ce, SL("XHTML5"), 11 TSRMLS_CC);

	return SUCCESS;

}

PHP_METHOD(Phalcon_Tag, getEscaper) {

	zval *params, *result, *autoescape = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &params);



	ZEPHIR_INIT_VAR(result);
	ZVAL_NULL(result);
	ZEPHIR_INIT_VAR(autoescape);
	ZVAL_NULL(autoescape);
	ZEPHIR_OBS_NVAR(autoescape);
	if (!(zephir_array_isset_string_fetch(&autoescape, params, SS("escape"), 0 TSRMLS_CC))) {
		zephir_read_static_property_ce(&autoescape, phalcon_tag_ce, SL("_autoEscape") TSRMLS_CC);
	}
	if (ZEPHIR_IS_TRUE(autoescape)) {
		ZEPHIR_INIT_BNVAR(result);
		zephir_call_self(result, this_ptr, "getescaperservice");
	}
	RETURN_CCTOR(result);

}

PHP_METHOD(Phalcon_Tag, renderAttributes) {

	HashTable *_2, *_6;
	HashPosition _1, _5;
	zval *code_param = NULL, *attributes, *order, *escaper, *attrs = NULL, *value = NULL, *escaped = NULL, *attribute = NULL, *key = NULL, *_0, **_3, *_4, **_7, *_8 = NULL;
	zval *code = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &code_param, &attributes);

	zephir_get_strval(code, code_param);
	ZEPHIR_SEPARATE_PARAM(code);


	ZEPHIR_INIT_VAR(attrs);
	array_init(attrs);
	ZEPHIR_INIT_VAR(order);
	array_init_size(order, 13);
	ZEPHIR_INIT_VAR(_0);
	ZVAL_STRING(_0, "type", 1);
	zephir_array_fast_append(order, _0);
	ZEPHIR_INIT_BNVAR(_0);
	ZVAL_STRING(_0, "for", 1);
	zephir_array_fast_append(order, _0);
	ZEPHIR_INIT_BNVAR(_0);
	ZVAL_STRING(_0, "src", 1);
	zephir_array_fast_append(order, _0);
	ZEPHIR_INIT_BNVAR(_0);
	ZVAL_STRING(_0, "href", 1);
	zephir_array_fast_append(order, _0);
	ZEPHIR_INIT_BNVAR(_0);
	ZVAL_STRING(_0, "action", 1);
	zephir_array_fast_append(order, _0);
	ZEPHIR_INIT_BNVAR(_0);
	ZVAL_STRING(_0, "id", 1);
	zephir_array_fast_append(order, _0);
	ZEPHIR_INIT_BNVAR(_0);
	ZVAL_STRING(_0, "name", 1);
	zephir_array_fast_append(order, _0);
	ZEPHIR_INIT_BNVAR(_0);
	ZVAL_STRING(_0, "value", 1);
	zephir_array_fast_append(order, _0);
	ZEPHIR_INIT_BNVAR(_0);
	ZVAL_STRING(_0, "class", 1);
	zephir_array_fast_append(order, _0);
	ZEPHIR_INIT_VAR(escaper);
	zephir_call_self_p1(escaper, this_ptr, "getescaper", attributes);
	zephir_is_iterable(attributes, &_2, &_1, 0, 0);
	for (
	  ; zephir_hash_get_current_data_ex(_2, (void**) &_3, &_1) == SUCCESS
	  ; zephir_hash_move_forward_ex(_2, &_1)
	) {
		ZEPHIR_GET_HMKEY(attribute, _2, _1);
		ZEPHIR_GET_HVALUE(value, _3);
		if (zephir_array_isset(order, attribute)) {
			zephir_array_update_zval(&attrs, attribute, &value, PH_COPY | PH_SEPARATE);
		}
	}
	ZEPHIR_INIT_BNVAR(_0);
	zephir_call_func_p2(_0, "array_merge_recursive", attrs, attributes);
	ZEPHIR_CPY_WRT(attrs, _0);
	if (zephir_array_isset_string(attrs, SS("escape"))) {
		zephir_array_fetch_string(&_4, attrs, SL("escape"), PH_NOISY | PH_READONLY TSRMLS_CC);
		zephir_array_unset(&attrs, _4, PH_SEPARATE);
	}
	zephir_is_iterable(attrs, &_6, &_5, 0, 0);
	for (
	  ; zephir_hash_get_current_data_ex(_6, (void**) &_7, &_5) == SUCCESS
	  ; zephir_hash_move_forward_ex(_6, &_5)
	) {
		ZEPHIR_GET_HMKEY(key, _6, _5);
		ZEPHIR_GET_HVALUE(value, _7);
		if ((Z_TYPE_P(key) == IS_STRING)) {
			if (zephir_is_true(escaper)) {
				ZEPHIR_INIT_NVAR(escaped);
				zephir_call_method_p1(escaped, escaper, "escapehtmlattr", value);
			} else {
				ZEPHIR_CPY_WRT(escaped, value);
			}
			ZEPHIR_INIT_LNVAR(_8);
			ZEPHIR_CONCAT_SVSVS(_8, " ", key, "=\"", escaped, "\"");
			zephir_concat_self(&code, _8 TSRMLS_CC);
		}
	}
	RETURN_CTOR(code);

}

/**
 * Sets the dependency injector container.
 *
 * @param Phalcon\DiInterface dependencyInjector
 */
PHP_METHOD(Phalcon_Tag, setDI) {

	zval *dependencyInjector, *_0;

	zephir_fetch_params(0, 1, 0, &dependencyInjector);



	if (!(zephir_is_instance_of(dependencyInjector, SL("Phalcon\\DiInterface") TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_STRW(spl_ce_InvalidArgumentException, "Parameter 'dependencyInjector' must be an instance of 'Phalcon\\DiInterface'");
		return;
	}
	if ((Z_TYPE_P(dependencyInjector) != IS_OBJECT)) {
		ZEPHIR_THROW_EXCEPTION_STRW(phalcon_tag_exception_ce, "Parameter dependencyInjector must be an Object");
		return;
	}
	zephir_update_static_property_ce(phalcon_tag_ce, SL("_dependencyInjector"), dependencyInjector TSRMLS_CC);

}

/**
 * Internally gets the request dispatcher
 *
 * @return Phalcon\DiInterface
 */
PHP_METHOD(Phalcon_Tag, getDI) {

	zval *_0;


	_0 = zephir_fetch_static_property_ce(phalcon_tag_ce, SL("_dependencyInjector") TSRMLS_CC);
	RETURN_CTORW(_0);

}

/**
 * Return a URL service from the default DI
 *
 * @return Phalcon\Mvc\UrlInterface
 */
PHP_METHOD(Phalcon_Tag, getUrlService) {

	zval *url = NULL, *dependencyInjector, *_0, *_1, *_2;

	ZEPHIR_MM_GROW();

	zephir_read_static_property_ce(&url, phalcon_tag_ce, SL("_urlService") TSRMLS_CC);
	if ((Z_TYPE_P(url) != IS_OBJECT)) {
		zephir_read_static_property_ce(&dependencyInjector, phalcon_tag_ce, SL("_dependencyInjector") TSRMLS_CC);
		if ((Z_TYPE_P(dependencyInjector) != IS_OBJECT)) {
			ZEPHIR_INIT_VAR(dependencyInjector);
			zephir_call_static(dependencyInjector, "Phalcon\\Di", "getdefault");
		}
		if ((Z_TYPE_P(dependencyInjector) != IS_OBJECT)) {
			ZEPHIR_THROW_EXCEPTION_STR(phalcon_tag_exception_ce, "A dependency injector container is required to obtain the \"url\" service");
			return;
		}
		ZEPHIR_INIT_VAR(_0);
		ZEPHIR_INIT_VAR(_1);
		ZVAL_STRING(_1, "url", 1);
		zephir_call_method_p1(_0, dependencyInjector, "getshared", _1);
		ZEPHIR_CPY_WRT(url, _0);
		zephir_update_static_property_ce(phalcon_tag_ce, SL("_urlService"), url TSRMLS_CC);
	}
	RETURN_CCTOR(url);

}

/**
 * Returns an Escaper service from the default DI
 *
 * @return Phalcon\EscaperInterface
 */
PHP_METHOD(Phalcon_Tag, getEscaperService) {

	zval *escaper = NULL, *dependencyInjector, *_0, *_1, *_2;

	ZEPHIR_MM_GROW();

	zephir_read_static_property_ce(&escaper, phalcon_tag_ce, SL("_escaperService") TSRMLS_CC);
	if ((Z_TYPE_P(escaper) != IS_OBJECT)) {
		zephir_read_static_property_ce(&dependencyInjector, phalcon_tag_ce, SL("_dependencyInjector") TSRMLS_CC);
		if ((Z_TYPE_P(dependencyInjector) != IS_OBJECT)) {
			ZEPHIR_INIT_VAR(dependencyInjector);
			zephir_call_static(dependencyInjector, "Phalcon\\Di", "getdefault");
		}
		if ((Z_TYPE_P(dependencyInjector) != IS_OBJECT)) {
			ZEPHIR_THROW_EXCEPTION_STR(phalcon_tag_exception_ce, "A dependency injector container is required to obtain the \"escaper\" service");
			return;
		}
		ZEPHIR_INIT_VAR(_0);
		ZEPHIR_INIT_VAR(_1);
		ZVAL_STRING(_1, "escaper", 1);
		zephir_call_method_p1(_0, dependencyInjector, "getshared", _1);
		ZEPHIR_CPY_WRT(escaper, _0);
		zephir_update_static_property_ce(phalcon_tag_ce, SL("_escaperService"), escaper TSRMLS_CC);
	}
	RETURN_CCTOR(escaper);

}

/**
 * Set autoescape mode in generated html
 *
 * @param boolean autoescape
 */
PHP_METHOD(Phalcon_Tag, setAutoescape) {

	zval *autoescape_param = NULL, *_0, *_1;
	zend_bool autoescape;

	zephir_fetch_params(0, 1, 0, &autoescape_param);

	autoescape = zephir_get_boolval(autoescape_param);


	ZVAL_BOOL(_1, autoescape);
	zephir_update_static_property_ce(phalcon_tag_ce, SL("_autoEscape"), _1 TSRMLS_CC);

}

/**
 * Assigns default values to generated tags by helpers
 *
 * <code>
 * //Assigning "peter" to "name" component
 * Phalcon\Tag::setDefault("name", "peter");
 *
 * //Later in the view
 * echo Phalcon\Tag::textField("name"); //Will have the value "peter" by default
 * </code>
 *
 * @param string id
 * @param string value
 */
PHP_METHOD(Phalcon_Tag, setDefault) {

	zend_bool _0;
	zval *id_param = NULL, *value, *_1;
	zval *id = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &id_param, &value);

	zephir_get_strval(id, id_param);


	if ((Z_TYPE_P(value) != IS_NULL)) {
		_0 = (Z_TYPE_P(value) == IS_ARRAY);
		if (!(_0)) {
			_0 = (Z_TYPE_P(value) == IS_OBJECT);
		}
		if (_0) {
			ZEPHIR_THROW_EXCEPTION_STR(phalcon_tag_exception_ce, "Only scalar values can be assigned to UI components");
			return;
		}
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * Assigns default values to generated tags by helpers
 *
 * <code>
 * //Assigning "peter" to "name" component
 * Phalcon\Tag::setDefaults(array("name" => "peter"));
 *
 * //Later in the view
 * echo Phalcon\Tag::textField("name"); //Will have the value "peter" by default
 * </code>
 *
 * @param array values
 */
PHP_METHOD(Phalcon_Tag, setDefaults) {

	zval *values, *_0;

	zephir_fetch_params(0, 1, 0, &values);



	if ((Z_TYPE_P(values) != IS_ARRAY)) {
		ZEPHIR_THROW_EXCEPTION_STRW(phalcon_tag_exception_ce, "An array is required as default values");
		return;
	}
	zephir_update_static_property_ce(phalcon_tag_ce, SL("_displayValues"), values TSRMLS_CC);

}

/**
 * Alias of Phalcon\Tag::setDefault
 *
 * @param string id
 * @param string value
 */
PHP_METHOD(Phalcon_Tag, displayTo) {

	zval *id, *value;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &id, &value);



	zephir_call_self_p2(return_value, this_ptr, "setdefault", id, value);
	RETURN_MM();

}

/**
 * Check if a helper has a default value set using Phalcon\Tag::setDefault or value from _POST
 *
 * @param string name
 * @return boolean
 */
PHP_METHOD(Phalcon_Tag, hasValue) {

	zval *name, *displayValues, *_POST;

	zephir_fetch_params(0, 1, 0, &name);



	zephir_read_static_property_ce(&displayValues, phalcon_tag_ce, SL("_displayValues") TSRMLS_CC);
	if (zephir_array_isset(displayValues, name)) {
		RETURN_BOOL(1);
	} else {
		zephir_get_global(&_POST, SS("_POST") TSRMLS_CC);
		if (zephir_array_isset(_POST, name)) {
			RETURN_BOOL(1);
		}
	}
	RETURN_BOOL(0);

}

/**
 * Every helper calls this function to check whether a component has a predefined
 * value using Phalcon\Tag::setDefault or value from _POST
 *
 * @param string name
 * @param array params
 * @return mixed
 */
PHP_METHOD(Phalcon_Tag, getValue) {

	zval *name, *params = NULL, *value = NULL, *autoescape, *displayValues, *escaper = NULL, *_POST, *_0;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &name, &params);

	if (!params) {
		params = ZEPHIR_GLOBAL(global_null);
	}


	zephir_read_static_property_ce(&displayValues, phalcon_tag_ce, SL("_displayValues") TSRMLS_CC);
	ZEPHIR_OBS_VAR(value);
	if (!(zephir_array_isset_fetch(&value, displayValues, name, 0 TSRMLS_CC))) {
		ZEPHIR_OBS_NVAR(value);
		zephir_get_global(&_POST, SS("_POST") TSRMLS_CC);
		if (!(zephir_array_isset_fetch(&value, _POST, name, 0 TSRMLS_CC))) {
			RETURN_MM_NULL();
		}
	}
	if ((Z_TYPE_P(value) == IS_STRING)) {
		_0 = zephir_fetch_static_property_ce(phalcon_tag_ce, SL("_autoEscape") TSRMLS_CC);
		if (zephir_is_true(_0)) {
			ZEPHIR_INIT_VAR(escaper);
			zephir_call_self(escaper, this_ptr, "getescaperservice");
			zephir_call_method_p1(return_value, escaper, "escapehtmlattr", value);
			RETURN_MM();
		}
		if ((Z_TYPE_P(params) == IS_ARRAY)) {
			ZEPHIR_OBS_VAR(autoescape);
			if (zephir_array_isset_string_fetch(&autoescape, params, SS("escape"), 0 TSRMLS_CC)) {
				if (zephir_is_true(autoescape)) {
					ZEPHIR_INIT_NVAR(escaper);
					zephir_call_self(escaper, this_ptr, "getescaperservice");
					zephir_call_method_p1(return_value, escaper, "escapehtmlattr", value);
					RETURN_MM();
				}
			}
		}
	}
	RETURN_CCTOR(value);

}

/**
 * Resets the request and internal values to avoid those fields will have any default value
 */
PHP_METHOD(Phalcon_Tag, resetInput) {

	HashTable *_3;
	HashPosition _2;
	zval *key = NULL, *value = NULL, *_0, *_1, *_POST, **_4, *_5;

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(_1);
	array_init(_1);
	zephir_update_static_property_ce(phalcon_tag_ce, SL("_displayValues"), _1 TSRMLS_CC);
	zephir_get_global(&_POST, SS("_POST") TSRMLS_CC);
	zephir_is_iterable(_POST, &_3, &_2, 0, 0);
	for (
	  ; zephir_hash_get_current_data_ex(_3, (void**) &_4, &_2) == SUCCESS
	  ; zephir_hash_move_forward_ex(_3, &_2)
	) {
		ZEPHIR_GET_HMKEY(key, _3, _2);
		ZEPHIR_GET_HVALUE(value, _4);
		zephir_array_fetch(&_5, _POST, key, PH_NOISY | PH_READONLY TSRMLS_CC);
		zephir_array_unset(&_POST, _5, PH_SEPARATE);
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * Builds a HTML A tag using framework conventions
 *
 *<code>
 *	echo Phalcon\Tag::linkTo("signup/register", "Register Here!");
 *	echo Phalcon\Tag::linkTo(array("signup/register", "Register Here!"));
 *	echo Phalcon\Tag::linkTo(array("signup/register", "Register Here!", "class" => "btn-primary"));
 *	echo Phalcon\Tag::linkTo("http://phalconphp.com/", "Phalcon", FALSE);
 *	echo Phalcon\Tag::linkTo(array("http://phalconphp.com/", "Phalcon Home", FALSE));
 *	echo Phalcon\Tag::linkTo(array("http://phalconphp.com/", "Phalcon Home", "local" =>FALSE));
 *</code>
 *
 * @param array|string parameters
 * @param string text
 * @param boolean local
 * @return string
 */
PHP_METHOD(Phalcon_Tag, linkTo) {

	HashTable *_3;
	HashPosition _2;
	zval *parameters, *text = NULL, *local = NULL, *key = NULL, *value = NULL, *params = NULL, *action = NULL, *url, *code, *_0, *_1, **_4, *_5 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 2, &parameters, &text, &local);

	if (!text) {
		ZEPHIR_CPY_WRT(text, ZEPHIR_GLOBAL(global_null));
	} else {
		ZEPHIR_SEPARATE_PARAM(text);
	}
	if (!local) {
		ZEPHIR_CPY_WRT(local, ZEPHIR_GLOBAL(global_true));
	} else {
		ZEPHIR_SEPARATE_PARAM(local);
	}


	if ((Z_TYPE_P(parameters) != IS_ARRAY)) {
		ZEPHIR_INIT_VAR(params);
		array_init_size(params, 5);
		zephir_array_fast_append(params, parameters);
		zephir_array_fast_append(params, text);
		zephir_array_fast_append(params, local);
	} else {
		ZEPHIR_CPY_WRT(params, parameters);
	}
	ZEPHIR_OBS_VAR(action);
	if (!(zephir_array_isset_long_fetch(&action, params, 0, 0 TSRMLS_CC))) {
		ZEPHIR_OBS_NVAR(action);
		if (!(zephir_array_isset_string_fetch(&action, params, SS("action"), 0 TSRMLS_CC))) {
			ZEPHIR_INIT_BNVAR(action);
			ZVAL_STRING(action, "", 1);
		} else {
			zephir_array_fetch_string(&_0, params, SL("action"), PH_NOISY | PH_READONLY TSRMLS_CC);
			zephir_array_unset(&params, _0, PH_SEPARATE);
		}
	}
	ZEPHIR_OBS_NVAR(text);
	if (!(zephir_array_isset_long_fetch(&text, params, 1, 0 TSRMLS_CC))) {
		ZEPHIR_OBS_NVAR(text);
		if (!(zephir_array_isset_string_fetch(&text, params, SS("text"), 0 TSRMLS_CC))) {
			ZEPHIR_INIT_BNVAR(text);
			ZVAL_STRING(text, "", 1);
		} else {
			zephir_array_fetch_string(&_0, params, SL("text"), PH_NOISY | PH_READONLY TSRMLS_CC);
			zephir_array_unset(&params, _0, PH_SEPARATE);
		}
	}
	ZEPHIR_OBS_NVAR(local);
	if (!(zephir_array_isset_long_fetch(&local, params, 2, 0 TSRMLS_CC))) {
		ZEPHIR_OBS_NVAR(local);
		if (!(zephir_array_isset_string_fetch(&local, params, SS("local"), 0 TSRMLS_CC))) {
			ZEPHIR_INIT_BNVAR(local);
			ZVAL_BOOL(local, 1);
		} else {
			zephir_array_fetch_string(&_0, params, SL("local"), PH_NOISY | PH_READONLY TSRMLS_CC);
			zephir_array_unset(&params, _0, PH_SEPARATE);
		}
	}
	ZEPHIR_INIT_VAR(code);
	if (zephir_is_true(local)) {
		ZEPHIR_INIT_VAR(url);
		zephir_call_self(url, this_ptr, "geturlservice");
		ZEPHIR_INIT_VAR(_1);
		zephir_call_method_p1(_1, url, "get", action);
		ZEPHIR_CONCAT_SVS(code, "<a href=\"", _1, "\"");
	} else {
		ZEPHIR_CONCAT_SVS(code, "<a href=\"", action, "\"");
	}
	zephir_is_iterable(params, &_3, &_2, 0, 0);
	for (
	  ; zephir_hash_get_current_data_ex(_3, (void**) &_4, &_2) == SUCCESS
	  ; zephir_hash_move_forward_ex(_3, &_2)
	) {
		ZEPHIR_GET_HMKEY(key, _3, _2);
		ZEPHIR_GET_HVALUE(value, _4);
		if ((Z_TYPE_P(key) != IS_LONG)) {
			ZEPHIR_INIT_LNVAR(_5);
			ZEPHIR_CONCAT_SVSVS(_5, " ", key, "=\"", value, "\"");
			zephir_concat_self(&code, _5 TSRMLS_CC);
		}
	}
	ZEPHIR_INIT_LNVAR(_5);
	ZEPHIR_CONCAT_SVS(_5, ">", text, "</a>");
	zephir_concat_self(&code, _5 TSRMLS_CC);
	RETURN_CCTOR(code);

}

/**
 * Builds generic INPUT tags
 *
 * @param   string type
 * @param	array parameters
 * @param 	boolean asValue
 * @return	string
 */
PHP_METHOD(Phalcon_Tag, _inputField) {

	HashTable *_5;
	HashPosition _4;
	zend_bool asValue;
	zval *type_param = NULL, *parameters, *asValue_param = NULL, *params = NULL, *id, *value = NULL, *key = NULL, *code = NULL, *name, *doctype, *_0, _1, *_2, **_6, *_7 = NULL;
	zval *type = NULL, *_3;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 1, &type_param, &parameters, &asValue_param);

	zephir_get_strval(type, type_param);
	if (!asValue_param) {
		asValue = 0;
	} else {
		asValue = zephir_get_boolval(asValue_param);
	}


	ZEPHIR_INIT_VAR(params);
	array_init(params);
	if ((Z_TYPE_P(parameters) != IS_ARRAY)) {
		zephir_array_append(&params, parameters, PH_SEPARATE);
	} else {
		ZEPHIR_CPY_WRT(params, parameters);
	}
	if ((asValue == 0)) {
		ZEPHIR_OBS_VAR(id);
		if (!(zephir_array_isset_long_fetch(&id, params, 0, 0 TSRMLS_CC))) {
			zephir_array_fetch_string(&_0, params, SL("id"), PH_NOISY | PH_READONLY TSRMLS_CC);
			zephir_array_update_long(&params, 0, &_0, PH_COPY | PH_SEPARATE, "phalcon/tag.zep", 460);
		}
		ZEPHIR_OBS_VAR(name);
		if (zephir_array_isset_string_fetch(&name, params, SS("name"), 0 TSRMLS_CC)) {
			if (ZEPHIR_IS_EMPTY(name)) {
				zephir_array_update_string(&params, SL("name"), &id, PH_COPY | PH_SEPARATE);
			}
		} else {
			zephir_array_update_string(&params, SL("name"), &id, PH_COPY | PH_SEPARATE);
		}
		ZEPHIR_SINIT_VAR(_1);
		ZVAL_STRING(&_1, "[", 0);
		ZEPHIR_INIT_VAR(_2);
		zephir_fast_strpos(_2, id, &_1, 0 );
		if (!(zephir_is_true(_2))) {
			if (!(zephir_array_isset_string(params, SS("id")))) {
				zephir_array_update_string(&params, SL("id"), &id, PH_COPY | PH_SEPARATE);
			}
		}
		if (!(zephir_array_isset_string(params, SS("value")))) {
			ZEPHIR_INIT_VAR(value);
			zephir_call_self_p2(value, this_ptr, "getvalue", id, params);
			zephir_array_update_string(&params, SL("value"), &value, PH_COPY | PH_SEPARATE);
		}
	} else {
		if (!(zephir_array_isset_string(params, SS("value")))) {
			if (zephir_array_isset_long(params, 0)) {
				ZEPHIR_OBS_NVAR(value);
				zephir_array_fetch_long(&value, params, 0, PH_NOISY TSRMLS_CC);
				zephir_array_update_string(&params, SL("value"), &value, PH_COPY | PH_SEPARATE);
			}
		}
	}
	ZEPHIR_INIT_VAR(_3);
	ZEPHIR_CONCAT_SVS(_3, "<input type=\"", type, "\"");
	ZEPHIR_CPY_WRT(code, _3);
	zephir_is_iterable(params, &_5, &_4, 0, 0);
	for (
	  ; zephir_hash_get_current_data_ex(_5, (void**) &_6, &_4) == SUCCESS
	  ; zephir_hash_move_forward_ex(_5, &_4)
	) {
		ZEPHIR_GET_HMKEY(key, _5, _4);
		ZEPHIR_GET_HVALUE(value, _6);
		if ((Z_TYPE_P(key) != IS_LONG)) {
			ZEPHIR_INIT_LNVAR(_7);
			ZEPHIR_CONCAT_SVSVS(_7, " ", key, "=\"", value, "\"");
			zephir_concat_self(&code, _7 TSRMLS_CC);
		}
	}
	zephir_read_static_property_ce(&doctype, phalcon_tag_ce, SL("_documentType") TSRMLS_CC);
	if (ZEPHIR_GT_LONG(doctype, 5)) {
		zephir_concat_self_str(&code, SL(" />") TSRMLS_CC);
	} else {
		zephir_concat_self_str(&code, SL(">") TSRMLS_CC);
	}
	RETURN_CCTOR(code);

}

/**
 * Builds INPUT tags that implements the checked attribute
 *
 * @param   string type
 * @param	array parameters
 * @return	string
 */
PHP_METHOD(Phalcon_Tag, _inputFieldChecked) {

	HashTable *_6;
	HashPosition _5;
	zval *type_param = NULL, *parameters, *params = NULL, *value = NULL, *id, *key = NULL, *code = NULL, *name, *currentValue, *doctype, *_0, _1, *_2, *_3 = NULL, **_7, *_8 = NULL;
	zval *type = NULL, *_4;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &type_param, &parameters);

	zephir_get_strval(type, type_param);


	if ((Z_TYPE_P(parameters) != IS_ARRAY)) {
		ZEPHIR_INIT_VAR(params);
		array_init_size(params, 2);
		zephir_array_fast_append(params, parameters);
	} else {
		ZEPHIR_CPY_WRT(params, parameters);
	}
	ZEPHIR_INIT_VAR(value);
	ZVAL_NULL(value);
	if (!(zephir_array_isset_long(params, 0))) {
		zephir_array_fetch_string(&_0, params, SL("id"), PH_NOISY | PH_READONLY TSRMLS_CC);
		zephir_array_update_long(&params, 0, &_0, PH_COPY | PH_SEPARATE, "phalcon/tag.zep", 541);
	}
	ZEPHIR_OBS_VAR(id);
	zephir_array_fetch_long(&id, params, 0, PH_NOISY TSRMLS_CC);
	if (!(zephir_array_isset_string(params, SS("name")))) {
		zephir_array_update_string(&params, SL("name"), &id, PH_COPY | PH_SEPARATE);
	} else {
		ZEPHIR_OBS_VAR(name);
		zephir_array_fetch_string(&name, params, SL("name"), PH_NOISY TSRMLS_CC);
		if (ZEPHIR_IS_EMPTY(name)) {
			zephir_array_update_string(&params, SL("name"), &id, PH_COPY | PH_SEPARATE);
		}
	}
	ZEPHIR_SINIT_VAR(_1);
	ZVAL_STRING(&_1, "[", 0);
	ZEPHIR_INIT_VAR(_2);
	zephir_fast_strpos(_2, id, &_1, 0 );
	if (!(zephir_is_true(_2))) {
		if (!(zephir_array_isset_string(params, SS("id")))) {
			zephir_array_update_string(&params, SL("id"), &id, PH_COPY | PH_SEPARATE);
		}
	}
	ZEPHIR_INIT_BNVAR(value);
	zephir_call_self_p2(value, this_ptr, "getvalue", id, params);
	if (zephir_array_isset_string(params, SS("value"))) {
		zephir_array_fetch_string(&currentValue, params, SL("value"), PH_NOISY | PH_READONLY TSRMLS_CC);
		if (ZEPHIR_IS_EQUAL(currentValue, value)) {
			ZEPHIR_INIT_VAR(_3);
			ZVAL_STRING(_3, "checked", 1);
			zephir_array_update_string(&params, SL("checked"), &_3, PH_COPY | PH_SEPARATE);
		}
	} else {
		if (zephir_is_true(value)) {
			ZEPHIR_INIT_NVAR(_3);
			ZVAL_STRING(_3, "checked", 1);
			zephir_array_update_string(&params, SL("checked"), &_3, PH_COPY | PH_SEPARATE);
		}
		zephir_array_update_string(&params, SL("value"), &value, PH_COPY | PH_SEPARATE);
	}
	ZEPHIR_INIT_VAR(_4);
	ZEPHIR_CONCAT_SVS(_4, "<input type=\"", type, "\"");
	ZEPHIR_CPY_WRT(code, _4);
	zephir_is_iterable(params, &_6, &_5, 0, 0);
	for (
	  ; zephir_hash_get_current_data_ex(_6, (void**) &_7, &_5) == SUCCESS
	  ; zephir_hash_move_forward_ex(_6, &_5)
	) {
		ZEPHIR_GET_HMKEY(key, _6, _5);
		ZEPHIR_GET_HVALUE(value, _7);
		if ((Z_TYPE_P(key) != IS_LONG)) {
			ZEPHIR_INIT_LNVAR(_8);
			ZEPHIR_CONCAT_SVSVS(_8, " ", key, "=\"", value, "\"");
			zephir_concat_self(&code, _8 TSRMLS_CC);
		}
	}
	zephir_read_static_property_ce(&doctype, phalcon_tag_ce, SL("_documentType") TSRMLS_CC);
	if (ZEPHIR_GT_LONG(doctype, 5)) {
		zephir_concat_self_str(&code, SL(" />") TSRMLS_CC);
	} else {
		zephir_concat_self_str(&code, SL(">") TSRMLS_CC);
	}
	RETURN_CCTOR(code);

}

/**
 * Builds a HTML input[type="color"] tag
 *
 * @param array parameters
 * @return string
 */
PHP_METHOD(Phalcon_Tag, colorField) {

	zval *parameters, *_0;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &parameters);



	ZEPHIR_INIT_VAR(_0);
	ZVAL_STRING(_0, "color", 1);
	zephir_call_self_p2(return_value, this_ptr, "_inputfield", _0, parameters);
	RETURN_MM();

}

/**
 * Builds a HTML input[type="text"] tag
 *
 * <code>
 *	echo Phalcon\Tag::textField(array("name", "size" => 30));
 * </code>
 *
 * @param	array parameters
 * @return	string
 */
PHP_METHOD(Phalcon_Tag, textField) {

	zval *parameters, *_0;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &parameters);



	ZEPHIR_INIT_VAR(_0);
	ZVAL_STRING(_0, "text", 1);
	zephir_call_self_p2(return_value, this_ptr, "_inputfield", _0, parameters);
	RETURN_MM();

}

/**
 * Builds a HTML input[type="number"] tag
 *
 * <code>
 *	echo Phalcon\Tag::numericField(array("price", "min" => "1", "max" => "5"));
 * </code>
 *
 * @param	array parameters
 * @return	string
 */
PHP_METHOD(Phalcon_Tag, numericField) {

	zval *parameters, *_0;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &parameters);



	ZEPHIR_INIT_VAR(_0);
	ZVAL_STRING(_0, "number", 1);
	zephir_call_self_p2(return_value, this_ptr, "_inputfield", _0, parameters);
	RETURN_MM();

}

/**
 * Builds a HTML input[type="range"] tag
 *
 * @param array parameters
 * @return string
 */
PHP_METHOD(Phalcon_Tag, rangeField) {

	zval *parameters, *_0;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &parameters);



	ZEPHIR_INIT_VAR(_0);
	ZVAL_STRING(_0, "range", 1);
	zephir_call_self_p2(return_value, this_ptr, "_inputfield", _0, parameters);
	RETURN_MM();

}

/**
 * Builds a HTML input[type="email"] tag
 *
 * <code>
 *	echo Phalcon\Tag::emailField("email");
 * </code>
 *
 * @param	array parameters
 * @return	string
 */
PHP_METHOD(Phalcon_Tag, emailField) {

	zval *parameters, *_0;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &parameters);



	ZEPHIR_INIT_VAR(_0);
	ZVAL_STRING(_0, "email", 1);
	zephir_call_self_p2(return_value, this_ptr, "_inputfield", _0, parameters);
	RETURN_MM();

}

/**
 * Builds a HTML input[type="date"] tag
 *
 * <code>
 *	echo Phalcon\Tag::dateField(array("born", "value" => "14-12-1980"))
 * </code>
 *
 * @param	array parameters
 * @return	string
 */
PHP_METHOD(Phalcon_Tag, dateField) {

	zval *parameters, *_0;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &parameters);



	ZEPHIR_INIT_VAR(_0);
	ZVAL_STRING(_0, "date", 1);
	zephir_call_self_p2(return_value, this_ptr, "_inputfield", _0, parameters);
	RETURN_MM();

}

/**
 * Builds a HTML input[type="datetime"] tag
 *
 * @param array parameters
 * @return string
 */
PHP_METHOD(Phalcon_Tag, dateTimeField) {

	zval *parameters, *_0;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &parameters);



	ZEPHIR_INIT_VAR(_0);
	ZVAL_STRING(_0, "datetime", 1);
	zephir_call_self_p2(return_value, this_ptr, "_inputfield", _0, parameters);
	RETURN_MM();

}

/**
 * Builds a HTML input[type="datetime-local"] tag
 *
 * @param array parameters
 * @return string
 */
PHP_METHOD(Phalcon_Tag, dateTimeLocalField) {

	zval *parameters, *_0;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &parameters);



	ZEPHIR_INIT_VAR(_0);
	ZVAL_STRING(_0, "datetime-local", 1);
	zephir_call_self_p2(return_value, this_ptr, "_inputfield", _0, parameters);
	RETURN_MM();

}

/**
 * Builds a HTML input[type="month"] tag
 *
 * @param array parameters
 * @return string
 */
PHP_METHOD(Phalcon_Tag, monthField) {

	zval *parameters, *_0;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &parameters);



	ZEPHIR_INIT_VAR(_0);
	ZVAL_STRING(_0, "month", 1);
	zephir_call_self_p2(return_value, this_ptr, "_inputfield", _0, parameters);
	RETURN_MM();

}

/**
 * Builds a HTML input[type="time"] tag
 *
 * @param array parameters
 * @return string
 */
PHP_METHOD(Phalcon_Tag, timeField) {

	zval *parameters, *_0;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &parameters);



	ZEPHIR_INIT_VAR(_0);
	ZVAL_STRING(_0, "time", 1);
	zephir_call_self_p2(return_value, this_ptr, "_inputfield", _0, parameters);
	RETURN_MM();

}

/**
 * Builds a HTML input[type="week"] tag
 *
 * @param array parameters
 * @return string
 */
PHP_METHOD(Phalcon_Tag, weekField) {

	zval *parameters, *_0;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &parameters);



	ZEPHIR_INIT_VAR(_0);
	ZVAL_STRING(_0, "week", 1);
	zephir_call_self_p2(return_value, this_ptr, "_inputfield", _0, parameters);
	RETURN_MM();

}

/**
 * Builds a HTML input[type="password"] tag
 *
 *<code>
 * echo Phalcon\Tag::passwordField(array("name", "size" => 30));
 *</code>
 *
 * @param	array parameters
 * @return	string
 */
PHP_METHOD(Phalcon_Tag, passwordField) {

	zval *parameters, *_0;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &parameters);



	ZEPHIR_INIT_VAR(_0);
	ZVAL_STRING(_0, "password", 1);
	zephir_call_self_p2(return_value, this_ptr, "_inputfield", _0, parameters);
	RETURN_MM();

}

/**
 * Builds a HTML input[type="hidden"] tag
 *
 *<code>
 * echo Phalcon\Tag::hiddenField(array("name", "value" => "mike"));
 *</code>
 *
 * @param	array parameters
 * @return	string
 */
PHP_METHOD(Phalcon_Tag, hiddenField) {

	zval *parameters, *_0;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &parameters);



	ZEPHIR_INIT_VAR(_0);
	ZVAL_STRING(_0, "hidden", 1);
	zephir_call_self_p2(return_value, this_ptr, "_inputfield", _0, parameters);
	RETURN_MM();

}

/**
 * Builds a HTML input[type="file"] tag
 *
 *<code>
 * echo Phalcon\Tag::fileField("file");
 *</code>
 *
 * @param	array parameters
 * @return	string
 */
PHP_METHOD(Phalcon_Tag, fileField) {

	zval *parameters, *_0;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &parameters);



	ZEPHIR_INIT_VAR(_0);
	ZVAL_STRING(_0, "file", 1);
	zephir_call_self_p2(return_value, this_ptr, "_inputfield", _0, parameters);
	RETURN_MM();

}

/**
 * Builds a HTML input[type="search"] tag
 *
 * @param array parameters
 * @return string
 */
PHP_METHOD(Phalcon_Tag, searchField) {

	zval *parameters, *_0;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &parameters);



	ZEPHIR_INIT_VAR(_0);
	ZVAL_STRING(_0, "search", 1);
	zephir_call_self_p2(return_value, this_ptr, "_inputfield", _0, parameters);
	RETURN_MM();

}

/**
 * Builds a HTML input[type="tel"] tag
 *
 * @param array parameters
 * @return string
 */
PHP_METHOD(Phalcon_Tag, telField) {

	zval *parameters, *_0;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &parameters);



	ZEPHIR_INIT_VAR(_0);
	ZVAL_STRING(_0, "tel", 1);
	zephir_call_self_p2(return_value, this_ptr, "_inputfield", _0, parameters);
	RETURN_MM();

}

/**
 * Builds a HTML input[type="url"] tag
 *
 * @param array parameters
 * @return string
 */
PHP_METHOD(Phalcon_Tag, urlField) {

	zval *parameters, *_0;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &parameters);



	ZEPHIR_INIT_VAR(_0);
	ZVAL_STRING(_0, "url", 1);
	zephir_call_self_p2(return_value, this_ptr, "_inputfield", _0, parameters);
	RETURN_MM();

}

/**
 * Builds a HTML input[type="check"] tag
 *
 *<code>
 * echo Phalcon\Tag::checkField(array("terms", "value" => "Y"));
 *</code>
 *
 * @param	array parameters
 * @return	string
 */
PHP_METHOD(Phalcon_Tag, checkField) {

	zval *parameters, *_0;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &parameters);



	ZEPHIR_INIT_VAR(_0);
	ZVAL_STRING(_0, "checkbox", 1);
	zephir_call_self_p2(return_value, this_ptr, "_inputfieldchecked", _0, parameters);
	RETURN_MM();

}

/**
 * Builds a HTML input[type="radio"] tag
 *
 *<code>
 * echo Phalcon\Tag::radioField(array("wheather", "value" => "hot"))
 *</code>
 *
 * Volt syntax:
 *<code>
 * {{ radio_field("Save") }}
 *</code>
 *
 * @param	array parameters
 * @return	string
 */
PHP_METHOD(Phalcon_Tag, radioField) {

	zval *parameters, *_0;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &parameters);



	ZEPHIR_INIT_VAR(_0);
	ZVAL_STRING(_0, "radio", 1);
	zephir_call_self_p2(return_value, this_ptr, "_inputfieldchecked", _0, parameters);
	RETURN_MM();

}

/**
 * Builds a HTML input[type="image"] tag
 *
 *<code>
 * echo Phalcon\Tag::imageInput(array("src" => "/img/button.png"));
 *</code>
 *
 * Volt syntax:
 *<code>
 * {{ image_input("src": "/img/button.png") }}
 *</code>
 *
 * @param	array parameters
 * @return	string
 */
PHP_METHOD(Phalcon_Tag, imageInput) {

	zval *parameters, *_0;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &parameters);



	ZEPHIR_INIT_VAR(_0);
	ZVAL_STRING(_0, "image", 1);
	zephir_call_self_p3(return_value, this_ptr, "_inputfield", _0, parameters, ZEPHIR_GLOBAL(global_true));
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
 * @param	array parameters
 * @return	string
 */
PHP_METHOD(Phalcon_Tag, submitButton) {

	zval *parameters, *_0;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &parameters);



	ZEPHIR_INIT_VAR(_0);
	ZVAL_STRING(_0, "submit", 1);
	zephir_call_self_p3(return_value, this_ptr, "_inputfield", _0, parameters, ZEPHIR_GLOBAL(global_true));
	RETURN_MM();

}

/**
 * Builds a HTML SELECT tag using a PHP array for options
 *
 *<code>
 *	echo Phalcon\Tag::selectStatic("status", array("A" => "Active", "I" => "Inactive"))
 *</code>
 *
 * @param	array parameters
 * @param   array data
 * @return	string
 */
PHP_METHOD(Phalcon_Tag, selectStatic) {

	zval *parameters, *data = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &parameters, &data);

	if (!data) {
		data = ZEPHIR_GLOBAL(global_null);
	}


	zephir_call_static_p2(return_value, "Phalcon\\Tag\\Select", "selectfield", parameters, data);
	RETURN_MM();

}

/**
 * Builds a HTML SELECT tag using a Phalcon\Mvc\Model resultset as options
 *
 *<code>
 *	echo Phalcon\Tag::select(array(
 *		"robotId",
 *		Robots::find("type = "mechanical""),
 *		"using" => array("id", "name")
 * 	));
 *</code>
 *
 * Volt syntax:
 *<code>
 * {{ select("robotId", robots, "using": ["id", "name"]) }}
 *</code>
 *
 * @param	array parameters
 * @param   array data
 * @return	string
 */
PHP_METHOD(Phalcon_Tag, select) {

	zval *parameters, *data = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &parameters, &data);

	if (!data) {
		data = ZEPHIR_GLOBAL(global_null);
	}


	zephir_call_static_p2(return_value, "Phalcon\\Tag\\Select", "selectfield", parameters, data);
	RETURN_MM();

}

/**
 * Builds a HTML TEXTAREA tag
 *
 *<code>
 * echo Phalcon\Tag::textArea(array("comments", "cols" => 10, "rows" => 4))
 *</code>
 *
 * Volt syntax:
 *<code>
 * {{ text_area("comments", "cols": 10, "rows": 4) }}
 *</code>
 *
 * @param	array parameters
 * @return	string
 */
PHP_METHOD(Phalcon_Tag, textArea) {

	HashTable *_2;
	HashPosition _1;
	zval *parameters, *params = NULL, *id, *key = NULL, *name, *avalue = NULL, *content = NULL, *code, *_0, **_3, *_4 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &parameters);



	if ((Z_TYPE_P(parameters) != IS_ARRAY)) {
		ZEPHIR_INIT_VAR(params);
		array_init_size(params, 2);
		zephir_array_fast_append(params, parameters);
	} else {
		ZEPHIR_CPY_WRT(params, parameters);
	}
	if (!(zephir_array_isset_long(params, 0))) {
		if (zephir_array_isset_string(params, SS("id"))) {
			zephir_array_fetch_string(&_0, params, SL("id"), PH_NOISY | PH_READONLY TSRMLS_CC);
			zephir_array_update_long(&params, 0, &_0, PH_COPY | PH_SEPARATE, "phalcon/tag.zep", 967);
		}
	}
	ZEPHIR_OBS_VAR(id);
	zephir_array_fetch_long(&id, params, 0, PH_NOISY TSRMLS_CC);
	if (!(zephir_array_isset_string(params, SS("name")))) {
		zephir_array_update_string(&params, SL("name"), &id, PH_COPY | PH_SEPARATE);
	} else {
		ZEPHIR_OBS_VAR(name);
		zephir_array_fetch_string(&name, params, SL("name"), PH_NOISY TSRMLS_CC);
		if (ZEPHIR_IS_EMPTY(name)) {
			zephir_array_update_string(&params, SL("name"), &id, PH_COPY | PH_SEPARATE);
		}
	}
	if (!(zephir_array_isset_string(params, SS("id")))) {
		zephir_array_update_string(&params, SL("id"), &id, PH_COPY | PH_SEPARATE);
	}
	if (zephir_array_isset_string(params, SS("value"))) {
		ZEPHIR_OBS_VAR(content);
		zephir_array_fetch_string(&content, params, SL("value"), PH_NOISY TSRMLS_CC);
		zephir_array_fetch_string(&_0, params, SL("value"), PH_NOISY | PH_READONLY TSRMLS_CC);
		zephir_array_unset(&params, _0, PH_SEPARATE);
	} else {
		ZEPHIR_INIT_NVAR(content);
		zephir_call_self_p2(content, this_ptr, "getvalue", id, params);
	}
	ZEPHIR_INIT_VAR(code);
	ZVAL_STRING(code, "<textarea", 1);
	zephir_is_iterable(params, &_2, &_1, 0, 0);
	for (
	  ; zephir_hash_get_current_data_ex(_2, (void**) &_3, &_1) == SUCCESS
	  ; zephir_hash_move_forward_ex(_2, &_1)
	) {
		ZEPHIR_GET_HMKEY(key, _2, _1);
		ZEPHIR_GET_HVALUE(avalue, _3);
		if ((Z_TYPE_P(key) != IS_LONG)) {
			ZEPHIR_INIT_LNVAR(_4);
			ZEPHIR_CONCAT_SVSVS(_4, " ", key, "=\"", avalue, "\"");
			zephir_concat_self(&code, _4 TSRMLS_CC);
		}
	}
	ZEPHIR_INIT_LNVAR(_4);
	ZEPHIR_CONCAT_SVS(_4, ">", content, "</textarea>");
	zephir_concat_self(&code, _4 TSRMLS_CC);
	RETURN_CCTOR(code);

}

/**
 * Builds a HTML FORM tag
 *
 * <code>
 * echo Phalcon\Tag::form("posts/save");
 * echo Phalcon\Tag::form(array("posts/save", "method" => "post"));
 * </code>
 *
 * Volt syntax:
 * <code>
 * {{ form("posts/save") }}
 * {{ form("posts/save", "method": "post") }}
 * </code>
 *
 * @param array parameters
 * @return string
 */
PHP_METHOD(Phalcon_Tag, form) {

	HashTable *_3;
	HashPosition _2;
	zval *parameters = NULL, *params = NULL, *paramsAction = NULL, *action, *url, *code, *key = NULL, *avalue = NULL, *_0, *_1 = NULL, **_4;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &parameters);

	ZEPHIR_SEPARATE_PARAM(parameters);


	if ((Z_TYPE_P(parameters) != IS_ARRAY)) {
		ZEPHIR_INIT_VAR(params);
		array_init_size(params, 2);
		zephir_array_fast_append(params, parameters);
	} else {
		ZEPHIR_CPY_WRT(params, parameters);
	}
	if (zephir_array_isset_long(params, 0)) {
		ZEPHIR_OBS_VAR(paramsAction);
		zephir_array_fetch_long(&paramsAction, params, 0, PH_NOISY TSRMLS_CC);
	} else {
		if (zephir_array_isset_string(params, SS("action"))) {
			ZEPHIR_OBS_NVAR(paramsAction);
			zephir_array_fetch_string(&paramsAction, params, SL("action"), PH_NOISY TSRMLS_CC);
		} else {
			ZEPHIR_INIT_NVAR(paramsAction);
			ZVAL_NULL(paramsAction);
		}
	}
	if (!(zephir_array_isset_string(params, SS("method")))) {
		ZEPHIR_INIT_VAR(_0);
		ZVAL_STRING(_0, "post", 1);
		zephir_array_update_string(&params, SL("method"), &_0, PH_COPY | PH_SEPARATE);
	}
	ZEPHIR_INIT_VAR(action);
	ZVAL_NULL(action);
	if (!(ZEPHIR_IS_EMPTY(paramsAction))) {
		ZEPHIR_INIT_VAR(url);
		zephir_call_self(url, this_ptr, "geturlservice");
		ZEPHIR_INIT_BNVAR(action);
		zephir_call_method_p1(action, url, "get", paramsAction);
	}
	if (zephir_array_isset_string(params, SS("parameters"))) {
		ZEPHIR_OBS_NVAR(parameters);
		zephir_array_fetch_string(&parameters, params, SL("parameters"), PH_NOISY TSRMLS_CC);
		ZEPHIR_INIT_VAR(_1);
		ZEPHIR_CONCAT_SV(_1, "?", parameters);
		zephir_concat_self(&action, _1 TSRMLS_CC);
	}
	if (!(ZEPHIR_IS_EMPTY(action))) {
		zephir_array_update_string(&params, SL("action"), &action, PH_COPY | PH_SEPARATE);
	}
	ZEPHIR_INIT_VAR(code);
	ZVAL_STRING(code, "<form", 1);
	zephir_is_iterable(params, &_3, &_2, 0, 0);
	for (
	  ; zephir_hash_get_current_data_ex(_3, (void**) &_4, &_2) == SUCCESS
	  ; zephir_hash_move_forward_ex(_3, &_2)
	) {
		ZEPHIR_GET_HMKEY(key, _3, _2);
		ZEPHIR_GET_HVALUE(avalue, _4);
		if ((Z_TYPE_P(key) != IS_LONG)) {
			ZEPHIR_INIT_LNVAR(_1);
			ZEPHIR_CONCAT_SVSVS(_1, " ", key, "=\"", avalue, "\"");
			zephir_concat_self(&code, _1 TSRMLS_CC);
		}
	}
	zephir_concat_self_str(&code, SL(">") TSRMLS_CC);
	RETURN_CCTOR(code);

}

/**
 * Builds a HTML close FORM tag
 *
 * @return	string
 */
PHP_METHOD(Phalcon_Tag, endForm) {


	RETURN_STRING("</form>", 1);

}

/**
 * Set the title of view content
 *
 *<code>
 * Phalcon\Tag::setTitle("Welcome to my Page");
 *</code>
 *
 * @param string title
 */
PHP_METHOD(Phalcon_Tag, setTitle) {

	zval *title_param = NULL, *_0;
	zval *title = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &title_param);

	zephir_get_strval(title, title_param);


	zephir_update_static_property_ce(phalcon_tag_ce, SL("_documentTitle"), title TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

/**
 * Set the title separator of view content
 *
 *<code>
 * Phalcon\Tag::setTitleSeparator("-");
 *</code>
 *
 * @param string titleSeparator
 */
PHP_METHOD(Phalcon_Tag, setTitleSeparator) {

	zval *titleSeparator_param = NULL, *_0;
	zval *titleSeparator = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &titleSeparator_param);

	zephir_get_strval(titleSeparator, titleSeparator_param);


	zephir_update_static_property_ce(phalcon_tag_ce, SL("_documentTitleSeparator"), titleSeparator TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

/**
 * Appends a text to current document title
 *
 * @param string title
 */
PHP_METHOD(Phalcon_Tag, appendTitle) {

	zval *title_param = NULL, *_0;
	zval *title = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &title_param);

	zephir_get_strval(title, title_param);


	zephir_update_static_property_ce(phalcon_tag_ce, SL("_documentTitle"), title TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

/**
 * Prepends a text to current document title
 *
 * @param string title
 */
PHP_METHOD(Phalcon_Tag, prependTitle) {

	zval *title_param = NULL, *_0, *_1, *_2;
	zval *title = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &title_param);

	zephir_get_strval(title, title_param);


	zephir_read_static_property_ce(&_1, phalcon_tag_ce, SL("_documentTitle") TSRMLS_CC);
	ZEPHIR_INIT_VAR(_2);
	ZEPHIR_CONCAT_VV(_2, title, _1);
	zephir_update_static_property_ce(phalcon_tag_ce, SL("_documentTitle"), _2 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

/**
 * Gets the current document title
 *
 * <code>
 * 	echo Phalcon\Tag::getTitle();
 * </code>
 *
 * <code>
 * 	{{ get_title() }}
 * </code>
 *
 * @return string
 */
PHP_METHOD(Phalcon_Tag, getTitle) {

	zval *tags_param = NULL, *documentTitle, *_0;
	zend_bool tags;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &tags_param);

	if (!tags_param) {
		tags = 1;
	} else {
		tags = zephir_get_boolval(tags_param);
	}


	zephir_read_static_property_ce(&documentTitle, phalcon_tag_ce, SL("_documentTitle") TSRMLS_CC);
	if (tags) {
		ZEPHIR_INIT_VAR(_0);
		ZEPHIR_GET_CONSTANT(_0, "PHP_EOL");
		ZEPHIR_CONCAT_SVSV(return_value, "<title>", documentTitle, "</title>", _0);
		RETURN_MM();
	}
	RETURN_CCTOR(documentTitle);

}

/**
 * Gets the current document title separator
 *
 * <code>
 *         echo Phalcon\Tag::getTitleSeparator();
 * </code>
 *
 * <code>
 *         {{ get_title_separator() }}
 * </code>
 *
 * @return string
 */
PHP_METHOD(Phalcon_Tag, getTitleSeparator) {


	RETURN_MEMBER(this_ptr, "_documentTitleSeparator");

}

/**
 * Builds a LINK[rel="stylesheet"] tag
 *
 * <code>
 * 	echo Phalcon\Tag::stylesheetLink("http://fonts.googleapis.com/css?family=Rosario", false);
 * 	echo Phalcon\Tag::stylesheetLink("css/style.css");
 * </code>
 *
 * Volt Syntax:
 *<code>
 * 	{{ stylesheet_link("http://fonts.googleapis.com/css?family=Rosario", false) }}
 * 	{{ stylesheet_link("css/style.css") }}
 *</code>
 *
 * @param	array parameters
 * @param   boolean local
 * @return	string
 */
PHP_METHOD(Phalcon_Tag, stylesheetLink) {

	HashTable *_4;
	HashPosition _3;
	zval *parameters = NULL, *local = NULL, *params = NULL, *firstParam, *url, *code, *key = NULL, *value = NULL, *doctype, *eol, *_0 = NULL, *_1, *_2, **_5, *_6 = NULL, *_7;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 2, &parameters, &local);

	if (!parameters) {
		parameters = ZEPHIR_GLOBAL(global_null);
	}
	if (!local) {
		ZEPHIR_CPY_WRT(local, ZEPHIR_GLOBAL(global_true));
	} else {
		ZEPHIR_SEPARATE_PARAM(local);
	}


	if ((Z_TYPE_P(parameters) != IS_ARRAY)) {
		ZEPHIR_INIT_VAR(params);
		array_init_size(params, 3);
		zephir_array_fast_append(params, parameters);
		zephir_array_fast_append(params, local);
	} else {
		ZEPHIR_CPY_WRT(params, parameters);
	}
	if (!(zephir_array_isset_string(params, SS("href")))) {
		if (zephir_array_isset_long(params, 0)) {
			ZEPHIR_OBS_VAR(firstParam);
			zephir_array_fetch_long(&firstParam, params, 0, PH_NOISY TSRMLS_CC);
			zephir_array_update_string(&params, SL("href"), &firstParam, PH_COPY | PH_SEPARATE);
		} else {
			ZEPHIR_INIT_VAR(_0);
			ZVAL_STRING(_0, "", 1);
			zephir_array_update_string(&params, SL("href"), &_0, PH_COPY | PH_SEPARATE);
		}
	}
	ZEPHIR_INIT_BNVAR(local);
	ZVAL_BOOL(local, 0);
	if (zephir_array_isset_long(params, 1)) {
		ZEPHIR_OBS_NVAR(local);
		zephir_array_fetch_long(&local, params, 1, PH_NOISY TSRMLS_CC);
	} else {
		if (zephir_array_isset_string(params, SS("local"))) {
			ZEPHIR_OBS_NVAR(local);
			zephir_array_fetch_string(&local, params, SL("local"), PH_NOISY TSRMLS_CC);
			zephir_array_fetch_string(&_1, params, SL("local"), PH_NOISY | PH_READONLY TSRMLS_CC);
			zephir_array_unset(&params, _1, PH_SEPARATE);
		}
	}
	if (!(zephir_array_isset_string(params, SS("type")))) {
		ZEPHIR_INIT_NVAR(_0);
		ZVAL_STRING(_0, "text/css", 1);
		zephir_array_update_string(&params, SL("type"), &_0, PH_COPY | PH_SEPARATE);
	}
	if (zephir_is_true(local)) {
		ZEPHIR_INIT_VAR(url);
		zephir_call_self(url, this_ptr, "geturlservice");
		ZEPHIR_INIT_VAR(_2);
		zephir_array_fetch_string(&_1, params, SL("href"), PH_NOISY | PH_READONLY TSRMLS_CC);
		zephir_call_method_p1(_2, url, "getstatic", _1);
		zephir_array_update_string(&params, SL("href"), &_2, PH_COPY | PH_SEPARATE);
		//missing empty
	}
	ZEPHIR_INIT_VAR(code);
	ZVAL_STRING(code, "<link rel=\"stylesheet\"", 1);
	zephir_is_iterable(params, &_4, &_3, 0, 0);
	for (
	  ; zephir_hash_get_current_data_ex(_4, (void**) &_5, &_3) == SUCCESS
	  ; zephir_hash_move_forward_ex(_4, &_3)
	) {
		ZEPHIR_GET_HMKEY(key, _4, _3);
		ZEPHIR_GET_HVALUE(value, _5);
		if ((Z_TYPE_P(key) != IS_LONG)) {
			ZEPHIR_INIT_LNVAR(_6);
			ZEPHIR_CONCAT_SVSVS(_6, " ", key, "=\"", value, "\"");
			zephir_concat_self(&code, _6 TSRMLS_CC);
		}
	}
	zephir_read_static_property_ce(&doctype, phalcon_tag_ce, SL("_documentType") TSRMLS_CC);
	ZEPHIR_INIT_VAR(eol);
	ZEPHIR_GET_CONSTANT(eol, "PHP_EOL");
	if (ZEPHIR_GT_LONG(doctype, 5)) {
		ZEPHIR_INIT_LNVAR(_6);
		ZEPHIR_CONCAT_SV(_6, " />", eol);
		zephir_concat_self(&code, _6 TSRMLS_CC);
	} else {
		ZEPHIR_INIT_VAR(_7);
		ZEPHIR_CONCAT_SV(_7, ">", eol);
		zephir_concat_self(&code, _7 TSRMLS_CC);
	}
	RETURN_CCTOR(code);

}

/**
 * Builds a SCRIPT[type="javascript"] tag
 *
 * <code>
 *         echo Phalcon\Tag::javascriptInclude("http://ajax.googleapis.com/ajax/libs/jquery/1.7.1/jquery.min.js", false);
 *         echo Phalcon\Tag::javascriptInclude("javascript/jquery.js");
 * </code>
 *
 * Volt syntax:
 * <code>
 * {{ javascript_include("http://ajax.googleapis.com/ajax/libs/jquery/1.7.1/jquery.min.js", false) }}
 * {{ javascript_include("javascript/jquery.js") }}
 * </code>
 *
 * @param array parameters
 * @param   boolean local
 * @return string
 */
PHP_METHOD(Phalcon_Tag, javascriptInclude) {

	HashTable *_4;
	HashPosition _3;
	zval *parameters = NULL, *local = NULL, *params = NULL, *firstParam, *code, *url, *eol, *key = NULL, *value = NULL, *_0 = NULL, *_1, *_2, **_5, *_6 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 2, &parameters, &local);

	if (!parameters) {
		parameters = ZEPHIR_GLOBAL(global_null);
	}
	if (!local) {
		ZEPHIR_CPY_WRT(local, ZEPHIR_GLOBAL(global_true));
	} else {
		ZEPHIR_SEPARATE_PARAM(local);
	}


	if ((Z_TYPE_P(parameters) != IS_ARRAY)) {
		ZEPHIR_INIT_VAR(params);
		array_init_size(params, 3);
		zephir_array_fast_append(params, parameters);
		zephir_array_fast_append(params, local);
	} else {
		ZEPHIR_CPY_WRT(params, parameters);
	}
	if (!(zephir_array_isset_string(params, SS("src")))) {
		if (zephir_array_isset_long(params, 0)) {
			ZEPHIR_OBS_VAR(firstParam);
			zephir_array_fetch_long(&firstParam, params, 0, PH_NOISY TSRMLS_CC);
			zephir_array_update_string(&params, SL("src"), &firstParam, PH_COPY | PH_SEPARATE);
		} else {
			ZEPHIR_INIT_VAR(_0);
			ZVAL_STRING(_0, "", 1);
			zephir_array_update_string(&params, SL("src"), &_0, PH_COPY | PH_SEPARATE);
		}
	}
	ZEPHIR_INIT_BNVAR(local);
	ZVAL_BOOL(local, 0);
	if (zephir_array_isset_long(params, 1)) {
		ZEPHIR_OBS_NVAR(local);
		zephir_array_fetch_long(&local, params, 1, PH_NOISY TSRMLS_CC);
	} else {
		if (zephir_array_isset_string(params, SS("local"))) {
			ZEPHIR_OBS_NVAR(local);
			zephir_array_fetch_string(&local, params, SL("local"), PH_NOISY TSRMLS_CC);
			zephir_array_fetch_string(&_1, params, SL("local"), PH_NOISY | PH_READONLY TSRMLS_CC);
			zephir_array_unset(&params, _1, PH_SEPARATE);
		}
	}
	if (!(zephir_array_isset_string(params, SS("type")))) {
		ZEPHIR_INIT_NVAR(_0);
		ZVAL_STRING(_0, "text/javascript", 1);
		zephir_array_update_string(&params, SL("type"), &_0, PH_COPY | PH_SEPARATE);
	}
	if (zephir_is_true(local)) {
		ZEPHIR_INIT_VAR(url);
		zephir_call_self(url, this_ptr, "geturlservice");
		ZEPHIR_INIT_VAR(_2);
		zephir_array_fetch_string(&_1, params, SL("src"), PH_NOISY | PH_READONLY TSRMLS_CC);
		zephir_call_method_p1(_2, url, "getstatic", _1);
		zephir_array_update_string(&params, SL("src"), &_2, PH_COPY | PH_SEPARATE);
	}
	ZEPHIR_INIT_VAR(eol);
	ZEPHIR_GET_CONSTANT(eol, "PHP_EOL");
	ZEPHIR_INIT_VAR(code);
	ZVAL_STRING(code, "<script", 1);
	zephir_is_iterable(params, &_4, &_3, 0, 0);
	for (
	  ; zephir_hash_get_current_data_ex(_4, (void**) &_5, &_3) == SUCCESS
	  ; zephir_hash_move_forward_ex(_4, &_3)
	) {
		ZEPHIR_GET_HMKEY(key, _4, _3);
		ZEPHIR_GET_HVALUE(value, _5);
		if ((Z_TYPE_P(key) != IS_LONG)) {
			ZEPHIR_INIT_LNVAR(_6);
			ZEPHIR_CONCAT_SVSVS(_6, " ", key, "=\"", value, "\"");
			zephir_concat_self(&code, _6 TSRMLS_CC);
		}
	}
	ZEPHIR_INIT_LNVAR(_6);
	ZEPHIR_CONCAT_SV(_6, "></script>", eol);
	zephir_concat_self(&code, _6 TSRMLS_CC);
	RETURN_CCTOR(code);

}

/**
 * Builds HTML IMG tags
 *
 * <code>
 *         echo Phalcon\Tag::image("img/bg.png");
 *         echo Phalcon\Tag::image(array("img/photo.jpg", "alt" => "Some Photo"));
 * </code>
 *
 * Volt Syntax:
 * <code>
 *         {{ image("img/bg.png") }}
 *         {{ image("img/photo.jpg", "alt": "Some Photo") }}
 *         {{ image("http://static.mywebsite.com/img/bg.png", false) }}
 * </code>
 *
 * @param  array parameters
 * @param  boolean local
 * @return string
 */
PHP_METHOD(Phalcon_Tag, image) {

	HashTable *_3;
	HashPosition _2;
	zval *parameters = NULL, *local = NULL, *params = NULL, *code, *url, *key = NULL, *value = NULL, *doctype, *_0, *_1 = NULL, **_4, *_5 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 2, &parameters, &local);

	if (!parameters) {
		parameters = ZEPHIR_GLOBAL(global_null);
	}
	if (!local) {
		local = ZEPHIR_GLOBAL(global_true);
	}


	if ((Z_TYPE_P(parameters) != IS_ARRAY)) {
		ZEPHIR_INIT_VAR(params);
		array_init_size(params, 2);
		zephir_array_fast_append(params, parameters);
	} else {
		ZEPHIR_CPY_WRT(params, parameters);
	}
	if (!(zephir_array_isset_string(params, SS("src")))) {
		if (zephir_array_isset_long(params, 0)) {
			zephir_array_fetch_long(&_0, params, 0, PH_NOISY | PH_READONLY TSRMLS_CC);
			zephir_array_update_string(&params, SL("src"), &_0, PH_COPY | PH_SEPARATE);
		} else {
			ZEPHIR_INIT_VAR(_1);
			ZVAL_STRING(_1, "", 1);
			zephir_array_update_string(&params, SL("src"), &_1, PH_COPY | PH_SEPARATE);
		}
	}
	if (zephir_is_true(local)) {
		ZEPHIR_INIT_VAR(url);
		zephir_call_self(url, this_ptr, "geturlservice");
		ZEPHIR_INIT_NVAR(_1);
		zephir_array_fetch_string(&_0, params, SL("src"), PH_NOISY | PH_READONLY TSRMLS_CC);
		zephir_call_method_p1(_1, url, "getstatic", _0);
		zephir_array_update_string(&params, SL("src"), &_1, PH_COPY | PH_SEPARATE);
	}
	ZEPHIR_INIT_VAR(code);
	ZVAL_STRING(code, "<img", 1);
	zephir_is_iterable(params, &_3, &_2, 0, 0);
	for (
	  ; zephir_hash_get_current_data_ex(_3, (void**) &_4, &_2) == SUCCESS
	  ; zephir_hash_move_forward_ex(_3, &_2)
	) {
		ZEPHIR_GET_HMKEY(key, _3, _2);
		ZEPHIR_GET_HVALUE(value, _4);
		if ((Z_TYPE_P(key) != IS_LONG)) {
			ZEPHIR_INIT_LNVAR(_5);
			ZEPHIR_CONCAT_SVSVS(_5, " ", key, "=\"", value, "\"");
			zephir_concat_self(&code, _5 TSRMLS_CC);
		}
	}
	zephir_read_static_property_ce(&doctype, phalcon_tag_ce, SL("_documentType") TSRMLS_CC);
	if (ZEPHIR_GT_LONG(doctype, 5)) {
		zephir_concat_self_str(&code, SL(" />") TSRMLS_CC);
	} else {
		zephir_concat_self_str(&code, SL(">") TSRMLS_CC);
	}
	RETURN_CCTOR(code);

}

/**
 * Converts texts into URL-friendly titles
 *
 *<code>
 * echo Phalcon\Tag::friendlyTitle("These are big important news", "-")
 *</code>
 *
 * @param string text
 * @param string separator
 * @param boolean lowercase
 * @return text
 */
PHP_METHOD(Phalcon_Tag, friendlyTitle) {

	zval *text, *separator = NULL, *lowercase = NULL, *pattern, *friendly, *friendlyText = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 2, &text, &separator, &lowercase);

	if (!separator) {
		ZEPHIR_INIT_VAR(separator);
		ZVAL_STRING(separator, "-", 1);
	}
	if (!lowercase) {
		lowercase = ZEPHIR_GLOBAL(global_true);
	}


	ZEPHIR_INIT_VAR(pattern);
	ZVAL_STRING(pattern, "~[^a-z0-9A-Z]+~", 1);
	ZEPHIR_INIT_VAR(friendly);
	zephir_call_func_p3(friendly, "preg_replace", pattern, separator, text);
	if (!(ZEPHIR_IS_EMPTY(lowercase))) {
		ZEPHIR_INIT_VAR(friendlyText);
		zephir_fast_strtolower(friendlyText, friendly);
	} else {
		ZEPHIR_CPY_WRT(friendlyText, friendly);
	}
	RETURN_CCTOR(friendlyText);

}

/**
 * Set the document type of content
 *
 * @param string doctype
 */
PHP_METHOD(Phalcon_Tag, setDocType) {

	zval *doctype, *_0;

	zephir_fetch_params(0, 1, 0, &doctype);



	zephir_update_static_property_ce(phalcon_tag_ce, SL("_documentType"), doctype TSRMLS_CC);

}

/**
 * Get the document type declaration of content
 *
 * @return string
 */
PHP_METHOD(Phalcon_Tag, getDocType) {

	zval *doctype, *_0 = NULL, *_1 = NULL;

	ZEPHIR_MM_GROW();

	zephir_read_static_property_ce(&doctype, phalcon_tag_ce, SL("_documentType") TSRMLS_CC);
	do {
		if (ZEPHIR_IS_LONG(doctype, 1)) {
			ZEPHIR_INIT_VAR(_0);
			ZEPHIR_GET_CONSTANT(_0, "PHP_EOL");
			ZEPHIR_CONCAT_SV(return_value, "<!DOCTYPE html PUBLIC \"-//W3C//DTD HTML 3.2 Final//EN\">", _0);
			RETURN_MM();
		}
		if (ZEPHIR_IS_LONG(doctype, 2)) {
			ZEPHIR_INIT_NVAR(_0);
			ZEPHIR_GET_CONSTANT(_0, "PHP_EOL");
			ZEPHIR_INIT_VAR(_1);
			ZEPHIR_GET_CONSTANT(_1, "PHP_EOL");
			ZEPHIR_CONCAT_SVSV(return_value, "<!DOCTYPE html PUBLIC \"-//W3C//DTD HTML 4.01//EN\"", _0, "\t\"http://www.w3.org/TR/html4/strict.dtd\">", _1);
			RETURN_MM();
		}
		if (ZEPHIR_IS_LONG(doctype, 3)) {
			ZEPHIR_INIT_NVAR(_0);
			ZEPHIR_GET_CONSTANT(_0, "PHP_EOL");
			ZEPHIR_INIT_NVAR(_1);
			ZEPHIR_GET_CONSTANT(_1, "PHP_EOL");
			ZEPHIR_CONCAT_SVSV(return_value, "<!DOCTYPE html PUBLIC \"-//W3C//DTD HTML 4.01 Transitional//EN\"", _0, "\t\"http://www.w3.org/TR/html4/loose.dtd\">", _1);
			RETURN_MM();
		}
		if (ZEPHIR_IS_LONG(doctype, 4)) {
			ZEPHIR_INIT_NVAR(_0);
			ZEPHIR_GET_CONSTANT(_0, "PHP_EOL");
			ZEPHIR_INIT_NVAR(_1);
			ZEPHIR_GET_CONSTANT(_1, "PHP_EOL");
			ZEPHIR_CONCAT_SVSV(return_value, "<!DOCTYPE html PUBLIC \"-//W3C//DTD HTML 4.01 Frameset//EN\"", _0, "\t\"http://www.w3.org/TR/html4/frameset.dtd\">", _1);
			RETURN_MM();
		}
		if (ZEPHIR_IS_LONG(doctype, 5)) {
			ZEPHIR_INIT_NVAR(_0);
			ZEPHIR_GET_CONSTANT(_0, "PHP_EOL");
			ZEPHIR_CONCAT_SV(return_value, "<!DOCTYPE html>", _0);
			RETURN_MM();
		}
		if (ZEPHIR_IS_LONG(doctype, 6)) {
			ZEPHIR_INIT_NVAR(_0);
			ZEPHIR_GET_CONSTANT(_0, "PHP_EOL");
			ZEPHIR_INIT_NVAR(_1);
			ZEPHIR_GET_CONSTANT(_1, "PHP_EOL");
			ZEPHIR_CONCAT_SVSV(return_value, "<!DOCTYPE html PUBLIC \"-//W3C//DTD XHTML 1.0 Strict//EN\"", _0, "\t\"http://www.w3.org/TR/xhtml1/DTD/xhtml1-strict.dtd\">", _1);
			RETURN_MM();
		}
		if (ZEPHIR_IS_LONG(doctype, 7)) {
			ZEPHIR_INIT_NVAR(_0);
			ZEPHIR_GET_CONSTANT(_0, "PHP_EOL");
			ZEPHIR_INIT_NVAR(_1);
			ZEPHIR_GET_CONSTANT(_1, "PHP_EOL");
			ZEPHIR_CONCAT_SVSV(return_value, "<!DOCTYPE html PUBLIC \"-//W3C//DTD XHTML 1.0 Transitional//EN\"", _0, "\t\"http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd\">", _1);
			RETURN_MM();
		}
		if (ZEPHIR_IS_LONG(doctype, 8)) {
			ZEPHIR_INIT_NVAR(_0);
			ZEPHIR_GET_CONSTANT(_0, "PHP_EOL");
			ZEPHIR_INIT_NVAR(_1);
			ZEPHIR_GET_CONSTANT(_1, "PHP_EOL");
			ZEPHIR_CONCAT_SVSV(return_value, "<!DOCTYPE html PUBLIC \"-//W3C//DTD XHTML 1.0 Frameset//EN\"", _0, "\t\"http://www.w3.org/TR/xhtml1/DTD/xhtml1-frameset.dtd\">", _1);
			RETURN_MM();
		}
		if (ZEPHIR_IS_LONG(doctype, 9)) {
			ZEPHIR_INIT_NVAR(_0);
			ZEPHIR_GET_CONSTANT(_0, "PHP_EOL");
			ZEPHIR_INIT_NVAR(_1);
			ZEPHIR_GET_CONSTANT(_1, "PHP_EOL");
			ZEPHIR_CONCAT_SVSV(return_value, "<!DOCTYPE html PUBLIC \"-//W3C//DTD XHTML 1.1//EN\"", _0, "\t\"http://www.w3.org/TR/xhtml11/DTD/xhtml11.dtd\">", _1);
			RETURN_MM();
		}
		if (ZEPHIR_IS_LONG(doctype, 10)) {
			ZEPHIR_INIT_NVAR(_0);
			ZEPHIR_GET_CONSTANT(_0, "PHP_EOL");
			ZEPHIR_INIT_NVAR(_1);
			ZEPHIR_GET_CONSTANT(_1, "PHP_EOL");
			ZEPHIR_CONCAT_SVSV(return_value, "<!DOCTYPE html PUBLIC \"-//W3C//DTD XHTML 2.0//EN\"", _0, "\t\"http://www.w3.org/MarkUp/DTD/xhtml2.dtd\">", _1);
			RETURN_MM();
		}
		RETURN_MM_STRING("", 1);
	} while(0);

	ZEPHIR_MM_RESTORE();

}

/**
 * Builds a HTML tag
 *
 *<code>
 *        echo Phalcon\Tag::tagHtml(name, parameters, selfClose, onlyStart, eol);
 *</code>
 *
 * @param string tagName
 * @param array parameters
 * @param boolean selfClose
 * @param boolean onlyStart
 * @param boolean useEol
 * @return string
 */
PHP_METHOD(Phalcon_Tag, tagHtml) {

	HashTable *_1;
	HashPosition _0;
	zval *tagName, *parameters = NULL, *selfClose = NULL, *onlyStart = NULL, *useEol = NULL, *params = NULL, *localCode, *key = NULL, *value = NULL, *doctype, **_2, *_3 = NULL, *_4;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 4, &tagName, &parameters, &selfClose, &onlyStart, &useEol);

	if (!parameters) {
		parameters = ZEPHIR_GLOBAL(global_null);
	}
	if (!selfClose) {
		selfClose = ZEPHIR_GLOBAL(global_false);
	}
	if (!onlyStart) {
		onlyStart = ZEPHIR_GLOBAL(global_false);
	}
	if (!useEol) {
		useEol = ZEPHIR_GLOBAL(global_false);
	}


	if ((Z_TYPE_P(parameters) != IS_ARRAY)) {
		ZEPHIR_INIT_VAR(params);
		array_init_size(params, 2);
		zephir_array_fast_append(params, parameters);
	} else {
		ZEPHIR_CPY_WRT(params, parameters);
	}
	ZEPHIR_INIT_VAR(localCode);
	ZEPHIR_CONCAT_SV(localCode, "<", tagName);
	zephir_is_iterable(params, &_1, &_0, 0, 0);
	for (
	  ; zephir_hash_get_current_data_ex(_1, (void**) &_2, &_0) == SUCCESS
	  ; zephir_hash_move_forward_ex(_1, &_0)
	) {
		ZEPHIR_GET_HMKEY(key, _1, _0);
		ZEPHIR_GET_HVALUE(value, _2);
		if ((Z_TYPE_P(key) != IS_LONG)) {
			ZEPHIR_INIT_LNVAR(_3);
			ZEPHIR_CONCAT_SVSVS(_3, " ", key, "=\"", value, "\"");
			zephir_concat_self(&localCode, _3 TSRMLS_CC);
		}
	}
	zephir_read_static_property_ce(&doctype, phalcon_tag_ce, SL("_documentType") TSRMLS_CC);
	if (ZEPHIR_GT_LONG(doctype, 5)) {
		if (zephir_is_true(selfClose)) {
			zephir_concat_self_str(&localCode, SL(" />") TSRMLS_CC);
		} else {
			zephir_concat_self_str(&localCode, SL(">") TSRMLS_CC);
		}
	} else {
		if (zephir_is_true(onlyStart)) {
			zephir_concat_self_str(&localCode, SL(">") TSRMLS_CC);
		} else {
			ZEPHIR_INIT_LNVAR(_3);
			ZEPHIR_CONCAT_SVS(_3, "></", tagName, ">");
			zephir_concat_self(&localCode, _3 TSRMLS_CC);
		}
	}
	if (zephir_is_true(useEol)) {
		ZEPHIR_INIT_VAR(_4);
		ZEPHIR_GET_CONSTANT(_4, "PHP_EOL");
		zephir_concat_self(&localCode, _4 TSRMLS_CC);
	}
	RETURN_CCTOR(localCode);

}

/**
 * Builds a HTML tag closing tag
 *
 *<code>
 *        echo Phalcon\Tag::tagHtmlClose("script", true)
 *</code>
 *
 * @param string tagName
 * @param boolean useEol
 * @return string
 */
PHP_METHOD(Phalcon_Tag, tagHtmlClose) {

	zval *tagName, *useEol = NULL, *localCode, *_0;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &tagName, &useEol);

	if (!useEol) {
		useEol = ZEPHIR_GLOBAL(global_false);
	}


	ZEPHIR_INIT_VAR(localCode);
	ZEPHIR_CONCAT_SVS(localCode, "</", tagName, ">");
	if (zephir_is_true(useEol)) {
		ZEPHIR_INIT_VAR(_0);
		ZEPHIR_GET_CONSTANT(_0, "PHP_EOL");
		zephir_concat_self(&localCode, _0 TSRMLS_CC);
	}
	RETURN_CCTOR(localCode);

}

