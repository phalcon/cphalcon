
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
#include "kernel/hash.h"
#include "kernel/concat.h"
#include "kernel/string.h"


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
 * Obtains the 'escaper' service if required
 *
 * @param array params
 * @return EscaperInterface
 */
PHP_METHOD(Phalcon_Tag, getEscaper) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *params_param = NULL, *autoescape = NULL;
	zval *params = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &params_param);

	params = params_param;


	ZEPHIR_OBS_VAR(autoescape);
	if (!(zephir_array_isset_string_fetch(&autoescape, params, SS("escape"), 0 TSRMLS_CC))) {
		ZEPHIR_OBS_NVAR(autoescape);
		zephir_read_static_property_ce(&autoescape, phalcon_tag_ce, SL("_autoEscape") TSRMLS_CC);
	}
	if (!(zephir_is_true(autoescape))) {
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

	zend_bool _10$$7, _11$$8;
	HashTable *_1, *_4, *_8;
	HashPosition _0, _3, _7;
	zephir_fcall_cache_entry *_15 = NULL, *_16 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *attributes = NULL;
	zval *code_param = NULL, *attributes_param = NULL, *order = NULL, *escaper = NULL, *attrs = NULL, *attribute = NULL, *value = NULL, *escaped = NULL, *key = NULL, *newCode = NULL, **_2, **_5, *_6 = NULL, **_9, *_17$$8 = NULL, *_12$$9 = NULL, *_13$$9 = NULL, *_14$$9 = NULL;
	zval *code = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &code_param, &attributes_param);

	if (unlikely(Z_TYPE_P(code_param) != IS_STRING && Z_TYPE_P(code_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'code' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (likely(Z_TYPE_P(code_param) == IS_STRING)) {
		zephir_get_strval(code, code_param);
	} else {
		ZEPHIR_INIT_VAR(code);
		ZVAL_EMPTY_STRING(code);
	}
	attributes = attributes_param;


	ZEPHIR_INIT_VAR(order);
	zephir_create_array(order, 10, 0 TSRMLS_CC);
	zephir_array_update_string(&order, SL("rel"), &ZEPHIR_GLOBAL(global_null), PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&order, SL("type"), &ZEPHIR_GLOBAL(global_null), PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&order, SL("for"), &ZEPHIR_GLOBAL(global_null), PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&order, SL("src"), &ZEPHIR_GLOBAL(global_null), PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&order, SL("href"), &ZEPHIR_GLOBAL(global_null), PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&order, SL("action"), &ZEPHIR_GLOBAL(global_null), PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&order, SL("id"), &ZEPHIR_GLOBAL(global_null), PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&order, SL("name"), &ZEPHIR_GLOBAL(global_null), PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&order, SL("value"), &ZEPHIR_GLOBAL(global_null), PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&order, SL("class"), &ZEPHIR_GLOBAL(global_null), PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_VAR(attrs);
	array_init(attrs);
	zephir_is_iterable(order, &_1, &_0, 0, 0, "phalcon/tag.zep", 137);
	for (
	  ; zephir_hash_get_current_data_ex(_1, (void**) &_2, &_0) == SUCCESS
	  ; zephir_hash_move_forward_ex(_1, &_0)
	) {
		ZEPHIR_GET_HMKEY(key, _1, _0);
		ZEPHIR_GET_HVALUE(value, _2);
		ZEPHIR_OBS_NVAR(attribute);
		if (zephir_array_isset_fetch(&attribute, attributes, key, 0 TSRMLS_CC)) {
			zephir_array_update_zval(&attrs, key, &attribute, PH_COPY | PH_SEPARATE);
		}
	}
	zephir_is_iterable(attributes, &_4, &_3, 0, 0, "phalcon/tag.zep", 143);
	for (
	  ; zephir_hash_get_current_data_ex(_4, (void**) &_5, &_3) == SUCCESS
	  ; zephir_hash_move_forward_ex(_4, &_3)
	) {
		ZEPHIR_GET_HMKEY(key, _4, _3);
		ZEPHIR_GET_HVALUE(value, _5);
		if (!(zephir_array_isset(attrs, key))) {
			zephir_array_update_zval(&attrs, key, &value, PH_COPY | PH_SEPARATE);
		}
	}
	ZEPHIR_CALL_SELF(&_6, "getescaper", NULL, 0, attributes);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(escaper, _6);
	zephir_array_unset_string(&attrs, SS("escape"), PH_SEPARATE);
	ZEPHIR_CPY_WRT(newCode, code);
	zephir_is_iterable(attrs, &_8, &_7, 0, 0, "phalcon/tag.zep", 162);
	for (
	  ; zephir_hash_get_current_data_ex(_8, (void**) &_9, &_7) == SUCCESS
	  ; zephir_hash_move_forward_ex(_8, &_7)
	) {
		ZEPHIR_GET_HMKEY(key, _8, _7);
		ZEPHIR_GET_HVALUE(value, _9);
		_10$$7 = Z_TYPE_P(key) == IS_STRING;
		if (_10$$7) {
			_10$$7 = Z_TYPE_P(value) != IS_NULL;
		}
		if (_10$$7) {
			_11$$8 = Z_TYPE_P(value) == IS_ARRAY;
			if (!(_11$$8)) {
				_11$$8 = Z_TYPE_P(value) == IS_RESOURCE;
			}
			if (_11$$8) {
				ZEPHIR_INIT_NVAR(_12$$9);
				object_init_ex(_12$$9, phalcon_tag_exception_ce);
				ZEPHIR_INIT_NVAR(_13$$9);
				zephir_gettype(_13$$9, value TSRMLS_CC);
				ZEPHIR_INIT_LNVAR(_14$$9);
				ZEPHIR_CONCAT_SVSVS(_14$$9, "Value at index: '", key, "' type: '", _13$$9, "' cannot be rendered");
				ZEPHIR_CALL_METHOD(NULL, _12$$9, "__construct", &_15, 9, _14$$9);
				zephir_check_call_status();
				zephir_throw_exception_debug(_12$$9, "phalcon/tag.zep", 151 TSRMLS_CC);
				ZEPHIR_MM_RESTORE();
				return;
			}
			if (zephir_is_true(escaper)) {
				ZEPHIR_CALL_METHOD(&escaped, escaper, "escapehtmlattr", &_16, 0, value);
				zephir_check_call_status();
			} else {
				ZEPHIR_CPY_WRT(escaped, value);
			}
			ZEPHIR_INIT_LNVAR(_17$$8);
			ZEPHIR_CONCAT_SVSVS(_17$$8, " ", key, "=\"", escaped, "\"");
			zephir_concat_self(&newCode, _17$$8 TSRMLS_CC);
		}
	}
	RETURN_CCTOR(newCode);

}

/**
 * Sets the dependency injector container.
 */
PHP_METHOD(Phalcon_Tag, setDI) {

	zval *dependencyInjector;

	zephir_fetch_params(0, 1, 0, &dependencyInjector);



	zephir_update_static_property_ce(phalcon_tag_ce, SL("_dependencyInjector"), &dependencyInjector TSRMLS_CC);

}

/**
 * Internally gets the request dispatcher
 */
PHP_METHOD(Phalcon_Tag, getDI) {

	zval *di = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL;

	ZEPHIR_MM_GROW();

	ZEPHIR_OBS_VAR(di);
	zephir_read_static_property_ce(&di, phalcon_tag_ce, SL("_dependencyInjector") TSRMLS_CC);
	if (Z_TYPE_P(di) != IS_OBJECT) {
		ZEPHIR_CALL_CE_STATIC(&di, phalcon_di_ce, "getdefault", &_0, 1);
		zephir_check_call_status();
	}
	RETURN_CCTOR(di);

}

/**
 * Returns a URL service from the default DI
 */
PHP_METHOD(Phalcon_Tag, getUrlService) {

	zval *url = NULL, *dependencyInjector = NULL, *_0$$3, *_2$$3 = NULL, *_3$$3;
	int ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_1 = NULL;

	ZEPHIR_MM_GROW();

	ZEPHIR_OBS_VAR(url);
	zephir_read_static_property_ce(&url, phalcon_tag_ce, SL("_urlService") TSRMLS_CC);
	if (Z_TYPE_P(url) != IS_OBJECT) {
		_0$$3 = zephir_fetch_static_property_ce(phalcon_tag_ce, SL("_dependencyInjector") TSRMLS_CC);
		ZEPHIR_CPY_WRT(dependencyInjector, _0$$3);
		if (Z_TYPE_P(dependencyInjector) != IS_OBJECT) {
			ZEPHIR_CALL_CE_STATIC(&dependencyInjector, phalcon_di_ce, "getdefault", &_1, 1);
			zephir_check_call_status();
		}
		if (Z_TYPE_P(dependencyInjector) != IS_OBJECT) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_tag_exception_ce, "A dependency injector container is required to obtain the 'url' service", "phalcon/tag.zep", 202);
			return;
		}
		ZEPHIR_INIT_VAR(_3$$3);
		ZVAL_STRING(_3$$3, "url", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&_2$$3, dependencyInjector, "getshared", NULL, 0, _3$$3);
		zephir_check_temp_parameter(_3$$3);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(url, _2$$3);
		zephir_update_static_property_ce(phalcon_tag_ce, SL("_urlService"), &url TSRMLS_CC);
	}
	RETURN_CCTOR(url);

}

/**
 * Returns an Escaper service from the default DI
 */
PHP_METHOD(Phalcon_Tag, getEscaperService) {

	zval *escaper = NULL, *dependencyInjector = NULL, *_0$$3, *_2$$3 = NULL, *_3$$3;
	int ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_1 = NULL;

	ZEPHIR_MM_GROW();

	ZEPHIR_OBS_VAR(escaper);
	zephir_read_static_property_ce(&escaper, phalcon_tag_ce, SL("_escaperService") TSRMLS_CC);
	if (Z_TYPE_P(escaper) != IS_OBJECT) {
		_0$$3 = zephir_fetch_static_property_ce(phalcon_tag_ce, SL("_dependencyInjector") TSRMLS_CC);
		ZEPHIR_CPY_WRT(dependencyInjector, _0$$3);
		if (Z_TYPE_P(dependencyInjector) != IS_OBJECT) {
			ZEPHIR_CALL_CE_STATIC(&dependencyInjector, phalcon_di_ce, "getdefault", &_1, 1);
			zephir_check_call_status();
		}
		if (Z_TYPE_P(dependencyInjector) != IS_OBJECT) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_tag_exception_ce, "A dependency injector container is required to obtain the 'escaper' service", "phalcon/tag.zep", 227);
			return;
		}
		ZEPHIR_INIT_VAR(_3$$3);
		ZVAL_STRING(_3$$3, "escaper", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&_2$$3, dependencyInjector, "getshared", NULL, 0, _3$$3);
		zephir_check_temp_parameter(_3$$3);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(escaper, _2$$3);
		zephir_update_static_property_ce(phalcon_tag_ce, SL("_escaperService"), &escaper TSRMLS_CC);
	}
	RETURN_CCTOR(escaper);

}

