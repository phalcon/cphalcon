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

final class GetExpressionResolvedTest extends AbstractUnitTestCase
{
    /**
     * @return array<array-key, array{0: mixed}>
     */
    public static function providerResolvedValues(): array
    {
        return [
            ['a string'],
            [42],
            [1.5],
            [true],
            [false],
            [null],
            [['a' => 1, 'b' => [2, 3]]],
        ];
    }

    /**
     * @dataProvider providerResolvedValues
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-09-20
     */
    public function testGetExpressionReturnsTheResolvedValue(mixed $value): void
    {
        $annotation = new Annotation(['name' => 'Sample']);

        $actual = $annotation->getExpression(
            [
                'type'  => Annotation::T_RESOLVED,
                'value' => $value,
            ]
        );

        $this->assertSame($value, $actual);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-09-20
     */
    public function testTResolvedDoesNotCollideWithTheParserTypes(): void
    {
        $this->assertSame(1000, Annotation::T_RESOLVED);
    }
}
