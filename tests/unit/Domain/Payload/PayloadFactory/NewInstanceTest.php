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

namespace Phalcon\Tests\Unit\Domain\Payload\PayloadFactory;

use Phalcon\Domain\Payload\PayloadFactory;
use Phalcon\Domain\Payload\PayloadInterface;
use Phalcon\Talon\PHPUnit\AbstractUnitTestCase;

final class NewInstanceTest extends AbstractUnitTestCase
{
    /**
     * Unit Tests Phalcon\Domain\Payload\PayloadFactory :: newInstance()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-05-24
     */
    public function testHttpPayloadPayloadFactoryNewInstance(): void
    {
        $factory = new PayloadFactory();
        $payload = $factory->newInstance();

        $this->assertInstanceOf(
            PayloadInterface::class,
            $payload
        );
    }
}
