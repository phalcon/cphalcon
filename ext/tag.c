
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

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"
#include "php_phalcon.h"
#include "phalcon.h"

#include "Zend/zend_operators.h"
#include "Zend/zend_exceptions.h"
#include "Zend/zend_interfaces.h"

#include "kernel/main.h"
#include "kernel/memory.h"

#include "kernel/exception.h"
#include "kernel/object.h"
#include "kernel/fcall.h"
#include "kernel/array.h"
#include "kernel/hash.h"
#include "kernel/concat.h"
#include "kernel/operators.h"
#include "kernel/string.h"

/**
 * Phalcon\Tag
 *
 * Phalcon\Tag is designed to simplify building of HTML tags.
 * It provides a set of helpers to generate HTML in a dynamic way.
 * This component is an abstract class that you can extend to add more helpers.
 */


/**
 * Phalcon\Tag initializer
 */
PHALCON_INIT_CLASS(Phalcon_Tag){

	PHALCON_REGISTER_CLASS(Phalcon, Tag, tag, phalcon_tag_method_entry, 0);

	zend_declare_property_null(phalcon_tag_ce, SL("_displayValues"), ZEND_ACC_PROTECTED|ZEND_ACC_STATIC TSRMLS_CC);
	zend_declare_property_null(phalcon_tag_ce, SL("_documentTitle"), ZEND_ACC_PROTECTED|ZEND_ACC_STATIC TSRMLS_CC);
	zend_declare_property_long(phalcon_tag_ce, SL("_documentType"), 11, ZEND_ACC_PROTECTED|ZEND_ACC_STATIC TSRMLS_CC);
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
 * @param Phalcon\DiInterface $dependencyInjector
 */
PHP_METHOD(Phalcon_Tag, setDI){

	zval *dependency_injector;

	phalcon_fetch_params(0, 1, 0, &dependency_injector);

	if (Z_TYPE_P(dependency_injector) != IS_OBJECT) {
		PHALCON_THROW_EXCEPTION_STRW(phalcon_tag_exception_ce, "Parameter dependencyInjector must be an Object");
		return;
	}
	phalcon_update_static_property(SL("phalcon\\tag"), SL("_dependencyInjector"), dependency_injector TSRMLS_CC);

}

/**
 * Internally gets the request dispatcher
 *
 * @return Phalcon\DiInterface
 */
PHP_METHOD(Phalcon_Tag, getDI){

	zval *dependency_injector;

	PHALCON_MM_GROW();

	PHALCON_OBS_VAR(dependency_injector);
	phalcon_read_static_property(&dependency_injector, SL("phalcon\\tag"), SL("_dependencyInjector") TSRMLS_CC);
	RETURN_CCTOR(dependency_injector);
}

/**
 * Return a URL service from the default DI
 *
 * @return Phalcon\Mvc\UrlInterface
 */
PHP_METHOD(Phalcon_Tag, getUrlService){

	zval *url = NULL, *dependency_injector = NULL, *service;

	PHALCON_MM_GROW();

	PHALCON_OBS_VAR(url);
	phalcon_read_static_property(&url, SL("phalcon\\tag"), SL("_urlService") TSRMLS_CC);
	if (Z_TYPE_P(url) != IS_OBJECT) {

		PHALCON_OBS_VAR(dependency_injector);
		phalcon_read_static_property(&dependency_injector, SL("phalcon\\tag"), SL("_dependencyInjector") TSRMLS_CC);
		if (Z_TYPE_P(dependency_injector) != IS_OBJECT) {
			PHALCON_INIT_NVAR(dependency_injector);
			PHALCON_CALL_STATIC(dependency_injector, "phalcon\\di", "getdefault");
		}

		if (Z_TYPE_P(dependency_injector) != IS_OBJECT) {
			PHALCON_THROW_EXCEPTION_STR(phalcon_tag_exception_ce, "A dependency injector container is required to obtain the \"url\" service");
			return;
		}

		PHALCON_INIT_VAR(service);
		ZVAL_STRING(service, "url", 1);

		PHALCON_INIT_NVAR(url);
		phalcon_call_method_p1(url, dependency_injector, "getshared", service);
		PHALCON_VERIFY_INTERFACE(url, phalcon_mvc_urlinterface_ce);
		phalcon_update_static_property(SL("phalcon\\tag"), SL("_urlService"), url TSRMLS_CC);
	}

	RETURN_CCTOR(url);
}

/**
 * Returns an Escaper service from the default DI
 *
 * @return Phalcon\EscaperInterface
 */
PHP_METHOD(Phalcon_Tag, getEscaperService){

	zval *escaper = NULL, *dependency_injector = NULL, *service;

	PHALCON_MM_GROW();

	PHALCON_OBS_VAR(escaper);
	phalcon_read_static_property(&escaper, SL("phalcon\\tag"), SL("_escaperService") TSRMLS_CC);
	if (Z_TYPE_P(escaper) != IS_OBJECT) {

		PHALCON_OBS_VAR(dependency_injector);
		phalcon_read_static_property(&dependency_injector, SL("phalcon\\tag"), SL("_dependencyInjector") TSRMLS_CC);
		if (Z_TYPE_P(dependency_injector) != IS_OBJECT) {
			PHALCON_INIT_NVAR(dependency_injector);
			PHALCON_CALL_STATIC(dependency_injector, "phalcon\\di", "getdefault");
		}

		if (Z_TYPE_P(dependency_injector) != IS_OBJECT) {
			PHALCON_THROW_EXCEPTION_STR(phalcon_tag_exception_ce, "A dependency injector container is required to obtain the \"escaper\" service");
			return;
		}

		PHALCON_INIT_VAR(service);
		ZVAL_STRING(service, "escaper", 1);

		PHALCON_INIT_NVAR(escaper);
		phalcon_call_method_p1(escaper, dependency_injector, "getshared", service);
		PHALCON_VERIFY_INTERFACE(escaper, phalcon_escaperinterface_ce);
		phalcon_update_static_property(SL("phalcon\\tag"), SL("_escaperService"), escaper TSRMLS_CC);
	}

	RETURN_CCTOR(escaper);
}

/**
 * Set autoescape mode in generated html
 *
 * @param boolean $autoescape
 */
PHP_METHOD(Phalcon_Tag, setAutoescape){

	zval *autoescape;

	phalcon_fetch_params(0, 1, 0, &autoescape);

	phalcon_update_static_property(SL("phalcon\\tag"), SL("_autoEscape"), autoescape TSRMLS_CC);

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
 * @param string $id
 * @param string $value
 */
PHP_METHOD(Phalcon_Tag, setDefault){

	zval *id, *value;
	zval *t0 = NULL;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 2, 0, &id, &value);

	if (Z_TYPE_P(value) != IS_NULL) {
		if (Z_TYPE_P(value) == IS_ARRAY || Z_TYPE_P(value) == IS_OBJECT) {
			PHALCON_THROW_EXCEPTION_STR(phalcon_tag_exception_ce, "Only scalar values can be assigned to UI components");
			return;
		}
	}
	PHALCON_OBSERVE_VAR(t0);
	phalcon_read_static_property(&t0, SL("phalcon\\tag"), SL("_displayValues") TSRMLS_CC);
	if (Z_TYPE_P(t0) != IS_ARRAY) {
		convert_to_array(t0);
	}
	phalcon_array_update_zval(&t0, id, &value, PH_COPY);
	phalcon_update_static_property(SL("phalcon\\tag"), SL("_displayValues"), t0 TSRMLS_CC);


	PHALCON_MM_RESTORE();
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
 * @param array $values
 */
PHP_METHOD(Phalcon_Tag, setDefaults){

	zval *values;

	phalcon_fetch_params(0, 1, 0, &values);

	if (Z_TYPE_P(values) != IS_ARRAY) {
		PHALCON_THROW_EXCEPTION_STRW(phalcon_tag_exception_ce, "An array is required as default values");
		return;
	}
	phalcon_update_static_property(SL("phalcon\\tag"), SL("_displayValues"), values TSRMLS_CC);

}

/**
 * Alias of Phalcon\Tag::setDefault
 *
 * @param string $id
 * @param string $value
 */
PHALCON_DOC_METHOD(Phalcon_Tag, displayTo)

/**
 * Check if a helper has a default value set using Phalcon\Tag::setDefault or value from $_POST
 *
 * @param string $name
 * @return boolean
 */
PHP_METHOD(Phalcon_Tag, hasValue){

	zval *name, *display_values, *_POST;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 0, &name);

	PHALCON_OBS_VAR(display_values);
	phalcon_read_static_property(&display_values, SL("phalcon\\tag"), SL("_displayValues") TSRMLS_CC);

	/**
	 * Check if there is a predefined value for it
	 */
	if (phalcon_array_isset(display_values, name)) {
		RETURN_MM_TRUE;
	} else {
		/**
		 * Check if there is a post value for the item
		 */
		phalcon_get_global(&_POST, SS("_POST") TSRMLS_CC);
		if (phalcon_array_isset(_POST, name)) {
			RETURN_MM_TRUE;
		}
	}

	RETURN_MM_FALSE;
}

/**
 * Every helper calls this function to check whether a component has a predefined
 * value using Phalcon\Tag::setDefault or value from $_POST
 *
 * @param string $name
 * @param array $params
 * @return mixed
 */
PHP_METHOD(Phalcon_Tag, getValue){

	zval *name, *params = NULL, *display_values, *value = NULL, *_POST;
	zval *autoescape = NULL, *escaper = NULL;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 1, &name, &params);

	if (!params) {
		PHALCON_INIT_VAR(params);
	}

	PHALCON_OBS_VAR(display_values);
	phalcon_read_static_property(&display_values, SL("phalcon\\tag"), SL("_displayValues") TSRMLS_CC);

	/**
	 * Check if there is a predefined value for it
	 */
	if (phalcon_array_isset(display_values, name)) {
		PHALCON_OBS_VAR(value);
		phalcon_array_fetch(&value, display_values, name, PH_NOISY);
	} else {
		/**
		 * Check if there is a post value for the item
		 */
		phalcon_get_global(&_POST, SS("_POST") TSRMLS_CC);
		if (phalcon_array_isset(_POST, name)) {
			PHALCON_OBS_NVAR(value);
			phalcon_array_fetch(&value, _POST, name, PH_NOISY);
		} else {
			RETURN_MM_NULL();
		}
	}

	PHALCON_OBS_VAR(autoescape);
	phalcon_read_static_property(&autoescape, SL("phalcon\\tag"), SL("_autoEscape") TSRMLS_CC);

	/**
	 * Escape all values in autoescape mode. Only escaping values
	 */
	if (Z_TYPE_P(value) == IS_STRING) {
		if (zend_is_true(autoescape)) {
			PHALCON_INIT_VAR(escaper);
			PHALCON_CALL_SELF(escaper, this_ptr, "getescaperservice");
			phalcon_call_method_p1(return_value, escaper, "escapehtmlattr", value);
			RETURN_MM();
		} else {
			if (Z_TYPE_P(params) == IS_ARRAY) {

				/**
				 * A escape parameter is set?
				 */
				if (phalcon_array_isset_string(params, SS("escape"))) {

					PHALCON_OBS_NVAR(autoescape);
					phalcon_array_fetch_string(&autoescape, params, SL("escape"), PH_NOISY);
					if (zend_is_true(autoescape)) {
						PHALCON_INIT_NVAR(escaper);
						PHALCON_CALL_SELF(escaper, this_ptr, "getescaperservice");
						phalcon_call_method_p1(return_value, escaper, "escapehtmlattr", value);
						RETURN_MM();
					}
				}
			}
		}
	}

	RETURN_CCTOR(value);
}

