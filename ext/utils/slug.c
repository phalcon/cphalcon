#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php_phalcon.h"
#include "utils/slug.h"

#include "kernel/main.h"
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/string.h"

PHALCON_INIT_CLASS(Phalcon_Utils_Slug) {
	PHALCON_REGISTER_CLASS(Phalcon\\Utils, Slug, utils_slug, phalcon_utils_slug_method_entry, ZEND_ACC_EXPLICIT_ABSTRACT_CLASS);
	return SUCCESS;
}

PHP_METHOD(Phalcon_Utils_Slug, generate) {
	zval *string, *replace = NULL, *delimiter = NULL;
	zval *old_locale, *category, *locale;
	zval *tmp = NULL, *space;
	zval *clean = NULL, *from, *to, *pattern, *empty;

	phalcon_fetch_params(0, 1, 2, &string, &replace, &delimiter);

	PHALCON_MM_GROW();

	if (!delimiter) {
		PHALCON_INIT_VAR(delimiter);
		ZVAL_STRING(delimiter, "-", 1);
	}

	/* $old_locale = setlocale(LC_ALL, 'en_US.UTF-8'); */
	PHALCON_INIT_VAR(old_locale);

	PHALCON_INIT_VAR(category);
	ZVAL_LONG(category, 6 /* LC_ALL */);

	PHALCON_INIT_VAR(locale);
	ZVAL_STRING(locale, "en_US.UTF-8", 1);

	phalcon_call_func_p2(old_locale, "setlocale", category, locale);

	/* $tmp = iconv('UTF-8', 'ASCII//TRANSLIT', $string); */
	PHALCON_INIT_NVAR(tmp);

	PHALCON_INIT_VAR(from);
	ZVAL_STRING(from, "UTF-8", 1);

	PHALCON_INIT_VAR(to);
	ZVAL_STRING(to, "ASCII//TRANSLIT", 1);

	phalcon_call_func_p3(tmp, "iconv", from, to, string);

	if (replace != NULL && zend_is_true(replace)) {
		if (Z_TYPE_P(replace) != IS_ARRAY) {
			PHALCON_SEPARATE_PARAM(replace);
			convert_to_array(replace);
		}

		/* $clean = str_replace($tmp, $replace, ' '); */
		PHALCON_INIT_NVAR(clean);

		PHALCON_INIT_VAR(space);
		ZVAL_STRING(space, " ", 1);

		phalcon_call_func_p3(clean, "str_replace", replace, space, tmp);

		/* $tmp = $clean; */
		PHALCON_CPY_WRT(tmp, clean);
	}

	/* clean = preg_replace('/[^a-zA-Z0-9\\/_|+ -]/', '', $rmp); */
	PHALCON_INIT_NVAR(clean);

	PHALCON_INIT_VAR(pattern);
	ZVAL_STRING(pattern, "/[^a-zA-Z0-9\\/_|+ -]/", 1);

	PHALCON_INIT_VAR(empty);
	ZVAL_EMPTY_STRING(empty);

	phalcon_call_func_p3(clean, "preg_replace", pattern, empty, tmp);

	/* $tmp = strtolower($clean); */
	PHALCON_INIT_NVAR(tmp);
	phalcon_fast_strtolower(tmp, clean);

	/* $clean = preg_replace("/[\/_|+ -]+/", $delimiter, $tmp); */
	PHALCON_INIT_NVAR(clean);

	PHALCON_INIT_NVAR(pattern);
	ZVAL_STRING(pattern, "/[\\/_|+ -]+/", 1);

	phalcon_call_func_p3(clean, "preg_replace", pattern, delimiter, tmp);

	/* $result = trim($clean, $delimiter); */
	phalcon_call_func_p2(return_value, "trim", clean, delimiter);

	/* setlocale(LC_ALL, $old_locale); */
	phalcon_call_func_p2_noret("setlocale", category, old_locale);

	PHALCON_MM_RESTORE();
}
