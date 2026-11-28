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

namespace Phalcon\Tests\Unit\Acl\Adapter\Memory;

use Phalcon\Acl\Adapter\Memory;
use Phalcon\Talon\PHPUnit\AbstractUnitTestCase;

/**
 * The ACL calls the access functions with the PHP weak type rules, the same
 * as cphalcon. The test file declares strict_types=1, so the mode of the
 * caller has no effect.
 */
final class WeakModeTypesTest extends AbstractUnitTestCase
{
    /**
     * @issue  https://github.com/phalcon/phalcon/issues/805
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-11-14
     */
    public function testAclAdapterMemoryWeakModeFunction(): void
    {
        $acl = new Memory();
        $acl->addRole('r');
        $acl->addComponent('c', ['a']);
        $acl->allow(
            'r',
            'c',
            'a',
            function (int $x): bool {
                return $x === 5;
            }
        );

        $actual = $acl->isAllowed('r', 'c', 'a', ['x' => '5']);

        $this->assertTrue($actual);
    }
}