/**
 * Set autoescape mode in generated html
 */
PHP_METHOD(Phalcon_Tag, setAutoescape) {

	zval *autoescape_param = NULL, *_0;
	zend_bool autoescape;

	zephir_fetch_params(0, 1, 0, &autoescape_param);

	autoescape = zephir_get_boolval(autoescape_param);


	ZEPHIR_INIT_ZVAL_NREF(_0);
	ZVAL_BOOL(_0, autoescape);
	zephir_update_static_property_ce(phalcon_tag_ce, SL("_autoEscape"), &_0 TSRMLS_CC);

}

/**
 * Assigns default values to generated tags by helpers
 *
 * <code>
 * // Assigning "peter" to "name" component
 * Phalcon\Tag::setDefault("name", "peter");
 *
 * // Later in the view
 * echo Phalcon\Tag::textField("name"); //Will have the value "peter" by default
 * </code>
 *
 * @param string id
 * @param string value
 */
PHP_METHOD(Phalcon_Tag, setDefault) {

	zend_bool _0$$3;
	zval *id_param = NULL, *value;
	zval *id = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &id_param, &value);

	if (unlikely(Z_TYPE_P(id_param) != IS_STRING && Z_TYPE_P(id_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'id' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (likely(Z_TYPE_P(id_param) == IS_STRING)) {
		zephir_get_strval(id, id_param);
	} else {
		ZEPHIR_INIT_VAR(id);
		ZVAL_EMPTY_STRING(id);
	}


	if (Z_TYPE_P(value) != IS_NULL) {
		_0$$3 = Z_TYPE_P(value) == IS_ARRAY;
		if (!(_0$$3)) {
			_0$$3 = Z_TYPE_P(value) == IS_OBJECT;
		}
		if (_0$$3) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_tag_exception_ce, "Only scalar values can be assigned to UI components", "phalcon/tag.zep", 262);
			return;
		}
	}
	zephir_update_static_property_array_multi_ce(phalcon_tag_ce, SL("_displayValues"), &value TSRMLS_CC, SL("z"), 1, id);
	ZEPHIR_MM_RESTORE();

}

/**
 * Assigns default values to generated tags by helpers
 *
 * <code>
 * // Assigning "peter" to "name" component
 * Phalcon\Tag::setDefaults(array("name" => "peter"));
 *
 * // Later in the view
 * echo Phalcon\Tag::textField("name"); //Will have the value "peter" by default
 * </code>
 */
PHP_METHOD(Phalcon_Tag, setDefaults) {

	zend_bool merge, _0;
	zval *values_param = NULL, *merge_param = NULL, *_1, *_2$$3, *_3$$3;
	zval *values = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &values_param, &merge_param);

	values = values_param;
	if (!merge_param) {
		merge = 0;
	} else {
		merge = zephir_get_boolval(merge_param);
	}


	_0 = merge;
	if (_0) {
		ZEPHIR_OBS_VAR(_1);
		zephir_read_static_property_ce(&_1, phalcon_tag_ce, SL("_displayValues") TSRMLS_CC);
		_0 = Z_TYPE_P(_1) == IS_ARRAY;
	}
	if (_0) {
		ZEPHIR_INIT_VAR(_2$$3);
		_3$$3 = zephir_fetch_static_property_ce(phalcon_tag_ce, SL("_displayValues") TSRMLS_CC);
		zephir_fast_array_merge(_2$$3, &(_3$$3), &(values) TSRMLS_CC);
		zephir_update_static_property_ce(phalcon_tag_ce, SL("_displayValues"), &_2$$3 TSRMLS_CC);
	} else {
		zephir_update_static_property_ce(phalcon_tag_ce, SL("_displayValues"), &values TSRMLS_CC);
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * Alias of Phalcon\Tag::setDefault
 *
 * @param string id
 * @param string value
 */
PHP_METHOD(Phalcon_Tag, displayTo) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *id, *value;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &id, &value);



	ZEPHIR_CALL_SELF(NULL, "setdefault", NULL, 0, id, value);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * Check if a helper has a default value set using Phalcon\Tag::setDefault or value from _POST
 *
 * @param string name
 * @return boolean
 */
PHP_METHOD(Phalcon_Tag, hasValue) {

	zend_bool _1;
	zval *name, *_POST, *_0;

	ZEPHIR_MM_GROW();
	zephir_get_global(&_POST, SS("_POST") TSRMLS_CC);
	zephir_fetch_params(0, 1, 0, &name);



	_0 = zephir_fetch_static_property_ce(phalcon_tag_ce, SL("_displayValues") TSRMLS_CC);
	_1 = zephir_array_isset(_0, name);
	if (!(_1)) {
		_1 = zephir_array_isset(_POST, name);
	}
	RETURN_MM_BOOL(_1);

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

	zend_bool _0;
	zval *name, *params = NULL, *_POST, *value = NULL, *_1$$3;

	ZEPHIR_MM_GROW();
	zephir_get_global(&_POST, SS("_POST") TSRMLS_CC);
	zephir_fetch_params(1, 1, 1, &name, &params);

	if (!params) {
		params = ZEPHIR_GLOBAL(global_null);
	}


	_0 = !zephir_is_true(params);
	if (!(_0)) {
		ZEPHIR_OBS_VAR(value);
		_0 = !(zephir_array_isset_string_fetch(&value, params, SS("value"), 0 TSRMLS_CC));
	}
	if (_0) {
		ZEPHIR_OBS_NVAR(value);
		_1$$3 = zephir_fetch_static_property_ce(phalcon_tag_ce, SL("_displayValues") TSRMLS_CC);
		if (!(zephir_array_isset_fetch(&value, _1$$3, name, 0 TSRMLS_CC))) {
			ZEPHIR_OBS_NVAR(value);
			if (!(zephir_array_isset_fetch(&value, _POST, name, 0 TSRMLS_CC))) {
				RETURN_MM_NULL();
			}
		}
	}
	RETURN_CCTOR(value);

}

/**
 * Resets the request and internal values to avoid those fields will have any default value
 */
