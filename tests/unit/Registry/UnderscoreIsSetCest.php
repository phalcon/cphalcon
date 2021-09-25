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

class UnderscoreIsSetCest
{
    /**
     * Unit Tests Phalcon\Registry :: __isset()
     *
     * @author Sid Roberts <https://github.com/SidRoberts>
     * @since  2019-05-25
     */
    public function registryUnderscoreIsSet(UnitTester $I)
    {
        $I->wantToTest('Registry - __isset()');

        $data = [
            'one'   => 'two',
            'three' => 'four',
            'five'  => 'six',
        ];

        $registry = new Registry($data);

        $I->assertTrue(
            isset($registry->three)
        );

        $I->assertFalse(
            isset($registry->unknown)
        );
    }
}
