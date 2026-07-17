
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
 * Decodes a string using `json_decode`, throwing the native `\JsonException`
 * on failure. Any framework-flavored exception is added by the `Support`
 * helper class that wraps this trait.
 */
trait DecodeTrait
{
    /**
     * Decodes a string using `json_decode`
     *
     * @param string $data        JSON data to parse
     * @param bool   $associative When `true`, objects are converted to arrays
     * @param int    $depth       Recursion depth
     * @param int    $options     Bitmask of json_decode options
     *
     * @return mixed
     *
     * @throws \JsonException if the data cannot be decoded
     * @link https://www.php.net/manual/en/function.json-decode.php
     */
    protected static function toDecode(
        string data,
        bool associative = false,
        int depth = 512,
        int options = 79
    ) {
        var decoded, error, message;

        /**
         * Need to clear the json_last_error() before the code below
         */
        let decoded = json_encode(null),
            decoded = json_decode(data, associative, depth, options),
            error   = json_last_error(),
            message = json_last_error_msg();

        /**
         * When JSON_THROW_ON_ERROR is set, json_decode() has already raised a
         * native \JsonException above; otherwise the error is surfaced the
         * same way here.
         */
        if (JSON_ERROR_NONE !== error) {
            json_encode(null);

            throw new \JsonException(message, error);
        }

        return decoded;
    }
}
