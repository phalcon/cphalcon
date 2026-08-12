
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Translate\Adapter;

use Phalcon\Contracts\Translate\TranslateTypes;
use Phalcon\Translate\Exception;
use Phalcon\Translate\Exceptions\InvalidDataType;
use Phalcon\Translate\Exceptions\MissingContent;
use Phalcon\Translate\InterpolatorFactory;

/**
 * Defines translation lists using PHP arrays
 *
 * @phpstan-import-type translate_array_options from TranslateTypes
 * @phpstan-import-type translate_data from TranslateTypes
 * @phpstan-import-type translate_placeholders from TranslateTypes
 */
class NativeArray extends AbstractAdapter
{
    /**
     * @phpstan-var translate_data
     */
    private array translate = [];

    /**
     * NativeArray constructor.
     *
     * @param InterpolatorFactory        $interpolator
     * @phpstan-param translate_array_options $options
     *
     * @throws InvalidDataType
     * @throws MissingContent
     */
    public function __construct(
        <InterpolatorFactory> interpolator,
	array options
    ) {
        var data;

        parent::__construct(interpolator, options);

        if unlikely !fetch data, options["content"] {
            throw new MissingContent();
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
    public function exists( string index) -> bool
    {
        return this->has(index);
    }

    /**
     * Check whether is defined a translation key in the internal array
     */
    public function has( string index) -> bool
    {
        return isset this->translate[index];
    }

    /**
     * Returns the translation related to the given key
     *
     * @phpstan-param translate_placeholders $placeholders
     *
     * @return string
     * @throws Exception
     */
    public function query( string translateKey, array placeholders = []) -> string
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
     * @phpstan-return translate_data
     */
    public function toArray() -> array
    {
        return this->translate;
    }
}
