
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
 * Phalcon\Validation\Validator\PresenceOf
 *
 * Validates that a value is not null or empty string
 *
 *<code>
 *use Phalcon\Validation\Validator\PresenceOf;
 *
 *$validator->add('name', new PresenceOf(array(
 *   'message' => 'The name is required'
 *)));
 *</code>
 */
class PresenceOf extends Phalcon\Validation\Validator implements Phalcon\Validation\ValidatorInterface
{

	/**
	 * Executes the validation
	 *
	 * @param Phalcon\Validation validator
	 * @param string field
	 * @return boolean
	 */
	public function validate(<Phalcon\Validation> validator, string! field)
	{
		var value, message, replacePairs;

		let value = validator->getValue(field);
		if empty value {

			let message = this->getOption("message");
                        let replacePairs = [":field": field];
			if empty message {
				let message = ":field is required";
			}

			validator->appendMessage(new Phalcon\Validation\Message(strtr(message, replacePairs), field, "PresenceOf"));
			return false;
		}

		return true;
	}

}
