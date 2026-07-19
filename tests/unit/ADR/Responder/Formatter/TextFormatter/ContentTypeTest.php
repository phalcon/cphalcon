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

namespace Phalcon\Tests\Unit\ADR\Responder\Formatter\TextFormatter;

use Phalcon\ADR\Responder\Formatter\TextFormatter;
use Phalcon\Talon\PHPUnit\AbstractUnitTestCase;

final class ContentTypeTest extends AbstractUnitTestCase
{
    /**
     * Unit Tests Phalcon\ADR\Responder\Formatter\TextFormatter :: contentType()
     */
    public function testAdrResponderFormatterTextFormatterContentType(): void
    {
        $this->assertSame('text/plain', (new TextFormatter())->contentType());
    }
}
