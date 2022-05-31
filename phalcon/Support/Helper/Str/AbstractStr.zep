
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */

namespace Phalcon\Support\Helper\Str;

/**
 * Abstract class offering methods to help with the Str namespace. This can
 * be moved to a trait once Zephir supports it.
 *
 * @todo move to trait when there is support for it
 */
abstract class AbstractStr
{
    /**
     * Check if a string ends with a given string
     *
     * @param string $haystack
     * @param string $needle
     * @param bool   $ignoreCase
     *
     * @return bool
     */
    protected function toEndsWith(
        string haystack,
        string needle,
        bool ignoreCase = true
    ) -> bool {
        var child, parent;

        if ("" === haystack) {
            return false;
        }

        if likely ignoreCase {
            let child  = mb_strtolower(needle),
                parent = mb_strtolower(haystack);
        } else {
            let child  = needle,
                parent = haystack;
        }


        return ends_with(parent, child);
    }

    /**
     * Interpolates context values into the message placeholders
     *
     * @see http://www.php-fig.org/psr/psr-3/ Section 1.2 Message
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
     * Check if a string starts with a given string
     *
     * @param string $haystack
     * @param string $needle
     * @param bool   $ignoreCase
     *
     * @return bool
     */
    protected function toStartsWith(
        string haystack,
        string needle,
        bool ignoreCase = true
    ) -> bool {
        var child, parent;

        if ("" === haystack) {
            return false;
        }

        if likely ignoreCase {
            let child  = mb_strtolower(needle),
                parent = mb_strtolower(haystack);
        } else {
            let child  = needle,
                parent = haystack;
        }


        return starts_with(parent, child);
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
