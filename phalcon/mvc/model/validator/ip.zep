
/*
 +------------------------------------------------------------------------+
 | Phalcon Framework                                                      |
 +------------------------------------------------------------------------+
 | Copyright (c) 2011-2017 Phalcon Team (https://phalconphp.com)          |
 +------------------------------------------------------------------------+
 | This source file is subject to the New BSD License that is bundled     |
 | with this package in the file LICENSE.txt.                             |
 |                                                                        |
 | If you did not receive a copy of the license and are unable to         |
 | obtain it through the world-wide-web, please send an email             |
 | to license@phalconphp.com so we can send you a copy immediately.       |
 +------------------------------------------------------------------------+
 | Authors: Andres Gutierrez <andres@phalconphp.com>                      |
 |          Eduar Carvajal <eduar@phalconphp.com>                         |
 +------------------------------------------------------------------------+
 */

namespace Phalcon\Mvc\Model\Validator;

use Phalcon\Mvc\EntityInterface;
use Phalcon\Mvc\Model\Exception;
use Phalcon\Mvc\Model\Validator;

/**
 * Phalcon\Mvc\Model\Validator\IP
 *
 * Validates that a value is ipv4 address in valid range
 *
 * This validator is only for use with Phalcon\Mvc\Collection. If you are using
 * Phalcon\Mvc\Model, please use the validators provided by Phalcon\Validation.
 *
 *<code>
 * use Phalcon\Mvc\Model\Validator\Ip;
 *
 * class Data extends \Phalcon\Mvc\Collection
 * {
 *     public function validation()
 *     {
 *         // Any pubic IP
 *         $this->validate(
 *             new IP(
 *                 [
 *                     "field"         => "server_ip",
 *                     "version"       => IP::VERSION_4 | IP::VERSION_6, // v6 and v4. The same if not specified
 *                     "allowReserved" => false,   // False if not specified. Ignored for v6
 *                     "allowPrivate"  => false,   // False if not specified
 *                     "message"       => "IP address has to be correct",
 *                 ]
 *             )
 *         );
 *
 *         // Any public v4 address
 *         $this->validate(
 *             new IP(
 *                 [
 *                     "field"   => "ip_4",
 *                     "version" => IP::VERSION_4,
 *                     "message" => "IP address has to be correct",
 *                 ]
 *             )
 *         );
 *
 *         // Any v6 address
 *         $this->validate(
 *             new IP(
 *                 [
 *                     "field"        => "ip6",
 *                     "version"      => IP::VERSION_6,
 *                     "allowPrivate" => true,
 *                     "message"      => "IP address has to be correct",
 *                 ]
 *             )
 *         );
 *
 *         if ($this->validationHasFailed() === true) {
 *             return false;
 *         }
 *     }
 * }
 *</code>
 *
 * @deprecated 3.1.0
 */
class Ip extends Validator
{
	const VERSION_4  = FILTER_FLAG_IPV4;
	const VERSION_6  = FILTER_FLAG_IPV6;

	/**
	 * Executes the validator
	 */
	public function validate(<EntityInterface> record) -> boolean
	{
		var field, value, message, version, allowPrivate, allowReserved, options;

		let field = this->getOption("field");

		if typeof field != "string" {
			throw new Exception("Field name must be a string");
		}

		let value = record->readAttribute(field);
		let version = this->getOption("version", FILTER_FLAG_IPV4 | FILTER_FLAG_IPV6);
		let allowPrivate = this->getOption("allowPrivate") ? 0 : FILTER_FLAG_NO_PRIV_RANGE;
		let allowReserved = this->getOption("allowReserved") ? 0 : FILTER_FLAG_NO_RES_RANGE;

		if this->getOption("allowEmpty", false) && empty value {
			return true;
		}

		let options = [
			"options": [
				"default": false
			],
			"flags": version | allowPrivate | allowReserved
		];

		/**
		 * Filters the format using FILTER_VALIDATE_IP
		 */
		if !filter_var(value, FILTER_VALIDATE_IP, options) {

			let message = this->getOption("message", "IP address is incorrect");
			this->appendMessage(strtr(message, [":field": field]), field, "IP");

			return false;
		}

		return true;
	}
}
