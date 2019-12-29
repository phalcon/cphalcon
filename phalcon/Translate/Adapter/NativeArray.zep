
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Translate\Adapter;

use ArrayAccess;
use Phalcon\Translate\Exception;
use Phalcon\Translate\InterpolatorFactory;

/**
 * Phalcon\Translate\Adapter\NativeArray
 *
 * Allows to define translation lists using PHP arrays
 */
class NativeArray extends AbstractAdapter implements ArrayAccess
{
    /**
     * @var array
     */
    private translate;

    /**
     * @var bool
     */
    private triggerError = false;

    /**
     * Phalcon\Translate\Adapter\NativeArray constructor
     *
     * @param array options = [
     *     'content' => '',
     *     'triggerError' => false
     * ]
     */
    public function __construct(<InterpolatorFactory> interpolator, array! options)
    {
        var data, error;

        parent::__construct(interpolator, options);

        if unlikely !fetch data, options["content"] {
            throw new Exception("Translation content was not provided");
        }

        if fetch error, options["triggerError"] {
            let this->triggerError = (bool) error;
        }

        if unlikely typeof data !== "array" {
            throw new Exception("Translation data must be an array");
        }

        let this->translate = data;
    }

    /**
     * Check whether is defined a translation key in the internal array
     */
    public function exists(string! index) -> bool
    {
        return isset this->translate[index];
    }

    /**
     * Whenever a key is not found this medhod will be called
     */
    public function notFound(string! index) -> string
    {
        if unlikely (true === this->triggerError) {
            throw new Exception("Cannot find translation key: " . index);
        }

        return index;
    }

    /**
     * Returns the translation related to the given key
     */
    public function query(string! index, array placeholders = []) -> string
    {
        var translation;

        if !fetch translation, this->translate[index] {
            return this->notFound(index);
        }

        return this->replacePlaceholders(translation, placeholders);
    }
}
