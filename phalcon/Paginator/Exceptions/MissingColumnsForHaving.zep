
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

class MissingColumnsForHaving extends Exception
{
    public function __construct()
    {
        parent::__construct(
            "When having is set there should be columns option provided for which calculate row count"
        );
    }
}
