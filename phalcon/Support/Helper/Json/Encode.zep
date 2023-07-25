
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
 * Encodes a string using `json_encode` and throws an exception if the
 * JSON data cannot be encoded
 *
 * The following options are used if none specified for json_encode
 *
 * JSON_HEX_TAG, JSON_HEX_APOS, JSON_HEX_AMP, JSON_HEX_QUOT,
 * JSON_UNESCAPED_SLASHES
 *
 * If JSON_THROW_ON_ERROR is defined in the options a JsonException will be
 * thrown in the case of an error. Otherwise, any error will throw
 * InvalidArgumentException
 *
 * @see  https://www.ietf.org/rfc/rfc4627.txt
 */
class Encode
{
    /**
     * @param mixed $data    JSON data to parse
     * @param int   $options Bitmask of JSON encode options.
     * @param int   $depth   Recursion depth.
     *
     * @return string
     *
     * @throws InvalidArgumentException if the JSON cannot be encoded.
     * @link https://www.php.net/manual/en/function.json-encode.php
     */
    public function __invoke(
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
         * The above will throw an exception when JSON_THROW_ON_ERROR is
         * specified. If not, the code below will handle the exception when
         * an error occurs
         */
        if (JSON_ERROR_NONE !== error) {
            json_encode(null);
            throw new InvalidArgumentException(message, error);
        }

        return (string) encoded;
    }
}
