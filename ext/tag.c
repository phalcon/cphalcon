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

#include "tag.h"
#include "tag/exception.h"
#include "tag/select.h"
#include "di.h"
#include "diinterface.h"
#include "escaperinterface.h"
#include "mvc/urlinterface.h"

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

#include "interned-strings.h"

/**
 * Phalcon\Tag
 *
 * Phalcon\Tag is designed to simplify building of HTML tags.
 * It provides a set of helpers to generate HTML in a dynamic way.
 * This component is an abstract class that you can extend to add more helpers.
 */
zend_class_entry *phalcon_tag_ce;

PHP_METHOD(Phalcon_Tag, setDI);
PHP_METHOD(Phalcon_Tag, getDI);
PHP_METHOD(Phalcon_Tag, getUrlService);
PHP_METHOD(Phalcon_Tag, getEscaperService);
PHP_METHOD(Phalcon_Tag, getAutoescape);
PHP_METHOD(Phalcon_Tag, setAutoescape);
PHP_METHOD(Phalcon_Tag, setDefault);
PHP_METHOD(Phalcon_Tag, setDefaults);
PHP_METHOD(Phalcon_Tag, hasValue);
PHP_METHOD(Phalcon_Tag, getValue);
PHP_METHOD(Phalcon_Tag, resetInput);
PHP_METHOD(Phalcon_Tag, linkTo);
PHP_METHOD(Phalcon_Tag, _inputField);
PHP_METHOD(Phalcon_Tag, _inputFieldChecked);
PHP_METHOD(Phalcon_Tag, colorField);
PHP_METHOD(Phalcon_Tag, textField);
PHP_METHOD(Phalcon_Tag, numericField);
PHP_METHOD(Phalcon_Tag, rangeField);
PHP_METHOD(Phalcon_Tag, emailField);
PHP_METHOD(Phalcon_Tag, dateField);
PHP_METHOD(Phalcon_Tag, dateTimeField);
PHP_METHOD(Phalcon_Tag, dateTimeLocalField);
PHP_METHOD(Phalcon_Tag, monthField);
PHP_METHOD(Phalcon_Tag, timeField);
PHP_METHOD(Phalcon_Tag, weekField);
PHP_METHOD(Phalcon_Tag, passwordField);
PHP_METHOD(Phalcon_Tag, hiddenField);
PHP_METHOD(Phalcon_Tag, fileField);
PHP_METHOD(Phalcon_Tag, checkField);
PHP_METHOD(Phalcon_Tag, radioField);
PHP_METHOD(Phalcon_Tag, imageInput);
PHP_METHOD(Phalcon_Tag, searchField);
PHP_METHOD(Phalcon_Tag, telField);
PHP_METHOD(Phalcon_Tag, urlField);
PHP_METHOD(Phalcon_Tag, submitButton);
PHP_METHOD(Phalcon_Tag, selectStatic);
PHP_METHOD(Phalcon_Tag, select);
PHP_METHOD(Phalcon_Tag, textArea);
PHP_METHOD(Phalcon_Tag, form);
PHP_METHOD(Phalcon_Tag, endForm);
PHP_METHOD(Phalcon_Tag, setTitle);
PHP_METHOD(Phalcon_Tag, setTitleSeparator);
PHP_METHOD(Phalcon_Tag, appendTitle);
PHP_METHOD(Phalcon_Tag, prependTitle);
PHP_METHOD(Phalcon_Tag, getTitleSeparator);
PHP_METHOD(Phalcon_Tag, getTitle);
PHP_METHOD(Phalcon_Tag, stylesheetLink);
PHP_METHOD(Phalcon_Tag, javascriptInclude);
PHP_METHOD(Phalcon_Tag, image);
PHP_METHOD(Phalcon_Tag, friendlyTitle);
PHP_METHOD(Phalcon_Tag, setDocType);
PHP_METHOD(Phalcon_Tag, getDocType);
PHP_METHOD(Phalcon_Tag, tagHtml);
PHP_METHOD(Phalcon_Tag, tagHtmlClose);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_tag_setdi, 0, 0, 1)
	ZEND_ARG_INFO(0, dependencyInjector)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_tag_setautoescape, 0, 0, 1)
	ZEND_ARG_INFO(0, autoescape)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_tag_setdefault, 0, 0, 2)
	ZEND_ARG_INFO(0, id)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_tag_setdefaults, 0, 0, 1)
	ZEND_ARG_INFO(0, values)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_tag_hasvalue, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_tag_getvalue, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_INFO(0, params)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_tag_linkto, 0, 0, 1)
	ZEND_ARG_INFO(0, parameters)
	ZEND_ARG_INFO(0, text)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_tag_generic_field, 0, 0, 1)
	ZEND_ARG_INFO(0, parameters)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_tag_selectstatic, 0, 0, 1)
	ZEND_ARG_INFO(0, parameters)
	ZEND_ARG_INFO(0, data)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_tag_select, 0, 0, 1)
	ZEND_ARG_INFO(0, parameters)
	ZEND_ARG_INFO(0, data)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_tag_textarea, 0, 0, 1)
	ZEND_ARG_INFO(0, parameters)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_tag_form, 0, 0, 0)
	ZEND_ARG_INFO(0, parameters)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_tag_settitle, 0, 0, 1)
	ZEND_ARG_INFO(0, title)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_tag_settitleseparator, 0, 0, 1)
	ZEND_ARG_INFO(0, separator)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_tag_appendtitle, 0, 0, 1)
	ZEND_ARG_INFO(0, title)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_tag_prependtitle, 0, 0, 1)
	ZEND_ARG_INFO(0, title)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_tag_gettitle, 0, 0, 0)
	ZEND_ARG_INFO(0, tags)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_tag_stylesheetlink, 0, 0, 0)
	ZEND_ARG_INFO(0, parameters)
	ZEND_ARG_INFO(0, local)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_tag_javascriptinclude, 0, 0, 0)
	ZEND_ARG_INFO(0, parameters)
	ZEND_ARG_INFO(0, local)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_tag_image, 0, 0, 0)
	ZEND_ARG_INFO(0, parameters)
	ZEND_ARG_INFO(0, local)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_tag_friendlytitle, 0, 0, 1)
	ZEND_ARG_INFO(0, text)
	ZEND_ARG_INFO(0, separator)
	ZEND_ARG_INFO(0, lowercase)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_tag_setdoctype, 0, 0, 1)
	ZEND_ARG_INFO(0, doctype)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_tag_taghtml, 0, 0, 1)
	ZEND_ARG_INFO(0, tagName)
	ZEND_ARG_INFO(0, parameters)
	ZEND_ARG_INFO(0, selfClose)
	ZEND_ARG_INFO(0, onlyStart)
	ZEND_ARG_INFO(0, useEol)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_tag_taghtmlclose, 0, 0, 1)
	ZEND_ARG_INFO(0, tagName)
	ZEND_ARG_INFO(0, useEol)
ZEND_END_ARG_INFO()

