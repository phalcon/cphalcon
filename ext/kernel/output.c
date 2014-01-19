
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

#include "php_phalcon.h"

#include <Zend/zend_API.h>
#include <main/php_output.h>

#include "kernel/memory.h"
#include "kernel/output.h"

void phalcon_ob_start(TSRMLS_D)
{
#if PHP_VERSION_ID < 50400
	php_start_ob_buffer(NULL, 0, 1 TSRMLS_CC);
#else
	php_output_start_default(TSRMLS_C);
#endif
}

void phalcon_ob_get_contents(zval *result TSRMLS_DC)
{
#if PHP_VERSION_ID < 50400
	php_ob_get_buffer(result TSRMLS_CC);
#else
	php_output_get_contents(result TSRMLS_CC);
#endif
}

int phalcon_ob_end_flush(TSRMLS_D)
{
	if (phalcon_ob_get_level(TSRMLS_C) < 1) {
		php_error_docref("ref.outcontrol" TSRMLS_CC, E_NOTICE, "failed to delete and flush buffer. No buffer to flush");
		return FAILURE;
	}

#if PHP_VERSION_ID < 50400
	php_end_ob_buffer(1, 0 TSRMLS_CC);
	return SUCCESS;
#else
	return php_output_end(TSRMLS_C);
#endif
}

int phalcon_ob_end_clean(TSRMLS_D)
{
	if (phalcon_ob_get_level(TSRMLS_C) < 1) {
		php_error_docref("ref.outcontrol" TSRMLS_CC, E_NOTICE, "failed to delete buffer. No buffer to delete");
		return FAILURE;
	}

#if PHP_VERSION_ID < 50400
	php_end_ob_buffer(0, 0 TSRMLS_CC);
	return SUCCESS;
#else
	return php_output_discard(TSRMLS_C);
#endif
}

int phalcon_ob_flush(TSRMLS_D)
{
	if (phalcon_ob_get_level(TSRMLS_C) < 1) {
		php_error_docref("ref.outcontrol" TSRMLS_CC, E_NOTICE, "failed to flush buffer. No buffer to flush");
		return FAILURE;
	}

#if PHP_VERSION_ID < 50400
	php_end_ob_buffer(1, 1 TSRMLS_CC);
	return SUCCESS;
#else
	return php_output_flush(TSRMLS_C);
#endif
}

int phalcon_ob_clean(TSRMLS_D)
{
	if (phalcon_ob_get_level(TSRMLS_C) < 1) {
		php_error_docref("ref.outcontrol" TSRMLS_CC, E_NOTICE, "failed to delete buffer. No buffer to delete");
		return FAILURE;
	}

#if PHP_VERSION_ID < 50400
	php_end_ob_buffer(0, 1 TSRMLS_CC);
	return SUCCESS;
#else
	return php_output_clean(TSRMLS_C);
#endif
}

int phalcon_ob_get_level(TSRMLS_D)
{
#if PHP_VERSION_ID < 50400
	return OG(ob_nesting_level);
#else
	return php_output_get_level(TSRMLS_C);
#endif
}
