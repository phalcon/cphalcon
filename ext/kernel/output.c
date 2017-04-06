
/*
  +------------------------------------------------------------------------+
  | Zephir Language                                                        |
  +------------------------------------------------------------------------+
  | Copyright (c) 2011-2017 Zephir Team (http://www.zephir-lang.com)       |
  +------------------------------------------------------------------------+
  | This source file is subject to the New BSD License that is bundled     |
  | with this package in the file docs/LICENSE.txt.                        |
  |                                                                        |
  | If you did not receive a copy of the license and are unable to         |
  | obtain it through the world-wide-web, please send an email             |
  | to license@zephir-lang.com so we can send you a copy immediately.      |
  +------------------------------------------------------------------------+
  | Authors: Andres Gutierrez <andres@zephir-lang.com>                     |
  |          Eduar Carvajal <eduar@zephir-lang.com>                        |
  |          Vladimir Kolesnikov <vladimir@extrememember.com>              |
  +------------------------------------------------------------------------+
*/

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"
#include "php_ext.h"
#include "kernel/memory.h"
#include "kernel/output.h"

#include <Zend/zend_API.h>
#include <main/php_output.h>

void zephir_ob_start(TSRMLS_D)
{
	php_output_start_default(TSRMLS_C);
}

void zephir_ob_get_contents(zval *result TSRMLS_DC)
{
	php_output_get_contents(result TSRMLS_CC);
}

int zephir_ob_end_flush(TSRMLS_D)
{
	if (zephir_ob_get_level(TSRMLS_C) < 1) {
		php_error_docref("ref.outcontrol" TSRMLS_CC, E_NOTICE, "failed to delete and flush buffer. No buffer to flush");
		return FAILURE;
	}

	return php_output_end(TSRMLS_C);
}

int zephir_ob_end_clean(TSRMLS_D)
{
	if (zephir_ob_get_level(TSRMLS_C) < 1) {
		php_error_docref("ref.outcontrol" TSRMLS_CC, E_NOTICE, "failed to delete buffer. No buffer to delete");
		return FAILURE;
	}

	return php_output_discard(TSRMLS_C);
}

int zephir_ob_flush(TSRMLS_D)
{
	if (zephir_ob_get_level(TSRMLS_C) < 1) {
		php_error_docref("ref.outcontrol" TSRMLS_CC, E_NOTICE, "failed to flush buffer. No buffer to flush");
		return FAILURE;
	}

	return php_output_flush(TSRMLS_C);
}

int zephir_ob_clean(TSRMLS_D)
{
	if (zephir_ob_get_level(TSRMLS_C) < 1) {
		php_error_docref("ref.outcontrol" TSRMLS_CC, E_NOTICE, "failed to delete buffer. No buffer to delete");
		return FAILURE;
	}

	return php_output_clean(TSRMLS_C);
}

int zephir_ob_get_level(TSRMLS_D)
{
	return php_output_get_level(TSRMLS_C);
}
