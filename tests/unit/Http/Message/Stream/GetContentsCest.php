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

use Phalcon\Http\Message\Exception;
use Phalcon\Http\Message\Stream;
use UnitTester;

/**
 * Class GetContentsCest
 */
class GetContentsCest
{
    /**
     * Tests Phalcon\Http\Message\Stream :: getContents()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2019-02-10
     */
    public function httpMessageStreamGetContents(UnitTester $I)
    {
        $I->wantToTest('Http\Message\Stream - getContents()');
        $fileName = dataFolder('/assets/stream/bill-of-rights.txt');
        $expected = file_get_contents($fileName);
        $stream   = new Stream($fileName, 'rb');

        $actual = $stream->getContents();
        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests Phalcon\Http\Message\Stream :: getContents() - from position
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2019-02-10
     */
    public function httpMessageStreamGetContentsFromPosition(UnitTester $I)
    {
        $I->wantToTest('Http\Message\Stream - getContents() - from position');
        $fileName = dataFolder('/assets/stream/bill-of-rights.txt');
        $stream   = new Stream($fileName, 'rb');

        $stream->seek(2169);
        $expected = 'The powers not delegated to the United States by the '
            . 'Constitution, nor prohibited by it to the States, are '
            . 'reserved to the States respectively, or to the people.'
            . "\n";
        $actual   = $stream->getContents();
        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests Phalcon\Http\Message\Stream :: getContents() - exception
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2019-02-10
     */
    public function httpMessageStreamGetContentsException(UnitTester $I)
    {
        $I->wantToTest('Http\Message\Stream - getContents() - exception');
        $I->expectThrowable(
            new Exception(
                'The resource is not readable.'
            ),
            function () {
                $fileName = dataFolder('/assets/stream/bill-of-rights-empty.txt');
                $stream   = new Stream($fileName, 'wb');

                $actual = $stream->getContents();
            }
        );
    }
}
