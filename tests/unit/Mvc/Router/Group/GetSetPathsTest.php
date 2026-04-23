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
use Phalcon\Tests\AbstractUnitTestCase;

final class GetSetPathsTest extends AbstractUnitTestCase
{
    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function testMvcRouterGroupGetPaths(): void
    {
        $group = new Group();

        $actual = $group->getPaths();
        $this->assertNull($actual);

        $paths = [
            'one',
            'two',
        ];
        $group->setPaths($paths);
        $expected = $paths;
        $actual   = $group->getPaths();
        $this->assertSame($expected, $actual);
    }
}
