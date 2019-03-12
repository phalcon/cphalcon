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

namespace Phalcon\Test\Unit\Http\Message\ServerRequest;

use InvalidArgumentException;
use Phalcon\Http\Message\ServerRequest;
use Phalcon\Http\Message\UploadedFile;
use UnitTester;

/**
 * Class WithUploadedFilesCest
 */
class WithUploadedFilesCest
{
    /**
     * Tests Phalcon\Http\Message\ServerRequest :: withUploadedFiles()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2019-02-10
     */
    public function httpMessageServerRequestWithUploadedFiles(UnitTester $I)
    {
        $I->wantToTest('Http\Message\ServerRequest - withUploadedFiles()');
        $files       = [
            new UploadedFile('php://memory', 0),
            new UploadedFile('php://memory', 0),
        ];
        $request     = new ServerRequest();
        $newInstance = $request->withUploadedFiles($files);
        $I->assertNotEquals($request, $newInstance);

        $expected = $files;
        $actual   = $newInstance->getUploadedFiles();
        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests Phalcon\Http\Message\ServerRequest :: withUploadedFiles() -
     * exception
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2019-02-10
     */
    public function httpMessageServerRequestWithUploadedFilesException(UnitTester $I)
    {
        $I->wantToTest('Http\Message\ServerRequest - withUploadedFiles() - exception');
        $I->expectThrowable(
            new InvalidArgumentException('Invalid uploaded file'),
            function () use ($I) {
                $files       = [
                    'something-else',
                ];
                $request     = new ServerRequest();
                $newInstance = $request->withUploadedFiles($files);
            }
        );
    }
}
