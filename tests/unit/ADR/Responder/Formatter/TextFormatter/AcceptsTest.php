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

final class AcceptsTest extends AbstractUnitTestCase
{
    /**
     * Unit Tests Phalcon\ADR\Responder\Formatter\TextFormatter :: accepts()
     */
    public function testAdrResponderFormatterTextFormatterAccepts(): void
    {
        $formatter = new TextFormatter();

        $this->assertTrue($formatter->accepts('text/plain'));
        $this->assertFalse($formatter->accepts('application/json'));
    }
}
