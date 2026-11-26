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

namespace Phalcon\Tests\Unit\Auth;

use Phalcon\Auth\Adapter\Config\MemoryAdapterConfig;
use Phalcon\Auth\Adapter\Memory;
use Phalcon\Auth\Exceptions\ConfigRequiresNonEmptyValue;
use Phalcon\Auth\Guard\Config\SessionGuardConfig;
use Phalcon\Auth\Guard\Session;
use Phalcon\Auth\Guard\UserRemember;
use Phalcon\Encryption\Security;
use Phalcon\Talon\PHPUnit\AbstractUnitTestCase;
use Phalcon\Tests\Unit\Auth\Fake\FakeCookies;
use Phalcon\Tests\Unit\Auth\Fake\FakeRequest;
use Phalcon\Tests\Unit\Auth\Fake\FakeSessionManager;
use PHPUnit\Framework\Attributes\DataProvider;
use stdClass;
use TypeError;

/**
 * cphalcon accepts a value of any type for these parameters. The method body
 * examines the value.
 *
 * @issue https://github.com/phalcon/phalcon/issues/848
 */
final class ParameterTypesTest extends AbstractUnitTestCase
{
    /**
     * @return array<string, array{0: mixed}>
     */
    public static function getAssertValues(): array
    {
        return [
            'null'   => [null],
            'int'    => [5],
            'array'  => [['a']],
            'object' => [new stdClass()],
        ];
    }

    /**
     * @return array<string, array{0: mixed}>
     */
    public static function getRememberValues(): array
    {
        return [
            'null'   => [null],
            'int'    => [5],
            'object' => [new stdClass()],
        ];
    }

    /**
     * @issue  https://github.com/phalcon/phalcon/issues/848
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-11-25
     */
    #[DataProvider('getAssertValues')]
    public function testAuthConfigRequiresNonEmptyValueAssert(mixed $value): void
    {
        ConfigRequiresNonEmptyValue::assert($value, 'Guard', 'name');

        $this->expectException(ConfigRequiresNonEmptyValue::class);
        $this->expectExceptionMessage("Guard requires a non-empty 'name'");

        ConfigRequiresNonEmptyValue::assert('', 'Guard', 'name');
    }

    /**
     * @issue  https://github.com/phalcon/phalcon/issues/848
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-11-25
     */
    public function testAuthGuardHasValidCredentials(): void
    {
        $guard = new class (
            $this->getAdapter(),
            new FakeRequest(),
            new FakeCookies(),
            new FakeSessionManager()
        ) extends Session {
            public function call(mixed $user): bool
            {
                return $this->hasValidCredentials($user, ['password' => 'secret']);
            }
        };

        $this->assertFalse($guard->call(null));

        $this->expectException(TypeError::class);
        $this->expectExceptionMessage(
            'validateCredentials(): Argument #1 ($user) must be of type '
            . 'Phalcon\\Contracts\\Auth\\AuthUser, string given'
        );

        $guard->call('x');
    }

    /**
     * @issue  https://github.com/phalcon/phalcon/issues/848
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-11-25
     */
    public function testAuthGuardSessionNullConfig(): void
    {
        $guard = new Session(
            $this->getAdapter(),
            new FakeRequest(),
            new FakeCookies(),
            new FakeSessionManager(),
            null
        );

        $this->assertInstanceOf(SessionGuardConfig::class, $guard->getConfig());
        $this->assertSame('auth', $guard->getName());
    }

    /**
     * @issue  https://github.com/phalcon/phalcon/issues/848
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-11-25
     */
    #[DataProvider('getRememberValues')]
    public function testAuthGuardUserRemember(mixed $payload): void
    {
        $this->expectException(TypeError::class);
        $this->expectExceptionMessage("The parameter must be 'array' or 'string'");

        new UserRemember($payload);
    }

    private function getAdapter(): Memory
    {
        $security = new Security();

        return new Memory(
            $security,
            new MemoryAdapterConfig([
                [
                    'id'       => 1,
                    'email'    => 'alice@example.com',
                    'password' => $security->hash('secret'),
                ],
            ])
        );
    }
}
