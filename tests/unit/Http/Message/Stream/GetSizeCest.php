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
 * Class GetSizeCest
 */
class GetSizeCest
{
    /**
     * Tests Phalcon\Http\Message\Stream :: getSize()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2019-02-10
     */
    public function httpMessageStreamGetSize(UnitTester $I)
    {
        $I->wantToTest('Http\Message\Stream - getSize()');
        $fileName = dataFolder('/assets/stream/bill-of-rights.txt');
        $expected = filesize($fileName);
        $stream   = new Stream($fileName, 'rb');
        $actual   = $stream->getSize();
        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests Phalcon\Http\Message\Stream :: getSize() - invalid stream
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2019-02-10
     */
    public function httpMessageStreamGetSizeInvalid(UnitTester $I)
    {
        $I->wantToTest('Http\Message\Stream - getSize() - invalid');
        $stream   = new Stream('php://memory', 'rb');
        $expected = 0;
        $actual   = $stream->getSize();
        $I->assertEquals($expected, $actual);
    }
}
