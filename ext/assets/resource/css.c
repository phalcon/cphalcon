
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
 * Phalcon\Assets\Resource\Css
 *
 * Represents CSS resources
 */


/**
 * Phalcon\Assets\Resource\Css initializer
 */
PHALCON_INIT_CLASS(Phalcon_Assets_Resource_Css){

	PHALCON_REGISTER_CLASS_EX(Phalcon\\Assets\\Resource, Css, assets_resource_css, phalcon_assets_resource_ce, phalcon_assets_resource_css_method_entry, 0);

	return SUCCESS;
}

/**
 * Phalcon\Assets\Resource\Css
 *
 * @param string $path
 * @param boolean $local
 * @param boolean $filter
 * @param array $attributes
 */
PHP_METHOD(Phalcon_Assets_Resource_Css, __construct){

	zval *path, *local = NULL, *filter = NULL, *attributes = NULL, *type;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 3, &path, &local, &filter, &attributes);
	
	PHALCON_INIT_VAR(type);
	ZVAL_STRING(type, "css", 1);
	
	phalcon_call_parent_p5_noret(
		this_ptr,
		phalcon_assets_resource_css_ce, "__construct",
		type, path,
		(local ? local : PHALCON_GLOBAL(z_true)),
		(filter ? filter : PHALCON_GLOBAL(z_true)),
		(attributes ? attributes : PHALCON_GLOBAL(z_null))
	);
	
	PHALCON_MM_RESTORE();
}

