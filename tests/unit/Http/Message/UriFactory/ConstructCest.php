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

namespace Phalcon\Test\Unit\Http\UriFactory;

use Phalcon\Http\UriFactory;
use Psr\Http\Message\UriFactoryInterface;
use UnitTester;

/**
 * Class CreateUriCest
 */
class ConstructCest
{
    /**
     * Tests Phalcon\Http\UriFactory :: __construct()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2019-02-07
     */
    public function httpUrifactoryConstruct(UnitTester $I)
    {
        $I->wantToTest('Http\UriFactory - __construct()');

        $factory = new UriFactory();
        $class   = UriFactoryInterface::class;
        $I->assertInstanceOf($class, $factory);
    }
}