/**
 * Resets the request and internal values to avoid those fields will have any default value
 */
PHP_METHOD(Phalcon_Tag, resetInput){

	zval *empty_array = NULL;

	PHALCON_MM_GROW();

	PHALCON_INIT_VAR(empty_array);
	array_init(empty_array);

	phalcon_update_static_property(SL("phalcon\\tag"), SL("_displayValues"), empty_array TSRMLS_CC);

	phalcon_set_symbol_str(SS("_POST"), empty_array TSRMLS_CC);

	PHALCON_MM_RESTORE();
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
 * @param array|string $parameters
 * @param   string $text
 * @return string
 */
PHP_METHOD(Phalcon_Tag, linkTo){

	zval *parameters, *text = NULL, *params = NULL, *action = NULL, *url, *internal_url;
	zval *code, *value = NULL, *key = NULL, *escaped;
	HashTable *ah0;
	HashPosition hp0;
	zval **hd;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 1, &parameters, &text);

	if (!text) {
		PHALCON_INIT_VAR(text);
	} else {
		PHALCON_SEPARATE_PARAM(text);
	}

	if (Z_TYPE_P(parameters) != IS_ARRAY) {
		PHALCON_INIT_VAR(params);
		array_init_size(params, 2);
		phalcon_array_append(&params, parameters, 0);
		phalcon_array_append(&params, text, 0);
	} else {
		PHALCON_CPY_WRT(params, parameters);
	}

	PHALCON_INIT_VAR(action);
	ZVAL_EMPTY_STRING(action);
	if (phalcon_array_isset_long(params, 0)) {
		PHALCON_OBS_NVAR(action);
		phalcon_array_fetch_long(&action, params, 0, PH_NOISY);
	} else {
		if (phalcon_array_isset_string(params, SS("action"))) {
			PHALCON_OBS_NVAR(action);
			phalcon_array_fetch_string(&action, params, SL("action"), PH_NOISY);
			phalcon_array_unset_string(&params, SS("action"), PH_SEPARATE);
		}
	}

	PHALCON_INIT_NVAR(text);
	ZVAL_EMPTY_STRING(text);
	if (phalcon_array_isset_long(params, 1)) {
		PHALCON_OBS_NVAR(text);
		phalcon_array_fetch_long(&text, params, 1, PH_NOISY);
	} else {
		if (phalcon_array_isset_string(params, SS("text"))) {
			PHALCON_OBS_NVAR(text);
			phalcon_array_fetch_string(&text, params, SL("text"), PH_NOISY);
			phalcon_array_unset_string(&params, SS("text"), PH_SEPARATE);
		}
	}

	PHALCON_INIT_VAR(url);
	PHALCON_CALL_SELF(url, this_ptr, "geturlservice");

	PHALCON_INIT_VAR(internal_url);
	phalcon_call_method_p1(internal_url, url, "get", action);

	PHALCON_INIT_VAR(escaped);

	PHALCON_INIT_VAR(code);
	phalcon_htmlspecialchars(escaped, internal_url, NULL, NULL TSRMLS_CC);
	PHALCON_CONCAT_SVS(code, "<a href=\"", escaped, "\"");
	zval_dtor(escaped);
	ZVAL_NULL(escaped);

	phalcon_is_iterable(params, &ah0, &hp0, 0, 0);

	while (zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) == SUCCESS) {

		PHALCON_GET_HKEY(key, ah0, hp0);
		PHALCON_GET_HVALUE(value);

		if (Z_TYPE_P(key) != IS_LONG) {
			phalcon_htmlspecialchars(escaped, value, NULL, NULL TSRMLS_CC);
			PHALCON_SCONCAT_SVSVS(code, " ", key, "=\"", escaped, "\"");
			zval_dtor(escaped);
			ZVAL_NULL(escaped);
		}

		zend_hash_move_forward_ex(ah0, &hp0);
	}

	PHALCON_SCONCAT_SVS(code, ">", text, "</a>");

	RETURN_CTOR(code);
}

