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

final class GetArgumentsTest extends AbstractUnitTestCase
{
    private int $PHANNOT_T_STRING = 303;

    /**
     * @author Jeremy PASTOURET <https://github.com/jenovateurs>
     * @since  2020-01-22
     */
    public function testAnnotationsAnnotationGetArguments(): void
    {
        $value  = 'test';
        $value1 = 'test1';

        $annotation = new Annotation(
            [
                'name'      => 'NovAnnotation',
                'arguments' => [
                    [
                        'expr' => [
                            'type'  => $this->PHANNOT_T_STRING,
                            'value' => $value,
                        ],
                    ],
                    [
                        'expr' => [
                            'type'  => $this->PHANNOT_T_STRING,
                            'value' => $value1,
                        ],
                    ],
                ],
            ]
        );

        $this->assertEquals([$value, $value1], $annotation->getArguments());
    }
}
