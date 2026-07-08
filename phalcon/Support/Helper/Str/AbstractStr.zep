
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */

namespace Phalcon\Support\Helper\Str;

use Phalcon\Traits\Support\Helper\Str\EndsWithTrait;
use Phalcon\Traits\Support\Helper\Str\StartsWithTrait;

/**
 * Abstract class offering methods to help with the Str namespace. This can
 * be moved to a trait once Zephir supports it.
 *
 * This base exists only for the `Str` helper hierarchy; it is not a general
 * base class. New code that needs these routines should compose the relevant
 * invokable helper (for example `Str\Interpolate`) rather than extending it.
 *
 * @internal
 *
 * @todo move to trait when there is support for it
 */
abstract class AbstractStr
{
    use EndsWithTrait;
    use StartsWithTrait;

    /**
     * Interpolates context values into the message placeholders
     *
     * @see https://www.php-fig.org/psr/psr-3/ Section 1.2 Message
     *
     * @param string $input
     * @param array  $context
     * @param string $left
     * @param string $right
     *
     * @return string
     */
    protected function toInterpolate(
        string input,
        array context = [],
        string left = "%",
        string right = "%"
    ) -> string {
        var key, replace, value;

        if empty(context) {
            return input;
        }

        let replace = [];
        for key, value in context {
            let replace[left . key . right] = value;
        }

        return strtr(input, replace);
    }

    /**
     * Lowercases a string using mbstring
     *
     * @param string $text
     * @param string $encoding
     *
     * @return string
     */
    protected function toLower(
        string text,
        string encoding = "UTF-8"
    ) -> string {
        return mb_convert_case(text, MB_CASE_LOWER, encoding);
    }

    /**
     * Uppercases a string using mbstring
     *
     * @param string $text
     * @param string $encoding
     *
     * @return string
     */
    protected function toUpper(
        string text,
        string encoding = "UTF-8"
    ) -> string {
        return mb_convert_case(text, MB_CASE_UPPER, encoding);
    }
}
