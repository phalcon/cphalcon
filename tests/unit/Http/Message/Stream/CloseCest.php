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
use UnitTester;

class CloseCest
{
    /**
     * Tests Phalcon\Http\Message\Stream :: close()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-02-10
     */
    public function httpMessageStreamClose(UnitTester $I)
    {
        $I->wantToTest('Http\Message\Stream - close()');

        $fileName = dataDir('assets/stream/mit.txt');

        $handle = fopen($fileName, 'rb');

        $stream = new Stream($handle);

        $stream->close();

        $I->assertInternalType(
            'resource',
            $handle
        );
    }

    /**
     * Tests Phalcon\Http\Message\Stream :: close() - detach
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-02-10
     */
    public function httpMessageStreamCloseDetach(UnitTester $I)
    {
        $I->wantToTest('Http\Message\Stream - close()');

        $fileName = dataDir('assets/stream/mit.txt');

        $handle = fopen($fileName, 'rb');

        $stream = new Stream($handle);

        $stream->close();

        $I->assertNull(
            $stream->detach()
        );
    }
}
