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
 * Class OffsetExistsCest
 *
 * @package Phalcon\Test\Unit\Registry
 */
class OffsetExistsCest
{
    /**
     * Tests Phalcon\Registry :: offsetExists()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function registryOffsetExists(UnitTester $I)
    {
        $I->wantToTest('Registry - offsetExists()');
        $registry = new Registry();
        $registry->offsetSet('one', 1);

        $actual = $registry->offsetExists('one');
        $I->assertTrue($actual);

        $actual = $registry->offsetExists('unknown');
        $I->assertFalse($actual);
    }
}
