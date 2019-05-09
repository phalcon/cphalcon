
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
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */
/**
 * Phalcon\Validation\ValidatorInterface
 *
 * Interface for Phalcon\Validation\Validator
 */
ZEPHIR_INIT_CLASS(Phalcon_Validation_ValidatorInterface) {

	ZEPHIR_REGISTER_INTERFACE(Phalcon\\Validation, ValidatorInterface, phalcon, validation_validatorinterface, phalcon_validation_validatorinterface_method_entry);

	return SUCCESS;

}

/**
 * Returns an option in the validator's options
 * Returns null if the option hasn't set
 */
ZEPHIR_DOC_METHOD(Phalcon_Validation_ValidatorInterface, getOption);

/**
 * Checks if an option is defined
 */
ZEPHIR_DOC_METHOD(Phalcon_Validation_ValidatorInterface, hasOption);

/**
 * Executes the validation
 */
ZEPHIR_DOC_METHOD(Phalcon_Validation_ValidatorInterface, validate);

