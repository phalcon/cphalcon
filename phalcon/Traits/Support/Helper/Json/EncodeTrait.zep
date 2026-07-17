
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Traits\Support\Helper\Json;

/**
 * Encodes data using `json_encode`, throwing the native `\JsonException` on
 * failure. Any framework-flavored exception is added by the `Support` helper
 * class that wraps this trait.
 */
trait EncodeTrait
{
    /**
     * Encodes data using `json_encode`
     *
     * @param mixed $data    JSON data to encode
     * @param int   $options Bitmask of json_encode options
     * @param int   $depth   Recursion depth
     *
     * @return string
     *
     * @throws \JsonException if the data cannot be encoded
     * @link https://www.php.net/manual/en/function.json-encode.php
     */
    protected static function toEncode(
        var data,
        int options = 79,
        int depth = 512
    ) -> string {
        var encoded, error, message;

        /**
         * Need to clear the json_last_error() before the code below
         */
        let encoded = json_encode(null),
            encoded = json_encode(data, options, depth),
            error   = json_last_error(),
            message = json_last_error_msg();

        /**
         * When JSON_THROW_ON_ERROR is set, json_encode() has already raised a
         * native \JsonException above; otherwise the error is surfaced the
         * same way here.
         */
        if (JSON_ERROR_NONE !== error) {
            json_encode(null);

            throw new \JsonException(message, error);
        }

        return (string) encoded;
    }
}