static const zend_function_entry phalcon_tag_method_entry[] = {
	PHP_ME(Phalcon_Tag, setDI, arginfo_phalcon_tag_setdi, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Phalcon_Tag, getDI, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Phalcon_Tag, getUrlService, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Phalcon_Tag, getEscaperService, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Phalcon_Tag, getAutoescape, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Phalcon_Tag, setAutoescape, arginfo_phalcon_tag_setautoescape, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Phalcon_Tag, setDefault, arginfo_phalcon_tag_setdefault, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Phalcon_Tag, setDefaults, arginfo_phalcon_tag_setdefaults, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_MALIAS(Phalcon_Tag, displayTo, setDefault, arginfo_phalcon_tag_setdefault, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Phalcon_Tag, hasValue, arginfo_phalcon_tag_hasvalue, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Phalcon_Tag, getValue, arginfo_phalcon_tag_getvalue, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Phalcon_Tag, resetInput, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Phalcon_Tag, linkTo, arginfo_phalcon_tag_linkto, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Phalcon_Tag, _inputField, NULL, ZEND_ACC_STATIC|ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Tag, _inputFieldChecked, NULL, ZEND_ACC_STATIC|ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Tag, colorField, arginfo_phalcon_tag_generic_field, ZEND_ACC_STATIC|ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Tag, textField, arginfo_phalcon_tag_generic_field, ZEND_ACC_STATIC|ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Tag, numericField, arginfo_phalcon_tag_generic_field, ZEND_ACC_STATIC|ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Tag, rangeField, arginfo_phalcon_tag_generic_field, ZEND_ACC_STATIC|ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Tag, emailField, arginfo_phalcon_tag_generic_field, ZEND_ACC_STATIC|ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Tag, dateField, arginfo_phalcon_tag_generic_field, ZEND_ACC_STATIC|ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Tag, dateTimeField, arginfo_phalcon_tag_generic_field, ZEND_ACC_STATIC|ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Tag, dateTimeLocalField, arginfo_phalcon_tag_generic_field, ZEND_ACC_STATIC|ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Tag, monthField, arginfo_phalcon_tag_generic_field, ZEND_ACC_STATIC|ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Tag, timeField, arginfo_phalcon_tag_generic_field, ZEND_ACC_STATIC|ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Tag, weekField, arginfo_phalcon_tag_generic_field, ZEND_ACC_STATIC|ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Tag, passwordField, arginfo_phalcon_tag_generic_field, ZEND_ACC_STATIC|ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Tag, hiddenField, arginfo_phalcon_tag_generic_field, ZEND_ACC_STATIC|ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Tag, searchField, arginfo_phalcon_tag_generic_field, ZEND_ACC_STATIC|ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Tag, telField, arginfo_phalcon_tag_generic_field, ZEND_ACC_STATIC|ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Tag, urlField, arginfo_phalcon_tag_generic_field, ZEND_ACC_STATIC|ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Tag, fileField, arginfo_phalcon_tag_generic_field, ZEND_ACC_STATIC|ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Tag, checkField, arginfo_phalcon_tag_generic_field, ZEND_ACC_STATIC|ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Tag, radioField, arginfo_phalcon_tag_generic_field, ZEND_ACC_STATIC|ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Tag, imageInput, arginfo_phalcon_tag_generic_field, ZEND_ACC_STATIC|ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Tag, submitButton, arginfo_phalcon_tag_generic_field, ZEND_ACC_STATIC|ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Tag, selectStatic, arginfo_phalcon_tag_selectstatic, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Phalcon_Tag, select, arginfo_phalcon_tag_select, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Phalcon_Tag, textArea, arginfo_phalcon_tag_textarea, ZEND_ACC_STATIC|ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Tag, form, arginfo_phalcon_tag_form, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Phalcon_Tag, endForm, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Phalcon_Tag, setTitle, arginfo_phalcon_tag_settitle, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Phalcon_Tag, setTitleSeparator, arginfo_phalcon_tag_settitleseparator, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Phalcon_Tag, appendTitle, arginfo_phalcon_tag_appendtitle, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Phalcon_Tag, prependTitle, arginfo_phalcon_tag_prependtitle, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Phalcon_Tag, getTitle, arginfo_phalcon_tag_gettitle, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Phalcon_Tag, getTitleSeparator, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Phalcon_Tag, stylesheetLink, arginfo_phalcon_tag_stylesheetlink, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Phalcon_Tag, javascriptInclude, arginfo_phalcon_tag_javascriptinclude, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Phalcon_Tag, image, arginfo_phalcon_tag_image, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Phalcon_Tag, friendlyTitle, arginfo_phalcon_tag_friendlytitle, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Phalcon_Tag, setDocType, arginfo_phalcon_tag_setdoctype, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Phalcon_Tag, getDocType, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Phalcon_Tag, tagHtml, arginfo_phalcon_tag_taghtml, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Phalcon_Tag, tagHtmlClose, arginfo_phalcon_tag_taghtmlclose, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_FE_END
};

/**
 * Phalcon\Tag initializer
 */
PHALCON_INIT_CLASS(Phalcon_Tag){

	PHALCON_REGISTER_CLASS(Phalcon, Tag, tag, phalcon_tag_method_entry, 0);

	zend_declare_property_null(phalcon_tag_ce, SL("_displayValues"), ZEND_ACC_PROTECTED|ZEND_ACC_STATIC TSRMLS_CC);
	zend_declare_property_null(phalcon_tag_ce, SL("_documentTitle"), ZEND_ACC_PROTECTED|ZEND_ACC_STATIC TSRMLS_CC);
	zend_declare_property_null(phalcon_tag_ce, SL("_documentTitleSeparator"), ZEND_ACC_PROTECTED|ZEND_ACC_STATIC TSRMLS_CC);
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

static void phalcon_tag_get_escaper(zval **return_value_ptr, zval *params TSRMLS_DC)
{
	zval *autoescape, *result = NULL;

	if (!phalcon_array_isset_string_fetch(&autoescape, params, SS("escape"))) {
		autoescape = phalcon_fetch_static_property_ce(phalcon_tag_ce, SL("_autoEscape") TSRMLS_CC);
	}

	if (zend_is_true(autoescape)) {
		if (FAILURE == phalcon_call_class_method_aparams(&result, NULL, phalcon_fcall_self, NULL, SL("getescaperservice"), 0, NULL TSRMLS_CC)) {
			assert(result == NULL);
		}
	}

	*return_value_ptr = result;
}

static zend_bool phalcon_tag_attribute_filter(HashTable *ht, void *pData, zend_hash_key *hash_key, void *pParam)
{
	zval **z = (zval**)pData;
	return hash_key->arKey && hash_key->nKeyLength && Z_TYPE_PP(z) != IS_ARRAY;
}

PHALCON_STATIC void phalcon_tag_render_attributes(zval *code, zval *attributes TSRMLS_DC)
{
	zval *escaper, *escaped = NULL, *attrs;
	zval **value;
	HashPosition hp;
	uint i;

	struct str_size_t {
		const char *str;
		uint size;
	};

	static const struct str_size_t order[9] = {
		{ SS("type") },
		{ SS("for") },
		{ SS("src") },
		{ SS("href") },
		{ SS("action") },
		{ SS("id") },
		{ SS("name") },
		{ SS("value") },
		{ SS("class") },
	};

	assert(Z_TYPE_P(attributes) == IS_ARRAY);

	PHALCON_MM_GROW();

	PHALCON_OBS_VAR(escaper);
	phalcon_tag_get_escaper(&escaper, attributes TSRMLS_CC);
	if (EG(exception)) {
		assert(escaper == NULL);
		PHALCON_MM_RESTORE();
		return;
	}

	PHALCON_INIT_VAR(attrs);
	array_init_size(attrs, zend_hash_num_elements(Z_ARRVAL_P(attributes)));

	for (i=0; i<sizeof(order)/sizeof(order[0]); ++i) {
		if (phalcon_hash_find(Z_ARRVAL_P(attributes), order[i].str, order[i].size, (void**)&value) == SUCCESS) {
			Z_ADDREF_PP(value);
			add_assoc_zval_ex(attrs, order[i].str, order[i].size, *value);
		}
	}

	zend_hash_merge_ex(Z_ARRVAL_P(attrs), Z_ARRVAL_P(attributes), (copy_ctor_func_t)zval_add_ref, sizeof(zval*), phalcon_tag_attribute_filter, NULL);

	if (phalcon_array_isset_string(attrs, SS("escape"))) {
		phalcon_array_unset_string(&attrs, SS("escape"), 0);
	}

	if (escaper) {
		for (
			zend_hash_internal_pointer_reset_ex(Z_ARRVAL_P(attrs), &hp);
			zend_hash_get_current_data_ex(Z_ARRVAL_P(attrs), (void**)&value, &hp) == SUCCESS;
			zend_hash_move_forward_ex(Z_ARRVAL_P(attrs), &hp)
		) {
			zval key = phalcon_get_current_key_w(Z_ARRVAL_P(attrs), &hp);
			if (Z_TYPE_P(&key) == IS_STRING && Z_TYPE_PP(value) != IS_NULL) {
				PHALCON_CALL_METHOD(&escaped, escaper, "escapehtmlattr", *value);
				PHALCON_SCONCAT_SVSVS(code, " ", &key, "=\"", escaped, "\"");
			}
		}
	}
	else {
		for (
			zend_hash_internal_pointer_reset_ex(Z_ARRVAL_P(attrs), &hp);
			zend_hash_get_current_data_ex(Z_ARRVAL_P(attrs), (void**)&value, &hp) == SUCCESS;
			zend_hash_move_forward_ex(Z_ARRVAL_P(attrs), &hp)
		) {
			zval key = phalcon_get_current_key_w(Z_ARRVAL_P(attrs), &hp);
			if (Z_TYPE_P(&key) == IS_STRING && Z_TYPE_PP(value) != IS_NULL) {
				PHALCON_SCONCAT_SVSVS(code, " ", &key, "=\"", *value, "\"");
			}
		}
	}

	PHALCON_MM_RESTORE();
}

/**
 * Sets the dependency injector container.
 *
 * @param Phalcon\DiInterface $dependencyInjector
 */
PHP_METHOD(Phalcon_Tag, setDI){

	zval *dependency_injector;

	phalcon_fetch_params(0, 1, 0, &dependency_injector);
	PHALCON_VERIFY_INTERFACE_EX(dependency_injector, phalcon_diinterface_ce, phalcon_tag_exception_ce, 0);
	phalcon_update_static_property_ce(phalcon_tag_ce, SL("_dependencyInjector"), dependency_injector TSRMLS_CC);
}

/**
 * Internally gets the dependency injector
 *
 * @return Phalcon\DiInterface
 */
PHP_METHOD(Phalcon_Tag, getDI){

	zval *dependency_injector;

	dependency_injector = phalcon_fetch_static_property_ce(phalcon_tag_ce, SL("_dependencyInjector") TSRMLS_CC);
	RETURN_CTORW(dependency_injector);
}

/**
 * Return a URL service from the default DI
 *
 * @return Phalcon\Mvc\UrlInterface
 */
PHP_METHOD(Phalcon_Tag, getUrlService){

	zval *url = NULL, *dependency_injector = NULL, *service;

	PHALCON_MM_GROW();

	url = phalcon_fetch_static_property_ce(phalcon_tag_ce, SL("_urlService") TSRMLS_CC);
	if (Z_TYPE_P(url) != IS_OBJECT) {
	
		dependency_injector = phalcon_fetch_static_property_ce(phalcon_tag_ce, SL("_dependencyInjector") TSRMLS_CC);
		if (Z_TYPE_P(dependency_injector) != IS_OBJECT) {
			dependency_injector = NULL;
			PHALCON_CALL_CE_STATIC(&dependency_injector, phalcon_di_ce, "getdefault");
		}
	
		if (Z_TYPE_P(dependency_injector) != IS_OBJECT) {
			PHALCON_THROW_EXCEPTION_STR(phalcon_tag_exception_ce, "A dependency injector container is required to obtain the \"url\" service");
			return;
		}

		PHALCON_VERIFY_INTERFACE(dependency_injector, phalcon_diinterface_ce);
	
		PHALCON_INIT_VAR(service);
		PHALCON_ZVAL_MAYBE_INTERNED_STRING(service, phalcon_interned_url);
	
		url = NULL;
		PHALCON_CALL_METHOD(&url, dependency_injector, "getshared", service);
		PHALCON_VERIFY_INTERFACE(url, phalcon_mvc_urlinterface_ce);
		phalcon_update_static_property_ce(phalcon_tag_ce, SL("_urlService"), url TSRMLS_CC);
	}
	
	RETURN_CTOR(url);
}

/**
 * Returns an Escaper service from the default DI
 *
 * @return Phalcon\EscaperInterface
 */
PHP_METHOD(Phalcon_Tag, getEscaperService){

	zval *escaper = NULL, *dependency_injector = NULL, *service;

	PHALCON_MM_GROW();

	escaper = phalcon_fetch_static_property_ce(phalcon_tag_ce, SL("_escaperService") TSRMLS_CC);
	if (Z_TYPE_P(escaper) != IS_OBJECT) {
	
		dependency_injector = phalcon_fetch_static_property_ce(phalcon_tag_ce, SL("_dependencyInjector") TSRMLS_CC);
		if (Z_TYPE_P(dependency_injector) != IS_OBJECT) {
			dependency_injector = NULL;
			PHALCON_CALL_CE_STATIC(&dependency_injector, phalcon_di_ce, "getdefault");
		}
	
		if (Z_TYPE_P(dependency_injector) != IS_OBJECT) {
			PHALCON_THROW_EXCEPTION_STR(phalcon_tag_exception_ce, "A dependency injector container is required to obtain the \"escaper\" service");
			return;
		}

		PHALCON_VERIFY_INTERFACE(dependency_injector, phalcon_diinterface_ce);
	
		PHALCON_ALLOC_GHOST_ZVAL(service);
		PHALCON_ZVAL_MAYBE_INTERNED_STRING(service, phalcon_interned_escaper);
	
		escaper = NULL;
		PHALCON_CALL_METHOD(&escaper, dependency_injector, "getshared", service);
		PHALCON_VERIFY_INTERFACE(escaper, phalcon_escaperinterface_ce);
		phalcon_update_static_property_ce(phalcon_tag_ce, SL("_escaperService"), escaper TSRMLS_CC);
	}
	
	RETURN_CTOR(escaper);
}

/**
 * Get current autoescape mode
 *
 * @return bool
 */
PHP_METHOD(Phalcon_Tag, getAutoescape) {

	zval *autoescape;

	autoescape = phalcon_fetch_static_property_ce(phalcon_tag_ce, SL("_autoEscape") TSRMLS_CC);
	RETURN_ZVAL(autoescape, 1, 0);
}

/**
 * Set autoescape mode in generated html
 *
 * @param boolean $autoescape
 */
PHP_METHOD(Phalcon_Tag, setAutoescape){

	zval *autoescape;

	phalcon_fetch_params(0, 1, 0, &autoescape);
	
	phalcon_update_static_property_ce(phalcon_tag_ce, SL("_autoEscape"), autoescape TSRMLS_CC);
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

	phalcon_fetch_params(0, 2, 0, &id, &value);
	
	if (Z_TYPE_P(value) != IS_NULL) {
		if (Z_TYPE_P(value) == IS_ARRAY || Z_TYPE_P(value) == IS_OBJECT) {
			PHALCON_THROW_EXCEPTION_STRW(phalcon_tag_exception_ce, "Only scalar values can be assigned to UI components");
			return;
		}
	}

	phalcon_update_static_property_array_multi_ce(phalcon_tag_ce, SL("_displayValues"), value TSRMLS_CC, SL("z"), 1, id);
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
	phalcon_update_static_property_ce(phalcon_tag_ce, SL("_displayValues"), values TSRMLS_CC);
	
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

	phalcon_fetch_params(0, 1, 0, &name);
	
	display_values = phalcon_fetch_static_property_ce(phalcon_tag_ce, SL("_displayValues") TSRMLS_CC);
	
	/** 
	 * Check if there is a predefined value for it
	 */
	if (phalcon_array_isset(display_values, name)) {
		RETURN_TRUE;
	}

	/**
	 * Check if there is a post value for the item
	 */
	_POST = phalcon_get_global(SS("_POST") TSRMLS_CC);
	RETURN_BOOL(phalcon_array_isset(_POST, name));
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

	phalcon_fetch_params(0, 1, 1, &name, &params);
	
	if (!params || !phalcon_array_isset_string_fetch(&value, params, SS("value"))) {
		display_values = phalcon_fetch_static_property_ce(phalcon_tag_ce, SL("_displayValues") TSRMLS_CC);

		assert(value == NULL);

		/**
		 * Check if there is a predefined value for it
		 */
		if (!phalcon_array_isset_fetch(&value, display_values, name)) {

			assert(value == NULL);

			/* Check if there is a post value for the item */
			_POST = phalcon_get_global(SS("_POST") TSRMLS_CC);
			if (!phalcon_array_isset_fetch(&value, _POST, name)) {
				RETURN_NULL();
			}
		}
	}
	
	assert(value != NULL);
	RETURN_ZVAL(value, 1, 0);
}

/**
 * Resets the request and internal values to avoid those fields will have any default value
 */
PHP_METHOD(Phalcon_Tag, resetInput){

	zval *empty_array;

	MAKE_STD_ZVAL(empty_array);
	array_init(empty_array);

	phalcon_update_static_property_ce(phalcon_tag_ce, SL("_displayValues"), empty_array TSRMLS_CC);

	phalcon_set_symbol_str(SS("_POST"), empty_array TSRMLS_CC);

	zval_ptr_dtor(&empty_array);
}

/**
 * Builds a HTML A tag using framework conventions
 *
 *<code>
 *	echo Phalcon\Tag::linkTo('signup/register', 'Register Here!');
 *	echo Phalcon\Tag::linkTo(array('signup/register', 'Register Here!'));
 *	echo Phalcon\Tag::linkTo(array('signup/register', 'Register Here!', 'class' => 'btn-primary'));
 *	echo Phalcon\Tag::linkTo('http://phalconphp.com/', 'Google', FALSE);
 *	echo Phalcon\Tag::linkTo(array('http://phalconphp.com/', 'Phalcon Home', FALSE));
 *	echo Phalcon\Tag::linkTo(array('http://phalconphp.com/', 'Phalcon Home', 'local' =>FALSE));
 *</code>
 *
 * @param array|string $parameters
 * @param string $text
 * @param boolean $local
 * @return string
 */
PHP_METHOD(Phalcon_Tag, linkTo){

	zval *parameters, *text = NULL, *local = NULL,  *params = NULL;
	zval *action, *url = NULL, *internal_url = NULL, *link_text, *z_local;
	zval *code, *query;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 2, &parameters, &text, &local);
	
	if (!text) {
		text = PHALCON_GLOBAL(z_null);
	}

	if (!local) {
		local = PHALCON_GLOBAL(z_true);
	}
	
	if (Z_TYPE_P(parameters) != IS_ARRAY) { 
		PHALCON_INIT_VAR(params);
		array_init_size(params, 3);
		phalcon_array_append(&params, parameters, 0);
		phalcon_array_append(&params, text, 0);
		phalcon_array_append(&params, local, 0);
	} else {
		PHALCON_CPY_WRT_CTOR(params, parameters);
	}
	
	if (phalcon_array_isset_long_fetch(&action, params, 0)) {
	} else if (phalcon_array_isset_string_fetch(&action, params, SS("action"))) {
		phalcon_array_unset_string(&params, SS("action"), 0);
	}
	else {
		PHALCON_INIT_VAR(action);
		ZVAL_EMPTY_STRING(action);
	}
	
	if (phalcon_array_isset_long_fetch(&link_text, params, 1)) {
	} else if (phalcon_array_isset_string_fetch(&link_text, params, SS("text"))) {
		phalcon_array_unset_string(&params, SS("text"), 0);
	}
	else {
		PHALCON_INIT_VAR(link_text);
		ZVAL_EMPTY_STRING(link_text);
	}

	if (phalcon_array_isset_long_fetch(&z_local, params, 2)) {
	} else if (phalcon_array_isset_string_fetch(&z_local, params, SS("local"))) {
		phalcon_array_unset_string(&params, SS("local"), 0);
	} else {
		PHALCON_INIT_VAR(z_local);
		ZVAL_NULL(z_local);
	}
	
	if (phalcon_array_isset_string_fetch(&query, params, SS("query"))) {
		phalcon_array_unset_string(&params, SS("query"), 0);
	} else {
		PHALCON_INIT_VAR(query);
		ZVAL_NULL(query);
	}

	PHALCON_CALL_SELF(&url, "geturlservice");		
	PHALCON_CALL_METHOD(&internal_url, url, "get", action, query, z_local);
	phalcon_array_update_string(&params, SL("href"), internal_url, PH_COPY);

	PHALCON_INIT_VAR(code);
	ZVAL_STRING(code, "<a", 1);

	phalcon_tag_render_attributes(code, params TSRMLS_CC);
	if (EG(exception)) {
		PHALCON_MM_RESTORE();
		return;
	}

	PHALCON_CONCAT_VSVS(return_value, code, ">", link_text, "</a>");
	
	PHALCON_MM_RESTORE();
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
	zval *id = NULL, *name, *code, *doctype, *escaper;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 2, 1, &type, &parameters, &as_value);
	
	if (!as_value) {
		as_value = PHALCON_GLOBAL(z_false);
	}
	
	if (Z_TYPE_P(parameters) != IS_ARRAY) { 
		PHALCON_INIT_VAR(params);
		array_init_size(params, 1);
		phalcon_array_append(&params, parameters, 0);
	} else {
		PHALCON_CPY_WRT_CTOR(params, parameters);
	}
	
	if (PHALCON_IS_FALSE(as_value)) {
		if (!phalcon_array_isset_long_fetch(&id, params, 0)) {
			PHALCON_OBS_VAR(id);
			phalcon_array_fetch_string(&id, params, SL("id"), PH_NOISY);
			phalcon_array_update_long(&params, 0, id, PH_COPY);
		}

		if (phalcon_array_isset_string_fetch(&name, params, SS("name"))) {
			if (!zend_is_true(name)) {
				phalcon_array_update_string(&params, ISL(name), id, PH_COPY);
			}
		}
		else {
			phalcon_array_update_string(&params, ISL(name), id, PH_COPY);
		}

		/**
		 * Automatically assign the id if the name is not an array
		 */
		if (!phalcon_memnstr_str(id, SL("["))) {
			if (!phalcon_array_isset_string(params, SS("id"))) {
				phalcon_array_update_string(&params, SL("id"), id, PH_COPY);
			}
		}

		PHALCON_CALL_SELF(&value, "getvalue", id, params);
		phalcon_array_update_string(&params, ISL(value), value, PH_COPY);
	} else {
		/**
		 * Use the 'id' as value if the user hadn't set it
		 */
		if (!phalcon_array_isset_string(params, SS("value"))) {
			if (phalcon_array_isset_long_fetch(&value, params, 0)) {
				phalcon_array_update_string(&params, ISL(value), value, PH_COPY);
			}
		}
	}

	PHALCON_OBS_VAR(escaper);
	phalcon_tag_get_escaper(&escaper, params TSRMLS_CC);
	if (EG(exception)) {
		assert(escaper == NULL);
		PHALCON_MM_RESTORE();
		return;
	}

	phalcon_array_update_string(&params, ISL(type), type, PH_COPY);

	PHALCON_INIT_VAR(code);
	ZVAL_STRING(code, "<input", 1);

	phalcon_tag_render_attributes(code, params TSRMLS_CC);
	if (EG(exception)) {
		PHALCON_MM_RESTORE();
		return;
	}

	doctype = phalcon_fetch_static_property_ce(phalcon_tag_ce, SL("_documentType") TSRMLS_CC);
	
	/** 
	 * Check if Doctype is XHTML
	 */
	if (PHALCON_GT_LONG(doctype, 5)) {
		PHALCON_CONCAT_VS(return_value, code, " />");
	} else {
		PHALCON_CONCAT_VS(return_value, code, ">");
	}
	
	PHALCON_MM_RESTORE();
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
	zval *current_value, *code, *doctype;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 2, 0, &type, &parameters);
	
	if (Z_TYPE_P(parameters) != IS_ARRAY) { 
		PHALCON_INIT_VAR(params);
		array_init_size(params, 1);
		phalcon_array_append(&params, parameters, 0);
	} else {
		PHALCON_CPY_WRT_CTOR(params, parameters);
	}
	
	if (!phalcon_array_isset_long_fetch(&id, params, 0)) {
		PHALCON_OBS_VAR(id);
		phalcon_array_fetch_string(&id, params, SL("id"), PH_NOISY);
		phalcon_array_update_long(&params, 0, id, PH_COPY);
	}
	
	if (!phalcon_array_isset_string_fetch(&name, params, SS("name"))) {
		phalcon_array_update_string(&params, ISL(name), id, PH_COPY);
	} else {
		if (!zend_is_true(name)) {
			phalcon_array_update_string(&params, ISL(name), id, PH_COPY);
		}
	}
	
	/** 
	 * Automatically assign the id if the name is not an array
	 */
	if (!phalcon_memnstr_str(id, SL("["))) {
		if (!phalcon_array_isset_string(params, SS("id"))) {
			phalcon_array_update_string(&params, SL("id"), id, PH_COPY);
		}
	}

	/**
	 * Automatically check inputs
	 */
	if (phalcon_array_isset_string_fetch(&current_value, params, SS("value"))) {
		phalcon_array_unset_string(&params, SS("value"), 0);

		PHALCON_CALL_SELF(&value, "getvalue", id, params);

		if (Z_TYPE_P(value) != IS_NULL && PHALCON_IS_EQUAL(current_value, value)) {
			phalcon_array_update_string_string(&params, SL("checked"), SL("checked"), 0);
		}

		phalcon_array_update_string(&params, ISL(value), current_value, PH_COPY);
	} else {
		PHALCON_CALL_SELF(&value, "getvalue", id, params);

		/**
		 * Evaluate the value in POST
		 */
		if (zend_is_true(value)) {
			phalcon_array_update_string_string(&params, SL("checked"), SL("checked"), 0);
		}

		phalcon_array_update_string(&params, ISL(value), value, PH_COPY);
	}

	phalcon_array_update_string(&params, ISL(type), type, PH_COPY);

	PHALCON_INIT_VAR(code);
	ZVAL_STRING(code, "<input", 1);

	phalcon_tag_render_attributes(code, params TSRMLS_CC);
	if (EG(exception)) {
		PHALCON_MM_RESTORE();
		return;
	}

	doctype = phalcon_fetch_static_property_ce(phalcon_tag_ce, SL("_documentType") TSRMLS_CC);
	
	/** 
	 * Check if Doctype is XHTML
	 */
	if (PHALCON_GT_LONG(doctype, 5)) {
		PHALCON_CONCAT_VS(return_value, code, " />");
	} else {
		PHALCON_CONCAT_VS(return_value, code, ">");
	}
	
	PHALCON_MM_RESTORE();
}

