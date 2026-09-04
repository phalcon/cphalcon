
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Traits\Php;

/**
 * File based wrapper methods
 */
trait FileTrait
{
    /**
     * Closes an open file pointer
     *
     * @link https://php.net/manual/en/function.fclose.php
     *
     * @param resource $handle
     *
     * @return bool
     */
    protected static function phpFclose(var handle) -> bool
    {
        return fclose(handle);
    }

    /**
     * Gets line from file pointer and parse for CSV fields
     *
     * @param resource $stream
     * @param int      $length
     * @param string   $separator
     * @param string   $enclosure
     * @param string   $escape
     *
     * @return array<array-key, mixed>|false
     *
     * @link https://php.net/manual/en/function.fgetcsv.php
     */
    protected static function phpFgetCsv(
        var stream,
        int length = 0,
        string separator = ",",
        var enclosure = null,
        var escape = null
    ) -> array | false {
        if null === enclosure {
            let enclosure = "\"";
        }

        if null === escape {
            let escape = "\\";
        }

        return fgetcsv(stream, length, separator, enclosure, escape);
    }

    /**
     * @param string $filename
     *
     * @return bool
     *
     * @link https://php.net/manual/en/function.file-exists.php
     */
    protected static function phpFileExists(string filename) -> bool
    {
        return file_exists(filename);
    }

    /**
     * @param string        $filename
     * @param bool          $useIncludePath
     * @param resource|null $context
     * @param int           $offset
     * @param int|null      $length
     *
     * @return false|string
     *
     * @link https://php.net/manual/en/function.file-get-contents.php
     */
    protected static function phpFileGetContents(
        string filename,
        bool useIncludePath = false,
        var context = null,
        int offset = 0,
        int length = null
    ) -> false | string {
        if null === length {
            return file_get_contents(filename, useIncludePath, context, offset);
        }

        return file_get_contents(filename, useIncludePath, context, offset, length);
    }

    /**
     * @param string   $filename
     * @param mixed    $data
     * @param int      $flags
     * @param resource $context
     *
     * @return false|int
     *
     * @link https://php.net/manual/en/function.file-put-contents.php
     */
    protected static function phpFilePutContents(
        string filename,
        var data,
        int flags = 0,
        var context = null
    ) -> false | int {
        return file_put_contents(filename, data, flags, context);
    }

    /**
     * @param string        $filename
     * @param string        $mode
     * @param bool          $useIncludePath
     * @param resource|null $context
     *
     * @return resource|false
     *
     * @link https://php.net/manual/en/function.fopen.php
     */
    protected static function phpFopen(
        string filename,
        string mode,
        bool useIncludePath = false,
        var context = null
    ) -> var {
        return fopen(filename, mode, useIncludePath, context);
    }

    /**
     * Binary-safe file write
     *
     * @link https://php.net/manual/en/function.fwrite.php
     *
     * @param resource $handle
     * @param string   $data
     * @param int|null $length
     *
     * @return false|int
     */
    protected static function phpFwrite(var handle, string data, int length = null) -> false | int
    {
        if null === length {
            return fwrite(handle, data);
        }

        return fwrite(handle, data, length);
    }

    /**
     * Tells whether the filename is a directory
     *
     * @param string $filename
     *
     * @return bool
     *
     * @link https://php.net/manual/en/function.is-dir.php
     */
    protected static function phpIsDir(string filename) -> bool
    {
        return is_dir(filename);
    }

    /**
     * Tells whether the filename is writable
     *
     * @param string $filename
     *
     * @return bool
     *
     * @link https://php.net/manual/en/function.is-writable.php
     */
    protected static function phpIsWritable(string filename) -> bool
    {
        return is_writable(filename);
    }

    /**
     * Makes a directory
     *
     * @param string        $directory
     * @param int           $permissions
     * @param bool          $recursive
     * @param resource|null $context
     *
     * @return bool
     *
     * @link https://php.net/manual/en/function.mkdir.php
     */
    protected static function phpMkdir(
        string directory,
        int permissions = 0777,
        bool recursive = false,
        var context = null
    ) -> bool {
        return mkdir(directory, permissions, recursive, context);
    }

    /**
     * @param string        $filename
     * @param resource|null $context
     *
     * @return bool
     *
     * @link https://php.net/manual/en/function.unlink.php
     */
    protected static function phpUnlink(string filename, var context = null) -> bool
    {
        return unlink(filename, context);
    }
}
