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

namespace Phalcon\Tests\Unit\Forms\Element\Select;

use Phalcon\Forms\Element\Select;
use Phalcon\Html\Escaper;
use Phalcon\Html\TagFactory;
use Phalcon\Tests\AbstractUnitTestCase;

use function preg_replace;

final class RenderTest extends AbstractUnitTestCase
{
    private function normalize(string $html): string
    {
        return preg_replace('/[[:cntrl:]]/', '', $html);
    }

    /** @author Phalcon Team <team@phalcon.io> @since 2026-04-17 */
    public function testRenderFlatOptions(): void
    {
        $element = new Select('status', ['1' => 'Active', '2' => 'Inactive']);
        $element->setTagFactory(new TagFactory(new Escaper()));

        $actual = $this->normalize($element->render());

        $this->assertSame(
            '<select id="status" name="status">'
            . '<option value="1">Active</option>'
            . '<option value="2">Inactive</option>'
            . '</select>',
            $actual
        );
    }

    /** @author Phalcon Team <team@phalcon.io> @since 2026-04-17 */
    public function testRenderWithSelectedValue(): void
    {
        $element = new Select('status', ['1' => 'Active', '2' => 'Inactive']);
        $element->setTagFactory(new TagFactory(new Escaper()));
        $element->setDefault('2');

        $actual = $element->render();

        $this->assertStringContainsString('selected="selected"', $actual);
        $this->assertStringContainsString('value="2"', $actual);
    }

    /** @author Phalcon Team <team@phalcon.io> @since 2026-04-17 */
    public function testRenderWithUseEmpty(): void
    {
        $element = new Select(
            'status',
            ['1' => 'Active'],
            [
                'useEmpty'   => true,
                'emptyValue' => '',
                'emptyText'  => 'Pick one',
            ]
        );
        $element->setTagFactory(new TagFactory(new Escaper()));

        $actual = $this->normalize($element->render());

        $this->assertStringContainsString('<option value="">Pick one</option>', $actual);
    }

    /** @author Phalcon Team <team@phalcon.io> @since 2026-04-17 */
    public function testRenderWithOptgroups(): void
    {
        $element = new Select(
            'cars',
            [
                'Italian'  => ['1' => 'Ferrari'],
                'American' => ['2' => 'Ford'],
            ]
        );
        $element->setTagFactory(new TagFactory(new Escaper()));

        $actual = $element->render();

        $this->assertStringContainsString('<optgroup', $actual);
        $this->assertStringContainsString('label="Italian"', $actual);
        $this->assertStringContainsString('label="American"', $actual);
    }

    /** @author Phalcon Team <team@phalcon.io> @since 2026-04-17 */
    public function testRenderWithExtraAttributes(): void
    {
        $element = new Select('status', ['1' => 'Active']);
        $element->setTagFactory(new TagFactory(new Escaper()));

        $actual = $this->normalize($element->render(['class' => 'form-select']));

        $this->assertStringContainsString('class="form-select"', $actual);
        $this->assertStringContainsString('id="status"', $actual);
        $this->assertStringContainsString('name="status"', $actual);
    }

    /** @author Phalcon Team <team@phalcon.io> @since 2026-04-17 */
    public function testRenderReturnsWrapperWhenNoOptions(): void
    {
        $element = new Select('status');
        $element->setTagFactory(new TagFactory(new Escaper()));

        $actual = $this->normalize($element->render());

        $this->assertSame('<select id="status" name="status"></select>', $actual);
    }
}
