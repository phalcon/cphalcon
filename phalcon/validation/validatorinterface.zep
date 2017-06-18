
/*
 +------------------------------------------------------------------------+
 | Phalcon Framework                                                      |
 +------------------------------------------------------------------------+
 | Copyright (c) 2011-2017 Phalcon Team (https://phalconphp.com)          |
 +------------------------------------------------------------------------+
 | This source file is subject to the New BSD License that is bundled     |
 | with this package in the file LICENSE.txt.                             |
 |                                                                        |
 | If you did not receive a copy of the license and are unable to         |
 | obtain it through the world-wide-web, please send an email             |
 | to license@phalconphp.com so we can send you a copy immediately.       |
 +------------------------------------------------------------------------+
 | Authors: Andres Gutierrez <andres@phalconphp.com>                      |
 |          Eduar Carvajal <eduar@phalconphp.com>                         |
 +------------------------------------------------------------------------+
 */

namespace Phalcon\Validation;

/**
 * Phalcon\Validation\ValidatorInterface
 *
 * Interface for Phalcon\Validation\Validator
 */
interface ValidatorInterface
{

	/**
	 * Checks if an option is defined
	 */
	public function hasOption(string! key) -> boolean;

	/**
	 * Returns an option in the validator's options
	 * Returns null if the option hasn't set
	 */
	public function getOption(string! key, var defaultValue = null) -> var;

	/**
	 * Executes the validation
	 */
	public function validate(<\Phalcon\Validation> validation, string! attribute) -> boolean;

}
