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

namespace Phalcon\Test\Unit\Http\Uri;

use Phalcon\Http\Uri;
use Psr\Http\Message\UriInterface;
use UnitTester;

/**
 * Class ConstructCest
 */
class ConstructCest
{
    /**
     * Tests Phalcon\Http\Uri :: __construct()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function httpUriConstruct(UnitTester $I)
    {
        $I->wantToTest('Http\Uri - __construct()');

        $uri   = new Uri();
        $class = UriInterface::class;
        $I->assertInstanceOf($class, $uri);
    }
}
