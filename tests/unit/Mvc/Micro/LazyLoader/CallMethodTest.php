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

namespace Phalcon\Tests\Unit\Mvc\Micro\LazyLoader;

use Phalcon\Mvc\Micro\LazyLoader;
use Phalcon\Tests\AbstractUnitTestCase;
use Phalcon\Tests\Support\Micro\LazyLoaderHandler;

class CallMethodTest extends AbstractUnitTestCase
{
    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function testMvcMicroLazyloaderCallMethod(): void
    {
        $loader = new LazyLoader(LazyLoaderHandler::class);
        $result = $loader->callMethod('greet', ['name' => 'Phalcon']);
        $this->assertSame('Hello Phalcon', $result);
    }
}
