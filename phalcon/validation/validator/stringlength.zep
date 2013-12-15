
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
 * Phalcon\Validation\Validator\StringLength
 *
 * Validates that a string has the specified maximum and minimum constraints
 *
 *<code>
 *use Phalcon\Validation\Validator\StringLength as StringLength;
 *
 *$validation->add('name_last', new StringLength(array(
 *      'max' => 50,
 *      'min' => 2,
 *      'messageMaximum' => 'We don\'t like really long names',
 *      'messageMinimum' => 'We want more than just their initials'
 *)));
 *</code>
 *
 */
class StringLength extends Phalcon\Validation\Validator implements Phalcon\Validation\ValidatorInterface
{

	/**
	 * Executes the validation
	 *
	 * @param Phalcon\Validation validation
	 * @param string field
	 * @return boolean
	 */
	public function validate(<Phalcon\Validation> validation, string! field) -> boolean
	{
		var isSetMin, isSetMax, value, length, message, minimum, maximum, replacePairs;

		/**
		 * At least one of 'min' or 'max' must be set
		 */
		let isSetMin = this->isSetOption("min"),
			isSetMax = this->isSetOption("max");

		if !isSetMin && !isSetMax {
			throw new Phalcon\Mvc\Model\Exception("A minimum or maximum must be set");
		}

		let value = validation->getValue(field);

                if this->isSetOption("allowEmpty") && (typeof value == "null" || empty value) {
                    return true;
                }

		/**
		 * Check if mbstring is available to calculate the correct length
		 */
		if function_exists("mb_strlen") {
			let length = mb_strlen(value);
		} else {
			let length = strlen(value);
		}

		/**
		 * Maximum length
		 */
		if isSetMax {

			let maximum = this->getOption("max");
			if length > maximum {

				/**
				 * Check if the developer has defined a custom message
				 */
				let message = this->getOption("messageMaximum");
                                let replacePairs = [":field": field, ":max":  maximum];
				if !message {
		 			let message = "Value of field :field exceeds the maximum :max characters";
		 		}

		 		validation->appendMessage(new Phalcon\Validation\Message(strtr(message, replacePairs), field, "TooLong"));
				return false;
			}
		}

		/**
		 * Minimum length
		 */
		if isSetMin {

			let minimum = this->getOption("min");
			if length < minimum {

				/**
				 * Check if the developer has defined a custom message
				 */
				let message = this->getOption("messageMinimum");
                                let replacePairs = [":field": field, ":min":  minimum];
				if !message {
                                        let message = "Value of field :field is less than the minimum :min characters";
		 		}

		 		validation->appendMessage(new Phalcon\Validation\Message(strtr(message, replacePairs), field, "TooShort"));
				return false;
			}
		}

		return true;
	}

}
