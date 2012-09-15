
/*
  +------------------------------------------------------------------------+
  | Phalcon Framework                                                      |
  +------------------------------------------------------------------------+
  | Copyright (c) 2011-2012 Phalcon Team (http://www.phalconphp.com)       |
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
#include "kernel/concat.h"
#include "kernel/operators.h"

/**
 * Phalcon\Tag
 *
 * Phalcon\Tag is designed to simplify building of HTML tags.
 * It provides a set of helpers to generate HTML in a dynamic way.
 * This component is an abstract class that you can extend to add more helpers.
 */

/**
 * Sets the dependency injector container.
 *
 * @param Phalcon\DI $dispatcher
 */
PHP_METHOD(Phalcon_Tag, setDI){

	zval *dependency_injector = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &dependency_injector) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	if (Z_TYPE_P(dependency_injector) != IS_OBJECT) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_tag_exception_ce, "Parameter dependencyInjector must be an Object");
		return;
	}
	phalcon_update_static_property(SL("phalcon\\tag"), SL("_dependencyInjector"), dependency_injector TSRMLS_CC);
	
	PHALCON_MM_RESTORE();
}

/**
 * Internally gets the request dispatcher
 *
 * @return Phalcon\DI
 */
PHP_METHOD(Phalcon_Tag, getDI){

	zval *dependency_injector = NULL;

	PHALCON_MM_GROW();
	PHALCON_OBSERVE_VAR(dependency_injector);
	phalcon_read_static_property(&dependency_injector, SL("phalcon\\tag"), SL("_dependencyInjector") TSRMLS_CC);
	
	RETURN_CCTOR(dependency_injector);
}

/**
 * Return a URL service from the DI
 *
 * @return Phalcon\Mvc\Url
 */
PHP_METHOD(Phalcon_Tag, getUrlService){

	zval *dependency_injector = NULL, *service = NULL, *url = NULL;

	PHALCON_MM_GROW();
	PHALCON_OBSERVE_VAR(dependency_injector);
	phalcon_read_static_property(&dependency_injector, SL("phalcon\\tag"), SL("_dependencyInjector") TSRMLS_CC);
	if (Z_TYPE_P(dependency_injector) != IS_OBJECT) {
		PHALCON_INIT_VAR(dependency_injector);
		PHALCON_CALL_STATIC(dependency_injector, "phalcon\\di", "getdefault");
	}
	
	if (Z_TYPE_P(dependency_injector) != IS_OBJECT) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_tag_exception_ce, "A dependency injector container is required to obtain the \"url\" service");
		return;
	}
	
	PHALCON_INIT_VAR(service);
	ZVAL_STRING(service, "url", 1);
	
	PHALCON_INIT_VAR(url);
	PHALCON_CALL_METHOD_PARAMS_1(url, dependency_injector, "getshared", service, PH_NO_CHECK);
	
	RETURN_CCTOR(url);
}

/**
 * Returns a Dispatcher service from the DI
 *
 * @return Phalcon\Mvc\Dispatcher
 */
PHP_METHOD(Phalcon_Tag, getDispatcherService){

	zval *dependency_injector = NULL, *service = NULL, *dispatcher = NULL;

	PHALCON_MM_GROW();
	PHALCON_OBSERVE_VAR(dependency_injector);
	phalcon_read_static_property(&dependency_injector, SL("phalcon\\tag"), SL("_dependencyInjector") TSRMLS_CC);
	if (Z_TYPE_P(dependency_injector) != IS_OBJECT) {
		PHALCON_INIT_VAR(dependency_injector);
		PHALCON_CALL_STATIC(dependency_injector, "phalcon\\di", "getdefault");
	}
	
	if (Z_TYPE_P(dependency_injector) != IS_OBJECT) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_tag_exception_ce, "A dependency injector container is required to obtain the \"dispatcher\" service");
		return;
	}
	
	PHALCON_INIT_VAR(service);
	ZVAL_STRING(service, "dispatcher", 1);
	
	PHALCON_INIT_VAR(dispatcher);
	PHALCON_CALL_METHOD_PARAMS_1(dispatcher, dependency_injector, "getshared", service, PH_NO_CHECK);
	
	RETURN_CCTOR(dispatcher);
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

	zval *id = NULL, *value = NULL, *is_scalar = NULL;
	zval *t0 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zz", &id, &value) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	if (zend_is_true(value)) {
		PHALCON_INIT_VAR(is_scalar);
		PHALCON_CALL_FUNC_PARAMS_1(is_scalar, "is_scalar", value);
		if (Z_TYPE_P(is_scalar) == IS_BOOL && !Z_BVAL_P(is_scalar)) {
			PHALCON_THROW_EXCEPTION_STR(phalcon_tag_exception_ce, "Only scalar values can be assigned to UI components");
			return;
		}
	}
	PHALCON_OBSERVE_VAR(t0);
	phalcon_read_static_property(&t0, SL("phalcon\\tag"), SL("_displayValues") TSRMLS_CC);
	if (Z_TYPE_P(t0) != IS_ARRAY) {
		convert_to_array(t0);
	}
	phalcon_array_update_zval(&t0, id, &value, PH_COPY TSRMLS_CC);
	phalcon_update_static_property(SL("phalcon\\tag"), SL("_displayValues"), t0 TSRMLS_CC);
	
	
	PHALCON_MM_RESTORE();
}

/**
 * Alias of Phalcon\Tag::setDefault
 *
 * @param string $id
 * @param string $value
 */
PHP_METHOD(Phalcon_Tag, displayTo){

	zval *id = NULL, *value = NULL, *default_value = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zz", &id, &value) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	PHALCON_INIT_VAR(default_value);
	PHALCON_CALL_SELF_PARAMS_2(default_value, this_ptr, "setdefault", id, value);
	
	RETURN_CCTOR(default_value);
}

/**
 * Every helper calls this function to check whether a component has a predefined
 * value using Phalcon\Tag::setDefault or value from $_POST
 *
 * @param string $name
 * @return mixed
 */
