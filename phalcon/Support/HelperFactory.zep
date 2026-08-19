
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */

namespace Phalcon\Support;

use Phalcon\Contracts\Support\SupportTypes;
use Phalcon\Factory\AbstractFactory;
use Phalcon\Support\Helper\Arr\Blacklist;
use Phalcon\Support\Helper\Arr\Chunk;
use Phalcon\Support\Helper\Arr\Filter;
use Phalcon\Support\Helper\Arr\First;
use Phalcon\Support\Helper\Arr\FirstKey;
use Phalcon\Support\Helper\Arr\Flatten;
use Phalcon\Support\Helper\Arr\Get;
use Phalcon\Support\Helper\Arr\Group;
use Phalcon\Support\Helper\Arr\Has;
use Phalcon\Support\Helper\Arr\IsUnique;
use Phalcon\Support\Helper\Arr\Last;
use Phalcon\Support\Helper\Arr\LastKey;
use Phalcon\Support\Helper\Arr\Order;
use Phalcon\Support\Helper\Arr\Pluck;
use Phalcon\Support\Helper\Arr\Set;
use Phalcon\Support\Helper\Arr\SliceLeft;
use Phalcon\Support\Helper\Arr\SliceRight;
use Phalcon\Support\Helper\Arr\Split;
use Phalcon\Support\Helper\Arr\ToObject;
use Phalcon\Support\Helper\Arr\ValidateAll;
use Phalcon\Support\Helper\Arr\ValidateAny;
use Phalcon\Support\Helper\Arr\Whitelist;
use Phalcon\Support\Helper\File\Basename;
use Phalcon\Support\Helper\Json\Decode;
use Phalcon\Support\Helper\Json\Encode;
use Phalcon\Support\Helper\Number\IsBetween;
use Phalcon\Support\Helper\Str\Camelize;
use Phalcon\Support\Helper\Str\Concat;
use Phalcon\Support\Helper\Str\CountVowels;
use Phalcon\Support\Helper\Str\Decapitalize;
use Phalcon\Support\Helper\Str\Decrement;
use Phalcon\Support\Helper\Str\DirFromFile;
use Phalcon\Support\Helper\Str\DirSeparator;
use Phalcon\Support\Helper\Str\Dynamic;
use Phalcon\Support\Helper\Str\EndsWith;
use Phalcon\Support\Helper\Str\FirstBetween;
use Phalcon\Support\Helper\Str\Friendly;
use Phalcon\Support\Helper\Str\Humanize;
use Phalcon\Support\Helper\Str\Includes;
use Phalcon\Support\Helper\Str\Increment;
use Phalcon\Support\Helper\Str\Interpolate;
use Phalcon\Support\Helper\Str\IsAnagram;
use Phalcon\Support\Helper\Str\IsLower;
use Phalcon\Support\Helper\Str\IsPalindrome;
use Phalcon\Support\Helper\Str\IsUpper;
use Phalcon\Support\Helper\Str\KebabCase;
use Phalcon\Support\Helper\Str\Len;
use Phalcon\Support\Helper\Str\Lower;
use Phalcon\Support\Helper\Str\PascalCase;
use Phalcon\Support\Helper\Str\Prefix;
use Phalcon\Support\Helper\Str\Random;
use Phalcon\Support\Helper\Str\ReduceSlashes;
use Phalcon\Support\Helper\Str\SnakeCase;
use Phalcon\Support\Helper\Str\StartsWith;
use Phalcon\Support\Helper\Str\Suffix;
use Phalcon\Support\Helper\Str\Ucwords;
use Phalcon\Support\Helper\Str\Uncamelize;
use Phalcon\Support\Helper\Str\Underscore;
use Phalcon\Support\Helper\Str\Upper;
use Throwable;

