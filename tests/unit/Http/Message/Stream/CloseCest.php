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
 * Class CloseCest
 */
class CloseCest
{
    /**
     * Tests Phalcon\Http\Message\Stream :: close()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2019-02-10
     */
    public function httpMessageStreamClose(UnitTester $I)
    {
        $I->wantToTest('Http\Message\Stream - close()');
        $fileName = dataFolder('/assets/stream/bill-of-rights.txt');
        $handle   = fopen($fileName, 'rb');
        $stream   = new Stream($handle);
        $stream->close();

        $actual = is_resource($handle);
        $I->assertFalse($actual);
    }

    /**
     * Tests Phalcon\Http\Message\Stream :: close() - detach
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2019-02-10
     */
    public function httpMessageStreamCloseDetach(UnitTester $I)
    {
        $I->wantToTest('Http\Message\Stream - close()');
        $fileName = dataFolder('/assets/stream/bill-of-rights.txt');
        $handle   = fopen($fileName, 'rb');
        $stream   = new Stream($handle);
        $stream->close();

        $actual = $stream->detach();
        $I->assertNull($actual);
    }
}
