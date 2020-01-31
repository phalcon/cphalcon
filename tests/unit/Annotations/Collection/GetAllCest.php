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
use Phalcon\Annotations\Annotation;
use UnitTester;

class GetAllCest
{
    /**
     * Tests Phalcon\Annotations\Collection :: getAll()
     *
     * @author Jeremy PASTOURET <https://github.com/jenovateurs>
     * @since  2020-01-27
     */
    public function annotationsCollectionGetAll(UnitTester $I)
    {
        $I->wantToTest('Annotations\Collection - getAll()');

        $dataAnnotation = [
            'name' => 'NovAnnotation'
        ];

        $dataAnnotation1 = [
            'name' => 'NovAnnotation1'
        ];

        $dataAnnotation2 = [
            'name' => 'NovAnnotation'
        ];

        $reflectionData = [
            $dataAnnotation,
            $dataAnnotation1,
            $dataAnnotation2
        ];

        $collection = new Collection($reflectionData);

        $annotation  = new Annotation($dataAnnotation);
        $annotation2 = new Annotation($dataAnnotation2);

        $resultAnnotation = [
            $annotation,
            $annotation2
        ];

        //Check the result if the annotation doesn't exist
        $I->assertEmpty($collection->getAll('Phalconatation'));

        //Need to find two annotations with the name NovAnnotation
        $I->assertEquals($resultAnnotation, $collection->getAll('NovAnnotation'));
    }
}