/**
 * Builds generic INPUT tags
 *
 * @param   string $type
 * @param array $parameters
 * @param 	boolean $asValue
 * @return string
 */
PHP_METHOD(Phalcon_Tag, _inputField){

	zval *type, *parameters, *as_value = NULL, *params = NULL, *value = NULL;
	zval *id = NULL, *name, *code, *key = NULL, *doctype, *escaped;
	HashTable *ah0;
	HashPosition hp0;
	zval **hd;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 2, 1, &type, &parameters, &as_value);

	if (!as_value) {
		PHALCON_INIT_VAR(as_value);
		ZVAL_FALSE(as_value);
	}

	if (Z_TYPE_P(parameters) != IS_ARRAY) {
		PHALCON_INIT_VAR(params);
		array_init_size(params, 1);
		phalcon_array_append(&params, parameters, 0);
	} else {
		PHALCON_CPY_WRT(params, parameters);
	}

	PHALCON_INIT_VAR(value);
	if (PHALCON_IS_FALSE(as_value)) {
		if (!phalcon_array_isset_long(params, 0)) {
			PHALCON_OBS_VAR(id);
			phalcon_array_fetch_string(&id, params, SL("id"), PH_NOISY);
			phalcon_array_update_long(&params, 0, &id, PH_COPY | PH_SEPARATE);
		}

		PHALCON_OBS_NVAR(id);
		phalcon_array_fetch_long(&id, params, 0, PH_NOISY);
		if (!phalcon_array_isset_string(params, SS("name"))) {
			phalcon_array_update_string(&params, SL("name"), &id, PH_COPY | PH_SEPARATE);
		} else {
			PHALCON_OBS_VAR(name);
			phalcon_array_fetch_string(&name, params, SL("name"), PH_NOISY);
			if (!zend_is_true(name)) {
				phalcon_array_update_string(&params, SL("name"), &id, PH_COPY | PH_SEPARATE);
			}
		}

		/**
		 * Automatically assign the id if the name is not an array
		 */
		if (!phalcon_memnstr_str(id, SL("["))) {
			if (!phalcon_array_isset_string(params, SS("id"))) {
				phalcon_array_update_string(&params, SL("id"), &id, PH_COPY | PH_SEPARATE);
			}
		}

		/**
		 * Use the parameter 'value' if the developer had set it
		 */
		if (!phalcon_array_isset_string(params, SS("value"))) {
			PHALCON_CALL_SELF_PARAMS_2(value, this_ptr, "getvalue", id, params);
			phalcon_array_update_string(&params, SL("value"), &value, PH_COPY | PH_SEPARATE);
		}
	} else {
		/**
		 * Use the 'id' as value if the user hadn't set it
		 */
		if (!phalcon_array_isset_string(params, SS("value"))) {
			if (phalcon_array_isset_long(params, 0)) {
				PHALCON_OBS_NVAR(value);
				phalcon_array_fetch_long(&value, params, 0, PH_NOISY);
				phalcon_array_update_string(&params, SL("value"), &value, PH_COPY | PH_SEPARATE);
			}
		}
	}

	PHALCON_INIT_VAR(escaped);
	phalcon_htmlspecialchars(escaped, type, NULL, NULL TSRMLS_CC);

	PHALCON_INIT_VAR(code);
	PHALCON_CONCAT_SVS(code, "<input type=\"", escaped, "\"");

	zval_dtor(escaped);
	ZVAL_NULL(escaped);

	phalcon_is_iterable(params, &ah0, &hp0, 0, 0);

	while (zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) == SUCCESS) {

		PHALCON_GET_HKEY(key, ah0, hp0);
		PHALCON_GET_HVALUE(value);

		if (Z_TYPE_P(key) != IS_LONG) {
			phalcon_htmlspecialchars(escaped, value, NULL, NULL TSRMLS_CC);
			PHALCON_SCONCAT_SVSVS(code, " ", key, "=\"", escaped, "\"");
			zval_dtor(escaped);
			ZVAL_NULL(escaped);
		}

		zend_hash_move_forward_ex(ah0, &hp0);
	}

	PHALCON_OBS_VAR(doctype);
	phalcon_read_static_property(&doctype, SL("phalcon\\tag"), SL("_documentType") TSRMLS_CC);

	/**
	 * Check if Doctype is XHTML
	 */
	if (PHALCON_GT_LONG(doctype, 5)) {
		phalcon_concat_self_str(&code, SL(" />") TSRMLS_CC);
	} else {
		phalcon_concat_self_str(&code, SL(">") TSRMLS_CC);
	}

	RETURN_CTOR(code);
}

/**
 * Builds INPUT tags that implements the checked attribute
 *
 * @param   string $type
 * @param array $parameters
 * @return string
 */
PHP_METHOD(Phalcon_Tag, _inputFieldChecked){

	zval *type, *parameters, *params = NULL, *value = NULL, *id = NULL, *name;
	zval *current_value, *code, *key = NULL, *doctype, *escaped;
	HashTable *ah0;
	HashPosition hp0;
	zval **hd;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 2, 0, &type, &parameters);

	if (Z_TYPE_P(parameters) != IS_ARRAY) {
		PHALCON_INIT_VAR(params);
		array_init_size(params, 1);
		phalcon_array_append(&params, parameters, PH_SEPARATE);
	} else {
		PHALCON_CPY_WRT(params, parameters);
	}

	PHALCON_INIT_VAR(value);
	if (!phalcon_array_isset_long(params, 0)) {
		PHALCON_OBS_VAR(id);
		phalcon_array_fetch_string(&id, params, SL("id"), PH_NOISY);
		phalcon_array_update_long(&params, 0, &id, PH_COPY | PH_SEPARATE);
	}

	PHALCON_OBS_NVAR(id);
	phalcon_array_fetch_long(&id, params, 0, PH_NOISY);
	if (!phalcon_array_isset_string(params, SS("name"))) {
		phalcon_array_update_string(&params, SL("name"), &id, PH_COPY | PH_SEPARATE);
	} else {
		PHALCON_OBS_VAR(name);
		phalcon_array_fetch_string(&name, params, SL("name"), PH_NOISY);
		if (!zend_is_true(name)) {
			phalcon_array_update_string(&params, SL("name"), &id, PH_COPY | PH_SEPARATE);
		}
	}

	/**
	 * Automatically assign the id if the name is not an array
	 */
	if (!phalcon_memnstr_str(id, SL("["))) {
		if (!phalcon_array_isset_string(params, SS("id"))) {
			phalcon_array_update_string(&params, SL("id"), &id, PH_COPY | PH_SEPARATE);
		}
	}

	PHALCON_CALL_SELF_PARAMS_2(value, this_ptr, "getvalue", id, params);

	/**
	 * Automatically check inputs
	 */
	if (phalcon_array_isset_string(params, SS("value"))) {

		PHALCON_OBS_VAR(current_value);
		phalcon_array_fetch_string(&current_value, params, SL("value"), PH_NOISY);
		if (Z_TYPE_P(value) != IS_NULL) {
			if (PHALCON_IS_EQUAL(current_value, value)) {
				phalcon_array_update_string_string(&params, SL("checked"), SL("checked"), PH_SEPARATE);
			}
		}
	} else {
		/**
		 * Evaluate the value in POST
		 */
		if (zend_is_true(value)) {
			phalcon_array_update_string_string(&params, SL("checked"), SL("checked"), PH_SEPARATE);
		}

		/**
		 * Update the value anyways
		 */
		phalcon_array_update_string(&params, SL("value"), &value, PH_COPY | PH_SEPARATE);
	}

	PHALCON_INIT_VAR(escaped);
	phalcon_htmlspecialchars(escaped, type, NULL, NULL TSRMLS_CC);

	PHALCON_INIT_VAR(code);
	PHALCON_CONCAT_SVS(code, "<input type=\"", escaped, "\"");

	zval_dtor(escaped);
	ZVAL_NULL(escaped);

	phalcon_is_iterable(params, &ah0, &hp0, 0, 0);

	while (zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) == SUCCESS) {

		PHALCON_GET_HKEY(key, ah0, hp0);
		PHALCON_GET_HVALUE(value);

		if (Z_TYPE_P(key) != IS_LONG) {
			phalcon_htmlspecialchars(escaped, value, NULL, NULL TSRMLS_CC);
			PHALCON_SCONCAT_SVSVS(code, " ", key, "=\"", escaped, "\"");
			zval_dtor(escaped);
			ZVAL_NULL(escaped);
		}

		zend_hash_move_forward_ex(ah0, &hp0);
	}

	PHALCON_OBS_VAR(doctype);
	phalcon_read_static_property(&doctype, SL("phalcon\\tag"), SL("_documentType") TSRMLS_CC);

	/**
	 * Check if Doctype is XHTML
	 */
	if (PHALCON_GT_LONG(doctype, 5)) {
		phalcon_concat_self_str(&code, SL(" />") TSRMLS_CC);
	} else {
		phalcon_concat_self_str(&code, SL(">") TSRMLS_CC);
	}

	RETURN_CTOR(code);
}

