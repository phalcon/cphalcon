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

namespace Phalcon\Tests\Unit\Domain\Payload\Payload;

use Phalcon\Domain\Payload\Payload;
use Phalcon\Tests\AbstractUnitTestCase;
use RuntimeException;

final class GetSetExceptionTest extends AbstractUnitTestCase
{
    /**
     * Unit Tests Phalcon\Domain\Payload\Payload ::
     * getException()/setException()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-06-07
     */
    public function testHttpPayloadPayloadGetSetException(): void
    {
        $payload   = new Payload();
        $exception = new RuntimeException('Runtime error');
        $payload->setException($exception);

        $actual = $payload->getException();
        $this->assertSame($exception, $actual);
    }
}
