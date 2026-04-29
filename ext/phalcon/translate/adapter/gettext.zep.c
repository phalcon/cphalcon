
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
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/operators.h"
#include "kernel/exception.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/object.h"
#include "kernel/concat.h"
#include "kernel/array.h"


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */
/**
 * Phalcon\Translate\Adapter\Gettext
 *
 * ```php
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
 * ```
 *
 * Allows translate using gettext
 *
 * @property int          $category
 * @property string       $defaultDomain
 * @property string|array $directory
 * @property string|false $locale
 */
ZEPHIR_INIT_CLASS(Phalcon_Translate_Adapter_Gettext)
{
	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Translate\\Adapter, Gettext, phalcon, translate_adapter_gettext, phalcon_translate_adapter_abstractadapter_ce, phalcon_translate_adapter_gettext_method_entry, 0);

	/**
	 * @var int
	 */
	zend_declare_property_null(phalcon_translate_adapter_gettext_ce, SL("category"), ZEND_ACC_PROTECTED);
	/**
	 * @var string
	 */
	zend_declare_property_null(phalcon_translate_adapter_gettext_ce, SL("defaultDomain"), ZEND_ACC_PROTECTED);
	/**
	 * @var string|array
	 */
	zend_declare_property_null(phalcon_translate_adapter_gettext_ce, SL("directory"), ZEND_ACC_PROTECTED);
	/**
	 * @var string
	 */
	zend_declare_property_null(phalcon_translate_adapter_gettext_ce, SL("locale"), ZEND_ACC_PROTECTED);
	zend_class_implements(phalcon_translate_adapter_gettext_ce, 1, zend_ce_arrayaccess);
	return SUCCESS;
}

/**
 * Gettext constructor.
 *
 * @param InterpolatorFactory $interpolator
 * @param array               $options = [
 *                                       'locale'        => '',
 *                                       'defaultDomain' => '',
 *                                       'directory'     => '',
 *                                       'category'      => ''
 *                                       ]
 *
 * @throws Exception
 */
PHP_METHOD(Phalcon_Translate_Adapter_Gettext, __construct)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval options;
	zval *interpolator, interpolator_sub, *options_param = NULL, _0, _1;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&interpolator_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&options);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_OBJECT_OF_CLASS(interpolator, phalcon_translate_interpolatorfactory_ce)
		ZEPHIR_Z_PARAM_ARRAY(options, options_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 2, 0, &interpolator, &options_param);
	ZEPHIR_OBS_COPY_OR_DUP(&options, options_param);
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "gettext");
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "phpfunctionexists", NULL, 0, &_1);
	zephir_check_call_status();
	if (UNEXPECTED(!zephir_is_true(&_0))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_translate_exception_ce, "This class requires the gettext extension for PHP", "phalcon/Translate/Adapter/Gettext.zep", 80);
		return;
	}
	ZEPHIR_CALL_PARENT(NULL, phalcon_translate_adapter_gettext_ce, getThis(), "__construct", NULL, 0, interpolator, &options);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "prepareoptions", NULL, 0, &options);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();
}

/**
 * Check whether is defined a translation key in the internal array
 *
 * @param string $index
 *
 * @return bool
 * @deprecated
 */
PHP_METHOD(Phalcon_Translate_Adapter_Gettext, exists)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval index_zv;
	zend_string *index = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&index_zv);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(index)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	ZVAL_STR_COPY(&index_zv, index);
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "has", NULL, 0, &index_zv);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * @return int
 */
PHP_METHOD(Phalcon_Translate_Adapter_Gettext, getCategory)
{

	RETURN_MEMBER(getThis(), "category");
}

/**
 * @return string
 */
PHP_METHOD(Phalcon_Translate_Adapter_Gettext, getDefaultDomain)
{

	RETURN_MEMBER(getThis(), "defaultDomain");
}

/**
 * @return string|array
 */
PHP_METHOD(Phalcon_Translate_Adapter_Gettext, getDirectory)
{

	RETURN_MEMBER(getThis(), "directory");
}

/**
 * @return string
 */
