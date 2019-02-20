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
 * Class EofCest
 */
class EofCest
{
    /**
     * Tests Phalcon\Http\Message\Stream :: eof()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2019-02-10
     */
    public function httpMessageStreamEof(UnitTester $I)
    {
        $I->wantToTest('Http\Message\Stream - eof()');
        $fileName = dataFolder('/assets/stream/bill-of-rights.txt');
        $offset   = filesize($fileName);
        $handle   = fopen($fileName, 'rb');
        fseek($handle, $offset);
        $stream   = new Stream($handle);

        $actual = $stream->eof();
        $I->assertTrue($actual);
    }
}
