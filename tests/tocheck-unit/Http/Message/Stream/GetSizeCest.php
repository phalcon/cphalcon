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
use Phalcon\Test\Fixtures\Http\Message\StreamFixture;
use UnitTester;

use function dataDir;

class GetSizeCest
{
    /**
     * Tests Phalcon\Http\Message\Stream :: getSize()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-02-10
     */
    public function httpMessageStreamGetSize(UnitTester $I)
    {
        $I->wantToTest('Http\Message\Stream - getSize()');
        $fileName = dataDir('assets/stream/mit.txt');
        $expected = filesize($fileName);
        $stream   = new Stream($fileName, 'rb');
        $actual   = $stream->getSize();
        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests Phalcon\Http\Message\Stream :: getSize() - invalid stream
     *
     * @author Phalcon Team <team@phalcon.io>
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

    /**
     * Tests Phalcon\Http\Message\Stream :: getSize() - invalid handle
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-02-10
     */
    public function httpMessageStreamGetSizeInvalidHandle(UnitTester $I)
    {
        $I->wantToTest('Http\Message\Stream - getSize() - invalid');
        $stream = new StreamFixture('php://memory', 'rb');
        $stream->setHandle(null);

        $actual = $stream->getSize();
        $I->assertNull($actual);
    }
}
