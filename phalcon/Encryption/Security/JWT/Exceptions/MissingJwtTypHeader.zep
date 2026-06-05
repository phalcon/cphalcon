
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Encryption\Security\JWT\Exceptions;

use InvalidArgumentException;

class MissingJwtTypHeader extends InvalidArgumentException
{
    public function __construct()
    {
        parent::__construct("Invalid Header (missing 'typ' element)");
    }
}