PHP_METHOD(Phalcon_Tag, getValue){

	zval *name = NULL, *display_values = NULL, *default_value = NULL;
	zval *post = NULL, *le_post_name = NULL, *have_magic_quotes = NULL;
	zval *post_name = NULL, *striped = NULL;
	zval *g0 = NULL;
	int eval_int;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &name) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	PHALCON_OBSERVE_VAR(display_values);
	phalcon_read_static_property(&display_values, SL("phalcon\\tag"), SL("_displayValues") TSRMLS_CC);
	eval_int = phalcon_array_isset(display_values, name);
	if (eval_int) {
		PHALCON_INIT_VAR(default_value);
		phalcon_array_fetch(&default_value, display_values, name, PH_NOISY_CC);
		
		RETURN_CCTOR(default_value);
	} else {
		phalcon_get_global(&g0, SL("_POST")+1 TSRMLS_CC);
		PHALCON_CPY_WRT(post, g0);
		eval_int = phalcon_array_isset(post, name);
		if (eval_int) {
			PHALCON_INIT_VAR(le_post_name);
			phalcon_array_fetch(&le_post_name, post, name, PH_NOISY_CC);
			
			PHALCON_INIT_VAR(have_magic_quotes);
			PHALCON_CALL_FUNC(have_magic_quotes, "get_magic_quotes_gpc");
			if (!zend_is_true(have_magic_quotes)) {
				PHALCON_CPY_WRT(post_name, le_post_name);
				
				RETURN_CCTOR(post_name);
			} else {
				PHALCON_INIT_VAR(striped);
				PHALCON_CALL_FUNC_PARAMS_1(striped, "stripslashes", le_post_name);
				
				RETURN_CCTOR(striped);
			}
		}
	}
	
	PHALCON_MM_RESTORE();
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
 *</code>
 *
 * @param array $parameters
 * @return string
 */
PHP_METHOD(Phalcon_Tag, linkTo){

	zval *parameters = NULL, *text = NULL, *params = NULL, *action = NULL, *url = NULL, *internal_url = NULL;
	zval *code = NULL, *value = NULL, *key = NULL, *attribute = NULL;
	zval *r0 = NULL;
	HashTable *ah0;
	HashPosition hp0;
	zval **hd;
	char *hash_index;
	uint hash_index_len;
	ulong hash_num;
	int hash_type;
	int eval_int;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z|z", &parameters, &text) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	if (!text) {
		PHALCON_ALLOC_ZVAL_MM(text);
		ZVAL_NULL(text);
	} else {
		PHALCON_SEPARATE_PARAM(text);
	}
	
	if (Z_TYPE_P(parameters) != IS_ARRAY) { 
		PHALCON_INIT_VAR(params);
		array_init(params);
		phalcon_array_append(&params, parameters, PH_SEPARATE TSRMLS_CC);
		phalcon_array_append(&params, text, PH_SEPARATE TSRMLS_CC);
	} else {
		PHALCON_CPY_WRT(params, parameters);
	}
	
	PHALCON_INIT_VAR(action);
	ZVAL_STRING(action, "", 1);
	eval_int = phalcon_array_isset_long(params, 0);
	if (eval_int) {
		PHALCON_INIT_VAR(action);
		phalcon_array_fetch_long(&action, params, 0, PH_NOISY_CC);
	} else {
		eval_int = phalcon_array_isset_string(params, SL("action")+1);
		if (eval_int) {
			PHALCON_INIT_VAR(action);
			phalcon_array_fetch_string(&action, params, SL("action"), PH_NOISY_CC);
			PHALCON_SEPARATE(params);
			phalcon_array_unset_string(params, SL("action")+1);
		}
	}
	
	PHALCON_INIT_VAR(text);
	ZVAL_STRING(text, "", 1);
	eval_int = phalcon_array_isset_long(params, 1);
	if (eval_int) {
		PHALCON_INIT_VAR(text);
		phalcon_array_fetch_long(&text, params, 1, PH_NOISY_CC);
	} else {
		eval_int = phalcon_array_isset_string(params, SL("text")+1);
		if (eval_int) {
			PHALCON_INIT_VAR(text);
			phalcon_array_fetch_string(&text, params, SL("text"), PH_NOISY_CC);
			PHALCON_SEPARATE(params);
			phalcon_array_unset_string(params, SL("text")+1);
		}
	}
	
	PHALCON_INIT_VAR(url);
	PHALCON_CALL_SELF(url, this_ptr, "geturlservice");
	
	PHALCON_INIT_VAR(internal_url);
	PHALCON_CALL_METHOD_PARAMS_1(internal_url, url, "get", action, PH_NO_CHECK);
	
	PHALCON_INIT_VAR(code);
	PHALCON_CONCAT_SVS(code, "<a href=\"", internal_url, "\"");
	if (!phalcon_valid_foreach(params TSRMLS_CC)) {
		return;
	}
	
	ah0 = Z_ARRVAL_P(params);
	zend_hash_internal_pointer_reset_ex(ah0, &hp0);
	fes_9b93_1:
		if(zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) != SUCCESS){
			goto fee_9b93_1;
		}
		
		PHALCON_INIT_VAR(key);
		PHALCON_GET_FOREACH_KEY(key, ah0, hp0);
		PHALCON_INIT_VAR(value);
		ZVAL_ZVAL(value, *hd, 1, 0);
		if (Z_TYPE_P(key) != IS_LONG) {
			PHALCON_INIT_VAR(attribute);
			PHALCON_CONCAT_SVSVS(attribute, " ", key, "=\"", value, "\"");
			phalcon_concat_self(&code, attribute TSRMLS_CC);
		}
		zend_hash_move_forward_ex(ah0, &hp0);
		goto fes_9b93_1;
	fee_9b93_1:
	
	PHALCON_ALLOC_ZVAL_MM(r0);
	PHALCON_CONCAT_SVS(r0, ">", text, "</a>");
	phalcon_concat_self(&code, r0 TSRMLS_CC);
	
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

	zval *type = NULL, *parameters = NULL, *as_value = NULL, *params = NULL, *id = NULL, *name = NULL;
	zval *value = NULL, *code = NULL, *key = NULL, *attribute = NULL;
	zval *t0 = NULL;
	HashTable *ah0;
	HashPosition hp0;
	zval **hd;
	char *hash_index;
	uint hash_index_len;
	ulong hash_num;
	int hash_type;
	int eval_int;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zz|z", &type, &parameters, &as_value) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	if (!as_value) {
		PHALCON_ALLOC_ZVAL_MM(as_value);
		ZVAL_BOOL(as_value, 0);
	}
	
	if (Z_TYPE_P(parameters) != IS_ARRAY) { 
		PHALCON_INIT_VAR(params);
		array_init(params);
		phalcon_array_append(&params, parameters, PH_SEPARATE TSRMLS_CC);
	} else {
		PHALCON_CPY_WRT(params, parameters);
	}
	if (Z_TYPE_P(as_value) == IS_BOOL && !Z_BVAL_P(as_value)) {
		eval_int = phalcon_array_isset_long(params, 0);
		if (!eval_int) {
			PHALCON_INIT_VAR(id);
			phalcon_array_fetch_string(&id, params, SL("id"), PH_NOISY_CC);
			phalcon_array_update_long(&params, 0, &id, PH_COPY | PH_SEPARATE TSRMLS_CC);
		}
		
		PHALCON_INIT_VAR(id);
		phalcon_array_fetch_long(&id, params, 0, PH_NOISY_CC);
		eval_int = phalcon_array_isset_string(params, SL("name")+1);
		if (!eval_int) {
			phalcon_array_update_string(&params, SL("name"), &id, PH_COPY | PH_SEPARATE TSRMLS_CC);
		} else {
			PHALCON_INIT_VAR(name);
			phalcon_array_fetch_string(&name, params, SL("name"), PH_NOISY_CC);
			if (!zend_is_true(name)) {
				phalcon_array_update_string(&params, SL("name"), &id, PH_COPY | PH_SEPARATE TSRMLS_CC);
			}
		}
		
		eval_int = phalcon_array_isset_string(params, SL("id")+1);
		if (!eval_int) {
			phalcon_array_update_string(&params, SL("id"), &id, PH_COPY | PH_SEPARATE TSRMLS_CC);
		}
		
		eval_int = phalcon_array_isset_string(params, SL("value")+1);
		if (!eval_int) {
			PHALCON_INIT_VAR(value);
			PHALCON_CALL_SELF_PARAMS_1(value, this_ptr, "getvalue", id);
			phalcon_array_update_string(&params, SL("value"), &value, PH_COPY | PH_SEPARATE TSRMLS_CC);
		}
	} else {
		eval_int = phalcon_array_isset_long(params, 0);
		if (eval_int) {
			PHALCON_INIT_VAR(value);
			phalcon_array_fetch_long(&value, params, 0, PH_NOISY_CC);
			phalcon_array_update_string(&params, SL("value"), &value, PH_COPY | PH_SEPARATE TSRMLS_CC);
		}
	}
	
	PHALCON_INIT_VAR(code);
	PHALCON_CONCAT_SVS(code, "<input type=\"", type, "\"");
	if (!phalcon_valid_foreach(params TSRMLS_CC)) {
		return;
	}
	
	ah0 = Z_ARRVAL_P(params);
	zend_hash_internal_pointer_reset_ex(ah0, &hp0);
	fes_9b93_2:
		if(zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) != SUCCESS){
			goto fee_9b93_2;
		}
		
		PHALCON_INIT_VAR(key);
		PHALCON_GET_FOREACH_KEY(key, ah0, hp0);
		PHALCON_INIT_VAR(value);
		ZVAL_ZVAL(value, *hd, 1, 0);
		if (Z_TYPE_P(key) != IS_LONG) {
			PHALCON_INIT_VAR(attribute);
			PHALCON_CONCAT_SVSVS(attribute, " ", key, "=\"", value, "\"");
			phalcon_concat_self(&code, attribute TSRMLS_CC);
		}
		zend_hash_move_forward_ex(ah0, &hp0);
		goto fes_9b93_2;
	fee_9b93_2:
	
	PHALCON_INIT_VAR(t0);
	ZVAL_STRING(t0, " />", 1);
	phalcon_concat_self(&code, t0 TSRMLS_CC);
	
	RETURN_CTOR(code);
}

