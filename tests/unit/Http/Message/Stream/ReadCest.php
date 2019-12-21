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

namespace Phalcon\Test\Unit\Http\Message\Stream;

use Phalcon\Http\Message\Stream;
use RuntimeException;
use UnitTester;

class ReadCest
{
    /**
     * Tests Phalcon\Http\Message\Stream :: read()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-02-10
     */
    public function httpMessageStreamRead(UnitTester $I)
    {
        $I->wantToTest('Http\Message\Stream - read()');

        $fileName = dataDir('assets/stream/mit.txt');

        $stream = new Stream($fileName, 'rb');

        $expected = "The MIT License (MIT)\n\nCopyright (c) 2015-present, Phalcon PHP";
        $actual   = $stream->read(62);
        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests Phalcon\Http\Message\Stream :: read() - detached
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-02-10
     */
    public function httpMessageStreamReadDetached(UnitTester $I)
    {
        $I->wantToTest('Http\Message\Stream - read() - detached');

        $I->expectThrowable(
            new RuntimeException(
                'A valid resource is required.'
            ),
            function () {
                $fileName = dataDir('assets/stream/mit.txt');

                $stream = new Stream($fileName, 'rb');

                $stream->detach();

                $stream->read(10);
            }
        );
    }
}
