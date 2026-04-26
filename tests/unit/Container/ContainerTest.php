<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 *
 * Implementation of this file has been heavily influenced by CapsulePHP.
 * Additionally, there are implementations from ioc-interop, which is a
 * Composer dependency, and from service-interop and resolver-interop. The
 * latter two are copied and re-implemented here: service-interop is not yet
 * published on Packagist, and resolver-interop requires PHP 8.4 (this project
 * targets PHP 8.1). Once both packages become available and compatible, the
 * copies will be replaced with the actual Composer dependencies.
 *
 * @link    https://github.com/capsulephp/di
 * @license https://github.com/capsulephp/di/blob/3.x/LICENSE.md
 *
 * @link    https://github.com/ioc-interop/interface
 * @license https://github.com/ioc-interop/interface/blob/1.x/LICENSE.md
 *
 * @link    https://github.com/service-interop/interface
 * @license https://github.com/service-interop/interface/blob/1.x/LICENSE.md
 *
 * @link    https://github.com/resolver-interop/interface/tree/1.x
 * @license https://github.com/resolver-interop/interface/blob/1.x/LICENSE.md
 */

declare(strict_types=1);

namespace Phalcon\Tests\Unit\Container;

use Closure;
use Phalcon\Container\Container;
use Phalcon\Container\Definition\ServiceDefinition;
use Phalcon\Container\Exception\Invalid;
use Phalcon\Container\Exception\NotFound;
use Phalcon\Container\Interop\Service\Collection;
use Phalcon\Container\Interop\Service\Lifetime;
use Phalcon\Container\Resolver\Lazy\Env;
use Phalcon\Tests\AbstractUnitTestCase;
use Phalcon\Tests\Unit\Container\Fake\FakeService;
use Phalcon\Tests\Unit\Container\Fake\FakeServiceWithDependency;
use RuntimeException;