static void phalcon_tag_generic_field(INTERNAL_FUNCTION_PARAMETERS, const char* type, int as_value)
{
	zval *parameters, *field_type;

	phalcon_fetch_params(0, 1, 0, &parameters);

	PHALCON_ALLOC_GHOST_ZVAL(field_type);
	ZVAL_STRING(field_type, type, 1);

	if (as_value) {
		PHALCON_RETURN_CALL_SELFW("_inputfield", field_type, parameters, PHALCON_GLOBAL(z_true));
	}
	else {
		PHALCON_RETURN_CALL_SELFW("_inputfield", field_type, parameters);
	}
}

static void phalcon_tag_generic_field_checked(INTERNAL_FUNCTION_PARAMETERS, const char* type)
{
	zval *parameters, *field_type;

	phalcon_fetch_params(0, 1, 0, &parameters);

	PHALCON_ALLOC_GHOST_ZVAL(field_type);
	ZVAL_STRING(field_type, type, 1);
	PHALCON_RETURN_CALL_SELFW("_inputfieldchecked", field_type, parameters);
}

/**
 * Builds a HTML input[type="color"] tag
 *
 * @param array $parameters
 * @return string
 */
PHP_METHOD(Phalcon_Tag, colorField){

	phalcon_tag_generic_field(INTERNAL_FUNCTION_PARAM_PASSTHRU, "color", 0);
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

	phalcon_tag_generic_field(INTERNAL_FUNCTION_PARAM_PASSTHRU, "text", 0);
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

	phalcon_tag_generic_field(INTERNAL_FUNCTION_PARAM_PASSTHRU, "number", 0);
}

