
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
 * This is a base class for combined fields validators
 */
ZEPHIR_INIT_CLASS(Phalcon_Filter_Validation_AbstractCombinedFieldsValidator)
{
	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Filter\\Validation, AbstractCombinedFieldsValidator, phalcon, filter_validation_abstractcombinedfieldsvalidator, phalcon_filter_validation_abstractvalidator_ce, NULL, ZEND_ACC_EXPLICIT_ABSTRACT_CLASS);

	return SUCCESS;
}

