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

namespace Phalcon\Test\Unit\Http\Message\ServerRequestFactory;

use Phalcon\Http\Message\ServerRequestFactory;
use Psr\Http\Message\ServerRequestFactoryInterface;
use UnitTester;

/**
 * Class CreateServerRequestCest
 */
class ConstructCest
{
    /**
     * Tests Phalcon\Http\Message\ServerRequestFactory :: __construct()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2019-02-08
     */
    public function httpServerRequestFactoryConstruct(UnitTester $I)
    {
        $I->wantToTest('Http\ServerRequestFactory - __construct()');

        $factory = new ServerRequestFactory();
        $class   = ServerRequestFactoryInterface::class;
        $I->assertInstanceOf($class, $factory);
    }
}