/**
 * Builds a HTML input[type="text"] tag
 *
 * <code>
 *	echo Phalcon\Tag::textField(array("name", "size" => 30));
 * </code>
 *
 * @param array $parameters
 * @return string
 */
PHP_METHOD(Phalcon_Tag, textField){

	zval *parameters, *name;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 0, &parameters);

	PHALCON_INIT_VAR(name);
	ZVAL_STRING(name, "text", 1);
	PHALCON_CALL_SELF_PARAMS_2(return_value, this_ptr, "_inputfield", name, parameters);
	RETURN_MM();
}

/**
 * Builds a HTML input[type="number"] tag
 *
 * <code>
 *	echo Phalcon\Tag::numericField(array("price", "min" => "1", "max" => "5"));
 * </code>
 *
 * @param array $parameters
 * @return string
 */
PHP_METHOD(Phalcon_Tag, numericField){

	zval *parameters, *name;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 0, &parameters);

	PHALCON_INIT_VAR(name);
	ZVAL_STRING(name, "number", 1);
	PHALCON_CALL_SELF_PARAMS_2(return_value, this_ptr, "_inputfield", name, parameters);
	RETURN_MM();
}

/**
 * Builds a HTML input[type="email"] tag
 *
 * <code>
 *	echo Phalcon\Tag::emailField("email");
 * </code>
 *
 * @param array $parameters
 * @return string
 */
PHP_METHOD(Phalcon_Tag, emailField){

	zval *parameters, *name;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 0, &parameters);

	PHALCON_INIT_VAR(name);
	ZVAL_STRING(name, "email", 1);
	PHALCON_CALL_SELF_PARAMS_2(return_value, this_ptr, "_inputfield", name, parameters);
	RETURN_MM();
}

/**
 * Builds a HTML input[type="date"] tag
 *
 * <code>
 *	echo Phalcon\Tag::dateField(array("born", "value" => "14-12-1980"))
 * </code>
 *
 * @param array $parameters
 * @return string
 */
PHP_METHOD(Phalcon_Tag, dateField){

	zval *parameters, *name;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 0, &parameters);

	PHALCON_INIT_VAR(name);
	ZVAL_STRING(name, "date", 1);
	PHALCON_CALL_SELF_PARAMS_2(return_value, this_ptr, "_inputfield", name, parameters);
	RETURN_MM();
}

/**
 * Builds a HTML input[type="password"] tag
 *
 *<code>
 * echo Phalcon\Tag::passwordField(array("name", "size" => 30));
 *</code>
 *
 * @param array $parameters
 * @return string
 */
PHP_METHOD(Phalcon_Tag, passwordField){

	zval *parameters, *name;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 0, &parameters);

	PHALCON_INIT_VAR(name);
	ZVAL_STRING(name, "password", 1);
	PHALCON_CALL_SELF_PARAMS_2(return_value, this_ptr, "_inputfield", name, parameters);
	RETURN_MM();
}

/**
 * Builds a HTML input[type="hidden"] tag
 *
 *<code>
 * echo Phalcon\Tag::hiddenField(array("name", "value" => "mike"));
 *</code>
 *
 * @param array $parameters
 * @return string
 */
PHP_METHOD(Phalcon_Tag, hiddenField){

	zval *parameters, *name;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 0, &parameters);

	PHALCON_INIT_VAR(name);
	ZVAL_STRING(name, "hidden", 1);
	PHALCON_CALL_SELF_PARAMS_2(return_value, this_ptr, "_inputfield", name, parameters);
	RETURN_MM();
}

/**
 * Builds a HTML input[type="file"] tag
 *
 *<code>
 * echo Phalcon\Tag::fileField("file");
 *</code>
 *
 * @param array $parameters
 * @return string
 */
PHP_METHOD(Phalcon_Tag, fileField){

	zval *parameters, *name;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 0, &parameters);

	PHALCON_INIT_VAR(name);
	ZVAL_STRING(name, "file", 1);
	PHALCON_CALL_SELF_PARAMS_2(return_value, this_ptr, "_inputfield", name, parameters);
	RETURN_MM();
}

/**
 * Builds a HTML input[type="check"] tag
 *
 *<code>
 * echo Phalcon\Tag::checkField(array("terms", "value" => "Y"));
 *</code>
 *
 * @param array $parameters
 * @return string
 */
PHP_METHOD(Phalcon_Tag, checkField){

	zval *parameters, *name;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 0, &parameters);

	PHALCON_INIT_VAR(name);
	ZVAL_STRING(name, "checkbox", 1);
	PHALCON_CALL_SELF_PARAMS_2(return_value, this_ptr, "_inputfieldchecked", name, parameters);
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
 * @param array $parameters
 * @return string
 */
PHP_METHOD(Phalcon_Tag, radioField){

	zval *parameters, *name;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 0, &parameters);

	PHALCON_INIT_VAR(name);
	ZVAL_STRING(name, "radio", 1);
	PHALCON_CALL_SELF_PARAMS_2(return_value, this_ptr, "_inputfieldchecked", name, parameters);
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
 * @param array $parameters
 * @return string
 */
PHP_METHOD(Phalcon_Tag, imageInput){

	zval *parameters, *name, *as_value;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 0, &parameters);

	PHALCON_INIT_VAR(name);
	ZVAL_STRING(name, "image", 1);

	PHALCON_INIT_VAR(as_value);
	ZVAL_BOOL(as_value, 1);
	PHALCON_CALL_SELF_PARAMS_3(return_value, this_ptr, "_inputfield", name, parameters, as_value);
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
 * @param array $parameters
 * @return string
 */
PHP_METHOD(Phalcon_Tag, submitButton){

	zval *parameters, *name, *as_value;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 0, &parameters);

	PHALCON_INIT_VAR(name);
	ZVAL_STRING(name, "submit", 1);

	PHALCON_INIT_VAR(as_value);
	ZVAL_BOOL(as_value, 1);
	PHALCON_CALL_SELF_PARAMS_3(return_value, this_ptr, "_inputfield", name, parameters, as_value);
	RETURN_MM();
}

/**
 * Builds a HTML SELECT tag using a PHP array for options
 *
 *<code>
 *	echo Phalcon\Tag::selectStatic("status", array("A" => "Active", "I" => "Inactive"))
 *</code>
 *
 * @param array $parameters
 * @param   array $data
 * @return string
 */
PHP_METHOD(Phalcon_Tag, selectStatic){

	zval *parameters, *data = NULL;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 1, &parameters, &data);

	if (!data) {
		PHALCON_INIT_VAR(data);
	}

	PHALCON_CALL_STATIC_PARAMS_2(return_value, "phalcon\\tag\\select", "selectfield", parameters, data);
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
 * @param array $parameters
 * @param   array $data
 * @return string
 */
