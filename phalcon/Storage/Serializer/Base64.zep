
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Storage\Serializer;

use Phalcon\Storage\Serializer\Exceptions\InvalidSerializationInput;
use Phalcon\Storage\Serializer\Exceptions\InvalidUnserializationInput;

class Base64 extends AbstractSerializer
{
    /**
     * Serializes data
     *
     * @return string
     */
	public function serialize() -> string
	{
	    if typeof this->data !== "string" {
	        throw new InvalidSerializationInput();
	    }

		return base64_encode(this->data);
	}

    /**
     * Unserializes data
     *
     * @param mixed $data
     *
     * @retrun void
     */
	public function unserialize(mixed data) -> void
	{
	    var result;

	    if typeof data !== "string" {
	        throw new InvalidUnserializationInput();
	    }

        let result = this->phpBase64Decode(data, true);

        if unlikely false === result {
            let this->isSuccess = false,
                result          = "";
        } else {
            let this->isSuccess = true;
        }

        let this->data = result;
    }

    /**
     * Wrapper for base64_decode
     *
     * @param string $input
     * @param bool   $strict
     *
     * @return string|false
     */
    protected function phpBase64Decode(string input, bool strict = false)
    {
        return base64_decode(input, strict);
    }
}