/**
 * Builds a HTML input[type="text"] tag
 *
 * <code>
 *	echo Phalcon\Tag::textField(array("name", "size" => 30))
 * </code>
 *
 * @param array $parameters
 * @return string
 */
PHP_METHOD(Phalcon_Tag, textField){

	zval *parameters = NULL, *name = NULL, *html = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &parameters) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	PHALCON_INIT_VAR(name);
	ZVAL_STRING(name, "text", 1);
	
	PHALCON_INIT_VAR(html);
	PHALCON_CALL_SELF_PARAMS_2(html, this_ptr, "_inputfield", name, parameters);
	
	RETURN_CCTOR(html);
}

/**
 * Builds a HTML input[type="password"] tag
 *
 *<code>
 * echo Phalcon\Tag::passwordField(array("name", "size" => 30))
 *</code>
 *
 * @param array $parameters
 * @return string
 */
PHP_METHOD(Phalcon_Tag, passwordField){

	zval *parameters = NULL, *name = NULL, *html = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &parameters) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	PHALCON_INIT_VAR(name);
	ZVAL_STRING(name, "password", 1);
	
	PHALCON_INIT_VAR(html);
	PHALCON_CALL_SELF_PARAMS_2(html, this_ptr, "_inputfield", name, parameters);
	
	RETURN_CCTOR(html);
}

/**
 * Builds a HTML input[type="hidden"] tag
 *
 *<code>
 * echo Phalcon\Tag::hiddenField(array("name", "value" => "mike"))
 *</code>
 *
 * @param array $parameters
 * @return string
 */
PHP_METHOD(Phalcon_Tag, hiddenField){

	zval *parameters = NULL, *name = NULL, *html = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &parameters) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	PHALCON_INIT_VAR(name);
	ZVAL_STRING(name, "hidden", 1);
	
	PHALCON_INIT_VAR(html);
	PHALCON_CALL_SELF_PARAMS_2(html, this_ptr, "_inputfield", name, parameters);
	
	RETURN_CCTOR(html);
}

/**
 * Builds a HTML input[type="file"] tag
 *
 *<code>
 * echo Phalcon\Tag::fileField("file")
 *</code>
 *
 * @param array $parameters
 * @return string
 */
