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
 * Class OffsetUnsetCest
 *
 * @package Phalcon\Tests\Unit\Di
 */
class OffsetUnsetCest
{
    /**
     * Tests Phalcon\Di :: offsetUnset()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-09-09
     */
    public function diOffsetUnset(UnitTester $I)
    {
        $I->wantToTest('Di - offsetUnset()');

        $container = new Di();
        $escaper   = new Escaper();

        $container->set('escaper', $escaper);

        $actual = $container->has('escaper');
        $I->assertTrue($actual);

        unset($container['escaper']);

        $actual = $container->has('escaper');
        $I->assertFalse($actual);
    }
}
