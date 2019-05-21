
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
use Phalcon\Validation;
use Phalcon\Validation\Validator;

/**
 * Phalcon\Validation\Validator\Numericality
 *
 * Check for a valid numeric value
 *
 * <code>
 * use Phalcon\Validation;
 * use Phalcon\Validation\Validator\Numericality;
 *
 * $validator = new Validation();
 *
 * $validator->add(
 *     "price",
 *     new Numericality(
 *         [
 *             "message" => ":field is not numeric",
 *         ]
 *     )
 * );
 *
 * $validator->add(
 *     [
 *         "price",
 *         "amount",
 *     ],
 *     new Numericality(
 *         [
 *             "message" => [
 *                 "price"  => "price is not numeric",
 *                 "amount" => "amount is not numeric",
 *             ]
 *         ]
 *     )
 * );
 * </code>
 */
class Numericality extends Validator
{
    protected advice = "Field :field does not have a valid numeric format";

    /**
     * Executes the validation
     */
    public function validate(<Validation> validation, var field) -> bool
    {
        var value, label, replacePairs, code;

        let value = validation->getValue(field);

        if !preg_match("/^-?\d+(?:[\.,]\d+)?$/", value) || !is_numeric(value) {
            let label = this->prepareLabel(validation, field);

            let code = this->prepareCode(field);

            let replacePairs = [
                ":field": label
            ];

            validation->appendMessage(
                new Message(
                    strtr(this->getAdvice(field), replacePairs),
                    field,
                    get_class(this),
                    code
                )
            );

            return false;
        }

        return true;
    }
}