PHP_METHOD(Phalcon_Tag, fileField){

	zval *parameters = NULL, *name = NULL, *html = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &parameters) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	PHALCON_INIT_VAR(name);
	ZVAL_STRING(name, "file", 1);
	
	PHALCON_INIT_VAR(html);
	PHALCON_CALL_SELF_PARAMS_2(html, this_ptr, "_inputfield", name, parameters);
	
	RETURN_CCTOR(html);
}

/**
 * Builds a HTML input[type="check"] tag
 *
 *<code>
 * echo Phalcon\Tag::checkField(array("name", "size" => 30))
 *</code>
 *
 * @param array $parameters
 * @return string
 */
PHP_METHOD(Phalcon_Tag, checkField){

	zval *parameters = NULL, *name = NULL, *html = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &parameters) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	PHALCON_INIT_VAR(name);
	ZVAL_STRING(name, "checkbox", 1);
	
	PHALCON_INIT_VAR(html);
	PHALCON_CALL_SELF_PARAMS_2(html, this_ptr, "_inputfield", name, parameters);
	
	RETURN_CCTOR(html);
}

/**
 * Builds a HTML input[type="radio"] tag
 *
 * <code>echo Phalcon\Tag::radioField(array("name", "size" => 30))</code>
 *
 * @param array $parameters
 * @return string
 */
PHP_METHOD(Phalcon_Tag, radioField){

	zval *parameters = NULL, *name = NULL, *html = NULL;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &parameters) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	PHALCON_INIT_VAR(name);
	ZVAL_STRING(name, "radio", 1);

	PHALCON_INIT_VAR(html);
	PHALCON_CALL_SELF_PARAMS_2(html, this_ptr, "_inputfield", name, parameters);

	RETURN_CCTOR(html);
}

/**
 * Builds a HTML input[type="submit"] tag
 *
 *<code>
 * echo Phalcon\Tag::submitButton("Save")
 *</code>
 *
 * @param array $params
 * @return string
 */
PHP_METHOD(Phalcon_Tag, submitButton){

	zval *parameters = NULL, *name = NULL, *as_value = NULL, *html = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &parameters) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	PHALCON_INIT_VAR(name);
	ZVAL_STRING(name, "submit", 1);
	
	PHALCON_INIT_VAR(as_value);
	ZVAL_BOOL(as_value, 1);
	
	PHALCON_INIT_VAR(html);
	PHALCON_CALL_SELF_PARAMS_3(html, this_ptr, "_inputfield", name, parameters, as_value);
	
	RETURN_CCTOR(html);
}

/**
 * Builds a HTML SELECT tag using a PHP array for options
 *
 *<code>
 *	echo Phalcon\Tag::selectStatic("status", array("A" => "Active", "I" => "Inactive"))
 *</code>
 *
 * @param array $parameters
 * @return string
 */
PHP_METHOD(Phalcon_Tag, selectStatic){

	zval *parameters = NULL, *data = NULL, *html = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z|z", &parameters, &data) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	if (!data) {
		PHALCON_ALLOC_ZVAL_MM(data);
		ZVAL_NULL(data);
	}
	
	PHALCON_INIT_VAR(html);
	PHALCON_CALL_STATIC_PARAMS_2(html, "phalcon\\tag\\select", "selectfield", parameters, data);
	
	RETURN_CCTOR(html);
}

/**
 * Builds a HTML SELECT tag using a Phalcon_Model resultset as options
 *
 *<code>
 *	echo Phalcon\Tag::selectStatic(array(
 *		"robotId",
 *		Robots::find("type = 'mechanical'"),
 *		"using" => array("id", "name")
 * 	));
 *</code>
 *
 * @param array $params
 * @return string
 */
PHP_METHOD(Phalcon_Tag, select){

	zval *parameters = NULL, *data = NULL, *html = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z|z", &parameters, &data) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	if (!data) {
		PHALCON_ALLOC_ZVAL_MM(data);
		ZVAL_NULL(data);
	}
	
	PHALCON_INIT_VAR(html);
	PHALCON_CALL_STATIC_PARAMS_2(html, "phalcon\\tag\\select", "selectfield", parameters, data);
	
	RETURN_CCTOR(html);
}

/**
 * Builds a HTML TEXTAREA tag
 *
 *<code>
 * echo Phalcon\Tag::textArea(array("comments", "cols" => 10, "rows" => 4))
 *</code>
 *
 * @param array $parameters
 * @return string
 */
