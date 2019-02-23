<?php
declare(strict_types=1);

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Unit\Http\Message\UploadedFile;

use Phalcon\Http\Message\Exception;
use Phalcon\Http\Message\Stream;
use Phalcon\Http\Message\UploadedFile;
use UnitTester;

/**
 * Class MoveToCest
 */
class MoveToCest
{
    /**
     * Tests Phalcon\Http\Message\UploadedFile :: moveTo()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2019-02-10
     */
    public function httpMessageUploadedFileMoveTo(UnitTester $I)
    {
        $I->wantToTest('Http\Message\UploadedFile - moveTo()');
        $stream = new Stream('php://memory', 'w+b');
        $stream->write('Phalcon Framework');

        $file   = new UploadedFile($stream, 0);
        $target = $I->getNewFileName();
        $target = outputFolder('tests/stream/' . $target);

        $file->moveTo($target);

        $actual = file_exists($target);
        $I->assertTrue($actual);

        $expected = (string) $stream;
        $actual   = file_get_contents($target);
        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests Phalcon\Http\Message\UploadedFile :: moveTo() - upload error
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2019-02-10
     */
    public function httpMessageUploadedFileMoveToUploadError(UnitTester $I)
    {
        $I->wantToTest('Http\Message\UploadedFile - moveTo() - upload error');
        $I->expectThrowable(
            new Exception('UploadedFile:moveTo - Failed to write file to disk.'),
            function () use ($I) {
                $stream = new Stream('php://memory', 'w+b');
                $stream->write('Phalcon Framework');
                $target = $I->getNewFileName();
                $target = outputFolder('tests/stream/' . $target);

                $file  = new UploadedFile($stream, 0, UPLOAD_ERR_CANT_WRITE);
                $file->moveTo($target);
            }
        );
    }

    /**
     * Tests Phalcon\Http\Message\UploadedFile :: moveTo() - wrong path
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2019-02-10
     */
    public function httpMessageUploadedFileMoveToWrongPath(UnitTester $I)
    {
        $I->wantToTest('Http\Message\UploadedFile - moveTo() - wrong path');
        $I->expectThrowable(
            new Exception('UploadedFile:moveTo - Target folder is empty string, not a folder or not writable'),
            function () use ($I) {
                $stream = new Stream('php://memory', 'w+b');
                $stream->write('Phalcon Framework');

                $file  = new UploadedFile($stream, 0);
                $file->moveTo(123);
            }
        );
    }

    /**
     * Tests Phalcon\Http\Message\UploadedFile :: moveTo() - already moved
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2019-02-10
     */
    public function httpMessageUploadedFileMoveToAlreadyMoved(UnitTester $I)
    {
        $I->wantToTest('Http\Message\UploadedFile - moveTo() - already moved');
        $I->expectThrowable(
            new Exception('UploadedFile:moveTo - File has already been moved'),
            function () use ($I) {
                $stream = new Stream('php://memory', 'w+b');
                $stream->write('Phalcon Framework');

                $file   = new UploadedFile($stream, 0);
                $target = $I->getNewFileName();
                $target = outputFolder('tests/stream/' . $target);

                $file->moveTo($target);
                $file->moveTo($target);
            }
        );
    }
}