PHP_METHOD(Phalcon_Translate_Adapter_Gettext, getLocale)
{

	RETURN_MEMBER(getThis(), "locale");
}

/**
 * Check whether is defined a translation key in the internal array
 *
 * @param string $index
 *
 * @return bool
 */
PHP_METHOD(Phalcon_Translate_Adapter_Gettext, has)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval index_zv, result;
	zend_string *index = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&index_zv);
	ZVAL_UNDEF(&result);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(index)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	ZVAL_STR_COPY(&index_zv, index);
	ZEPHIR_CALL_METHOD(&result, this_ptr, "query", NULL, 0, &index_zv);
	zephir_check_call_status();
	RETURN_MM_BOOL(!ZEPHIR_IS_IDENTICAL(&result, &index_zv));
}

/**
 * The plural version of gettext().
 * Some languages have more than one form for plural messages dependent on
 * the count.
 *
 * @param string      $msgid1
 * @param string      $msgid2
 * @param int         $count
 * @param array       $placeholders
 * @param string|null $domain
 *
 * @return string
 */
PHP_METHOD(Phalcon_Translate_Adapter_Gettext, nquery)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval placeholders;
	zend_long count, ZEPHIR_LAST_CALL_STATUS;
	zval msgid1_zv, msgid2_zv, *count_param = NULL, *placeholders_param = NULL, domain_zv, translation, _0$$3, _1$$4;
	zend_string *msgid1 = NULL, *msgid2 = NULL, *domain = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&msgid1_zv);
	ZVAL_UNDEF(&msgid2_zv);
	ZVAL_UNDEF(&domain_zv);
	ZVAL_UNDEF(&translation);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_1$$4);
	ZVAL_UNDEF(&placeholders);
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(3, 5)
		Z_PARAM_STR(msgid1)
		Z_PARAM_STR(msgid2)
		Z_PARAM_LONG(count)
		Z_PARAM_OPTIONAL
		ZEPHIR_Z_PARAM_ARRAY(placeholders, placeholders_param)
		Z_PARAM_STR_OR_NULL(domain)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	count_param = ZEND_CALL_ARG(execute_data, 3);
	if (ZEND_NUM_ARGS() > 3) {
		placeholders_param = ZEND_CALL_ARG(execute_data, 4);
	}
	ZVAL_STR_COPY(&msgid1_zv, msgid1);
	ZVAL_STR_COPY(&msgid2_zv, msgid2);
	if (UNEXPECTED(Z_TYPE_P(count_param) != IS_LONG)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'count' must be of the type int"));
		RETURN_MM_NULL();
	}
	count = Z_LVAL_P(count_param);
	if (!placeholders_param) {
		ZEPHIR_INIT_VAR(&placeholders);
		array_init(&placeholders);
	} else {
		zephir_get_arrval(&placeholders, placeholders_param);
	}
	if (!domain) {
		ZEPHIR_INIT_VAR(&domain_zv);
	} else {
	ZVAL_STR_COPY(&domain_zv, domain);
	}
	if (!(!(ZEPHIR_IS_EMPTY(&domain_zv)))) {
		ZVAL_LONG(&_0$$3, count);
		ZEPHIR_CALL_FUNCTION(&translation, "ngettext", NULL, 0, &msgid1_zv, &msgid2_zv, &_0$$3);
		zephir_check_call_status();
	} else {
		ZVAL_LONG(&_1$$4, count);
		ZEPHIR_CALL_FUNCTION(&translation, "dngettext", NULL, 0, &domain_zv, &msgid1_zv, &msgid2_zv, &_1$$4);
		zephir_check_call_status();
	}
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "replaceplaceholders", NULL, 0, &translation, &placeholders);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Returns the translation related to the given key.
 *
 * ```php
 * $translator->query("你好 %name%！", ["name" => "Phalcon"]);
 * ```
 *
 * @param string $translateKey
 * @param array  $placeholders
 *
 * @return string
 */
