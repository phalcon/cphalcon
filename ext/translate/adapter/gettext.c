
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
  +------------------------------------------------------------------------+
*/

#include "translate/adapter/gettext.h"
#include "translate/adapter.h"
#include "translate/adapterinterface.h"
#include "translate/exception.h"

#include <locale.h>
#include <libintl.h>

#include "kernel/main.h"
#include "kernel/memory.h"
#include "kernel/exception.h"
#include "kernel/array.h"
#include "kernel/object.h"
#include "kernel/hash.h"
#include "kernel/concat.h"
#include "kernel/fcall.h"
#include "kernel/string.h"

/**
 * Phalcon\Translate\Adapter\Gettext
 *
 * Allows to define translation lists using PHP arrays
 *
 */
zend_class_entry *phalcon_translate_adapter_gettext_ce;

static zend_object_handlers phalcon_translate_adapter_gettext_object_handlers;

static zval* phalcon_translate_adapter_gettext_read_dimension(zval *object, zval *offset, int type TSRMLS_DC)
{
	zval *translation;
	char *msgstr;

	if (!is_phalcon_class(Z_OBJCE_P(object))) {
		return zend_get_std_object_handlers()->read_dimension(object, offset, type TSRMLS_CC);
	}

	msgstr = gettext(Z_STRVAL_P(offset));

	PHALCON_INIT_VAR(translation);
	ZVAL_STRING(translation, msgstr, 1);

	return translation;
}

static int phalcon_translate_adapter_gettext_has_dimension(zval *object, zval *offset, int check_empty TSRMLS_DC)
{
	char *msgstr;

	if (!is_phalcon_class(Z_OBJCE_P(object))) {
		return zend_get_std_object_handlers()->has_dimension(object, offset, check_empty TSRMLS_CC);
	}

	msgstr = gettext(Z_STRVAL_P(offset));

	return (1 == check_empty) ? strlen(msgstr) : 1;
}

PHP_METHOD(Phalcon_Translate_Adapter_Gettext, __construct);
PHP_METHOD(Phalcon_Translate_Adapter_Gettext, query);
PHP_METHOD(Phalcon_Translate_Adapter_Gettext, exists);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_translate_adapter_gettext___construct, 0, 0, 1)
	ZEND_ARG_INFO(0, options)
ZEND_END_ARG_INFO()

static const zend_function_entry phalcon_translate_adapter_gettext_method_entry[] = {
	PHP_ME(Phalcon_Translate_Adapter_Gettext, __construct, arginfo_phalcon_translate_adapter_gettext___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phalcon_Translate_Adapter_Gettext, query, arginfo_phalcon_translate_adapterinterface_query, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Translate_Adapter_Gettext, exists, arginfo_phalcon_translate_adapterinterface_exists, ZEND_ACC_PUBLIC)
	PHP_FE_END
};

/**
 * Phalcon\Translate\Adapter\Gettext initializer
 */
