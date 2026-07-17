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

namespace Phalcon\Tests\Unit\ADR\Payload\Payload;

use Phalcon\ADR\Payload\Payload;
use Phalcon\Talon\PHPUnit\AbstractUnitTestCase;

final class WithGetExtrasTest extends AbstractUnitTestCase
{
    /**
     * Unit Tests Phalcon\ADR\Payload\Payload :: withExtras()/getExtras()
     */
    public function testAdrPayloadPayloadWithGetExtras(): void
    {
        $payload = new Payload();
        $new     = $payload->withExtras(['meta' => true]);

        $this->assertNotSame($payload, $new);
        $this->assertNull($payload->getExtras());
        $this->assertSame(['meta' => true], $new->getExtras());
    }
}
