
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
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
	public function hasOption(string! key) -> bool;

	/**
	 * Returns an option in the validator's options
	 * Returns null if the option hasn't set
	 */
	public function getOption(string! key, var defaultValue = null) -> var;

	/**
	 * Executes the validation
	 */
	public function validate(<\Phalcon\Validation> validation, var field) -> bool;
}
