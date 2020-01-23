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

class HasArgumentCest
{
    private $PHANNOT_T_STRING = 303;
    /**
     * Tests Phalcon\Annotations\Annotation :: hasArgument()
     *
     * @author Jeremy PASTOURET <https://github.com/jenovateurs>
     * @since  2020-01-22
     */
    public function annotationsAnnotationHasArgument(UnitTester $I)
    {
        $I->wantToTest('Annotations\Annotation - hasArgument()');

        $sValue = 'test';
        $sValue1 = 'test1';

        $oAnnotation = new Annotation([
            'name'       => 'NovAnnotation',
            'arguments'  => [
                [
                    'expr' => [
                        'type'  => $this->PHANNOT_T_STRING,
                        'value' => $sValue
                    ]
                ],
                [
                    'expr' => [
                        'type'  => $this->PHANNOT_T_STRING,
                        'value' => $sValue1
                    ]
                ]
            ]
        ]);
        
        $I->assertTrue($oAnnotation->hasArgument(0));

        $I->assertTrue($oAnnotation->hasArgument(1));

        $I->assertFalse($oAnnotation->hasArgument(2));
    }
}
