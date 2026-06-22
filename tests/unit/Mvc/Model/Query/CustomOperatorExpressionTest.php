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

namespace Phalcon\Tests\Unit\Mvc\Model\Query;

use Phalcon\Mvc\Model\Query;
use Phalcon\Tests\AbstractUnitTestCase;
use PHPUnit\Framework\Attributes\DataProvider;
use ReflectionClass;

final class CustomOperatorExpressionTest extends AbstractUnitTestCase
{
    public static function operatorProvider(): array
    {
        return [
            //  token code, expected op string
            [401, '@@'],
            [402, '@>'],
            [403, '<@'],
            [404, '&&'],
            [405, '||'],
            [406, '->'],
            [416, '->>'],
            [417, '#>'],
            [418, '#>>'],
        ];
    }

    #[DataProvider('operatorProvider')]
    public function testGetExpressionCustomOperator(int $code, string $op): void
    {
        $expected = [
            'type'  => 'binary-op',
            'op'    => $op,
            'left'  => null,
            'right' => null,
        ];

        $query         = new Query();
        $reflection    = new ReflectionClass(Query::class);
        $getExpression = $reflection->getMethod('getExpression');

        $this->assertSame(
            $expected,
            $getExpression->invokeArgs($query, [['type' => $code], false])
        );
    }
}
