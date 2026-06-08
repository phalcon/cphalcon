<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * For the full copyright and license information, please view the LICENSE.md
 * file that was distributed with this source code.
 */

declare(strict_types=1);

namespace Phalcon\Tests\Unit\Forms\Element\Group;

use Phalcon\Forms\Element\CheckGroup;
use Phalcon\Html\Escaper;
use Phalcon\Html\TagFactory;
use Phalcon\Tests\AbstractUnitTestCase;

final class CheckGroupTest extends AbstractUnitTestCase
{
    private function factory(): TagFactory
    {
        return new TagFactory(new Escaper());
    }

    // -----------------------------------------------------------------------
    // Constructor - name normalisation
    // -----------------------------------------------------------------------

    public function testConstructorAppendsArrayBracketsWhenMissing(): void
    {
        $element = new CheckGroup('colors');

        $this->assertSame('colors[]', $element->getName());
    }

    public function testConstructorDoesNotDoubleAppendBrackets(): void
    {
        $element = new CheckGroup('colors[]');

        $this->assertSame('colors[]', $element->getName());
    }

    public function testConstructorPreservesIndexedBrackets(): void
    {
        $element = new CheckGroup('choices[sub]');

        $this->assertSame('choices[sub]', $element->getName());
    }

    // -----------------------------------------------------------------------
    // Options
    // -----------------------------------------------------------------------

    public function testConstructorAcceptsOptions(): void
    {
        $options = ['red' => 'Red', 'blue' => 'Blue'];
        $element = new CheckGroup('colors', $options);

        $this->assertSame($options, $element->getOptions());
    }

    public function testSetOptionsReplacesOptions(): void
    {
        $element = new CheckGroup('colors', ['red' => 'Red']);
        $element->setOptions(['green' => 'Green', 'blue' => 'Blue']);

        $this->assertSame(['green' => 'Green', 'blue' => 'Blue'], $element->getOptions());
    }

    public function testSetOptionsReturnsElementInterface(): void
    {
        $element = new CheckGroup('colors');
        $result  = $element->setOptions(['a' => 'A']);

        $this->assertSame($element, $result);
    }

    // -----------------------------------------------------------------------
    // Attributes
    // -----------------------------------------------------------------------

    public function testConstructorAcceptsAttributes(): void
    {
        $element = new CheckGroup('colors', [], ['class' => 'check-field']);

        $this->assertSame(['class' => 'check-field'], $element->getAttributes());
    }

    // -----------------------------------------------------------------------
    // Rendering
    // -----------------------------------------------------------------------

    public function testRenderProducesCheckboxInputs(): void
    {
        $element = new CheckGroup('colors', ['red' => 'Red', 'blue' => 'Blue']);
        $element->setTagFactory($this->factory());

        $rendered = $element->render();

        $this->assertStringContainsString('type="checkbox"', $rendered);
        $this->assertStringContainsString('name="colors[]"', $rendered);
        $this->assertStringContainsString('value="red"', $rendered);
        $this->assertStringContainsString('value="blue"', $rendered);
        $this->assertStringContainsString('>Red</label>', $rendered);
        $this->assertStringContainsString('>Blue</label>', $rendered);
    }

    public function testRenderChecksDefaultValue(): void
    {
        $element = new CheckGroup('colors', ['red' => 'Red', 'blue' => 'Blue']);
        $element->setTagFactory($this->factory());
        $element->setDefault(['red']);

        $rendered = $element->render();

        // 'red' line should have checked attribute
        $lines = explode(PHP_EOL, $rendered);
        $this->assertStringContainsString('checked="checked"', $lines[0]);
        $this->assertStringNotContainsString('checked', $lines[1]);
    }

    public function testRenderWithExtraAttributesMergesCorrectly(): void
    {
        $element = new CheckGroup('colors', ['red' => 'Red']);
        $element->setTagFactory($this->factory());

        $rendered = $element->render(['class' => 'my-check']);

        $this->assertStringContainsString('class="my-check"', $rendered);
    }

    public function testToStringEqualsRender(): void
    {
        $element = new CheckGroup('colors', ['red' => 'Red']);
        $element->setTagFactory($this->factory());

        $this->assertSame($element->render(), (string) $element);
    }
}
