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

class ValidCest
{
    /**
     * Tests Phalcon\Annotations\Collection :: valid()
     *
     * @author Jeremy PASTOURET <https://github.com/jenovateurs>
     * @since  2020-01-31
     */
    public function annotationsCollectionValid(UnitTester $I)
    {
        $I->wantToTest('Annotations\Collection - valid()');

        $dataAnnotation = [
            'name' => 'NovAnnotation',
        ];

        $dataAnnotation1 = [
            'name' => 'Phalconatation',
        ];

        $reflectionData = [
            $dataAnnotation,
            $dataAnnotation1,
        ];

        $collection = new Collection($reflectionData);

        $actual = $collection->valid();
        $I->assertTrue($actual);

        $collection->next();

        $actual = $collection->valid();
        $I->assertTrue($actual);

        $collection->next();

        $actual = $collection->valid();
        $I->assertFalse($actual);
    }
}
