
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

#include "assets/resource/css.h"
#include "assets/resource.h"

#include "kernel/main.h"
#include "kernel/memory.h"
#include "kernel/fcall.h"

/**
 * Phalcon\Assets\Resource\Css
 *
 * Represents CSS resources
 */
zend_class_entry *phalcon_assets_resource_css_ce;

PHP_METHOD(Phalcon_Assets_Resource_Css, __construct);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_assets_resource_css___construct, 0, 0, 1)
	ZEND_ARG_INFO(0, path)
	ZEND_ARG_INFO(0, local)
	ZEND_ARG_INFO(0, filter)
	ZEND_ARG_INFO(0, attributes)
ZEND_END_ARG_INFO()

static const zend_function_entry phalcon_assets_resource_css_method_entry[] = {
	PHP_ME(Phalcon_Assets_Resource_Css, __construct, arginfo_phalcon_assets_resource_css___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_FE_END
};

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
	
	PHALCON_ALLOC_GHOST_ZVAL(type);
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

