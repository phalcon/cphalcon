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

final class FromArrayTest extends AbstractUnitTestCase
{
    /**
     * Unit Tests Phalcon\ADR\Input\Input :: fromArray()/toArray()
     */
    public function testAdrInputInputFromArray(): void
    {
        $data  = ['name' => 'test', 'age' => 30];
        $input = Input::fromArray($data);

        $this->assertInstanceOf(Input::class, $input);
        $this->assertSame($data, $input->toArray());
    }
}
