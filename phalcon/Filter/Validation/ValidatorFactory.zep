
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Filter\Validation;

use Phalcon\Factory\AbstractFactory;

class ValidatorFactory extends AbstractFactory
{
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

    /**
     * @return string
     */
    protected function getExceptionClass() -> string
    {
        return "Phalcon\\Validation\\Exception";
    }

    /**
     * Returns the available adapters
     *
     * @return string[]
     */
    protected function getServices() -> array
    {
        return [
            "alnum"        : "Phalcon\\Filter\\Validation\\Validator\\Alnum",
            "alpha"        : "Phalcon\\Filter\\Validation\\Validator\\Alpha",
            "between"      : "Phalcon\\Filter\\Validation\\Validator\\Between",
            "callback"     : "Phalcon\\Filter\\Validation\\Validator\\Callback",
            "confirmation" : "Phalcon\\Filter\\Validation\\Validator\\Confirmation",
            "creditCard"   : "Phalcon\\Filter\\Validation\\Validator\\CreditCard",
            "date"         : "Phalcon\\Filter\\Validation\\Validator\\Date",
            "digit"        : "Phalcon\\Filter\\Validation\\Validator\\Digit",
            "email"        : "Phalcon\\Filter\\Validation\\Validator\\Email",
            "exception"    : "Phalcon\\Filter\\Validation\\Validator\\Exception",
            "exclusionIn"  : "Phalcon\\Filter\\Validation\\Validator\\ExclusionIn",
            "file"         : "Phalcon\\Filter\\Validation\\Validator\\File",
            "identical"    : "Phalcon\\Filter\\Validation\\Validator\\Identical",
            "inclusionIn"  : "Phalcon\\Filter\\Validation\\Validator\\InclusionIn",
            "ip"           : "Phalcon\\Filter\\Validation\\Validator\\Ip",
            "numericality" : "Phalcon\\Filter\\Validation\\Validator\\Numericality",
            "presenceOf"   : "Phalcon\\Filter\\Validation\\Validator\\PresenceOf",
            "regex"        : "Phalcon\\Filter\\Validation\\Validator\\Regex",
            "stringLength" : "Phalcon\\Filter\\Validation\\Validator\\StringLength",
            "uniqueness"   : "Phalcon\\Filter\\Validation\\Validator\\Uniqueness",
            "url"          : "Phalcon\\Filter\\Validation\\Validator\\Url"
        ];
    }
}
