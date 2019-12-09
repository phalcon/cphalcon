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

namespace Phalcon\Test\Unit\Collection\Collection;

use Phalcon\Collection;
use UnitTester;

class SetCest
{
    /**
     * Tests Phalcon\Collection :: set()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function collectionSet(UnitTester $I)
    {
        $I->wantToTest('Collection - set()');

        $collection = new Collection();

        $collection->set('three', 'two');

        $I->assertEquals(
            'two',
            $collection->get('three')
        );

        $collection->three = 'Cardoe';

        $I->assertEquals(
            'Cardoe',
            $collection->get('three')
        );

        $collection->offsetSet('three', 123);

        $I->assertEquals(
            123,
            $collection->get('three')
        );


        $collection['three'] = true;

        $I->assertTrue(
            $collection->get('three')
        );
    }
}
