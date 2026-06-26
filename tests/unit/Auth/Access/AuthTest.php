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

namespace Phalcon\Tests\Unit\Auth\Access;

use Phalcon\Auth\Access\Auth;
use Phalcon\Tests\AbstractUnitTestCase;
use Phalcon\Tests\Unit\Auth\Fake\FakeGuard;
use Phalcon\Tests\Unit\Auth\Fake\FakeRoleUser;

final class AuthTest extends AbstractUnitTestCase
{
    public function testIsAllowedHonorsExceptActions(): void
    {
        $guard  = new FakeGuard();
        $access = new Auth();
        $access->setExceptActions(['login']);

        $this->assertTrue($access->isAllowed($guard, 'login'));
        $this->assertFalse($access->isAllowed($guard, 'dashboard'));
    }

    public function testIsAllowedHonorsOnlyActions(): void
    {
        $guard = new FakeGuard();
        $guard->setUser(new FakeRoleUser());

        $access = new Auth();
        $access->setOnlyActions(['admin']);

        $this->assertFalse($access->isAllowed($guard, 'home'));
        $this->assertTrue($access->isAllowed($guard, 'admin'));
    }

    public function testIsAllowedWhenAuthenticated(): void
    {
        $guard = new FakeGuard();
        $guard->setUser(new FakeRoleUser());

        $this->assertTrue((new Auth())->isAllowed($guard, 'index'));
    }

    public function testIsAllowedWhenNotAuthenticated(): void
    {
        $this->assertFalse((new Auth())->isAllowed(new FakeGuard(), 'index'));
    }
}
