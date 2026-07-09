
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
use Phalcon\Traits\Php\Base64Trait;

class Base64 extends AbstractSerializer
{
    use Base64Trait;

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

		return this->phpBase64Encode(this->data);
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
}
