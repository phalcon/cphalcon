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

namespace Phalcon\Test\Unit\Http\Message\StreamFactory;

use Phalcon\Http\Message\Stream;
use Phalcon\Http\Message\StreamFactory;
use UnitTester;

/**
 * Class CreateStreamFromFileCest
 */
class CreateStreamFromFileCest
{
    /**
     * Tests Phalcon\Http\Message\StreamFactory :: createStreamFromFile()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2019-02-10
     */
    public function httpMessageStreamFactoryCreateStreamFromFile(UnitTester $I)
    {
        $I->wantToTest('Http\Message\StreamFactory - createStreamFromFile()');
        $fileName = dataFolder('/assets/stream/bill-of-rights.txt');
        $expected = file_get_contents($fileName);

        $factory = new StreamFactory();
        $stream  = $factory->createStreamFromFile($fileName);

        $class = Stream::class;
        $I->assertInstanceOf($class, $stream);

        $actual = $stream->getContents();
        $I->assertEquals($expected, $actual);
    }
}
