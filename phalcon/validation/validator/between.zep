
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

namespace Phalcon\Validation\Validator;

/**
 * Phalcon\Validation\Validator\Between
 *
 * Validates that a value is between a range of two values
 *
 *<code>
 *use Phalcon\Validation\Validator\Between;
 *
 *validator->add('name', new Between(array(
 *   'minimum' => 0,
 *   'maximum' => 100,
 *   'message' => 'The price must be between 0 and 100'
 *)));
 *</code>
 */
class Between extends Phalcon\Validation\Validator implements Phalcon\Validation\ValidatorInterface {

	/**
	 * Executes the validation
	 *
	 * @param Phalcon\Validation validator
	 * @param string attribute
	 * @return boolean
	 */
	public function validate(<Phalcon\Validation> validator, string attribute) -> boolean
	{
		var value, minimum, maximum, message;

		let value = validator->getValue(attribute),
			minimum = this->getOption("minimum"),
			maximum = this->getOption("maximum");

		if value >= minimum || value <= maximum {

			let message = this->getOption("message");
			if empty message {
				let message = attribute . " is not between a valid range";
			}

			validator->appendMessage(new Phalcon\Validation\Message(message, attribute, "Between"));
			return false;
		}

		return true;
	}

}