PHP_METHOD(Phalcon_Tag, select){

	zval *parameters, *data = NULL;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 1, &parameters, &data);

	if (!data) {
		PHALCON_INIT_VAR(data);
	}

	PHALCON_CALL_STATIC_PARAMS_2(return_value, "phalcon\\tag\\select", "selectfield", parameters, data);
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
 * @param array $parameters
 * @return string
 */
PHP_METHOD(Phalcon_Tag, textArea){

	zval *parameters, *params = NULL, *id = NULL, *name, *content = NULL, *code;
	zval *avalue = NULL, *key = NULL, *escaped;
	HashTable *ah0;
	HashPosition hp0;
	zval **hd;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 0, &parameters);

	if (Z_TYPE_P(parameters) != IS_ARRAY) {
		PHALCON_INIT_VAR(params);
		array_init_size(params, 1);
		phalcon_array_append(&params, parameters, PH_SEPARATE);
	} else {
		PHALCON_CPY_WRT(params, parameters);
	}
	if (!phalcon_array_isset_long(params, 0)) {
		if (phalcon_array_isset_string(params, SS("id"))) {
			PHALCON_OBS_VAR(id);
			phalcon_array_fetch_string(&id, params, SL("id"), PH_NOISY);
			phalcon_array_update_long(&params, 0, &id, PH_COPY | PH_SEPARATE);
		}
	}

	PHALCON_OBS_NVAR(id);
	phalcon_array_fetch_long(&id, params, 0, PH_NOISY);
	if (!phalcon_array_isset_string(params, SS("name"))) {
		phalcon_array_update_string(&params, SL("name"), &id, PH_COPY | PH_SEPARATE);
	} else {
		PHALCON_OBS_VAR(name);
		phalcon_array_fetch_string(&name, params, SL("name"), PH_NOISY);
		if (!zend_is_true(name)) {
			phalcon_array_update_string(&params, SL("name"), &id, PH_COPY | PH_SEPARATE);
		}
	}

	if (!phalcon_array_isset_string(params, SS("id"))) {
		phalcon_array_update_string(&params, SL("id"), &id, PH_COPY | PH_SEPARATE);
	}

	PHALCON_INIT_NVAR(content);
	PHALCON_CALL_SELF_PARAMS_2(content, this_ptr, "getvalue", id, params);

	PHALCON_INIT_VAR(code);
	ZVAL_STRING(code, "<textarea", 1);

	phalcon_is_iterable(params, &ah0, &hp0, 0, 0);

	PHALCON_INIT_VAR(escaped);

	while (zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) == SUCCESS) {

		PHALCON_GET_HKEY(key, ah0, hp0);
		PHALCON_GET_HVALUE(avalue);

		if (Z_TYPE_P(key) != IS_LONG) {
			phalcon_htmlspecialchars(escaped, avalue, NULL, NULL TSRMLS_CC);
			PHALCON_SCONCAT_SVSVS(code, " ", key, "=\"", escaped, "\"");
			zval_dtor(escaped);
			ZVAL_NULL(escaped);
		}

		zend_hash_move_forward_ex(ah0, &hp0);
	}

	PHALCON_SCONCAT_SVS(code, ">", content, "</textarea>");

	RETURN_CTOR(code);
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
 * @param array $parameters
 * @return string
 */
PHP_METHOD(Phalcon_Tag, form){

	zval *parameters = NULL, *params = NULL, *params_action = NULL, *action = NULL;
	zval *url, *code, *avalue = NULL, *key = NULL, *escaped;
	HashTable *ah0;
	HashPosition hp0;
	zval **hd;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 0, 1, &parameters);

	if (!parameters) {
		PHALCON_INIT_VAR(parameters);
	} else {
		PHALCON_SEPARATE_PARAM(parameters);
	}

	if (Z_TYPE_P(parameters) != IS_ARRAY) {
		PHALCON_INIT_VAR(params);
		array_init_size(params, 1);
		phalcon_array_append(&params, parameters, PH_SEPARATE);
	} else {
		PHALCON_CPY_WRT(params, parameters);
	}
	if (phalcon_array_isset_long(params, 0)) {
		PHALCON_OBS_VAR(params_action);
		phalcon_array_fetch_long(&params_action, params, 0, PH_NOISY);
	} else {
		if (phalcon_array_isset_string(params, SS("action"))) {
			PHALCON_OBS_NVAR(params_action);
			phalcon_array_fetch_string(&params_action, params, SL("action"), PH_NOISY);
		} else {
			PHALCON_INIT_NVAR(params_action);
		}
	}

	/**
	 * By default the method is POST
	 */
	if (!phalcon_array_isset_string(params, SS("method"))) {
		phalcon_array_update_string_string(&params, SL("method"), SL("post"), PH_SEPARATE);
	}

	PHALCON_INIT_VAR(action);

	if (Z_TYPE_P(params_action) != IS_NULL) {
		PHALCON_INIT_VAR(url);
		PHALCON_CALL_SELF(url, this_ptr, "geturlservice");

		phalcon_call_method_p1(action, url, "get", params_action);
	}

	/**
	 * Check for extra parameters
	 */
	if (phalcon_array_isset_string(params, SS("parameters"))) {
		PHALCON_OBS_NVAR(parameters);
		phalcon_array_fetch_string(&parameters, params, SL("parameters"), PH_NOISY);
		PHALCON_SCONCAT_SV(action, "?", parameters);
	}

	if (Z_TYPE_P(action) != IS_NULL) {
		phalcon_array_update_string(&params, SL("action"), &action, PH_COPY | PH_SEPARATE);
	}

	PHALCON_INIT_VAR(code);
	ZVAL_STRING(code, "<form", 1);

	phalcon_is_iterable(params, &ah0, &hp0, 0, 0);

	PHALCON_INIT_VAR(escaped);

	while (zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) == SUCCESS) {

		PHALCON_GET_HKEY(key, ah0, hp0);
		PHALCON_GET_HVALUE(avalue);

		if (Z_TYPE_P(key) != IS_LONG) {
			phalcon_htmlspecialchars(escaped, avalue, NULL, NULL TSRMLS_CC);
			PHALCON_SCONCAT_SVSVS(code, " ", key, "=\"", escaped, "\"");
			zval_dtor(escaped);
			ZVAL_NULL(escaped);
		}

		zend_hash_move_forward_ex(ah0, &hp0);
	}

	phalcon_concat_self_str(&code, SL(">") TSRMLS_CC);

	RETURN_CTOR(code);
}

/**
 * Builds a HTML close FORM tag
 *
 * @return string
 */
PHP_METHOD(Phalcon_Tag, endForm){


	RETURN_STRING("</form>", 1);
}

/**
 * Set the title of view content
 *
 *<code>
 * Phalcon\Tag::setTitle('Welcome to my Page');
 *</code>
 *
 * @param string $title
 */
PHP_METHOD(Phalcon_Tag, setTitle){

	zval *title;

	phalcon_fetch_params(0, 1, 0, &title);

	phalcon_update_static_property(SL("phalcon\\tag"), SL("_documentTitle"), title TSRMLS_CC);

}

/**
 * Appends a text to current document title
 *
 * @param string $title
 */
PHP_METHOD(Phalcon_Tag, appendTitle){

	zval *title;
	zval *t0 = NULL;
	zval *r0 = NULL;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 0, &title);

	PHALCON_OBS_VAR(t0);
	phalcon_read_static_property(&t0, SL("phalcon\\tag"), SL("_documentTitle") TSRMLS_CC);
	PHALCON_ALLOC_ZVAL_MM(r0);
	concat_function(r0, t0, title TSRMLS_CC);
	phalcon_update_static_property(SL("phalcon\\tag"), SL("_documentTitle"), r0 TSRMLS_CC);

	PHALCON_MM_RESTORE();
}