PHP_METHOD(Phalcon_Tag, textArea){

	zval *parameters = NULL, *params = NULL, *id = NULL, *name = NULL, *content = NULL, *code = NULL;
	zval *avalue = NULL, *key = NULL, *attribute = NULL, *end_code = NULL;
	zval *r0 = NULL;
	HashTable *ah0;
	HashPosition hp0;
	zval **hd;
	char *hash_index;
	uint hash_index_len;
	ulong hash_num;
	int hash_type;
	int eval_int;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &parameters) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	if (Z_TYPE_P(parameters) != IS_ARRAY) { 
		PHALCON_INIT_VAR(params);
		array_init(params);
		phalcon_array_append(&params, parameters, PH_SEPARATE TSRMLS_CC);
	} else {
		PHALCON_CPY_WRT(params, parameters);
	}
	eval_int = phalcon_array_isset_long(params, 0);
	if (!eval_int) {
		PHALCON_ALLOC_ZVAL_MM(r0);
		phalcon_array_fetch_string(&r0, params, SL("id"), PH_NOISY_CC);
		phalcon_array_update_long(&params, 0, &r0, PH_COPY | PH_SEPARATE TSRMLS_CC);
	}
	
	PHALCON_INIT_VAR(id);
	phalcon_array_fetch_long(&id, params, 0, PH_NOISY_CC);
	eval_int = phalcon_array_isset_string(params, SL("name")+1);
	if (!eval_int) {
		phalcon_array_update_string(&params, SL("name"), &id, PH_COPY | PH_SEPARATE TSRMLS_CC);
	} else {
		PHALCON_INIT_VAR(name);
		phalcon_array_fetch_string(&name, params, SL("name"), PH_NOISY_CC);
		if (!zend_is_true(name)) {
			phalcon_array_update_string(&params, SL("name"), &id, PH_COPY | PH_SEPARATE TSRMLS_CC);
		}
	}
	
	eval_int = phalcon_array_isset_string(params, SL("id")+1);
	if (!eval_int) {
		phalcon_array_update_string(&params, SL("id"), &id, PH_COPY | PH_SEPARATE TSRMLS_CC);
	}
	
	eval_int = phalcon_array_isset_string(params, SL("value")+1);
	if (eval_int) {
		PHALCON_INIT_VAR(content);
		phalcon_array_fetch_string(&content, params, SL("value"), PH_NOISY_CC);
		PHALCON_SEPARATE(params);
		phalcon_array_unset_string(params, SL("value")+1);
	} else {
		PHALCON_INIT_VAR(content);
		PHALCON_CALL_SELF_PARAMS_1(content, this_ptr, "getvalue", id);
	}
	
	PHALCON_INIT_VAR(code);
	ZVAL_STRING(code, "<textarea ", 1);
	if (!phalcon_valid_foreach(params TSRMLS_CC)) {
		return;
	}
	
	ah0 = Z_ARRVAL_P(params);
	zend_hash_internal_pointer_reset_ex(ah0, &hp0);
	fes_9b93_3:
		if(zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) != SUCCESS){
			goto fee_9b93_3;
		}
		
		PHALCON_INIT_VAR(key);
		PHALCON_GET_FOREACH_KEY(key, ah0, hp0);
		PHALCON_INIT_VAR(avalue);
		ZVAL_ZVAL(avalue, *hd, 1, 0);
		if (Z_TYPE_P(key) != IS_LONG) {
			PHALCON_INIT_VAR(attribute);
			PHALCON_CONCAT_VSVS(attribute, key, "=\"", avalue, "\" ");
			phalcon_concat_self(&code, attribute TSRMLS_CC);
		}
		zend_hash_move_forward_ex(ah0, &hp0);
		goto fes_9b93_3;
	fee_9b93_3:
	
	PHALCON_INIT_VAR(end_code);
	PHALCON_CONCAT_SVS(end_code, ">", content, "</textarea>");
	phalcon_concat_self(&code, end_code TSRMLS_CC);
	
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
 * @param array $parameters
 * @return string
 */
PHP_METHOD(Phalcon_Tag, form){

	zval *parameters = NULL, *params = NULL, *dispatcher = NULL, *dispatch_params = NULL;
	zval *slash = NULL, *action_parameters = NULL, *action = NULL, *controller_name = NULL;
	zval *action_name = NULL, *url = NULL, *form_action = NULL, *query_parameters = NULL;
	zval *code = NULL, *avalue = NULL, *key = NULL, *attribute = NULL, *final_code = NULL;
	zval *r0 = NULL;
	HashTable *ah0;
	HashPosition hp0;
	zval **hd;
	char *hash_index;
	uint hash_index_len;
	ulong hash_num;
	int hash_type;
	int eval_int;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "|z", &parameters) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	if (!parameters) {
		PHALCON_ALLOC_ZVAL_MM(parameters);
		ZVAL_NULL(parameters);
	} else {
		PHALCON_SEPARATE_PARAM(parameters);
	}
	
	if (Z_TYPE_P(parameters) != IS_ARRAY) { 
		PHALCON_INIT_VAR(params);
		array_init(params);
		phalcon_array_append(&params, parameters, PH_SEPARATE TSRMLS_CC);
	} else {
		PHALCON_CPY_WRT(params, parameters);
	}
	
	PHALCON_INIT_VAR(dispatcher);
	PHALCON_CALL_SELF(dispatcher, this_ptr, "getdispatcherservice");
	
	PHALCON_INIT_VAR(dispatch_params);
	PHALCON_CALL_METHOD(dispatch_params, dispatcher, "getparams", PH_NO_CHECK);
	
	PHALCON_INIT_VAR(slash);
	ZVAL_STRING(slash, "/", 1);
	
	PHALCON_INIT_VAR(action_parameters);
	phalcon_fast_join(action_parameters, slash, dispatch_params TSRMLS_CC);
	eval_int = phalcon_array_isset_long(params, 0);
	if (!eval_int) {
		eval_int = phalcon_array_isset_string(params, SL("action")+1);
		if (eval_int) {
			PHALCON_INIT_VAR(action);
			phalcon_array_fetch_string(&action, params, SL("action"), PH_NOISY_CC);
		} else {
			PHALCON_INIT_VAR(controller_name);
			PHALCON_CALL_METHOD(controller_name, dispatcher, "getcontrollername", PH_NO_CHECK);
			
			PHALCON_INIT_VAR(action_name);
			PHALCON_CALL_METHOD(action_name, dispatcher, "getactionname", PH_NO_CHECK);
			
			PHALCON_INIT_VAR(action);
			PHALCON_CONCAT_VSV(action, controller_name, "/", action_name);
		}
	} else {
		PHALCON_INIT_VAR(action);
		phalcon_array_fetch_long(&action, params, 0, PH_NOISY_CC);
	}
	
	eval_int = phalcon_array_isset_string(params, SL("method")+1);
	if (!eval_int) {
		phalcon_array_update_string_string(&params, SL("method"), SL("post"), PH_SEPARATE TSRMLS_CC);
	}
	
	PHALCON_INIT_VAR(url);
	PHALCON_CALL_SELF(url, this_ptr, "geturlservice");
	if (zend_is_true(action_parameters)) {
		PHALCON_ALLOC_ZVAL_MM(r0);
		PHALCON_CALL_METHOD_PARAMS_1(r0, url, "get", action, PH_NO_CHECK);
		PHALCON_CPY_WRT(action, r0);
	} else {
		PHALCON_INIT_VAR(form_action);
		PHALCON_CONCAT_VSV(form_action, action, "/", action_parameters);
		
		PHALCON_INIT_VAR(action);
		PHALCON_CALL_METHOD_PARAMS_1(action, url, "get", form_action, PH_NO_CHECK);
	}
	
	eval_int = phalcon_array_isset_string(params, SL("parameters")+1);
	if (eval_int) {
		PHALCON_INIT_VAR(parameters);
		phalcon_array_fetch_string(&parameters, params, SL("parameters"), PH_NOISY_CC);
		
		PHALCON_INIT_VAR(query_parameters);
		PHALCON_CONCAT_SV(query_parameters, "?", parameters);
		phalcon_concat_self(&action, query_parameters TSRMLS_CC);
	}
	
	PHALCON_INIT_VAR(code);
	PHALCON_CONCAT_SVS(code, "<form action=\"", action, "\"");
	if (!phalcon_valid_foreach(params TSRMLS_CC)) {
		return;
	}
	
	ah0 = Z_ARRVAL_P(params);
	zend_hash_internal_pointer_reset_ex(ah0, &hp0);
	fes_9b93_4:
		if(zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) != SUCCESS){
			goto fee_9b93_4;
		}
		
		PHALCON_INIT_VAR(key);
		PHALCON_GET_FOREACH_KEY(key, ah0, hp0);
		PHALCON_INIT_VAR(avalue);
		ZVAL_ZVAL(avalue, *hd, 1, 0);
		if (Z_TYPE_P(key) != IS_LONG) {
			PHALCON_INIT_VAR(attribute);
			PHALCON_CONCAT_SVSVS(attribute, " ", key, "=\"", avalue, "\"");
			phalcon_concat_self(&code, attribute TSRMLS_CC);
		}
		zend_hash_move_forward_ex(ah0, &hp0);
		goto fes_9b93_4;
	fee_9b93_4:
	
	PHALCON_INIT_VAR(final_code);
	PHALCON_CONCAT_VS(final_code, code, ">");
	
	RETURN_CTOR(final_code);
}

