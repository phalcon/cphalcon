
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
  +------------------------------------------------------------------------+
*/

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"
#include "php_phalcon.h"
#include "kernel/memory.h"

#include "Zend/zend_API.h"

void phalcon_ob_start(TSRMLS_D)
{
	php_output_start_default(TSRMLS_C);
}

void phalcon_ob_get_contents(zval *result TSRMLS_DC)
{
	php_output_get_contents(result TSRMLS_CC);
}

void phalcon_ob_end_clean(TSRMLS_D)
{
	php_output_end(TSRMLS_C);
}

void phalcon_ob_clean(TSRMLS_D)
{
	php_output_clean(TSRMLS_C);
}

int phalcon_ob_get_level(TSRMLS_D)
{
	return php_output_get_level(TSRMLS_C);
}