/**
 * Prepends a text to current document title
 *
 * @param string $title
 */
PHP_METHOD(Phalcon_Tag, prependTitle){

	zval *title, *document_title;
	zval *r0 = NULL;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 0, &title);

	PHALCON_OBS_VAR(document_title);
	phalcon_read_static_property(&document_title, SL("phalcon\\tag"), SL("_documentTitle") TSRMLS_CC);

	PHALCON_INIT_VAR(r0);
	PHALCON_CONCAT_VV(r0, title, document_title);
	phalcon_update_static_property(SL("phalcon\\tag"), SL("_documentTitle"), r0 TSRMLS_CC);

	PHALCON_MM_RESTORE();
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
PHP_METHOD(Phalcon_Tag, getTitle){

	zval *tags = NULL, *document_title;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 0, 1, &tags);

	if (!tags) {
		PHALCON_INIT_VAR(tags);
		ZVAL_BOOL(tags, 1);
	}

	PHALCON_OBS_VAR(document_title);
	phalcon_read_static_property(&document_title, SL("phalcon\\tag"), SL("_documentTitle") TSRMLS_CC);
	if (PHALCON_IS_TRUE(tags)) {
		PHALCON_CONCAT_SVS(return_value, "<title>", document_title, "</title>" PHP_EOL);
		RETURN_MM();
	}

	RETURN_CCTOR(document_title);
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
 * @param array $parameters
 * @param   boolean $local
 * @return string
 */
PHP_METHOD(Phalcon_Tag, stylesheetLink){

	zval *parameters = NULL, *local = NULL, *params = NULL, *first_param;
	zval *url, *url_href, *href, *code, *value = NULL, *key = NULL, *doctype;
	zval *escaped;
	HashTable *ah0;
	HashPosition hp0;
	zval **hd;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 0, 2, &parameters, &local);

	if (!parameters) {
		PHALCON_INIT_VAR(parameters);
	}

	if (!local) {
		PHALCON_INIT_VAR(local);
		ZVAL_BOOL(local, 1);
	} else {
		PHALCON_SEPARATE_PARAM(local);
	}

	if (Z_TYPE_P(parameters) != IS_ARRAY) {
		PHALCON_INIT_VAR(params);
		array_init_size(params, 2);
		phalcon_array_append(&params, parameters, 0);
		phalcon_array_append(&params, local, 0);
	} else {
		PHALCON_CPY_WRT(params, parameters);
	}
	if (!phalcon_array_isset_string(params, SS("href"))) {
		if (phalcon_array_isset_long(params, 0)) {
			PHALCON_OBS_VAR(first_param);
			phalcon_array_fetch_long(&first_param, params, 0, PH_NOISY);
			phalcon_array_update_string(&params, SL("href"), &first_param, PH_COPY | PH_SEPARATE);
		} else {
			phalcon_array_update_string_string(&params, SL("href"), SL(""), PH_SEPARATE);
		}
	}

	PHALCON_INIT_NVAR(local);
	ZVAL_BOOL(local, 0);
	if (phalcon_array_isset_long(params, 1)) {
		PHALCON_OBS_NVAR(local);
		phalcon_array_fetch_long(&local, params, 1, PH_NOISY);
	} else {
		if (phalcon_array_isset_string(params, SS("local"))) {
			PHALCON_OBS_NVAR(local);
			phalcon_array_fetch_string(&local, params, SL("local"), PH_NOISY);
			phalcon_array_unset_string(&params, SS("local"), PH_SEPARATE);
		}
	}

	if (!phalcon_array_isset_string(params, SS("type"))) {
		phalcon_array_update_string_string(&params, SL("type"), SL("text/css"), PH_SEPARATE);
	}

	/**
	 * URLs are generated through the 'url' service
	 */
	if (zend_is_true(local)) {
		PHALCON_INIT_VAR(url);
		PHALCON_CALL_SELF(url, this_ptr, "geturlservice");

		PHALCON_OBS_VAR(url_href);
		phalcon_array_fetch_string(&url_href, params, SL("href"), PH_NOISY);

		PHALCON_INIT_VAR(href);
		phalcon_call_method_p1(href, url, "getstatic", url_href);
		phalcon_array_update_string(&params, SL("href"), &href, PH_COPY | PH_SEPARATE);
	}

	PHALCON_INIT_VAR(code);
	ZVAL_STRING(code, "<link rel=\"stylesheet\"", 1);

	PHALCON_INIT_VAR(escaped);

	phalcon_is_iterable(params, &ah0, &hp0, 0, 0);

	while (zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) == SUCCESS) {

		PHALCON_GET_HKEY(key, ah0, hp0);
		PHALCON_GET_HVALUE(value);

		if (Z_TYPE_P(key) != IS_LONG) {
			phalcon_htmlspecialchars(escaped, value, NULL, NULL TSRMLS_CC);
			PHALCON_SCONCAT_SVSVS(code, " ", key, "=\"", escaped, "\"");
			zval_dtor(escaped);
			ZVAL_NULL(escaped);
		}

		zend_hash_move_forward_ex(ah0, &hp0);
	}

	PHALCON_OBS_VAR(doctype);
	phalcon_read_static_property(&doctype, SL("phalcon\\tag"), SL("_documentType") TSRMLS_CC);

	/**
	 * Check if Doctype is XHTML
	 */
	if (PHALCON_GT_LONG(doctype, 5)) {
		phalcon_concat_self_str(&code, SL(" />" PHP_EOL) TSRMLS_CC);
	} else {
		phalcon_concat_self_str(&code, SL(">" PHP_EOL) TSRMLS_CC);
	}

	RETURN_CTOR(code);
}

/**
 * Builds a SCRIPT[type="javascript"] tag
 *
 * <code>
 * 	echo Phalcon\Tag::javascriptInclude("http://ajax.googleapis.com/ajax/libs/jquery/1.7.1/jquery.min.js", false);
 * 	echo Phalcon\Tag::javascriptInclude("javascript/jquery.js");
 * </code>
 *
 * Volt syntax:
 * <code>
 * {{ javascript_include("http://ajax.googleapis.com/ajax/libs/jquery/1.7.1/jquery.min.js", false) }}
 * {{ javascript_include("javascript/jquery.js") }}
 * </code>
 *
 * @param array $parameters
 * @param   boolean $local
 * @return string
 */
