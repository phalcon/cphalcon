
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Storage\Serializer;

use Phalcon\Support\Helper\Json\Decode;
use Phalcon\Support\Helper\Json\Encode;

class Json extends AbstractSerializer
{
    private <Decode> decode;
    private <Encode> encode;

    /**
     * AbstractSerializer constructor.
     */
    public function __construct(var data = null)
    {
        let this->encode = new Encode(),
            this->decode = new Decode();

        parent::__construct(data);
    }

    /**
     * Serializes data
     */
    public function serialize() -> mixed
    {
        if (true !== this->isSerializable(this->data)) {
            return this->data;
        }

        return this->encode->__invoke(this->data);
    }

    /**
     * Unserializes data
     */
    public function unserialize(mixed data) -> void
    {
        if (true !== this->isSerializable(data)) {
            let this->data = data;
        } else {
            let this->data = this->decode->__invoke(data);
        }
    }
}
