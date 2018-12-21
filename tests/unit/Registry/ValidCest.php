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

/**
 * Class ValidCest
 *
 * @package Phalcon\Test\Unit\Registry
 */
class ValidCest
{
    /**
     * Tests Phalcon\Registry :: valid()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function registryValid(UnitTester $I)
    {
        $I->wantToTest('Registry - valid()');
        $registry = new Registry();
        $registry->offsetSet('one', 1);

        $registry->rewind();

        $actual = $registry->valid();
        $I->assertTrue($actual);

        $registry->next();
        $actual = $registry->valid();
        $I->assertFalse($actual);
    }
}
