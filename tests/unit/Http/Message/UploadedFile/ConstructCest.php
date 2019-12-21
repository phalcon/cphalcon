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

use Codeception\Example;
use Phalcon\Http\Message\Exception\InvalidArgumentException;
use Phalcon\Http\Message\UploadedFile;
use Psr\Http\Message\UploadedFileInterface;
use stdClass;
use UnitTester;

use function fopen;

class ConstructCest
{
    /**
     * Tests Phalcon\Http\Message\UploadedFile :: __construct()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-02-10
     */
    public function httpMessageUploadedFileConstruct(UnitTester $I)
    {
        $I->wantToTest('Http\Message\UploadedFile - __construct()');

        $stream = logsDir(
            uniqid('test')
        );

        $file = new UploadedFile($stream, 100);

        $I->assertInstanceOf(
            UploadedFileInterface::class,
            $file
        );
    }

    /**
     * Tests Phalcon\Http\Message\UploadedFile :: __construct() - $resource
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-02-10
     */
    public function httpMessageUploadedFileConstructResource(UnitTester $I)
    {
        $I->wantToTest('Http\Message\UploadedFile - __construct()');

        $stream = logsDir(
            uniqid('test')
        );

        $stream = fopen($stream, 'w+b');
        $file   = new UploadedFile($stream, 100);

        $I->assertInstanceOf(
            UploadedFileInterface::class,
            $file
        );
    }

    /**
     * Tests Phalcon\Http\Message\UploadedFile :: __construct() - stream
     * exception
     *
     * @dataProvider getStreamExamples
     *
     * @author       Phalcon Team <team@phalcon.io>
     * @since        2019-02-18
     */
    public function httpMessageUploadedFileConstructStreamException(UnitTester $I, Example $example)
    {
        $I->wantToTest(
            'Http\Message\UploadedFile - __construct() - stream ' . $example[0]
        );

        $I->expectThrowable(
            new InvalidArgumentException('Invalid stream or file passed'),
            function () use ($example) {
                $file = new UploadedFile($example[1], 100);
            }
        );
    }

    /**
     * Tests Phalcon\Http\Message\UploadedFile :: __construct() - error
     * exception
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-02-18
     */
    public function httpMessageUploadedFileConstructErrorException(UnitTester $I)
    {
        $I->wantToTest(
            'Http\Message\UploadedFile - __construct() - error exception'
        );

        $I->expectThrowable(
            new InvalidArgumentException('Invalid error. Must be one of the UPLOAD_ERR_* constants'),
            function () {
                $stream = logsDir(
                    uniqid('test')
                );

                $file = new UploadedFile($stream, 100, 100);
            }
        );
    }

    private function getStreamExamples(): array
    {
        return [
            [
                'array',
                ['array'],
            ],
            [
                'boolean',
                true,
            ],
            [
                'float',
                123.45,
            ],
            [
                'integer',
                123,
            ],
            [
                'null',
                null,
            ],
            [
                'object',
                new stdClass(),
            ],
        ];
    }
}