/**
 * Builds a HTML input[type="range"] tag
 *
 * @param array $parameters
 * @return string
 */
PHP_METHOD(Phalcon_Tag, rangeField){

	phalcon_tag_generic_field(INTERNAL_FUNCTION_PARAM_PASSTHRU, "range", 0);
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
	
	phalcon_tag_generic_field(INTERNAL_FUNCTION_PARAM_PASSTHRU, "email", 0);
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

	phalcon_tag_generic_field(INTERNAL_FUNCTION_PARAM_PASSTHRU, "date", 0);
}

/**
 * Builds a HTML input[type="datetime"] tag
 *
 * @param array $parameters
 * @return string
 */
PHP_METHOD(Phalcon_Tag, dateTimeField){

	phalcon_tag_generic_field(INTERNAL_FUNCTION_PARAM_PASSTHRU, "datetime", 0);
}

/**
 * Builds a HTML input[type="datetime-local"] tag
 *
 * @param array $parameters
 * @return string
 */
PHP_METHOD(Phalcon_Tag, dateTimeLocalField){

	phalcon_tag_generic_field(INTERNAL_FUNCTION_PARAM_PASSTHRU, "datetime-local", 0);
}

/**
 * Builds a HTML input[type="month"] tag
 *
 * @param array $parameters
 * @return string
 */
