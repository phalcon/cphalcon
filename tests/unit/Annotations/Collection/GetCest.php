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

use Phalcon\Annotations\Annotation;
use Phalcon\Annotations\Collection;
use Phalcon\Annotations\Exception;
use UnitTester;

class GetCest
{
    /**
     * Tests Phalcon\Annotations\Collection :: get()
     *
     * @author Jeremy PASTOURET <https://github.com/jenovateurs>
     * @since  2020-01-27
     */
    public function annotationsCollectionGet(UnitTester $I)
    {
        $I->wantToTest('Annotations\Collection - get()');

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
        $annotation = new Annotation($dataAnnotation1);

        $I->assertEquals($annotation, $collection->get('Phalconatation'));

        //Check what happens if collection doesn't find an annotation
        $I->expectThrowable(
            new Exception('Collection doesn\'t have an annotation called \'NoExist\''),
            function () {
                $collection = new Collection();
                $collection->get('NoExist');
            }
        );
    }
}
