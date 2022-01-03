
/**
 * This file is part of the Phalcon.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */

namespace Phalcon\Support;

use Phalcon\Factory\AbstractFactory;

/**
 * ServiceLocator implementation for helpers
 *
 * @method array  blacklist(array $collection, array $blackList)
 * @method array  chunk(array $collection, int $size, bool $preserveKeys = false)
 * @method mixed  first(array $collection, callable $method = null)
 * @method mixed  firstKey(array $collection, callable $method = null)
 * @method array  flatten(array $collection, bool $deep = false)
 * @method mixed  get(array $collection, $index, $defaultValue = null, string $cast = null)
 * @method array  group(array $collection, $method)
 * @method bool   has(array $collection, $index)
 * @method bool   isUnique(array $collection)
 * @method mixed  last(array $collection, callable $method = null)
 * @method mixed  lastKey(array $collection, callable $method = null)
 * @method array  order(array $collection, $attribute, string $order = 'asc')
 * @method array  pluck(array $collection, string $element)
 * @method array  set(array $collection, $value, $index = null)
 * @method array  sliceLeft(array $collection, int $elements = 1)
 * @method array  sliceRight(array $collection, int $elements = 1)
 * @method array  split(array $collection)
 * @method object toObject(array $collection)
 * @method bool   validateAll(array $collection, callable $method)
 * @method bool   validateAny(array $collection, callable $method)
 * @method array  whitelist(array $collection, array $whiteList)
 * @method string basename(string $uri, string $suffix = null)
 * @method string decode(string $data, bool $associative = false, int $depth = 512, int $options = 0)
 * @method string encode($data, int $options = 0, int $depth = 512)
 * @method bool   between(int $value, int $start, int $end)
 * @method string camelize(string $text, string $delimiters = null, bool $lowerFirst = false)
 * @method string concat(string $delimiter, string $first, string $second, string ...$arguments)
 * @method int    countVowels(string $text)
 * @method string decapitalize(string $text, bool $upperRest = false, string $encoding = 'UTF-8')
 * @method string decrement(string $text, string $separator = '_')
 * @method string dirFromFile(string $file)
 * @method string dirSeparator(string $directory)
 * @method bool   endsWith(string $haystack, string $needle, bool $ignoreCase = true)
 * @method string firstBetween(string $text, string $start, string $end)
 * @method string friendly(string $text, string $separator = '-', bool $lowercase = true, $replace = null)
 * @method string humanize(string $text)
 * @method bool   includes(string $haystack, string $needle)
 * @method string increment(string $text, string $separator = '_')
 * @method bool   isAnagram(string $first, string $second)
 * @method bool   isLower(string $text, string $encoding = 'UTF-8')
 * @method bool   isPalindrome(string $text)
 * @method bool   isUpper(string $text, string $encoding = 'UTF-8')
 * @method string kebabCase(string $text, string $delimiters = null)
 * @method int    len(string $text, string $encoding = 'UTF-8')
 * @method string lower(string $text, string $encoding = 'UTF-8')
 * @method string pascalCase(string $text, string $delimiters = null)
 * @method string prefix($text, string $prefix)
 * @method string random(int $type = 0, int $length = 8)
 * @method string reduceSlashes(string $text)
 * @method bool   startsWith(string $haystack, string $needle, bool $ignoreCase = true)
 * @method string snakeCase(string $text, string $delimiters = null)
 * @method string suffix($text, string $suffix)
 * @method string ucwords(string $text, string $encoding = 'UTF-8')
 * @method string uncamelize(string $text, string $delimiters = '_')
 * @method string underscore(string $text)
 * @method string upper(string $text, string $encoding = 'UTF-8')
 */
class HelperFactory extends AbstractFactory
{
    /**
     * FactoryTrait constructor.
     *
     * @param array $services
     */
    public function __construct(array! services = [])
    {
        this->init(services);
    }

    /**
     * @param string $name
     * @param array  $arguments
     *
     * @return mixed
     * @throws Exception
     */
    public function __call(string name, array arguments)
    {
        var helper;

        let helper = this->newInstance(name);

        return call_user_func_array([helper, "__invoke"], arguments);
    }

    /**
     * @param string $name
     *
     * @return mixed
     * @throws Exception
     */
    public function newInstance(string name)
    {
        return create_instance(this->getService(name));
    }

    /**
     * @return string
     */
    protected function getExceptionClass() -> string
    {
        return "Phalcon\\Support\\Exception";
    }

