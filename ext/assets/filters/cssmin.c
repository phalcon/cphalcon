
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
#include "phalcon.h"

#include "Zend/zend_operators.h"
#include "Zend/zend_exceptions.h"
#include "Zend/zend_interfaces.h"

#include "kernel/main.h"
#include "kernel/memory.h"

#include "kernel/fcall.h"

/**
 * Phalcon\Assets\Filters\Cssmin
 *
 * Removes spaces/tabs/line breaks in CSS files reducing their size
 */


/**
 * Phalcon\Assets\Filters\Cssmin initializer
 */
PHALCON_INIT_CLASS(Phalcon_Assets_Filters_Cssmin){

	PHALCON_REGISTER_CLASS(Phalcon\\Assets\\Filters, Cssmin, assets_filters_cssmin, phalcon_assets_filters_cssmin_method_entry, 0);

	return SUCCESS;
}

/**
 * Filters the content using CSSMIN
 *
 * @param string $content
 * @return $content
 */
PHP_METHOD(Phalcon_Assets_Filters_Cssmin, filter){

	zval *content, *filtered;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 0, &content);
	
	PHALCON_INIT_VAR(filtered);
	phalcon_call_func_p1(filtered, "phalcon_cssmin", content);
	RETURN_CCTOR(filtered);
}

