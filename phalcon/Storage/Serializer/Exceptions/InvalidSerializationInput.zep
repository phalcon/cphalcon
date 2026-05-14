
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Storage\Serializer\Exceptions;

class InvalidSerializationInput extends \InvalidArgumentException
{
    public function __construct()
    {
        parent::__construct("Data for the serializer must be of type string");
    }
}
