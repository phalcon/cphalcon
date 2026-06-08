<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

declare(strict_types=1);

namespace Phalcon\Tests\Unit\Auth\Access;

use Phalcon\Acl\Adapter\Memory as AclMemory;
use Phalcon\Auth\Access\Acl;
use Phalcon\Auth\Exception;
use Phalcon\Tests\AbstractUnitTestCase;
use Phalcon\Tests\Unit\Auth\Fake\FakeAuthUserNoRemember;
use Phalcon\Tests\Unit\Auth\Fake\FakeGuard;
use Phalcon\Tests\Unit\Auth\Fake\FakeRoleUser;

final class AclTest extends AbstractUnitTestCase
{
    public function testAllowsRoleWithAccess(): void
    {
        $gate = new Acl($this->buildAcl());

        $this->assertTrue(
            $gate->isAllowed(
                $this->buildGuardWithRole(),
                'edit',
                ['handler' => 'invoices']
            )
        );
    }

    public function testDeniesRoleWithoutAccess(): void
    {
        $gate = new Acl($this->buildAcl());

        $this->assertFalse(
            $gate->isAllowed(
                $this->buildGuardWithRole(),
                'pay',
                ['handler' => 'invoices']
            )
        );
    }

    public function testExceptBypassesTheGate(): void
    {
        $gate = new Acl($this->buildAcl());
        $gate->setExceptActions(['login']);

        // Bypass happens before role/handler resolution - no exception
        $this->assertTrue($gate->isAllowed(new FakeGuard(), 'login'));
    }

    public function testGuestRoleUsedWhenNoUser(): void
    {
        $gate = new Acl($this->buildAcl(), ['guestRole' => 'guests']);

        $this->assertTrue(
            $gate->isAllowed(new FakeGuard(), 'view', ['handler' => 'invoices'])
        );
        $this->assertFalse(
            $gate->isAllowed(new FakeGuard(), 'edit', ['handler' => 'invoices'])
        );
    }

    public function testModulePrefixesComponent(): void
    {
        $acl = new AclMemory();
        $acl->addRole('admins');
        $acl->addComponent('admin:invoices', ['edit']);
        $acl->allow('admins', 'admin:invoices', 'edit');

        $gate = new Acl($acl);

        $this->assertTrue(
            $gate->isAllowed(
                $this->buildGuardWithRole(),
                'edit',
                ['handler' => 'invoices', 'module' => 'admin']
            )
        );
    }

    public function testModuleSeparatorOption(): void
    {
        $acl = new AclMemory();
        $acl->addRole('admins');
        $acl->addComponent('admin.invoices', ['edit']);
        $acl->allow('admins', 'admin.invoices', 'edit');

        $gate = new Acl($acl, ['moduleSeparator' => '.']);

        $this->assertTrue(
            $gate->isAllowed(
                $this->buildGuardWithRole(),
                'edit',
                ['handler' => 'invoices', 'module' => 'admin']
            )
        );
    }

    public function testOnlyScopesTheGate(): void
    {
        $gate = new Acl($this->buildAcl());
        $gate->setOnlyActions(['delete']);

        // 'edit' is outside the scoped list - allowed without an ACL check
        $this->assertTrue(
            $gate->isAllowed($this->buildGuardWithRole(), 'edit')
        );
    }

    public function testParamsArePassedToCallableRules(): void
    {
        $acl = new AclMemory();
        $acl->addRole('admins');
        $acl->addComponent('invoices', ['pay']);
        $acl->allow(
            'admins',
            'invoices',
            'pay',
            function ($amount) {
                return $amount < 100;
            }
        );

        $gate  = new Acl($acl);
        $guard = $this->buildGuardWithRole();

        $this->assertTrue(
            $gate->isAllowed(
                $guard,
                'pay',
                ['handler' => 'invoices', 'params' => ['amount' => 50]]
            )
        );
        $this->assertFalse(
            $gate->isAllowed(
                $guard,
                'pay',
                ['handler' => 'invoices', 'params' => ['amount' => 150]]
            )
        );
    }

    public function testThrowsWhenHandlerMissing(): void
    {
        $this->expectException(Exception::class);
        $this->expectExceptionMessage('handler');

        (new Acl($this->buildAcl()))->isAllowed(
            $this->buildGuardWithRole(),
            'edit'
        );
    }

    public function testThrowsWhenUserNotRoleAware(): void
    {
        $this->expectException(Exception::class);
        $this->expectExceptionMessage('RoleAwareInterface');

        $guard = new FakeGuard();
        $guard->setUser(new FakeAuthUserNoRemember(['id' => 1]));

        (new Acl($this->buildAcl()))->isAllowed(
            $guard,
            'edit',
            ['handler' => 'invoices']
        );
    }

    private function buildAcl(): AclMemory
    {
        $acl = new AclMemory();
        $acl->addRole('admins');
        $acl->addRole('guests');
        $acl->addComponent('invoices', ['edit', 'pay', 'view']);
        $acl->allow('admins', 'invoices', 'edit');
        $acl->allow('guests', 'invoices', 'view');

        return $acl;
    }

    private function buildGuardWithRole(string $role = 'admins'): FakeGuard
    {
        $guard = new FakeGuard();
        $guard->setUser(new FakeRoleUser(1, $role));

        return $guard;
    }
}
