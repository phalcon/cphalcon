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

namespace Phalcon\Test\Unit\Di;

use Phalcon\Di;
use UnitTester;

class ConstructCest
{
    /**
     * Tests Phalcon\Di :: __construct()
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function diConstruct(UnitTester $I)
    {
        $I->wantToTest('Di - __construct()');

        $di = new Di();

        $I->assertInstanceOf(Di::class, $di);

        $I->assertInstanceOf(Di::class, Di::getDefault());
    }
}
