<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */

declare(strict_types=1);

namespace Phalcon\Tests\Unit\Container\Resolver\Lazy;

use Exception;
use Phalcon\Container\Resolver\Lazy\ArrayValues;
use Phalcon\Container\Resolver\Lazy\CallableGet;
use Phalcon\Container\Resolver\Lazy\CallableNew;
use Phalcon\Container\Resolver\Lazy\Get;
use Phalcon\Container\Resolver\Lazy\NewInstance;
use Phalcon\Talon\PHPUnit\AbstractUnitTestCase;
use PHPUnit\Framework\Attributes\DataProvider;
use stdClass;

/**
 * cphalcon accepts a value of any type for these parameters. The method body
 * examines the value.
 *
 * @issue https://github.com/phalcon/phalcon/issues/849
 */
final class ParameterTypesTest extends AbstractUnitTestCase
{
    /**
     * @return array<string, array{0: class-string, 1: mixed, 2: string}>
     */
    public static function getLazyIds(): array
    {
        return [
            'Get null'          => [Get::class, null, 'get:NULL'],
            'Get int'           => [Get::class, 5, 'get:5'],
            'CallableGet null'  => [CallableGet::class, null, 'get:NULL'],
            'CallableGet int'   => [CallableGet::class, 5, 'get:5'],
            'CallableNew null'  => [CallableNew::class, null, 'new:NULL'],
            'CallableNew int'   => [CallableNew::class, 5, 'new:5'],
            'NewInstance null'  => [NewInstance::class, null, 'new:NULL'],
            'NewInstance int'   => [NewInstance::class, 5, 'new:5'],
        ];
    }

    /**
     * @issue  https://github.com/phalcon/phalcon/issues/849
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-11-25
     */
    public function testContainerResolverLazyArrayValuesMergeNull(): void
    {
        $this->expectException(Exception::class);
        $this->expectExceptionMessage('The argument is not initialized or iterable()');

        (new ArrayValues())->merge(null);
    }

    /**
     * @issue  https://github.com/phalcon/phalcon/issues/849
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-11-25
     */
    public function testContainerResolverLazyArrayValuesMergeString(): void
    {
        $values = new ArrayValues(['z' => 0]);
        $values->merge('xy');
        $values->merge('');

        $this->assertSame(
            ['z' => 0, 0 => 'x', 1 => 'y'],
            $values->resolve(new stdClass())
        );
    }

    /**
     * @issue  https://github.com/phalcon/phalcon/issues/849
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-11-25
     *
     * @param class-string $class
     */
    #[DataProvider('getLazyIds')]
    public function testContainerResolverLazyId(string $class, mixed $id, string $expected): void
    {
        $ioc = new class () {
            public function get(mixed $name): string
            {
                return 'get:' . var_export($name, true);
            }

            public function new(mixed $name): string
            {
                return 'new:' . var_export($name, true);
            }
        };

        $result = (new $class($id))->resolve($ioc);
        if (is_callable($result)) {
            $result = $result();
        }

        $this->assertSame($expected, $result);
    }
}
