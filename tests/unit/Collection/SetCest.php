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

namespace Phalcon\Test\Unit\Collection;

use Phalcon\Collection;
use UnitTester;

/**
 * Class SetCest
 */
class SetCest
{
    /**
     * Tests Phalcon\Collection :: set()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function collectionSet(UnitTester $I)
    {
        $I->wantToTest('Collection - set()');
        $collection = new Collection();

        $collection->set('three', 'two');
        $expected = 'two';
        $actual   = $collection->get('three');
        $I->assertEquals($expected, $actual);

        $collection->three = 'Phalcon';
        $expected          = 'Phalcon';
        $actual            = $collection->get('three');
        $I->assertEquals($expected, $actual);

        $collection->offsetSet('three', 123);
        $expected = 123;
        $actual   = $collection->get('three');
        $I->assertEquals($expected, $actual);

        $collection['three'] = true;
        $actual              = $collection->get('three');
        $I->assertTrue($actual);
    }
}