/**
 * Builds a HTML close FORM tag
 *
 * @return string
 */
PHP_METHOD(Phalcon_Tag, endForm){

	zval *end_form = NULL;

	PHALCON_MM_GROW();
	PHALCON_INIT_VAR(end_form);
	ZVAL_STRING(end_form, "</form>", 1);
	
	RETURN_CTOR(end_form);
}

/**
 * Set the title of view content
 *
 * @param string $title
 */
PHP_METHOD(Phalcon_Tag, setTitle){

	zval *title = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &title) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	phalcon_update_static_property(SL("phalcon\\tag"), SL("_documentTitle"), title TSRMLS_CC);
	
	PHALCON_MM_RESTORE();
}

/**
 * Add to title of view content
 *
 * @param string $title
 */
PHP_METHOD(Phalcon_Tag, appendTitle){

	zval *title = NULL;
	zval *t0 = NULL;
	zval *r0 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &title) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	PHALCON_OBSERVE_VAR(t0);
	phalcon_read_static_property(&t0, SL("phalcon\\tag"), SL("_documentTitle") TSRMLS_CC);
	PHALCON_ALLOC_ZVAL_MM(r0);
	concat_function(r0, t0, title TSRMLS_CC);
	phalcon_update_static_property(SL("phalcon\\tag"), SL("_documentTitle"), r0 TSRMLS_CC);
	
	PHALCON_MM_RESTORE();
}

/**
 * Add before the title of view content
 *
 * @param string $title
 */
PHP_METHOD(Phalcon_Tag, prependTitle){

	zval *title = NULL, *document_title = NULL;
	zval *r0 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &title) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	PHALCON_OBSERVE_VAR(document_title);
	phalcon_read_static_property(&document_title, SL("phalcon\\tag"), SL("_documentTitle") TSRMLS_CC);
	
	PHALCON_ALLOC_ZVAL_MM(r0);
	PHALCON_CONCAT_VV(r0, title, document_title);
	phalcon_update_static_property(SL("phalcon\\tag"), SL("_documentTitle"), r0 TSRMLS_CC);
	
	PHALCON_MM_RESTORE();
}

/**
 * Get the title of view content
 *
 * @return string
 */
PHP_METHOD(Phalcon_Tag, getTitle){

	zval *document_title = NULL, *eol = NULL, *title_html = NULL;

	PHALCON_MM_GROW();
	PHALCON_OBSERVE_VAR(document_title);
	phalcon_read_static_property(&document_title, SL("phalcon\\tag"), SL("_documentTitle") TSRMLS_CC);
	
	PHALCON_INIT_VAR(eol);
	zend_get_constant(SL("PHP_EOL"), eol TSRMLS_CC);
	
	PHALCON_INIT_VAR(title_html);
	PHALCON_CONCAT_SVSV(title_html, "<title>", document_title, "</title>", eol);
	
	RETURN_CTOR(title_html);
}

/**
 * Builds a LINK[rel="stylesheet"] tag
 *
 * <code>
 * echo Phalcon\Tag::stylesheetLink("http://fonts.googleapis.com/css?family=Rosario", false);
 * echo Phalcon\Tag::stylesheetLink("css/style.css");
 * </code>
 *
 * @param array $parameters
 * @param   boolean $local
 * @return string
 */
