
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Forms\Exceptions;

use Phalcon\Forms\Exception;

class SchemaEntryMissingKey extends Exception
{
    public function __construct(int index, string key)
    {
        parent::__construct(
            "Form schema definition at index " . index . " is missing required key \"" . key . "\""
        );
    }
}
