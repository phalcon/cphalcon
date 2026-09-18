
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


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */
/**
 * Component INPUT[type=file] for forms
 */
ZEPHIR_INIT_CLASS(Phalcon_Forms_Element_File)
{
	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Forms\\Element, File, phalcon, forms_element_file, phalcon_forms_element_abstractelement_ce, NULL, 0);

	{
		zval _zc0;
		ZVAL_STRINGL(&_zc0, "inputFile", sizeof("inputFile") - 1);
		zephir_declare_typed_property(phalcon_forms_element_file_ce, SL("method"), &_zc0, ZEND_ACC_PROTECTED, MAY_BE_STRING, NULL, 0);
	}

	return SUCCESS;
}

