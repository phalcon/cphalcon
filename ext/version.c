
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
  |          Nikolaos Dimopoulos <nikos@niden.net>                         |
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

#include "kernel/fcall.h"
#include "kernel/array.h"
#include "kernel/concat.h"
#include "kernel/operators.h"

/**
 * Phalcon\Version
 *
 * This version allows to get version of the framework
 */


/**
 * Area where the version number is set. The format is as follows:
 * ABBCCDE
 *
 * A - Major version
 * B - Med version (two digits)
 * C - Min version (two digits)
 * D - Special release: 1 = Alpha, 2 = Beta, 3 = RC, 4 = Stable
 * E - Special release version i.e. RC1, Beta2 etc.
 */
PHP_METHOD(Phalcon_Version, _getVersion){

	zval *version = NULL;

	PHALCON_MM_GROW();
	PHALCON_INIT_VAR(version);
	array_init(version);
	add_next_index_long(version, 0);
	add_next_index_long(version, 5);
	add_next_index_long(version, 0);
	add_next_index_long(version, 2);
	add_next_index_long(version, 1);
	
	RETURN_CTOR(version);
}

/**
 * Returns the active version (string)
 *
 * @return string
 */
PHP_METHOD(Phalcon_Version, get){

	zval *version = NULL, *major = NULL, *medium = NULL, *minor = NULL, *special = NULL, *special_number = NULL;
	zval *result = NULL, *suffix = NULL, *final_version = NULL;

	PHALCON_MM_GROW();
	PHALCON_INIT_VAR(version);
	PHALCON_CALL_SELF(version, this_ptr, "_getversion");
	
	PHALCON_INIT_VAR(major);
	phalcon_array_fetch_long(&major, version, 0, PH_NOISY_CC);
	
	PHALCON_INIT_VAR(medium);
	phalcon_array_fetch_long(&medium, version, 1, PH_NOISY_CC);
	
	PHALCON_INIT_VAR(minor);
	phalcon_array_fetch_long(&minor, version, 2, PH_NOISY_CC);
	
	PHALCON_INIT_VAR(special);
	phalcon_array_fetch_long(&special, version, 3, PH_NOISY_CC);
	
	PHALCON_INIT_VAR(special_number);
	phalcon_array_fetch_long(&special_number, version, 4, PH_NOISY_CC);
	
	PHALCON_INIT_VAR(result);
	PHALCON_CONCAT_VSVSVS(result, major, ".", medium, ".", minor, " ");
	
	if (phalcon_compare_strict_long(special, 1 TSRMLS_CC)) {
		PHALCON_INIT_VAR(suffix);
		PHALCON_CONCAT_SV(suffix, "ALPHA ", special_number);
		goto ph_end_0;
	}
	
	if (phalcon_compare_strict_long(special, 2 TSRMLS_CC)) {
		PHALCON_INIT_VAR(suffix);
		PHALCON_CONCAT_SV(suffix, "BETA ", special_number);
		goto ph_end_0;
	}
	
	if (phalcon_compare_strict_long(special, 1 TSRMLS_CC)) {
		PHALCON_INIT_VAR(suffix);
		PHALCON_CONCAT_SV(suffix, "RC ", special_number);
		goto ph_end_0;
	}
	
	PHALCON_INIT_VAR(suffix);
	ZVAL_STRING(suffix, "", 1);
	goto ph_end_0;
	
	ph_end_0:
	phalcon_concat_self(&result, suffix TSRMLS_CC);
	
	PHALCON_INIT_VAR(final_version);
	PHALCON_CALL_FUNC_PARAMS_1(final_version, "trim", result);
	
	RETURN_CCTOR(final_version);
}

/**
 * Returns the numeric active version
 *
 * @return int
 */
PHP_METHOD(Phalcon_Version, getId){

	zval *version = NULL, *major = NULL, *medium = NULL, *minor = NULL, *special = NULL, *special_number = NULL;
	zval *format = NULL, *real_medium = NULL, *real_minor = NULL;

	PHALCON_MM_GROW();
	PHALCON_INIT_VAR(version);
	PHALCON_CALL_SELF(version, this_ptr, "_getversion");
	
	PHALCON_INIT_VAR(major);
	phalcon_array_fetch_long(&major, version, 0, PH_NOISY_CC);
	
	PHALCON_INIT_VAR(medium);
	phalcon_array_fetch_long(&medium, version, 1, PH_NOISY_CC);
	
	PHALCON_INIT_VAR(minor);
	phalcon_array_fetch_long(&minor, version, 2, PH_NOISY_CC);
	
	PHALCON_INIT_VAR(special);
	phalcon_array_fetch_long(&special, version, 3, PH_NOISY_CC);
	
	PHALCON_INIT_VAR(special_number);
	phalcon_array_fetch_long(&special_number, version, 4, PH_NOISY_CC);
	
	PHALCON_INIT_VAR(format);
	ZVAL_STRING(format, "%02s", 1);
	
	PHALCON_INIT_VAR(real_medium);
	PHALCON_CALL_FUNC_PARAMS_2(real_medium, "sprintf", format, medium);
	
	PHALCON_INIT_VAR(real_minor);
	PHALCON_CALL_FUNC_PARAMS_2(real_minor, "sprintf", format, minor);
	
	PHALCON_INIT_VAR(version);
	PHALCON_CONCAT_VVVVV(version, major, real_medium, real_minor, special, special_number);
	
	RETURN_CCTOR(version);
}

