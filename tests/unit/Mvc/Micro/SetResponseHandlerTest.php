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

class SetResponseHandlerTest extends AbstractUnitTestCase
{
    /**
     * Tests Phalcon\Mvc\Micro :: setResponseHandler()
     */
    public function testMicroResponseHandler(): void
    {
        $trace = [];

        $app = new Micro();

        $app->setResponseHandler(
            function () use (&$trace) {
                $trace[] = 1;
            }
        );

        $app->map(
            '/blog',
            function () use (&$trace) {
                $trace[] = 1;
            }
        );

        $app->handle('/blog');

        $this->assertCount(2, $trace);
    }
}
