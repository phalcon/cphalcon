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

namespace Phalcon\Tests\Unit\Http\Message\StreamFactory;

use Phalcon\Http\Message\Exception\InvalidArgumentException;
use Phalcon\Http\Message\Stream;
use Phalcon\Http\Message\StreamFactory;
use UnitTester;

class CreateStreamFromResourceCest
{
    /**
     * Tests Phalcon\Http\Message\StreamFactory :: createStreamFromResource()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-02-10
     */
    public function httpMessageStreamFactoryCreateStreamFromResource(UnitTester $I)
    {
        $I->wantToTest('Http\Message\StreamFactory - createStreamFromResource()');

        $fileName = dataDir('assets/stream/mit.txt');
        $expected = file_get_contents($fileName);
        $resource = fopen($fileName, 'r+b');
        $factory  = new StreamFactory();
        $stream   = $factory->createStreamFromResource($resource);

        $I->assertInstanceOf(
            Stream::class,
            $stream
        );

        $I->assertEquals(
            $expected,
            $stream->getContents()
        );
    }

    /**
     * Tests Phalcon\Http\Message\StreamFactory :: createStreamFromResource() -
     * exception
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-02-10
     */
    public function httpMessageStreamFactoryCreateStreamFromResourceException(UnitTester $I)
    {
        $I->wantToTest('Http\Message\StreamFactory - createStreamFromResource() - exception');

        $I->expectThrowable(
            new InvalidArgumentException(
                'Invalid stream provided'
            ),
            function () {
                $factory = new StreamFactory();

                $stream = $factory->createStreamFromResource(false);
            }
        );
    }
}
