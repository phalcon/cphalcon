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

namespace Phalcon\Tests\Unit\ADR\Exceptions;

use Phalcon\ADR\Exceptions\Exception;
use Phalcon\ADR\Exceptions\NotAnAction;
use Phalcon\Contracts\ADR\Exceptions\ADRThrowable;
use Phalcon\Talon\PHPUnit\AbstractUnitTestCase;
use Throwable;

final class HierarchyTest extends AbstractUnitTestCase
{
    /**
     * Unit Tests Phalcon\ADR\Exceptions\Exception :: implements ADRThrowable
     */
    public function testAdrExceptionsBaseImplementsThrowableContract(): void
    {
        $exception = new Exception();

        $this->assertInstanceOf(ADRThrowable::class, $exception);
        $this->assertInstanceOf(Throwable::class, $exception);
    }

    /**
     * Unit Tests Phalcon\ADR\Exceptions\NotAnAction :: extends the base
     */
    public function testAdrExceptionsGranularExtendBase(): void
    {
        $exception = new NotAnAction();

        $this->assertInstanceOf(Exception::class, $exception);
        $this->assertInstanceOf(ADRThrowable::class, $exception);
    }
}
