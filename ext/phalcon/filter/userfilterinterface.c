
#ifdef HAVE_CONFIG_H
#include "ext_config.h"
#endif

#include "php.h"
#include "../php_ext.h"
#include "../ext.h"

#include "kernel/main.h"


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
 * Phalcon\Filter\UserFilterInterface
 *
 * Interface for Phalcon\Filter user-filters
 */
ZEPHIR_INIT_CLASS(Phalcon_Filter_UserFilterInterface) {

	ZEPHIR_REGISTER_INTERFACE(Phalcon\\Filter, UserFilterInterface, phalcon, filter_userfilterinterface, phalcon_filter_userfilterinterface_method_entry);


	return SUCCESS;

}

/**
 * Filters a value
 *
 * @param mixed value
 * @return mixed
 */
ZEPHIR_DOC_METHOD(Phalcon_Filter_UserFilterInterface, filter);

