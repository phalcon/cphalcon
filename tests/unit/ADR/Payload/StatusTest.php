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

namespace Phalcon\Tests\Unit\ADR\Payload;

use Phalcon\ADR\Payload\Status;
use Phalcon\Talon\PHPUnit\AbstractUnitTestCase;
use ReflectionClass;

final class StatusTest extends AbstractUnitTestCase
{
    /**
     * Unit Tests Phalcon\ADR\Payload\Status :: constant values
     */
    public function testAdrPayloadStatusConstantValues(): void
    {
        $this->assertSame('SUCCESS', Status::SUCCESS);
        $this->assertSame('ERROR', Status::ERROR);
        $this->assertSame('FAILURE', Status::FAILURE);
        $this->assertSame('NOT_AUTHORIZED', Status::NOT_AUTHORIZED);
        $this->assertSame('NOT_AUTHENTICATED', Status::NOT_AUTHENTICATED);
        $this->assertSame('METHOD_NOT_ALLOWED', Status::METHOD_NOT_ALLOWED);
    }

    /**
     * Unit Tests Phalcon\ADR\Payload\Status :: vocabulary size
     */
    public function testAdrPayloadStatusVocabularySize(): void
    {
        $reflection = new ReflectionClass(Status::class);

        // 20 Aura-lineage statuses + METHOD_NOT_ALLOWED
        $this->assertCount(21, $reflection->getConstants());
    }
}