PHP_METHOD(Phalcon_Tag, stylesheetLink){

	zval *parameters = NULL, *local = NULL, *params = NULL, *first_param = NULL;
	zval *url = NULL, *href = NULL, *code = NULL, *value = NULL, *key = NULL, *attribute = NULL;
	zval *r0 = NULL;
	zval *t0 = NULL;
	HashTable *ah0;
	HashPosition hp0;
	zval **hd;
	char *hash_index;
	uint hash_index_len;
	ulong hash_num;
	int hash_type;
	int eval_int;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "|zz", &parameters, &local) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	if (!parameters) {
		PHALCON_ALLOC_ZVAL_MM(parameters);
		ZVAL_NULL(parameters);
	}
	
	if (!local) {
		PHALCON_ALLOC_ZVAL_MM(local);
		ZVAL_BOOL(local, 1);
	} else {
		PHALCON_SEPARATE_PARAM(local);
	}
	
	if (Z_TYPE_P(parameters) != IS_ARRAY) { 
		PHALCON_INIT_VAR(params);
		array_init(params);
		phalcon_array_append(&params, parameters, PH_SEPARATE TSRMLS_CC);
		phalcon_array_append(&params, local, PH_SEPARATE TSRMLS_CC);
	} else {
		PHALCON_CPY_WRT(params, parameters);
	}
	eval_int = phalcon_array_isset_string(params, SL("href")+1);
	if (!eval_int) {
		eval_int = phalcon_array_isset_long(params, 0);
		if (eval_int) {
			PHALCON_INIT_VAR(first_param);
			phalcon_array_fetch_long(&first_param, params, 0, PH_NOISY_CC);
			phalcon_array_update_string(&params, SL("href"), &first_param, PH_COPY | PH_SEPARATE TSRMLS_CC);
		} else {
			phalcon_array_update_string_string(&params, SL("href"), SL(""), PH_SEPARATE TSRMLS_CC);
		}
	}
	
	PHALCON_INIT_VAR(local);
	ZVAL_STRING(local, "", 1);
	eval_int = phalcon_array_isset_long(params, 1);
	if (eval_int) {
		PHALCON_INIT_VAR(local);
		phalcon_array_fetch_long(&local, params, 1, PH_NOISY_CC);
	} else {
		eval_int = phalcon_array_isset_string(params, SL("local")+1);
		if (eval_int) {
			PHALCON_INIT_VAR(local);
			phalcon_array_fetch_string(&local, params, SL("local"), PH_NOISY_CC);
			PHALCON_SEPARATE(params);
			phalcon_array_unset_string(params, SL("local")+1);
		}
	}
	
	eval_int = phalcon_array_isset_string(params, SL("type")+1);
	if (!eval_int) {
		phalcon_array_update_string_string(&params, SL("type"), SL("text/css"), PH_SEPARATE TSRMLS_CC);
	}
	
	if (zend_is_true(local)) {
		PHALCON_INIT_VAR(url);
		PHALCON_CALL_SELF(url, this_ptr, "geturlservice");
		
		PHALCON_ALLOC_ZVAL_MM(r0);
		phalcon_array_fetch_string(&r0, params, SL("href"), PH_NOISY_CC);
		
		PHALCON_INIT_VAR(href);
		PHALCON_CALL_METHOD_PARAMS_1(href, url, "get", r0, PH_NO_CHECK);
		phalcon_array_update_string(&params, SL("href"), &href, PH_COPY | PH_SEPARATE TSRMLS_CC);
	}
	
	PHALCON_INIT_VAR(code);
	ZVAL_STRING(code, "<link rel=\"stylesheet\"", 1);
	if (!phalcon_valid_foreach(params TSRMLS_CC)) {
		return;
	}
	
	ah0 = Z_ARRVAL_P(params);
	zend_hash_internal_pointer_reset_ex(ah0, &hp0);
	fes_9b93_5:
		if(zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) != SUCCESS){
			goto fee_9b93_5;
		}
		
		PHALCON_INIT_VAR(key);
		PHALCON_GET_FOREACH_KEY(key, ah0, hp0);
		PHALCON_INIT_VAR(value);
		ZVAL_ZVAL(value, *hd, 1, 0);
		if (Z_TYPE_P(key) != IS_LONG) {
			PHALCON_INIT_VAR(attribute);
			PHALCON_CONCAT_SVSVS(attribute, " ", key, "=\"", value, "\"");
			phalcon_concat_self(&code, attribute TSRMLS_CC);
		}
		zend_hash_move_forward_ex(ah0, &hp0);
		goto fes_9b93_5;
	fee_9b93_5:
	
	PHALCON_INIT_VAR(t0);
	ZVAL_STRING(t0, " />", 1);
	phalcon_concat_self(&code, t0 TSRMLS_CC);
	
	RETURN_CTOR(code);
}

/**
 * Builds a SCRIPT[type="javascript"] tag
 *
 * <code>
 * echo Phalcon\Tag::javascriptInclude("http://ajax.googleapis.com/ajax/libs/jquery/1.7.1/jquery.min.js", false);
 * echo Phalcon\Tag::javascriptInclude("javascript/jquery.js");
 * </code>
 *
 * @param array $parameters
 * @param   boolean $local
 * @return string
 */
