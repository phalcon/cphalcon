
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Storage\Serializer;

class Msgpack extends Igbinary
{
    /**
     * Serializes data
     *
     * @return string
     */
    protected function doSerialize(var value) -> string
    {
		return msgpack_pack(this->data);
	}

    /**
     * @param mixed $value
     *
     * @return mixed
     */
    protected function doUnserialize(value)
    {
        return msgpack_unpack(value);
    }
}
