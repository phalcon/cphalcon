
#ifdef HAVE_CONFIG_H
#include "../../../ext_config.h"
#endif

#include <php.h>
#include "../../../php_ext.h"
#include "../../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

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
 * Phalcon\Forms\Element\Date
 *
 * Component INPUT[type=date] for forms
 */
ZEPHIR_INIT_CLASS(Phalcon_Forms_Element_Date) {

	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Forms\\Element, Date, phalcon, forms_element_date, phalcon_forms_element_ce, phalcon_forms_element_date_method_entry, 0);


	return SUCCESS;

}

/**
 * Renders the element widget returning html
 *
 * @param array attributes
 * @return string
 */
PHP_METHOD(Phalcon_Forms_Element_Date, render) {

	zval *attributes = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &attributes);

	if (!attributes) {
		ZEPHIR_CPY_WRT(attributes, ZEPHIR_GLOBAL(global_null));
	}



}

