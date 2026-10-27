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

namespace Phalcon\Tests\Benchmarks\Acl;

use Phalcon\Acl\Adapter\Memory;
use Phalcon\Di\Di;
use PhpBench\Attributes\BeforeMethods;
use PhpBench\Attributes\Revs;
use RuntimeException;

#[BeforeMethods('setUp')]
final class AclBench
{
    private const ACCESS = ['index', 'view', 'edit', 'delete'];

    private const COMPONENTS = ['posts', 'comments', 'users', 'settings', 'reports'];

    private Memory $acl;

    public function setUp(): void
    {
        Di::reset();

        $this->acl = $this->buildAcl();
    }

    /**
     * The ACL with 4 roles and 5 components, as one request makes it.
     */
    #[Revs(200)]
    public function benchBuild(): void
    {
        $acl = $this->buildAcl();

        if (true !== $acl->isAllowed('admin', 'settings', 'delete')) {
            throw new RuntimeException('Unexpected value: false');
        }
    }

    public function benchIsAllowed(): void
    {
        if (true !== $this->acl->isAllowed('editor', 'posts', 'edit')) {
            throw new RuntimeException('Unexpected value: false');
        }
    }

    /**
     * The access comes from guest, through user (editor inherits user).
     */
    public function benchIsAllowedInherited(): void
    {
        if (true !== $this->acl->isAllowed('editor', 'comments', 'view')) {
            throw new RuntimeException('Unexpected value: false');
        }
    }

    public function benchIsDenied(): void
    {
        if (false !== $this->acl->isAllowed('guest', 'users', 'delete')) {
            throw new RuntimeException('Unexpected value: true');
        }
    }

    private function buildAcl(): Memory
    {
        $acl = new Memory();

        $acl->addRole('guest');
        $acl->addRole('user', 'guest');
        $acl->addRole('editor', 'user');
        $acl->addRole('admin', 'editor');

        foreach (self::COMPONENTS as $component) {
            $acl->addComponent($component, self::ACCESS);
        }

        $acl->allow('guest', 'posts', ['index', 'view']);
        $acl->allow('guest', 'comments', ['index', 'view']);
        $acl->allow('user', 'comments', 'edit');
        $acl->allow('editor', 'posts', ['edit', 'delete']);
        $acl->allow('admin', '*', '*');

        return $acl;
    }
}
