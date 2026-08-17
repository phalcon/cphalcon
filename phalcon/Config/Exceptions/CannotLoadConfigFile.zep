
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Config\Exceptions;

use Phalcon\Config\Exception;

class CannotLoadConfigFile extends Exception
{
    /**
     * @var string
     */
    private fileName;

    public function __construct(string fileName)
    {
        let this->fileName = fileName;

        parent::__construct(
            "Configuration file " . fileName . " cannot be loaded"
        );
    }

    public function getFileName() -> string
    {
        return this->fileName;
    }
}
