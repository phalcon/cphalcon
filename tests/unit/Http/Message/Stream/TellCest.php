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
 * Class TellCest
 */
class TellCest
{
    /**
     * Tests Phalcon\Http\Message\Stream :: tell()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2019-02-10
     */
    public function httpMessageStreamTell(UnitTester $I)
    {
        $I->wantToTest('Http\Message\Stream - tell()');
        $fileName = dataFolder('/assets/stream/bill-of-rights.txt');
        $handle   = fopen($fileName, 'rb');
        $stream   = new Stream($handle);

        $expected = 274;
        fseek($handle, $expected);
        $actual = $stream->tell();
        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests Phalcon\Http\Message\Stream :: tell() - detached
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2019-02-10
     */
    public function httpMessageStreamTellDetached(UnitTester $I)
    {
        $I->wantToTest('Http\Message\Stream - tell() - detached');
        $I->expectThrowable(
            new Exception(
                'A valid resource is required.'
            ),
            function () {
                $fileName = dataFolder('/assets/stream/bill-of-rights.txt');
                $stream   = new Stream($fileName, 'rb');
                $stream->detach();

                $stream->tell();
            }
        );
    }
}
