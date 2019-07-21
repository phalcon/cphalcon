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

namespace Phalcon\Test\Unit\Registry;

use Phalcon\Registry;
use UnitTester;

class ConstructCest
{
    /**
     * Tests Phalcon\Registry :: __construct()
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function registryConstruct(UnitTester $I)
    {
        $I->wantToTest('Registry - __construct()');

        $registry = new Registry();

        $I->assertInstanceOf(
            Registry::class,
            $registry
        );
    }
}
