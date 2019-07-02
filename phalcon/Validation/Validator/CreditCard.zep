
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Validation\Validator;

use Phalcon\Messages\Message;
use Phalcon\Validation\Validation;
use Phalcon\Validation\AbstractValidator;

/**
 * Checks if a value has a valid credit card number
 *
 * ```php
 * use Phalcon\Validation\Validation;
 * use Phalcon\Validation\Validator\CreditCard as CreditCardValidator;
 *
 * $validator = new Validation();
 *
 * $validator->add(
 *     "creditCard",
 *     new CreditCardValidator(
 *         [
 *             "message" => "The credit card number is not valid",
 *         ]
 *     )
 * );
 *
 * $validator->add(
 *     [
 *         "creditCard",
 *         "secondCreditCard",
 *     ],
 *     new CreditCardValidator(
 *         [
 *             "message" => [
 *                 "creditCard"       => "The credit card number is not valid",
 *                 "secondCreditCard" => "The second credit card number is not valid",
 *             ],
 *         ]
 *     )
 * );
 * ```
 */
class CreditCard extends AbstractValidator
{
    protected template = "Field :field is not valid for a credit card number";

    /**
     * Executes the validation
     */
    public function validate(<Validation> validation, var field) -> bool
    {
        var value, valid;

        let value = validation->getValue(field);

        let valid = this->verifyByLuhnAlgorithm(value);

        if !valid {
            validation->appendMessage(
                this->messageFactory(validation, field)
            );

            return false;
        }

        return true;
    }

    /**
     * is a simple checksum formula used to validate a variety of identification
     * numbers
     */
    private function verifyByLuhnAlgorithm(string number) -> bool
    {
        var digit, position, hash = "", result;
        array digits;

        let digits = (array) str_split(number);

        for position, digit in digits->reversed() {
            let hash .= (position % 2 ? digit * 2 : digit);
        }

        let result = array_sum(
            str_split(hash)
        );

        return (result % 10 == 0);
    }
}
