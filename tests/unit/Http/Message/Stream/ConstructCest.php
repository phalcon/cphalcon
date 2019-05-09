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

namespace Phalcon\Test\Unit\Http\Message\Stream;

use Codeception\Example;
use Phalcon\Http\Message\Exception;
use Phalcon\Http\Message\Stream;
use Psr\Http\Message\StreamInterface;
use stdClass;
use UnitTester;

class ConstructCest
{
    /**
     * Tests Phalcon\Http\Message\Stream :: __construct()
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2019-02-08
     */
    public function httpMessageStreamConstruct(UnitTester $I)
    {
        $I->wantToTest('Http\Message\Stream - __construct()');

        $request = new Stream("php://temp");

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
     * @author       Phalcon Team <team@phalconphp.com>
     * @since        2019-02-08
     */
    public function httpMessageStreamConstructException(UnitTester $I, Example $example)
    {
        $I->wantToTest('Http\Message\Stream - __construct() ' . $example[0]);
        $I->expectThrowable(
            new Exception(
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
            ['array', ['array']],
            ['boolean', true],
            ['float', 123.45],
            ['integer', 123],
            ['null', null],
            ['object', new stdClass()],
        ];
    }
}
