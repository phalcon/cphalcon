
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
#include "kernel/exception.h"
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/operators.h"
#include "kernel/array.h"
#include "kernel/hash.h"
#include "kernel/concat.h"


/*
 +------------------------------------------------------------------------+
 | Phalcon Framework                                                      |
 +------------------------------------------------------------------------+
 | Copyright (c) 2011-2013 Phalcon Team (http://www.phalconphp.com)       |
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

/**
 * Sets the dependency injector container.
 *
 * @param Phalcon\DiInterface dependencyInjector
 */
PHP_METHOD(Phalcon_Tag, setDI) {

	zval *dependencyInjector;

	zephir_fetch_params(0, 1, 0, &dependencyInjector);



	if ((Z_TYPE_P(dependencyInjector) != IS_OBJECT)) {
		ZEPHIR_THROW_EXCEPTION_STRW(phalcon_tag_exception_ce, "Parameter dependencyInjector must be an Object");
		return;
	}

}

/**
 * Internally gets the request dispatcher
 *
 * @return Phalcon\DiInterface
 */
PHP_METHOD(Phalcon_Tag, getDI) {


	RETURN_NULL();

}

/**
 * Return a URL service from the default DI
 *
 * @return Phalcon\Mvc\UrlInterface
 */
PHP_METHOD(Phalcon_Tag, getUrlService) {

	zval *url, *dependencyInjector, *_0;

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(url);
	ZVAL_NULL(url);
	if ((Z_TYPE_P(url) != IS_OBJECT)) {
		ZEPHIR_INIT_VAR(dependencyInjector);
		ZVAL_NULL(dependencyInjector);
		if ((Z_TYPE_P(dependencyInjector) != IS_OBJECT)) {
		}
		if ((Z_TYPE_P(dependencyInjector) != IS_OBJECT)) {
			ZEPHIR_THROW_EXCEPTION_STR(phalcon_tag_exception_ce, "A dependency injector container is required to obtain the 'url' service");
			return;
		}
		ZEPHIR_INIT_VAR(_0);
		ZVAL_STRING(_0, "url", 1);
		ZEPHIR_INIT_BNVAR(url);
		zephir_call_method_p1(url, dependencyInjector, "getshared", _0);
	}
	RETURN_CCTOR(url);

}

/**
 * Returns an Escaper service from the default DI
 *
 * @return Phalcon\EscaperInterface
 */
PHP_METHOD(Phalcon_Tag, getEscaperService) {

	zval *escaper, *dependencyInjector, *_0;

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(escaper);
	ZVAL_NULL(escaper);
	if ((Z_TYPE_P(escaper) != IS_OBJECT)) {
		ZEPHIR_INIT_VAR(dependencyInjector);
		ZVAL_NULL(dependencyInjector);
		if ((Z_TYPE_P(dependencyInjector) != IS_OBJECT)) {
		}
		if ((Z_TYPE_P(dependencyInjector) != IS_OBJECT)) {
			ZEPHIR_THROW_EXCEPTION_STR(phalcon_tag_exception_ce, "A dependency injector container is required to obtain the 'escaper' service");
			return;
		}
		ZEPHIR_INIT_VAR(_0);
		ZVAL_STRING(_0, "escaper", 1);
		ZEPHIR_INIT_BNVAR(escaper);
		zephir_call_method_p1(escaper, dependencyInjector, "getshared", _0);
	}
	RETURN_CCTOR(escaper);

}

/**
 * Set autoescape mode in generated html
 *
 * @param boolean autoescape
 */
