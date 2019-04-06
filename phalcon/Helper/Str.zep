
/**
 * This file is part of the Phalcon.
 *
 * (c) Phalcon Team <team@phalcon.com>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */

namespace Phalcon\Helper;

use Phalcon\Helper\Arr;
use Phalcon\Helper\Exception;

/**
 * Phalcon\Helper\Str
 *
 * This class offers quick string functions throught the framework
 */
class Str
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
    final public static function camelize(string! text, var delimiter = null) -> string
    {
        return text->camelize(delimiter);
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
    //final public static function concat(string! separator, string! a, string! b) -> string
    final public static function concat() -> string
    {
        var argument, arguments, data, first, last, prefix, separator, suffix;

        let arguments = func_get_args();

        if count(arguments) < 3 {
            throw new Exception("concat needs at least three parameters");
        }

        let separator = Arr::first(arguments),
            arguments = Arr::tail(arguments),
            first     = Arr::first(arguments),
            last      = Arr::last(arguments),
            prefix    = "",
            suffix    = "",
            data      = [];

        if self::startsWith(first, separator) {
            let prefix = separator;
        }

        if self::endsWith(last, separator) {
            let suffix = separator;
        }


        for argument in arguments {
            let data[] = rtrim(ltrim(argument, separator), separator);
        }

        return prefix . implode(separator, data) . suffix;
    }

    /**
     * Retuns number of vowels in provided string. Uses a regular expression
     * to count the number of vowels (A, E, I, O, U) in a string.
     *
     * @param string $string
     *
     * @return int
     */
    final public static function countVowels(string! text) -> int
    {
        var matches;

        preg_match_all("/[aeiou]/i", text, matches);

        return count(matches[0]);
    }

    /**
     * Decapitalizes the first letter of the sring and then adds it with rest
     * of the string. Omit the upperRest parameter to keep the rest of the
     * string intact, or set it to true to convert to uppercase.
     *
     * @param string $string
     * @param bool   $upperRest
     *
     * @return string
     */
    final public static function decapitalize(string! text, bool upperRest = false, string! encoding = "UTF-8") -> string
    {
        var substr, suffix;

        if function_exists("mb_substr") {
            let substr = mb_substr(text, 1);
        } else {
            let substr = substr(text, 1);
        }

        if upperRest {
            if function_exists("mb_strtoupper") {
                let suffix = mb_strtoupper(substr, encoding);
            } else {
                let suffix = substr->upper();
            }
        } else {
            let suffix = substr;
        }

        if function_exists("mb_strtolower") {
            return mb_strtolower(mb_substr(text, 0, 1), encoding) . suffix;
        } else {
            return strtolower(substr(text, 0, 1)) . suffix;
        }
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
    final public static function dynamic(
        string! text,
        string! leftDelimiter = "{",
        string! rightDelimiter = "}",
        string! separator = "|"
    ) -> string
    {
        var ldS, rdS, pattern, matches, match, words, word, sub;

        if substr_count(text, leftDelimiter) !== substr_count(text, rightDelimiter) {
            throw new \RuntimeException(
                "Syntax error in string \"" . text . "\""
            );
        }

        let ldS = preg_quote(leftDelimiter),
            rdS = preg_quote(rightDelimiter),
            pattern = "/" . ldS . "([^" . ldS . rdS . "]+)" . rdS . "/",
            matches = [];

        if !preg_match_all(pattern, text, matches, 2) {
            return text;
        }

        if typeof matches == "array" {
            for match in matches {
                if !isset match[0] || !isset match[1] {
                    continue;
                }

                let words = explode(separator, match[1]),
                    word = words[array_rand(words)],
                    sub = preg_quote(match[0], separator),
                    text = preg_replace("/" . sub . "/", word, text, 1);
            }
        }

        return text;
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
    final public static function endsWith(string str, string end, bool ignoreCase = true) -> bool
    {
        return ends_with(str, end, ignoreCase);
    }

    /**
     * Returns the first string there is between the strings from the
     * parameter start and end.
     *
     * @param string $haystack
     * @param string $start
     * @param string $end
     *
     * @return string
     */
    final public static function firstStringBetween(
        string! haystack,
        string! start,
        string! end
    ) -> string
    {
        if function_exists("mb_strstr") {
            return trim(mb_strstr(mb_strstr(haystack, start), end, true), start . end);
        } else {
            return trim(strstr(strstr(haystack, start), end, true), start . end);
        }
    }

    /**
     * Makes an underscored or dashed phrase human-readable
     *
     * <code>
     * echo Phalcon\Text::humanize("start-a-horse"); // "start a horse"
     * echo Phalcon\Text::humanize("five_cats"); // "five cats"
     * </code>
     */
    final public static function humanize(string! text) -> string
    {
        return preg_replace("#[_-]+#", " ", trim(text));
    }

    /**
     * Lets you determine whether or not a string includes another string.
     *
     * @param string $needle
     * @param string $haystack
     *
     * @return bool
     */
    final public static function includes(string! needle, string! haystack) -> bool
    {
        if function_exists("mb_strpos") {
            return (bool) mb_strpos(haystack, needle);
        } else {
            return (bool) strpos(haystack, needle);
        }
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
    final public static function increment(string str, string separator = "_") -> string
    {
        var parts, number;

        let parts = explode(separator, str);

        if fetch number, parts[1] {
            let number++;
        } else {
            let number = 1;
        }

        return parts[0] . separator. number;
    }

    /**
     * Compare two strings and returns true if both strings are anagram,
     * false otherwise.
     *
     * @param string $first
     * @param string $second
     *
     * @return bool
     */
    final public static function isAnagram(string! first, string! second) -> bool
    {
        return count_chars(first, 1) === count_chars(second, 1);
    }

    /**
     * Returns true if the given string is lower case, false otherwise.
     *
     * @param string text
     *
     * @return bool
     */
    final public static function isLower(string! text, string! encoding = "UTF-8") ->  bool
    {
        if function_exists("mb_strtolower") {
            return text === mb_strtolower(text, encoding);
        } else {
            return text === text->lower();
        }
    }

    /**
     * Returns true if the given string is a palindrome, false otherwise.
     *
     * @param string $text
     *
     * @return bool
     */
    final public static function isPalindrome(string! text) -> bool
    {
        return strrev(text) === text;
    }

    /**
     * Returns true if the given string is upper case, false otherwise.
     *
     * @param string text
     *
     * @return bool
     */
    final public static function isUpper(string! text, string! encoding = "UTF-8") -> bool
    {
        if function_exists("mb_strtoupper") {
            return text === mb_strtoupper(text, encoding);
        } else {
            return text === text->upper();
        }
    }

    /**
     * Lowercases a string, this function makes use of the mbstring extension if
     * available
     *
     * <code>
     * echo Phalcon\Text::lower("HELLO"); // hello
     * </code>
     */
    final public static function lower(string! str, string! encoding = "UTF-8") -> string
    {
        /**
         * 'lower' checks for the mbstring extension to make a correct lowercase
         * transformation
         */
        if function_exists("mb_strtolower") {
            return mb_strtolower(str, encoding);
        }

        return str->lower();
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
    final public static function random(int type = 0, long length = 8) -> string
    {
        var pool, str = "";
        int end;

        switch type {

            case Str::RANDOM_ALPHA:
                let pool = array_merge(range("a", "z"), range("A", "Z"));
                break;

            case Str::RANDOM_HEXDEC:
                let pool = array_merge(range(0, 9), range("a", "f"));
                break;

            case Str::RANDOM_NUMERIC:
                let pool = range(0, 9);
                break;

            case Str::RANDOM_NOZERO:
                let pool = range(1, 9);
                break;

            case Str::RANDOM_DISTINCT:
                let pool = str_split("2345679ACDEFHJKLMNPRSTUVWXYZ");
                break;

            default:
                // Default type \Phalcon\Text::RANDOM_ALNUM
                let pool = array_merge(
                    range(0, 9),
                    range("a", "z"),
                    range("A", "Z")
                );

                break;
        }

        let end = count(pool) - 1;

        while strlen(str) < length {
            let str .= pool[mt_rand(0, end)];
        }

        return str;
    }

    /**
     * Reduces multiple slashes in a string to single slashes
     *
     * <code>
     * echo Phalcon\Text::reduceSlashes("foo//bar/baz"); // foo/bar/baz
     * echo Phalcon\Text::reduceSlashes("http://foo.bar///baz/buz"); // http://foo.bar/baz/buz
     * </code>
     */
    final public static function reduceSlashes(string! text) -> string
    {
        return preg_replace("#(?<!:)//+#", "/", text);
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
    final public static function startsWith(string! text, string! start, bool ignoreCase = true) -> bool
    {
        return starts_with(text, start, ignoreCase);
    }

    /**
     * Uncamelize strings which are camelized
     *
     * <code>
     * echo Phalcon\Text::uncamelize("CocoBongo"); // coco_bongo
     * echo Phalcon\Text::uncamelize("CocoBongo", "-"); // coco-bongo
     * </code>
     */
    final public static function uncamelize(string! text, var delimiter = null) -> string
    {
        return text->uncamelize(delimiter);
    }

    /**
     * Makes a phrase underscored instead of spaced
     *
     * <code>
     * echo Phalcon\Text::underscore("look behind"); // "look_behind"
     * echo Phalcon\Text::underscore("Awesome Phalcon"); // "Awesome_Phalcon"
     * </code>
     */
    final public static function underscore(string! text) -> string
    {
        return preg_replace("#\s+#", "_", trim(text));
    }

    /**
     * Uppercases a string, this function makes use of the mbstring extension if
     * available
     *
     * <code>
     * echo Phalcon\Text::upper("hello"); // HELLO
     * </code>
     */
    final public static function upper(string! text, string! encoding = "UTF-8") -> string
    {
        /**
         * 'upper' checks for the mbstring extension to make a correct lowercase
         * transformation
         */
        if function_exists("mb_strtoupper") {
            return mb_strtoupper(text, encoding);
        }

        return text->upper();
    }
}