PHP_METHOD(Phalcon_Tag, javascriptInclude){

	zval *parameters = NULL, *local = NULL, *params = NULL, *first_param;
	zval *url, *params_src, *src, *code, *value = NULL, *key = NULL, *escaped;
	HashTable *ah0;
	HashPosition hp0;
	zval **hd;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 0, 2, &parameters, &local);

	if (!parameters) {
		PHALCON_INIT_VAR(parameters);
	}

	if (!local) {
		PHALCON_INIT_VAR(local);
		ZVAL_BOOL(local, 1);
	} else {
		PHALCON_SEPARATE_PARAM(local);
	}

	if (Z_TYPE_P(parameters) != IS_ARRAY) {
		PHALCON_INIT_VAR(params);
		array_init_size(params, 2);
		phalcon_array_append(&params, parameters, 0);
		phalcon_array_append(&params, local, 0);
	} else {
		PHALCON_CPY_WRT(params, parameters);
	}
	if (!phalcon_array_isset_string(params, SS("src"))) {
		if (phalcon_array_isset_long(params, 0)) {
			PHALCON_OBS_VAR(first_param);
			phalcon_array_fetch_long(&first_param, params, 0, PH_NOISY);
			phalcon_array_update_string(&params, SL("src"), &first_param, PH_COPY | PH_SEPARATE);
		} else {
			phalcon_array_update_string_string(&params, SL("src"), SL(""), PH_SEPARATE);
		}
	}

	PHALCON_INIT_NVAR(local);
	ZVAL_BOOL(local, 0);
	if (phalcon_array_isset_long(params, 1)) {
		PHALCON_OBS_NVAR(local);
		phalcon_array_fetch_long(&local, params, 1, PH_NOISY);
	} else {
		if (phalcon_array_isset_string(params, SS("local"))) {
			PHALCON_OBS_NVAR(local);
			phalcon_array_fetch_string(&local, params, SL("local"), PH_NOISY);
			phalcon_array_unset_string(&params, SS("local"), PH_SEPARATE);
		}
	}

	if (!phalcon_array_isset_string(params, SS("type"))) {
		phalcon_array_update_string_string(&params, SL("type"), SL("text/javascript"), PH_SEPARATE);
	}

	/**
	 * URLs are generated through the 'url' service
	 */
	if (zend_is_true(local)) {
		PHALCON_INIT_VAR(url);
		PHALCON_CALL_SELF(url, this_ptr, "geturlservice");

		PHALCON_OBS_VAR(params_src);
		phalcon_array_fetch_string(&params_src, params, SL("src"), PH_NOISY);

		PHALCON_INIT_VAR(src);
		phalcon_call_method_p1(src, url, "getstatic", params_src);
		phalcon_array_update_string(&params, SL("src"), &src, PH_COPY | PH_SEPARATE);
	}

	PHALCON_INIT_VAR(code);
	ZVAL_STRING(code, "<script", 1);

	phalcon_is_iterable(params, &ah0, &hp0, 0, 0);

	PHALCON_INIT_VAR(escaped);

	while (zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) == SUCCESS) {

		PHALCON_GET_HKEY(key, ah0, hp0);
		PHALCON_GET_HVALUE(value);

		if (Z_TYPE_P(key) != IS_LONG) {
			phalcon_htmlspecialchars(escaped, value, NULL, NULL TSRMLS_CC);
			PHALCON_SCONCAT_SVSVS(code, " ", key, "=\"", escaped, "\"");
			zval_dtor(escaped);
			ZVAL_NULL(escaped);
		}

		zend_hash_move_forward_ex(ah0, &hp0);
	}

	PHALCON_CONCAT_VS(return_value, code, "></script>" PHP_EOL);
	PHALCON_MM_RESTORE();
}

/**
 * Builds HTML IMG tags
 *
 * <code>
 * 	echo Phalcon\Tag::image("img/bg.png");
 * 	echo Phalcon\Tag::image(array("img/photo.jpg", "alt" => "Some Photo"));
 * </code>
 *
 * Volt Syntax:
 * <code>
 * 	{{ image("img/bg.png") }}
 * 	{{ image("img/photo.jpg", "alt": "Some Photo") }}
 * 	{{ image("http://static.mywebsite.com/img/bg.png", false) }}
 * </code>
 *
 * @param  array $parameters
 * @param  boolean $local
 * @return string
 */
PHP_METHOD(Phalcon_Tag, image){

	zval *parameters = NULL, *local = NULL, *params = NULL, *first_param;
	zval *url, *url_src, *src, *code, *value = NULL, *key = NULL, *doctype, *escaped;
	HashTable *ah0;
	HashPosition hp0;
	zval **hd;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 0, 2, &parameters, &local);

	if (!parameters) {
		PHALCON_INIT_VAR(parameters);
	}

	if (!local) {
		PHALCON_INIT_VAR(local);
		ZVAL_BOOL(local, 1);
	}

	if (Z_TYPE_P(parameters) != IS_ARRAY) {
		PHALCON_INIT_VAR(params);
		array_init_size(params, 1);
		phalcon_array_append(&params, parameters, 0);
	} else {
		PHALCON_CPY_WRT(params, parameters);
	}
	if (!phalcon_array_isset_string(params, SS("src"))) {
		if (phalcon_array_isset_long(params, 0)) {
			PHALCON_OBS_VAR(first_param);
			phalcon_array_fetch_long(&first_param, params, 0, PH_NOISY);
			phalcon_array_update_string(&params, SL("src"), &first_param, PH_COPY | PH_SEPARATE);
		} else {
			phalcon_array_update_string_string(&params, SL("src"), SL(""), PH_SEPARATE);
		}
	}

	/**
	 * Use the 'url' service if the URI is local
	 */
	if (zend_is_true(local)) {
		PHALCON_INIT_VAR(url);
		PHALCON_CALL_SELF(url, this_ptr, "geturlservice");

		PHALCON_OBS_VAR(url_src);
		phalcon_array_fetch_string(&url_src, params, SL("src"), PH_NOISY);

		PHALCON_INIT_VAR(src);
		phalcon_call_method_p1(src, url, "getstatic", url_src);
		phalcon_array_update_string(&params, SL("src"), &src, PH_COPY | PH_SEPARATE);
	}

	PHALCON_INIT_VAR(code);
	ZVAL_STRING(code, "<img", 1);

	phalcon_is_iterable(params, &ah0, &hp0, 0, 0);

	PHALCON_INIT_VAR(escaped);

	while (zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) == SUCCESS) {

		PHALCON_GET_HKEY(key, ah0, hp0);
		PHALCON_GET_HVALUE(value);

		if (Z_TYPE_P(key) != IS_LONG) {
			phalcon_htmlspecialchars(escaped, value, NULL, NULL TSRMLS_CC);
			PHALCON_SCONCAT_SVSVS(code, " ", key, "=\"", escaped, "\"");
			zval_dtor(escaped);
			ZVAL_NULL(escaped);
		}

		zend_hash_move_forward_ex(ah0, &hp0);
	}

	PHALCON_OBS_VAR(doctype);
	phalcon_read_static_property(&doctype, SL("phalcon\\tag"), SL("_documentType") TSRMLS_CC);

	/**
	 * Check if Doctype is XHTML
	 */
	if (PHALCON_GT_LONG(doctype, 5)) {
		phalcon_concat_self_str(&code, SL(" />") TSRMLS_CC);
	} else {
		phalcon_concat_self_str(&code, SL(">") TSRMLS_CC);
	}

	RETURN_CTOR(code);
}

/**
 * Converts texts into URL-friendly titles
 *
 *<code>
 * echo Phalcon\Tag::friendlyTitle('These are big important news', '-')
 *</code>
 *
 * @param string $text
 * @param string $separator
 * @param boolean $lowercase
 * @return text
 */
PHP_METHOD(Phalcon_Tag, friendlyTitle){

	zval *text, *separator = NULL, *lowercase = NULL, *pattern, *friendly;
	zval *friendly_text = NULL;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 2, &text, &separator, &lowercase);

	if (!separator) {
		PHALCON_INIT_VAR(separator);
		ZVAL_STRING(separator, "-", 1);
	}

	if (!lowercase) {
		PHALCON_INIT_VAR(lowercase);
		ZVAL_BOOL(lowercase, 1);
	}

	PHALCON_INIT_VAR(pattern);
	ZVAL_STRING(pattern, "~[^a-z0-9A-Z]+~", 1);

	PHALCON_INIT_VAR(friendly);
	phalcon_call_func_p3(friendly, "preg_replace", pattern, separator, text);
	if (zend_is_true(lowercase)) {
		PHALCON_INIT_VAR(friendly_text);
		phalcon_fast_strtolower(friendly_text, friendly);
	} else {
		PHALCON_CPY_WRT(friendly_text, friendly);
	}

	RETURN_CCTOR(friendly_text);
}

/**
 * Set the document type of content
 *
 * @param string $doctype
 */
PHP_METHOD(Phalcon_Tag, setDocType){

	zval *doctype;

	phalcon_fetch_params(0, 1, 0, &doctype);

	phalcon_update_static_property(SL("phalcon\\tag"), SL("_documentType"), doctype TSRMLS_CC);

}

