
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */

namespace Phalcon\Support\Helper\Json;

use JsonException;
use Phalcon\Support\Helper\Json\Exceptions\JsonDecodeError;
use Phalcon\Traits\Support\Helper\Json\DecodeTrait;

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
 * JsonDecodeError
 */
class Decode
{
    use DecodeTrait;

    /**
     * @param int<1, max> $depth       Recursion depth.
     *
     * @throws JsonDecodeError if the JSON cannot be decoded.
     * @link https://www.php.net/manual/en/function.json-decode.php
     */
    public function __invoke(
        string data,
        bool associative = false,
        int depth = 512,
        int options = 79
    ) {
        var ex;

        try {
            return this->toDecode(data, associative, depth, options);
        } catch JsonException, ex {
            throw new JsonDecodeError(ex->getMessage(), ex->getCode(), ex);
        }
    }
}
