
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Storage\Serializer;

use Serializable;

interface SerializerInterface extends Serializable
{
    /**
     * @var mixed
     */
    public function getData() -> var;

    /**
     * @param $data
     */
    public function setData(var data) -> void;
}
