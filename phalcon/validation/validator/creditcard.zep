namespace Phalcon\Validation\Validator;

use Phalcon\Validation;
use Phalcon\Validation\Validator;
use Phalcon\Validation\Message;

/**
 * Phalcon\Validation\Validator\CreditCard
 *
 * Checks if a value has a valid creditcard number
 *
 *<code>
 *use Phalcon\Validation\Validator\CreditCard as CreditCardValidator;
 *
 *$validator->add('creditcard', new EmailValidator(array(
 *   'message' => 'The credit card number is not valid'
 *)));
 *</code>
 */
class CreditCard extends Validator
{
    public function validate(<Validation> validation, string! field) -> boolean
    {
        var message, label, replacePairs, value, valid;

		let value = validation->getValue(field);

        let valid = this->verifyByLuhnAlgorithm(value);

        if !valid {
            let label = this->getOption("label");
			if empty label {
				let label = validation->getLabel(field);
			}

			let message = this->getOption("message");
			let replacePairs = [":field": label];
			if empty message {
				let message = validation->getDefaultMessage("CreditCard");
			}

			validation->appendMessage(new Message(strtr(message, replacePairs), field, "CreditCard"));
			return false;
        }

        return true;
    }

    private function verifyByLuhnAlgorithm(number)
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
