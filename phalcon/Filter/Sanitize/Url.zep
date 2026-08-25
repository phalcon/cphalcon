
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
        var sanitized, scheme;

        let sanitized = (string) filter_var(input, FILTER_SANITIZE_URL);

        /**
         * FILTER_SANITIZE_URL keeps the scheme intact, so a dangerous scheme
         * such as "javascript:", "data:" or "vbscript:" survives and becomes
         * XSS when the value is emitted into an href/src. Drop the value when
         * its scheme is not on the safe allow-list. An empty scheme (a
         * relative URL) is allowed.
         */
        let scheme = (string) parse_url(sanitized, PHP_URL_SCHEME);

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
