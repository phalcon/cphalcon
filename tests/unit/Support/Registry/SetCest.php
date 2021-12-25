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

namespace Phalcon\Tests\Unit\Support\Registry;

use Phalcon\Support\Registry;
use UnitTester;

class SetCest
{
    /**
     * Tests Phalcon\Support\Registry :: set()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function registrySet(UnitTester $I)
    {
        $I->wantToTest('Registry - set()');

        $registry = new Registry();


        $registry->set('three', 'two');

        $I->assertEquals(
            'two',
            $registry->get('three')
        );
    }
}