PHP_METHOD(Phalcon_Tag, monthField){

	phalcon_tag_generic_field(INTERNAL_FUNCTION_PARAM_PASSTHRU, "month", 0);
}

/**
 * Builds a HTML input[type="time"] tag
 *
 * @param array $parameters
 * @return string
 */
PHP_METHOD(Phalcon_Tag, timeField){

	phalcon_tag_generic_field(INTERNAL_FUNCTION_PARAM_PASSTHRU, "time", 0);
}

/**
 * Builds a HTML input[type="week"] tag
 *
 * @param array $parameters
 * @return string
 */
PHP_METHOD(Phalcon_Tag, weekField){

	phalcon_tag_generic_field(INTERNAL_FUNCTION_PARAM_PASSTHRU, "week", 0);
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

	phalcon_tag_generic_field(INTERNAL_FUNCTION_PARAM_PASSTHRU, "password", 0);
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

	phalcon_tag_generic_field(INTERNAL_FUNCTION_PARAM_PASSTHRU, "hidden", 0);
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

	phalcon_tag_generic_field(INTERNAL_FUNCTION_PARAM_PASSTHRU, "file", 0);
}

/**
 * Builds a HTML input[type="search"] tag
 *
 * @param array $parameters
 * @return string
 */
PHP_METHOD(Phalcon_Tag, searchField){

	phalcon_tag_generic_field(INTERNAL_FUNCTION_PARAM_PASSTHRU, "search", 0);
}

