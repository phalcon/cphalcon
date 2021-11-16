
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Storage\Serializer;

use InvalidArgumentException;
use JsonSerializable;

/**
 * Class Json
 *
 * @package Phalcon\Storage\Serializer
 */
class Json extends AbstractSerializer
{
    /**
     * Serializes data
     *
     * @return JsonSerializable|mixed|string
     */
    public function serialize()
    {
        if (typeof this->data === "object" && !(this->data instanceof JsonSerializable)) {
            throw new InvalidArgumentException(
                "Data for the JSON serializer cannot be of type 'object' " .
                "without implementing 'JsonSerializable'"
            );
        }

        if !this->isSerializable(this->data) {
            return this->data;
        }

        return this->getEncode(this->data);
    }

    /**
     * Unserializes data
     *
     * @param string $data
     *
     * @return void
     */
    public function unserialize(var data) -> void
    {
        let this->data = this->getDecode(data);
    }

    /**
     * @todo Remove this when we get traits
     */
    private function getDecode(
        string! data,
        bool associative = false,
        int depth = 512,
        int options = 0
    ) -> var
    {
        var decoded;

        let decoded = json_decode(data, associative, depth, options);

        if unlikely JSON_ERROR_NONE !== json_last_error() {
            throw new InvalidArgumentException(
                "json_decode error: " . json_last_error_msg()
            );
        }

        return decoded;
    }

    /**
     * @todo Remove this when we get traits
     */
    private function getEncode(
        var data,
        int options = 0,
        int depth = 512
    ) -> string
    {
        var encoded;

        let encoded = json_encode(data, options, depth);

        if unlikely JSON_ERROR_NONE !== json_last_error() {
            throw new InvalidArgumentException(
                "json_encode error: " . json_last_error_msg()
            );
        }

        return encoded;
    }

}
