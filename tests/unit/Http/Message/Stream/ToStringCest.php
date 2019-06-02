<?php
declare(strict_types=1);

/**
 * This file is part of the Phalcon Framework.
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Unit\Http\Message\Stream;

use Phalcon\Http\Message\Stream;
use UnitTester;

class ToStringCest
{
    /**
     * Tests Phalcon\Http\Message\Stream :: __toString()
     *
     * @since  2019-02-10
     */
    public function httpMessageStreamToString(UnitTester $I)
    {
        $I->wantToTest('Http\Message\Stream - __toString()');

        $fileName = dataDir('assets/stream/bill-of-rights.txt');
        $expected = file_get_contents($fileName);
        $stream   = new Stream($fileName, 'rb');

        $I->assertEquals(
            $expected,
            (string) $stream
        );

        $I->assertEquals(
            $expected,
            $stream->__toString()
        );
    }
}
