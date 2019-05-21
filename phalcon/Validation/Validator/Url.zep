
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
 * Phalcon\Validation\Validator\Url
 *
 * Checks if a value has a url format
 *
 * <code>
 * use Phalcon\Validation;
 * use Phalcon\Validation\Validator\Url as UrlValidator;
 *
 * $validator = new Validation();
 *
 * $validator->add(
 *     "url",
 *     new UrlValidator(
 *         [
 *             "message" => ":field must be a url",
 *         ]
 *     )
 * );
 *
 * $validator->add(
 *     [
 *         "url",
 *         "homepage",
 *     ],
 *     new UrlValidator(
 *         [
 *             "message" => [
 *                 "url"      => "url must be a url",
 *                 "homepage" => "homepage must be a url",
 *             ]
 *         ]
 *     )
 * );
 * </code>
 */
class Url extends Validator
{
    protected advice = "Field :field must be a url";

    /**
     * Executes the validation
     */
    public function validate(<Validation> validation, var field) -> bool
    {
        var code, label, options, replacePairs, result, value;

        let value = validation->getValue(field);

        if fetch options, this->options["options"] {
            let result = filter_var(value, FILTER_VALIDATE_URL, options);
        } else {
            let result = filter_var(value, FILTER_VALIDATE_URL);
        }

        if !result {
            let label   = this->prepareLabel(validation, field),
                code    = this->prepareCode(field);

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
