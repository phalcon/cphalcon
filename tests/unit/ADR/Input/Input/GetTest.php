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

namespace Phalcon\Tests\Unit\ADR\Input\Input;

use Phalcon\ADR\Input\Input;
use Phalcon\Talon\PHPUnit\AbstractUnitTestCase;

final class GetTest extends AbstractUnitTestCase
{
    /**
     * Unit Tests Phalcon\ADR\Input\Input :: get()/has()
     */
    public function testAdrInputInputGet(): void
    {
        $input = Input::fromArray(['name' => 'test']);

        $this->assertTrue($input->has('name'));
        $this->assertSame('test', $input->get('name'));

        $this->assertFalse($input->has('missing'));
        $this->assertNull($input->get('missing'));
        $this->assertSame('fallback', $input->get('missing', 'fallback'));
    }
}
