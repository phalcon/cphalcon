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

namespace Phalcon\Test\Unit\Http\Message\StreamFactory;

use InvalidArgumentException;
use Phalcon\Http\Message\Stream;
use Phalcon\Http\Message\StreamFactory;
use UnitTester;

class CreateStreamFromResourceCest
{
    /**
     * Tests Phalcon\Http\Message\StreamFactory :: createStreamFromResource()
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2019-02-10
     */
    public function httpMessageStreamFactoryCreateStreamFromResource(UnitTester $I)
    {
        $I->wantToTest('Http\Message\StreamFactory - createStreamFromResource()');
        $fileName = dataDir('/assets/stream/bill-of-rights.txt');
        $expected = file_get_contents($fileName);
        $resource = fopen($fileName, 'r+b');

        $factory = new StreamFactory();
        $stream  = $factory->createStreamFromResource($resource);

        $class = Stream::class;
        $I->assertInstanceOf($class, $stream);

        $actual = $stream->getContents();
        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests Phalcon\Http\Message\StreamFactory :: createStreamFromResource() -
     * exception
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2019-02-10
     */
    public function httpMessageStreamFactoryCreateStreamFromResourceException(UnitTester $I)
    {
        $I->wantToTest('Http\Message\StreamFactory - createStreamFromResource() - exception');

        $I->expectThrowable(
            new InvalidArgumentException(
                "Invalid stream provided"
            ),
            function () {
                $factory = new StreamFactory();
                $stream  = $factory->createStreamFromResource(false);
            }
        );
    }
}
