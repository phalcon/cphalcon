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

namespace Phalcon\Test\Unit\Http\Request;

use Phalcon\Http\Request;
use Phalcon\Http\RequestInterface;
use UnitTester;

/**
 * Class ConstructCest
 */
class ConstructCest
{
    /**
     * Tests Phalcon\Http\Cookie :: __construct()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function httpRequestConstruct(UnitTester $I)
    {
        $I->wantToTest("Http\Request - __construct()");

        $actual = new Request();
        $class  = RequestInterface::class;
        $I->assertInstanceOf($class, $actual);
    }
}
