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

namespace Phalcon\Tests\Unit\Annotations\Annotation;

use Phalcon\Annotations\Annotation;
use Phalcon\Talon\PHPUnit\AbstractUnitTestCase;

final class GetNamedParameterTest extends AbstractUnitTestCase
{
    private int $PHANNOT_T_ARRAY  = 308;
    private int $PHANNOT_T_STRING = 303;

    /**
     * @author Jeremy PASTOURET <https://github.com/jenovateurs>
     * @since  2020-01-22
     */
    public function testAnnotationsAnnotationGetNamedParameter(): void
    {
        $value  = 'test';
        $value1 = 'test1';
        $value2 = 'test2';

        $oneExpr   = ['type' => $this->PHANNOT_T_STRING, 'value' => $value];
        $twoExpr   = ['type' => $this->PHANNOT_T_STRING, 'value' => $value1];
        $threeExpr = ['type' => $this->PHANNOT_T_STRING, 'value' => $value2];

        $name      = 'one_item';
        $name1     = 'two_item';
        $name2     = 'three_item';
        $exprName  = 'first_argument';
        $exprName1 = 'second_argument';

        $annotation = new Annotation(
            [
                'name'      => 'NovAnnotation',
                'arguments' => [
                    [
                        'name' => $exprName,
                        'expr' => [
                            'type'  => $this->PHANNOT_T_ARRAY,
                            'items' => [
                                ['name' => $name, 'expr' => $oneExpr],
                                ['name' => $name1, 'expr' => $twoExpr],
                            ],
                        ],
                    ],
                    [
                        'name' => $exprName1,
                        'expr' => [
                            'type'  => $this->PHANNOT_T_ARRAY,
                            'items' => [
                                ['name' => $name2, 'expr' => $threeExpr],
                            ],
                        ],
                    ],
                ],
            ]
        );

        $expected = [$name => $value, $name1 => $value1];
        $this->assertEquals($expected, $annotation->getNamedParameter($exprName));

        $expected1 = [$name2 => $value2];
        $this->assertEquals($expected1, $annotation->getNamedParameter($exprName1));
    }
}
