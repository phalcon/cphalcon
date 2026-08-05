
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Storage\Serializer;

use Phalcon\Traits\Php\MsgpackTrait;

class Msgpack extends Igbinary
{
    use MsgpackTrait;

    /**
     * Serializes data
     */
    protected function doSerialize(var value) -> string
    {
		return this->phpMsgpackPack(value);
    }

    /**
     * @param mixed $value
     */
    protected function doUnserialize(value)
    {
        return this->phpMsgpackUnpack(value);
    }
}