PHP_METHOD(Phalcon_Tag, setAutoescape) {

	zval *autoescape;

	zephir_fetch_params(0, 1, 0, &autoescape);




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

	zval *id, *value;

	zephir_fetch_params(0, 2, 0, &id, &value);



	if ((Z_TYPE_P(value) != IS_NULL)) {
		if (((Z_TYPE_P(value) == IS_ARRAY) || (Z_TYPE_P(value) == IS_OBJECT))) {
			ZEPHIR_THROW_EXCEPTION_STRW(phalcon_tag_exception_ce, "Only scalar values can be assigned to UI components");
			return;
		}
	}

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

	zval *values;

	zephir_fetch_params(0, 1, 0, &values);



	if ((Z_TYPE_P(values) != IS_ARRAY)) {
		ZEPHIR_THROW_EXCEPTION_STRW(phalcon_tag_exception_ce, "An array is required as default values");
		return;
	}

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

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &name);



	ZEPHIR_INIT_VAR(displayValues);
	ZVAL_NULL(displayValues);
	if (zephir_array_isset(displayValues, name)) {
		RETURN_MM_BOOL(1);
	} else {
		zephir_get_global(&_POST, SS("_POST") TSRMLS_CC);
		if (zephir_array_isset(_POST, name)) {
			RETURN_MM_BOOL(1);
		}
	}
	RETURN_MM_BOOL(0);

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

	zval *name, *params = NULL, *value = NULL, *autoescape, *displayValues, *escaper = NULL, *_POST;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &name, &params);

	if (!params) {
		ZEPHIR_CPY_WRT(params, ZEPHIR_GLOBAL(global_null));
	}


	ZEPHIR_INIT_VAR(displayValues);
	ZVAL_NULL(displayValues);
	ZEPHIR_OBS_VAR(value);
	if (!(zephir_array_isset_fetch(&value, displayValues, name TSRMLS_CC))) {
		ZEPHIR_OBS_NVAR(value);
		zephir_get_global(&_POST, SS("_POST") TSRMLS_CC);
		if (!(zephir_array_isset_fetch(&value, _POST, name TSRMLS_CC))) {
			RETURN_MM_NULL();
		}
	}
	if ((Z_TYPE_P(value) == IS_STRING)) {
		if (0) {
			ZEPHIR_INIT_VAR(escaper);
			zephir_call_self(escaper, this_ptr, "getescaperservice");
			zephir_call_method_p1(return_value, escaper, "escapehtmlattr", value);
			RETURN_MM();
		}
		if ((Z_TYPE_P(params) == IS_ARRAY)) {
			ZEPHIR_OBS_VAR(autoescape);
			if (zephir_array_isset_string_fetch(&autoescape, params, SS("escape") TSRMLS_CC)) {
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

	HashTable *_2;
	HashPosition _1;
	zval *key = NULL, *value = NULL, *_0, *_POST, **_3;

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(_0);
	array_init(_0);
	zephir_get_global(&_POST, SS("_POST") TSRMLS_CC);
	zephir_is_iterable(_POST, &_2, &_1, 0, 0);
	for (
		; zend_hash_get_current_data_ex(_2, (void**) &_3, &_1) == SUCCESS
		; zend_hash_move_forward_ex(_2, &_1)
	) {
		ZEPHIR_GET_HMKEY(key, _2, _1);
		ZEPHIR_GET_HVALUE(value, _3);
		zephir_array_unset(&_POST, key, PH_SEPARATE TSRMLS_CC);
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * Builds a HTML A tag using framework conventions
 *
 *<code>
 *	echo Phalcon\Tag::linkTo('signup/register', 'Register Here!');
 *	echo Phalcon\Tag::linkTo(array('signup/register', 'Register Here!'));
 *	echo Phalcon\Tag::linkTo(array('signup/register', 'Register Here!', 'class' => 'btn-primary'));
 *</code>
 *
 * @param	array|string parameters
 * @param   string text
 * @return	string
 */
PHP_METHOD(Phalcon_Tag, linkTo) {

	HashTable *_3;
	HashPosition _2;
	zval *parameters, *text = NULL, *key = NULL, *value = NULL, *params = NULL, *action = NULL, *url, *code = NULL, *_0, *_1, **_4, *_5 = NULL, *_6 = NULL, *_7 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &parameters, &text);

	if (!text) {
		ZEPHIR_CPY_WRT(text, ZEPHIR_GLOBAL(global_null));
	}
	ZEPHIR_SEPARATE_PARAM(text);


	if ((Z_TYPE_P(parameters) != IS_ARRAY)) {
		ZEPHIR_INIT_VAR(params);
		zephir_call_func_p2(params, "array", parameters, text);
	} else {
		ZEPHIR_CPY_WRT(params, parameters);
	}
	ZEPHIR_OBS_VAR(action);
	if (!(zephir_array_isset_long_fetch(&action, params, 0 TSRMLS_CC))) {
		ZEPHIR_OBS_NVAR(action);
		if (!(zephir_array_isset_string_fetch(&action, params, SS("action") TSRMLS_CC))) {
			ZEPHIR_INIT_BNVAR(action);
			ZVAL_STRING(action, "", 1);
		} else {
			zephir_array_unset_string(&params, SS("action"), PH_SEPARATE);
		}
	}
	ZEPHIR_OBS_NVAR(text);
	if (!(zephir_array_isset_long_fetch(&text, params, 1 TSRMLS_CC))) {
		ZEPHIR_OBS_NVAR(text);
		if (!(zephir_array_isset_string_fetch(&text, params, SS("text") TSRMLS_CC))) {
			ZEPHIR_INIT_BNVAR(text);
			ZVAL_STRING(text, "", 1);
		} else {
			zephir_array_unset_string(&params, SS("text"), PH_SEPARATE);
		}
	}
	ZEPHIR_INIT_VAR(url);
	zephir_call_self(url, this_ptr, "geturlservice");
	ZEPHIR_INIT_VAR(_0);
	zephir_call_method_p1(_0, url, "get", action);
	ZEPHIR_INIT_VAR(_1);
	ZEPHIR_CONCAT_SV(_1, "<a href=\"", _0);
	ZEPHIR_INIT_VAR(code);
	ZEPHIR_CONCAT_VS(code, _1, "\"");
	zephir_is_iterable(params, &_3, &_2, 0, 0);
	for (
		; zend_hash_get_current_data_ex(_3, (void**) &_4, &_2) == SUCCESS
		; zend_hash_move_forward_ex(_3, &_2)
	) {
		ZEPHIR_GET_HMKEY(key, _3, _2);
		ZEPHIR_GET_HVALUE(value, _4);
		if ((Z_TYPE_P(key) != IS_LONG)) {
			ZEPHIR_INIT_LNVAR(_5);
			ZEPHIR_CONCAT_SV(_5, " ", key);
			ZEPHIR_INIT_LNVAR(_6);
			ZEPHIR_CONCAT_VS(_6, _5, "=\"");
			ZEPHIR_INIT_LNVAR(_7);
			concat_function(_7, _6, value TSRMLS_CC);
			ZEPHIR_INIT_NVAR(code);
			ZEPHIR_CONCAT_VS(code, _7, "\"");
			zephir_concat_self(&code, code TSRMLS_CC);
		}
	}
	ZEPHIR_INIT_LNVAR(_5);
	ZEPHIR_CONCAT_SV(_5, ">", text);
	ZEPHIR_INIT_BNVAR(code);
	ZEPHIR_CONCAT_VS(code, _5, "</a>");
	zephir_concat_self(&code, code TSRMLS_CC);
	RETURN_CCTOR(code);

}

