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
use UnitTester;

class DetachCest
{
    /**
     * Tests Phalcon\Http\Message\Stream :: detach()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-02-10
     */
    public function httpMessageStreamDetach(UnitTester $I)
    {
        $I->wantToTest('Http\Message\Stream - detach()');
        $fileName = dataDir('assets/stream/mit.txt');
        $handle   = fopen($fileName, 'rb');
        $stream   = new Stream($handle);

        $actual = $stream->detach();
        $I->assertEquals($handle, $actual);
    }
}