PHP_METHOD(Phalcon_Translate_Adapter_Gettext, query)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval placeholders;
	zval translateKey_zv, *placeholders_param = NULL, _0;
	zend_string *translateKey = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&translateKey_zv);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&placeholders);
	ZEND_PARSE_PARAMETERS_START(1, 2)
		Z_PARAM_STR(translateKey)
		Z_PARAM_OPTIONAL
		ZEPHIR_Z_PARAM_ARRAY(placeholders, placeholders_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	if (ZEND_NUM_ARGS() > 1) {
		placeholders_param = ZEND_CALL_ARG(execute_data, 2);
	}
	ZVAL_STR_COPY(&translateKey_zv, translateKey);
	if (!placeholders_param) {
		ZEPHIR_INIT_VAR(&placeholders);
		array_init(&placeholders);
	} else {
		zephir_get_arrval(&placeholders, placeholders_param);
	}
	ZEPHIR_CALL_FUNCTION(&_0, "gettext", NULL, 0, &translateKey_zv);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "replaceplaceholders", NULL, 0, &_0, &placeholders);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Sets the default domain
 *
 * @return string
 */
PHP_METHOD(Phalcon_Translate_Adapter_Gettext, resetDomain)
{
	zval _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getdefaultdomain", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_FUNCTION("textdomain", NULL, 0, &_0);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Sets the domain default to search within when calls are made to gettext()
 *
 * @param string $domain
 */
PHP_METHOD(Phalcon_Translate_Adapter_Gettext, setDefaultDomain)
{
	zval domain_zv;
	zend_string *domain = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&domain_zv);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(domain)
	ZEND_PARSE_PARAMETERS_END();
	ZVAL_STR(&domain_zv, domain);
	zephir_update_property_zval(this_ptr, ZEND_STRL("defaultDomain"), &domain_zv);
}

/**
 * Sets the path for a domain
 *
 * ```php
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
 * ```
 *
 * @param string|array $directory
 */
PHP_METHOD(Phalcon_Translate_Adapter_Gettext, setDirectory)
{
	zend_string *_3$$4;
	zend_ulong _2$$4;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_4 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *directory, directory_sub, key, value, *_0$$4, _1$$4, _5$$7;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&directory_sub);
	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&_1$$4);
	ZVAL_UNDEF(&_5$$7);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(directory)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &directory);
	if (ZEPHIR_IS_EMPTY(directory)) {
		RETURN_MM_NULL();
	}
	zephir_update_property_zval(this_ptr, ZEND_STRL("directory"), directory);
	if (Z_TYPE_P(directory) == IS_ARRAY) {
		zephir_is_iterable(directory, 0, "phalcon/Translate/Adapter/Gettext.zep", 249);
		if (Z_TYPE_P(directory) == IS_ARRAY) {
			ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(directory), _2$$4, _3$$4, _0$$4)
			{
				ZEPHIR_INIT_NVAR(&key);
				if (_3$$4 != NULL) { 
					ZVAL_STR_COPY(&key, _3$$4);
				} else {
					ZVAL_LONG(&key, _2$$4);
				}
				ZEPHIR_INIT_NVAR(&value);
				ZVAL_COPY(&value, _0$$4);
				ZEPHIR_CALL_FUNCTION(NULL, "bindtextdomain", &_4, 0, &key, &value);
				zephir_check_call_status();
			} ZEND_HASH_FOREACH_END();
		} else {
			ZEPHIR_CALL_METHOD(NULL, directory, "rewind", NULL, 0);
			zephir_check_call_status();
			while (1) {
				ZEPHIR_CALL_METHOD(&_1$$4, directory, "valid", NULL, 0);
				zephir_check_call_status();
				if (!zend_is_true(&_1$$4)) {
					break;
				}
				ZEPHIR_CALL_METHOD(&key, directory, "key", NULL, 0);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&value, directory, "current", NULL, 0);
				zephir_check_call_status();
					ZEPHIR_CALL_FUNCTION(NULL, "bindtextdomain", &_4, 0, &key, &value);
					zephir_check_call_status();
				ZEPHIR_CALL_METHOD(NULL, directory, "next", NULL, 0);
				zephir_check_call_status();
			}
		}
		ZEPHIR_INIT_NVAR(&value);
		ZEPHIR_INIT_NVAR(&key);
	} else {
		ZEPHIR_CALL_METHOD(&_5$$7, this_ptr, "getdefaultdomain", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_CALL_FUNCTION(NULL, "bindtextdomain", &_4, 0, &_5$$7, directory);
		zephir_check_call_status();
	}
	ZEPHIR_MM_RESTORE();
}