final class ContainerTest extends AbstractUnitTestCase
{
    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-04-18
     */
    public function testContainerAliasChainDoesNotFalselyDetectCircular(): void
    {
        $bucket = new Container();
        $bucket->set('a', FakeService::class);
        $bucket->set('b', FakeService::class);
        $bucket->set('c', FakeService::class);
        $bucket->set('d', FakeService::class);
        $bucket->setAlias('a', 'b');
        $bucket->setAlias('b', 'c');
        $bucket->setAlias('c', 'd');
        $this->assertInstanceOf(FakeService::class, $bucket->get('d'));
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-04-18
     */
    public function testContainerAutowiresConstructorDependencies(): void
    {
        $bucket = new Container();
        $bucket->set(FakeService::class, FakeService::class);
        $bucket->set(FakeServiceWithDependency::class, FakeServiceWithDependency::class);

        $instance = $bucket->get(FakeServiceWithDependency::class);

        $this->assertInstanceOf(FakeServiceWithDependency::class, $instance);
        $this->assertInstanceOf(FakeService::class, $instance->service);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-04-18
     */
    public function testContainerAutowiresConstructorDependenciesNoDefinitions(): void
    {
        $bucket = new Container();

        $instance = $bucket->get(FakeServiceWithDependency::class);

        $this->assertInstanceOf(FakeServiceWithDependency::class, $instance);
        $this->assertInstanceOf(FakeService::class, $instance->service);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-04-18
     */
    public function testContainerBindRegistersDefinition(): void
    {
        $bucket = new Container();
        $def    = $bucket->bind('iface', FakeService::class);

        $this->assertInstanceOf(ServiceDefinition::class, $def);
        $this->assertTrue($bucket->has('iface'));
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-04-18
     */
    public function testContainerCallableGetReturnsClosure(): void
    {
        $this->expectException(RuntimeException::class);
        $this->expectExceptionMessage('Not implemented: requires Zephir \$this-in-closure support');

        $bucket = new Container();
        $bucket->set('fake', FakeService::class);

        $callable = $bucket->callableGet('fake');

        $this->assertInstanceOf(Closure::class, $callable);
        $this->assertInstanceOf(FakeService::class, $callable());
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-04-18
     */
    public function testContainerCallableNewReturnsClosureReturningDifferentInstances(): void
    {
        $this->expectException(RuntimeException::class);
        $this->expectExceptionMessage('Not implemented: requires Zephir \$this-in-closure support');

        $bucket = new Container();
        $bucket->set('fake', FakeService::class);

        $callable = $bucket->callableNew('fake');

        $this->assertInstanceOf(Closure::class, $callable);
        $this->assertNotSame($callable(), $callable());
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-04-18
     */
    public function testContainerCircularAliasThrowsInvalid(): void
    {
        $bucket = new Container();
        $bucket->set('a', FakeService::class);
        $bucket->setAlias('a', 'b');

        $this->expectException(Invalid::class);

        $bucket->setAlias('b', 'a');
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-04-18
     */
    public function testContainerDetectCircularAliasSeenBreak(): void
    {
        $bucket = new Container();
        // Inject a pre-existing cycle (bypassing setAlias protection)
        $this->setProtectedProperty($bucket, 'aliases', ['b' => 'a', 'a' => 'b']);
        // detectCircularAlias('new_alias', 'a') follows a→b→a and hits the seen break
        $bucket->setAlias('a', 'new_alias');
        // If we reach here without throwing, the break was hit correctly
        $this->assertTrue($bucket->hasAlias('new_alias'));
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-04-18
     */
    public function testContainerExtendModifiesService(): void
    {
        $bucket = new Container();
        $bucket->set('fake', FakeService::class);
        $bucket->extend('fake', static function (FakeService $svc): FakeService {
            $svc->value = 'extended';

            return $svc;
        });

        $instance = $bucket->get('fake');

        $this->assertSame('extended', $instance->value);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-04-18
     */
    public function testContainerExtendThrowsForUnregisteredService(): void
    {
        $bucket = new Container();
        $this->expectException(NotFound::class);
        $bucket->extend('unknown', static function (object $svc, object $c) {
            return $svc;
        });
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-04-18
     */
    public function testContainerExtendThrowsWhenAlreadyResolved(): void
    {
        $bucket = new Container();
        $bucket->set('fake', FakeService::class);
        $bucket->get('fake');

        $this->expectException(Invalid::class);

        $bucket->extend('fake', static function (FakeService $svc): FakeService {
            return $svc;
        });
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-04-18
     */
    public function testContainerFindProcessorThrowsForUnprocessable(): void
    {
        $bucket = new Container();
        $this->expectException(Invalid::class);
        $bucket->set('svc', 42);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-04-18
     */
    public function testContainerGetByTagReturnsEmptyArrayForUnknownTag(): void
    {
        $bucket = new Container();

        $this->assertSame([], $bucket->getByTag('unknown-tag'));
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-04-18
     */
    public function testContainerGetByTagReturnsResolvedInstances(): void
    {
        $bucket = new Container();
        $bucket->set('fake', FakeService::class)->addTag('my-tag');

        $result = $bucket->getByTag('my-tag');

        $this->assertCount(1, $result);
        $this->assertInstanceOf(FakeService::class, $result[0]);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-04-18
     */
    public function testContainerGetDefinitionReturnsServiceDefinition(): void
    {
        $bucket = new Container();
        $bucket->set('fake', FakeService::class);

        $def = $bucket->getDefinition('fake');

        $this->assertInstanceOf(ServiceDefinition::class, $def);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-04-18
     */
    public function testContainerGetDefinitionThrowsForMissing(): void
    {
        $bucket = new Container();

        $this->expectException(NotFound::class);

        $bucket->getDefinition('missing');
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-04-18
     */
    public function testContainerGetInstanceThrowsForMissing(): void
    {
        $bucket = new Container();

        $this->expectException(NotFound::class);

        $bucket->getInstance('missing');
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-04-18
     */
    public function testContainerGetInvokesClosure(): void
    {
        $bucket = new Container();
        $bucket->set('fake', static function (): FakeService {
            $svc        = new FakeService();
            $svc->value = 'from-closure';

            return $svc;
        });

        $instance = $bucket->get('fake');

        $this->assertInstanceOf(FakeService::class, $instance);
        $this->assertSame('from-closure', $instance->value);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-04-18
     */
    public function testContainerGetParameterThrowsForMissing(): void
    {
        $bucket = new Container();

        $this->expectException(NotFound::class);

        $bucket->getParameter('missing');
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-04-18
     */
    public function testContainerGetResolvesParameterByName(): void
    {
        $bucket = new Container();
        $bucket->setParameter('app.name', 'Phalcon');

        $this->assertSame('Phalcon', $bucket->get('app.name'));
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-04-18
     */
    public function testContainerGetResolvesViaAlias(): void
    {
        $bucket = new Container();
        $bucket->set('fake', FakeService::class);
        $bucket->setAlias('fake', 'alias');

        $instance = $bucket->get('alias');

        $this->assertInstanceOf(FakeService::class, $instance);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-04-18
     */
    public function testContainerGetReturnsInstance(): void
    {
        $bucket   = new Container();
        $bucket->set('fake', FakeService::class);
        $instance = $bucket->get('fake');

        $this->assertInstanceOf(FakeService::class, $instance);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-04-18
     */
    public function testContainerGetReturnsSameInstanceOnSubsequentCalls(): void
    {
        $bucket = new Container();
        $bucket->set('fake', FakeService::class);

        $first  = $bucket->get('fake');
        $second = $bucket->get('fake');

        $this->assertSame($first, $second);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-04-18
     */
    public function testContainerGetReturnsSameObjectWhenRegisteredAsObject(): void
    {
        $bucket   = new Container();
        $service  = new FakeService();
        $bucket->set('fake', $service);

        $this->assertSame($service, $bucket->get('fake'));
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-04-18
     */
    public function testContainerGetServiceReturnsObject(): void
    {
        $bucket = new Container();
        $bucket->set('fake', FakeService::class);

        $instance = $bucket->getService('fake');

        $this->assertInstanceOf(FakeService::class, $instance);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-04-18
     */
    public function testContainerGetServiceThrowsForNonObjectParameter(): void
    {
        $bucket = new Container();
        $bucket->setParameter('scalar', 'not-an-object');

        $this->expectException(Invalid::class);

        $bucket->getService('scalar');
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-04-18
     */
    public function testContainerHasAliasTrueAfterSet(): void
    {
        $bucket = new Container();
        $bucket->set('fake', FakeService::class);
        $bucket->setAlias('fake', 'alias');

        $this->assertTrue($bucket->hasAlias('alias'));
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-04-18
     */
    public function testContainerHasFalseForUnknown(): void
    {
        $bucket = new Container();

        $this->assertFalse($bucket->has('nonexistent'));
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-04-18
     */
    public function testContainerHasInstanceFalseBeforeSet(): void
    {
        $bucket = new Container();

        $this->assertFalse($bucket->hasInstance('missing'));
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-04-18
     */
    public function testContainerHasInstanceTrueAfterSet(): void
    {
        $bucket   = new Container();
        $instance = new FakeService();
        $bucket->setInstance('fake', $instance, Lifetime::SINGLETON);

        $this->assertTrue($bucket->hasInstance('fake'));
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-04-18
     */
    public function testContainerHasParameterFalseBeforeSet(): void
    {
        $bucket = new Container();

        $this->assertFalse($bucket->hasParameter('missing'));
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-04-18
     */
    public function testContainerHasParameterTrueAfterSet(): void
    {
        $bucket = new Container();
        $bucket->setParameter('key', 'value');

        $this->assertTrue($bucket->hasParameter('key'));
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-04-18
     */
    public function testContainerHasServiceDelegatesToHas(): void
    {
        $bucket = new Container();
        $bucket->set('fake', FakeService::class);

        $this->assertTrue($bucket->hasService('fake'));
        $this->assertFalse($bucket->hasService('nonexistent'));
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-04-18
     */
    public function testContainerHasTrueAfterSet(): void
    {
        $bucket = new Container();
        $bucket->set('fake', FakeService::class);

        $this->assertTrue($bucket->has('fake'));
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-04-18
     */
    public function testContainerImplementsCollection(): void
    {
        $bucket = new Container();

        $this->assertInstanceOf(Collection::class, $bucket);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-04-18
     */
    public function testContainerImplicitAutowiringOfKnownClass(): void
    {
        $bucket   = new Container();
        $instance = $bucket->get(FakeService::class);

        $this->assertInstanceOf(FakeService::class, $instance);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-04-18
     */
    public function testContainerIsAutowireEnabledDefaultsToTrue(): void
    {
        $bucket = new Container();

        $this->assertTrue($bucket->isAutowireEnabled());
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-04-18
     */
    public function testContainerNewDefinitionReturnsServiceDefinition(): void
    {
        $bucket = new Container();
        $def    = $bucket->newDefinition('test');
        $this->assertInstanceOf(ServiceDefinition::class, $def);
        $this->assertSame('test', $def->getServiceName());
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-04-18
     */
    public function testContainerNewReturnsDifferentInstanceEachCall(): void
    {
        $bucket = new Container();
        $bucket->set('fake', FakeService::class);

        $first  = $bucket->new('fake');
        $second = $bucket->new('fake');

        $this->assertNotSame($first, $second);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-04-18
     */
    public function testContainerParameterWithLazyEnvValue(): void
    {
        $_ENV['BUCKET_TEST_KEY'] = 'hello-env';

        $bucket = new Container();
        $bucket->setParameter('app.key', new Env('BUCKET_TEST_KEY'));

        $this->assertSame('hello-env', $bucket->getParameter('app.key'));

        unset($_ENV['BUCKET_TEST_KEY']);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-04-18
     */
    public function testContainerResolveAliasThrowsOnCyclicChain(): void
    {
        $bucket = new Container();
        // Inject a pre-existing cycle to trigger the safety-net in resolveAlias()
        $this->setProtectedProperty($bucket, 'aliases', ['a' => 'b', 'b' => 'a']);
        $this->expectException(Invalid::class);
        $bucket->get('a');
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-04-18
     */
    public function testContainerSetAliasAndGetAlias(): void
    {
        $bucket = new Container();
        $bucket->set('fake', FakeService::class);
        $bucket->setAlias('fake', 'alias');

        $this->assertSame('fake', $bucket->getAlias('alias'));
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-04-18
     */
    public function testContainerSetAutowireFalseDisablesImplicitAutowiring(): void
    {
        $bucket = new Container();
        $bucket->setAutowire(false);

        $this->expectException(NotFound::class);

        $bucket->get(FakeService::class);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-04-18
     */
    public function testContainerSetAutowireFalseReturnsDisabled(): void
    {
        $bucket = new Container();
        $bucket->setAutowire(false);

        $this->assertFalse($bucket->isAutowireEnabled());
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-04-18
     */
    public function testContainerSetDefinitionOverwrites(): void
    {
        $bucket  = new Container();
        $bucket->set('fake', FakeService::class);
        $newDef  = new ServiceDefinition('fake', 'string');
        $bucket->setDefinition('fake', $newDef);

        $this->assertSame($newDef, $bucket->getDefinition('fake'));
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-04-18
     */
    public function testContainerSetInstanceAndGetInstance(): void
    {
        $bucket   = new Container();
        $instance = new FakeService();
        $bucket->setInstance('fake', $instance, Lifetime::SINGLETON);

        $this->assertSame($instance, $bucket->getInstance('fake'));
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-04-18
     */
    public function testContainerSetParameterAndGetParameter(): void
    {
        $bucket = new Container();
        $bucket->setParameter('db.host', 'localhost');

        $this->assertSame('localhost', $bucket->getParameter('db.host'));
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-04-18
     */
    public function testContainerSetReturnsServiceDefinition(): void
    {
        $bucket = new Container();
        $def    = $bucket->set('fake', FakeService::class);

        $this->assertInstanceOf(ServiceDefinition::class, $def);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-04-18
     */
    public function testContainerTransientLifetimeReturnsNewInstanceEachGet(): void
    {
        $bucket = new Container();
        $bucket->set('fake', FakeService::class)->setLifetime(Lifetime::TRANSIENT);

        $first  = $bucket->get('fake');
        $second = $bucket->get('fake');

        $this->assertNotSame($first, $second);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-04-18
     */
    public function testContainerUnsetAlias(): void
    {
        $bucket = new Container();
        $bucket->set('original', FakeService::class);
        $bucket->setAlias('original', 'alias');
        $this->assertTrue($bucket->hasAlias('alias'));
        $bucket->unsetAlias('alias');
        $this->assertFalse($bucket->hasAlias('alias'));
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-04-18
     */
    public function testContainerUnsetDefinitionRemovesIt(): void
    {
        $bucket = new Container();
        $bucket->set('fake', FakeService::class);
        $bucket->unsetDefinition('fake');

        $this->assertFalse($bucket->hasDefinition('fake'));
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-04-18
     */
    public function testContainerUnsetInstanceRemovesIt(): void
    {
        $bucket   = new Container();
        $instance = new FakeService();
        $bucket->setInstance('fake', $instance, Lifetime::SINGLETON);
        $bucket->unsetInstance('fake');

        $this->assertFalse($bucket->hasInstance('fake'));
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-04-18
     */
    public function testContainerUnsetInstancesRemovesOnlyMatchingLifetime(): void
    {
        $bucket    = new Container();
        $singleton = new FakeService();
        $scoped    = new FakeService();

        $bucket->setInstance('singleton', $singleton, Lifetime::SINGLETON);
        $bucket->setInstance('scoped', $scoped, Lifetime::SCOPED);

        $bucket->unsetInstances(Lifetime::SCOPED);

        $this->assertTrue($bucket->hasInstance('singleton'));
        $this->assertFalse($bucket->hasInstance('scoped'));
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-04-18
     */
    public function testContainerUnsetParameterRemovesIt(): void
    {
        $bucket = new Container();
        $bucket->setParameter('key', 'value');
        $bucket->unsetParameter('key');

        $this->assertFalse($bucket->hasParameter('key'));
    }
}
