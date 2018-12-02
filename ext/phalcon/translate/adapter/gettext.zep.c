
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
#include "kernel/exception.h"
#include "kernel/fcall.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/memory.h"
#include "kernel/operators.h"
#include "kernel/main.h"
#include "kernel/concat.h"
#include "kernel/array.h"


/**
 * Phalcon\Translate\Adapter\Gettext
 *
 * <code>
 * use Phalcon\Translate\Adapter\Gettext;
 *
 * $adapter = new Gettext(
 *     [
 *         "locale"        => "de_DE.UTF-8",
 *         "defaultDomain" => "translations",
 *         "directory"     => "/path/to/application/locales",
 *         "category"      => LC_MESSAGES,
 *     ]
 * );
 * </code>
 *
 * Allows translate using gettext
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

	zend_class_implements(phalcon_translate_adapter_gettext_ce TSRMLS_CC, 1, zend_ce_arrayaccess);
	return SUCCESS;

}

/**
 */
PHP_METHOD(Phalcon_Translate_Adapter_Gettext, getDirectory) {

	

	RETURN_MEMBER(getThis(), "_directory");

}

/**
 */
PHP_METHOD(Phalcon_Translate_Adapter_Gettext, getDefaultDomain) {

	

	RETURN_MEMBER(getThis(), "_defaultDomain");

}

/**
 */
PHP_METHOD(Phalcon_Translate_Adapter_Gettext, getLocale) {

	

	RETURN_MEMBER(getThis(), "_locale");

}

/**
 */
PHP_METHOD(Phalcon_Translate_Adapter_Gettext, getCategory) {

	

	RETURN_MEMBER(getThis(), "_category");

}

/**
 * Phalcon\Translate\Adapter\Gettext constructor
 */
PHP_METHOD(Phalcon_Translate_Adapter_Gettext, __construct) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL;
	zval *options_param = NULL;
	zval *options = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &options_param);

	options = options_param;


	if (!((zephir_function_exists_ex(SS("gettext") TSRMLS_CC) == SUCCESS))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_translate_exception_ce, "This class requires the gettext extension for PHP", "phalcon/translate/adapter/gettext.zep", 72);
		return;
	}
	ZEPHIR_CALL_PARENT(NULL, phalcon_translate_adapter_gettext_ce, getThis(), "__construct", &_0, 466, options);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "prepareoptions", NULL, 0, options);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * Returns the translation related to the given key.
 *
 * <code>
 * $translator->query("你好 %name%！", ["name" => "Phalcon"]);
 * </code>
 */
PHP_METHOD(Phalcon_Translate_Adapter_Gettext, query) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *index_param = NULL, *placeholders = NULL, *translation = NULL;
	zval *index = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &index_param, &placeholders);

	if (UNEXPECTED(Z_TYPE_P(index_param) != IS_STRING && Z_TYPE_P(index_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'index' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(index_param) == IS_STRING)) {
		zephir_get_strval(index, index_param);
	} else {
		ZEPHIR_INIT_VAR(index);
		ZVAL_EMPTY_STRING(index);
	}
	if (!placeholders) {
		placeholders = ZEPHIR_GLOBAL(global_null);
	}


	ZEPHIR_CALL_FUNCTION(&translation, "gettext", NULL, 469, index);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "replaceplaceholders", NULL, 0, translation, placeholders);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Check whether is defined a translation key in the internal array
 */
PHP_METHOD(Phalcon_Translate_Adapter_Gettext, exists) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *index_param = NULL, *result = NULL;
	zval *index = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &index_param);

	if (UNEXPECTED(Z_TYPE_P(index_param) != IS_STRING && Z_TYPE_P(index_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'index' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(index_param) == IS_STRING)) {
		zephir_get_strval(index, index_param);
	} else {
		ZEPHIR_INIT_VAR(index);
		ZVAL_EMPTY_STRING(index);
	}


	ZEPHIR_CALL_METHOD(&result, this_ptr, "query", NULL, 0, index);
	zephir_check_call_status();
	RETURN_MM_BOOL(!ZEPHIR_IS_IDENTICAL(result, index));

}

