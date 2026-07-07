
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
    protected function phpFclose(var handle) -> bool
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
    protected function phpFgetCsv(
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
    protected function phpFileExists(string filename) -> bool
    {
        return file_exists(filename);
    }

    /**
     * @param string $filename
     *
     * @return false|string
     *
     * @link https://php.net/manual/en/function.file-get-contents.php
     */
    protected function phpFileGetContents(string filename) -> false | string
    {
        return file_get_contents(filename);
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
    protected function phpFilePutContents(
        string filename,
        var data,
        int flags = 0,
        var context = null
    ) -> false | int {
        return file_put_contents(filename, data, flags, context);
    }

    /**
     * @param string $filename
     * @param string $mode
     *
     * @return resource|false
     *
     * @link https://php.net/manual/en/function.fopen.php
     */
    protected function phpFopen(string filename, string mode) -> mixed
    {
        return fopen(filename, mode);
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
    protected function phpFwrite(var handle, string data, int length = null) -> false | int
    {
        if null === length {
            return fwrite(handle, data);
        }

        return fwrite(handle, data, length);
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
    protected function phpIsWritable(string filename) -> bool
    {
        return is_writable(filename);
    }

    /**
     * @param string $filename
     *
     * @return bool
     *
     * @link https://php.net/manual/en/function.unlink.php
     */
    protected function phpUnlink(string filename) -> bool
    {
        return unlink(filename);
    }
}
