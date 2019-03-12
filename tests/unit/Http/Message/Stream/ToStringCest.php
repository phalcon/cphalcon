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

use Phalcon\Http\Message\Stream;
use UnitTester;

/**
 * Class ToStringCest
 */
class ToStringCest
{
    /**
     * Tests Phalcon\Http\Message\Stream :: __toString()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2019-02-10
     */
    public function httpMessageStreamToString(UnitTester $I)
    {
        $I->wantToTest('Http\Message\Stream - __toString()');
        $fileName = dataFolder('/assets/stream/bill-of-rights.txt');
        $expected = file_get_contents($fileName);
        $stream   = new Stream($fileName, 'rb');

        $actual = (string) $stream;
        $I->assertEquals($expected, $actual);

        $actual = $stream->__toString();
        $I->assertEquals($expected, $actual);
    }
}
