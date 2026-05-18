<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * For the full copyright and license information, please view the LICENSE.md
 * file that was distributed with this source code.
 */

declare(strict_types=1);

namespace Phalcon\Tests\Unit\Html\TagFactory;

use Phalcon\Html\Escaper;
use Phalcon\Html\TagFactory;
use Phalcon\Tests\AbstractUnitTestCase;

/**
 * Verifies that the `*Raw` factory entries skip escaping while their non-Raw
 * counterparts continue to escape. The pair shares a class — the difference
 * is a `forceRaw` constructor flag injected by the factory recipe.
 */
final class RawVariantsTest extends AbstractUnitTestCase
{
    public function testAnchorEscapingByDefault(): void
    {
        $factory = new TagFactory(new Escaper());
        $rendered = $factory->a('/x', '<b>hi</b>');

        $this->assertStringContainsString('&lt;b&gt;hi&lt;/b&gt;', $rendered);
    }

    public function testAnchorRawDoesNotEscape(): void
    {
        $factory = new TagFactory(new Escaper());
        $rendered = $factory->aRaw('/x', '<b>hi</b>');

        $this->assertStringContainsString('<b>hi</b>', $rendered);
        $this->assertStringNotContainsString('&lt;b&gt;', $rendered);
    }

    public function testButtonRawDoesNotEscape(): void
    {
        $factory = new TagFactory(new Escaper());

        $this->assertStringContainsString('&lt;i&gt;', $factory->button('<i>x</i>'));
        $this->assertStringContainsString('<i>x</i>', $factory->buttonRaw('<i>x</i>'));
    }

    public function testElementRawDoesNotEscape(): void
    {
        $factory = new TagFactory(new Escaper());

        $this->assertStringContainsString(
            '&lt;span&gt;hi&lt;/span&gt;',
            $factory->element('p', '<span>hi</span>')
        );
        $this->assertStringContainsString(
            '<span>hi</span>',
            $factory->elementRaw('p', '<span>hi</span>')
        );
    }

    public function testLabelRawDoesNotEscape(): void
    {
        $factory = new TagFactory(new Escaper());

        $this->assertStringContainsString('&lt;b&gt;', $factory->label('<b>x</b>'));
        $this->assertStringContainsString('<b>x</b>', $factory->labelRaw('<b>x</b>'));
    }

    public function testOlRawAddsRawItemsByDefault(): void
    {
        $factory = new TagFactory(new Escaper());

        $ol = $factory->newInstance('ol');
        $ol('    ', "\n", []);
        $ol->add('<i>x</i>');
        $this->assertStringContainsString('&lt;i&gt;', (string) $ol);

        $olRaw = $factory->newInstance('olRaw');
        $olRaw('    ', "\n", []);
        $olRaw->add('<i>x</i>');
        $this->assertStringContainsString('<i>x</i>', (string) $olRaw);
        $this->assertStringNotContainsString('&lt;i&gt;', (string) $olRaw);
    }

    public function testUlRawAddsRawItemsByDefault(): void
    {
        $factory = new TagFactory(new Escaper());

        $ulRaw = $factory->newInstance('ulRaw');
        $ulRaw('    ', "\n", []);
        $ulRaw->add('<b>x</b>');

        $rendered = (string) $ulRaw;
        $this->assertStringContainsString('<b>x</b>', $rendered);
        $this->assertStringNotContainsString('&lt;b&gt;', $rendered);
    }

    public function testInjectAttributeStripsUserDuplicate(): void
    {
        $factory = new TagFactory(new Escaper());

        // user supplies a duplicate href; the positional href must win
        $rendered = $factory->a(
            '/correct',
            'go',
            ['href' => '/wrong']
        );

        $this->assertStringContainsString('href="/correct"', $rendered);
        $this->assertStringNotContainsString('/wrong', $rendered);
    }

    public function testInjectAttributeStripsUserDuplicateForImg(): void
    {
        $factory = new TagFactory(new Escaper());

        $rendered = $factory->img('/correct.png', ['src' => '/wrong.png']);

        $this->assertStringContainsString('src="/correct.png"', $rendered);
        $this->assertStringNotContainsString('/wrong.png', $rendered);
    }
}
