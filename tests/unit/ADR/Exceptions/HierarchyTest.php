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
use Phalcon\ADR\Exceptions\HeadersAlreadySent;
use Phalcon\ADR\Exceptions\MethodNotAllowed;
use Phalcon\ADR\Exceptions\NotAnAction;
use Phalcon\ADR\Exceptions\OutputAlreadySent;
use Phalcon\ADR\Exceptions\RouteNotFound;
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
     * Unit Tests Phalcon\ADR\Exceptions :: every granular exception extends the
     * base, implements the contract and carries its own message
     */
    public function testAdrExceptionsGranularExtendBase(): void
    {
        $exceptions = [
            new NotAnAction('MyApp\\Action\\Foo'),
            new RouteNotFound(),
            new MethodNotAllowed(),
            new HeadersAlreadySent(),
            new OutputAlreadySent(),
        ];

        foreach ($exceptions as $exception) {
            $this->assertInstanceOf(Exception::class, $exception);
            $this->assertInstanceOf(ADRThrowable::class, $exception);
            $this->assertNotSame('', $exception->getMessage());
        }
    }
}
