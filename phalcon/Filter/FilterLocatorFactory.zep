
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Filter;

use Phalcon\Filter\FilterLocator;
use Phalcon\Service\LocatorInterface;
use Phalcon\Service\LocatorFactoryInterface;

class FilterLocatorFactory implements LocatorFactoryInterface
{
    /**
     * Returns a Locator object with all the helpers defined in anonynous
     * functions
     */
    public function newInstance() -> <LocatorInterface>
    {
        var locator, helpers;

        /**
         * Available helpers
         */
        let helpers = [
            FilterLocator::FILTER_ABSINT      : function () {
                return new \Phalcon\Filter\Sanitize\AbsInt();
            },
            FilterLocator::FILTER_ALNUM       : function () {
                return new \Phalcon\Filter\Sanitize\Alnum();
            },
            FilterLocator::FILTER_ALPHA       : function () {
                return new \Phalcon\Filter\Sanitize\Alpha();
            },
            FilterLocator::FILTER_BOOL        : function () {
                return new \Phalcon\Filter\Sanitize\BoolVal();
            },
            FilterLocator::FILTER_EMAIL       : function () {
                return new \Phalcon\Filter\Sanitize\Email();
            },
            FilterLocator::FILTER_FLOAT       : function () {
                return new \Phalcon\Filter\Sanitize\FloatVal();
            },
            FilterLocator::FILTER_INT         : function () {
                return new \Phalcon\Filter\Sanitize\IntVal();
            },
            FilterLocator::FILTER_LOWER       : function () {
                return new \Phalcon\Filter\Sanitize\Lower();
            },
            FilterLocator::FILTER_LOWERFIRST  : function () {
                return new \Phalcon\Filter\Sanitize\LowerFirst();
            },
            FilterLocator::FILTER_REGEX       : function () {
                return new \Phalcon\Filter\Sanitize\Regex();
            },
            FilterLocator::FILTER_REMOVE      : function () {
                return new \Phalcon\Filter\Sanitize\Remove();
            },
            FilterLocator::FILTER_REPLACE     : function () {
                return new \Phalcon\Filter\Sanitize\Replace();
            },
            FilterLocator::FILTER_SPECIAL     : function () {
                return new \Phalcon\Filter\Sanitize\Special();
            },
            FilterLocator::FILTER_SPECIALFULL : function () {
                return new \Phalcon\Filter\Sanitize\SpecialFull();
            },
            FilterLocator::FILTER_STRING      : function () {
                return new \Phalcon\Filter\Sanitize\StringVal();
            },
            FilterLocator::FILTER_STRIPTAGS   : function () {
                return new \Phalcon\Filter\Sanitize\Striptags();
            },
            FilterLocator::FILTER_TRIM        : function () {
                return new \Phalcon\Filter\Sanitize\Trim();
            },
            FilterLocator::FILTER_UPPER       : function () {
                return new \Phalcon\Filter\Sanitize\Upper();
            },
            FilterLocator::FILTER_UPPERFIRST  : function () {
                return new \Phalcon\Filter\Sanitize\UpperFirst();
            },
            FilterLocator::FILTER_UPPERWORDS  : function () {
                return new \Phalcon\Filter\Sanitize\UpperWords();
            },
            FilterLocator::FILTER_URL         : function () {
                return new \Phalcon\Filter\Sanitize\Url();
            }
        ];

        let locator = new FilterLocator(helpers);

        return locator;
    }
}


