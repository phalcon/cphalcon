
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Filter\Validation\Validator;

use Phalcon\Messages\Message;
use Phalcon\Filter\Validation;
use Phalcon\Filter\Validation\AbstractValidator;

/**
 * Check for a valid numeric value
 *
 * ```php
 * use Phalcon\Filter\Validation;
 * use Phalcon\Filter\Validation\Validator\Numericality;
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
 * ```
 */
class Numericality extends AbstractValidator
{
    protected template = "Field :field does not have a valid numeric format";

    /**
     * Constructor
     *
     * @param array options = [
     *     'message' => '',
     *     'template' => '',
     *     'allowEmpty' => false
     * ]
     */
    public function __construct(array! options = [])
    {
        parent::__construct(options);
    }

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

        if this->allowEmpty(field, value) {
            return true;
        }

        if !preg_match(pattern, value) {
            validation->appendMessage(
                this->messageFactory(validation, field)
            );

            return false;
        }

        return true;
    }
}
