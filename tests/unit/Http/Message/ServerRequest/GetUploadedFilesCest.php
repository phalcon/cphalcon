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
 * Class GetUploadedFilesCest
 */
class GetUploadedFilesCest
{
    /**
     * Tests Phalcon\Http\Message\ServerRequest :: getUploadedFiles()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2019-03-03
     */
    public function httpMessageServerRequestGetUploadedFiles(UnitTester $I)
    {
        $I->wantToTest('Http\Message\ServerRequest - getUploadedFiles()');
        $files   = [
            new UploadedFile('php://memory', 0),
            new UploadedFile('php://memory', 0),
        ];
        $request = new ServerRequest(
            'GET',
            null,
            [],
            'php://input',
            [],
            [],
            [],
            $files
        );

        $expected = $files;
        $actual   = $request->getUploadedFiles();
        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests Phalcon\Http\Message\ServerRequest :: getUploadedFiles() - empty
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2019-03-03
     */
    public function httpMessageServerRequestGetUploadedFilesEmpty(UnitTester $I)
    {
        $I->wantToTest('Http\Message\ServerRequest - getUploadedFiles() - empty');
        $request = new ServerRequest();

        $actual = $request->getUploadedFiles();
        $I->assertEmpty($actual);
    }

    /**
     * Tests Phalcon\Http\Message\ServerRequest :: getUploadedFiles() -
     * exception
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2019-03-03
     */
    public function httpMessageServerRequestGetUploadedFilesException(UnitTester $I)
    {
        $I->wantToTest('Http\Message\ServerRequest - getUploadedFiles() - exception');
        $I->expectThrowable(
            new InvalidArgumentException('Invalid uploaded file'),
            function () use ($I) {
                $files   = [
                    'something-else',
                ];
                $request = new ServerRequest(
                    'GET',
                    null,
                    [],
                    'php://input',
                    [],
                    [],
                    [],
                    $files
                );

                $actual = $request->getUploadedFiles();
            }
        );
    }
}
