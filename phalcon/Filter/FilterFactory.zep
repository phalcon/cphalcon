
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
            Filter::FILTER_ABSINT     : "Phalcon\\Filter\\Sanitize\\AbsInt",
            Filter::FILTER_ALNUM      : "Phalcon\\Filter\\Sanitize\\Alnum",
            Filter::FILTER_ALPHA      : "Phalcon\\Filter\\Sanitize\\Alpha",
            Filter::FILTER_BOOL       : "Phalcon\\Filter\\Sanitize\\BoolVal",
            Filter::FILTER_EMAIL      : "Phalcon\\Filter\\Sanitize\\Email",
            Filter::FILTER_FLOAT      : "Phalcon\\Filter\\Sanitize\\FloatVal",
            Filter::FILTER_INT        : "Phalcon\\Filter\\Sanitize\\IntVal",
            Filter::FILTER_LOWER      : "Phalcon\\Filter\\Sanitize\\Lower",
            Filter::FILTER_LOWERFIRST : "Phalcon\\Filter\\Sanitize\\LowerFirst",
            Filter::FILTER_REGEX      : "Phalcon\\Filter\\Sanitize\\Regex",
            Filter::FILTER_REMOVE     : "Phalcon\\Filter\\Sanitize\\Remove",
            Filter::FILTER_REPLACE    : "Phalcon\\Filter\\Sanitize\\Replace",
            Filter::FILTER_SPECIAL    : "Phalcon\\Filter\\Sanitize\\Special",
            Filter::FILTER_SPECIALFULL: "Phalcon\\Filter\\Sanitize\\SpecialFull",
            Filter::FILTER_STRING     : "Phalcon\\Filter\\Sanitize\\StringVal",
            Filter::FILTER_STRIPTAGS  : "Phalcon\\Filter\\Sanitize\\Striptags",
            Filter::FILTER_TRIM       : "Phalcon\\Filter\\Sanitize\\Trim",
            Filter::FILTER_UPPER      : "Phalcon\\Filter\\Sanitize\\Upper",
            Filter::FILTER_UPPERFIRST : "Phalcon\\Filter\\Sanitize\\UpperFirst",
            Filter::FILTER_UPPERWORDS : "Phalcon\\Filter\\Sanitize\\UpperWords",
            Filter::FILTER_URL        : "Phalcon\\Filter\\Sanitize\\Url"
        ];
    }
}
