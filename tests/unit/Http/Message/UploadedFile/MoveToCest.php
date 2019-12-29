<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

declare(strict_types=1);

namespace Phalcon\Test\Unit\Http\Message\UploadedFile;

use Phalcon\Http\Message\Exception\InvalidArgumentException;
use Phalcon\Http\Message\Stream;
use Phalcon\Http\Message\UploadedFile;
use UnitTester;

use function outputDir;

class MoveToCest
{
    /**
     * Tests Phalcon\Http\Message\UploadedFile :: moveTo()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-02-10
     */
    public function httpMessageUploadedFileMoveTo(UnitTester $I)
    {
        $I->wantToTest('Http\Message\UploadedFile - moveTo()');

        $stream = new Stream('php://memory', 'w+b');

        $stream->write('Phalcon Framework');

        $file   = new UploadedFile($stream, 0);
        $target = $I->getNewFileName();
        $target = outputDir(
            'tests/stream/' . $target
        );

        $file->moveTo($target);
        $I->seeFileFound($target);
        $I->openFile($target);

        $I->seeFileContentsEqual(
            (string) $stream
        );
    }

    /**
     * Tests Phalcon\Http\Message\UploadedFile :: moveTo() - upload error
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-02-10
     */
    public function httpMessageUploadedFileMoveToUploadError(UnitTester $I)
    {
        $I->wantToTest('Http\Message\UploadedFile - moveTo() - upload error');

        $I->expectThrowable(
            new InvalidArgumentException(
                'Failed to write file to disk.'
            ),
            function () use ($I) {
                $stream = new Stream('php://memory', 'w+b');

                $stream->write('Phalcon Framework');

                $target = $I->getNewFileName();

                $target = outputDir(
                    'tests/stream/' . $target
                );

                $file = new UploadedFile($stream, 0, UPLOAD_ERR_CANT_WRITE);

                $file->moveTo($target);
            }
        );
    }

    /**
     * Tests Phalcon\Http\Message\UploadedFile :: moveTo() - wrong path
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-02-10
     */
    public function httpMessageUploadedFileMoveToWrongPath(UnitTester $I)
    {
        $I->wantToTest('Http\Message\UploadedFile - moveTo() - wrong path');

        $I->expectThrowable(
            new InvalidArgumentException(
                'Target folder is empty string, not a folder or not writable'
            ),
            function () use ($I) {
                $stream = new Stream('php://memory', 'w+b');

                $stream->write('Phalcon Framework');

                $file = new UploadedFile($stream, 0);

                $file->moveTo(123);
            }
        );
    }

    /**
     * Tests Phalcon\Http\Message\UploadedFile :: moveTo() - already moved
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-02-10
     */
    public function httpMessageUploadedFileMoveToAlreadyMoved(UnitTester $I)
    {
        $I->wantToTest('Http\Message\UploadedFile - moveTo() - already moved');

        $I->expectThrowable(
            new InvalidArgumentException(
                'File has already been moved'
            ),
            function () use ($I) {
                $stream = new Stream('php://memory', 'w+b');

                $stream->write('Phalcon Framework');

                $file = new UploadedFile($stream, 0);

                $target = $I->getNewFileName();

                $target = outputDir(
                    'tests/stream/' . $target
                );

                $file->moveTo($target);
                $file->moveTo($target);
            }
        );
    }
}
