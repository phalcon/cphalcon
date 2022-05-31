
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Storage\Serializer;

/**
 * @property mixed $data
 * @property bool  $isSuccess
 */
abstract class AbstractSerializer implements SerializerInterface
{
    /**
     * @var mixed
     */
    protected data = null;

    /**
     * @var bool
     */
    protected isSuccess = true;

    /**
     * AbstractSerializer constructor.
     *
     * @param mixed|null $data
     */
    public function __construct(var data = null)
    {
        this->setData(data);
    }

    /**
     * @return mixed
     */
    public function getData()
    {
        return this->data;
    }

    /**
     * Returns `true` if the serialize/unserialize operation was successful;
     * `false` otherwise
     *
     * @return bool
     */
    public function isSuccess() -> bool
    {
        return this->isSuccess;
    }

    /**
     * @param mixed $data
     */
    public function setData(data) -> void
    {
        let this->data = data;
    }

    /**
     * If this returns true, then the data is returned as is
     *
     * @param mixed $data
     *
     * @return bool
     */
    protected function isSerializable(data) -> bool
    {
        return !(
            null === data ||
            true === is_bool(data) ||
            true === is_numeric(data)
        );
    }

    public function __serialize() -> array
    {
        if typeof this->data === "array" {
            return this->data;
        }

        return [];
    }

    public function __unserialize(array data) -> void
    {
        let this->data = data;
    }
}
