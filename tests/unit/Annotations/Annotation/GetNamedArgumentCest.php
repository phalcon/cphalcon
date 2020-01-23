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

class GetNamedArgumentCest
{
    private $PHANNOT_T_ARRAY = 308;
    private $PHANNOT_T_STRING = 303;
    /**
     * Tests Phalcon\Annotations\Annotation :: getNamedArgument()
     *
     * @author Jeremy PASTOURET <https://github.com/jenovateurs>
     * @since  2020-01-22
     */
    public function annotationsAnnotationGetNamedArgument(UnitTester $I)
    {
        $I->wantToTest('Annotations\Annotation - getNamedArgument()');

        $sValue = 'test';
        $sValue1 = 'test1';
        $sValue2 = 'test2';

        $aOneExpr = [
            'type'  => $this->PHANNOT_T_STRING,
            'value' => $sValue
        ];

        $aTwoExpr = [
            'type'  => $this->PHANNOT_T_STRING,
            'value' => $sValue1
        ];

        $aThreeExpr = [
            'type'  => $this->PHANNOT_T_STRING,
            'value' => $sValue2
        ];

        $sName  = 'one_item';
        $sName1 = 'two_item';
        $sName2 = 'three_item';
        
        $sExprName  = 'first_argument';
        $sExprName1 = 'second_argument';

        $oAnnotation = new Annotation([
            'name'       => 'NovAnnotation',
            'arguments'  => [
                [
                    'name' => $sExprName,
                    'expr' => [
                        'type'  => $this->PHANNOT_T_ARRAY,
                        'items' => [
                            [
                                'name' => $sName,
                                'expr' => $aOneExpr
                            ],
                            [
                                'name' => $sName1,
                                'expr' => $aTwoExpr
                            ]
                        ]
                    ]
                ],
                [
                    'name' => $sExprName1,
                    'expr' => [
                        'type'  => $this->PHANNOT_T_ARRAY,
                        'items' => [
                            [
                                'name' => $sName2,
                                'expr' => $aThreeExpr
                            ]
                        ]
                    ]
                ]
            ]
        ]);

        $aResult = [
            $sName  => $sValue,
            $sName1 => $sValue1
        ];

        $I->assertEquals($oAnnotation->getNamedArgument($sExprName), $aResult);

        $aResult1 = [
            $sName2  => $sValue2
        ];
        
        $I->assertEquals($oAnnotation->getNamedArgument($sExprName1), $aResult1);
    }
}
