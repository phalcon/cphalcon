
/*
 +------------------------------------------------------------------------+
 | Phalcon Framework                                                      |
 +------------------------------------------------------------------------+
 | Copyright (c) 2011-2017 Phalcon Team (https://phalconphp.com)          |
 +------------------------------------------------------------------------+
 | This source file is subject to the New BSD License that is bundled     |
 | with this package in the file docs/LICENSE.txt.                        |
 |                                                                        |
 | If you did not receive a copy of the license and are unable to         |
 | obtain it through the world-wide-web, please send an email             |
 | to license@phalconphp.com so we can send you a copy immediately.       |
 +------------------------------------------------------------------------+
 | Authors: Gorka Guridi <gorka.guridi@gmail.com>                         |
 +------------------------------------------------------------------------+
 */

namespace Phalcon\Validation\Validator;

use Phalcon\Validation;
use Phalcon\Validation\Validator;
use Phalcon\Validation\Message;

/**
 * Phalcon\Validation\Validator\ip
 *
 * Check for ip addresses
 *
 * <code>
 * use Phalcon\Validation\Validator\Ip as IpValidator;
 *
 * $validator->add(
 *     "ip_address",
 *     new IpValidator(
 *         [
 *             "message" => ":field must contain only ip addresses",
 *             "version" => IP::VERSION_4 | IP::VERSION_6, // v6 and v4. The same if not specified
 *             "allowReserved" => false,   // False if not specified. Ignored for v6
 *             "allowPrivate" => false,   // False if not specified
 *             "allowEmpty" => false,
 *         ]
 *     )
 * );
 *
 * $validator->add(
 *     [
 *         "source_address",
 *         "destination_address",
 *     ],
 *     new IpValidator(
 *         [
 *             "message" => [
 *                 "source_address" => "source_address must contain only ip addresses",
 *                 "destination_address" => "destination_address must contain only ip addresses",
 *             ],
 *             "version" => [
 *                  "source_address" => Ip::VERSION_4 | IP::VERSION_6,
 *                  "destination_address" => Ip::VERSION_4,
 *             ],
 *             "allowReserved" => [
 *                  "source_address" => false,
 *                  "destination_address" => true,
 *             ],
 *             "allowPrivate" => [
 *                  "source_address" => false,
 *                  "destination_address" => true,
 *             ],
 *             "allowEmpty" => [
 *                  "source_address" => false,
 *                  "destination_address" => true,
 *             ],
 *         ]
 *     )
 * );
 * </code>
 */
class Ip extends Validator
{

    const VERSION_4  = FILTER_FLAG_IPV4;
    const VERSION_6  = FILTER_FLAG_IPV6;

    /**
     * Executes the validation
     */
    public function validate(<Validation> validation, string! field) -> boolean
    {
        var value, version, allowPrivate, allowReserved, allowEmpty, message, label, replacePairs, options;

        let value = validation->getValue(field);

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
        if empty message {
            let message = validation->getDefaultMessage("Ip");
        }

        let version = this->getOption("version", FILTER_FLAG_IPV4 | FILTER_FLAG_IPV6);
        if typeof version == "array" {
            let version = version[field];
        }

        let allowPrivate = this->getOption("allowPrivate") ? 0 : FILTER_FLAG_NO_PRIV_RANGE;
        if typeof allowPrivate == "array" {
            let allowPrivate = allowPrivate[field];
        }

        let allowReserved = this->getOption("allowReserved") ? 0 : FILTER_FLAG_NO_RES_RANGE;
        if typeof allowReserved == "array" {
            let allowReserved = allowReserved[field];
        }

        let allowEmpty = this->getOption("allowEmpty", false);
        if typeof allowEmpty == "array" {
            let allowEmpty = isset allowEmpty[field] ? allowEmpty[field] : false;
        }

        if allowEmpty && empty value {
            return true;
        }

        let options = [
           "options": [
             "default": false
           ],
           "flags": version | allowPrivate | allowReserved
        ];

        if !filter_var(value, FILTER_VALIDATE_IP, options) {
            let replacePairs = [":field": label];
            validation->appendMessage(new Message(strtr(message, replacePairs), field, "Ip"));
            return false;
	}

	return true;
    }
}
