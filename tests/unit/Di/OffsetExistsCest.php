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

use Phalcon\Di\Di;
use Phalcon\Html\Escaper;
use UnitTester;

/**
 * Class OffsetExistsCest
 *
 * @package Phalcon\Tests\Unit\Di
 */
class OffsetExistsCest
{
    /**
     * Tests Phalcon\Di\Di :: offsetExists()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-09-09
     */
    public function diOffsetExists(UnitTester $I)
    {
        $I->wantToTest('Di - offsetExists()');

        $container = new Di();

        $actual = isset($container['escaper']);
        $I->assertFalse($actual);

        $container->set('escaper', Escaper::class);

        $actual = isset($container['escaper']);
        $I->assertTrue($actual);
    }
}
