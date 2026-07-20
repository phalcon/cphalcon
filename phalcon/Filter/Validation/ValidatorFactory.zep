
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
use Phalcon\Filter\Validation\Validator\Alnum;
use Phalcon\Filter\Validation\Validator\Alpha;
use Phalcon\Filter\Validation\Validator\Between;
use Phalcon\Filter\Validation\Validator\Callback;
use Phalcon\Filter\Validation\Validator\Confirmation;
use Phalcon\Filter\Validation\Validator\CreditCard;
use Phalcon\Filter\Validation\Validator\Date;
use Phalcon\Filter\Validation\Validator\Digit;
use Phalcon\Filter\Validation\Validator\Email;
use Phalcon\Filter\Validation\Validator\Exception as ValidatorException;
use Phalcon\Filter\Validation\Validator\ExclusionIn;
use Phalcon\Filter\Validation\Validator\File;
use Phalcon\Filter\Validation\Validator\Identical;
use Phalcon\Filter\Validation\Validator\InclusionIn;
use Phalcon\Filter\Validation\Validator\Ip;
use Phalcon\Filter\Validation\Validator\Numericality;
use Phalcon\Filter\Validation\Validator\PresenceOf;
use Phalcon\Filter\Validation\Validator\Regex;
use Phalcon\Filter\Validation\Validator\StringLength;
use Phalcon\Filter\Validation\Validator\Uniqueness;
use Phalcon\Filter\Validation\Validator\Url;

class ValidatorFactory extends AbstractFactory
{
    /**
     * TagFactory constructor.
     */
    public function __construct( array services = [])
    {
        this->init(services);
    }

    /**
     * Creates a new instance
     */
    public function newInstance( string name) -> <ValidatorInterface>
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
        return Exception::class;
    }

    /**
     * Returns the available adapters
     *
     * @return string[]
     */
    protected function getServices() -> array
    {
        return [
            "alnum"        : Alnum::class,
            "alpha"        : Alpha::class,
            "between"      : Between::class,
            "callback"     : Callback::class,
            "confirmation" : Confirmation::class,
            "creditCard"   : CreditCard::class,
            "date"         : Date::class,
            "digit"        : Digit::class,
            "email"        : Email::class,
            "exception"    : ValidatorException::class,
            "exclusionIn"  : ExclusionIn::class,
            "file"         : File::class,
            "identical"    : Identical::class,
            "inclusionIn"  : InclusionIn::class,
            "ip"           : Ip::class,
            "numericality" : Numericality::class,
            "presenceOf"   : PresenceOf::class,
            "regex"        : Regex::class,
            "stringLength" : StringLength::class,
            "uniqueness"   : Uniqueness::class,
            "url"          : Url::class
        ];
    }
}