    /**
     * Returns the available adapters
     *
     * @return string[]
     */
    protected function getServices() -> array
    {
        return [
            "blacklist"     : "Phalcon\\Support\\Helper\\Arr\\Blacklist",
            "chunk"         : "Phalcon\\Support\\Helper\\Arr\\Chunk",
            "filter"        : "Phalcon\\Support\\Helper\\Arr\\Filter",
            "first"         : "Phalcon\\Support\\Helper\\Arr\\First",
            "firstKey"      : "Phalcon\\Support\\Helper\\Arr\\FirstKey",
            "flatten"       : "Phalcon\\Support\\Helper\\Arr\\Flatten",
            "get"           : "Phalcon\\Support\\Helper\\Arr\\Get",
            "group"         : "Phalcon\\Support\\Helper\\Arr\\Group",
            "has"           : "Phalcon\\Support\\Helper\\Arr\\Has",
            "isUnique"      : "Phalcon\\Support\\Helper\\Arr\\IsUnique",
            "last"          : "Phalcon\\Support\\Helper\\Arr\\Last",
            "lastKey"       : "Phalcon\\Support\\Helper\\Arr\\LastKey",
            "order"         : "Phalcon\\Support\\Helper\\Arr\\Order",
            "pluck"         : "Phalcon\\Support\\Helper\\Arr\\Pluck",
            "set"           : "Phalcon\\Support\\Helper\\Arr\\Set",
            "sliceLeft"     : "Phalcon\\Support\\Helper\\Arr\\SliceLeft",
            "sliceRight"    : "Phalcon\\Support\\Helper\\Arr\\SliceRight",
            "split"         : "Phalcon\\Support\\Helper\\Arr\\Split",
            "toObject"      : "Phalcon\\Support\\Helper\\Arr\\ToObject",
            "validateAll"   : "Phalcon\\Support\\Helper\\Arr\\ValidateAll",
            "validateAny"   : "Phalcon\\Support\\Helper\\Arr\\ValidateAny",
            "whitelist"     : "Phalcon\\Support\\Helper\\Arr\\Whitelist",
            "basename"      : "Phalcon\\Support\\Helper\\File\\Basename",
            "decode"        : "Phalcon\\Support\\Helper\\Json\\Decode",
            "encode"        : "Phalcon\\Support\\Helper\\Json\\Encode",
            "isBetween"     : "Phalcon\\Support\\Helper\\Number\\IsBetween",
            "camelize"      : "Phalcon\\Support\\Helper\\Str\\Camelize",
            "concat"        : "Phalcon\\Support\\Helper\\Str\\Concat",
            "countVowels"   : "Phalcon\\Support\\Helper\\Str\\CountVowels",
            "decapitalize"  : "Phalcon\\Support\\Helper\\Str\\Decapitalize",
            "decrement"     : "Phalcon\\Support\\Helper\\Str\\Decrement",
            "dirFromFile"   : "Phalcon\\Support\\Helper\\Str\\DirFromFile",
            "dirSeparator"  : "Phalcon\\Support\\Helper\\Str\\DirSeparator",
            "dynamic"       : "Phalcon\\Support\\Helper\\Str\\Dynamic",
            "endsWith"      : "Phalcon\\Support\\Helper\\Str\\EndsWith",
            "firstBetween"  : "Phalcon\\Support\\Helper\\Str\\FirstBetween",
            "friendly"      : "Phalcon\\Support\\Helper\\Str\\Friendly",
            "humanize"      : "Phalcon\\Support\\Helper\\Str\\Humanize",
            "includes"      : "Phalcon\\Support\\Helper\\Str\\Includes",
            "increment"     : "Phalcon\\Support\\Helper\\Str\\Increment",
            "interpolate"   : "Phalcon\\Support\\Helper\\Str\\Interpolate",
            "isAnagram"     : "Phalcon\\Support\\Helper\\Str\\IsAnagram",
            "isLower"       : "Phalcon\\Support\\Helper\\Str\\IsLower",
            "isPalindrome"  : "Phalcon\\Support\\Helper\\Str\\IsPalindrome",
            "isUpper"       : "Phalcon\\Support\\Helper\\Str\\IsUpper",
            "kebabCase"     : "Phalcon\\Support\\Helper\\Str\\KebabCase",
            "len"           : "Phalcon\\Support\\Helper\\Str\\Len",
            "lower"         : "Phalcon\\Support\\Helper\\Str\\Lower",
            "pascalCase"    : "Phalcon\\Support\\Helper\\Str\\PascalCase",
            "prefix"        : "Phalcon\\Support\\Helper\\Str\\Prefix",
            "random"        : "Phalcon\\Support\\Helper\\Str\\Random",
            "reduceSlashes" : "Phalcon\\Support\\Helper\\Str\\ReduceSlashes",
            "snakeCase"     : "Phalcon\\Support\\Helper\\Str\\SnakeCase",
            "startsWith"    : "Phalcon\\Support\\Helper\\Str\\StartsWith",
            "suffix"        : "Phalcon\\Support\\Helper\\Str\\Suffix",
            "ucwords"       : "Phalcon\\Support\\Helper\\Str\\Ucwords",
            "uncamelize"    : "Phalcon\\Support\\Helper\\Str\\Uncamelize",
            "underscore"    : "Phalcon\\Support\\Helper\\Str\\Underscore",
            "upper"         : "Phalcon\\Support\\Helper\\Str\\Upper"
        ];
    }
}
