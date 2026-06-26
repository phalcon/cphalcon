<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 *
 * Implementation of this file has been influenced by sinbadxiii/cphalcon-auth
 * @link    https://github.com/sinbadxiii/cphalcon-auth
 */

declare(strict_types=1);

namespace Phalcon\Tests\Unit\Auth;

use Phalcon\Auth\Access\Acl;
use Phalcon\Auth\Access\Auth;
use Phalcon\Auth\Access\Guest;
use Phalcon\Auth\Adapter\AdapterLocator;
use Phalcon\Auth\Adapter\Memory;
use Phalcon\Auth\Exception;
use Phalcon\Auth\Guard\GuardLocator;
use Phalcon\Auth\Guard\Session;
use Phalcon\Auth\Guard\Token;
use Phalcon\Auth\ManagerFactory;
use Phalcon\Config\Config;
use Phalcon\Container\Container;
use Phalcon\Container\Exceptions\Exception as ContainerException;
use Phalcon\Encryption\Security;
use Phalcon\Http\RequestInterface;
use Phalcon\Http\Response\CookiesInterface;
use Phalcon\Session\ManagerInterface as SessionManagerInterface;
use Phalcon\Tests\AbstractUnitTestCase;
use Phalcon\Tests\Unit\Auth\Fake\FakeCookies;
use Phalcon\Tests\Unit\Auth\Fake\FakeRequest;
use Phalcon\Tests\Unit\Auth\Fake\FakeSessionManager;

final class ManagerFactoryTest extends AbstractUnitTestCase
{
    private Container $container;
    private Security $security;

    protected function setUp(): void
    {
        $this->security  = new Security();
        $this->container = new Container();

        $request = new FakeRequest();
        $cookies = new FakeCookies();
        $session = new FakeSessionManager();

        $this->container->set(RequestInterface::class, fn () => $request);
        $this->container->set(CookiesInterface::class, fn () => $cookies);
        $this->container->set(SessionManagerInterface::class, fn () => $session);
    }

    public function testLoadAcceptsConfigInterface(): void
    {
        $config  = new Config($this->singleSessionConfig());
        $factory = new ManagerFactory($this->security, $this->container);
        $manager = $factory->load($config);

        $this->assertInstanceOf(Session::class, $manager->getDefaultGuard());
    }

    public function testLoadFallsBackToEmptyUsersWhenNonArrayProvided(): void
    {
        $factory = new ManagerFactory($this->security, $this->container);
        $manager = $factory->load([
            'guards' => [
                'web' => [
                    'type'    => 'session',
                    'default' => true,
                    'adapter' => [
                        'name'    => 'memory',
                        'options' => ['users' => 'not-an-array'],
                    ],
                    'options' => [],
                ],
            ],
        ]);

        $this->assertInstanceOf(Session::class, $manager->getDefaultGuard());
    }

    public function testLoadIgnoresMissingAccess(): void
    {
        $factory = new ManagerFactory($this->security, $this->container);
        $manager = $factory->load($this->singleSessionConfig());

        $this->assertSame(
            [
                'acl'   => Acl::class,
                'auth'  => Auth::class,
                'guest' => Guest::class,
            ],
            $manager->getAccessList()
        );
    }

    public function testLoadSetsAccessListWhenProvided(): void
    {
        $config           = $this->singleSessionConfig();
        $config['access'] = [
            'auth' => Auth::class,
        ];

        $factory = new ManagerFactory($this->security, $this->container);
        $manager = $factory->load($config);

        $this->assertArrayHasKey('auth', $manager->getAccessList());
        $this->assertSame(Auth::class, $manager->getAccessList()['auth']);
    }

    public function testLoadThrowsForMissingAdapter(): void
    {
        $this->expectException(Exception::class);
        $this->expectExceptionMessageMatches("/requires 'adapter'/");

        $factory = new ManagerFactory($this->security, $this->container);
        $factory->load([
            'guards' => [
                'web' => [
                    'type' => 'session',
                ],
            ],
        ]);
    }

    public function testLoadThrowsForMissingAdapterName(): void
    {
        $this->expectException(Exception::class);
        $this->expectExceptionMessageMatches("/requires 'name'/");

        $factory = new ManagerFactory($this->security, $this->container);
        $factory->load([
            'guards' => [
                'web' => [
                    'type'    => 'session',
                    'adapter' => ['options' => []],
                ],
            ],
        ]);
    }

