<?php
declare(strict_types=1);

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Unit\Http\Message\Stream;

use Phalcon\Http\Message\Stream;
use Phalcon\Test\Fixtures\Http\Message\StreamFixture;
use RuntimeException;
use UnitTester;

class SeekCest
{
    /**
     * Tests Phalcon\Http\Message\Stream :: seek()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-02-10
     */
    public function httpMessageStreamSeek(UnitTester $I)
    {
        $I->wantToTest('Http\Message\Stream - seek()');
        $fileName = dataDir('assets/stream/bill-of-rights.txt');
        $stream   = new Stream($fileName, 'rb');

        $stream->seek(274);
        $expected = 'A well regulated Militia, being necessary to the security of a free State, '
            . 'the right of the people to keep and bear Arms, shall not be infringed.';
        $actual   = $stream->read(145);
        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests Phalcon\Http\Message\Stream :: seek() - after file size
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-02-10
     */
    public function httpMessageStreamSeekAfterFileSize(UnitTester $I)
    {
        $I->wantToTest('Http\Message\Stream - seek() - after file size');
        $fileName = dataDir('assets/stream/bill-of-rights.txt');
        $stream   = new Stream($fileName, 'rb');

        $stream->seek(10240);
        $expected = '';
        $actual   = $stream->read(1);
        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests Phalcon\Http\Message\Stream :: seek() - exception
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-02-10
     */
    public function httpMessageStreamSeekException(UnitTester $I)
    {
        $I->wantToTest('Http\Message\Stream - seek() - exception');
        $fileName = dataDir('assets/stream/bill-of-rights.txt');
        $stream   = new StreamFixture($fileName, 'rb');

        $I->expectThrowable(
            new RuntimeException('The resource is not seekable.'),
            function () use ($stream) {
                $stream->seek(10240);
            }
        );
    }
}
