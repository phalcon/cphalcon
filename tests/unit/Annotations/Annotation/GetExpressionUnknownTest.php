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
use Phalcon\Annotations\Exceptions\UnknownAnnotationExpression;
use Phalcon\Talon\PHPUnit\AbstractUnitTestCase;

final class GetExpressionUnknownTest extends AbstractUnitTestCase
{
    /**
     * The parser never gives a type code that is not in the list, so the
     * expression comes from a hand built node here.
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-09-19
     */
    public function testAnnotationsAnnotationGetExpressionUnknownType(): void
    {
        $this->expectException(UnknownAnnotationExpression::class);
        $this->expectExceptionMessage('The expression 999 is unknown');

        new Annotation(
            [
                'name'      => 'Unknown',
                'arguments' => [
                    ['expr' => ['type' => 999]],
                ],
            ]
        );
    }
}
