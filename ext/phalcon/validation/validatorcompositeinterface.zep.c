
#ifdef HAVE_CONFIG_H
#include "../../ext_config.h"
#endif

#include <php.h>
#include "../../php_ext.h"
#include "../../ext.h"

#include <Zend/zend_exceptions.h>

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
ZEPHIR_INIT_CLASS(Phalcon_Validation_ValidatorCompositeInterface) {

	ZEPHIR_REGISTER_INTERFACE(Phalcon\\Validation, ValidatorCompositeInterface, phalcon, validation_validatorcompositeinterface, phalcon_validation_validatorcompositeinterface_method_entry);

	return SUCCESS;

}

/**
 * Executes the validation
 */
ZEPHIR_DOC_METHOD(Phalcon_Validation_ValidatorCompositeInterface, getValidators);
/**
 * Executes the validation
 */
ZEPHIR_DOC_METHOD(Phalcon_Validation_ValidatorCompositeInterface, validate);
