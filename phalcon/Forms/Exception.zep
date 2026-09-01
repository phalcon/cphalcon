
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Forms;

/**
 * Exceptions thrown in Phalcon\Forms will use this class
 */
class Exception extends \Exception
{
    public static function tagFactoryNotFound() -> <self>
    {
        return new self(
            "A TagFactory must be provided via setTagFactory() or through a parent Form"
        );
    }

    public static function usingParameterRequired() -> <self>
    {
        return new self(
            "The 'using' parameter is required for resultset options"
        );
    }
}