    public function testLoadThrowsForMissingGuardType(): void
    {
        $this->expectException(Exception::class);
        $this->expectExceptionMessageMatches("/requires 'type'/");

        $factory = new ManagerFactory($this->security, $this->container);
        $factory->load([
            'guards' => [
                'web' => [
                    'adapter' => ['name' => 'memory', 'options' => []],
                ],
            ],
        ]);
    }

    public function testLoadThrowsForUnknownAdapter(): void
    {
        $this->expectException(Exception::class);
        $this->expectExceptionMessageMatches('/Unknown auth adapter/');

        $factory = new ManagerFactory($this->security, $this->container);
        $factory->load([
            'guards' => [
                'web' => [
                    'type'    => 'session',
                    'adapter' => ['name' => 'no-such-adapter', 'options' => []],
                ],
            ],
        ]);
    }

    public function testLoadThrowsForUnknownGuard(): void
    {
        $this->expectException(Exception::class);
        $this->expectExceptionMessageMatches('/Unknown auth guard/');

        $factory = new ManagerFactory($this->security, $this->container);
        $factory->load([
            'guards' => [
                'web' => [
                    'type'    => 'no-such-guard',
                    'adapter' => ['name' => 'memory', 'options' => []],
                ],
            ],
        ]);
    }

    public function testLoadThrowsWhenModelMissingModelClass(): void
    {
        $this->expectException(Exception::class);

        $factory = new ManagerFactory($this->security, $this->container);
        $factory->load([
            'guards' => [
                'web' => [
                    'type'    => 'session',
                    'adapter' => ['name' => 'model', 'options' => []],
                ],
            ],
        ]);
    }

    public function testLoadThrowsWhenSessionDepsMissingFromContainer(): void
    {
        $this->expectException(ContainerException::class);
        $this->expectExceptionMessageMatches('/RequestInterface/');

        $emptyContainer = new Container();

        $factory = new ManagerFactory($this->security, $emptyContainer);
        $factory->load($this->singleSessionConfig());
    }

    public function testLoadThrowsWhenStreamMissingFile(): void
    {
        $this->expectException(Exception::class);

        $factory = new ManagerFactory($this->security, $this->container);
        $factory->load([
            'guards' => [
                'web' => [
                    'type'    => 'session',
                    'adapter' => ['name' => 'stream', 'options' => []],
                ],
            ],
        ]);
    }

    public function testLoadThrowsWhenTokenGuardDepsMissingFromContainer(): void
    {
        $this->expectException(ContainerException::class);

        $emptyContainer = new Container();

        $factory = new ManagerFactory($this->security, $emptyContainer);
        $factory->load([
            'guards' => [
                'api' => [
                    'type'    => 'token',
                    'adapter' => ['name' => 'memory', 'options' => []],
                    'options' => [
                        'inputKey'   => 'api_token',
                        'storageKey' => 'api_token',
                    ],
                ],
            ],
        ]);
    }

    public function testLoadThrowsWhenTokenGuardMissingKeys(): void
    {
        $this->expectException(Exception::class);

        $factory = new ManagerFactory($this->security, $this->container);
        $factory->load([
            'guards' => [
                'api' => [
                    'type'    => 'token',
                    'adapter' => ['name' => 'memory', 'options' => []],
                    'options' => [],
                ],
            ],
        ]);
    }

    public function testLoadUsesCallerProvidedAdapterLocator(): void
    {
        $adapterLocator = new AdapterLocator($this->container);
        $adapterLocator->register('aliased_memory', Memory::class);

        $factory = new ManagerFactory(
            $this->security,
            $this->container,
            adapterLocator: $adapterLocator,
        );

        $config = $this->singleSessionConfig();
        $config['guards']['web']['adapter']['name'] = 'aliased_memory';

        $manager = $factory->load($config);

        $guard = $manager->getDefaultGuard();
        $this->assertInstanceOf(Session::class, $guard);
        $this->assertInstanceOf(Memory::class, $guard->getAdapter());
    }