PHALCON_INIT_CLASS(Phalcon_Translate_Adapter_Gettext){

	PHALCON_REGISTER_CLASS_EX(Phalcon\\Translate\\Adapter, Gettext, translate_adapter_gettext, phalcon_translate_adapter_ce, phalcon_translate_adapter_gettext_method_entry, 0);

	zend_declare_property_null(phalcon_translate_adapter_gettext_ce, SL("_locale"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_translate_adapter_gettext_ce, SL("_defaultDomain"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_translate_adapter_gettext_ce, SL("_directory"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_class_implements(phalcon_translate_adapter_gettext_ce TSRMLS_CC, 1, phalcon_translate_adapterinterface_ce);

	phalcon_translate_adapter_gettext_object_handlers                = phalcon_translate_adapter_object_handlers;
	phalcon_translate_adapter_gettext_object_handlers.read_dimension = phalcon_translate_adapter_gettext_read_dimension;
	phalcon_translate_adapter_gettext_object_handlers.has_dimension  = phalcon_translate_adapter_gettext_has_dimension;

	return SUCCESS;
}

/**
 * Phalcon\Translate\Adapter\Gettext constructor
 *
 * @param array $options
 * @throws \Phalcon\Translate\Exception
 */
PHP_METHOD(Phalcon_Translate_Adapter_Gettext, __construct){

	zval *options, *locale, *default_domain, *directory, *setting, *key = NULL, *value = NULL;
	HashTable *ah0;
	HashPosition hp0;
	zval **hd;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 0, &options);
	
	if (Z_TYPE_P(options) != IS_ARRAY) { 
		PHALCON_THROW_EXCEPTION_STRW(phalcon_translate_exception_ce, "Invalid options");
		return;
	}

	if (!phalcon_array_isset_string_fetch(&locale, options, SS("locale"))) {
		PHALCON_THROW_EXCEPTION_STRW(phalcon_translate_exception_ce, "Parameter \"locale\" is required");
		return;
	}

	if (!phalcon_array_isset_string_fetch(&default_domain, options, SS("defaultDomain"))) {
		PHALCON_THROW_EXCEPTION_STRW(phalcon_translate_exception_ce, "Parameter \"defaultDomain\" is required");
		return;
	}

	if (!phalcon_array_isset_string_fetch(&directory, options, SS("directory"))) {
		PHALCON_THROW_EXCEPTION_STRW(phalcon_translate_exception_ce, "Parameter \"directory\" is required");
		return;
	}

	phalcon_update_property_this(this_ptr, SL("_locale"), locale TSRMLS_CC);
	phalcon_update_property_this(this_ptr, SL("_defaultDomain"), default_domain TSRMLS_CC);
	phalcon_update_property_this(this_ptr, SL("_directory"), directory TSRMLS_CC);

	PHALCON_INIT_VAR(setting);
	PHALCON_CONCAT_SV(setting, "LC_ALL=", locale);

	PHALCON_CALL_FUNCTION(NULL, "putenv", setting);

	setlocale(LC_ALL, Z_STRVAL_P(locale));
	
	if (Z_TYPE_P(directory) == IS_ARRAY) {
		phalcon_is_iterable(directory, &ah0, &hp0, 0, 0);
		while (zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) == SUCCESS) {
			PHALCON_GET_HKEY(key, ah0, hp0);
			PHALCON_GET_HVALUE(value);

			bindtextdomain(Z_STRVAL_P(key), Z_STRVAL_P(value));

			zend_hash_move_forward_ex(ah0, &hp0);
		}
	} else {
		bindtextdomain(Z_STRVAL_P(default_domain), Z_STRVAL_P(directory));
	}

	textdomain(Z_STRVAL_P(default_domain));

	PHALCON_MM_RESTORE();
}

/**
 * Returns the translation related to the given key
 *
 * @param string $index
 * @param array $placeholders
 * @param string $domain
 * @return string
 */
PHP_METHOD(Phalcon_Translate_Adapter_Gettext, query){

	zval *index, *placeholders = NULL, *domain = NULL;
	zval *translation, *key = NULL, *value = NULL, *key_placeholder = NULL, *replaced = NULL;
	HashTable *ah0;
	HashPosition hp0;
	zval **hd;
	char *msgstr;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 2, &index, &placeholders, &domain);
	
	if (!domain) {
		msgstr = gettext(Z_STRVAL_P(index));
	} else {
		msgstr = dgettext(Z_STRVAL_P(domain), Z_STRVAL_P(index));
	}

	PHALCON_INIT_VAR(translation);
	ZVAL_STRING(translation, msgstr, 1);

	if (placeholders && Z_TYPE_P(placeholders) == IS_ARRAY && zend_hash_num_elements(Z_ARRVAL_P(placeholders))) {
		phalcon_is_iterable(placeholders, &ah0, &hp0, 0, 0);
		while (zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) == SUCCESS) {
			PHALCON_GET_HKEY(key, ah0, hp0);
			PHALCON_GET_HVALUE(value);

			PHALCON_INIT_NVAR(key_placeholder);
			PHALCON_CONCAT_SVS(key_placeholder, "%", key, "%");

			PHALCON_INIT_NVAR(replaced);
			phalcon_fast_str_replace(replaced, key_placeholder, value, translation);

			PHALCON_CPY_WRT(translation, replaced);

			zend_hash_move_forward_ex(ah0, &hp0);
		}
	}

	RETURN_CTOR(translation);
}

/**
 * Check whether is defined a translation key in the internal array
 *
 * @param string $index
 * @return bool
 */
PHP_METHOD(Phalcon_Translate_Adapter_Gettext, exists){

	zval *index, *domain = NULL;
	char *msgstr;

	phalcon_fetch_params(0, 1, 1, &index, &domain);

	if (!domain) {
		msgstr = gettext(Z_STRVAL_P(index));
	} else {
		msgstr = dgettext(Z_STRVAL_P(domain), Z_STRVAL_P(index));
	}

	if (strlen(msgstr) > 0) {
		RETURN_TRUE;
	} else {
		RETURN_FALSE;
	}
}