/**
 * ServiceLocator implementation for helpers
 *
 * @phpstan-import-type support_collection from SupportTypes
 * @phpstan-import-type support_helper_services from SupportTypes
 *
 * @method string basename(string $uri, string $suffix = null)
 * @method support_collection blacklist(support_collection $collection, support_collection $blackList)
 * @method string camelize(string $text, string $delimiters = null, bool $lowerFirst = false)
 * @method support_collection chunk(support_collection $collection, int $size, bool $preserveKeys = false)
 * @method string concat(string $delimiter, string $first, string $second, string ...$arguments)
 * @method int    countVowels(string $text)
 * @method string decapitalize(string $text, bool $upperRest = false, string $encoding = 'UTF-8')
 * @method string decode(string $data, bool $associative = false, int $depth = 512, int $options = 0)
 * @method string decrement(string $text, string $separator = '_')
 * @method string dirFromFile(string $file)
 * @method string dirSeparator(string $directory)
 * @method string dynamic(string $text, string $leftDel = "{", string $rightDel = "}", string $separator = "|")
 * @method string encode($data, int $options = 0, int $depth = 512)
 * @method bool   endsWith(string $haystack, string $needle, bool $ignoreCase = true)
 * @method mixed  filter(support_collection $collection, callable|null $method)
 * @method mixed  first(support_collection $collection, callable $method = null)
 * @method string firstBetween(string $text, string $start, string $end)
 * @method mixed  firstKey(support_collection $collection, callable $method = null)
 * @method string friendly(string $text, string $separator = '-', bool $lowercase = true, $replace = null)
 * @method support_collection flatten(support_collection $collection, bool $deep = false)
 * @method mixed  get(support_collection $collection, $index, $defaultValue = null, string $cast = null)
 * @method array<array-key, list<mixed>> group(support_collection $collection, $method)
 * @method bool   has(support_collection $collection, $index)
 * @method string humanize(string $text)
 * @method bool   includes(string $haystack, string $needle)
 * @method string increment(string $text, string $separator = '_')
 * @method string interpolate(string $message, string[] $context=[], string $leftToken="%", string $rightToken="%")
 * @method bool   isAnagram(string $first, string $second)
 * @method bool   isBetween(int $value, int $start, int $end)
 * @method bool   isLower(string $text, string $encoding = 'UTF-8')
 * @method bool   isPalindrome(string $text)
 * @method bool   isUnique(support_collection $collection)
 * @method bool   isUpper(string $text, string $encoding = 'UTF-8')
 * @method string kebabCase(string $text, string $delimiters = null)
 * @method mixed  last(support_collection $collection, callable $method = null)
 * @method mixed  lastKey(support_collection $collection, callable $method = null)
 * @method int    len(string $text, string $encoding = 'UTF-8')
 * @method string lower(string $text, string $encoding = 'UTF-8')
 * @method support_collection order(support_collection $collection, $attribute, string $order = 'asc')
 * @method string pascalCase(string $text, string $delimiters = null)
 * @method support_collection pluck(support_collection $collection, string $element)
 * @method string prefix(string $text, string $prefix)
 * @method string random(int $type = 0, int $length = 8)
 * @method string reduceSlashes(string $text)
 * @method support_collection set(support_collection $collection, $value, $index = null)
 * @method support_collection sliceLeft(support_collection $collection, int $elements = 1)
 * @method support_collection sliceRight(support_collection $collection, int $elements = 1)
 * @method string snakeCase(string $text, string $delimiters = null)
 * @method support_collection split(support_collection $collection)
 * @method bool   startsWith(string $haystack, string $needle, bool $ignoreCase = true)
 * @method string suffix(string $text, string $suffix)
 * @method object toObject(support_collection $collection)
 * @method bool   validateAll(support_collection $collection, callable $method)
 * @method bool   validateAny(support_collection $collection, callable $method)
 * @method string ucwords(string $text, string $encoding = 'UTF-8')
 * @method string uncamelize(string $text, string $delimiters = '_')
 * @method string underscore(string $text)
 * @method string upper(string $text, string $encoding = 'UTF-8')
 * @method support_collection whitelist(support_collection $collection, support_collection $whiteList)
 */
class HelperFactory extends AbstractFactory
{
    /**
     * Constructor.
     *
     * @phpstan-param support_helper_services $services
     */
    public function __construct( array services = [])
    {
        this->init(services);
    }

    /**
     * @phpstan-param array<array-key, mixed> $arguments
     *
     * @throws Exception
     */
    public function __call(string name, array arguments)
    {
        var helper;

        let helper = this->newInstance(name);

        return call_user_func_array([helper, "__invoke"], arguments);
    }

    /**
     * @return object
     *
     * @throws Exception
     */
    public function newInstance(string name)
    {
        if (true !== isset(this->services[name])) {
            let this->services[name] = create_instance(this->getService(name));
        }

        return this->services[name];
    }

    /**
     * @return class-string<Throwable>
     */
    protected function getExceptionClass() -> string
    {
        return Exception::class;
    }

    /**
     * Returns the available adapters
     *
     * @phpstan-return support_helper_services
     *
     * @return string[]
     */
    protected function getServices() -> array
    {
        return [
            "blacklist"     : Blacklist::class,
            "chunk"         : Chunk::class,
            "filter"        : Filter::class,
            "first"         : First::class,
            "firstKey"      : FirstKey::class,
            "flatten"       : Flatten::class,
            "get"           : Get::class,
            "group"         : Group::class,
            "has"           : Has::class,
            "isUnique"      : IsUnique::class,
            "last"          : Last::class,
            "lastKey"       : LastKey::class,
            "order"         : Order::class,
            "pluck"         : Pluck::class,
            "set"           : Set::class,
            "sliceLeft"     : SliceLeft::class,
            "sliceRight"    : SliceRight::class,
            "split"         : Split::class,
            "toObject"      : ToObject::class,
            "validateAll"   : ValidateAll::class,
            "validateAny"   : ValidateAny::class,
            "whitelist"     : Whitelist::class,
            "basename"      : Basename::class,
            "decode"        : Decode::class,
            "encode"        : Encode::class,
            "isBetween"     : IsBetween::class,
            "camelize"      : Camelize::class,
            "concat"        : Concat::class,
            "countVowels"   : CountVowels::class,
            "decapitalize"  : Decapitalize::class,
            "decrement"     : Decrement::class,
            "dirFromFile"   : DirFromFile::class,
            "dirSeparator"  : DirSeparator::class,
            "dynamic"       : Dynamic::class,
            "endsWith"      : EndsWith::class,
            "firstBetween"  : FirstBetween::class,
            "friendly"      : Friendly::class,
            "humanize"      : Humanize::class,
            "includes"      : Includes::class,
            "increment"     : Increment::class,
            "interpolate"   : Interpolate::class,
            "isAnagram"     : IsAnagram::class,
            "isLower"       : IsLower::class,
            "isPalindrome"  : IsPalindrome::class,
            "isUpper"       : IsUpper::class,
            "kebabCase"     : KebabCase::class,
            "len"           : Len::class,
            "lower"         : Lower::class,
            "pascalCase"    : PascalCase::class,
            "prefix"        : Prefix::class,
            "random"        : Random::class,
            "reduceSlashes" : ReduceSlashes::class,
            "snakeCase"     : SnakeCase::class,
            "startsWith"    : StartsWith::class,
            "suffix"        : Suffix::class,
            "ucwords"       : Ucwords::class,
            "uncamelize"    : Uncamelize::class,
            "underscore"    : Underscore::class,
            "upper"         : Upper::class
        ];
    }
}
