<?php
declare(strict_types=1);

/**
 * This file is part of the Cardoe Framework.
 *
 * For the full copyright and license information, please view the LICENSE.md
 * file that was distributed with this source code.
 */

namespace Cardoe\Helper;

use function array_merge;
use function count;
use function count_chars;
use function explode;
use function implode;
use function ltrim;
use function mb_strtolower;
use function mb_strtoupper;
use function mb_substr;
use function mt_rand;
use function pathinfo;
use function preg_match_all;
use function preg_replace;
use function range;
use function rtrim;
use function str_split;
use function strlen;
use function strrev;
use function substr;
use function substr_compare;
use function trim;
use const DIRECTORY_SEPARATOR;
use const PATHINFO_FILENAME;

/**
 * Cardoe\Helper\Str
 *
 * This class offers quick string functions throughout the framework
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
     * Concatenates strings using the separator only once without duplication in
     * places concatenation
     *
     * @param string $separator
     * @param mixed  ...$arguments
     *
     * @return string
     * @throws Exception
     */
    final public static function concat(string $separator, ...$arguments): string
    {
        if (count($arguments) < 2) {
            throw new Exception('concat needs at least three parameters');
        }

        $first  = Arr::first($arguments);
        $last   = Arr::last($arguments);
        $prefix = '';
        $suffix = '';
        $data   = [];

        if (true === self::startsWith($first, $separator)) {
            $prefix = $separator;
        }

        if (true === self::endsWith($last, $separator)) {
            $suffix = $separator;
        }


        foreach ($arguments as $argument) {
            $data[] = rtrim(ltrim($argument, $separator), $separator);
        }

        return $prefix . implode($separator, $data) . $suffix;
    }

    /**
     * Check if a string starts with a given string
     *
     * @param string $haystack
     * @param string $needle
     * @param bool   $ignoreCase
     *
     * @return bool
     */
    final public static function startsWith(
        string $haystack,
        string $needle,
        bool $ignoreCase = true
    ): bool {
        if ('' === $haystack) {
            return false;
        }

        return substr_compare(
            $haystack,
            $needle,
            0,
            strlen($needle),
            $ignoreCase
        ) === 0;
    }

    /**
     * Check if a string ends with a given string
     *
     * @param string $haystack
     * @param string $needle
     * @param bool   $ignoreCase
     *
     * @return bool
     */
    final public static function endsWith(
        string $haystack,
        string $needle,
        bool $ignoreCase = true
    ): bool {
        if ('' === $haystack) {
            return false;
        }

        return substr_compare(
            $haystack,
            $needle,
            -strlen($needle),
            strlen($needle),
            $ignoreCase
        ) === 0;
    }

    /**
     * Returns number of vowels in provided string. Uses a regular expression
     * to count the number of vowels (A, E, I, O, U) in a string.
     *
     * @param string $text
     *
     * @return int
     */
    final public static function countVowels(string $text): int
    {
        preg_match_all('/[aeiou]/i', $text, $matches);

        return count($matches[0]);
    }

    /**
     * Decapitalizes the first letter of the string and then adds it with rest
     * of the string. Omit the upperRest parameter to keep the rest of the
     * string intact, or set it to true to convert to uppercase.
     *
     * @param string $text
     * @param bool   $upperRest
     * @param string $encoding
     *
     * @return string
     */
    final public static function decapitalize(
        string $text,
        bool $upperRest = false,
        string $encoding = 'UTF-8'
    ): string {
        $substr = mb_substr($text, 1);

        if (true === $upperRest) {
            $suffix = mb_strtoupper($substr, $encoding);
        } else {
            $suffix = $substr;
        }

        return mb_strtolower(mb_substr($text, 0, 1), $encoding) . $suffix;
    }

    /**
     * Accepts a file name (without extension) and returns a calculated
     * directory structure with the filename in the end
     *
     * @param string $file
     *
     * @return string
     */
    final public static function dirFromFile(string $file): string
    {
        $name  = pathinfo($file, PATHINFO_FILENAME);
        $start = substr($name, 0, -2);

        if (!$start) {
            $start = substr($name, 0, 1);
        }

        return implode('/', str_split($start, 2)) . '/';
    }

    /**
     * Accepts a directory name and ensures that it ends with
     * DIRECTORY_SEPARATOR
     *
     * @param string $directory
     *
     * @return string
     */
    final public static function dirSeparator(string $directory): string
    {
        return rtrim($directory, DIRECTORY_SEPARATOR) . DIRECTORY_SEPARATOR;
    }

    /**
     * Returns the first string there is between the strings from the
     * parameter start and end.
     *
     * @param string $text
     * @param string $start
     * @param string $end
     *
     * @return string
     */
    final public static function firstBetween(
        string $text,
        string $start,
        string $end
    ): string {
        return trim(
            mb_strstr(
                mb_strstr($text, $start),
                $end,
                true
            ),
            $start . $end
        );
    }

    /**
     * Makes an underscored or dashed phrase human-readable
     *
     * @param string $text
     *
     * @return string
     */
    final public static function humanize(string $text): string
    {
        return preg_replace('#[_-]+#', ' ', trim($text));
    }

    /**
     * Lets you determine whether or not a string includes another string.
     *
     * @param string $haystack
     * @param string $needle
     *
     * @return bool
     */
    final public static function includes(string $haystack, string $needle): bool
    {
        return (bool) mb_strpos($haystack, $needle);
    }

    /**
     * Adds a number to a string or increment that number if it already is
     * defined
     *
     * @param string $text
     * @param string $separator
     *
     * @return string
     */
    final public static function increment(string $text, string $separator = '_'): string
    {
        $parts  = explode($separator, $text);
        $number = 1;

        if (true === isset($parts[1])) {
            $number = ((int) $parts[1]) + 1;
        }

        return $parts[0] . $separator . $number;
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
    final public static function isAnagram(string $first, string $second): bool
    {
        return count_chars($first, 1) === count_chars($second, 1);
    }

    /**
     * Returns true if the given string is lower case, false otherwise.
     *
     * @param string $text
     * @param string $encoding
     *
     * @return bool
     */
    final public static function isLower(string $text, string $encoding = 'UTF-8'): bool
    {
        return $text === mb_strtolower($text, $encoding);
    }

    /**
     * Returns true if the given string is a palindrome, false otherwise.
     *
     * @param string $text
     *
     * @return bool
     */
    final public static function isPalindrome(string $text): bool
    {
        return strrev($text) === $text;
    }

    /**
     * Returns true if the given string is upper case, false otherwise.
     *
     * @param string $text
     * @param string $encoding
     *
     * @return bool
     */
    final public static function isUpper(string $text, string $encoding = 'UTF-8'): bool
    {
        return $text === mb_strtoupper($text, $encoding);
    }

    /**
     * Lowercases a string, this function makes use of the mbstring extension if
     * available
     *
     * @param string $text
     * @param string $encoding
     *
     * @return string
     */
    final public static function lower(string $text, string $encoding = 'UTF-8'): string
    {
        return mb_strtolower($text, $encoding);
    }

    /**
     * Generates a random string based on the given type. Type is one of the
     * RANDOM_* constants
     *
     * @param int $type
     * @param int $length
     *
     * @return string
     */
    final public static function random(
        int $type = self::RANDOM_ALNUM,
        int $length = 8
    ): string {
        $text  = '';
        $type  = ($type < 0 || $type > 5) ? self::RANDOM_ALNUM : $type;
        $pools = [
            self::RANDOM_ALPHA    => array_merge(
                range('a', 'z'),
                range('A', 'Z')
            ),
            self::RANDOM_HEXDEC   => array_merge(
                range(0, 9),
                range('a', 'f')
            ),
            self::RANDOM_NUMERIC  => range(0, 9),
            self::RANDOM_NOZERO   => range(1, 9),
            self::RANDOM_DISTINCT => str_split('2345679ACDEFHJKLMNPRSTUVWXYZ'),
            self::RANDOM_ALNUM    => array_merge(
                range(0, 9),
                range('a', 'z'),
                range('A', 'Z')
            ),
        ];

        $end = count($pools[$type]) - 1;

        while (strlen($text) < $length) {
            $text .= $pools[$type][mt_rand(0, $end)];
        }

        return $text;
    }

    /**
     * Reduces multiple slashes in a string to single slashes
     *
     * @param string $text
     *
     * @return string
     */
    final public static function reduceSlashes(string $text): string
    {
        return preg_replace('#(?<!:)//+#', '/', $text);
    }

    /**
     * Makes a phrase underscored instead of spaced
     *
     * @param string $text
     *
     * @return string
     */
    final public static function underscore(string $text): string
    {
        return preg_replace('#\s+#', '_', trim($text));
    }

    /**
     * Uppercases a string, this function makes use of the mbstring extension if
     * available
     *
     * @param string $text
     * @param string $encoding
     *
     * @return string
     */
    final public static function upper(string $text, string $encoding = 'UTF-8'): string
    {
        return mb_strtoupper($text, $encoding);
    }
}
