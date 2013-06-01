
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

	PHALCON_REGISTER_CLASS_EX(Phalcon\\Assets\\Resource, Css, assets_resource_css, "phalcon\\assets\\resource", phalcon_assets_resource_css_method_entry, 0);

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
	zval *p0[] = { NULL, NULL, NULL, NULL, NULL };

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 3, &path, &local, &filter, &attributes);
	
	if (!local) {
		PHALCON_INIT_VAR(local);
		ZVAL_BOOL(local, 1);
	}
	
	if (!filter) {
		PHALCON_INIT_VAR(filter);
		ZVAL_BOOL(filter, 1);
	}
	
	if (!attributes) {
		PHALCON_INIT_VAR(attributes);
	}
	
	PHALCON_INIT_VAR(type);
	ZVAL_STRING(type, "css", 1);
	
	p0[0] = type;
	p0[1] = path;
	p0[2] = local;
	p0[3] = filter;
	p0[4] = attributes;
	PHALCON_CALL_PARENT_PARAMS_NORETURN(this_ptr, "Phalcon\\Assets\\Resource\\Css", "__construct", 5, p0);
	
	PHALCON_MM_RESTORE();
}

