
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Translate\Adapter;

use Phalcon\Translate\Exception;
use Phalcon\Translate\Exceptions\InvalidDataType;
use Phalcon\Translate\Exceptions\MissingContent;
use Phalcon\Translate\Exceptions\KeyNotFound;
use Phalcon\Translate\InterpolatorFactory;

/**
 * Defines translation lists using PHP arrays
 *
 * @phpstan-type TOptions array{
 *      content?: array<string, string>,
 *      triggerError?: bool
 * }
 */
class NativeArray extends AbstractAdapter
{
    /**
     * @var array
     */
    private translate = [];

    /**
     * @var bool
     */
    private triggerError = false;

    /**
     * NativeArray constructor.
     *
     * @param InterpolatorFactory $interpolator
     * @param TOptions            $options
     *
     * @throws Exception
     */
    public function __construct(<InterpolatorFactory> interpolator, array! options)
    {
        var data, error;

        parent::__construct(interpolator, options);

        if unlikely !fetch data, options["content"] {
            throw new MissingContent();
        }

        if fetch error, options["triggerError"] {
            let this->triggerError = (bool) error;
        }

        if unlikely typeof data !== "array" {
            throw new InvalidDataType();
        }

        let this->translate = data;
    }

    /**
     * Check whether is defined a translation key in the internal array
     *
     * @param string $index
     *
     * @return bool
     * @deprecated
     */
    public function exists(string! index) -> bool
    {
        return this->has(index);
    }

    /**
     * Check whether is defined a translation key in the internal array
     *
     * @param string $index
     *
     * @return bool
     */
    public function has(string! index) -> bool
    {
        return isset this->translate[index];
    }

    /**
     * Whenever a key is not found this method will be called
     *
     * @param string $index
     *
     * @return string
     * @throws Exception
     */
    public function notFound(string! index) -> string
    {
        if unlikely (true === this->triggerError) {
            throw new KeyNotFound(index);
        }

        return index;
    }

    /**
     * Returns the translation related to the given key
     *
     * @phpstan-param array<string, string> $placeholders
     *
     * @return string
     * @throws Exception
     */
    public function query(string! translateKey, array placeholders = []) -> string
    {
        var translation;

        if !fetch translation, this->translate[translateKey] {
            return this->notFound(translateKey);
        }

        return this->replacePlaceholders(translation, placeholders);
    }

    /**
     * Returns the internal array
     *
     * @phpstan-return array<string, string>
     */
    public function toArray() -> array
    {
        return this->translate;
    }
}
