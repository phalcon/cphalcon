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

namespace Phalcon\Tests\Unit\Mvc\Router\Group;

use Phalcon\Mvc\Router\Group;
use Phalcon\Mvc\Router\GroupInterface;
use Phalcon\Tests\AbstractUnitTestCase;

final class BeforeMatchTest extends AbstractUnitTestCase
{
    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function testMvcRouterGroupBeforeMatch(): void
    {
        $group    = new Group();
        $callback = function () {
            return true;
        };
        $result = $group->beforeMatch($callback);
        $this->assertInstanceOf(GroupInterface::class, $result);
    }
}
