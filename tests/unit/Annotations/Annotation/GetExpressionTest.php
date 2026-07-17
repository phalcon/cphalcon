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

final class GetExpressionTest extends AbstractUnitTestCase
{
    private int $PHANNOT_T_STRING = 303;

    /**
     * @author Jeremy PASTOURET <https://github.com/jenovateurs>
     * @since  2020-01-22
     */
    public function testAnnotationsAnnotationGetExpression(): void
    {
        $value  = 'test';
        $value1 = 'test1';

        $oneExpr = [
            'type'  => $this->PHANNOT_T_STRING,
            'value' => $value,
        ];

        $twoExpr = [
            'type'  => $this->PHANNOT_T_STRING,
            'value' => $value1,
        ];

        $annotation = new Annotation(
            [
                'name'      => 'NovAnnotation',
                'arguments' => [
                    ['expr' => $oneExpr],
                    ['expr' => $twoExpr],
                ],
            ]
        );

        $this->assertEquals($value, $annotation->getExpression($oneExpr));
        $this->assertEquals($value1, $annotation->getExpression($twoExpr));
    }
}
