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

namespace Phalcon\Tests\Unit\Support\Collection\ReadOnlyCollection;

use Phalcon\Support\Collection\ReadOnlyCollection;
use UnitTester;

class HasCest
{
    /**
     * Tests Phalcon\Support\Collection\ReadOnlyCollection :: has()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function supportCollectionHas(UnitTester $I)
    {
        $I->wantToTest('Support\Collection - has()');

        $data = [
            'one'   => 'two',
            'three' => 'four',
            'five'  => 'six',
        ];

        $collection = new ReadOnlyCollection($data);

        $actual = $collection->has('three');
        $I->assertTrue($actual);

        $actual = $collection->has('THREE');
        $I->assertTrue($actual);

        $actual = $collection->has(uniqid());
        $I->assertFalse($actual);

        $actual = $collection->__isset('three');
        $I->assertTrue($actual);

        $actual = isset($collection['three']);
        $I->assertTrue($actual);

        $actual = isset($collection[uniqid()]);
        $I->assertFalse($actual);

        $actual = $collection->offsetExists('three');
        $I->assertTrue($actual);

        $actual = $collection->offsetExists(uniqid());
        $I->assertFalse($actual);
    }

    /**
     * Tests Phalcon\Support\Collection\ReadOnlyCollection :: has() - sensitive
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function supportCollectionHasSensitive(UnitTester $I)
    {
        $I->wantToTest('Support\Collection - has()');

        $data = [
            'one'   => 'two',
            'three' => 'four',
            'five'  => 'six',
        ];

        $collection = new ReadOnlyCollection($data, false);

        $actual = $collection->has('three');
        $I->assertTrue($actual);

        $actual = $collection->has('THREE');
        $I->assertFalse($actual);

        $actual = $collection->has(uniqid());
        $I->assertFalse($actual);

        $actual = $collection->__isset('three');
        $I->assertTrue($actual);

        $actual = isset($collection['three']);
        $I->assertTrue($actual);

        $actual = isset($collection[uniqid()]);
        $I->assertFalse($actual);

        $actual = $collection->offsetExists('three');
        $I->assertTrue($actual);

        $actual = $collection->offsetExists(uniqid());
        $I->assertFalse($actual);
    }
}
