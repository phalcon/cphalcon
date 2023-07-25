
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */

namespace Phalcon\Support\Helper\Json;

use InvalidArgumentException;

/**
 * Decodes a string using `json_decode` and throws an exception if the
 * JSON data cannot be decoded
 *
 * The following options are used if none specified for json_encode
 *
 * JSON_HEX_TAG, JSON_HEX_APOS, JSON_HEX_AMP, JSON_HEX_QUOT,
 * JSON_UNESCAPED_SLASHES
 *
 * If JSON_THROW_ON_ERROR is defined in the options a JsonException will be
 * thrown in the case of an error. Otherwise, any error will throw
 * InvalidArgumentException
 */
class Decode
{
    /**
     * @param string $data        JSON data to parse
     * @param bool   $associative When `true`, objects are converted to arrays
     * @param int    $depth       Recursion depth.
     * @param int    $options     Bitmask of JSON decode options.
     *
     * @return mixed
     *
     * @throws InvalidArgumentException if the JSON cannot be decoded.
     * @link https://www.php.net/manual/en/function.json-decode.php
     */
    public function __invoke(
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
         * The above will throw an exception when JSON_THROW_ON_ERROR is
         * specified. If not, the code below will handle the exception when
         * an error occurs
         */
        if (JSON_ERROR_NONE !== error) {
            json_encode(null);
            throw new InvalidArgumentException(message, error);
        }

        return decoded;
    }
}
