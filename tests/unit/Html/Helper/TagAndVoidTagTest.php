<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * For the full copyright and license information, please view the LICENSE.md
 * file that was distributed with this source code.
 */

declare(strict_types=1);

namespace Phalcon\Tests\Unit\Html\Helper;

use Phalcon\Html\Escaper;
use Phalcon\Html\Helper\Doctype;
use Phalcon\Html\Helper\Tag;
use Phalcon\Html\Helper\VoidTag;
use Phalcon\Html\TagFactory;
use Phalcon\Tests\AbstractUnitTestCase;

final class TagAndVoidTagTest extends AbstractUnitTestCase
{
    public function testFactoryRegistersTagAndVoidTag(): void
    {
        $factory = new TagFactory(new Escaper());

        $this->assertTrue($factory->has('tag'));
        $this->assertTrue($factory->has('voidTag'));
        $this->assertSame('<section>', $factory->tag('section'));
        $this->assertSame('<input name="x">', $factory->voidTag('input', ['name' => 'x']));
    }
    public function testTagRendersOpenTagOnly(): void
    {
        $tag = new Tag(new Escaper());

        $this->assertSame('<div>', $tag('div'));
        $this->assertSame(
            '<div class="x">',
            $tag('div', ['class' => 'x'])
        );
    }

    public function testVoidTagDefaultsToHtml5SelfClose(): void
    {
        $vt = new VoidTag(new Escaper(), new Doctype());

        $this->assertSame('<br>', $vt('br'));
        $this->assertSame(
            '<hr class="sep">',
            $vt('hr', ['class' => 'sep'])
        );
    }

    public function testVoidTagWithoutDoctypeDoesNotSelfClose(): void
    {
        $vt = new VoidTag(new Escaper());

        $this->assertSame('<br>', $vt('br'));
    }

    public function testVoidTagXhtmlAddsTrailingSlash(): void
    {
        $doctype = new Doctype();
        $doctype(Doctype::XHTML5);

        $vt = new VoidTag(new Escaper(), $doctype);

        $this->assertSame('<br />', $vt('br'));
    }
}
