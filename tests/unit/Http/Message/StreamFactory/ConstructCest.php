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

use Phalcon\Http\Message\StreamFactory;
use Psr\Http\Message\StreamFactoryInterface;
use UnitTester;

/**
 * Class CreateStreamCest
 */
class ConstructCest
{
    /**
     * Tests Phalcon\Http\Message\StreamFactory :: __construct()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2019-02-08
     */
    public function httpStreamFactoryConstruct(UnitTester $I)
    {
        $I->wantToTest('Http\StreamFactory - __construct()');

        $factory = new StreamFactory();
        $class   = StreamFactoryInterface::class;
        $I->assertInstanceOf($class, $factory);
    }
}
