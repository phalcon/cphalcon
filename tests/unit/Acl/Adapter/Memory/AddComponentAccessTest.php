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

namespace Phalcon\Tests\Unit\Acl\Adapter\Memory;

use Phalcon\Acl\Adapter\Memory;
use Phalcon\Acl\Component;
use Phalcon\Acl\Exception;
use Phalcon\Tests\AbstractUnitTestCase;

final class AddComponentAccessTest extends AbstractUnitTestCase
{
    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function testAclAdapterMemoryAddComponentAccess(): void
    {
        $acl = new Memory();

        $actual = $acl->addComponent('Customer', ['index']);
        $this->assertTrue($actual);

        $actual = $acl->addComponentAccess('Customer', ['new']);
        $this->assertTrue($actual);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function testAclAdapterMemoryAddComponentAccessUnknown(): void
    {
        $this->expectException(Exception::class);
        $this->expectExceptionMessage("Component 'Post' does not exist in the ACL");

        $acl = new Memory();
        $acl->addComponentAccess('Post', ['update']);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function testAclAdapterMemoryAddComponentAccessWrongAccessList(): void
    {
        $this->expectException(Exception::class);
        $this->expectExceptionMessage('Invalid value for the accessList');

        $acl  = new Memory();
        $post = new Component('Post');

        $acl->addComponent($post, ['update']);
        $acl->addComponentAccess('Post', 123);
    }
}
