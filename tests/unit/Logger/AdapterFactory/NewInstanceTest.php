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

namespace Phalcon\Tests\Unit\Logger\AdapterFactory;

use Phalcon\Logger\Adapter\AdapterInterface;
use Phalcon\Logger\AdapterFactory;
use Phalcon\Logger\Exception;
use Phalcon\Tests\AbstractUnitTestCase;

use function outputDir;

final class NewInstanceTest extends AbstractUnitTestCase
{
    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function testLoggerAdapterFactoryNewInstance(): void
    {
        $fileName = $this->getNewFileName();
        $fileName = outputDir('tests/logs/' . $fileName);
        $factory  = new AdapterFactory();

        $logger = $factory->newInstance('stream', $fileName);
        $this->assertInstanceOf(AdapterInterface::class, $logger);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-06
     */
    public function testLoggerAdapterFactoryNewInstanceException(): void
    {
        $this->expectException(Exception::class);
        $this->expectExceptionMessage('Service unknown is not registered');

        $factory = new AdapterFactory();
        $factory->newInstance('unknown', '123.log');
    }
}