/**
 * Builds a HTML input[type="tel"] tag
 *
 * @param array $parameters
 * @return string
 */
PHP_METHOD(Phalcon_Tag, telField){

	phalcon_tag_generic_field(INTERNAL_FUNCTION_PARAM_PASSTHRU, "tel", 0);
}

/**
 * Builds a HTML input[type="url"] tag
 *
 * @param array $parameters
 * @return string
 */
PHP_METHOD(Phalcon_Tag, urlField){

	phalcon_tag_generic_field(INTERNAL_FUNCTION_PARAM_PASSTHRU, "url", 0);
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

	phalcon_tag_generic_field_checked(INTERNAL_FUNCTION_PARAM_PASSTHRU, "checkbox");
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

	phalcon_tag_generic_field_checked(INTERNAL_FUNCTION_PARAM_PASSTHRU, "radio");
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

	phalcon_tag_generic_field(INTERNAL_FUNCTION_PARAM_PASSTHRU, "image", 1);
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

	phalcon_tag_generic_field(INTERNAL_FUNCTION_PARAM_PASSTHRU, "submit", 1);
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
		data = PHALCON_GLOBAL(z_null);
	}
	
	PHALCON_RETURN_CALL_CE_STATIC(phalcon_tag_select_ce, "selectfield", parameters, data);
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
		data = PHALCON_GLOBAL(z_null);
	}
	
	PHALCON_RETURN_CALL_CE_STATIC(phalcon_tag_select_ce, "selectfield", parameters, data);
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
	zval *escaped = NULL, *escaper;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 0, &parameters);
	
	if (Z_TYPE_P(parameters) != IS_ARRAY) { 
		PHALCON_INIT_VAR(params);
		array_init_size(params, 1);
		phalcon_array_append(&params, parameters, 0);
	} else {
		PHALCON_CPY_WRT(params, parameters);
	}
	if (!phalcon_array_isset_long_fetch(&id, params, 0)) {
		if (phalcon_array_isset_string_fetch(&id, params, SS("id"))) {
			phalcon_array_update_long(&params, 0, id, PH_COPY | PH_SEPARATE);
		}
	}
	
	if (!phalcon_array_isset_string_fetch(&name, params, SS("name"))) {
		phalcon_array_update_string(&params, ISL(name), id, PH_COPY | PH_SEPARATE);
	} else {
		if (!zend_is_true(name)) {
			phalcon_array_update_string(&params, ISL(name), id, PH_COPY | PH_SEPARATE);
		}
	}
	
	if (!phalcon_array_isset_string(params, SS("id"))) {
		phalcon_array_update_string(&params, SL("id"), id, PH_COPY | PH_SEPARATE);
	}

	PHALCON_CALL_SELF(&content, "getvalue", id, params);

	PHALCON_OBS_VAR(escaper);
	phalcon_tag_get_escaper(&escaper, params TSRMLS_CC);
	if (EG(exception)) {
		PHALCON_MM_RESTORE();
		return;
	}

	if (escaper) {
		PHALCON_CALL_METHOD(&escaped, escaper, "escapehtml", content);
	}
	else {
		escaped = content;
	}

	PHALCON_INIT_VAR(code);
	ZVAL_STRING(code, "<textarea", 1);

	phalcon_tag_render_attributes(code, params TSRMLS_CC);
	if (EG(exception)) {
		PHALCON_MM_RESTORE();
		return;
	}

	PHALCON_CONCAT_VSVS(return_value, code, ">", escaped, "</textarea>");

	PHALCON_MM_RESTORE();
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
	zval *url = NULL, *code;

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

	if (!phalcon_array_isset_long_fetch(&params_action, params, 0)) {
		if (!phalcon_array_isset_string_fetch(&params_action, params, SS("action"))) {
			assert(params_action == NULL);
			PHALCON_INIT_VAR(params_action);
		}
	}
	
	/** 
	 * By default the method is POST
	 */
	if (!phalcon_array_isset_string(params, SS("method"))) {
		phalcon_array_update_string_string(&params, SL("method"), SL("post"), PH_SEPARATE);
	}
	
	if (Z_TYPE_P(params_action) != IS_NULL) {
		PHALCON_CALL_SELF(&url, "geturlservice");
		PHALCON_CALL_METHOD(&action, url, "get", params_action);
	}
	else {
		PHALCON_INIT_VAR(action);
	}
	
	/** 
	 * Check for extra parameters
	 */
	if (phalcon_array_isset_string_fetch(&parameters, params, SS("parameters"))) {
		PHALCON_SCONCAT_SV(action, "?", parameters);
	}
	
	if (Z_TYPE_P(action) != IS_NULL) {
		phalcon_array_update_string(&params, SL("action"), action, PH_COPY | PH_SEPARATE);
	}
	
	PHALCON_INIT_VAR(code);
	ZVAL_STRING(code, "<form", 1);

	phalcon_tag_render_attributes(code, params TSRMLS_CC);
	if (EG(exception)) {
		PHALCON_MM_RESTORE();
		return;
	}

	PHALCON_CONCAT_VS(return_value, code, ">");
	
	PHALCON_MM_RESTORE();
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
	
	phalcon_update_static_property_ce(phalcon_tag_ce, SL("_documentTitle"), title TSRMLS_CC);
	
}

/**
 * Set the title separator of view content
 *
 *<code>
 * Phalcon\Tag::setTitleSeparator('-');
 *</code>
 *
 * @param string $titleSeparator
 */
PHP_METHOD(Phalcon_Tag, setTitleSeparator){

	zval *title_separator;

	phalcon_fetch_params(0, 1, 0, &title_separator);
	
	phalcon_update_static_property_ce(phalcon_tag_ce, SL("_documentTitleSeparator"), title_separator TSRMLS_CC);
	
}

/**
 * Appends a text to current document title
 *
 * @param string $title
 */
PHP_METHOD(Phalcon_Tag, appendTitle){

	zval *title, *document_title, *document_title_separator, *r0;

	phalcon_fetch_params(0, 1, 0, &title);
	
	document_title = phalcon_fetch_static_property_ce(phalcon_tag_ce, SL("_documentTitle") TSRMLS_CC);
	document_title_separator = phalcon_fetch_static_property_ce(phalcon_tag_ce, SL("_documentTitleSeparator") TSRMLS_CC);
	ALLOC_INIT_ZVAL(r0);
	PHALCON_CONCAT_VVV(r0, document_title, document_title_separator, title);
	phalcon_update_static_property_ce(phalcon_tag_ce, SL("_documentTitle"), r0 TSRMLS_CC);
	zval_ptr_dtor(&r0);
}

