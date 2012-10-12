
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
#include "kernel/string.h"

/**
 * Phalcon\Text
 *
 * Provides utilities when working with strings
 */

/**
 * Converts strings to camelize style
 *
 *<code>
 *	echo Phalcon\Text::camelize('coco_bongo'); //CocoBongo
 *</code>
 *
 * @param string $str
 * @return string
 */
PHP_METHOD(Phalcon_Text, camelize){

	zval *str, *camelized;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &str) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	PHALCON_INIT_VAR(camelized);
	phalcon_camelize(camelized, str TSRMLS_CC);
	
	RETURN_CCTOR(camelized);
}

/**
 * Uncamelize strings which are camelized
 *
 *<code>
 *	echo Phalcon\Text::camelize('CocoBongo'); //coco_bongo
 *</code>
 *
 * @param string $str
 * @return string
 */
PHP_METHOD(Phalcon_Text, uncamelize){

	zval *str, *uncamelized;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &str) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	PHALCON_INIT_VAR(uncamelized);
	phalcon_uncamelize(uncamelized, str TSRMLS_CC);
	
	RETURN_CCTOR(uncamelized);
}

