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

namespace Phalcon\Tests\Unit\Mvc\Micro;

use Phalcon\Mvc\Micro;
use Phalcon\Tests\AbstractUnitTestCase;

class GetHandlersTest extends AbstractUnitTestCase
{
    /**
     * @author Sid Roberts <https://github.com/SidRoberts>
     * @since  2019-05-22
     */
    public function testMvcMicroGetHandlers(): void
    {
        $micro = new Micro();

        $getRoute = $micro->get(
            '/test',
            function () {
                return 'this is get';
            }
        );

        $postRoute = $micro->post(
            '/test',
            function () {
                return 'this is post';
            }
        );

        $headRoute = $micro->head(
            '/test',
            function () {
                return 'this is head';
            }
        );

        $handlers = $micro->getHandlers();

        $this->assertCount(
            3,
            $handlers
        );

        $this->assertEquals(
            'this is get',
            $handlers[$getRoute->getRouteId()]()
        );

        $this->assertEquals(
            'this is post',
            $handlers[$postRoute->getRouteId()]()
        );

        $this->assertEquals(
            'this is head',
            $handlers[$headRoute->getRouteId()]()
        );
    }
}
