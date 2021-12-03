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

namespace Phalcon\Tests\Unit\Di;

use Phalcon\Di;
use Phalcon\Html\Escaper;
use UnitTester;

/**
 * Class HasCest
 *
 * @package Phalcon\Tests\Unit\Di
 */
class HasCest
{
    /**
     * Tests Phalcon\Di :: has()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-09-09
     */
    public function diHas(UnitTester $I)
    {
        $I->wantToTest('Di - has()');

        $container = new Di();

        $actual = $container->has('escaper');
        $I->assertFalse($actual);

        $container->set('escaper', Escaper::class);

        $actual = $container->has('escaper');
        $I->assertTrue($actual);
    }
}
