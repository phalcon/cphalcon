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
 * Class ReadCest
 */
class ReadCest
{
    /**
     * Tests Phalcon\Http\Message\Stream :: read()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2019-02-10
     */
    public function httpMessageStreamRead(UnitTester $I)
    {
        $I->wantToTest('Http\Message\Stream - read()');
        $fileName = dataFolder('/assets/stream/bill-of-rights.txt');
        $stream   = new Stream($fileName, 'rb');

        $expected = 'Congress shall make no law respecting an establishment of '
            . 'religion, or prohibiting the free exercise thereof; or '
            . 'abridging the freedom of speech, or of the press; or the '
            . 'right of the people peaceably to assemble, and to petition '
            . 'the Government for a redress of grievances.';
        $actual   = $stream->read(272);
        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests Phalcon\Http\Message\Stream :: read() - detached
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2019-02-10
     */
    public function httpMessageStreamReadDetached(UnitTester $I)
    {
        $I->wantToTest('Http\Message\Stream - read() - detached');
        $I->expectThrowable(
            new Exception(
                'A valid resource is required.'
            ),
            function () {
                $fileName = dataFolder('/assets/stream/bill-of-rights.txt');
                $stream   = new Stream($fileName, 'rb');
                $stream->detach();

                $stream->read(10);
            }
        );
    }
}
