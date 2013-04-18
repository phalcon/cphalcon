
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
 * This class allows to get the installed version of the framework
 */


/**
 * Phalcon\Version initializer
 */
PHALCON_INIT_CLASS(Phalcon_Version){

	PHALCON_REGISTER_CLASS(Phalcon, Version, version, phalcon_version_method_entry, 0);

	return SUCCESS;
}

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

	zval *version;

	PHALCON_MM_GROW();

	PHALCON_INIT_VAR(version);
	array_init_size(version, 5);
	add_next_index_long(version, 1);
	add_next_index_long(version, 1);
	add_next_index_long(version, 0);
	add_next_index_long(version, 2);
	add_next_index_long(version, 2);
	RETURN_CTOR(version);
}

/**
 * Returns the active version (string)
 *
 * <code>
 * echo Phalcon\Version::get();
 * </code>
 *
 * @return string
 */
PHP_METHOD(Phalcon_Version, get){

	zval *version, *major, *medium, *minor, *special, *special_number;
	zval *result, *suffix = NULL, *final_version;

	PHALCON_MM_GROW();

	PHALCON_INIT_VAR(version);
	PHALCON_CALL_SELF(version, this_ptr, "_getversion");

	PHALCON_OBS_VAR(major);
	phalcon_array_fetch_long(&major, version, 0, PH_NOISY_CC);

	PHALCON_OBS_VAR(medium);
	phalcon_array_fetch_long(&medium, version, 1, PH_NOISY_CC);

	PHALCON_OBS_VAR(minor);
	phalcon_array_fetch_long(&minor, version, 2, PH_NOISY_CC);

	PHALCON_OBS_VAR(special);
	phalcon_array_fetch_long(&special, version, 3, PH_NOISY_CC);

	PHALCON_OBS_VAR(special_number);
	phalcon_array_fetch_long(&special_number, version, 4, PH_NOISY_CC);

	PHALCON_INIT_VAR(result);
	PHALCON_CONCAT_VSVSVS(result, major, ".", medium, ".", minor, " ");

	switch (phalcon_get_intval(special)) {

		case 1:
			PHALCON_INIT_VAR(suffix);
			PHALCON_CONCAT_SV(suffix, "ALPHA ", special_number);
			break;

		case 2:
			PHALCON_INIT_NVAR(suffix);
			PHALCON_CONCAT_SV(suffix, "BETA ", special_number);
			break;

		case 3:
			PHALCON_INIT_NVAR(suffix);
			PHALCON_CONCAT_SV(suffix, "RC ", special_number);
			break;

		default:
			PHALCON_INIT_NVAR(suffix);
			ZVAL_STRING(suffix, "", 1);
			break;

	}
	phalcon_concat_self(&result, suffix TSRMLS_CC);

	PHALCON_INIT_VAR(final_version);
	PHALCON_CALL_FUNC_PARAMS_1(final_version, "trim", result);
	RETURN_CCTOR(final_version);
}

/**
 * Returns the numeric active version
 *
 * <code>
 * echo Phalcon\Version::getId();
 * </code>
 *
 * @return int
 */
PHP_METHOD(Phalcon_Version, getId){

	zval *version = NULL, *major, *medium, *minor, *special, *special_number;
	zval *format, *real_medium, *real_minor;

	PHALCON_MM_GROW();

	PHALCON_INIT_VAR(version);
	PHALCON_CALL_SELF(version, this_ptr, "_getversion");

	PHALCON_OBS_VAR(major);
	phalcon_array_fetch_long(&major, version, 0, PH_NOISY_CC);

	PHALCON_OBS_VAR(medium);
	phalcon_array_fetch_long(&medium, version, 1, PH_NOISY_CC);

	PHALCON_OBS_VAR(minor);
	phalcon_array_fetch_long(&minor, version, 2, PH_NOISY_CC);

	PHALCON_OBS_VAR(special);
	phalcon_array_fetch_long(&special, version, 3, PH_NOISY_CC);

	PHALCON_OBS_VAR(special_number);
	phalcon_array_fetch_long(&special_number, version, 4, PH_NOISY_CC);

	PHALCON_INIT_VAR(format);
	ZVAL_STRING(format, "%02s", 1);

	PHALCON_INIT_VAR(real_medium);
	PHALCON_CALL_FUNC_PARAMS_2(real_medium, "sprintf", format, medium);

	PHALCON_INIT_VAR(real_minor);
	PHALCON_CALL_FUNC_PARAMS_2(real_minor, "sprintf", format, minor);

	PHALCON_INIT_NVAR(version);
	PHALCON_CONCAT_VVVVV(version, major, real_medium, real_minor, special, special_number);
	RETURN_CCTOR(version);
}

