
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Filter;

use Phalcon\Filter;

class FilterFactory
{
    /**
     * Returns a Locator object with all the helpers defined in anonymous
     * functions
     */
    public function newInstance() -> <FilterInterface>
    {
        return new Filter(
            this->getAdapters()
        );
    }

    protected function getAdapters() -> array
    {
        return [
            "absint"      : "Phalcon\\Filter\\Sanitize\\AbsInt",
            "alnum"       : "Phalcon\\Filter\\Sanitize\\Alnum",
            "alpha"       : "Phalcon\\Filter\\Sanitize\\Alpha",
            "bool"        : "Phalcon\\Filter\\Sanitize\\BoolVal",
            "email"       : "Phalcon\\Filter\\Sanitize\\Email",
            "float"       : "Phalcon\\Filter\\Sanitize\\FloatVal",
            "int"         : "Phalcon\\Filter\\Sanitize\\IntVal",
            "lower"       : "Phalcon\\Filter\\Sanitize\\Lower",
            "lowerFirst"  : "Phalcon\\Filter\\Sanitize\\LowerFirst",
            "regex"       : "Phalcon\\Filter\\Sanitize\\Regex",
            "remove"      : "Phalcon\\Filter\\Sanitize\\Remove",
            "replace"     : "Phalcon\\Filter\\Sanitize\\Replace",
            "special"     : "Phalcon\\Filter\\Sanitize\\Special",
            "specialFull" : "Phalcon\\Filter\\Sanitize\\SpecialFull",
            "string"      : "Phalcon\\Filter\\Sanitize\\StringVal",
            "striptags"   : "Phalcon\\Filter\\Sanitize\\Striptags",
            "trim"        : "Phalcon\\Filter\\Sanitize\\Trim",
            "upper"       : "Phalcon\\Filter\\Sanitize\\Upper",
            "upperFirst"  : "Phalcon\\Filter\\Sanitize\\UpperFirst",
            "upperWords"  : "Phalcon\\Filter\\Sanitize\\UpperWords",
            "url"         : "Phalcon\\Filter\\Sanitize\\Url"
        ];
    }
}
