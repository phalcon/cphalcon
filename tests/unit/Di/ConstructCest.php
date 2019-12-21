<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

declare(strict_types=1);

namespace Phalcon\Test\Unit\Di;

use Phalcon\Di;
use UnitTester;

class ConstructCest
{
    /**
     * Tests Phalcon\Di :: __construct()
     *
     * @author Phalcon Team <team@phalcon.io>
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
