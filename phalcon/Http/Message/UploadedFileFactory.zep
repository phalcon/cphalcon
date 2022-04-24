
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 *
 * Implementation of this file has been influenced by Zend Diactoros
 * @link    https://github.com/zendframework/zend-diactoros
 * @license https://github.com/zendframework/zend-diactoros/blob/master/LICENSE.md
 */

namespace Phalcon\Http\Message;

use Psr\Http\Message\StreamInterface;
use Psr\Http\Message\UploadedFileInterface;
use Psr\Http\Message\UploadedFileFactoryInterface;

/**
 * PSR-17 UploadedFileFactory
 */
final class UploadedFileFactory implements UploadedFileFactoryInterface
{
    /**
     * Create a new uploaded file.
     *
     * If a size is not provided it will be determined by checking the size of
     * the stream.
     *
     * @link http://php.net/manual/features.file-upload.post-method.php
     * @link http://php.net/manual/features.file-upload.errors.php
     *
     * @param StreamInterface $stream          The underlying stream representing the
     *                                         uploaded file content.
     * @param int             $size            The size of the file in bytes.
     * @param int             $error           The PHP file upload error.
     * @param string          $clientFilename  The filename as provided by the client, if any.
     * @param string          $clientMediaType The media type as provided by the client, if any.
     *
     * @throws \InvalidArgumentException If the file resource is not readable.
     */
    public function createUploadedFile(
        <StreamInterface> stream,
        int size = null,
        int error = 0,
        string clientFilename = null,
        string clientMediaType = null
    ) -> <UploadedFileInterface>
    {
        return new UploadedFile(
            stream,
            size,
            error,
            clientFilename,
            clientMediaType
        );
    }
}