/**
 * Prepends a text to current document title
 *
 * @param string $title
 */
PHP_METHOD(Phalcon_Tag, prependTitle){

	zval *title, *document_title, *document_title_separator, *r0;

	phalcon_fetch_params(0, 1, 0, &title);
	
	document_title = phalcon_fetch_static_property_ce(phalcon_tag_ce, SL("_documentTitle") TSRMLS_CC);
	document_title_separator = phalcon_fetch_static_property_ce(phalcon_tag_ce, SL("_documentTitleSeparator") TSRMLS_CC);
	
	ALLOC_INIT_ZVAL(r0);
	PHALCON_CONCAT_VVV(r0, title, document_title_separator, document_title);
	phalcon_update_static_property_ce(phalcon_tag_ce, SL("_documentTitle"), r0 TSRMLS_CC);
	zval_ptr_dtor(&r0);
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

	phalcon_fetch_params(0, 0, 1, &tags);
	
	document_title = phalcon_fetch_static_property_ce(phalcon_tag_ce, SL("_documentTitle") TSRMLS_CC);
	if (!tags || zend_is_true(tags)) {
		PHALCON_CONCAT_SVS(return_value, "<title>", document_title, "</title>" PHP_EOL);
	}
	else {
		RETURN_ZVAL(document_title, 1, 0);
	}
}

/**
 * Gets the current document title separator
 *
 * <code>
 * 	echo Phalcon\Tag::getTitleSeparator();
 * </code>
 *
 * <code>
 * 	{{ get_title_separator() }}
 * </code>
 *
 * @return string
 */
PHP_METHOD(Phalcon_Tag, getTitleSeparator){

	zval *document_title_separator;
	document_title_separator = phalcon_fetch_static_property_ce(phalcon_tag_ce, SL("_documentTitleSeparator") TSRMLS_CC);
	RETURN_ZVAL(document_title_separator, 1, 0);
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
	zval *url = NULL, *url_href, *href = NULL, *code, *doctype, *z_local;
	zval *rel;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 0, 2, &parameters, &local);
	
	if (!parameters) {
		parameters = PHALCON_GLOBAL(z_null);
	}

	if (!local) {
		local = PHALCON_GLOBAL(z_true);
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
		if (phalcon_array_isset_long_fetch(&first_param, params, 0)) {
			phalcon_array_update_string(&params, SL("href"), first_param, PH_COPY | PH_SEPARATE);
		} else {
			phalcon_array_update_string_string(&params, SL("href"), SL(""), PH_SEPARATE);
		}
	}
	
	if (phalcon_array_isset_long_fetch(&z_local, params, 1)) {
	} else if (phalcon_array_isset_string_fetch(&z_local, params, SS("local"))) {
		phalcon_array_unset_string(&params, SS("local"), PH_SEPARATE);
	}
	else {
		PHALCON_INIT_VAR(z_local);
		ZVAL_TRUE(z_local);
	}
	
	if (!phalcon_array_isset_string(params, SS("type"))) {
		phalcon_array_update_string_string(&params, ISL(type), SL("text/css"), PH_SEPARATE);
	}
	
	/** 
	 * URLs are generated through the 'url' service
	 */
	if (zend_is_true(z_local)) {
		PHALCON_CALL_SELF(&url, "geturlservice");
	
		PHALCON_OBS_VAR(url_href);
		phalcon_array_fetch_string(&url_href, params, SL("href"), PH_NOISY);
	
		PHALCON_CALL_METHOD(&href, url, "getstatic", url_href);
		phalcon_array_update_string(&params, SL("href"), href, PH_COPY | PH_SEPARATE);
	}
	
	PHALCON_INIT_VAR(code);
	
	if (phalcon_array_isset_string_fetch(&rel, params, SS("rel"))) {
		phalcon_array_unset_string(&params, SS("rel"), PH_SEPARATE);
		PHALCON_CONCAT_SVS(code, "<link rel=\"", rel, "\"");
	} else {
		ZVAL_STRING(code, "<link rel=\"stylesheet\"", 1);
	}

	phalcon_tag_render_attributes(code, params TSRMLS_CC);
	if (EG(exception)) {
		PHALCON_MM_RESTORE();
		return;
	}

	doctype = phalcon_fetch_static_property_ce(phalcon_tag_ce, SL("_documentType") TSRMLS_CC);
	
	/** 
	 * Check if Doctype is XHTML
	 */
	if (PHALCON_GT_LONG(doctype, 5)) {
		PHALCON_CONCAT_VS(return_value, code, " />" PHP_EOL);
	} else {
		PHALCON_CONCAT_VS(return_value, code, ">" PHP_EOL);
	}
	
	PHALCON_MM_RESTORE();
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
	zval *url = NULL, *params_src, *src = NULL, *code, *z_local;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 0, 2, &parameters, &local);
	
	if (!parameters) {
		parameters = PHALCON_GLOBAL(z_null);
	}

	if (!local) {
		local = PHALCON_GLOBAL(z_true);
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
		if (phalcon_array_isset_long_fetch(&first_param, params, 0)) {
			phalcon_array_update_string(&params, SL("src"), first_param, PH_COPY | PH_SEPARATE);
		} else {
			phalcon_array_update_string_string(&params, SL("src"), SL(""), PH_SEPARATE);
		}
	}
	
	if (phalcon_array_isset_long_fetch(&z_local, params, 1)) {
	} else if (phalcon_array_isset_string_fetch(&z_local, params, SS("local"))) {
		phalcon_array_unset_string(&params, SS("local"), PH_SEPARATE);
	} else {
		PHALCON_INIT_VAR(z_local);
		ZVAL_TRUE(z_local);
	}
	
	if (!phalcon_array_isset_string(params, SS("type"))) {
		phalcon_array_update_string_string(&params, ISL(type), SL("text/javascript"), PH_SEPARATE);
	}
	
	/** 
	 * URLs are generated through the 'url' service
	 */
	if (zend_is_true(z_local)) {
		PHALCON_CALL_SELF(&url, "geturlservice");
	
		PHALCON_OBS_VAR(params_src);
		phalcon_array_fetch_string(&params_src, params, SL("src"), PH_NOISY);
	
		PHALCON_CALL_METHOD(&src, url, "getstatic", params_src);
		phalcon_array_update_string(&params, SL("src"), src, PH_COPY | PH_SEPARATE);
	}
	
	PHALCON_INIT_VAR(code);
	ZVAL_STRING(code, "<script", 1);

	phalcon_tag_render_attributes(code, params TSRMLS_CC);
	if (EG(exception)) {
		PHALCON_MM_RESTORE();
		return;
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

	zval *parameters = NULL, *local = NULL, *params = NULL, *first_param, *second_param;
	zval *url = NULL, *url_src, *src = NULL, *code, *doctype;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 0, 2, &parameters, &local);
	
	if (!parameters) {
		parameters = PHALCON_GLOBAL(z_null);
	}
	
	if (!local) {
		PHALCON_INIT_VAR(local);
		if (Z_TYPE_P(parameters) == IS_ARRAY && phalcon_array_isset_long_fetch(&second_param, parameters, 1)) {
			ZVAL_BOOL(local, zend_is_true(second_param));
		} else {
			ZVAL_TRUE(local);
		}
	}
	
	if (Z_TYPE_P(parameters) != IS_ARRAY) { 
		PHALCON_INIT_VAR(params);
		array_init_size(params, 1);
		phalcon_array_append(&params, parameters, 0);
	} else {
		PHALCON_CPY_WRT(params, parameters);
	}

	if (!phalcon_array_isset_string(params, SS("src"))) {
		if (phalcon_array_isset_long_fetch(&first_param, params, 0)) {
			phalcon_array_update_string(&params, SL("src"), first_param, PH_COPY | PH_SEPARATE);
		} else {
			phalcon_array_update_string_string(&params, SL("src"), SL(""), PH_SEPARATE);
		}
	}
	
	/** 
	 * Use the 'url' service if the URI is local
	 */
	if (zend_is_true(local)) {
		PHALCON_CALL_SELF(&url, "geturlservice");
	
		PHALCON_OBS_VAR(url_src);
		phalcon_array_fetch_string(&url_src, params, SL("src"), PH_NOISY);
	
		PHALCON_CALL_METHOD(&src, url, "getstatic", url_src);
		phalcon_array_update_string(&params, SL("src"), src, PH_COPY | PH_SEPARATE);
	}
	
	PHALCON_INIT_VAR(code);
	ZVAL_STRING(code, "<img", 1);

	phalcon_tag_render_attributes(code, params TSRMLS_CC);
	if (EG(exception)) {
		PHALCON_MM_RESTORE();
		return;
	}

	doctype = phalcon_fetch_static_property_ce(phalcon_tag_ce, SL("_documentType") TSRMLS_CC);
	
	/** 
	 * Check if Doctype is XHTML
	 */
	if (PHALCON_GT_LONG(doctype, 5)) {
		PHALCON_CONCAT_VS(return_value, code, " />");
	} else {
		PHALCON_CONCAT_VS(return_value, code, ">");
	}
	
	PHALCON_MM_RESTORE();
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

	zval *text, *separator = NULL, *lowercase = NULL, *pattern, *friendly = NULL;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 2, &text, &separator, &lowercase);
	
	if (!separator) {
		PHALCON_INIT_VAR(separator);
		ZVAL_STRING(separator, "-", 1);
	}
	
	if (!lowercase) {
		lowercase = PHALCON_GLOBAL(z_true);
	}
	
	PHALCON_INIT_VAR(pattern);
	ZVAL_STRING(pattern, "~[^a-z0-9A-Z]+~", 1);
	
	PHALCON_CALL_FUNCTION(&friendly, "preg_replace", pattern, separator, text);
	if (zend_is_true(lowercase)) {
		phalcon_fast_strtolower(return_value, friendly);
	} else {
		RETVAL_ZVAL(friendly, 1, 0);
	}
	
	PHALCON_MM_RESTORE();
}

