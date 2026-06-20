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

namespace Phalcon\Tests\Unit\Support\Debug\Report;

use Phalcon\Support\Debug\Report\BacktraceItem;
use Phalcon\Tests\AbstractUnitTestCase;

final class BacktraceItemTest extends AbstractUnitTestCase
{
    public function testGettersReturnConstructorValues(): void
    {
        $fragment = [
            'mode'      => 'full',
            'firstLine' => 1,
            'line'      => 4,
            'lastLine'  => 9,
            'lines'     => ["<?php\n", "echo 1;\n"],
        ];

        $item = new BacktraceItem(
            'myFunction',
            '->',
            'My\\Klass',
            'https://docs/klass',
            'https://docs/func',
            true,
            ['a', 1],
            '/path/file.php',
            42,
            $fragment
        );

        $this->assertSame('My\\Klass', $item->getClassName());
        $this->assertSame('https://docs/klass', $item->getClassLink());
        $this->assertSame('->', $item->getType());
        $this->assertSame('myFunction', $item->getFunctionName());
        $this->assertSame('https://docs/func', $item->getFunctionLink());
        $this->assertTrue($item->hasArgs());
        $this->assertSame(['a', 1], $item->getArgs());
        $this->assertSame('/path/file.php', $item->getFile());
        $this->assertSame(42, $item->getLine());
        $this->assertSame($fragment, $item->getFragment());
    }

    public function testDefaultsForMinimalFrame(): void
    {
        $item = new BacktraceItem('closure');

        $this->assertNull($item->getClassName());
        $this->assertNull($item->getType());
        $this->assertFalse($item->hasArgs());
        $this->assertSame([], $item->getArgs());
        $this->assertNull($item->getFragment());
    }
}