PHP_METHOD(Phalcon_Tag, resetInput) {

	zval *_0, *_1, *_2 = NULL;

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(_0);
	array_init(_0);
	zephir_update_static_property_ce(phalcon_tag_ce, SL("_displayValues"), &_0 TSRMLS_CC);
	ZEPHIR_INIT_VAR(_1);
	array_init(_1);
	ZEPHIR_INIT_VAR(_2);
	if (zephir_set_symbol_str(SS("_POST"), _2 TSRMLS_CC) == FAILURE) {
	  return;
	}
	zephir_update_static_property_ce(phalcon_tag_ce, SL("_documentTitle"), &ZEPHIR_GLOBAL(global_null) TSRMLS_CC);
	zephir_update_static_property_ce(phalcon_tag_ce, SL("_documentAppendTitle"), &ZEPHIR_GLOBAL(global_null) TSRMLS_CC);
	zephir_update_static_property_ce(phalcon_tag_ce, SL("_documentPrependTitle"), &ZEPHIR_GLOBAL(global_null) TSRMLS_CC);
	zephir_update_static_property_ce(phalcon_tag_ce, SL("_documentTitleSeparator"), &ZEPHIR_GLOBAL(global_null) TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

/**
 * Builds a HTML A tag using framework conventions
 *
 *<code>
 * echo Phalcon\Tag::linkTo("signup/register", "Register Here!");
 * echo Phalcon\Tag::linkTo(array("signup/register", "Register Here!"));
 * echo Phalcon\Tag::linkTo(array("signup/register", "Register Here!", "class" => "btn-primary"));
 * echo Phalcon\Tag::linkTo("http://phalconphp.com/", "Phalcon", FALSE);
 * echo Phalcon\Tag::linkTo(array("http://phalconphp.com/", "Phalcon Home", FALSE));
 * echo Phalcon\Tag::linkTo(array("http://phalconphp.com/", "Phalcon Home", "local" =>FALSE));
 *</code>
 *
 * @param array|string parameters
 * @param string text
 * @param boolean local
 * @return string
 */
PHP_METHOD(Phalcon_Tag, linkTo) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *parameters, *text = NULL, *local = NULL, *params = NULL, *action = NULL, *query = NULL, *url = NULL, *code = NULL, *_0 = NULL, *_1, *_2;

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


	if (Z_TYPE_P(parameters) != IS_ARRAY) {
		ZEPHIR_INIT_VAR(params);
		zephir_create_array(params, 3, 0 TSRMLS_CC);
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
			ZEPHIR_INIT_NVAR(action);
			ZVAL_STRING(action, "", 1);
		} else {
			zephir_array_unset_string(&params, SS("action"), PH_SEPARATE);
		}
	}
	ZEPHIR_OBS_NVAR(text);
	if (!(zephir_array_isset_long_fetch(&text, params, 1, 0 TSRMLS_CC))) {
		ZEPHIR_OBS_NVAR(text);
		if (!(zephir_array_isset_string_fetch(&text, params, SS("text"), 0 TSRMLS_CC))) {
			ZEPHIR_INIT_NVAR(text);
			ZVAL_STRING(text, "", 1);
		} else {
			zephir_array_unset_string(&params, SS("text"), PH_SEPARATE);
		}
	}
	ZEPHIR_OBS_NVAR(local);
	if (!(zephir_array_isset_long_fetch(&local, params, 2, 0 TSRMLS_CC))) {
		ZEPHIR_OBS_NVAR(local);
		if (!(zephir_array_isset_string_fetch(&local, params, SS("local"), 0 TSRMLS_CC))) {
			ZEPHIR_INIT_NVAR(local);
			ZVAL_BOOL(local, 1);
		} else {
			zephir_array_unset_string(&params, SS("local"), PH_SEPARATE);
		}
	}
	ZEPHIR_OBS_VAR(query);
	if (zephir_array_isset_string_fetch(&query, params, SS("query"), 0 TSRMLS_CC)) {
		zephir_array_unset_string(&params, SS("query"), PH_SEPARATE);
	} else {
		ZEPHIR_INIT_NVAR(query);
		ZVAL_NULL(query);
	}
	ZEPHIR_CALL_SELF(&url, "geturlservice", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_0, url, "get", NULL, 0, action, query, local);
	zephir_check_call_status();
	zephir_array_update_string(&params, SL("href"), &_0, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_VAR(_1);
	ZVAL_STRING(_1, "<a", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_SELF(&code, "renderattributes", NULL, 0, _1, params);
	zephir_check_temp_parameter(_1);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_2);
	ZEPHIR_CONCAT_SVS(_2, ">", text, "</a>");
	zephir_concat_self(&code, _2 TSRMLS_CC);
	RETURN_CCTOR(code);

}

/**
 * Builds generic INPUT tags
 *
 * @param string type
 * @param array parameters
 * @param boolean asValue
 * @return string
 */
PHP_METHOD(Phalcon_Tag, _inputField) {

	int ZEPHIR_LAST_CALL_STATUS;
	zend_bool asValue, _1$$10;
	zval *type_param = NULL, *parameters, *asValue_param = NULL, *params = NULL, *id = NULL, *value = NULL, *code = NULL, *name = NULL, *_3, *_4, *_0$$6, *_2$$5 = NULL;
	zval *type = NULL;

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
	if (Z_TYPE_P(parameters) != IS_ARRAY) {
		zephir_array_append(&params, parameters, PH_SEPARATE, "phalcon/tag.zep", 434);
	} else {
		ZEPHIR_CPY_WRT(params, parameters);
	}
	if (asValue == 0) {
		ZEPHIR_OBS_VAR(id);
		if (!(zephir_array_isset_long_fetch(&id, params, 0, 0 TSRMLS_CC))) {
			zephir_array_fetch_string(&_0$$6, params, SL("id"), PH_NOISY | PH_READONLY, "phalcon/tag.zep", 442 TSRMLS_CC);
			zephir_array_update_long(&params, 0, &_0$$6, PH_COPY | PH_SEPARATE ZEPHIR_DEBUG_PARAMS_DUMMY);
		}
		ZEPHIR_OBS_VAR(name);
		if (zephir_array_isset_string_fetch(&name, params, SS("name"), 0 TSRMLS_CC)) {
			if (ZEPHIR_IS_EMPTY(name)) {
				zephir_array_update_string(&params, SL("name"), &id, PH_COPY | PH_SEPARATE);
			}
		} else {
			zephir_array_update_string(&params, SL("name"), &id, PH_COPY | PH_SEPARATE);
		}
		if (Z_TYPE_P(id) == IS_STRING) {
			_1$$10 = !(zephir_memnstr_str(id, SL("["), "phalcon/tag.zep", 457));
			if (_1$$10) {
				_1$$10 = !(zephir_array_isset_string(params, SS("id")));
			}
			if (_1$$10) {
				zephir_array_update_string(&params, SL("id"), &id, PH_COPY | PH_SEPARATE);
			}
		}
		ZEPHIR_CALL_SELF(&_2$$5, "getvalue", NULL, 0, id, params);
		zephir_check_call_status();
		zephir_array_update_string(&params, SL("value"), &_2$$5, PH_COPY | PH_SEPARATE);
	} else {
		if (!(zephir_array_isset_string(params, SS("value")))) {
			ZEPHIR_OBS_VAR(value);
			if (zephir_array_isset_long_fetch(&value, params, 0, 0 TSRMLS_CC)) {
				zephir_array_update_string(&params, SL("value"), &value, PH_COPY | PH_SEPARATE);
			}
		}
	}
	zephir_array_update_string(&params, SL("type"), &type, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_VAR(_3);
	ZVAL_STRING(_3, "<input", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_SELF(&code, "renderattributes", NULL, 0, _3, params);
	zephir_check_temp_parameter(_3);
	zephir_check_call_status();
	_4 = zephir_fetch_static_property_ce(phalcon_tag_ce, SL("_documentType") TSRMLS_CC);
	if (ZEPHIR_GT_LONG(_4, 5)) {
		zephir_concat_self_str(&code, SL(" />") TSRMLS_CC);
	} else {
		zephir_concat_self_str(&code, SL(">") TSRMLS_CC);
	}
	RETURN_CCTOR(code);

}

/**
 * Builds INPUT tags that implements the checked attribute
 *
 * @param string type
 * @param array parameters
 * @return string
 */
PHP_METHOD(Phalcon_Tag, _inputFieldChecked) {

	zend_bool _3$$11;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *type_param = NULL, *parameters, *params = NULL, *value = NULL, *id = NULL, *code = NULL, *name = NULL, *currentValue = NULL, _1, *_2, *_6, *_7, *_0$$5, *_4$$12, *_5$$14;
	zval *type = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &type_param, &parameters);

	zephir_get_strval(type, type_param);


	if (Z_TYPE_P(parameters) != IS_ARRAY) {
		ZEPHIR_INIT_VAR(params);
		zephir_create_array(params, 1, 0 TSRMLS_CC);
		zephir_array_fast_append(params, parameters);
	} else {
		ZEPHIR_CPY_WRT(params, parameters);
	}
	if (!(zephir_array_isset_long(params, 0))) {
		zephir_array_fetch_string(&_0$$5, params, SL("id"), PH_NOISY | PH_READONLY, "phalcon/tag.zep", 508 TSRMLS_CC);
		zephir_array_update_long(&params, 0, &_0$$5, PH_COPY | PH_SEPARATE ZEPHIR_DEBUG_PARAMS_DUMMY);
	}
	ZEPHIR_OBS_VAR(id);
	zephir_array_fetch_long(&id, params, 0, PH_NOISY, "phalcon/tag.zep", 511 TSRMLS_CC);
	if (!(zephir_array_isset_string(params, SS("name")))) {
		zephir_array_update_string(&params, SL("name"), &id, PH_COPY | PH_SEPARATE);
	} else {
		ZEPHIR_OBS_VAR(name);
		zephir_array_fetch_string(&name, params, SL("name"), PH_NOISY, "phalcon/tag.zep", 515 TSRMLS_CC);
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
	ZEPHIR_OBS_VAR(currentValue);
	if (zephir_array_isset_string_fetch(&currentValue, params, SS("value"), 0 TSRMLS_CC)) {
		zephir_array_unset_string(&params, SS("value"), PH_SEPARATE);
		ZEPHIR_CALL_SELF(&value, "getvalue", NULL, 0, id, params);
		zephir_check_call_status();
		_3$$11 = Z_TYPE_P(value) != IS_NULL;
		if (_3$$11) {
			_3$$11 = ZEPHIR_IS_EQUAL(currentValue, value);
		}
		if (_3$$11) {
			ZEPHIR_INIT_VAR(_4$$12);
			ZVAL_STRING(_4$$12, "checked", 1);
			zephir_array_update_string(&params, SL("checked"), &_4$$12, PH_COPY | PH_SEPARATE);
		}
		zephir_array_update_string(&params, SL("value"), &currentValue, PH_COPY | PH_SEPARATE);
	} else {
		ZEPHIR_CALL_SELF(&value, "getvalue", NULL, 0, id, params);
		zephir_check_call_status();
		if (Z_TYPE_P(value) != IS_NULL) {
			ZEPHIR_INIT_VAR(_5$$14);
			ZVAL_STRING(_5$$14, "checked", 1);
			zephir_array_update_string(&params, SL("checked"), &_5$$14, PH_COPY | PH_SEPARATE);
		}
		zephir_array_update_string(&params, SL("value"), &value, PH_COPY | PH_SEPARATE);
	}
	zephir_array_update_string(&params, SL("type"), &type, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_VAR(_6);
	ZVAL_STRING(_6, "<input", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_SELF(&code, "renderattributes", NULL, 0, _6, params);
	zephir_check_temp_parameter(_6);
	zephir_check_call_status();
	_7 = zephir_fetch_static_property_ce(phalcon_tag_ce, SL("_documentType") TSRMLS_CC);
	if (ZEPHIR_GT_LONG(_7, 5)) {
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

	int ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL;
	zval *parameters, *_1;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &parameters);



	ZEPHIR_INIT_VAR(_1);
	ZVAL_STRING(_1, "color", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_RETURN_CALL_SELF("_inputfield", &_0, 430, _1, parameters);
	zephir_check_temp_parameter(_1);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Builds a HTML input[type="text"] tag
 *
 * <code>
 * echo Phalcon\Tag::textField(array("name", "size" => 30));
 * </code>
 *
 * @param array parameters
 * @return string
 */
PHP_METHOD(Phalcon_Tag, textField) {

	int ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL;
	zval *parameters, *_1;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &parameters);



	ZEPHIR_INIT_VAR(_1);
	ZVAL_STRING(_1, "text", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_RETURN_CALL_SELF("_inputfield", &_0, 430, _1, parameters);
	zephir_check_temp_parameter(_1);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Builds a HTML input[type="number"] tag
 *
 * <code>
 * echo Phalcon\Tag::numericField(array("price", "min" => "1", "max" => "5"));
 * </code>
 *
 * @param array parameters
 * @return string
 */
PHP_METHOD(Phalcon_Tag, numericField) {

	int ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL;
	zval *parameters, *_1;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &parameters);



	ZEPHIR_INIT_VAR(_1);
	ZVAL_STRING(_1, "number", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_RETURN_CALL_SELF("_inputfield", &_0, 430, _1, parameters);
	zephir_check_temp_parameter(_1);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Builds a HTML input[type="range"] tag
 *
 * @param array parameters
 * @return string
 */
PHP_METHOD(Phalcon_Tag, rangeField) {

	int ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL;
	zval *parameters, *_1;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &parameters);



	ZEPHIR_INIT_VAR(_1);
	ZVAL_STRING(_1, "range", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_RETURN_CALL_SELF("_inputfield", &_0, 430, _1, parameters);
	zephir_check_temp_parameter(_1);
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
 * @return string
 */
PHP_METHOD(Phalcon_Tag, emailField) {

	int ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL;
	zval *parameters, *_1;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &parameters);



	ZEPHIR_INIT_VAR(_1);
	ZVAL_STRING(_1, "email", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_RETURN_CALL_SELF("_inputfield", &_0, 430, _1, parameters);
	zephir_check_temp_parameter(_1);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Builds a HTML input[type="date"] tag
 *
 * <code>
 * echo Phalcon\Tag::dateField(array("born", "value" => "14-12-1980"))
 * </code>
 *
 * @param array parameters
 * @return string
 */
PHP_METHOD(Phalcon_Tag, dateField) {

	int ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL;
	zval *parameters, *_1;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &parameters);



	ZEPHIR_INIT_VAR(_1);
	ZVAL_STRING(_1, "date", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_RETURN_CALL_SELF("_inputfield", &_0, 430, _1, parameters);
	zephir_check_temp_parameter(_1);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Builds a HTML input[type="datetime"] tag
 *
 * @param array parameters
 * @return string
 */
PHP_METHOD(Phalcon_Tag, dateTimeField) {

	int ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL;
	zval *parameters, *_1;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &parameters);



	ZEPHIR_INIT_VAR(_1);
	ZVAL_STRING(_1, "datetime", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_RETURN_CALL_SELF("_inputfield", &_0, 430, _1, parameters);
	zephir_check_temp_parameter(_1);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Builds a HTML input[type="datetime-local"] tag
 *
 * @param array parameters
 * @return string
 */
PHP_METHOD(Phalcon_Tag, dateTimeLocalField) {

	int ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL;
	zval *parameters, *_1;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &parameters);



	ZEPHIR_INIT_VAR(_1);
	ZVAL_STRING(_1, "datetime-local", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_RETURN_CALL_SELF("_inputfield", &_0, 430, _1, parameters);
	zephir_check_temp_parameter(_1);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Builds a HTML input[type="month"] tag
 *
 * @param array parameters
 * @return string
 */
PHP_METHOD(Phalcon_Tag, monthField) {

	int ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL;
	zval *parameters, *_1;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &parameters);



	ZEPHIR_INIT_VAR(_1);
	ZVAL_STRING(_1, "month", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_RETURN_CALL_SELF("_inputfield", &_0, 430, _1, parameters);
	zephir_check_temp_parameter(_1);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Builds a HTML input[type="time"] tag
 *
 * @param array parameters
 * @return string
 */
PHP_METHOD(Phalcon_Tag, timeField) {

	int ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL;
	zval *parameters, *_1;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &parameters);



	ZEPHIR_INIT_VAR(_1);
	ZVAL_STRING(_1, "time", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_RETURN_CALL_SELF("_inputfield", &_0, 430, _1, parameters);
	zephir_check_temp_parameter(_1);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Builds a HTML input[type="week"] tag
 *
 * @param array parameters
 * @return string
 */
PHP_METHOD(Phalcon_Tag, weekField) {

	int ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL;
	zval *parameters, *_1;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &parameters);



	ZEPHIR_INIT_VAR(_1);
	ZVAL_STRING(_1, "week", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_RETURN_CALL_SELF("_inputfield", &_0, 430, _1, parameters);
	zephir_check_temp_parameter(_1);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Builds a HTML input[type="password"] tag
 *
 *<code>
 * echo Phalcon\Tag::passwordField(array("name", "size" => 30));
 *</code>
 *
 * @param array parameters
 * @return string
 */
PHP_METHOD(Phalcon_Tag, passwordField) {

	int ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL;
	zval *parameters, *_1;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &parameters);



	ZEPHIR_INIT_VAR(_1);
	ZVAL_STRING(_1, "password", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_RETURN_CALL_SELF("_inputfield", &_0, 430, _1, parameters);
	zephir_check_temp_parameter(_1);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Builds a HTML input[type="hidden"] tag
 *
 *<code>
 * echo Phalcon\Tag::hiddenField(array("name", "value" => "mike"));
 *</code>
 *
 * @param array parameters
 * @return string
 */
PHP_METHOD(Phalcon_Tag, hiddenField) {

	int ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL;
	zval *parameters, *_1;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &parameters);



	ZEPHIR_INIT_VAR(_1);
	ZVAL_STRING(_1, "hidden", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_RETURN_CALL_SELF("_inputfield", &_0, 430, _1, parameters);
	zephir_check_temp_parameter(_1);
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
 * @return string
 */
PHP_METHOD(Phalcon_Tag, fileField) {

	int ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL;
	zval *parameters, *_1;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &parameters);



	ZEPHIR_INIT_VAR(_1);
	ZVAL_STRING(_1, "file", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_RETURN_CALL_SELF("_inputfield", &_0, 430, _1, parameters);
	zephir_check_temp_parameter(_1);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Builds a HTML input[type="search"] tag
 *
 * @param array parameters
 * @return string
 */
PHP_METHOD(Phalcon_Tag, searchField) {

	int ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL;
	zval *parameters, *_1;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &parameters);



	ZEPHIR_INIT_VAR(_1);
	ZVAL_STRING(_1, "search", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_RETURN_CALL_SELF("_inputfield", &_0, 430, _1, parameters);
	zephir_check_temp_parameter(_1);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Builds a HTML input[type="tel"] tag
 *
 * @param array parameters
 * @return string
 */
PHP_METHOD(Phalcon_Tag, telField) {

	int ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL;
	zval *parameters, *_1;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &parameters);



	ZEPHIR_INIT_VAR(_1);
	ZVAL_STRING(_1, "tel", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_RETURN_CALL_SELF("_inputfield", &_0, 430, _1, parameters);
	zephir_check_temp_parameter(_1);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Builds a HTML input[type="url"] tag
 *
 * @param array parameters
 * @return string
 */
PHP_METHOD(Phalcon_Tag, urlField) {

	int ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL;
	zval *parameters, *_1;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &parameters);



	ZEPHIR_INIT_VAR(_1);
	ZVAL_STRING(_1, "url", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_RETURN_CALL_SELF("_inputfield", &_0, 430, _1, parameters);
	zephir_check_temp_parameter(_1);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Builds a HTML input[type="check"] tag
 *
 *<code>
 * echo Phalcon\Tag::checkField(array("terms", "value" => "Y"));
 *</code>
 *
 * Volt syntax:
 *<code>
 * {{ check_field("terms") }}
 *</code>
 *
 * @param array parameters
 * @return string
 */
PHP_METHOD(Phalcon_Tag, checkField) {

	int ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL;
	zval *parameters, *_1;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &parameters);



	ZEPHIR_INIT_VAR(_1);
	ZVAL_STRING(_1, "checkbox", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_RETURN_CALL_SELF("_inputfieldchecked", &_0, 431, _1, parameters);
	zephir_check_temp_parameter(_1);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Builds a HTML input[type="radio"] tag
 *
 *<code>
 * echo Phalcon\Tag::radioField(array("weather", "value" => "hot"))
 *</code>
 *
 * Volt syntax:
 *<code>
 * {{ radio_field("Save") }}
 *</code>
 *
 * @param array parameters
 * @return string
 */
PHP_METHOD(Phalcon_Tag, radioField) {

	int ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL;
	zval *parameters, *_1;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &parameters);



	ZEPHIR_INIT_VAR(_1);
	ZVAL_STRING(_1, "radio", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_RETURN_CALL_SELF("_inputfieldchecked", &_0, 431, _1, parameters);
	zephir_check_temp_parameter(_1);
	zephir_check_call_status();
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
 * @param array parameters
 * @return string
 */
PHP_METHOD(Phalcon_Tag, imageInput) {

	int ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL;
	zval *parameters, *_1, *_2;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &parameters);



	ZEPHIR_INIT_VAR(_1);
	ZVAL_STRING(_1, "image", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_INIT_VAR(_2);
	ZVAL_BOOL(_2, 1);
	ZEPHIR_RETURN_CALL_SELF("_inputfield", &_0, 430, _1, parameters, _2);
	zephir_check_temp_parameter(_1);
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
 * @return string
 */
PHP_METHOD(Phalcon_Tag, submitButton) {

	int ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL;
	zval *parameters, *_1, *_2;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &parameters);



	ZEPHIR_INIT_VAR(_1);
	ZVAL_STRING(_1, "submit", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_INIT_VAR(_2);
	ZVAL_BOOL(_2, 1);
	ZEPHIR_RETURN_CALL_SELF("_inputfield", &_0, 430, _1, parameters, _2);
	zephir_check_temp_parameter(_1);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Builds a HTML SELECT tag using a PHP array for options
 *
 *<code>
 * echo Phalcon\Tag::selectStatic("status", array("A" => "Active", "I" => "Inactive"))
 *</code>
 *
 * @param array parameters
 * @param array data
 * @return string
 */
PHP_METHOD(Phalcon_Tag, selectStatic) {

	int ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL;
	zval *parameters, *data = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &parameters, &data);

	if (!data) {
		data = ZEPHIR_GLOBAL(global_null);
	}


	ZEPHIR_RETURN_CALL_CE_STATIC(phalcon_tag_select_ce, "selectfield", &_0, 211, parameters, data);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Builds a HTML SELECT tag using a Phalcon\Mvc\Model resultset as options
 *
 *<code>
 * echo Phalcon\Tag::select([
 *     "robotId",
 *     Robots::find("type = "mechanical""),
 *     "using" => ["id", "name"]
 * ]);
 *</code>
 *
 * Volt syntax:
 *<code>
 * {{ select("robotId", robots, "using": ["id", "name"]) }}
 *</code>
 *
 * @param array parameters
 * @param array data
 * @return string
 */
PHP_METHOD(Phalcon_Tag, select) {

	int ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL;
	zval *parameters, *data = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &parameters, &data);

	if (!data) {
		data = ZEPHIR_GLOBAL(global_null);
	}


	ZEPHIR_RETURN_CALL_CE_STATIC(phalcon_tag_select_ce, "selectfield", &_0, 211, parameters, data);
	zephir_check_call_status();
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
 * @param array parameters
 * @return string
 */
PHP_METHOD(Phalcon_Tag, textArea) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *parameters, *params = NULL, *id = NULL, *name = NULL, *content = NULL, *code = NULL, *_1, *_2, *_0$$6;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &parameters);



	if (Z_TYPE_P(parameters) != IS_ARRAY) {
		ZEPHIR_INIT_VAR(params);
		zephir_create_array(params, 1, 0 TSRMLS_CC);
		zephir_array_fast_append(params, parameters);
	} else {
		ZEPHIR_CPY_WRT(params, parameters);
	}
	if (!(zephir_array_isset_long(params, 0))) {
		if (zephir_array_isset_string(params, SS("id"))) {
			zephir_array_fetch_string(&_0$$6, params, SL("id"), PH_NOISY | PH_READONLY, "phalcon/tag.zep", 937 TSRMLS_CC);
			zephir_array_update_long(&params, 0, &_0$$6, PH_COPY | PH_SEPARATE ZEPHIR_DEBUG_PARAMS_DUMMY);
		}
	}
	ZEPHIR_OBS_VAR(id);
	zephir_array_fetch_long(&id, params, 0, PH_NOISY, "phalcon/tag.zep", 941 TSRMLS_CC);
	if (!(zephir_array_isset_string(params, SS("name")))) {
		zephir_array_update_string(&params, SL("name"), &id, PH_COPY | PH_SEPARATE);
	} else {
		ZEPHIR_OBS_VAR(name);
		zephir_array_fetch_string(&name, params, SL("name"), PH_NOISY, "phalcon/tag.zep", 945 TSRMLS_CC);
		if (ZEPHIR_IS_EMPTY(name)) {
			zephir_array_update_string(&params, SL("name"), &id, PH_COPY | PH_SEPARATE);
		}
	}
	if (!(zephir_array_isset_string(params, SS("id")))) {
		zephir_array_update_string(&params, SL("id"), &id, PH_COPY | PH_SEPARATE);
	}
	if (zephir_array_isset_string(params, SS("value"))) {
		ZEPHIR_OBS_VAR(content);
		zephir_array_fetch_string(&content, params, SL("value"), PH_NOISY, "phalcon/tag.zep", 956 TSRMLS_CC);
		zephir_array_unset_string(&params, SS("value"), PH_SEPARATE);
	} else {
		ZEPHIR_CALL_SELF(&content, "getvalue", NULL, 0, id, params);
		zephir_check_call_status();
	}
	ZEPHIR_INIT_VAR(_1);
	ZVAL_STRING(_1, "<textarea", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_SELF(&code, "renderattributes", NULL, 0, _1, params);
	zephir_check_temp_parameter(_1);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_2);
	ZEPHIR_CONCAT_SVS(_2, ">", content, "</textarea>");
	zephir_concat_self(&code, _2 TSRMLS_CC);
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

	int ZEPHIR_LAST_CALL_STATUS;
	zval *parameters = NULL, *params = NULL, *paramsAction = NULL, *action = NULL, *code = NULL, *_3, *_0$$6, *_1$$7 = NULL, *_2$$8;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &parameters);

	ZEPHIR_SEPARATE_PARAM(parameters);


	if (Z_TYPE_P(parameters) != IS_ARRAY) {
		ZEPHIR_INIT_VAR(params);
		zephir_create_array(params, 1, 0 TSRMLS_CC);
		zephir_array_fast_append(params, parameters);
	} else {
		ZEPHIR_CPY_WRT(params, parameters);
	}
	ZEPHIR_OBS_VAR(paramsAction);
	if (!(zephir_array_isset_long_fetch(&paramsAction, params, 0, 0 TSRMLS_CC))) {
		ZEPHIR_OBS_NVAR(paramsAction);
		zephir_array_isset_string_fetch(&paramsAction, params, SS("action"), 0 TSRMLS_CC);
	}
	if (!(zephir_array_isset_string(params, SS("method")))) {
		ZEPHIR_INIT_VAR(_0$$6);
		ZVAL_STRING(_0$$6, "post", 1);
		zephir_array_update_string(&params, SL("method"), &_0$$6, PH_COPY | PH_SEPARATE);
	}
	ZEPHIR_INIT_VAR(action);
	ZVAL_NULL(action);
	if (!(ZEPHIR_IS_EMPTY(paramsAction))) {
		ZEPHIR_CALL_SELF(&_1$$7, "geturlservice", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&action, _1$$7, "get", NULL, 0, paramsAction);
		zephir_check_call_status();
	}
	ZEPHIR_OBS_NVAR(parameters);
	if (zephir_array_isset_string_fetch(&parameters, params, SS("parameters"), 0 TSRMLS_CC)) {
		ZEPHIR_INIT_VAR(_2$$8);
		ZEPHIR_CONCAT_SV(_2$$8, "?", parameters);
		zephir_concat_self(&action, _2$$8 TSRMLS_CC);
	}
	if (!(ZEPHIR_IS_EMPTY(action))) {
		zephir_array_update_string(&params, SL("action"), &action, PH_COPY | PH_SEPARATE);
	}
	ZEPHIR_INIT_VAR(_3);
	ZVAL_STRING(_3, "<form", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_SELF(&code, "renderattributes", NULL, 0, _3, params);
	zephir_check_temp_parameter(_3);
	zephir_check_call_status();
	zephir_concat_self_str(&code, SL(">") TSRMLS_CC);
	RETURN_CCTOR(code);

}

/**
 * Builds a HTML close FORM tag
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
 */
PHP_METHOD(Phalcon_Tag, setTitle) {

	zval *title_param = NULL;
	zval *title = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &title_param);

	zephir_get_strval(title, title_param);


	zephir_update_static_property_ce(phalcon_tag_ce, SL("_documentTitle"), &title TSRMLS_CC);
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
	zval *titleSeparator = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &titleSeparator_param);

	zephir_get_strval(titleSeparator, titleSeparator_param);


	zephir_update_static_property_ce(phalcon_tag_ce, SL("_documentTitleSeparator"), &titleSeparator TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

/**
 * Appends a text to current document title
 */
PHP_METHOD(Phalcon_Tag, appendTitle) {

	zval *title_param = NULL;
	zval *title = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &title_param);

	zephir_get_strval(title, title_param);


	zephir_update_static_property_ce(phalcon_tag_ce, SL("_documentAppendTitle"), &title TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

/**
 * Prepends a text to current document title
 */
PHP_METHOD(Phalcon_Tag, prependTitle) {

	zval *title_param = NULL;
	zval *title = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &title_param);

	zephir_get_strval(title, title_param);


	zephir_update_static_property_ce(phalcon_tag_ce, SL("_documentPrependTitle"), &title TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

/**
 * Gets the current document title.
 * The title will be automatically escaped.
 *
 * <code>
 * echo Phalcon\Tag::getTitle();
 * </code>
 *
 * <code>
 * {{ get_title() }}
 * </code>
 */
PHP_METHOD(Phalcon_Tag, getTitle) {

	zval *_1;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *tags_param = NULL, *items = NULL, *output = NULL, *documentTitle = NULL, *documentAppendTitle = NULL, *documentPrependTitle = NULL, *documentTitleSeparator = NULL, *escaper = NULL, *_0 = NULL, *_2, *_3, *_4, *_5, *_6$$8;
	zend_bool tags;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &tags_param);

	if (!tags_param) {
		tags = 1;
	} else {
		tags = zephir_get_boolval(tags_param);
	}


	ZEPHIR_INIT_VAR(_1);
	zephir_create_array(_1, 1, 0 TSRMLS_CC);
	zephir_array_update_string(&_1, SL("escape"), &ZEPHIR_GLOBAL(global_true), PH_COPY | PH_SEPARATE);
	ZEPHIR_CALL_SELF(&_0, "getescaper", NULL, 0, _1);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(escaper, _0);
	ZEPHIR_INIT_VAR(items);
	array_init(items);
	ZEPHIR_INIT_VAR(output);
	ZVAL_STRING(output, "", 1);
	_2 = zephir_fetch_static_property_ce(phalcon_tag_ce, SL("_documentPrependTitle") TSRMLS_CC);
	ZEPHIR_CALL_METHOD(&documentPrependTitle, escaper, "escapehtml", NULL, 0, _2);
	zephir_check_call_status();
	_3 = zephir_fetch_static_property_ce(phalcon_tag_ce, SL("_documentTitle") TSRMLS_CC);
	ZEPHIR_CALL_METHOD(&documentTitle, escaper, "escapehtml", NULL, 0, _3);
	zephir_check_call_status();
	_4 = zephir_fetch_static_property_ce(phalcon_tag_ce, SL("_documentAppendTitle") TSRMLS_CC);
	ZEPHIR_CALL_METHOD(&documentAppendTitle, escaper, "escapehtml", NULL, 0, _4);
	zephir_check_call_status();
	_5 = zephir_fetch_static_property_ce(phalcon_tag_ce, SL("_documentTitleSeparator") TSRMLS_CC);
	ZEPHIR_CALL_METHOD(&documentTitleSeparator, escaper, "escapehtml", NULL, 0, _5);
	zephir_check_call_status();
	if (!(ZEPHIR_IS_EMPTY(documentPrependTitle))) {
		zephir_array_append(&items, documentPrependTitle, PH_SEPARATE, "phalcon/tag.zep", 1102);
	}
	if (!(ZEPHIR_IS_EMPTY(documentTitle))) {
		zephir_array_append(&items, documentTitle, PH_SEPARATE, "phalcon/tag.zep", 1106);
	}
	if (!(ZEPHIR_IS_EMPTY(documentAppendTitle))) {
		zephir_array_append(&items, documentAppendTitle, PH_SEPARATE, "phalcon/tag.zep", 1110);
	}
	if (ZEPHIR_IS_EMPTY(documentTitleSeparator)) {
		ZEPHIR_INIT_NVAR(documentTitleSeparator);
		ZVAL_STRING(documentTitleSeparator, "", 1);
	}
	if (!(ZEPHIR_IS_EMPTY(items))) {
		ZEPHIR_INIT_NVAR(output);
		zephir_fast_join(output, documentTitleSeparator, items TSRMLS_CC);
	}
	if (tags) {
		ZEPHIR_INIT_VAR(_6$$8);
		ZEPHIR_GET_CONSTANT(_6$$8, "PHP_EOL");
		ZEPHIR_CONCAT_SVSV(return_value, "<title>", output, "</title>", _6$$8);
		RETURN_MM();
	}
	RETURN_CCTOR(output);

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

	zval *_0;


	_0 = zephir_fetch_static_property_ce(phalcon_tag_ce, SL("_documentTitleSeparator") TSRMLS_CC);
	RETURN_CTORW(_0);

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
 * @param boolean local
 * @return string
 */
PHP_METHOD(Phalcon_Tag, stylesheetLink) {

	int ZEPHIR_LAST_CALL_STATUS;
	zend_bool local;
	zval *parameters = NULL, *local_param = NULL, *params = NULL, *code = NULL, *_10, *_11, *_0$$3, *_1$$5, *_2$$7, *_3$$8, *_4$$10, *_5$$11, *_6$$12 = NULL, *_7$$12 = NULL, *_8$$12, *_9$$13, *_12$$14, *_13$$14, *_14$$15, *_15$$15;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 2, &parameters, &local_param);

	if (!parameters) {
		parameters = ZEPHIR_GLOBAL(global_null);
	}
	if (!local_param) {
		local = 1;
	} else {
		local = zephir_get_boolval(local_param);
	}


	if (Z_TYPE_P(parameters) != IS_ARRAY) {
		ZEPHIR_INIT_VAR(params);
		zephir_create_array(params, 2, 0 TSRMLS_CC);
		zephir_array_fast_append(params, parameters);
		ZEPHIR_INIT_VAR(_0$$3);
		ZVAL_BOOL(_0$$3, local);
		zephir_array_fast_append(params, _0$$3);
	} else {
		ZEPHIR_CPY_WRT(params, parameters);
	}
	if (zephir_array_isset_long(params, 1)) {
		ZEPHIR_OBS_VAR(_1$$5);
		zephir_array_fetch_long(&_1$$5, params, 1, PH_NOISY, "phalcon/tag.zep", 1173 TSRMLS_CC);
		local = zephir_get_boolval(_1$$5);
	} else {
		if (zephir_array_isset_string(params, SS("local"))) {
			ZEPHIR_OBS_VAR(_2$$7);
			zephir_array_fetch_string(&_2$$7, params, SL("local"), PH_NOISY, "phalcon/tag.zep", 1176 TSRMLS_CC);
			local = zephir_get_boolval(_2$$7);
			zephir_array_unset_string(&params, SS("local"), PH_SEPARATE);
		}
	}
	if (!(zephir_array_isset_string(params, SS("type")))) {
		ZEPHIR_INIT_VAR(_3$$8);
		ZVAL_STRING(_3$$8, "text/css", 1);
		zephir_array_update_string(&params, SL("type"), &_3$$8, PH_COPY | PH_SEPARATE);
	}
	if (!(zephir_array_isset_string(params, SS("href")))) {
		if (zephir_array_isset_long(params, 0)) {
			zephir_array_fetch_long(&_4$$10, params, 0, PH_NOISY | PH_READONLY, "phalcon/tag.zep", 1187 TSRMLS_CC);
			zephir_array_update_string(&params, SL("href"), &_4$$10, PH_COPY | PH_SEPARATE);
		} else {
			ZEPHIR_INIT_VAR(_5$$11);
			ZVAL_STRING(_5$$11, "", 1);
			zephir_array_update_string(&params, SL("href"), &_5$$11, PH_COPY | PH_SEPARATE);
		}
	}
	if (local == 1) {
		ZEPHIR_CALL_SELF(&_6$$12, "geturlservice", NULL, 0);
		zephir_check_call_status();
		zephir_array_fetch_string(&_8$$12, params, SL("href"), PH_NOISY | PH_READONLY, "phalcon/tag.zep", 1197 TSRMLS_CC);
		ZEPHIR_CALL_METHOD(&_7$$12, _6$$12, "getstatic", NULL, 0, _8$$12);
		zephir_check_call_status();
		zephir_array_update_string(&params, SL("href"), &_7$$12, PH_COPY | PH_SEPARATE);
	}
	if (!(zephir_array_isset_string(params, SS("rel")))) {
		ZEPHIR_INIT_VAR(_9$$13);
		ZVAL_STRING(_9$$13, "stylesheet", 1);
		zephir_array_update_string(&params, SL("rel"), &_9$$13, PH_COPY | PH_SEPARATE);
	}
	ZEPHIR_INIT_VAR(_10);
	ZVAL_STRING(_10, "<link", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_SELF(&code, "renderattributes", NULL, 0, _10, params);
	zephir_check_temp_parameter(_10);
	zephir_check_call_status();
	_11 = zephir_fetch_static_property_ce(phalcon_tag_ce, SL("_documentType") TSRMLS_CC);
	if (ZEPHIR_GT_LONG(_11, 5)) {
		ZEPHIR_INIT_VAR(_12$$14);
		ZEPHIR_GET_CONSTANT(_12$$14, "PHP_EOL");
		ZEPHIR_INIT_VAR(_13$$14);
		ZEPHIR_CONCAT_SV(_13$$14, " />", _12$$14);
		zephir_concat_self(&code, _13$$14 TSRMLS_CC);
	} else {
		ZEPHIR_INIT_VAR(_14$$15);
		ZEPHIR_GET_CONSTANT(_14$$15, "PHP_EOL");
		ZEPHIR_INIT_VAR(_15$$15);
		ZEPHIR_CONCAT_SV(_15$$15, ">", _14$$15);
		zephir_concat_self(&code, _15$$15 TSRMLS_CC);
	}
	RETURN_CCTOR(code);

}

/**
 * Builds a SCRIPT[type="javascript"] tag
 *
 * <code>
 * echo Phalcon\Tag::javascriptInclude("http://ajax.googleapis.com/ajax/libs/jquery/1.7.1/jquery.min.js", false);
 * echo Phalcon\Tag::javascriptInclude("javascript/jquery.js");
 * </code>
 *
 * Volt syntax:
 * <code>
 * {{ javascript_include("http://ajax.googleapis.com/ajax/libs/jquery/1.7.1/jquery.min.js", false) }}
 * {{ javascript_include("javascript/jquery.js") }}
 * </code>
 *
 * @param array parameters
 * @param boolean local
 * @return string
 */
PHP_METHOD(Phalcon_Tag, javascriptInclude) {

	int ZEPHIR_LAST_CALL_STATUS;
	zend_bool local;
	zval *parameters = NULL, *local_param = NULL, *params = NULL, *code = NULL, *_9 = NULL, *_10, *_0$$3, *_1$$5, *_2$$7, *_3$$8, *_4$$10, *_5$$11, *_6$$12 = NULL, *_7$$12 = NULL, *_8$$12;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 2, &parameters, &local_param);

	if (!parameters) {
		parameters = ZEPHIR_GLOBAL(global_null);
	}
	if (!local_param) {
		local = 1;
	} else {
		local = zephir_get_boolval(local_param);
	}


	if (Z_TYPE_P(parameters) != IS_ARRAY) {
		ZEPHIR_INIT_VAR(params);
		zephir_create_array(params, 2, 0 TSRMLS_CC);
		zephir_array_fast_append(params, parameters);
		ZEPHIR_INIT_VAR(_0$$3);
		ZVAL_BOOL(_0$$3, local);
		zephir_array_fast_append(params, _0$$3);
	} else {
		ZEPHIR_CPY_WRT(params, parameters);
	}
	if (zephir_array_isset_long(params, 1)) {
		ZEPHIR_OBS_VAR(_1$$5);
		zephir_array_fetch_long(&_1$$5, params, 1, PH_NOISY, "phalcon/tag.zep", 1247 TSRMLS_CC);
		local = zephir_get_boolval(_1$$5);
	} else {
		if (zephir_array_isset_string(params, SS("local"))) {
			ZEPHIR_OBS_VAR(_2$$7);
			zephir_array_fetch_string(&_2$$7, params, SL("local"), PH_NOISY, "phalcon/tag.zep", 1250 TSRMLS_CC);
			local = zephir_get_boolval(_2$$7);
			zephir_array_unset_string(&params, SS("local"), PH_SEPARATE);
		}
	}
	if (!(zephir_array_isset_string(params, SS("type")))) {
		ZEPHIR_INIT_VAR(_3$$8);
		ZVAL_STRING(_3$$8, "text/javascript", 1);
		zephir_array_update_string(&params, SL("type"), &_3$$8, PH_COPY | PH_SEPARATE);
	}
	if (!(zephir_array_isset_string(params, SS("src")))) {
		if (zephir_array_isset_long(params, 0)) {
			zephir_array_fetch_long(&_4$$10, params, 0, PH_NOISY | PH_READONLY, "phalcon/tag.zep", 1261 TSRMLS_CC);
			zephir_array_update_string(&params, SL("src"), &_4$$10, PH_COPY | PH_SEPARATE);
		} else {
			ZEPHIR_INIT_VAR(_5$$11);
			ZVAL_STRING(_5$$11, "", 1);
			zephir_array_update_string(&params, SL("src"), &_5$$11, PH_COPY | PH_SEPARATE);
		}
	}
	if (local == 1) {
		ZEPHIR_CALL_SELF(&_6$$12, "geturlservice", NULL, 0);
		zephir_check_call_status();
		zephir_array_fetch_string(&_8$$12, params, SL("src"), PH_NOISY | PH_READONLY, "phalcon/tag.zep", 1271 TSRMLS_CC);
		ZEPHIR_CALL_METHOD(&_7$$12, _6$$12, "getstatic", NULL, 0, _8$$12);
		zephir_check_call_status();
		zephir_array_update_string(&params, SL("src"), &_7$$12, PH_COPY | PH_SEPARATE);
	}
	ZEPHIR_INIT_VAR(_9);
	ZVAL_STRING(_9, "<script", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_SELF(&code, "renderattributes", NULL, 0, _9, params);
	zephir_check_temp_parameter(_9);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(_9);
	ZEPHIR_GET_CONSTANT(_9, "PHP_EOL");
	ZEPHIR_INIT_VAR(_10);
	ZEPHIR_CONCAT_SV(_10, "></script>", _9);
	zephir_concat_self(&code, _10 TSRMLS_CC);
	RETURN_CCTOR(code);

}

/**
 * Builds HTML IMG tags
 *
 * <code>
 * echo Phalcon\Tag::image("img/bg.png");
 * echo Phalcon\Tag::image(array("img/photo.jpg", "alt" => "Some Photo"));
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
 * @param  boolean local
 * @return string
 */
PHP_METHOD(Phalcon_Tag, image) {

	int ZEPHIR_LAST_CALL_STATUS;
	zend_bool local;
	zval *parameters = NULL, *local_param = NULL, *params = NULL, *code = NULL, *src = NULL, *_5, *_6, *_0$$5, *_1$$8, *_2$$9 = NULL, *_3$$9 = NULL, *_4$$9;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 2, &parameters, &local_param);

	if (!parameters) {
		parameters = ZEPHIR_GLOBAL(global_null);
	}
	if (!local_param) {
		local = 1;
	} else {
		local = zephir_get_boolval(local_param);
	}


	if (Z_TYPE_P(parameters) != IS_ARRAY) {
		ZEPHIR_INIT_VAR(params);
		zephir_create_array(params, 1, 0 TSRMLS_CC);
		zephir_array_fast_append(params, parameters);
	} else {
		ZEPHIR_CPY_WRT(params, parameters);
		if (zephir_array_isset_long(params, 1)) {
			ZEPHIR_OBS_VAR(_0$$5);
			zephir_array_fetch_long(&_0$$5, params, 1, PH_NOISY, "phalcon/tag.zep", 1308 TSRMLS_CC);
			local = zephir_get_boolval(_0$$5);
		}
	}
	if (!(zephir_array_isset_string(params, SS("src")))) {
		ZEPHIR_OBS_VAR(src);
		if (zephir_array_isset_long_fetch(&src, params, 0, 0 TSRMLS_CC)) {
			zephir_array_update_string(&params, SL("src"), &src, PH_COPY | PH_SEPARATE);
		} else {
			ZEPHIR_INIT_VAR(_1$$8);
			ZVAL_STRING(_1$$8, "", 1);
			zephir_array_update_string(&params, SL("src"), &_1$$8, PH_COPY | PH_SEPARATE);
		}
	}
	if (local) {
		ZEPHIR_CALL_SELF(&_2$$9, "geturlservice", NULL, 0);
		zephir_check_call_status();
		zephir_array_fetch_string(&_4$$9, params, SL("src"), PH_NOISY | PH_READONLY, "phalcon/tag.zep", 1324 TSRMLS_CC);
		ZEPHIR_CALL_METHOD(&_3$$9, _2$$9, "getstatic", NULL, 0, _4$$9);
		zephir_check_call_status();
		zephir_array_update_string(&params, SL("src"), &_3$$9, PH_COPY | PH_SEPARATE);
	}
	ZEPHIR_INIT_VAR(_5);
	ZVAL_STRING(_5, "<img", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_SELF(&code, "renderattributes", NULL, 0, _5, params);
	zephir_check_temp_parameter(_5);
	zephir_check_call_status();
	_6 = zephir_fetch_static_property_ce(phalcon_tag_ce, SL("_documentType") TSRMLS_CC);
	if (ZEPHIR_GT_LONG(_6, 5)) {
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
 */
PHP_METHOD(Phalcon_Tag, friendlyTitle) {

	HashTable *_9$$6;
	HashPosition _8$$6;
	int ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_2 = NULL, *_5 = NULL, *_17 = NULL;
	zend_bool lowercase, _7$$4;
	zval *text_param = NULL, *separator_param = NULL, *lowercase_param = NULL, *replace = NULL, *friendly = NULL, *locale = NULL, *search = NULL, _0 = zval_used_for_init, *_1 = NULL, *_15 = NULL, *_16, *_19 = NULL, _3$$3 = zval_used_for_init, _4$$3 = zval_used_for_init, *_6$$3 = NULL, **_10$$6, *_11$$7 = NULL, _12$$7 = zval_used_for_init, *_13$$8, _14$$8, *_18$$9, _20$$10;
	zval *text = NULL, *separator = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 3, &text_param, &separator_param, &lowercase_param, &replace);

	zephir_get_strval(text, text_param);
	if (!separator_param) {
		ZEPHIR_INIT_VAR(separator);
		ZVAL_STRING(separator, "-", 1);
	} else {
		zephir_get_strval(separator, separator_param);
	}
	if (!lowercase_param) {
		lowercase = 1;
	} else {
		lowercase = zephir_get_boolval(lowercase_param);
	}
	if (!replace) {
		replace = ZEPHIR_GLOBAL(global_null);
	}


	ZEPHIR_SINIT_VAR(_0);
	ZVAL_STRING(&_0, "iconv", 0);
	ZEPHIR_CALL_FUNCTION(&_1, "extension_loaded", &_2, 134, &_0);
	zephir_check_call_status();
	if (zephir_is_true(_1)) {
		ZEPHIR_SINIT_VAR(_3$$3);
		ZVAL_LONG(&_3$$3, 0);
		ZEPHIR_SINIT_VAR(_4$$3);
		ZVAL_STRING(&_4$$3, "en_US.UTF-8", 0);
		ZEPHIR_CALL_FUNCTION(&locale, "setlocale", &_5, 432, &_3$$3, &_4$$3);
		zephir_check_call_status();
		ZEPHIR_SINIT_NVAR(_3$$3);
		ZVAL_STRING(&_3$$3, "UTF-8", 0);
		ZEPHIR_SINIT_NVAR(_4$$3);
		ZVAL_STRING(&_4$$3, "ASCII//TRANSLIT", 0);
		ZEPHIR_CALL_FUNCTION(&_6$$3, "iconv", NULL, 386, &_3$$3, &_4$$3, text);
		zephir_check_call_status();
		zephir_get_strval(text, _6$$3);
	}
	if (zephir_is_true(replace)) {
		_7$$4 = Z_TYPE_P(replace) != IS_ARRAY;
		if (_7$$4) {
			_7$$4 = Z_TYPE_P(replace) != IS_STRING;
		}
		if (_7$$4) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_tag_exception_ce, "Parameter replace must be an array or a string", "phalcon/tag.zep", 1363);
			return;
		}
		if (Z_TYPE_P(replace) == IS_ARRAY) {
			zephir_is_iterable(replace, &_9$$6, &_8$$6, 0, 0, "phalcon/tag.zep", 1369);
			for (
			  ; zephir_hash_get_current_data_ex(_9$$6, (void**) &_10$$6, &_8$$6) == SUCCESS
			  ; zephir_hash_move_forward_ex(_9$$6, &_8$$6)
			) {
				ZEPHIR_GET_HVALUE(search, _10$$6);
				ZEPHIR_INIT_NVAR(_11$$7);
				ZEPHIR_SINIT_NVAR(_12$$7);
				ZVAL_STRING(&_12$$7, " ", 0);
				zephir_fast_str_replace(&_11$$7, search, &_12$$7, text TSRMLS_CC);
				zephir_get_strval(text, _11$$7);
			}
		} else {
			ZEPHIR_INIT_VAR(_13$$8);
			ZEPHIR_SINIT_VAR(_14$$8);
			ZVAL_STRING(&_14$$8, " ", 0);
			zephir_fast_str_replace(&_13$$8, replace, &_14$$8, text TSRMLS_CC);
			zephir_get_strval(text, _13$$8);
		}
	}
	ZEPHIR_INIT_VAR(_15);
	ZVAL_STRING(_15, "/[^a-zA-Z0-9\\/_|+ -]/", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_INIT_VAR(_16);
	ZVAL_STRING(_16, "", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_FUNCTION(&friendly, "preg_replace", &_17, 29, _15, _16, text);
	zephir_check_temp_parameter(_15);
	zephir_check_temp_parameter(_16);
	zephir_check_call_status();
	if (lowercase) {
		ZEPHIR_INIT_VAR(_18$$9);
		zephir_fast_strtolower(_18$$9, friendly);
		ZEPHIR_CPY_WRT(friendly, _18$$9);
	}
	ZEPHIR_INIT_NVAR(_15);
	ZVAL_STRING(_15, "/[\\/_|+ -]+/", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_FUNCTION(&_19, "preg_replace", &_17, 29, _15, separator, friendly);
	zephir_check_temp_parameter(_15);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(friendly, _19);
	ZEPHIR_INIT_NVAR(_15);
	zephir_fast_trim(_15, friendly, separator, ZEPHIR_TRIM_BOTH TSRMLS_CC);
	ZEPHIR_CPY_WRT(friendly, _15);
	ZEPHIR_SINIT_NVAR(_0);
	ZVAL_STRING(&_0, "iconv", 0);
	ZEPHIR_CALL_FUNCTION(&_19, "extension_loaded", &_2, 134, &_0);
	zephir_check_call_status();
	if (zephir_is_true(_19)) {
		ZEPHIR_SINIT_VAR(_20$$10);
		ZVAL_LONG(&_20$$10, 0);
		ZEPHIR_CALL_FUNCTION(NULL, "setlocale", &_5, 432, &_20$$10, locale);
		zephir_check_call_status();
	}
	RETURN_CCTOR(friendly);

}

/**
 * Set the document type of content
 */
PHP_METHOD(Phalcon_Tag, setDocType) {

	zend_bool _0;
	zval *doctype_param = NULL, *_1$$3, *_2$$4;
	int doctype;

	zephir_fetch_params(0, 1, 0, &doctype_param);

	doctype = zephir_get_intval(doctype_param);


	_0 = doctype < 1;
	if (!(_0)) {
		_0 = doctype > 11;
	}
	if (_0) {
		ZEPHIR_INIT_ZVAL_NREF(_1$$3);
		ZVAL_LONG(_1$$3, 5);
		zephir_update_static_property_ce(phalcon_tag_ce, SL("_documentType"), &_1$$3 TSRMLS_CC);
	} else {
		ZEPHIR_INIT_ZVAL_NREF(_2$$4);
		ZVAL_LONG(_2$$4, doctype);
		zephir_update_static_property_ce(phalcon_tag_ce, SL("_documentType"), &_2$$4 TSRMLS_CC);
	}

}

/**
 * Get the document type declaration of content
 */
PHP_METHOD(Phalcon_Tag, getDocType) {

	zval *_0, *_1$$3, *_2$$4, *_3$$4, *_4$$5, *_5$$5, *_6$$6, *_7$$6, *_8$$7, *_9$$7, *_10$$8, *_11$$8, *_12$$9, *_13$$9, *_14$$10, *_15$$10, *_16$$11, *_17$$11, *_18$$12;

	ZEPHIR_MM_GROW();

	_0 = zephir_fetch_static_property_ce(phalcon_tag_ce, SL("_documentType") TSRMLS_CC);
	do {
		if (ZEPHIR_IS_LONG(_0, 1)) {
			ZEPHIR_INIT_VAR(_1$$3);
			ZEPHIR_GET_CONSTANT(_1$$3, "PHP_EOL");
			ZEPHIR_CONCAT_SV(return_value, "<!DOCTYPE html PUBLIC \"-//W3C//DTD HTML 3.2 Final//EN\">", _1$$3);
			RETURN_MM();
		}
		if (ZEPHIR_IS_LONG(_0, 2)) {
			ZEPHIR_INIT_VAR(_2$$4);
			ZEPHIR_GET_CONSTANT(_2$$4, "PHP_EOL");
			ZEPHIR_INIT_VAR(_3$$4);
			ZEPHIR_GET_CONSTANT(_3$$4, "PHP_EOL");
			ZEPHIR_CONCAT_SVSV(return_value, "<!DOCTYPE html PUBLIC \"-//W3C//DTD HTML 4.01//EN\"", _2$$4, "\t\"http://www.w3.org/TR/html4/strict.dtd\">", _3$$4);
			RETURN_MM();
		}
		if (ZEPHIR_IS_LONG(_0, 3)) {
			ZEPHIR_INIT_VAR(_4$$5);
			ZEPHIR_GET_CONSTANT(_4$$5, "PHP_EOL");
			ZEPHIR_INIT_VAR(_5$$5);
			ZEPHIR_GET_CONSTANT(_5$$5, "PHP_EOL");
			ZEPHIR_CONCAT_SVSV(return_value, "<!DOCTYPE html PUBLIC \"-//W3C//DTD HTML 4.01 Transitional//EN\"", _4$$5, "\t\"http://www.w3.org/TR/html4/loose.dtd\">", _5$$5);
			RETURN_MM();
		}
		if (ZEPHIR_IS_LONG(_0, 4)) {
			ZEPHIR_INIT_VAR(_6$$6);
			ZEPHIR_GET_CONSTANT(_6$$6, "PHP_EOL");
			ZEPHIR_INIT_VAR(_7$$6);
			ZEPHIR_GET_CONSTANT(_7$$6, "PHP_EOL");
			ZEPHIR_CONCAT_SVSV(return_value, "<!DOCTYPE html PUBLIC \"-//W3C//DTD HTML 4.01 Frameset//EN\"", _6$$6, "\t\"http://www.w3.org/TR/html4/frameset.dtd\">", _7$$6);
			RETURN_MM();
		}
		if (ZEPHIR_IS_LONG(_0, 6)) {
			ZEPHIR_INIT_VAR(_8$$7);
			ZEPHIR_GET_CONSTANT(_8$$7, "PHP_EOL");
			ZEPHIR_INIT_VAR(_9$$7);
			ZEPHIR_GET_CONSTANT(_9$$7, "PHP_EOL");
			ZEPHIR_CONCAT_SVSV(return_value, "<!DOCTYPE html PUBLIC \"-//W3C//DTD XHTML 1.0 Strict//EN\"", _8$$7, "\t\"http://www.w3.org/TR/xhtml1/DTD/xhtml1-strict.dtd\">", _9$$7);
			RETURN_MM();
		}
		if (ZEPHIR_IS_LONG(_0, 7)) {
			ZEPHIR_INIT_VAR(_10$$8);
			ZEPHIR_GET_CONSTANT(_10$$8, "PHP_EOL");
			ZEPHIR_INIT_VAR(_11$$8);
			ZEPHIR_GET_CONSTANT(_11$$8, "PHP_EOL");
			ZEPHIR_CONCAT_SVSV(return_value, "<!DOCTYPE html PUBLIC \"-//W3C//DTD XHTML 1.0 Transitional//EN\"", _10$$8, "\t\"http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd\">", _11$$8);
			RETURN_MM();
		}
		if (ZEPHIR_IS_LONG(_0, 8)) {
			ZEPHIR_INIT_VAR(_12$$9);
			ZEPHIR_GET_CONSTANT(_12$$9, "PHP_EOL");
			ZEPHIR_INIT_VAR(_13$$9);
			ZEPHIR_GET_CONSTANT(_13$$9, "PHP_EOL");
			ZEPHIR_CONCAT_SVSV(return_value, "<!DOCTYPE html PUBLIC \"-//W3C//DTD XHTML 1.0 Frameset//EN\"", _12$$9, "\t\"http://www.w3.org/TR/xhtml1/DTD/xhtml1-frameset.dtd\">", _13$$9);
			RETURN_MM();
		}
		if (ZEPHIR_IS_LONG(_0, 9)) {
			ZEPHIR_INIT_VAR(_14$$10);
			ZEPHIR_GET_CONSTANT(_14$$10, "PHP_EOL");
			ZEPHIR_INIT_VAR(_15$$10);
			ZEPHIR_GET_CONSTANT(_15$$10, "PHP_EOL");
			ZEPHIR_CONCAT_SVSV(return_value, "<!DOCTYPE html PUBLIC \"-//W3C//DTD XHTML 1.1//EN\"", _14$$10, "\t\"http://www.w3.org/TR/xhtml11/DTD/xhtml11.dtd\">", _15$$10);
			RETURN_MM();
		}
		if (ZEPHIR_IS_LONG(_0, 10)) {
			ZEPHIR_INIT_VAR(_16$$11);
			ZEPHIR_GET_CONSTANT(_16$$11, "PHP_EOL");
			ZEPHIR_INIT_VAR(_17$$11);
			ZEPHIR_GET_CONSTANT(_17$$11, "PHP_EOL");
			ZEPHIR_CONCAT_SVSV(return_value, "<!DOCTYPE html PUBLIC \"-//W3C//DTD XHTML 2.0//EN\"", _16$$11, "\t\"http://www.w3.org/MarkUp/DTD/xhtml2.dtd\">", _17$$11);
			RETURN_MM();
		}
		if (ZEPHIR_IS_LONG(_0, 5) || ZEPHIR_IS_LONG(_0, 11)) {
			ZEPHIR_INIT_VAR(_18$$12);
			ZEPHIR_GET_CONSTANT(_18$$12, "PHP_EOL");
			ZEPHIR_CONCAT_SV(return_value, "<!DOCTYPE html>", _18$$12);
			RETURN_MM();
		}
	} while(0);

	RETURN_MM_STRING("", 1);

}

/**
 * Builds a HTML tag
 *
 *<code>
 * echo Phalcon\Tag::tagHtml(name, parameters, selfClose, onlyStart, eol);
 *</code>
 */
PHP_METHOD(Phalcon_Tag, tagHtml) {

	int ZEPHIR_LAST_CALL_STATUS;
	zend_bool selfClose, onlyStart, useEol;
	zval *tagName_param = NULL, *parameters = NULL, *selfClose_param = NULL, *onlyStart_param = NULL, *useEol_param = NULL, *params = NULL, *localCode = NULL, *_1, *_3$$11;
	zval *tagName = NULL, *_0, *_2$$10;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 4, &tagName_param, &parameters, &selfClose_param, &onlyStart_param, &useEol_param);

	zephir_get_strval(tagName, tagName_param);
	if (!parameters) {
		parameters = ZEPHIR_GLOBAL(global_null);
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
		ZEPHIR_INIT_VAR(params);
		zephir_create_array(params, 1, 0 TSRMLS_CC);
		zephir_array_fast_append(params, parameters);
	} else {
		ZEPHIR_CPY_WRT(params, parameters);
	}
	ZEPHIR_INIT_VAR(_0);
	ZEPHIR_CONCAT_SV(_0, "<", tagName);
	ZEPHIR_CALL_SELF(&localCode, "renderattributes", NULL, 0, _0, params);
	zephir_check_call_status();
	_1 = zephir_fetch_static_property_ce(phalcon_tag_ce, SL("_documentType") TSRMLS_CC);
	if (ZEPHIR_GT_LONG(_1, 5)) {
		if (selfClose) {
			zephir_concat_self_str(&localCode, SL(" />") TSRMLS_CC);
		} else {
			zephir_concat_self_str(&localCode, SL(">") TSRMLS_CC);
		}
	} else {
		if (onlyStart) {
			zephir_concat_self_str(&localCode, SL(">") TSRMLS_CC);
		} else {
			ZEPHIR_INIT_VAR(_2$$10);
			ZEPHIR_CONCAT_SVS(_2$$10, "></", tagName, ">");
			zephir_concat_self(&localCode, _2$$10 TSRMLS_CC);
		}
	}
	if (useEol) {
		ZEPHIR_INIT_VAR(_3$$11);
		ZEPHIR_GET_CONSTANT(_3$$11, "PHP_EOL");
		zephir_concat_self(&localCode, _3$$11 TSRMLS_CC);
	}
	RETURN_CCTOR(localCode);

}

/**
 * Builds a HTML tag closing tag
 *
 *<code>
 * echo Phalcon\Tag::tagHtmlClose("script", true)
 *</code>
 */
PHP_METHOD(Phalcon_Tag, tagHtmlClose) {

	zend_bool useEol;
	zval *tagName_param = NULL, *useEol_param = NULL, *_0$$3;
	zval *tagName = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &tagName_param, &useEol_param);

	zephir_get_strval(tagName, tagName_param);
	if (!useEol_param) {
		useEol = 0;
	} else {
		useEol = zephir_get_boolval(useEol_param);
	}


	if (useEol) {
		ZEPHIR_INIT_VAR(_0$$3);
		ZEPHIR_GET_CONSTANT(_0$$3, "PHP_EOL");
		ZEPHIR_CONCAT_SVSV(return_value, "</", tagName, ">", _0$$3);
		RETURN_MM();
	}
	ZEPHIR_CONCAT_SVS(return_value, "</", tagName, ">");
	RETURN_MM();

}

