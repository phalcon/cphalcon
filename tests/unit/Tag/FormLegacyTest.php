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

namespace Phalcon\Tests\Unit\Tag;

use Phalcon\Tag;

/**
 * Covers Tag::formLegacy() and Tag::endForm().
 *
 * The action is resolved through the `url` service and only rendered when it
 * ends up non-empty, so a form with no action at all carries just the method.
 * A `parameters` entry is appended as a query string, whether or not there is
 * an action in front of it - and, because it is never removed from the bag, it
 * is also rendered as an attribute of its own.
 */
final class FormLegacyTest extends AbstractTagTestCase
{
    public function testEndForm(): void
    {
        $this->assertSame('</form>', Tag::endForm());
    }

    public function testFormWithActionKey(): void
    {
        $this->assertSame(
            '<form action="https://phalcon.io/save" method="post">',
            Tag::formLegacy(['action' => 'save'])
        );
    }

    public function testFormWithCustomMethod(): void
    {
        $this->assertSame(
            '<form action="https://phalcon.io/save" method="get">',
            Tag::formLegacy(['save', 'method' => 'get'])
        );
    }

    public function testFormWithNoActionRendersTheMethodOnly(): void
    {
        $this->assertSame('<form method="post">', Tag::formLegacy([]));
    }

    public function testFormWithParameters(): void
    {
        $this->assertSame(
            '<form action="https://phalcon.io/save?id=1" parameters="id=1"'
            . ' method="post">',
            Tag::formLegacy(['save', 'parameters' => 'id=1'])
        );
    }

    public function testFormWithParametersAndNoAction(): void
    {
        $this->assertSame(
            '<form action="?id=1" parameters="id=1" method="post">',
            Tag::formLegacy(['parameters' => 'id=1'])
        );
    }

    public function testFormWithPositionalAction(): void
    {
        $this->assertSame(
            '<form action="https://phalcon.io/save" method="post">',
            Tag::formLegacy('save')
        );
    }
}
