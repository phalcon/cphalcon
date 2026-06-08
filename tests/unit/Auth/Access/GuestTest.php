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

use Phalcon\Auth\Access\Guest;
use Phalcon\Tests\AbstractUnitTestCase;
use Phalcon\Tests\Unit\Auth\Fake\FakeGuard;
use Phalcon\Tests\Unit\Auth\Fake\FakeRoleUser;

final class GuestTest extends AbstractUnitTestCase
{
    public function testIsAllowedWhenAuthenticated(): void
    {
        $guard = new FakeGuard();
        $guard->setUser(new FakeRoleUser());

        $this->assertFalse((new Guest())->isAllowed($guard, 'index'));
    }

    public function testIsAllowedWhenGuest(): void
    {
        $this->assertTrue((new Guest())->isAllowed(new FakeGuard(), 'index'));
    }
}
