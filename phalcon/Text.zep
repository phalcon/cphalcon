
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon;

use Phalcon\Helper\Str;

/**
 * Phalcon\Text
 *
 * Provides utilities to work with texts
 */
abstract class Text
{
    const RANDOM_ALNUM    = 0;
    const RANDOM_ALPHA    = 1;
    const RANDOM_DISTINCT = 5;
    const RANDOM_HEXDEC   = 2;
    const RANDOM_NOZERO   = 4;
    const RANDOM_NUMERIC  = 3;

    /**
     * Converts strings to camelize style
     *
     * <code>
     * echo Phalcon\Text::camelize("coco_bongo"); // CocoBongo
     * echo Phalcon\Text::camelize("co_co-bon_go", "-"); // Co_coBon_go
     * echo Phalcon\Text::camelize("co_co-bon_go", "_-"); // CoCoBonGo
     * </code>
     */
    public static function camelize(string! text, var delimiter = null) -> string
    {
        return Str::camelize(text, delimiter);
    }

    /**
     * Concatenates strings using the separator only once without duplication in
     * places concatenation
     *
     * <code>
     * $str = Phalcon\Text::concat(
     *     "/",
     *     "/tmp/",
     *     "/folder_1/",
     *     "/folder_2",
     *     "folder_3/"
     * );
     *
     * // /tmp/folder_1/folder_2/folder_3/
     * echo $str;
     * </code>
     *
     * @param string separator
     * @param string a
     * @param string b
     * @param string ...N
     */
    //public static function concat(string! separator, string! a, string! b) -> string
    public static function concat() -> string
    {
        var args;

        let args = func_get_args();

        return call_user_func_array("\\Phalcon\\Helper\\Str::concat", args);
    }

    /**
     * Generates random text in accordance with the template
     *
     * <code>
     * // Hi my name is a Bob
     * echo Phalcon\Text::dynamic("{Hi|Hello}, my name is a {Bob|Mark|Jon}!");
     *
     * // Hi my name is a Jon
     * echo Phalcon\Text::dynamic("{Hi|Hello}, my name is a {Bob|Mark|Jon}!");
     *
     * // Hello my name is a Bob
     * echo Phalcon\Text::dynamic("{Hi|Hello}, my name is a {Bob|Mark|Jon}!");
     *
     * // Hello my name is a Zyxep
     * echo Phalcon\Text::dynamic(
     *     "[Hi/Hello], my name is a [Zyxep/Mark]!",
     *     "[", "]",
     *     "/"
     * );
     * </code>
     */
    public static function dynamic(
        string! text,
        string! leftDelimiter = "{",
        string! rightDelimiter = "}",
        string! separator = "|"
    ) -> string
    {
        return Str::dynamic(text, leftDelimiter, rightDelimiter, separator);
    }

    /**
     * Check if a string ends with a given string
     *
     * <code>
     * echo Phalcon\Text::endsWith("Hello", "llo"); // true
     * echo Phalcon\Text::endsWith("Hello", "LLO", false); // false
     * echo Phalcon\Text::endsWith("Hello", "LLO"); // true
     * </code>
     */
    public static function endsWith(string text, string end, bool ignoreCase = true) -> bool
    {
        return Str::endsWith(text, end, ignoreCase);
    }

    /**
     * Makes an underscored or dashed phrase human-readable
     *
     * <code>
     * echo Phalcon\Text::humanize("start-a-horse"); // "start a horse"
     * echo Phalcon\Text::humanize("five_cats"); // "five cats"
     * </code>
     */
    public static function humanize(string! text) -> string
    {
        return Str::humanize(text);
    }

    /**
     * Adds a number to a string or increment that number if it already is
     * defined
     *
     * <code>
     * echo Phalcon\Text::increment("a"); // "a_1"
     * echo Phalcon\Text::increment("a_1"); // "a_2"
     * </code>
     */
    public static function increment(string text, string separator = "_") -> string
    {
        return Str::increment(text, separator);
    }

    /**
     * Lowercases a string, this function makes use of the mbstring extension if
     * available
     *
     * <code>
     * echo Phalcon\Text::lower("HELLO"); // hello
     * </code>
     */
    public static function lower(string! text, string! encoding = "UTF-8") -> string
    {
        return Str::lower(text, encoding);
    }

    /**
     * Check if a string starts with a given string
     *
     * <code>
     * echo Phalcon\Text::startsWith("Hello", "He"); // true
     * echo Phalcon\Text::startsWith("Hello", "he", false); // false
     * echo Phalcon\Text::startsWith("Hello", "he"); // true
     * </code>
     */
    public static function startsWith(string text, string start, bool ignoreCase = true) -> bool
    {
        return Str::startsWith(text, start, ignoreCase);
    }

    /**
     * Generates a random string based on the given type. Type is one of the
     * RANDOM_* constants
     *
     * <code>
     * use Phalcon\Text;
     *
     * // "aloiwkqz"
     * echo Text::random(Text::RANDOM_ALNUM);
     * </code>
     */
    public static function random(int type = 0, long length = 8) -> string
    {
        return Str::random(type, length);
    }

    /**
     * Reduces multiple slashes in a string to single slashes
     *
     * <code>
     * // foo/bar/baz
     * echo Phalcon\Text::reduceSlashes("foo//bar/baz");
     *
     * // http://foo.bar/baz/buz
     * echo Phalcon\Text::reduceSlashes("http://foo.bar///baz/buz");
     * </code>
     */
    public static function reduceSlashes(string! text) -> string
    {
        return Str::reduceSlashes(text);
    }

    /**
     * Uncamelize strings which are camelized
     *
     * <code>
     * echo Phalcon\Text::uncamelize("CocoBongo"); // coco_bongo
     * echo Phalcon\Text::uncamelize("CocoBongo", "-"); // coco-bongo
     * </code>
     */
    public static function uncamelize(string! text, var delimiter = null) -> string
    {
        return Str::uncamelize(text, delimiter);
    }

    /**
     * Makes a phrase underscored instead of spaced
     *
     * <code>
     * echo Phalcon\Text::underscore("look behind"); // "look_behind"
     * echo Phalcon\Text::underscore("Awesome Phalcon"); // "Awesome_Phalcon"
     * </code>
     */
    public static function underscore(string! text) -> string
    {
        return Str::underscore(text);
    }

    /**
     * Uppercases a string, this function makes use of the mbstring extension if
     * available
     *
     * <code>
     * echo Phalcon\Text::upper("hello"); // HELLO
     * </code>
     */
    public static function upper(string! text, string! encoding = "UTF-8") -> string
    {
        return Str::upper(text, encoding);
    }
}
