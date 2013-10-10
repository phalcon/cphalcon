
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
#include "kernel/object.h"
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

	zval *dependencyInjector, *_0;

	zephir_fetch_params(0, 1, 0, &dependencyInjector);



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
			ZEPHIR_THROW_EXCEPTION_STR(phalcon_tag_exception_ce, "A dependency injector container is required to obtain the 'url' service");
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
			ZEPHIR_THROW_EXCEPTION_STR(phalcon_tag_exception_ce, "A dependency injector container is required to obtain the 'escaper' service");
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


	ZEPHIR_INIT_ZVAL_NREF(_1);
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

	zval *id_param = NULL, *value, *_0;
	zval *id = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &id_param, &value);

		zephir_get_strval(id, id_param);


	if ((Z_TYPE_P(value) != IS_NULL)) {
		if (((Z_TYPE_P(value) == IS_ARRAY) || (Z_TYPE_P(value) == IS_OBJECT))) {
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
		ZEPHIR_CPY_WRT(params, ZEPHIR_GLOBAL(global_null));
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
			if (zephir_array_isset_string_fetch(&autoescape, params, SS("escape"), 1 TSRMLS_CC)) {
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
	zval *key = NULL, *value = NULL, *_0, *_1, *_POST, **_4;

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(_1);
	array_init(_1);
	zephir_update_static_property_ce(phalcon_tag_ce, SL("_displayValues"), _1 TSRMLS_CC);
	zephir_get_global(&_POST, SS("_POST") TSRMLS_CC);
	zephir_is_iterable(_POST, &_3, &_2, 0, 0);
	for (
		; zend_hash_get_current_data_ex(_3, (void**) &_4, &_2) == SUCCESS
		; zend_hash_move_forward_ex(_3, &_2)
	) {
		ZEPHIR_GET_HMKEY(key, _3, _2);
		ZEPHIR_GET_HVALUE(value, _4);
		zephir_array_unset(&_POST, key, PH_SEPARATE);
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

	HashTable *_2;
	HashPosition _1;
	zval *parameters, *text = NULL, *key = NULL, *value = NULL, *params = NULL, *action = NULL, *url, *code, *_0, **_3, *_4 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &parameters, &text);

	if (!text) {
		ZEPHIR_CPY_WRT(text, ZEPHIR_GLOBAL(global_null));
	}
	ZEPHIR_SEPARATE_PARAM(text);


	if ((Z_TYPE_P(parameters) != IS_ARRAY)) {
		ZEPHIR_INIT_VAR(params);
		array_init(params);
		zephir_array_fast_append(params, parameters);
		zephir_array_fast_append(params, text);
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
			zephir_array_unset_string(&params, SS("action"), PH_SEPARATE);
		}
	}
	ZEPHIR_OBS_NVAR(text);
	if (!(zephir_array_isset_long_fetch(&text, params, 1, 0 TSRMLS_CC))) {
		ZEPHIR_OBS_NVAR(text);
		if (!(zephir_array_isset_string_fetch(&text, params, SS("text"), 0 TSRMLS_CC))) {
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
	ZEPHIR_INIT_VAR(code);
	ZEPHIR_CONCAT_SVS(code, "<a href=\"", _0, "\"");
	zephir_is_iterable(params, &_2, &_1, 0, 0);
	for (
		; zend_hash_get_current_data_ex(_2, (void**) &_3, &_1) == SUCCESS
		; zend_hash_move_forward_ex(_2, &_1)
	) {
		ZEPHIR_GET_HMKEY(key, _2, _1);
		ZEPHIR_GET_HVALUE(value, _3);
		if ((Z_TYPE_P(key) != IS_LONG)) {
			ZEPHIR_INIT_LNVAR(_4);
			ZEPHIR_CONCAT_SVSVS(_4, " ", key, "=\"", value, "\"");
			zephir_concat_self(&code, _4 TSRMLS_CC);
		}
	}
	ZEPHIR_INIT_LNVAR(_4);
	ZEPHIR_CONCAT_SVS(_4, ">", text, "</a>");
	zephir_concat_self(&code, _4 TSRMLS_CC);
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

	zend_bool asValue;
	zval *type_param = NULL, *parameters, *asValue_param = NULL;
	zval *type = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 1, &type_param, &parameters, &asValue_param);

		zephir_get_strval(type, type_param);
	if (!asValue_param) {
		asValue = 0;
	} else {
		asValue = zephir_get_boolval(asValue_param);
	}



}

/**
 * Builds INPUT tags that implements the checked attribute
 *
 * @param   string type
 * @param	array parameters
 * @return	string
 */
PHP_METHOD(Phalcon_Tag, _inputFieldChecked) {

	zval *type_param = NULL, *parameters;
	zval *type = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &type_param, &parameters);

		zephir_get_strval(type, type_param);



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
 * {{ radio_field('Save') }}
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
 * {{ image_input('src': '/img/button.png') }}
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
 * {{ submit_button('Save') }}
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
		ZEPHIR_CPY_WRT(data, ZEPHIR_GLOBAL(global_null));
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
 *		Robots::find("type = 'mechanical'"),
 *		"using" => array("id", "name")
 * 	));
 *</code>
 *
 * Volt syntax:
 *<code>
 * {{ select("robotId", robots, "using": ["id", "name"]) }}
 *</code>
 *
 * @param	array $parameters
 * @param   array $data
 * @return	string
 */
PHP_METHOD(Phalcon_Tag, select) {

	zval *parameters, *data = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &parameters, &data);

	if (!data) {
		ZEPHIR_CPY_WRT(data, ZEPHIR_GLOBAL(global_null));
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
 * @param	array $parameters
 * @return	string
 */
PHP_METHOD(Phalcon_Tag, textArea) {

	zval *parameters;

	zephir_fetch_params(0, 1, 0, &parameters);




}

