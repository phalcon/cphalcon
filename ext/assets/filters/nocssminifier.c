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
  | Authors: Remi Collet <remi@famillecollet.com>                          |
  +------------------------------------------------------------------------+
*/

/* placeholder for non-free csssminifier.c */

#include "php_phalcon.h"

#ifndef PHALCON_NON_FREE

#include "assets/filters/nocssminifier.h"
#include "assets/exception.h"
#include "kernel/exception.h"

int phalcon_cssmin(zval *return_value, zval *style TSRMLS_DC) {

	PHALCON_THROW_EXCEPTION_STRW(phalcon_assets_exception_ce, "Non-free csssminifier not available");
	return FAILURE;
}
#endif
