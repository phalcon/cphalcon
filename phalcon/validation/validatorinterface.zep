
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
	 *
	 * @param string key
	 * @return mixed
	 */
	public function isSetOption(key);

	/**
	 * Returns an option in the validator's options
	 * Returns null if the option hasn't been set
	 *
	 * @param string key
	 * @return mixed
	 */
	public function getOption(key);

	/**
	 * Executes the validation
	 *
	 * @param Phalcon\Validator validator
	 * @param string attribute
	 * @return Phalcon\Validation\Message\Group
	 */
	public function validate(validator, attribute);

}