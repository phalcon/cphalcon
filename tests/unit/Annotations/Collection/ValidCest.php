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

use Phalcon\Annotations\Annotation;
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

        $collection  = new Collection($reflectionData);
        $annotation  = new Annotation($dataAnnotation);
        $annotation1 = new Annotation($dataAnnotation1);

        $I->assertTrue($collection->valid());

        $collection->next();

        $I->assertTrue($collection->valid());

        $collection->next();

        $I->assertFalse($collection->valid());
    }
}
