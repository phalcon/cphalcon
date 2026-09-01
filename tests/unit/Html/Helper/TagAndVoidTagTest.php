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
use Phalcon\Talon\PHPUnit\AbstractUnitTestCase;

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

    public function testTagNameCannotBreakOutToMarkup(): void
    {
        $tag = new Tag(new Escaper());

        $this->assertStringNotContainsString(
            '<script>',
            $tag('x><script>alert(1)</script>')
        );
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

    public function testTagStripsAttributeNameSplittersPreventingInjection(): void
    {
        $tag = new Tag(new Escaper());

        $html = $tag('div', ['x onclick=alert(1) y' => 'v']);

        $document = new \DOMDocument();
        @$document->loadHTML('<html><body>' . $html . '</body></html>');
        $div = $document->getElementsByTagName('div')->item(0);

        $names = [];
        foreach ($div->attributes as $attribute) {
            $names[] = $attribute->name;
        }

        $this->assertNotContains('onclick', $names);
    }

    public function testTagStripsTagNameSplittersPreventingInjection(): void
    {
        $tag = new Tag(new Escaper());

        $this->assertSame(
            '<xonloadalert(1)y>',
            $tag('x onload=alert(1)/y')
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
