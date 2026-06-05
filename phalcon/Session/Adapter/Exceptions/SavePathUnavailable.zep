
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */

namespace Phalcon\Session\Adapter\Exceptions;

use Phalcon\Session\Exception;

class SavePathUnavailable extends Exception
{
    public function __construct(string path)
    {
        parent::__construct("The session save path [" . path . "] is not writable");
    }
}
