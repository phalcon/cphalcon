
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
 * Phalcon\Forms\Form
 *
 * This component allows to build forms using an object-oriented interface
 */
ZEPHIR_INIT_CLASS(Phalcon_Forms_Form) {

	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Forms, phalcon, Form, forms_form, phalcon_di_injectable_ce, NULL, 0);

	zend_declare_property_null(phalcon_forms_form_ce, SL("_position"), ZEND_ACC_PUBLIC TSRMLS_CC);
	zend_declare_property_null(phalcon_forms_form_ce, SL("_entity"), ZEND_ACC_PUBLIC TSRMLS_CC);
	zend_declare_property_null(phalcon_forms_form_ce, SL("_options"), ZEND_ACC_PUBLIC TSRMLS_CC);
	zend_declare_property_null(phalcon_forms_form_ce, SL("_data"), ZEND_ACC_PUBLIC TSRMLS_CC);
	zend_declare_property_null(phalcon_forms_form_ce, SL("_elements"), ZEND_ACC_PUBLIC TSRMLS_CC);
	zend_declare_property_null(phalcon_forms_form_ce, SL("_elementsIndexed"), ZEND_ACC_PUBLIC TSRMLS_CC);
	zend_declare_property_null(phalcon_forms_form_ce, SL("_messages"), ZEND_ACC_PUBLIC TSRMLS_CC);
	zend_declare_property_null(phalcon_forms_form_ce, SL("_action"), ZEND_ACC_PUBLIC TSRMLS_CC);

	return SUCCESS;

}

