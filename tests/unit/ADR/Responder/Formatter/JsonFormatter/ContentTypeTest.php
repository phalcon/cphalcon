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

namespace Phalcon\Tests\Unit\ADR\Responder\Formatter\JsonFormatter;

use Phalcon\ADR\Responder\Formatter\JsonFormatter;
use Phalcon\Talon\PHPUnit\AbstractUnitTestCase;

final class ContentTypeTest extends AbstractUnitTestCase
{
    /**
     * Unit Tests Phalcon\ADR\Responder\Formatter\JsonFormatter :: contentType()
     */
    public function testAdrResponderFormatterJsonFormatterContentType(): void
    {
        $this->assertSame('application/json', (new JsonFormatter())->contentType());
    }
}
