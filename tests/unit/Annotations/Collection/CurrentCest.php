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

class CurrentCest
{
    /**
     * Tests Phalcon\Annotations\Collection :: current()
     *
     * @author Jeremy PASTOURET <https://github.com/jenovateurs>
     * @since  2020-01-27
     */
    public function annotationsCollectionCurrent(UnitTester $I)
    {
        $I->wantToTest('Annotations\Collection - current()');

        $collection = new Collection();

        $I->assertFalse($collection->current());
    }

    /**
     * Tests Phalcon\Annotations\Collection :: current() with annotations
     *
     * @author Jeremy PASTOURET <https://github.com/jenovateurs>
     * @since  2020-01-27
     */
    public function annotationsCollectionCurrentWithAnnotations(UnitTester $I)
    {
        $I->wantToTest('Annotations\Collection - current() with annotations');

        $dataAnnotation = [
            'name' => 'NovAnnotation',
        ];

        $dataAnnotation1 = [
            'name' => 'NovAnnotation1',
        ];

        $reflectionData = [
            $dataAnnotation,
            $dataAnnotation1,
        ];

        $collection = new Collection($reflectionData);
        $annotation = new Annotation($dataAnnotation);

        $I->assertEquals($annotation, $collection->current());
    }
}
