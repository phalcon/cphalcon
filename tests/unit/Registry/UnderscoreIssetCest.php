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
 * Class UnderscoreIsset
 *
 * @package Phalcon\Test\Unit\Registry
 */
class UnderscoreIsset
{
    /**
     * Tests Phalcon\Registry :: __isset()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function registryUnderscoreIsset(UnitTester $I)
    {
        $I->wantToTest('Registry - __isset()');
        $registry = new Registry();
        $registry->offsetSet('one', 1);

        $actual = isset($registry['one']);
        $I->assertTrue($actual);

        $actual = isset($registry['unknown']);
        $I->assertFalse($actual);
    }
}
