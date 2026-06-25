<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * For the full copyright and license information, please view the LICENSE.md
 * file that was distributed with this source code.
 */

declare(strict_types=1);

namespace Phalcon\Tests\Unit\Html\Escaper;

use Phalcon\Html\Escaper;
use Phalcon\Html\Escaper\AttributeEscaper;
use Phalcon\Html\Escaper\CssEscaper;
use Phalcon\Html\Escaper\HtmlEscaper;
use Phalcon\Html\Escaper\JsEscaper;
use Phalcon\Html\Escaper\UrlEscaper;
use Phalcon\Tests\AbstractUnitTestCase;
use Phalcon\Tests\Unit\Html\Escaper\Fake\FakeHtmlEscaper;

/**
 * Verifies that the `Escaper` façade exposes its five per-context sub-objects
 * via `getXxxEscaper()` / `setXxxEscaper()`, that the legacy fan-out setters
 * (`setEncoding`, `setFlags`, `setDoubleEncode`) reach every sub-object, and
 * that each sub-object is independently reconfigurable.
 */
final class PerContextEscaperTest extends AbstractUnitTestCase
{
    public function testAttributeEscaperHandlesArrays(): void
    {
        $attr = new AttributeEscaper();

        $rendered = $attr->escape([
            'id'       => 'x',
            'class'    => 'foo bar',
            'disabled' => true,
            'hidden'   => false,    // dropped
            'noValue'  => null,     // dropped
        ]);

        $this->assertStringContainsString('id="x"', $rendered);
        $this->assertStringContainsString('class="foo bar"', $rendered);
        $this->assertStringContainsString('disabled', $rendered);
        $this->assertStringNotContainsString('hidden', $rendered);
        $this->assertStringNotContainsString('noValue', $rendered);
    }

    public function testFacadeDelegatesToSubObjects(): void
    {
        $facade = new Escaper();

        $this->assertSame('&lt;b&gt;', $facade->html('<b>'));
        $this->assertSame('a%2Fb', $facade->url('a/b'));
        $this->assertNotSame('', $facade->css('hi'));
        $this->assertNotSame('', $facade->js('hi'));
    }
    public function testFacadeProvidesAllFiveContexts(): void
    {
        $facade = new Escaper();

        $this->assertInstanceOf(HtmlEscaper::class, $facade->getHtmlEscaper());
        $this->assertInstanceOf(AttributeEscaper::class, $facade->getAttributeEscaper());
        $this->assertInstanceOf(CssEscaper::class, $facade->getCssEscaper());
        $this->assertInstanceOf(JsEscaper::class, $facade->getJsEscaper());
        $this->assertInstanceOf(UrlEscaper::class, $facade->getUrlEscaper());
    }

    public function testFanOutSettersReachAllContexts(): void
    {
        $facade = new Escaper();
        $facade->setEncoding('iso-8859-1');
        $facade->setFlags(ENT_QUOTES);
        $facade->setDoubleEncode(false);

        foreach (
            [
                $facade->getHtmlEscaper(),
                $facade->getAttributeEscaper(),
                $facade->getCssEscaper(),
                $facade->getJsEscaper(),
                $facade->getUrlEscaper(),
            ] as $sub
        ) {
            $this->assertSame('iso-8859-1', $sub->getEncoding());
            $this->assertSame(ENT_QUOTES, $sub->getFlags());
            $this->assertFalse($sub->getDoubleEncode());
        }
    }

    public function testIndividualContextReconfigurationDoesNotLeak(): void
    {
        $facade = new Escaper();

        // Tighten only the JS escaper
        $facade->getJsEscaper()->setEncoding('us-ascii');

        // HTML escaper still on default
        $this->assertSame('utf-8', $facade->getHtmlEscaper()->getEncoding());
        $this->assertSame('utf-8', $facade->getEncoding());
        $this->assertSame('us-ascii', $facade->getJsEscaper()->getEncoding());
    }

    public function testSubObjectIsCallableViaInvoke(): void
    {
        $html = new HtmlEscaper();

        $this->assertSame('&lt;b&gt;', $html('<b>'));
        $this->assertSame($html('<b>'), $html->escape('<b>'));
    }

    public function testSubObjectSubstitution(): void
    {
        $facade = new Escaper();

        $custom = new FakeHtmlEscaper();

        $facade->setHtmlEscaper($custom);

        $this->assertSame('<<<&lt;b&gt;>>>', $facade->html('<b>'));
        $this->assertSame('<b>', $custom->last);
        // attribute escaper is unaffected
        $this->assertSame('&lt;b&gt;', $facade->attributes('<b>'));
    }
}