/**
 * Changes the current domain (i.e. the translation file)
 *
 * @param string|null $domain
 *
 * @return string
 */
PHP_METHOD(Phalcon_Translate_Adapter_Gettext, setDomain)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval domain_zv;
	zend_string *domain = NULL;

	ZVAL_UNDEF(&domain_zv);
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(0, 1)
		Z_PARAM_OPTIONAL
		Z_PARAM_STR_OR_NULL(domain)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	if (!domain) {
		ZEPHIR_INIT_VAR(&domain_zv);
	} else {
		ZVAL_STR_COPY(&domain_zv, domain);
	}
	ZEPHIR_RETURN_CALL_FUNCTION("textdomain", NULL, 0, &domain_zv);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Sets locale information
 *
 * ```php
 * // Set locale to Dutch
 * $gettext->setLocale(LC_ALL, "nl_NL");
 *
 * // Try different possible locale names for German
 * $gettext->setLocale(LC_ALL, "de_DE@euro", "de_DE", "de", "ge");
 * ```
 *
 * @param int   $category
 * @param array $localeArray
 *
 * @return false|string
 */
PHP_METHOD(Phalcon_Translate_Adapter_Gettext, setLocale)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval localeArray;
	zval *category_param = NULL, *localeArray_param = NULL, _0, _1, _2$$3, _3$$3, _4$$3, _5$$3, _6$$3, _7$$3, _8$$3, _9$$3;
	zend_long category, ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_5$$3);
	ZVAL_UNDEF(&_6$$3);
	ZVAL_UNDEF(&_7$$3);
	ZVAL_UNDEF(&_8$$3);
	ZVAL_UNDEF(&_9$$3);
	ZVAL_UNDEF(&localeArray);
	ZEND_PARSE_PARAMETERS_START(1, 2)
		Z_PARAM_LONG(category)
		Z_PARAM_OPTIONAL
		ZEPHIR_Z_PARAM_ARRAY(localeArray, localeArray_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 1, &category_param, &localeArray_param);
	if (UNEXPECTED(Z_TYPE_P(category_param) != IS_LONG)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'category' must be of the type int"));
		RETURN_MM_NULL();
	}
	category = Z_LVAL_P(category_param);
	if (!localeArray_param) {
		ZEPHIR_INIT_VAR(&localeArray);
		array_init(&localeArray);
	} else {
		zephir_get_arrval(&localeArray, localeArray_param);
	}
	ZVAL_LONG(&_0, category);
	ZEPHIR_CALL_FUNCTION(&_1, "setlocale", NULL, 0, &_0, &localeArray);
	zephir_check_call_status();
	zephir_update_property_zval(this_ptr, ZEND_STRL("locale"), &_1);
	ZVAL_UNDEF(&_0);
	ZVAL_LONG(&_0, category);
	zephir_update_property_zval(this_ptr, ZEND_STRL("category"), &_0);
	zephir_read_property(&_0, this_ptr, ZEND_STRL("locale"), PH_NOISY_CC | PH_READONLY);
	if (!ZEPHIR_IS_FALSE_IDENTICAL(&_0)) {
		zephir_read_property(&_2$$3, this_ptr, ZEND_STRL("locale"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_INIT_VAR(&_3$$3);
		ZEPHIR_CONCAT_SV(&_3$$3, "LC_ALL=", &_2$$3);
		ZEPHIR_CALL_FUNCTION(NULL, "putenv", NULL, 0, &_3$$3);
		zephir_check_call_status();
		zephir_read_property(&_4$$3, this_ptr, ZEND_STRL("locale"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_INIT_VAR(&_5$$3);
		ZEPHIR_CONCAT_SV(&_5$$3, "LANG=", &_4$$3);
		ZEPHIR_CALL_FUNCTION(NULL, "putenv", NULL, 0, &_5$$3);
		zephir_check_call_status();
		zephir_read_property(&_6$$3, this_ptr, ZEND_STRL("locale"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_INIT_VAR(&_7$$3);
		ZEPHIR_CONCAT_SV(&_7$$3, "LANGUAGE=", &_6$$3);
		ZEPHIR_CALL_FUNCTION(NULL, "putenv", NULL, 0, &_7$$3);
		zephir_check_call_status();
		zephir_read_property(&_8$$3, this_ptr, ZEND_STRL("locale"), PH_NOISY_CC | PH_READONLY);
		ZVAL_LONG(&_9$$3, 6);
		ZEPHIR_CALL_FUNCTION(NULL, "setlocale", NULL, 0, &_9$$3, &_8$$3);
		zephir_check_call_status();
	}
	RETURN_MM_MEMBER(getThis(), "locale");
}

/**
 * Gets default options
 *
 * @return array
 */
PHP_METHOD(Phalcon_Translate_Adapter_Gettext, getOptionsDefault)
{

	zephir_create_array(return_value, 2, 0);
	add_assoc_long_ex(return_value, SL("category"), 6);
	add_assoc_stringl_ex(return_value, SL("defaultDomain"), SL("messages"));
	return;
}

/**
 * Validator for constructor
 *
 * @param array $options
 *
 * @throws Exception
 */
PHP_METHOD(Phalcon_Translate_Adapter_Gettext, prepareOptions)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *options_param = NULL, _0, _1, _2, _3, _4, _5, _6;
	zval options;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&options);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		ZEPHIR_Z_PARAM_ARRAY(options, options_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &options_param);
	ZEPHIR_OBS_COPY_OR_DUP(&options, options_param);
	if (UNEXPECTED(!(zephir_array_isset_string(&options, SL("locale"))))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_translate_exception_ce, "Parameter 'locale' is required", "phalcon/Translate/Adapter/Gettext.zep", 323);
		return;
	}
	if (UNEXPECTED(!(zephir_array_isset_string(&options, SL("directory"))))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_translate_exception_ce, "Parameter 'directory' is required", "phalcon/Translate/Adapter/Gettext.zep", 327);
		return;
	}
	ZEPHIR_INIT_VAR(&_0);
	ZEPHIR_CALL_METHOD(&_1, this_ptr, "getoptionsdefault", NULL, 0);
	zephir_check_call_status();
	zephir_fast_array_merge(&_0, &_1, &options);
	ZEPHIR_CPY_WRT(&options, &_0);
	zephir_array_fetch_string(&_2, &options, SL("category"), PH_NOISY | PH_READONLY, "phalcon/Translate/Adapter/Gettext.zep", 335);
	zephir_array_fetch_string(&_3, &options, SL("locale"), PH_NOISY | PH_READONLY, "phalcon/Translate/Adapter/Gettext.zep", 335);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "setlocale", NULL, 0, &_2, &_3);
	zephir_check_call_status();
	zephir_array_fetch_string(&_4, &options, SL("defaultDomain"), PH_NOISY | PH_READONLY, "phalcon/Translate/Adapter/Gettext.zep", 336);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "setdefaultdomain", NULL, 0, &_4);
	zephir_check_call_status();
	zephir_array_fetch_string(&_5, &options, SL("directory"), PH_NOISY | PH_READONLY, "phalcon/Translate/Adapter/Gettext.zep", 337);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "setdirectory", NULL, 0, &_5);
	zephir_check_call_status();
	zephir_array_fetch_string(&_6, &options, SL("defaultDomain"), PH_NOISY | PH_READONLY, "phalcon/Translate/Adapter/Gettext.zep", 338);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "setdomain", NULL, 0, &_6);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();
}

/**
 * @todo to be removed when we get traits
 */
PHP_METHOD(Phalcon_Translate_Adapter_Gettext, phpFunctionExists)
{
	zval name_zv;
	zend_string *name = NULL;

	ZVAL_UNDEF(&name_zv);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(name)
	ZEND_PARSE_PARAMETERS_END();
	ZVAL_STR(&name_zv, name);
	RETURN_BOOL((zephir_function_exists(&name_zv) == SUCCESS));
}

