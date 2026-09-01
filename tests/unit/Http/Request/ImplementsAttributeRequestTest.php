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

namespace Phalcon\Tests\Unit\Http\Request;

use Phalcon\Contracts\Http\AttributeRequest;
use Phalcon\Http\Request;
use Phalcon\Talon\PHPUnit\AbstractUnitTestCase;

final class ImplementsAttributeRequestTest extends AbstractUnitTestCase
{
    /**
     * Unit Tests Phalcon\Http\Request :: implements AttributeRequest
     */
    public function testHttpRequestImplementsAttributeRequest(): void
    {
        $request = new Request();

        $this->assertInstanceOf(AttributeRequest::class, $request);
    }
}
