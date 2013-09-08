
#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"
#include "php_test.h"
#include "test.h"

#include "Zend/zend_operators.h"
#include "Zend/zend_exceptions.h"
#include "Zend/zend_interfaces.h"

#include "kernel/main.h"
#include "kernel/fcall.h"
#include "kernel/memory.h"


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
/**
 * Phalcon\Assets\Resource\Css
 *
 * Represents CSS resources
 */
ZEPHIR_INIT_CLASS(Phalcon_Assets_Resource_Css) {

	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Assets\\Resource, phalcon, Css, assets_resource_css, phalcon_assets_resource_ce, phalcon_assets_resource_css_method_entry, 0);


	return SUCCESS;

}

/**
 * Phalcon\Assets\Resource\Css
 *
 * @param string path
 * @param boolean local
 * @param boolean filter
 * @param array attributes
 */
PHP_METHOD(Phalcon_Assets_Resource_Css, __construct) {

	zval *path, *local = NULL, *filter = NULL, *attributes = NULL, *_0;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 3, &path, &local, &filter, &attributes);

	if (!local) {
		ZEPHIR_INIT_VAR(local);
		ZVAL_BOOLlocal, 1);
	}
	if (!filter) {
		ZEPHIR_INIT_VAR(filter);
		ZVAL_BOOLfilter, 1);
	}
	if (!attributes) {
		ZEPHIR_INIT_VAR(attributes);
	}


	ZEPHIR_INIT_VAR(_0);
	ZVAL_STRING(_0, "css", 1);
	zephir_call_parent_p5_noret(this_ptr, phalcon_assets_resource_css_ce, "__construct", _0, path, local, filter, attributes);
	ZEPHIR_MM_RESTORE();

}

