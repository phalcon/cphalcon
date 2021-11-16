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

namespace Phalcon\Tests\Unit\Annotations\Collection;

use Phalcon\Annotations\Collection;
use UnitTester;

class CountCest
{
    /**
     * Tests Phalcon\Annotations\Collection :: count()
     *
     * @author Jeremy PASTOURET <https://github.com/jenovateurs>
     * @since  2020-01-27
     */
    public function annotationsCollectionCount(UnitTester $I)
    {
        $I->wantToTest('Annotations\Collection - count()');

        $reflectionData = [
            [
                'name' => 'NovAnnotation',
            ],
            [
                'name' => 'NovAnnotation1',
            ],
        ];

        $collection = new Collection($reflectionData);

        $I->assertEquals(count($reflectionData), $collection->count());
    }
}