/**
 * Get the document type declaration of content
 *
 * @return string
 */
PHP_METHOD(Phalcon_Tag, getDocType){

	zval *doctype;

	PHALCON_MM_GROW();

	PHALCON_OBS_VAR(doctype);
	phalcon_read_static_property(&doctype, SL("phalcon\\tag"), SL("_documentType") TSRMLS_CC);

	if (phalcon_compare_strict_long(doctype, 1 TSRMLS_CC)) {
		RETVAL_STRING("<!DOCTYPE html PUBLIC \"-//W3C//DTD HTML 3.2 Final//EN\">" PHP_EOL, 1);
	}
	else if (phalcon_compare_strict_long(doctype, 2 TSRMLS_CC)) {
		RETVAL_STRING("<!DOCTYPE html PUBLIC \"-//W3C//DTD HTML 4.01//EN\"" PHP_EOL "\t\"http://www.w3.org/TR/html4/strict.dtd\">" PHP_EOL, 1);
	}
	else if (phalcon_compare_strict_long(doctype, 3 TSRMLS_CC)) {
		RETVAL_STRING("<!DOCTYPE html PUBLIC \"-//W3C//DTD HTML 4.01 Transitional//EN\"" PHP_EOL "\t\"http://www.w3.org/TR/html4/loose.dtd\">" PHP_EOL, 1);
	}
	else if (phalcon_compare_strict_long(doctype, 4 TSRMLS_CC)) {
		RETVAL_STRING("<!DOCTYPE html PUBLIC \"-//W3C//DTD HTML 4.01 Frameset//EN\"" PHP_EOL"\t\"http://www.w3.org/TR/html4/frameset.dtd\">" PHP_EOL, 1);
	}
	else if (phalcon_compare_strict_long(doctype, 6 TSRMLS_CC)) {
		RETVAL_STRING("<!DOCTYPE html PUBLIC \"-//W3C//DTD XHTML 1.0 Strict//EN\"" PHP_EOL "\t\"http://www.w3.org/TR/xhtml1/DTD/xhtml1-strict.dtd\">" PHP_EOL, 1);
	}
	else if (phalcon_compare_strict_long(doctype, 7 TSRMLS_CC)) {
		RETVAL_STRING("<!DOCTYPE html PUBLIC \"-//W3C//DTD XHTML 1.0 Transitional//EN\"" PHP_EOL "\t\"http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd\">" PHP_EOL, 1);
	}
	else if (phalcon_compare_strict_long(doctype, 8 TSRMLS_CC)) {
		RETVAL_STRING("<!DOCTYPE html PUBLIC \"-//W3C//DTD XHTML 1.0 Frameset//EN\"" PHP_EOL "\t\"http://www.w3.org/TR/xhtml1/DTD/xhtml1-frameset.dtd\">" PHP_EOL, 1);
	}
	else if (phalcon_compare_strict_long(doctype, 9 TSRMLS_CC)) {
		RETVAL_STRING("<!DOCTYPE html PUBLIC \"-//W3C//DTD XHTML 1.1//EN\"" PHP_EOL"\t\"http://www.w3.org/TR/xhtml11/DTD/xhtml11.dtd\">" PHP_EOL, 1);
	}
	else if (phalcon_compare_strict_long(doctype, 10 TSRMLS_CC)) {
		RETVAL_STRING("<!DOCTYPE html PUBLIC \"-//W3C//DTD XHTML 2.0//EN\"" PHP_EOL "\t\"http://www.w3.org/MarkUp/DTD/xhtml2.dtd\">" PHP_EOL, 1);
	}

	PHALCON_MM_RESTORE();
}

/**
 * Builds a HTML tag
 *
 *<code>
 *	echo Phalcon\Tag::tagHtml($name, $parameters, $selfClose, $onlyStart, $eol);
 *</code>
 *
 * @param string $tagName
 * @param array $parameters
 * @param boolean $selfClose
 * @param boolean $onlyStart
 * @param boolean $useEol
 * @return string
 */
PHP_METHOD(Phalcon_Tag, tagHtml){

	zval *tag_name, *parameters = NULL, *self_close = NULL, *only_start = NULL;
	zval *use_eol = NULL, *params = NULL, *local_code, *value = NULL, *key = NULL;
	zval *doctype, *escaped;
	HashTable *ah0;
	HashPosition hp0;
	zval **hd;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 4, &tag_name, &parameters, &self_close, &only_start, &use_eol);

	if (!parameters) {
		PHALCON_INIT_VAR(parameters);
	}

	if (!self_close) {
		PHALCON_INIT_VAR(self_close);
		ZVAL_BOOL(self_close, 0);
	}

	if (!only_start) {
		PHALCON_INIT_VAR(only_start);
		ZVAL_BOOL(only_start, 0);
	}

	if (!use_eol) {
		PHALCON_INIT_VAR(use_eol);
		ZVAL_BOOL(use_eol, 0);
	}

	if (Z_TYPE_P(parameters) != IS_ARRAY) {
		PHALCON_INIT_VAR(params);
		array_init_size(params, 1);
		phalcon_array_append(&params, parameters, 0);
	} else {
		PHALCON_CPY_WRT(params, parameters);
	}

	PHALCON_INIT_VAR(local_code);
	PHALCON_CONCAT_SV(local_code, "<", tag_name);

	phalcon_is_iterable(params, &ah0, &hp0, 0, 0);

	PHALCON_INIT_VAR(escaped);

	while (zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) == SUCCESS) {

		PHALCON_GET_HKEY(key, ah0, hp0);
		PHALCON_GET_HVALUE(value);

		if (Z_TYPE_P(key) != IS_LONG) {
			phalcon_htmlspecialchars(escaped, value, NULL, NULL TSRMLS_CC);
			PHALCON_SCONCAT_SVSVS(local_code, " ", key, "=\"", escaped, "\"");
			zval_dtor(escaped);
			ZVAL_NULL(escaped);
		}

		zend_hash_move_forward_ex(ah0, &hp0);
	}

	PHALCON_OBS_VAR(doctype);
	phalcon_read_static_property(&doctype, SL("phalcon\\tag"), SL("_documentType") TSRMLS_CC);

	/**
	 * Check if Doctype is XHTML
	 */
	if (PHALCON_GT_LONG(doctype, 5)) {
		if (zend_is_true(self_close)) {
			phalcon_concat_self_str(&local_code, SL(" />") TSRMLS_CC);
		} else {
			phalcon_concat_self_str(&local_code, SL(">") TSRMLS_CC);
		}
	} else {
		if (zend_is_true(only_start)) {
			phalcon_concat_self_str(&local_code, SL(">") TSRMLS_CC);
		} else {
			PHALCON_SCONCAT_SVS(local_code, "></", tag_name, ">");
		}
	}

	if (zend_is_true(use_eol)) {
		phalcon_concat_self_str(&local_code, SL(PHP_EOL) TSRMLS_CC);
	}

	RETURN_CTOR(local_code);
}

/**
 * Builds a HTML tag closing tag
 *
 *<code>
 *	echo Phalcon\Tag::tagHtmlClose('script', true)
 *</code>
 *
 * @param string $tagName
 * @param boolean $useEol
 * @return string
 */
PHP_METHOD(Phalcon_Tag, tagHtmlClose){

	zval *tag_name, *use_eol = NULL, *local_code;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 1, &tag_name, &use_eol);

	if (!use_eol) {
		PHALCON_INIT_VAR(use_eol);
		ZVAL_FALSE(use_eol);
	}

	PHALCON_INIT_VAR(local_code);
	PHALCON_CONCAT_SVS(local_code, "</", tag_name, ">");
	if (zend_is_true(use_eol)) {
		phalcon_concat_self_str(&local_code, SL(PHP_EOL) TSRMLS_CC);
	}

	RETURN_CTOR(local_code);
}