PHP_METHOD(Phalcon_Tag, javascriptInclude){

	zval *parameters = NULL, *local = NULL, *params = NULL, *url = NULL, *src = NULL, *code = NULL;
	zval *value = NULL, *key = NULL, *attribute = NULL;
	zval *r0 = NULL, *r1 = NULL;
	zval *t0 = NULL;
	HashTable *ah0;
	HashPosition hp0;
	zval **hd;
	char *hash_index;
	uint hash_index_len;
	ulong hash_num;
	int hash_type;
	int eval_int;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "|zz", &parameters, &local) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	if (!parameters) {
		PHALCON_ALLOC_ZVAL_MM(parameters);
		ZVAL_NULL(parameters);
	}
	
	if (!local) {
		PHALCON_ALLOC_ZVAL_MM(local);
		ZVAL_BOOL(local, 1);
	} else {
		PHALCON_SEPARATE_PARAM(local);
	}
	
	if (Z_TYPE_P(parameters) != IS_ARRAY) { 
		PHALCON_INIT_VAR(params);
		array_init(params);
		phalcon_array_append(&params, parameters, PH_SEPARATE TSRMLS_CC);
		phalcon_array_append(&params, local, PH_SEPARATE TSRMLS_CC);
	} else {
		PHALCON_CPY_WRT(params, parameters);
	}
	eval_int = phalcon_array_isset_string(params, SL("src")+1);
	if (!eval_int) {
		eval_int = phalcon_array_isset_long(params, 0);
		if (eval_int) {
			PHALCON_ALLOC_ZVAL_MM(r0);
			phalcon_array_fetch_long(&r0, params, 0, PH_NOISY_CC);
			phalcon_array_update_string(&params, SL("src"), &r0, PH_COPY | PH_SEPARATE TSRMLS_CC);
		} else {
			phalcon_array_update_string_string(&params, SL("src"), SL(""), PH_SEPARATE TSRMLS_CC);
		}
	}
	
	PHALCON_INIT_VAR(local);
	ZVAL_STRING(local, "", 1);
	eval_int = phalcon_array_isset_long(params, 1);
	if (eval_int) {
		PHALCON_INIT_VAR(local);
		phalcon_array_fetch_long(&local, params, 1, PH_NOISY_CC);
	} else {
		eval_int = phalcon_array_isset_string(params, SL("local")+1);
		if (eval_int) {
			PHALCON_INIT_VAR(local);
			phalcon_array_fetch_string(&local, params, SL("local"), PH_NOISY_CC);
			PHALCON_SEPARATE(params);
			phalcon_array_unset_string(params, SL("local")+1);
		}
	}
	
	eval_int = phalcon_array_isset_string(params, SL("type")+1);
	if (!eval_int) {
		phalcon_array_update_string_string(&params, SL("type"), SL("text/javascript"), PH_SEPARATE TSRMLS_CC);
	}
	
	if (zend_is_true(local)) {
		PHALCON_INIT_VAR(url);
		PHALCON_CALL_SELF(url, this_ptr, "geturlservice");
		
		PHALCON_ALLOC_ZVAL_MM(r1);
		phalcon_array_fetch_string(&r1, params, SL("src"), PH_NOISY_CC);
		
		PHALCON_INIT_VAR(src);
		PHALCON_CALL_METHOD_PARAMS_1(src, url, "get", r1, PH_NO_CHECK);
		phalcon_array_update_string(&params, SL("src"), &src, PH_COPY | PH_SEPARATE TSRMLS_CC);
	}
	
	PHALCON_INIT_VAR(code);
	ZVAL_STRING(code, "<script", 1);
	if (!phalcon_valid_foreach(params TSRMLS_CC)) {
		return;
	}
	
	ah0 = Z_ARRVAL_P(params);
	zend_hash_internal_pointer_reset_ex(ah0, &hp0);
	fes_9b93_6:
		if(zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) != SUCCESS){
			goto fee_9b93_6;
		}
		
		PHALCON_INIT_VAR(key);
		PHALCON_GET_FOREACH_KEY(key, ah0, hp0);
		PHALCON_INIT_VAR(value);
		ZVAL_ZVAL(value, *hd, 1, 0);
		if (Z_TYPE_P(key) != IS_LONG) {
			PHALCON_INIT_VAR(attribute);
			PHALCON_CONCAT_SVSVS(attribute, " ", key, "=\"", value, "\"");
			phalcon_concat_self(&code, attribute TSRMLS_CC);
		}
		zend_hash_move_forward_ex(ah0, &hp0);
		goto fes_9b93_6;
	fee_9b93_6:
	
	PHALCON_INIT_VAR(t0);
	ZVAL_STRING(t0, "></script>", 1);
	phalcon_concat_self(&code, t0 TSRMLS_CC);
	
	RETURN_CTOR(code);
}

/**
 * Builds HTML IMG tags
 *
 * @param  array $parameters
 * @return string
 */
PHP_METHOD(Phalcon_Tag, image){

	zval *parameters = NULL, *params = NULL, *first_param = NULL, *url = NULL, *src = NULL;
	zval *code = NULL, *value = NULL, *key = NULL, *attribute = NULL;
	zval *r0 = NULL;
	zval *t0 = NULL;
	HashTable *ah0;
	HashPosition hp0;
	zval **hd;
	char *hash_index;
	uint hash_index_len;
	ulong hash_num;
	int hash_type;
	int eval_int;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "|z", &parameters) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	if (!parameters) {
		PHALCON_ALLOC_ZVAL_MM(parameters);
		ZVAL_NULL(parameters);
	}
	
	if (Z_TYPE_P(parameters) != IS_ARRAY) { 
		PHALCON_INIT_VAR(params);
		array_init(params);
		phalcon_array_append(&params, parameters, PH_SEPARATE TSRMLS_CC);
	} else {
		PHALCON_CPY_WRT(params, parameters);
	}
	eval_int = phalcon_array_isset_string(params, SL("src")+1);
	if (!eval_int) {
		eval_int = phalcon_array_isset_long(params, 0);
		if (eval_int) {
			PHALCON_INIT_VAR(first_param);
			phalcon_array_fetch_long(&first_param, params, 0, PH_NOISY_CC);
			phalcon_array_update_string(&params, SL("src"), &first_param, PH_COPY | PH_SEPARATE TSRMLS_CC);
		} else {
			phalcon_array_update_string_string(&params, SL("src"), SL(""), PH_SEPARATE TSRMLS_CC);
		}
	}
	
	PHALCON_INIT_VAR(url);
	PHALCON_CALL_SELF(url, this_ptr, "geturlservice");
	
	PHALCON_ALLOC_ZVAL_MM(r0);
	phalcon_array_fetch_string(&r0, params, SL("src"), PH_NOISY_CC);
	
	PHALCON_INIT_VAR(src);
	PHALCON_CALL_METHOD_PARAMS_1(src, url, "get", r0, PH_NO_CHECK);
	phalcon_array_update_string(&params, SL("src"), &src, PH_COPY | PH_SEPARATE TSRMLS_CC);
	
	PHALCON_INIT_VAR(code);
	ZVAL_STRING(code, "<img", 1);
	if (!phalcon_valid_foreach(params TSRMLS_CC)) {
		return;
	}
	
	ah0 = Z_ARRVAL_P(params);
	zend_hash_internal_pointer_reset_ex(ah0, &hp0);
	fes_9b93_7:
		if(zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) != SUCCESS){
			goto fee_9b93_7;
		}
		
		PHALCON_INIT_VAR(key);
		PHALCON_GET_FOREACH_KEY(key, ah0, hp0);
		PHALCON_INIT_VAR(value);
		ZVAL_ZVAL(value, *hd, 1, 0);
		if (Z_TYPE_P(key) != IS_LONG) {
			PHALCON_INIT_VAR(attribute);
			PHALCON_CONCAT_SVSVS(attribute, " ", key, "=\"", value, "\"");
			phalcon_concat_self(&code, attribute TSRMLS_CC);
		}
		zend_hash_move_forward_ex(ah0, &hp0);
		goto fes_9b93_7;
	fee_9b93_7:
	
	PHALCON_INIT_VAR(t0);
	ZVAL_STRING(t0, " />", 1);
	phalcon_concat_self(&code, t0 TSRMLS_CC);
	
	RETURN_CTOR(code);
}

