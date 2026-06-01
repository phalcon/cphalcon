
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Storage\Serializer;

interface SerializerInterface
{
    /**
     * @return mixed
     */
    public function getData() -> var;

    /**
     * Serializes data
     *
     * @return mixed
     */
    public function serialize() -> var;

    /**
     * @param mixed $data
     */
    public function setData(var data) -> void;

    /**
     * Unserializes data
     *
     * @param mixed $data
     */
    public function unserialize(var data) -> void;
}
