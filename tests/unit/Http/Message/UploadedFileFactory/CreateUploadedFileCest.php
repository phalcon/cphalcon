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

namespace Phalcon\Test\Unit\Http\Message\UploadedFileFactory;

use Phalcon\Http\Message\Stream;
use Phalcon\Http\Message\UploadedFileFactory;
use Psr\Http\Message\UploadedFileInterface;
use UnitTester;

/**
 * Class CreateUploadedFileCest
 */
class CreateUploadedFileCest
{
    /**
     * Tests Phalcon\Http\Message\UploadedFileFactory :: createUploadedFile()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2019-02-10
     */
    public function httpMessageUploadedFileFactoryCreateUploadedFile(UnitTester $I)
    {
        $I->wantToTest('Http\Message\UploadedFileFactory - createUploadedFile()');
        $factory = new UploadedFileFactory();
        $stream  = new Stream("php://temp");
        $file    = $factory->createUploadedFile($stream);
        $class   = UploadedFileInterface::class;
        $I->assertInstanceOf($class, $file);
    }
}