/**
 * Set the document type of content
 *
 * @param string $doctype
 */
PHP_METHOD(Phalcon_Tag, setDocType){

	zval *doctype;

	phalcon_fetch_params(0, 1, 0, &doctype);
	
	phalcon_update_static_property_ce(phalcon_tag_ce, SL("_documentType"), doctype TSRMLS_CC);
	
}

/**
 * Get the document type declaration of content
 *
 * @return string
 */
PHP_METHOD(Phalcon_Tag, getDocType){

	zval *doctype;

	doctype = phalcon_fetch_static_property_ce(phalcon_tag_ce, SL("_documentType") TSRMLS_CC);

	switch (phalcon_get_intval(doctype)) {
		case 1:  RETURN_STRING("<!DOCTYPE html PUBLIC \"-//W3C//DTD HTML 3.2 Final//EN\">" PHP_EOL, 1);
		/* no break */
		case 2:  RETURN_STRING("<!DOCTYPE html PUBLIC \"-//W3C//DTD HTML 4.01//EN\"" PHP_EOL "\t\"http://www.w3.org/TR/html4/strict.dtd\">" PHP_EOL, 1);
		/* no break */
		case 3:  RETURN_STRING("<!DOCTYPE html PUBLIC \"-//W3C//DTD HTML 4.01 Transitional//EN\"" PHP_EOL "\t\"http://www.w3.org/TR/html4/loose.dtd\">" PHP_EOL, 1);
		/* no break */
		case 4:  RETURN_STRING("<!DOCTYPE html PUBLIC \"-//W3C//DTD HTML 4.01 Frameset//EN\"" PHP_EOL"\t\"http://www.w3.org/TR/html4/frameset.dtd\">" PHP_EOL, 1);
		/* no break */
		case 5:  RETURN_STRING("<!DOCTYPE html>" PHP_EOL, 1);
		/* no break */
		case 6:  RETURN_STRING("<!DOCTYPE html PUBLIC \"-//W3C//DTD XHTML 1.0 Strict//EN\"" PHP_EOL "\t\"http://www.w3.org/TR/xhtml1/DTD/xhtml1-strict.dtd\">" PHP_EOL, 1);
		/* no break */
		case 7:  RETURN_STRING("<!DOCTYPE html PUBLIC \"-//W3C//DTD XHTML 1.0 Transitional//EN\"" PHP_EOL "\t\"http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd\">" PHP_EOL, 1);
		/* no break */
		case 8:  RETURN_STRING("<!DOCTYPE html PUBLIC \"-//W3C//DTD XHTML 1.0 Frameset//EN\"" PHP_EOL "\t\"http://www.w3.org/TR/xhtml1/DTD/xhtml1-frameset.dtd\">" PHP_EOL, 1);
		/* no break */
		case 9:  RETURN_STRING("<!DOCTYPE html PUBLIC \"-//W3C//DTD XHTML 1.1//EN\"" PHP_EOL"\t\"http://www.w3.org/TR/xhtml11/DTD/xhtml11.dtd\">" PHP_EOL, 1);
		/* no break */
		case 10: RETURN_STRING("<!DOCTYPE html PUBLIC \"-//W3C//DTD XHTML 2.0//EN\"" PHP_EOL "\t\"http://www.w3.org/MarkUp/DTD/xhtml2.dtd\">" PHP_EOL, 1);
		/* no break */
		case 11: RETURN_STRING("<!DOCTYPE html>" PHP_EOL, 1);
		/* no break */
		default: RETURN_EMPTY_STRING();
	}
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
	zval *use_eol = NULL, *params = NULL, *local_code, *doctype;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 4, &tag_name, &parameters, &self_close, &only_start, &use_eol);
	
	if (!parameters) {
		parameters = PHALCON_GLOBAL(z_null);
	}

	if (!self_close) {
		self_close = PHALCON_GLOBAL(z_false);
	}
	
	if (!only_start) {
		only_start = PHALCON_GLOBAL(z_false);
	}
	
	if (!use_eol) {
		use_eol = PHALCON_GLOBAL(z_false);
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

	phalcon_tag_render_attributes(local_code, params TSRMLS_CC);
	if (EG(exception)) {
		PHALCON_MM_RESTORE();
		return;
	}

	doctype = phalcon_fetch_static_property_ce(phalcon_tag_ce, SL("_documentType") TSRMLS_CC);
	
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
		use_eol = PHALCON_GLOBAL(z_false);
	}
	
	PHALCON_INIT_VAR(local_code);
	PHALCON_CONCAT_SVS(local_code, "</", tag_name, ">");
	if (zend_is_true(use_eol)) {
		phalcon_concat_self_str(&local_code, SL(PHP_EOL) TSRMLS_CC);
	}
	
	RETURN_CTOR(local_code);
}