/**
 * The plural version of gettext().
 * Some languages have more than one form for plural messages dependent on the count.
 */
PHP_METHOD(Phalcon_Translate_Adapter_Gettext, nquery) {

	zend_long count, ZEPHIR_LAST_CALL_STATUS;
	zval *msgid1_param = NULL, *msgid2_param = NULL, *count_param = NULL, *placeholders = NULL, *domain_param = NULL, *translation = NULL, _0$$3, _1$$4;
	zval *msgid1 = NULL, *msgid2 = NULL, *domain = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 2, &msgid1_param, &msgid2_param, &count_param, &placeholders, &domain_param);

	if (UNEXPECTED(Z_TYPE_P(msgid1_param) != IS_STRING && Z_TYPE_P(msgid1_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'msgid1' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(msgid1_param) == IS_STRING)) {
		zephir_get_strval(msgid1, msgid1_param);
	} else {
		ZEPHIR_INIT_VAR(msgid1);
		ZVAL_EMPTY_STRING(msgid1);
	}
	if (UNEXPECTED(Z_TYPE_P(msgid2_param) != IS_STRING && Z_TYPE_P(msgid2_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'msgid2' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(msgid2_param) == IS_STRING)) {
		zephir_get_strval(msgid2, msgid2_param);
	} else {
		ZEPHIR_INIT_VAR(msgid2);
		ZVAL_EMPTY_STRING(msgid2);
	}
	if (UNEXPECTED(Z_TYPE_P(count_param) != IS_LONG)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'count' must be a int") TSRMLS_CC);
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
	if (UNEXPECTED(Z_TYPE_P(domain_param) != IS_STRING && Z_TYPE_P(domain_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'domain' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(domain_param) == IS_STRING)) {
		zephir_get_strval(domain, domain_param);
	} else {
		ZEPHIR_INIT_VAR(domain);
		ZVAL_EMPTY_STRING(domain);
	}
	}


	if (!(!(!domain) && Z_STRLEN_P(domain))) {
		ZEPHIR_SINIT_VAR(_0$$3);
		ZVAL_LONG(&_0$$3, count);
		ZEPHIR_CALL_FUNCTION(&translation, "ngettext", NULL, 470, msgid1, msgid2, &_0$$3);
		zephir_check_call_status();
	} else {
		ZEPHIR_SINIT_VAR(_1$$4);
		ZVAL_LONG(&_1$$4, count);
		ZEPHIR_CALL_FUNCTION(&translation, "dngettext", NULL, 471, domain, msgid1, msgid2, &_1$$4);
		zephir_check_call_status();
	}
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "replaceplaceholders", NULL, 0, translation, placeholders);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Changes the current domain (i.e. the translation file)
 */
PHP_METHOD(Phalcon_Translate_Adapter_Gettext, setDomain) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *domain;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &domain);



	ZEPHIR_RETURN_CALL_FUNCTION("textdomain", NULL, 472, domain);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Sets the default domain
 */
PHP_METHOD(Phalcon_Translate_Adapter_Gettext, resetDomain) {

	zval *_0 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getdefaultdomain", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_FUNCTION("textdomain", NULL, 472, _0);
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

	if (UNEXPECTED(Z_TYPE_P(domain_param) != IS_STRING && Z_TYPE_P(domain_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'domain' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(domain_param) == IS_STRING)) {
		zephir_get_strval(domain, domain_param);
	} else {
		ZEPHIR_INIT_VAR(domain);
		ZVAL_EMPTY_STRING(domain);
	}


	zephir_update_property_this(getThis(), SL("_defaultDomain"), domain TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

/**
 * Sets the path for a domain
 *
 * <code>
 * // Set the directory path
 * $gettext->setDirectory("/path/to/the/messages");
 *
 * // Set the domains and directories path
 * $gettext->setDirectory(
 *     [
 *         "messages" => "/path/to/the/messages",
 *         "another"  => "/path/to/the/another",
 *     ]
 * );
 * </code>
 *
 * @param string|array directory The directory path or an array of directories and domains
 */
PHP_METHOD(Phalcon_Translate_Adapter_Gettext, setDirectory) {

	HashTable *_1$$4;
	HashPosition _0$$4;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_3 = NULL;
	zval *directory, *key = NULL, *value = NULL, **_2$$4, *_4$$6 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &directory);



	if (ZEPHIR_IS_EMPTY(directory)) {
		RETURN_MM_NULL();
	}
	zephir_update_property_this(getThis(), SL("_directory"), directory TSRMLS_CC);
	if (Z_TYPE_P(directory) == IS_ARRAY) {
		zephir_is_iterable(directory, &_1$$4, &_0$$4, 0, 0, "phalcon/translate/adapter/gettext.zep", 180);
		for (
		  ; zend_hash_get_current_data_ex(_1$$4, (void**) &_2$$4, &_0$$4) == SUCCESS
		  ; zend_hash_move_forward_ex(_1$$4, &_0$$4)
		) {
			ZEPHIR_GET_HMKEY(key, _1$$4, _0$$4);
			ZEPHIR_GET_HVALUE(value, _2$$4);
			ZEPHIR_CALL_FUNCTION(NULL, "bindtextdomain", &_3, 473, key, value);
			zephir_check_call_status();
		}
	} else {
		ZEPHIR_CALL_METHOD(&_4$$6, this_ptr, "getdefaultdomain", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_CALL_FUNCTION(NULL, "bindtextdomain", &_3, 473, _4$$6, directory);
		zephir_check_call_status();
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * Sets locale information
 *
 * <code>
 * // Set locale to Dutch
 * $gettext->setLocale(LC_ALL, "nl_NL");
 *
 * // Try different possible locale names for german
 * $gettext->setLocale(LC_ALL, "de_DE@euro", "de_DE", "de", "ge");
 * </code>
 */
PHP_METHOD(Phalcon_Translate_Adapter_Gettext, setLocale) {

	zval *locale = NULL;
	zval *category_param = NULL, *locale_param = NULL, *_0, *_1, _2, *_3, *_4, *_5, *_6, *_7, *_8, *_9, _10;
	zend_long category, ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &category_param, &locale_param);

	if (UNEXPECTED(Z_TYPE_P(category_param) != IS_LONG)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'category' must be a int") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	category = Z_LVAL_P(category_param);
	if (UNEXPECTED(Z_TYPE_P(locale_param) != IS_STRING && Z_TYPE_P(locale_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'locale' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(locale_param) == IS_STRING)) {
		zephir_get_strval(locale, locale_param);
	} else {
		ZEPHIR_INIT_VAR(locale);
		ZVAL_EMPTY_STRING(locale);
	}


	ZEPHIR_INIT_VAR(_0);
	ZEPHIR_INIT_VAR(_1);
	zephir_get_args(_1 TSRMLS_CC);
	ZEPHIR_SINIT_VAR(_2);
	ZVAL_STRING(&_2, "setlocale", 0);
	ZEPHIR_CALL_USER_FUNC_ARRAY(_0, &_2, _1);
	zephir_check_call_status();
	zephir_update_property_this(getThis(), SL("_locale"), _0 TSRMLS_CC);
	ZEPHIR_INIT_ZVAL_NREF(_3);
	ZVAL_LONG(_3, category);
	zephir_update_property_this(getThis(), SL("_category"), _3 TSRMLS_CC);
	_3 = zephir_fetch_nproperty_this(this_ptr, SL("_locale"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_4);
	ZEPHIR_CONCAT_SV(_4, "LC_ALL=", _3);
	ZEPHIR_CALL_FUNCTION(NULL, "putenv", NULL, 474, _4);
	zephir_check_call_status();
	_5 = zephir_fetch_nproperty_this(this_ptr, SL("_locale"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_6);
	ZEPHIR_CONCAT_SV(_6, "LANG=", _5);
	ZEPHIR_CALL_FUNCTION(NULL, "putenv", NULL, 474, _6);
	zephir_check_call_status();
	_7 = zephir_fetch_nproperty_this(this_ptr, SL("_locale"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_8);
	ZEPHIR_CONCAT_SV(_8, "LANGUAGE=", _7);
	ZEPHIR_CALL_FUNCTION(NULL, "putenv", NULL, 474, _8);
	zephir_check_call_status();
	_9 = zephir_fetch_nproperty_this(this_ptr, SL("_locale"), PH_NOISY_CC);
	ZEPHIR_SINIT_VAR(_10);
	ZVAL_LONG(&_10, 6);
	ZEPHIR_CALL_FUNCTION(NULL, "setlocale", NULL, 456, &_10, _9);
	zephir_check_call_status();
	RETURN_MM_MEMBER(getThis(), "_locale");

}

/**
 * Validator for constructor
 */
PHP_METHOD(Phalcon_Translate_Adapter_Gettext, prepareOptions) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *options_param = NULL, *_0, *_1 = NULL, *_2, *_3, *_4, *_5, *_6;
	zval *options = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &options_param);

	options = options_param;


	if (!(zephir_array_isset_string(options, SS("locale")))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_translate_exception_ce, "Parameter 'locale' is required", "phalcon/translate/adapter/gettext.zep", 215);
		return;
	}
	if (!(zephir_array_isset_string(options, SS("directory")))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_translate_exception_ce, "Parameter 'directory' is required", "phalcon/translate/adapter/gettext.zep", 219);
		return;
	}
	ZEPHIR_INIT_VAR(_0);
	ZEPHIR_CALL_METHOD(&_1, this_ptr, "getoptionsdefault", NULL, 0);
	zephir_check_call_status();
	zephir_fast_array_merge(_0, &(_1), &(options) TSRMLS_CC);
	ZEPHIR_CPY_WRT(options, _0);
	zephir_array_fetch_string(&_2, options, SL("category"), PH_NOISY | PH_READONLY, "phalcon/translate/adapter/gettext.zep", 224 TSRMLS_CC);
	zephir_array_fetch_string(&_3, options, SL("locale"), PH_NOISY | PH_READONLY, "phalcon/translate/adapter/gettext.zep", 224 TSRMLS_CC);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "setlocale", NULL, 0, _2, _3);
	zephir_check_call_status();
	zephir_array_fetch_string(&_4, options, SL("defaultDomain"), PH_NOISY | PH_READONLY, "phalcon/translate/adapter/gettext.zep", 225 TSRMLS_CC);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "setdefaultdomain", NULL, 0, _4);
	zephir_check_call_status();
	zephir_array_fetch_string(&_5, options, SL("directory"), PH_NOISY | PH_READONLY, "phalcon/translate/adapter/gettext.zep", 226 TSRMLS_CC);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "setdirectory", NULL, 0, _5);
	zephir_check_call_status();
	zephir_array_fetch_string(&_6, options, SL("defaultDomain"), PH_NOISY | PH_READONLY, "phalcon/translate/adapter/gettext.zep", 227 TSRMLS_CC);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "setdomain", NULL, 0, _6);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * Gets default options
 */
PHP_METHOD(Phalcon_Translate_Adapter_Gettext, getOptionsDefault) {

	

	zephir_create_array(return_value, 2, 0 TSRMLS_CC);
	add_assoc_long_ex(return_value, SS("category"), 6);
	add_assoc_stringl_ex(return_value, SS("defaultDomain"), SL("messages"), 1);
	return;

}

