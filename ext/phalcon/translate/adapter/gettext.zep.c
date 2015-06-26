
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
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"
#include "kernel/memory.h"
#include "kernel/operators.h"
#include "kernel/string.h"
#include "kernel/object.h"
#include "kernel/hash.h"
#include "kernel/concat.h"
#include "kernel/array.h"


/**
 * Class Gettext
 *
 * @package Phalcon\Translate\Adapter
 */
ZEPHIR_INIT_CLASS(Phalcon_Translate_Adapter_Gettext) {

	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Translate\\Adapter, Gettext, phalcon, translate_adapter_gettext, phalcon_translate_adapter_ce, phalcon_translate_adapter_gettext_method_entry, 0);

	/**
	 * @var string|array
	 */
	zend_declare_property_null(phalcon_translate_adapter_gettext_ce, SL("_directory"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * @var string
	 */
	zend_declare_property_null(phalcon_translate_adapter_gettext_ce, SL("_defaultDomain"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * @var string
	 */
	zend_declare_property_null(phalcon_translate_adapter_gettext_ce, SL("_locale"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * @var int
	 */
	zend_declare_property_null(phalcon_translate_adapter_gettext_ce, SL("_category"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_class_implements(phalcon_translate_adapter_gettext_ce TSRMLS_CC, 1, phalcon_translate_adapterinterface_ce);
	zend_class_implements(phalcon_translate_adapter_gettext_ce TSRMLS_CC, 1, zend_ce_arrayaccess);
	return SUCCESS;

}

/**
 * Phalcon\Translate\Adapter\Gettext constructor
 */
PHP_METHOD(Phalcon_Translate_Adapter_Gettext, __construct) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *options_param = NULL;
	zval *options = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &options_param);

	options = options_param;



	ZEPHIR_CALL_METHOD(NULL, this_ptr, "prepareoptions", NULL, 0, options);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * Returns the translation related to the given key
 *
 * @param string  index
 * @param array   placeholders
 * @param string  domain
 * @return string
 */
PHP_METHOD(Phalcon_Translate_Adapter_Gettext, query) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *index_param = NULL, *placeholders = NULL, *translation = NULL, *domain = NULL, *_0 = NULL, _1;
	zval *index = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &index_param, &placeholders);

	if (unlikely(Z_TYPE_P(index_param) != IS_STRING && Z_TYPE_P(index_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'index' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (likely(Z_TYPE_P(index_param) == IS_STRING)) {
		zephir_get_strval(index, index_param);
	} else {
		ZEPHIR_INIT_VAR(index);
		ZVAL_EMPTY_STRING(index);
	}
	if (!placeholders) {
		placeholders = ZEPHIR_GLOBAL(global_null);
	}


	ZEPHIR_CALL_FUNCTION(&_0, "func_num_args", NULL, 416);
	zephir_check_call_status();
	if (ZEPHIR_GT_LONG(_0, 2)) {
		ZEPHIR_SINIT_VAR(_1);
		ZVAL_LONG(&_1, 2);
		ZEPHIR_CALL_FUNCTION(&domain, "func_get_arg", NULL, 415, &_1);
		zephir_check_call_status();
	} else {
		ZEPHIR_INIT_NVAR(domain);
		ZVAL_NULL(domain);
	}
	if (!(zephir_is_true(domain))) {
		ZEPHIR_CALL_FUNCTION(&translation, "gettext", NULL, 418, index);
		zephir_check_call_status();
	} else {
		ZEPHIR_CALL_FUNCTION(&translation, "dgettext", NULL, 419, domain, index);
		zephir_check_call_status();
	}
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "replaceplaceholders", NULL, 0, translation, placeholders);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Check whether is defined a translation key in the internal array
 */
PHP_METHOD(Phalcon_Translate_Adapter_Gettext, exists) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *index_param = NULL, *_0 = NULL;
	zval *index = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &index_param);

	if (unlikely(Z_TYPE_P(index_param) != IS_STRING && Z_TYPE_P(index_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'index' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (likely(Z_TYPE_P(index_param) == IS_STRING)) {
		zephir_get_strval(index, index_param);
	} else {
		ZEPHIR_INIT_VAR(index);
		ZVAL_EMPTY_STRING(index);
	}


	ZEPHIR_CALL_METHOD(&_0, this_ptr, "query", NULL, 0, index);
	zephir_check_call_status();
	RETURN_MM_BOOL(zephir_fast_strlen_ev(_0) > 0);

}

/**
 * The plural version of gettext().
 * Some languages have more than one form for plural messages dependent on the count.
 *
 * @param  string  msgid1
 * @param  string  msgid2
 * @param  int     count
 * @param  array   placeholders
 * @param  string  domain
 *
 * @return string
 */
PHP_METHOD(Phalcon_Translate_Adapter_Gettext, nquery) {

	int count, ZEPHIR_LAST_CALL_STATUS;
	zval *msgid1_param = NULL, *msgid2_param = NULL, *count_param = NULL, *placeholders = NULL, *domain_param = NULL, *translation = NULL, _0 = zval_used_for_init;
	zval *msgid1 = NULL, *msgid2 = NULL, *domain = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 2, &msgid1_param, &msgid2_param, &count_param, &placeholders, &domain_param);

	if (unlikely(Z_TYPE_P(msgid1_param) != IS_STRING && Z_TYPE_P(msgid1_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'msgid1' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (likely(Z_TYPE_P(msgid1_param) == IS_STRING)) {
		zephir_get_strval(msgid1, msgid1_param);
	} else {
		ZEPHIR_INIT_VAR(msgid1);
		ZVAL_EMPTY_STRING(msgid1);
	}
	if (unlikely(Z_TYPE_P(msgid2_param) != IS_STRING && Z_TYPE_P(msgid2_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'msgid2' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (likely(Z_TYPE_P(msgid2_param) == IS_STRING)) {
		zephir_get_strval(msgid2, msgid2_param);
	} else {
		ZEPHIR_INIT_VAR(msgid2);
		ZVAL_EMPTY_STRING(msgid2);
	}
	if (unlikely(Z_TYPE_P(count_param) != IS_LONG)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'count' must be a long/integer") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	count = Z_LVAL_P(count_param);
	if (!placeholders) {
		placeholders = ZEPHIR_GLOBAL(global_null);
	}
	if (!domain_param) {
		ZEPHIR_INIT_VAR(domain);
		ZVAL_EMPTY_STRING(domain);
	} else {
	if (unlikely(Z_TYPE_P(domain_param) != IS_STRING && Z_TYPE_P(domain_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'domain' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (likely(Z_TYPE_P(domain_param) == IS_STRING)) {
		zephir_get_strval(domain, domain_param);
	} else {
		ZEPHIR_INIT_VAR(domain);
		ZVAL_EMPTY_STRING(domain);
	}
	}


	if (!(domain && Z_STRLEN_P(domain))) {
		ZEPHIR_SINIT_VAR(_0);
		ZVAL_LONG(&_0, count);
		ZEPHIR_CALL_FUNCTION(&translation, "ngettext", NULL, 420, msgid1, msgid2, &_0);
		zephir_check_call_status();
	} else {
		ZEPHIR_SINIT_NVAR(_0);
		ZVAL_LONG(&_0, count);
		ZEPHIR_CALL_FUNCTION(&translation, "dngettext", NULL, 421, domain, msgid1, msgid2, &_0);
		zephir_check_call_status();
	}
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "replaceplaceholders", NULL, 0, translation, placeholders);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Changes the current domain (i.e. the translation file). The passed domain must be one
 * of those passed to the constructor.
 *
 * @param  string domain
 *
 * @return string Returns the new current domain.
 * @throws \InvalidArgumentException
 */
PHP_METHOD(Phalcon_Translate_Adapter_Gettext, setDomain) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *domain_param = NULL;
	zval *domain = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &domain_param);

	if (unlikely(Z_TYPE_P(domain_param) != IS_STRING && Z_TYPE_P(domain_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'domain' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (likely(Z_TYPE_P(domain_param) == IS_STRING)) {
		zephir_get_strval(domain, domain_param);
	} else {
		ZEPHIR_INIT_VAR(domain);
		ZVAL_EMPTY_STRING(domain);
	}


	ZEPHIR_RETURN_CALL_FUNCTION("textdomain", NULL, 422, domain);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Sets the default domain
 *
 * @return string Returns the new current domain.
 */
PHP_METHOD(Phalcon_Translate_Adapter_Gettext, resetDomain) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *_0 = NULL;

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getdefaultdomain", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_FUNCTION("textdomain", NULL, 422, _0);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Sets the domain default to search within when calls are made to gettext()
 */
PHP_METHOD(Phalcon_Translate_Adapter_Gettext, setDefaultDomain) {

	zval *domain_param = NULL;
	zval *domain = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &domain_param);

	if (unlikely(Z_TYPE_P(domain_param) != IS_STRING && Z_TYPE_P(domain_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'domain' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (likely(Z_TYPE_P(domain_param) == IS_STRING)) {
		zephir_get_strval(domain, domain_param);
	} else {
		ZEPHIR_INIT_VAR(domain);
		ZVAL_EMPTY_STRING(domain);
	}


	zephir_update_property_this(this_ptr, SL("_defaultDomain"), domain TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

/**
 * Gets the default domain
 */
PHP_METHOD(Phalcon_Translate_Adapter_Gettext, getDefaultDomain) {


	RETURN_MEMBER(this_ptr, "_defaultDomain");

}

/**
 * Sets the path for a domain
 */
PHP_METHOD(Phalcon_Translate_Adapter_Gettext, setDirectory) {

	int ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_3 = NULL;
	HashTable *_1;
	HashPosition _0;
	zval *directory, *key = NULL, *value = NULL, **_2, *_4 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &directory);



	zephir_update_property_this(this_ptr, SL("_directory"), directory TSRMLS_CC);
	if (Z_TYPE_P(directory) == IS_ARRAY) {
		if (zephir_fast_count_int(directory TSRMLS_CC)) {
			zephir_is_iterable(directory, &_1, &_0, 0, 0, "phalcon/translate/adapter/gettext.zep", 180);
			for (
			  ; zephir_hash_get_current_data_ex(_1, (void**) &_2, &_0) == SUCCESS
			  ; zephir_hash_move_forward_ex(_1, &_0)
			) {
				ZEPHIR_GET_HMKEY(key, _1, _0);
				ZEPHIR_GET_HVALUE(value, _2);
				ZEPHIR_CALL_FUNCTION(NULL, "bindtextdomain", &_3, 423, key, value);
				zephir_check_call_status();
			}
		}
	} else {
		ZEPHIR_CALL_METHOD(&_4, this_ptr, "getdefaultdomain", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_CALL_FUNCTION(NULL, "bindtextdomain", &_3, 423, _4, directory);
		zephir_check_call_status();
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * Gets the path for a domain
 */
PHP_METHOD(Phalcon_Translate_Adapter_Gettext, getDirectory) {

	zval *directory;

	zephir_fetch_params(0, 1, 0, &directory);



	RETURN_MEMBER(this_ptr, "_directory");

}

/**
 * Sets locale information
 */
PHP_METHOD(Phalcon_Translate_Adapter_Gettext, setLocale) {

	zval *locale = NULL;
	zval *category_param = NULL, *locale_param = NULL, *_0, *_1 = NULL, _2, *_3, *_4;
	int category, ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &category_param, &locale_param);

	category = zephir_get_intval(category_param);
	if (unlikely(Z_TYPE_P(locale_param) != IS_STRING && Z_TYPE_P(locale_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'locale' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (likely(Z_TYPE_P(locale_param) == IS_STRING)) {
		zephir_get_strval(locale, locale_param);
	} else {
		ZEPHIR_INIT_VAR(locale);
		ZVAL_EMPTY_STRING(locale);
	}


	ZEPHIR_INIT_VAR(_0);
	ZEPHIR_CALL_FUNCTION(&_1, "func_get_args", NULL, 133);
	zephir_check_call_status();
	ZEPHIR_SINIT_VAR(_2);
	ZVAL_STRING(&_2, "setlocale", 0);
	ZEPHIR_CALL_USER_FUNC_ARRAY(_0, &_2, _1);
	zephir_check_call_status();
	zephir_update_property_this(this_ptr, SL("_locale"), _0 TSRMLS_CC);
	ZEPHIR_INIT_ZVAL_NREF(_3);
	ZVAL_LONG(_3, category);
	zephir_update_property_this(this_ptr, SL("_category"), _3 TSRMLS_CC);
	_3 = zephir_fetch_nproperty_this(this_ptr, SL("_locale"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_4);
	ZEPHIR_CONCAT_SV(_4, "LC_ALL=", _3);
	ZEPHIR_CALL_FUNCTION(NULL, "putenv", NULL, 424, _4);
	zephir_check_call_status();
	RETURN_MM_MEMBER(this_ptr, "_locale");

}

/**
 * Gets locale
 */
PHP_METHOD(Phalcon_Translate_Adapter_Gettext, getLocale) {


	RETURN_MEMBER(this_ptr, "_locale");

}

/**
 * Gets locale category
 */
PHP_METHOD(Phalcon_Translate_Adapter_Gettext, getCategory) {


	RETURN_MEMBER(this_ptr, "_category");

}

/**
 * Validator for constructor
 */
PHP_METHOD(Phalcon_Translate_Adapter_Gettext, prepareOptions) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *options_param = NULL, *_0, *_1 = NULL, *_2, *_3, *_4, *_5, *_6;
	zval *options = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &options_param);

	options = options_param;



	if (!(zephir_array_isset_string(options, SS("locale")))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_translate_exception_ce, "Parameter \"locale\" is required", "phalcon/translate/adapter/gettext.zep", 227);
		return;
	}
	if (!(zephir_array_isset_string(options, SS("directory")))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_translate_exception_ce, "Parameter \"directory\" is required", "phalcon/translate/adapter/gettext.zep", 231);
		return;
	}
	ZEPHIR_INIT_VAR(_0);
	ZEPHIR_CALL_METHOD(&_1, this_ptr, "getoptionsdefault", NULL, 0);
	zephir_check_call_status();
	zephir_fast_array_merge(_0, &(_1), &(options) TSRMLS_CC);
	ZEPHIR_CPY_WRT(options, _0);
	zephir_array_fetch_string(&_2, options, SL("category"), PH_NOISY | PH_READONLY, "phalcon/translate/adapter/gettext.zep", 236 TSRMLS_CC);
	zephir_array_fetch_string(&_3, options, SL("locale"), PH_NOISY | PH_READONLY, "phalcon/translate/adapter/gettext.zep", 236 TSRMLS_CC);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "setlocale", NULL, 0, _2, _3);
	zephir_check_call_status();
	zephir_array_fetch_string(&_4, options, SL("defaultDomain"), PH_NOISY | PH_READONLY, "phalcon/translate/adapter/gettext.zep", 237 TSRMLS_CC);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "setdefaultdomain", NULL, 0, _4);
	zephir_check_call_status();
	zephir_array_fetch_string(&_5, options, SL("directory"), PH_NOISY | PH_READONLY, "phalcon/translate/adapter/gettext.zep", 238 TSRMLS_CC);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "setdirectory", NULL, 0, _5);
	zephir_check_call_status();
	zephir_array_fetch_string(&_6, options, SL("defaultDomain"), PH_NOISY | PH_READONLY, "phalcon/translate/adapter/gettext.zep", 239 TSRMLS_CC);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "setdomain", NULL, 0, _6);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * Gets default options
 */
PHP_METHOD(Phalcon_Translate_Adapter_Gettext, getOptionsDefault) {


	zephir_create_array(return_value, 2, 0 TSRMLS_CC);
	add_assoc_long_ex(return_value, SS("category"), 0);
	add_assoc_stringl_ex(return_value, SS("defaultDomain"), SL("message"), 1);
	return;

}

