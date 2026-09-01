
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Filter\Sanitize;

use Phalcon\Contracts\Filter\Sanitizer;

/**
 * Phalcon\Filter\Sanitize\Url
 *
 * Sanitizes a value url
 */
class Url implements Sanitizer
{
    /**
     * @param mixed $input The text to sanitize
     *
     * @return string
     */
    public function __invoke(var input)
    {
        var parsed, sanitized, scheme;

        let sanitized = (string) filter_var(input, FILTER_SANITIZE_URL);

        /**
         * FILTER_SANITIZE_URL keeps the scheme intact, so a dangerous scheme
         * such as "javascript:", "data:" or "vbscript:" survives and becomes
         * XSS when the value is emitted into an href/src. Drop the value when
         * its scheme is not on the safe allow-list. An empty scheme (a
         * relative URL) is allowed.
         *
         * Decode HTML entities before the check, so an obfuscated scheme
         * such as "java&#115;cript:" cannot hide from parse_url(). A parse
         * failure (false) is not a relative URL: fail closed.
         */
        let parsed = parse_url(
            html_entity_decode(sanitized, ENT_QUOTES | ENT_HTML5),
            PHP_URL_SCHEME
        );

        if parsed === false {
            return "";
        }

        let scheme = (string) parsed;

        if scheme !== "" &&
            !in_array(
                strtolower(scheme),
                ["http", "https", "ftp", "ftps", "mailto", "tel"]
            ) {
            return "";
        }

        return sanitized;
    }
}
