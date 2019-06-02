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

class DetachCest
{
    /**
     * Tests Phalcon\Http\Message\Stream :: detach()
     *
     * @since  2019-02-10
     */
    public function httpMessageStreamDetach(UnitTester $I)
    {
        $I->wantToTest('Http\Message\Stream - detach()');
        $fileName = dataDir('assets/stream/bill-of-rights.txt');
        $handle   = fopen($fileName, 'rb');
        $stream   = new Stream($handle);

        $actual = $stream->detach();
        $I->assertEquals($handle, $actual);
    }
}
