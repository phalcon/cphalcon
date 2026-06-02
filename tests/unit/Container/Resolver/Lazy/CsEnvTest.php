<?php

declare(strict_types=1);

namespace Phalcon\Tests\Unit\Container\Resolver\Lazy;

use Phalcon\Container\Exceptions\EnvNotDefined;
use Phalcon\Container\Resolver\Lazy\CsEnv;
use Phalcon\Tests\AbstractUnitTestCase;
use Phalcon\Tests\Unit\Container\Resolver\Fake\FakeNameContainer;
use stdClass;

final class CsEnvTest extends AbstractUnitTestCase
{
    protected function setUp(): void
    {
        parent::setUp();
        unset($_ENV['PHALCON_TEST_CSV_VAR']);
    }

    protected function tearDown(): void
    {
        parent::tearDown();
        unset($_ENV['PHALCON_TEST_CSV_VAR']);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-04-18
     */
    public function testContainerResolverLazyCsEnvResolveCastsToFloat(): void
    {
        $_ENV['PHALCON_TEST_CSV_VAR'] = '1.1,2.2,3.3';

        $container = new FakeNameContainer();
        $lazy      = new CsEnv('PHALCON_TEST_CSV_VAR', 'float');
        $result    = $lazy->resolve($container);

        $this->assertSame([1.1, 2.2, 3.3], $result);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-04-18
     */
    public function testContainerResolverLazyCsEnvResolveCastsToInt(): void
    {
        $_ENV['PHALCON_TEST_CSV_VAR'] = '1,2,3';

        $container = new FakeNameContainer();
        $lazy      = new CsEnv('PHALCON_TEST_CSV_VAR', 'int');
        $result    = $lazy->resolve($container);

        $this->assertSame([1, 2, 3], $result);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-04-18
     */
    public function testContainerResolverLazyCsEnvResolveHandlesQuotedValues(): void
    {
        $_ENV['PHALCON_TEST_CSV_VAR'] = '"hello world",foo,"bar"';

        $container = new FakeNameContainer();
        $lazy      = new CsEnv('PHALCON_TEST_CSV_VAR');
        $result    = $lazy->resolve($container);
        $this->assertSame(['hello world', 'foo', 'bar'], $result);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-04-18
     */
    public function testContainerResolverLazyCsEnvResolveParsesCSV(): void
    {
        $_ENV['PHALCON_TEST_CSV_VAR'] = 'a,b,c';

        $container = new FakeNameContainer();
        $lazy      = new CsEnv('PHALCON_TEST_CSV_VAR');
        $result    = $lazy->resolve($container);

        $this->assertSame(['a', 'b', 'c'], $result);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-04-18
     */
    public function testContainerResolverLazyCsEnvResolveReturnsSingleElement(): void
    {
        $_ENV['PHALCON_TEST_CSV_VAR'] = 'onlyone';

        $container = new FakeNameContainer();
        $lazy      = new CsEnv('PHALCON_TEST_CSV_VAR');
        $result    = $lazy->resolve($container);

        $this->assertSame(['onlyone'], $result);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-04-18
     */
    public function testContainerResolverLazyCsEnvResolveThrowsNotFoundForMissingVar(): void
    {
        $container = new FakeNameContainer();
        $lazy      = new CsEnv('PHALCON_UNDEFINED_CSV_ENV_VAR_XYZ');

        $this->expectException(EnvNotDefined::class);
        $this->expectExceptionMessage(
            "Environment variable 'PHALCON_UNDEFINED_CSV_ENV_VAR_XYZ' is not defined"
        );

        $lazy->resolve($container);
    }
}
