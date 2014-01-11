
/*
 +------------------------------------------------------------------------+
 | Phalcon Framework                                                      |
 +------------------------------------------------------------------------+
 | Copyright (c) 2011-2014 Phalcon Team (http://www.phalconphp.com)       |
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
 * Phalcon\Validation\Validator\Uniqueness
 *
 * Check for alphanumeric character(s)
 *
 *<code>
 *use Phalcon\Validation\Validator\Uniqueness as UniquenessValidator;
 *
 *$validator->add('username', new UniquenessValidator(array(
 *   'message' => ':field must be unique'
 *)));
 *</code>
 */
class Uniqueness extends Phalcon\Validation\Validator implements Phalcon\Validation\ValidatorInterface
{

	/**
	 * Executes the validation
	 *
	 * @param  Phalcon\Validation validation
	 * @param  string             field
	 * @return boolean
	 */
	public function validate(<Phalcon\Validation> validation, string! field) -> boolean
	{
		var attribute, value, di, metaData, params, model, number, message, label, replacePairs;

		let value = validation->getValue(field),
                        model = this->getOption("model"),
                        attribute = this->getOption("attribute");
                
                if empty model {
                        throw new Phalcon\Validation\Exception("Model must be set");
                }
                
                if empty attribute {
                        let attribute = field;
                }
                
		let number = {model}::count([attribute . "=:value:", "bind": ["value" : value]]);

		if number {

                        let label = this->getOption("label");
                        if empty label {
                                let label = validation->getLabel(field);
                                if empty label {
                                        let label = field;
                                }
			}

			let message = this->getOption("message");
                        let replacePairs = [":field": label];
			if empty message {
                                let message = validation->getDefaultMessage("Uniqueness");
			}

			validation->appendMessage(new Phalcon\Validation\Message(strtr(message, replacePairs), field, "Uniqueness"));
			return false;
		}

		return true;
	}
}
