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
use Phalcon\Talon\PHPUnit\AbstractUnitTestCase;

final class GetSetInputTest extends AbstractUnitTestCase
{
    /**
     * Unit Tests Phalcon\Domain\Payload\Payload :: getInput()/setInput()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-05-24
     */
    public function testHttpPayloadPayloadGetSetInput(): void
    {
        $payload = new Payload();
        $payload->setInput('input');

        $actual = $payload->getInput();
        $this->assertSame('input', $actual);
    }
}
