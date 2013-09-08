
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
 * Phalcon\Assets\Filters\None
 *
 * Returns the content without make any modification to the original source
 */
ZEPHIR_INIT_CLASS(Phalcon_Assets_Filters_None) {

	ZEPHIR_REGISTER_CLASS(Phalcon\\Assets\\Filters, phalcon, None, assets_filters_none, phalcon_assets_filters_none_method_entry, 0);


	return SUCCESS;

}

/**
 * Returns the content without be touched
 *
 * @param string content
 * @return string
 */
PHP_METHOD(Phalcon_Assets_Filters_None, filter) {

	zval *content;

	zephir_fetch_params(0, 1, 0, &content);



	RETURN_CCTORW(content);

}

