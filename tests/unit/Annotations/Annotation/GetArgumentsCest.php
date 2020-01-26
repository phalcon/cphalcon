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

namespace Phalcon\Test\Unit\Annotations\Annotation;

use Phalcon\Annotations\Annotation;
use UnitTester;

class GetArgumentsCest
{
    private $PHANNOT_T_STRING = 303;
    /**
     * Tests Phalcon\Annotations\Annotation :: getArguments()
     *
     * @author Jeremy PASTOURET <https://github.com/jenovateurs>
     * @since  2020-01-22
     */
    public function annotationsAnnotationGetArguments(UnitTester $I)
    {
        $I->wantToTest('Annotations\Annotation - getArguments()');

        $value = 'test';
        $value1 = 'test1';

        $annotation = new Annotation([
            'name'       => 'NovAnnotation',
            'arguments'  => [
                [
                    'expr' => [
                        'type'  => $this->PHANNOT_T_STRING,
                        'value' => $value
                    ]
                ],
                [
                    'expr' => [
                        'type'  => $this->PHANNOT_T_STRING,
                        'value' => $value1
                    ]
                ]
            ]
        ]);

        $I->assertEquals([$value, $value1], $annotation->getArguments());
    }
}
