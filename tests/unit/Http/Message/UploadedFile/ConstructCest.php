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

use Codeception\Example;
use Phalcon\Http\Message\UploadedFile;
use Phalcon\Http\Message\Exception;
use Psr\Http\Message\UploadedFileInterface;
use UnitTester;

/**
 * Class ConstructCest
 */
class ConstructCest
{
    /**
     * Tests Phalcon\Http\Message\UploadedFile :: __construct()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2019-02-10
     */
    public function httpMessageUploadedFileConstruct(UnitTester $I)
    {
        $I->wantToTest('Http\Message\UploadedFile - __construct()');

        $stream = outputFolder(uniqid('test'));
        $file  = new UploadedFile($stream, 100);
        $class = UploadedFileInterface::class;
        $I->assertInstanceOf($class, $file);
    }

    /**
     * Tests Phalcon\Http\Message\UploadedFile :: __construct() - stream exception
     *
     * @dataProvider getStreamExamples
     *
     * @param UnitTester $I
     * @param Example    $example
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2019-02-18
     */
    public function httpMessageUploadedFileConstructStreamException(UnitTester $I, Example $example)
    {
        $I->wantToTest('Http\Message\UploadedFile - __construct() - stream ' . $example[0]);

        $I->expectThrowable(
            new Exception("UploadedFile:__construct - Invalid stream or file passed"),
            function () use ($example) {
                $file = new UploadedFile($example[1], 100);
            }
        );
    }

    /**
     * Tests Phalcon\Http\Message\UploadedFile :: __construct() - error exception
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2019-02-18
     */
    public function httpMessageUploadedFileConstructErrorException(UnitTester $I)
    {
        $I->wantToTest('Http\Message\UploadedFile - __construct() - error exception');

        $I->expectThrowable(
            new Exception("UploadedFile:__construct - Invalid 'error'. Must be one of the UPLOAD_ERR_* constants"),
            function () {
                $stream = outputFolder(uniqid('test'));
                $file = new UploadedFile($stream, 100, 100);
            }
        );
    }

    /**
     * @return array
     */
    private function getStreamExamples(): array
    {
        return [
            ['array',   ['array']],
            ['boolean', true],
            ['float',   123.45],
            ['integer', 123],
            ['null',    null],
            ['object',  new \stdClass()],
        ];
    }
}
