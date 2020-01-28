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

namespace Phalcon\Test\Unit\Http\Message\StreamFactory;

use Phalcon\Http\Message\Stream;
use Phalcon\Http\Message\StreamFactory;
use UnitTester;

class CreateStreamFromFileCest
{
    /**
     * Tests Phalcon\Http\Message\StreamFactory :: createStreamFromFile()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-02-10
     */
    public function httpMessageStreamFactoryCreateStreamFromFile(UnitTester $I)
    {
        $I->wantToTest('Http\Message\StreamFactory - createStreamFromFile()');

        $fileName = dataDir('assets/stream/mit.txt');
        $expected = file_get_contents($fileName);
        $factory  = new StreamFactory();
        $stream   = $factory->createStreamFromFile($fileName);

        $I->assertInstanceOf(
            Stream::class,
            $stream
        );

        $I->assertEquals(
            $expected,
            $stream->getContents()
        );
    }
}
