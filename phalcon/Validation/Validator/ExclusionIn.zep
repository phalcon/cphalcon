
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Validation\Validator;

use Phalcon\Messages\Message;
use Phalcon\Validation;
use Phalcon\Validation\AbstractValidator;
use Phalcon\Validation\Exception;

/**
 * Check if a value is not included into a list of values
 *
 * ```php
 * use Phalcon\Validation;
 * use Phalcon\Validation\Validator\ExclusionIn;
 *
 * $validator = new Validation();
 *
 * $validator->add(
 *     "status",
 *     new ExclusionIn(
 *         [
 *             "message" => "The status must not be A or B",
 *             "domain"  => [
 *                 "A",
 *                 "B",
 *             ],
 *         ]
 *     )
 * );
 *
 * $validator->add(
 *     [
 *         "status",
 *         "type",
 *     ],
 *     new ExclusionIn(
 *         [
 *             "message" => [
 *                 "status" => "The status must not be A or B",
 *                 "type"   => "The type must not be 1 or "
 *             ],
 *             "domain" => [
 *                 "status" => [
 *                     "A",
 *                     "B",
 *                 ],
 *                 "type"   => [1, 2],
 *             ],
 *         ]
 *     )
 * );
 * ```
 */
class ExclusionIn extends AbstractValidator
{
    protected template = "Field :field must not be a part of list: :domain";

    /**
     * Constructor
     *
     * @param array options = [
     *     'message' => '',
     *     'template' => '',
     *     'domain' => [],
     *     'strict' => false,
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
        var value, domain, replacePairs, strict, fieldDomain;

        let value = validation->getValue(field);
        if this->allowEmpty(field, value) {
            return true;
        }

        /**
         * A domain is an array with a list of valid values
         */
        let domain = this->getOption("domain");

        if fetch fieldDomain, domain[field] {
            if typeof fieldDomain == "array" {
                let domain = fieldDomain;
            }
        }

        if unlikely typeof domain != "array" {
            throw new Exception("Option 'domain' must be an array");
        }

        let strict = false;

        if this->hasOption("strict") {
            let strict = this->getOption("strict");

            if typeof strict == "array" {
                let strict = strict[field];
            }

            if unlikely typeof strict != "boolean" {
                throw new Exception("Option 'strict' must be a bool");
            }
        }

        /**
         * Check if the value is contained by the array
         */
        if in_array(value, domain, strict) {
            let replacePairs = [
                ":domain": join(", ", domain)
            ];

            validation->appendMessage(
                this->messageFactory(validation, field, replacePairs)
            );

            return false;
        }

        return true;
    }
}
