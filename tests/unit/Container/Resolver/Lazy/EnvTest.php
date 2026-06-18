<?php

declare(strict_types=1);

namespace Phalcon\Tests\Unit\Container\Resolver\Lazy;

use Phalcon\Container\Exceptions\EnvNotDefined;
use Phalcon\Container\Resolver\Lazy\Env;
use Phalcon\Tests\AbstractUnitTestCase;
use Phalcon\Tests\Unit\Container\Resolver\Fake\FakeNameContainer;
use PHPUnit\Framework\Attributes\BackupGlobals;
use stdClass;

#[BackupGlobals(true)]
final class EnvTest extends AbstractUnitTestCase
{
    protected function setUp(): void
    {
        parent::setUp();
        unset($_ENV['PHALCON_TEST_VAR']);
    }

    protected function tearDown(): void
    {
        parent::tearDown();
        unset($_ENV['PHALCON_TEST_VAR']);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-04-18
     */
    public function testContainerResolverLazyEnvResolveCastsToBool(): void
    {
        $_ENV['PHALCON_TEST_VAR'] = '1';

        $container = new FakeNameContainer();
        $lazy      = new Env('PHALCON_TEST_VAR', 'bool');
        $result    = $lazy->resolve($container);
        $this->assertTrue($result);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-04-18
     */
    public function testContainerResolverLazyEnvResolveCastsToFloat(): void
    {
        $_ENV['PHALCON_TEST_VAR'] = '3.14';

        $container = new FakeNameContainer();
        $lazy      = new Env('PHALCON_TEST_VAR', 'float');
        $result    = $lazy->resolve($container);
        $this->assertSame(3.14, $result);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-04-18
     */
    public function testContainerResolverLazyEnvResolveCastsToInt(): void
    {
        $_ENV['PHALCON_TEST_VAR'] = '42';

        $container = new FakeNameContainer();
        $lazy      = new Env('PHALCON_TEST_VAR', 'int');
        $result    = $lazy->resolve($container);
        $this->assertSame(42, $result);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-04-18
     */
    public function testContainerResolverLazyEnvResolveNoTypecastReturnsString(): void
    {
        $_ENV['PHALCON_TEST_VAR'] = '99';

        $container = new FakeNameContainer();
        $lazy      = new Env('PHALCON_TEST_VAR');
        $result    = $lazy->resolve($container);
        $this->assertIsString($result);
        $this->assertSame('99', $result);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-04-18
     */
    public function testContainerResolverLazyEnvResolveReturnsEnvValue(): void
    {
        $_ENV['PHALCON_TEST_VAR'] = 'hello';

        $container = new FakeNameContainer();
        $lazy      = new Env('PHALCON_TEST_VAR');
        $result    = $lazy->resolve($container);
        $this->assertSame('hello', $result);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-04-18
     */
    public function testContainerResolverLazyEnvResolveThrowsNotFoundForMissingVar(): void
    {
        $container = new FakeNameContainer();
        $lazy      = new Env('PHALCON_UNDEFINED_ENV_VAR_XYZ');

        $this->expectException(EnvNotDefined::class);
        $this->expectExceptionMessage(
            "Environment variable 'PHALCON_UNDEFINED_ENV_VAR_XYZ' is not defined"
        );

        $lazy->resolve($container);
    }
}
