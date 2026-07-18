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

namespace Phalcon\Tests\Unit\ADR\Emitter\Exceptions;

use Phalcon\ADR\Emitter\Exceptions\HeadersAlreadySent;
use Phalcon\ADR\Emitter\Exceptions\OutputAlreadySent;
use Phalcon\ADR\Exceptions\ADRThrowable;
use Phalcon\Talon\PHPUnit\AbstractUnitTestCase;

final class HierarchyTest extends AbstractUnitTestCase
{
    /**
     * Unit Tests Phalcon\ADR\Emitter\Exceptions :: implement ADRThrowable
     */
    public function testAdrEmitterExceptionsAreAdrThrowable(): void
    {
        $this->assertInstanceOf(ADRThrowable::class, new HeadersAlreadySent());
        $this->assertInstanceOf(ADRThrowable::class, new OutputAlreadySent());
    }
}
