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

namespace Phalcon\Test\Unit\Annotations\Collection;

use Phalcon\Annotations\Collection;
use UnitTester;

class KeyNextRewindCest
{
    /**
     * Tests Phalcon\Annotations\Collection :: key()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2002-02-21
     */
    public function annotationsCollectionKey(UnitTester $I)
    {
        $I->wantToTest('Annotations\Collection - key()');

        $reflectionData = [
            [
                'name' => 'Annotation-one',
            ],
            [
                'name' => 'Annotation-two',
            ],
        ];

        $collection = new Collection($reflectionData);

        $I->assertTrue($collection->has('Annotation-one'));
        $I->assertEquals(0, $collection->key());

        $collection->next();
        $I->assertEquals(1, $collection->key());

        $collection->rewind();
        $I->assertEquals(0, $collection->key());
    }
}
