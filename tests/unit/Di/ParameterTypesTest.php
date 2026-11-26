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

namespace Phalcon\Tests\Unit\Di;

use Phalcon\Di\Di;
use Phalcon\Di\Exceptions\AliasNameMustBeString;
use Phalcon\Di\Service;
use Phalcon\Di\Service\Builder;
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
     * @return array<string, array{0: mixed}>
     */
    public static function getParameters(): array
    {
        return [
            'null'   => [null],
            'string' => ['x'],
            'object' => [new stdClass()],
        ];
    }

    /**
     * @issue  https://github.com/phalcon/phalcon/issues/849
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-11-25
     */
    #[DataProvider('getParameters')]
    public function testDiServiceBuilderBuild(mixed $parameters): void
    {
        $instance = (new Builder())->build(
            new Di(),
            ['className' => stdClass::class],
            $parameters
        );

        $this->assertInstanceOf(stdClass::class, $instance);
    }

    /**
     * @issue  https://github.com/phalcon/phalcon/issues/849
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-11-25
     */
    #[DataProvider('getParameters')]
    public function testDiServiceResolve(mixed $parameters): void
    {
        $service = new Service(stdClass::class);

        $this->assertInstanceOf(stdClass::class, $service->resolve($parameters));
    }

    /**
     * The aliases are stored only when all of them are valid.
     *
     * @issue  https://github.com/phalcon/phalcon/issues/849
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-11-25
     */
    public function testDiSetAliasMixedList(): void
    {
        $di = new Di();
        $di->set('svc', stdClass::class);

        try {
            $di->setAlias('svc', ['a', 5]);
            $this->fail('An exception is expected');
        } catch (AliasNameMustBeString $ex) {
            $this->assertSame('Alias name must be a string', $ex->getMessage());
        }

        $this->assertFalse($di->has('a'));
    }

    /**
     * @issue  https://github.com/phalcon/phalcon/issues/849
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-11-25
     */
    public function testDiSetAliasNull(): void
    {
        $di = new Di();
        $di->set('svc', stdClass::class);

        $this->expectException(AliasNameMustBeString::class);
        $this->expectExceptionMessage('Alias name must be a string');

        $di->setAlias('svc', null);
    }
}
