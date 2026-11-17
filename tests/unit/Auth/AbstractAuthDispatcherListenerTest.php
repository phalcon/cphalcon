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

use Error;
use Phalcon\Auth\Access\AccessLocator;
use Phalcon\Auth\Manager;
use Phalcon\Container\Container;
use Phalcon\Talon\PHPUnit\AbstractUnitTestCase;
use Phalcon\Tests\Unit\Auth\Fake\FakeForwardListener;
use Phalcon\Tests\Unit\Auth\Fake\FakeGuard;
use Phalcon\Tests\Unit\Auth\Fake\FakeRedirectAccess;
use PHPUnit\Framework\Attributes\DataProvider;
use stdClass;
use Throwable;

final class AbstractAuthDispatcherListenerTest extends AbstractUnitTestCase
{
    /**
     * A value that cannot be called and the cphalcon message.
     *
     * @return array<string, array{0: mixed, 1: string}>
     */
    public static function getNotCallableValues(): array
    {
        return [
            'string' => ['nope', 'Call to undefined function nope()'],
            'array'  => [[new stdClass(), 'missing'], 'Call to undefined method stdClass::missing()'],
            'object' => [new stdClass(), 'Call to undefined function undefined()'],
            'int'    => [5, 'Call to undefined function undefined()'],
        ];
    }

    /**
     * A forward handler that cannot be called throws Error with the
     * cphalcon message.
     *
     * @issue  https://github.com/phalcon/phalcon/issues/817
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-11-16
     */
    #[DataProvider('getNotCallableValues')]
    public function testEnforceForwardHandlerNotCallable(
        mixed $value,
        string $expected
    ): void {
        $manager = new Manager(new AccessLocator(new Container()));
        $manager->addGuard('web', new FakeGuard(), true);

        $access = new FakeRedirectAccess();
        $access->setAllowed(false);
        $access->setTarget(['controller' => 'login', 'action' => 'index']);
        $manager->setAccess($access);

        $listener = new FakeForwardListener($manager, $value);

        $actual = null;
        try {
            $listener->check();
        } catch (Throwable $ex) {
            $actual = [$ex::class, $ex->getMessage()];
        }

        $this->assertSame([Error::class, $expected], $actual);
    }
}
