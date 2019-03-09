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
 * Class CreateStreamFromResourceCest
 */
class CreateStreamFromResourceCest
{
    /**
     * Tests Phalcon\Http\Message\StreamFactory :: createStreamFromResource()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2019-02-10
     */
    public function httpMessageStreamFactoryCreateStreamFromResource(UnitTester $I)
    {
        $I->wantToTest('Http\Message\StreamFactory - createStreamFromResource()');
        $I->skipTest('Need implementation');
    }

    /**
     * Tests Phalcon\Http\Message\StreamFactory :: createStreamFromResource() - exception
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2019-02-10
     */
    public function httpMessageStreamFactoryCreateStreamFromResourceException(UnitTester $I)
    {
        $I->wantToTest('Http\Message\StreamFactory - createStreamFromResource() - exception');

        $I->expectThrowable(
            new \InvalidArgumentException(
                "Invalid stream provided"
            ),
            function () {
                $factory = new StreamFactory();
                $stream  = $factory->createStreamFromResource(false);
            }
        );
    }
}
