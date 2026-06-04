
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Paginator\Exceptions;

use Phalcon\Paginator\Exception;

class BuilderModelNotDefined extends Exception
{
    public function __construct()
    {
        parent::__construct("Model not defined in builder");
    }
}
