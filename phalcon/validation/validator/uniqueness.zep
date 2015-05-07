
/*
 +------------------------------------------------------------------------+
 | Phalcon Framework                                                      |
 +------------------------------------------------------------------------+
 | Copyright (c) 2011-2015 Phalcon Team (http://www.phalconphp.com)       |
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

use Phalcon\Validation\Validator;

/**
 * Phalcon\Validation\Validator\Uniqueness
 *
 * Check that a field is unique in the related table
 *
 *<code>
 *use Phalcon\Validation\Validator\Uniqueness as UniquenessValidator;
 *
 *$validator->add('username', new UniquenessValidator(array(
 *    'model' => 'Users',
 *    'message' => ':field must be unique'
 *)));
 *</code>
 * 
 * Different attribute from the field
 *<code>
 *$validator->add('username', new UniquenessValidator(array(
 *    'model' => 'Users',
 *    'attribute' => 'nick'
 *)));
 *</code>
 */
class Uniqueness extends Validator
{

	/**
	 * Executes the validation
	 */
	public function validate(<\Phalcon\Validation> validation, string! field) -> boolean
	{
		var attribute, value, model, except, number, message, label, replacePairs;

		let value = validation->getValue(field),
			model = this->getOption("model"),
			attribute = this->getOption("attribute"),
			except = this->getOption("except");

		if empty model {
			throw new \Phalcon\Validation\Exception("Model must be set");
		}

		if empty attribute {
			let attribute = field;
		}

		if except  {
			let number = {model}::count([attribute . "=:value: AND " . attribute . "!= :except:", "bind": ["value": value, "except": except]]);
		} else {
			let number = {model}::count([attribute . "=:value:", "bind": ["value": value]]);
		}
		if number {

			let label = this->getOption("label");
			if empty label {
				let label = validation->getLabel(field);
			}

			let message = this->getOption("message"),
				replacePairs = [":field": label];
			if empty message {
				let message = validation->getDefaultMessage("Uniqueness");
			}

			validation->appendMessage(new \Phalcon\Validation\Message(strtr(message, replacePairs), field, "Uniqueness"));
			return false;
		}

		return true;
	}
}
