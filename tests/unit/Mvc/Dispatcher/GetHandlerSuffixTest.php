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

namespace Phalcon\Tests\Unit\Mvc\Dispatcher;

use Phalcon\Mvc\Dispatcher\Exception;
use Phalcon\Tests\Unit\Mvc\Dispatcher\Helper\BaseDispatcher;

class GetHandlerSuffixTest extends BaseDispatcher
{
    /**
     * @author Sid Roberts <https://github.com/SidRoberts>
     * @since  2019-06-01
     */
    public function testMvcDispatcherGetHandlerSuffix(): void
    {
        $dispatcher = $this->getDispatcher();

        $dispatcher->setControllerName('Index');

        $dispatcher->setControllerSuffix('Bleh');

        $this->expectException(Exception::class);
        $this->expectExceptionMessage(
            'Phalcon\Tests\Unit\Mvc\Dispatcher\Helper\IndexBleh handler class cannot be loaded'
        );
        $this->expectExceptionCode(Exception::EXCEPTION_HANDLER_NOT_FOUND);

        $dispatcher->dispatch();
    }
}
