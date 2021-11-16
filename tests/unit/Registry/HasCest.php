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

namespace Phalcon\Tests\Unit\Registry;

use Phalcon\Registry;
use UnitTester;

class HasCest
{
    /**
     * Tests Phalcon\Registry :: has()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function registryHas(UnitTester $I)
    {
        $I->wantToTest('Registry - has()');

        $data = [
            'one'   => 'two',
            'three' => 'four',
            'five'  => 'six',
        ];

        $registry = new Registry($data);

        $I->assertTrue(
            $registry->has('three')
        );

        $I->assertFalse(
            $registry->has('unknown')
        );
    }
}
