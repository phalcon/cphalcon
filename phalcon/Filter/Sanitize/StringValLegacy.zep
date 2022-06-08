
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Filter\Sanitize;

/**
 * Sanitizes a value to string using `filter_var()`. The filter provides
 * backwards compatibility with versions prior to v5. For PHP higher or equal to
 * 8.1, the filter will remain the string unchanged. If anything other than a
 * string is passed, the method will return false
 */
class StringValLegacy
{
    /**
     * @param string $input The text to sanitize
     *
     * @return string|false
     */
    public function __invoke(mixed input)
    {
        var major, minor;

        let major = PHP_MAJOR_VERSION,
            minor = PHP_MINOR_VERSION;

        if (
            major < 8 ||
            (major === 8 && minor === 0)
        ) {
            return filter_var(input, 513);
        }

        return input;
    }
}
