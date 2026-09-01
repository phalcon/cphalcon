
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Annotations\Exceptions;

use Phalcon\Annotations\Exception;

class AnnotationNotFound extends Exception
{
    public function __construct(string name)
    {
        parent::__construct(
            "Collection does not have an annotation called '" . name . "'"
        );
    }
}
