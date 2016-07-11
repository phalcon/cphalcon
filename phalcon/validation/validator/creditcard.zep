
/*
 +------------------------------------------------------------------------+
 | Phalcon Framework                                                      |
 +------------------------------------------------------------------------+
 | Copyright (c) 2011-2016 Phalcon Team (https://phalconphp.com)       |
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

use Phalcon\Validation;
use Phalcon\Validation\Validator;
use Phalcon\Validation\Message;

/**
 * Phalcon\Validation\Validator\CreditCard
 *
 * Checks if a value has a valid credit card number
 *
 * <code>
 * use Phalcon\Validation\Validator\CreditCard as CreditCardValidator;
 *
 * $validator->add('creditcard', new CreditCardValidator([
 *     'message' => 'The credit card number is not valid'
 * ]));
 *
 * $validator->add(['creditcard', 'secondCreditCard'], new CreditCardValidator([
 *     'message' => [
 *         'creditcard' => 'The credit card number is not valid',
 *         'secondCreditCard' => 'The second credit card number is not valid'
 *     ]
 * ]));
 * </code>
 */
class CreditCard extends Validator
{
    /**
     * Executes the validation
     */
    public function validate(<Validation> validation, string! field) -> boolean
    {
        var message, label, replacePairs, value, valid, code;

        let value = validation->getValue(field);

        let valid = this->verifyByLuhnAlgorithm(value);

        if !valid {
            let label = this->getOption("label");
            if typeof label == "array" {
                let label = label[field];
            }
            if empty label {
            	let label = validation->getLabel(field);
            }

            let message = this->getOption("message");
            if typeof message == "array" {
                let message = message[field];
            }
            let replacePairs = [":field": label];
            if empty message {
            	let message = validation->getDefaultMessage("CreditCard");
            }

            let code = this->getOption("code");
            if typeof code == "array" {
                let code = code[field];
            }

            validation->appendMessage(new Message(strtr(message, replacePairs), field, "CreditCard", code));
            return false;
        }

        return true;
    }

    /**
     * is a simple checksum formula used to validate a variety of identification numbers
     * @param  string number
     * @return boolean
     */
    private function verifyByLuhnAlgorithm(number) -> boolean
    {
        array digits;
        let digits = (array) str_split(number);

        var digit, position, hash = "";

        for position, digit in digits->reversed() {
            let hash .= (position % 2 ? digit * 2 : digit);
        }

        var result;
        let result = array_sum(str_split(hash));

        return (result % 10 == 0);
    }
}
