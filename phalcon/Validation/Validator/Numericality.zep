
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
        var value;
        string pattern;

        // Dump spaces in the string if we have any
        let value   = validation->getValue(field),
            value   = (string) value,
            value   = str_replace(" ", "", value),
            pattern = "/((^[-]?[0-9,]+(.[0-9]+)?$)|(^[-]?[0-9.]+(,[0-9]+)?$))/";

        if !preg_match(pattern, value) {
            validation->appendMessage(
                this->messageFactory(validation, field)
            );

            return false;
        }

        return true;
    }
}
