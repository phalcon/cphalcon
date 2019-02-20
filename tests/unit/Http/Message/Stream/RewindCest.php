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

use Phalcon\Http\Message\Exception;
use Phalcon\Http\Message\Stream;
use UnitTester;

/**
 * Class RewindCest
 */
class RewindCest
{
    /**
     * Tests Phalcon\Http\Message\Stream :: rewind()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2019-02-10
     */
    public function httpMessageStreamRewind(UnitTester $I)
    {
        $I->wantToTest('Http\Message\Stream - rewind()');
        $fileName = dataFolder('/assets/stream/bill-of-rights.txt');
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
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2019-02-10
     */
    public function httpMessageStreamRewindDetached(UnitTester $I)
    {
        $I->wantToTest('Http\Message\Stream - rewind() - detached');
        $I->expectThrowable(
            new Exception(
                'Stream:seek - A valid resource is required.'
            ),
            function () {
                $fileName = dataFolder('/assets/stream/bill-of-rights.txt');
                $stream   = new Stream($fileName, 'rb');
                $stream->detach();

                $stream->rewind();
            }
        );
    }
}
