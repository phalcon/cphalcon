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

class KeyNextRewindCest
{
    /**
     * Tests Phalcon\Annotations\Collection :: key() / next() / rewind()
     *
     * @author Jeremy PASTOURET <https://github.com/jenovateurs>
     * @since  2020-01-31
     */
    public function annotationsCollectionKeyNextRewind(UnitTester $I)
    {
        $I->wantToTest('Annotations\Collection - key() / next() / rewind()');

        $dataAnnotation = [
            'name' => 'NovAnnotation'
        ];

        $dataAnnotation1 = [
            'name' => 'Phalconatation'
        ];

        $reflectionData = [
            $dataAnnotation,
            $dataAnnotation1
        ];

        $collection  = new Collection($reflectionData);
        $annotation  = new Annotation($dataAnnotation);
        $annotation1 = new Annotation($dataAnnotation1);

        $I->assertEquals(0, $collection->key());

        $I->assertEquals($annotation, $collection->current());

        $collection->next();

        $I->assertEquals(1, $collection->key());

        $I->assertEquals($annotation1, $collection->current());

        $collection->rewind();

        $I->assertEquals(0, $collection->key());

        $I->assertEquals($annotation, $collection->current());
    }
}
