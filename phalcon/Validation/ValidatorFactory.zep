
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Validation;

use Phalcon\Factory\AbstractFactory;
use Phalcon\Helper\Arr;

class ValidatorFactory extends AbstractFactory
{
    protected exception = "Phalcon\\Validation\\Exception";

    /**
     * TagFactory constructor.
     */
    public function __construct(array! services = [])
    {
        this->init(services);
    }

    /**
     * Creates a new instance
     */
    public function newInstance(string! name) -> <ValidatorInterface>
    {
        var definition;

        let definition = this->getService(name);

        return create_instance(definition);
    }

    protected function getServices() -> array
    {
        return [
            "alnum"        : "Phalcon\\Validation\\Validator\\Alnum",
            "alpha"        : "Phalcon\\Validation\\Validator\\Alpha",
            "between"      : "Phalcon\\Validation\\Validator\\Between",
            "callback"     : "Phalcon\\Validation\\Validator\\Callback",
            "confirmation" : "Phalcon\\Validation\\Validator\\Confirmation",
            "creditCard"   : "Phalcon\\Validation\\Validator\\CreditCard",
            "date"         : "Phalcon\\Validation\\Validator\\Date",
            "digit"        : "Phalcon\\Validation\\Validator\\Digit",
            "email"        : "Phalcon\\Validation\\Validator\\Email",
            "exception"    : "Phalcon\\Validation\\Validator\\Exception",
            "exclusionIn"  : "Phalcon\\Validation\\Validator\\ExclusionIn",
            "file"         : "Phalcon\\Validation\\Validator\\File",
            "identical"    : "Phalcon\\Validation\\Validator\\Identical",
            "inclusionIn"  : "Phalcon\\Validation\\Validator\\InclusionIn",
            "ip"           : "Phalcon\\Validation\\Validator\\Ip",
            "numericality" : "Phalcon\\Validation\\Validator\\Numericality",
            "presenceOf"   : "Phalcon\\Validation\\Validator\\PresenceOf",
            "regex"        : "Phalcon\\Validation\\Validator\\Regex",
            "stringLength" : "Phalcon\\Validation\\Validator\\StringLength",
            "uniqueness"   : "Phalcon\\Validation\\Validator\\Uniqueness",
            "url"          : "Phalcon\\Validation\\Validator\\Url"
        ];
    }
}
