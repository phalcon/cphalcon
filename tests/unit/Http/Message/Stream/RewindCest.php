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

use Phalcon\Http\Message\Stream;
use RuntimeException;
use UnitTester;

class RewindCest
{
    /**
     * Tests Phalcon\Http\Message\Stream :: rewind()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-02-10
     */
    public function httpMessageStreamRewind(UnitTester $I)
    {
        $I->wantToTest('Http\Message\Stream - rewind()');
        $fileName = dataDir('assets/stream/mit.txt');
        $stream   = new Stream($fileName);

        $stream->seek(10);
        $expected = 10;
        $actual   = $stream->tell();
        $I->assertEquals($expected, $actual);

        $stream->rewind();
        $expected = 0;
        $actual   = $stream->tell();
        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests Phalcon\Http\Message\Stream :: rewind() - detached
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-02-10
     */
    public function httpMessageStreamRewindDetached(UnitTester $I)
    {
        $I->wantToTest('Http\Message\Stream - rewind() - detached');
        $I->expectThrowable(
            new RuntimeException(
                'A valid resource is required.'
            ),
            function () {
                $fileName = dataDir('assets/stream/mit.txt');
                $stream   = new Stream($fileName, 'rb');
                $stream->detach();

                $stream->rewind();
            }
        );
    }
}