    public function testLoadUsesCallerProvidedGuardLocator(): void
    {
        $guardLocator = new GuardLocator($this->container);
        $guardLocator->register('aliased_session', Session::class);

        $factory = new ManagerFactory(
            $this->security,
            $this->container,
            guardLocator: $guardLocator,
        );

        $config = $this->singleSessionConfig();
        $config['guards']['web']['type'] = 'aliased_session';

        $manager = $factory->load($config);

        $this->assertInstanceOf(Session::class, $manager->getDefaultGuard());
    }

    public function testLoadWithModelAdapter(): void
    {
        $factory = new ManagerFactory($this->security, $this->container);
        $manager = $factory->load([
            'guards' => [
                'web' => [
                    'type'    => 'session',
                    'default' => true,
                    'adapter' => [
                        'name'    => 'model',
                        'options' => ['model' => 'App\\Models\\User'],
                    ],
                    'options' => [],
                ],
            ],
        ]);

        $this->assertInstanceOf(Session::class, $manager->getDefaultGuard());
    }

    public function testLoadWithMultipleGuards(): void
    {
        $config = [
            'guards' => [
                'web' => [
                    'type'    => 'session',
                    'default' => true,
                    'adapter' => [
                        'name'    => 'memory',
                        'options' => [
                            'users' => [
                                [
                                    'id'       => 1,
                                    'email'    => 'alice@example.com',
                                    'password' => $this->security->hash('secret'),
                                ],
                            ],
                        ],
                    ],
                    'options' => [],
                ],
                'api' => [
                    'type'    => 'token',
                    'adapter' => [
                        'name'    => 'memory',
                        'options' => [
                            'users' => [
                                [
                                    'id'        => 2,
                                    'email'     => 'bob@example.com',
                                    'password'  => $this->security->hash('token123'),
                                    'api_token' => 'mytoken',
                                ],
                            ],
                        ],
                    ],
                    'options' => [
                        'inputKey'   => 'api_token',
                        'storageKey' => 'api_token',
                    ],
                ],
            ],
        ];

        $factory = new ManagerFactory($this->security, $this->container);
        $manager = $factory->load($config);

        $guards = $manager->getGuards();

        $this->assertArrayHasKey('web', $guards);
        $this->assertArrayHasKey('api', $guards);
        $this->assertInstanceOf(Session::class, $manager->getDefaultGuard());
    }

    public function testLoadWithSingleSessionGuard(): void
    {
        $factory = new ManagerFactory($this->security, $this->container);
        $manager = $factory->load($this->singleSessionConfig());

        $this->assertInstanceOf(Session::class, $manager->getDefaultGuard());
    }

    public function testLoadWithStreamAdapter(): void
    {
        $factory = new ManagerFactory($this->security, $this->container);
        $manager = $factory->load([
            'guards' => [
                'web' => [
                    'type'    => 'session',
                    'default' => true,
                    'adapter' => [
                        'name'    => 'stream',
                        'options' => ['file' => '/tmp/users.json'],
                    ],
                    'options' => [],
                ],
            ],
        ]);

        $this->assertInstanceOf(Session::class, $manager->getDefaultGuard());
    }

    public function testLoadWithTokenGuard(): void
    {
        $factory = new ManagerFactory($this->security, $this->container);
        $manager = $factory->load([
            'guards' => [
                'api' => [
                    'type'    => 'token',
                    'default' => true,
                    'adapter' => [
                        'name'    => 'memory',
                        'options' => ['users' => []],
                    ],
                    'options' => [
                        'inputKey'   => 'api_token',
                        'storageKey' => 'api_token',
                    ],
                ],
            ],
        ]);

        $this->assertInstanceOf(Token::class, $manager->getDefaultGuard());
    }

    private function singleSessionConfig(): array
    {
        return [
            'guards' => [
                'web' => [
                    'type'    => 'session',
                    'default' => true,
                    'adapter' => [
                        'name'    => 'memory',
                        'options' => [
                            'users' => [
                                [
                                    'id'       => 1,
                                    'email'    => 'alice@example.com',
                                    'password' => $this->security->hash('secret'),
                                ],
                            ],
                        ],
                    ],
                    'options' => [],
                ],
            ],
        ];
    }
}
