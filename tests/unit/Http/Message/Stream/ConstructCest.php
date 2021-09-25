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

namespace Phalcon\Tests\Unit\Http\Message\Stream;

use Codeception\Example;
use Phalcon\Http\Message\Stream;
use Psr\Http\Message\StreamInterface;
use RuntimeException;
use stdClass;
use UnitTester;

class ConstructCest
{
    /**
     * Tests Phalcon\Http\Message\Stream :: __construct()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-02-08
     */
    public function httpMessageStreamConstruct(UnitTester $I)
    {
        $I->wantToTest('Http\Message\Stream - __construct()');

        $request = new Stream('php://temp');

        $I->assertInstanceOf(
            StreamInterface::class,
            $request
        );
    }

    /**
     * Tests Phalcon\Http\Message\Stream :: __construct() - exception
     *
     * @dataProvider getExceptionExamples
     *
     * @author       Phalcon Team <team@phalcon.io>
     * @since        2019-02-08
     */
    public function httpMessageStreamConstructException(UnitTester $I, Example $example)
    {
        $I->wantToTest('Http\Message\Stream - __construct() ' . $example[0]);
        $I->expectThrowable(
            new RuntimeException(
                'The stream provided is not valid ' .
                '(string/resource) or could not be opened.'
            ),
            function () use ($example) {
                $request = new Stream($example[1]);
            }
        );
    }

    private function getExceptionExamples(): array
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
