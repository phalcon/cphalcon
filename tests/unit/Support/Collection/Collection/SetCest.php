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

namespace Phalcon\Tests\Unit\Support\Collection\Collection;

use Phalcon\Support\Collection;
use UnitTester;

class SetCest
{
    /**
     * Tests Phalcon\Support\Collection :: set()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function supportCollectionSet(UnitTester $I)
    {
        $I->wantToTest('Support\Collection - set()');

        $collection = new Collection();

        $collection->set('three', 'two');

        $expected = 'two';
        $actual   = $collection->get('three');
        $I->assertEquals($expected, $actual);

        $collection->three = 'Phalcon';

        $expected = 'Phalcon';
        $actual   = $collection->get('three');
        $I->assertEquals($expected, $actual);

        $collection->offsetSet('three', 123);

        $expected = 123;
        $actual   = $collection->get('three');
        $I->assertEquals($expected, $actual);

        $collection['three'] = true;

        $actual = $collection->get('three');
        $I->assertTrue($actual);
    }
}
